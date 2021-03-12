
#ifndef DOUBLE_LINKEDLIST_H_
#define DOUBLE_LINKEDLIST_H_


typedef struct node
{
	struct node * prev;
	s32 AGE;
	s32 ID;
	struct node * next;
}Node;

Slot * temp;

Node * CreateList(Node * Start);
void DisplayList(Node * Start);
Node * InsertInEmptyList(Node * Start,s32 Data,s32 Age);
Node * InsertInBeginning(Node * Start,s32 Data);
void InsertAtEnd(Node * Start,s32 Data,s32 Age);
void InsertAfter(Node * Start, s32 x,s32 Data, s32 id);
Node * InsertBefore(Node * Start, s32 x, s32 Data);
Node * DeleteNode(Node * Start,s32 Data);
Node * ReverseList(Node * Start);

Node  * Add_New_Patient_Record  (Node * Start);
Node  * Cancel_Resrvation       (Node * Start);	  
Node  * Edit_Patient_Record     (Node * Start, s32 ID);
s32     IsIdRepeated            (Node * Start, s32 Data);
Slot  * Reserve_New_Slot        (Slot * New);
void View_Patient_Record        (Node * Start, s32 ID);
void View_Reservations          (Slot * Start);
Slot * CreateSlottempList           (Slot * New , s32 x);


#endif