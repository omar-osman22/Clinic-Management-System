
#ifndef SLOT_LINKEDLIST_H_
#define SLOT_LINKEDLIST_H_

typedef struct slot
{
	struct slot * prev;
	s32 Time;
	struct slot * next;
}Slot;

Slot * CreateSlotList(Slot * Start);
void DisplaySlotList(Slot * Start);
Slot * InsertInSlotEmptyList(Slot * Start,s32 Data);
void InsertAtSlotEnd(Slot * Start,s32 Data);
Slot * DeleteSlot(Slot * Start,s32 Data);


Slot * New ;
#endif