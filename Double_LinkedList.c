#include <stdio.h>
#include <stdlib.h>
#include"STD_TYPES.h"
#include"Slot_LinkedList.h"
#include"Double_LinkedList.h"




Node * Start1 ;
/*Initialize pointer to counter to indicate if the list of patients is alreay created or not */
s32 y = 0 ;
s32 * py = &y;

/*Initialize pointer to counter to indicate if the list of slots is alreay created or not */
s32 z = 0 ;
s32 * pz = &z;

Node * CreateList(Node * Start)
{
	s32 n,id,age,i=1;
	printf("Please Enter The number of Patients: \n");
	scanf("%d",&n);
	
	Start = NULL;
	
	if(n == 0)
		return Start;
	
	printf("Enter The ID Of Patient Number %d: ",i);
	scanf("%d",&id);
	printf("Enter The AGE Of Patient Number %d : ",i);
	scanf("%d",&age);
	Start = InsertInEmptyList(Start,id,age);
	
	for(i = 2; i<=n ; i++)
	{
		printf("Enter The ID Of Patient number %d: ",i);
		scanf("%d",&id);
		printf("Enter The AGE Of Patient number %d: ",i);
		scanf("%d",&age);
		InsertAtEnd(Start,id,age);
	}
	return Start;
}

Node * InsertInEmptyList(Node * Start,s32 Data,s32 Age)
{
	
	Node * temp = (Node*)malloc(sizeof(Node));
	
	temp -> ID = Data;
	temp -> AGE = Age;
	temp -> prev = NULL;
	temp -> next = NULL;
	Start        = temp;
	
	
	return Start;
	
}
Node * InsertInBeginning(Node * Start,s32 Data)
{
	
}

void InsertAtEnd(Node * Start,s32 Data,s32 Age)
{
	
	Node * temp,*p;
	temp = (Node *)malloc(sizeof(Node));
	
	temp -> ID = Data;
	temp -> AGE = Age;
	
	p = Start;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;
	temp -> next = NULL;
	temp -> prev = p;
	
	
	
}
void InsertAfter(Node * Start, s32 x,s32 Data, s32 id)
{
	Node * temp,*p;
	temp = (Node *)malloc(sizeof(Node));
	
	temp -> ID = id;
	temp -> AGE = Data;
	
	p = Start;
	while((p!=NULL) && (p->ID != x))
	{
		p=p->next;
	}
	if(p == NULL)
	{
		printf("%d not present in the List",x);
	}
	else
	{
		temp -> prev = p;
		temp -> next = p -> next;
		if(p -> next != NULL)
		{
			p->next->prev = temp;
		}
		p->next = temp;
	}
}
Node * InsertBefore(Node * Start, s32 x, s32 Data)
{
	Node * temp,*p;
	if(Start == NULL)
	{
		printf("The List is empty\n");
		return Start;
	}
	if(Start->ID == x)
	{
		Start = InsertInBeginning(Start,Data);
		return Start;
	}
	p = Start;
	while(p!=NULL)
	{
		if(p->ID == x)
		{
			break;
		}
		p = p->next;
	}
	if(p == NULL)
	{
		printf("%d is not present at the List\n",x);
	}
	else
	{
		temp = (Node*)malloc(sizeof(Node));
		temp -> ID = Data;
		
		temp -> prev = p->prev;
		temp -> next = p;
		p    -> prev->next = temp;
		p    -> prev       = temp;
	}
	return Start;
}

Node * DeleteNode(Node * Start,s32 Data)
{
	Node * temp;
	if(Start == NULL)
	{
		printf("The List is empty\n");
		return Start;
	}
	
	if(Start->next == NULL)
	{
		if(Start->ID == Data)
		{
			temp = Start;
			Start = NULL;
			free(temp);
		}
		else
		{
			printf("The Value %d is not in the List\n",Data);
		}
		return Start;
	}
	
	if(Start->ID == Data)
	{
		temp        = Start;
		Start   = Start -> next;
		Start->prev = NULL;
		free(temp);
		
	}
	
	
	temp = Start->next;
	while(temp->next!=NULL)
	{
		if(temp->ID == Data)
		{
			break;
		}
		temp = temp->next;
	}
	if(temp->next != NULL)
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}
	else
	{
		if(temp->ID == Data)
		{
			temp->prev->next = NULL;
			free(temp);
		}
		else
		{
			printf("%d value is not in the List\n",Data);
		}
	}
	return Start;
}
void DisplayList(Node * Start)
{
	s32 i=1;
	if(Start != NULL)
	{
		Node * ptr = Start;
		printf("======== The List for Today Contains Till Now =========\n");
		printf("=========================================================\n");
		while (ptr  != NULL )
		{
			
			printf("Patient Number %d ID is %d\n",i,ptr -> ID );
			printf("Patient Number %d Age is %d\n",i,ptr -> AGE);
			printf("\n-------------------------------------------\n");
			ptr = ptr -> next;
			i++;
			
			
		}			
	}
	printf("===============================================================\n");
}
Node  * Add_New_Patient_Record  (Node * Start)
{
	s32 id,age,i = 2;
	if (*py == 0)
	{
		Start = CreateList(Start);
		*py = 1;
	}
	else
	{
		printf("Enter The ID Of Patient number %d: ",i);
		scanf("%d",&id);
		printf("Enter The AGE Of Patient number %d: ",i);
		scanf("%d",&age);
		InsertAtEnd(Start,id,age);
		i++;
	}
	return Start;
}
Node  * Edit_Patient_Record     (Node * Start, s32 ID)
{
	s32 age,id;
	printf("\n");
	printf("Enter Your patient's New Data\n");
	printf("Enter Patient Age: ");
	scanf("%d",&age);
	printf("Enter Patient ID: ");
	scanf("%d",&id);
	InsertAfter(Start,ID,age,id);
	Start = DeleteNode(Start,ID);
	
	
	return Start;
}


Node  * Cancel_Resrvation       (Node * Start)	  
{
	s32 x ;
	printf("Enter Patient Id will be deleted\n");
	scanf("%d",&x);
	Start = DeleteNode(Start,x);
	DisplayList(Start);
	return Start;
} 
void View_Patient_Record        (Node * Start, s32 ID)
{
	Node * ptr = Start;
	if(ptr == NULL)
	{
		printf("The List Is Empty");
	}
	while(ptr -> next != NULL)
	{
		if(ptr -> ID == ID)
		{
			break;
		}
		ptr = ptr -> next;
	}
	if(ptr -> next == NULL)
	{
		printf("ID is not Exist\n");
	}
	else 
	{
		printf("Patient Information\n=======================\n Patient ID is %d\n",ptr -> ID );
		printf("Patient Age is %d\n",ptr -> AGE);
	}
}
Slot  * Reserve_New_Slot        (Slot * New)
{
	s32 x,i=0 ;
	
	printf("Enter TIme You Will Reserve \n");
	scanf("%d",&x);
	if(x >= 0 && x<=5)
	{
	temp = CreateSlottempList(temp, x);
	//DisplaySlotList(temp);
	New = DeleteSlot(New,x);
	
	}
	else
	{
		printf("Sorry Time Choosed is Wrong\n");
		return New;
	}
	printf("***************************\n");
	printf("  Successful Reservation  \n");
	printf("***************************\n");
	
	return New;
	
}
void View_Reservations          (Slot * New)
{
	DisplaySlotList(temp);
	
}
s32     IsIdRepeated            (Node * Start,s32 Data)
{
	while(Start -> next != NULL)
	{
		if(Start -> ID == Data)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		Start = Start -> next;
	}
	
}
Slot * CreateSlottempList           (Slot * New, s32 x)
{
	if(*pz == 0)
	{
		New = InsertInSlotEmptyList(New,x);
		*pz = 1;
		
	}
	else
	{
		InsertAtSlotEnd(New,x);
	}	
		
	
	return New;
	
}