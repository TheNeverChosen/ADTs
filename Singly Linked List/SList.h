#ifndef SLIST_H
#define SLIST_H

#include<stdbool.h>

/*OBS:
  SN / SNode -> Singly Node
  SL / SList -> Singly Linked List */

//SList's Nodes definition
typedef struct SNode{
  void *data;
  struct SNode *next;
} SNode;

//SList's definition
typedef struct{
  SNode *begin, *end;
  int size;
} SList;

//Create new SNode
SNode* SN_Create(void *data, SNode *next);

/* Free SNode.
  freeData: true->free SNode's data, false->don't free SNode's data
  delNext: true->free next SNodes, false->don't free next SNodes */
void SN_Free(SNode *node, bool freeData, bool freeNext);

//Create new SList
SList* SL_Create();

/*Clear entire SList (remove SList's SNodes from memory)
  freeData: true->free SNode's data, false->don't free SNode's data */
void SL_Clear(SList *ls, bool freeData);

/*Free entire SList (remove SList and its SNodes from memory)
  freeData: true->free SNode's data, false->don't free SNode's data */
void SL_Free(SList *ls, bool freeData);

//Verify whether the list is empty
bool SL_IsEmpty(SList *ls);

//Get previous node to a specific index in SList. Complexity: O(index-1)
SNode* SL_GetPreNode(SList *ls, int index);

//Get SList's data at specific index. Complexity: O(index)
void* SL_Get(SList *ls, int index);

//Insert data at specific SList's index
bool SL_InsertIndex(SList *ls, void *data, int index);

//Insert data at SList's begin
bool SL_InsertBegin(SList *ls, void *data);

//Insert data at SList's end
bool SL_InsertEnd(SList *ls, void *data);

/*Delete node at specific SList's index
  freeData: true->free SNode's data, false->don't free SNode's data */
bool SL_DeleteIndex(SList *ls, int index, bool freeData);

/*Delete node at SList's begin
  freeData: true->free SNode's data, false->don't free SNode's data */
bool SL_DeleteBegin(SList *ls, bool freeData);

/*Delete node at SList's end
  freeData: true->free SNode's data, false->don't free SNode's data */
bool SL_DeleteEnd(SList *ls, bool freeData);

/*Print entire SList
  printData -> function to print SList's data
  sep -> Separator between SList's data */
void SL_Print(SList *ls, void (*printData)(void *data), char *sep);

#endif