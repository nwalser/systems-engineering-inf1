/*
Copyright 2021 Karl Rege

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
version 2 as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
*/

#ifndef _LISTS_H_
#define _LISTS_H_

/* The List data structure (ADT) */
typedef struct lstLinkedList* lstList;
#define LIST struct lstLinkedList

/* Comparator function type to compare two data elements 
implementing functions must return values <0,0,0> */
typedef int (*lstComparator) (const void*, const void*);

/* instantiates new empty List */
lstList lstCreate();

/*	Returns current size of List */
int lstSize(lstList pList);

/* Adds data referenced by void* at the beginning of the List;
increments size;*/	
void lstAddFirst(lstList pList, void* pData);

/* Adds data referenced by void* at the end of the List;
increments size;*/
void lstAddLast(lstList pList, void* pData);

/* Inserts data referenced by void* at a position into the List;
increments size;*/
void lstAdd(lstList pList, int pos, void* pData);

/* Adds data referenced by void* sorted into the List;
order is determinded by Comparator */
void lstAddSorted(lstList pList, void* pData, lstComparator cmp); 

/* Get the index'th data on the list;
Return data if accessible, else, return NULL; */
void* lstGet(lstList pList, int pos);

/* Get first data on the list and starts an iteration;
Return data if accessible, else, return NULL; */
void* lstFirst(lstList pList);

/* Get next data of an iteration;
Return data if accessible, else, return NULL; */
void* lstNext(lstList pList);

/* Remove the first data on the list;
Return removed data if accessible, else, return NULL */
void* lstRemoveFirst(lstList pList);

/* Remove the last data on the list;
Return removed data if accessible, else, return NULL */
void* lstRemoveLast(lstList pList);

/* Remove the index'th data on the list;
Return removed data if accessible, else, return NULL; */
void* lstRemove(lstList pList, int pos);

/* Remove all data of the list; 
but data elements are not freed; size = 0 */
void lstClear(lstList pList);

/* Remove all data of the list and frees list; 
but data elements are not freed; */
void lstFree(lstList pList);

/* Find index of data in the list
returns -1 if not found */
int lstIndexOf(lstList pList, void* pData, lstComparator compare);

/* Sort data in the list */
void lstSort(lstList pList, lstComparator compare);


/* stack and queue functions */
#define lstPush(stack,a) lstAddFirst(stack,a)
#define lstPop(stack) lstRemoveFirst(stack)
#define lstEnqueue(queue,a) lstAddFirst(queue,a)
#define lstDequeue(queue) lstRemoveLast(queue)

#endif
