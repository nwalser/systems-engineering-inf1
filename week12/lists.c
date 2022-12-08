#include <stdlib.h> 
#include "lists.h"

typedef struct lstListNode {
	struct lstListNode *pNext;
	void* pData;
} lstListNode;

struct lstLinkedList {
    lstListNode* pHead;
    lstListNode* pIter;
    int size;
};

lstList lstCreate() {
  lstList lNew = (lstList) malloc(sizeof(struct lstLinkedList));
  lNew -> pHead = NULL;
  lNew -> pIter = NULL;
  lNew -> size = 0;
  return lNew;
}

void lstAddFirst(lstList pList, void* pData) {
  lstListNode* pNew = (lstListNode*) malloc(sizeof(lstListNode));
  pNew -> pData = pData;
  pNew -> pNext = pList -> pHead;
  pList -> pHead = pNew;
  pList -> size += 1;
}

void lstAddLast(lstList pList, void* pData) {
  lstListNode* pNew = (lstListNode*) malloc(sizeof(lstListNode));
  pNew -> pData = pData;
  pNew -> pNext = NULL;
  if (pList -> pHead == NULL) pList -> pHead = pNew;
  else {
    lstListNode* p = pList -> pHead;
    while (p -> pNext != NULL) p = p -> pNext;
    p -> pNext = pNew;
  }
  pList -> size += 1;
}

void lstAdd(lstList pList, int pos, void* pData) {
  lstListNode* pNew = (lstListNode*) malloc(sizeof(lstListNode));
  pNew -> pData = pData;
  pNew -> pNext = NULL;
  if (pList -> pHead == NULL || pos == 0) {
    pNew -> pNext = pList -> pHead;
    pList -> pHead = pNew;
  } else {
    lstListNode* p = pList -> pHead;
    for (; p -> pNext != NULL && pos > 0; pos--) p = p -> pNext;
    pNew -> pNext = p -> pNext;
    p -> pNext = pNew;
  }
  pList -> size += 1;
}

void* lstGet(lstList pList, int pos) {
  lstListNode* p = pList -> pHead;
  for (; pos > 0; pos--) p = p -> pNext;
  return p -> pData;
}
void* lstFirst(lstList pList) {
	pList -> pIter = pList -> pHead;
	return (pList -> pIter != NULL) ? pList -> pIter -> pData : NULL;
		
}
void* lstNext(lstList pList) {
	pList -> pIter = pList -> pIter -> pNext;
	return (pList -> pIter != NULL) ? pList -> pIter -> pData : NULL;
}

int lstSize(lstList pList) {
	return pList -> size;
}

void* lstRemoveFirst(lstList pList) {
  lstListNode* p = NULL;
  if (pList -> pHead != NULL) {
    p = pList -> pHead;
    pList -> pHead = pList -> pHead -> pNext;
  }
  void* pData = NULL;
  if (p != NULL) {
    pData = p -> pData;
    pList -> size -= 1;
    free(p);
  }
  return pData;
}

void* lstRemoveLast(lstList pList) {
  lstListNode* p = NULL;
  if (pList -> pHead != NULL) {
    lstListNode* q = pList -> pHead;
    if (q -> pNext != NULL) {
      while (q -> pNext -> pNext != NULL) q = q -> pNext;
      p = q -> pNext;
      q -> pNext = NULL;
    } else {
      return lstRemoveFirst(pList);
    }
  }
  void* pData = NULL;
  if (p != NULL) {
    pData = p -> pData;
    free(p);
    pList -> size -= 1;
  }
  return pData;
}

void* lstRemove(lstList pList, int pos) {
	if (pos == 0 || pList -> pHead == NULL) return lstRemoveFirst(pList);
	else if (pos == pList -> size - 1) return lstRemoveLast(pList);
	else {
		lstListNode* p = pList -> pHead;
		for (; pos > 1; pos--) p = p -> pNext;
		void* pData = p -> pNext -> pData;
		lstListNode* q = p -> pNext;
		p -> pNext = p -> pNext -> pNext;
		free(q);
		pList -> size -= 1;
		return pData;				
	}
} 

void lstAddSorted(lstList pList, void* pData, lstComparator compare) {
  lstListNode* pNew = (lstListNode*)malloc(sizeof(lstListNode));
  pNew -> pData = pData;
  pNew -> pNext = NULL;
  pList -> size += 1;
  if (pList->pHead == NULL || (*compare) (pList->pHead->pData, pNew->pData) > 0) {
      pNew->pNext = pList->pHead;
      pList->pHead = pNew;
  } else {
    lstListNode* p = pList->pHead;
    while (p->pNext != NULL && (*compare)(p->pNext->pData, pNew->pData) < 0) {
		p = p->pNext;
    }
    pNew->pNext = p->pNext;
    p->pNext = pNew;
  }
}

int lstIndexOf(lstList pList, void* pData, lstComparator compare) {
  int index = -1;

  lstListNode * pIter = pList->pHead;

  while(pIter != NULL){
    index ++;

    if(compare(pData, (pIter->pData)) != -1)
      return index;

    pIter = pIter->pNext;
  }
  
  return index;
}

void lstClear(lstList pList) {
  lstListNode* p = pList -> pHead, * q;
  while (p != NULL) {
    q = p -> pNext;
    free(p);
    p = q;
  }
  pList -> pHead = NULL;
  pList -> size = 0;
}

void lstSort(lstList pList, lstComparator compare) {
    lstList sorted = lstCreate();
    void* pData;
    while ((pData = lstRemoveFirst(pList)) != NULL) lstAddSorted(sorted, pData, compare);
    pList -> pHead = sorted -> pHead;
    pList -> size = sorted -> size;
    free(sorted);
}

void lstFree(lstList pList) {
    lstClear(pList);
    free(pList);
}