#pragma once
#include "../StringUtils.h"
#include "../BasicDataStructs.h"

typedef struct tagChainNode // Node<String> {next,value}
{
	string_t value;
	struct tagChainNode* next;
} c_node;

/*
Signle connected list
*/
#define LINKEDLIST_CLASSNAME "BasicDataStruct.LinkedList"
#define __SELF_LinkedList__ struct tagSingleLinkedList *self
typedef struct tagSingleLinkedList
{
	c_node* head;
	c_node* tail;
	size_t size;
	void (*push)(__SELF_LinkedList__, string_t value);
	c_node* (*find)(__SELF_LinkedList__, string_t query);
	void (*_dispose)(struct tagSingleLinkedList** self);
	void (*_clear)(__SELF_LinkedList__);
	string_t (*get)(__SELF_LinkedList__, int id);
	string_t (*remove)(__SELF_LinkedList__, int id);
	//void (*push)(__SELF_List__, string_t value);

} LinkedList;

LinkedList* NewLinkedList();

void _LinkedList_pushBack(__SELF_LinkedList__, string_t value);
c_node* _LinkedList_find(__SELF_LinkedList__, string_t query);
void _LinkedList_dispose(LinkedList **self);
void _LinkedList_clear(__SELF_LinkedList__);
string_t _LinkedList_get(__SELF_LinkedList__, int id);
string_t _LinkedList_remove(__SELF_LinkedList__, int id);

void LinkedListDisplay(LinkedList* list, string_t name);
void ForEachInLinkedList(LinkedList* list, LIST_ITER_PROTOTYPE);