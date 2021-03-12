#include<stdio.h>
#include<stdlib.h>
#include"STD_TYPES.h"
#include"Slot_LinkedList.h"



Slot * CreateSlotList(Slot * Start)
{
	Start = InsertInSlotEmptyList(Start,1);
	InsertAtSlotEnd(Start,2);
	InsertAtSlotEnd(Start,3);
	InsertAtSlotEnd(Start,4);
	InsertAtSlotEnd(Start,5);

	
	return Start;
}

Slot * InsertInSlotEmptyList(Slot * Start,s32 Data)
{
	
	Slot * temp = (Slot*)malloc(sizeof(Slot));
	
	temp -> Time = Data;
	temp -> prev = NULL;
	temp -> next = NULL;
	Start        = temp;
	
	return Start;
}

void InsertAtSlotEnd(Slot * Start,s32 Data)
{
	Slot * temp,*p;
	temp = (Slot *)malloc(sizeof(Slot));
	
	temp -> Time = Data;
	
	p = Start;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;
	temp -> next = NULL;
	temp -> prev = p;
}

Slot * DeleteSlot(Slot * Start,s32 Data)
{
	Slot * temp;
	if(Start == NULL)
	{
		printf("The List is empty\n");
		return Start;
	}
	
	if(Start->next == NULL)
	{
		if(Start->Time == Data)
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
	
	if(Start->Time == Data)
	{
		temp        = Start;
		Start       = Start->next;
		Start->prev = NULL;
		free(temp);
		
	}
	
	temp = Start->next;
	while(temp->next!=NULL)
	{
		if(temp->Time == Data)
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
		if(temp->Time == Data)
		{
			temp->prev->next = NULL;
			free(temp);
		}
		else
		{
			//printf("%d value is not in the List\n",Data);
		}
	}
	return Start;
}
void DisplaySlotList(Slot * Start)
{
	Slot * ptr = Start;
	if(ptr != NULL)
	{
		while(ptr != NULL)
		{
			printf("%d  ",ptr -> Time);
			printf("\n");
			ptr = ptr -> next;
		}
	}
}