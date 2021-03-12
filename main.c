#include<stdio.h>
#include"STD_TYPES.h"
#include"Slot_LinkedList.h"
#include"Double_LinkedList.h"
#include"Config.h"



Node * NewPatient ;
Slot * NewSlot;
//slot * temp1 = temp;

void main (void)
{
	
	s32 ch ;
	s32 pass ;
	s32 op ;
	u8 i;
	s32 P_ID;
	NewSlot = CreateSlotList(NewSlot);

	printf("         **  ** ** ** **     Welcome To Doctor's Clinic    ** ** ** ** **\n");
	printf("\n");
		while(1)
		{
	printf("Choose:\n1 for Admin mode\n2 for User mode\n ");
	scanf("%d",&ch);
	if(ch == 1)
	{
		printf("Enter Your Password Please .. \n");
		scanf("%d",&pass);
		for(i=2;i>0;i--)
		{
			if(pass == PASSWORD)
			{
				break;
			}
			else
			{
				printf("Sorry You've entered Wrong Password, %d trials available\n",i);
				printf("please Enter Your Password Again..\n");
				scanf("%d",&pass);
			}
		}
			printf("==========================================================================\n");
			printf("                             Welcome Doctor                               \n");
			printf("==========================================================================\n");

			printf("                         Choose your operation                             \n");
		    printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- \n");
			printf("1- Add new patient record\n2- Edit patient record\n3-Reserve a slot with the doctor\n4- Cancel reservation\n ");
			scanf("%d",&op);
			if(op == 1)
			{
				printf(" ----------  You Can Add More than one Patient Doctor ----------------\n");
				printf("----------------------------------------------------------------------\n");
				NewPatient = Add_New_Patient_Record  (NewPatient);
				DisplayList(NewPatient);
			}
			else if(op == 2)
			{
				s32 x;
				printf("Enter Patient Id will be edited\n");
				scanf("%d",&x);
				NewPatient = Edit_Patient_Record(NewPatient,x);
				DisplayList(NewPatient);
				 
			}	
			else if(op == 3)
			{
				printf("       -------  --            Time Intervals      -- -------       \n");
				printf("\n===================================================================\n");
				printf("\n 1- 2pm to 2:30pm\n \n2- 2:30pm to 3pm \n\n3- 3pm to 3:30pm \n\n4-4pm to 4:30pm \n\n5- 4:30pm to 5pm \n\n");
				printf("\n------------------------------------------------------------------------\n");
				printf("\n       -------  --     Available Time Intervals Till Now    -- -------   \n");
				DisplaySlotList(NewSlot);
				NewSlot = Reserve_New_Slot(NewSlot);
				
				
				
				
				
				
			}
			else if (op == 4)
			{
				NewPatient = Cancel_Resrvation (NewPatient)	 ; 
			}
			else 
			{
				printf("operation Choosed Incorrect\n");
			}
			
		
		
		
			
		
		
	}
	else if (ch == 2)
	{
		printf("==========================================================================\n");
		printf("                             Welcome User                                 \n");
		printf("==========================================================================\n");
		printf("                         Choose your operation                             \n");
		printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- \n");
		printf("1- View Patient Record\n2- View Today's Reservations\n");
		scanf("%d",&op);
		if(op == 1)
		{
			printf("Please Enter Patient ID \n");
			scanf("%d",&P_ID);
			View_Patient_Record(NewPatient,P_ID);
		}
		else if (op == 2)
		{
			printf("       -------  --            Time Intervals      -- -------       \n");
			printf("\n===================================================================\n");
			printf("\n 1- 2pm to 2:30pm\n \n2- 2:30pm to 3pm \n\n3- 3pm to 3:30pm \n\n4-4pm to 4:30pm \n\n5- 4:30pm to 5pm \n\n");
			printf("\n------------------------------------------------------------------------\n");
			printf("\n       -------  --     Reserved Time Intervals Till Now    -- -------   \n");
		    View_Reservations(temp);

		}
		
	
	}
	else
	{
		printf("Sorry You Entered Wrong Input\n");
	}
	}
}


