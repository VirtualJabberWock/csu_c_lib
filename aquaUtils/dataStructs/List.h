#pragma once
#include "../StringUtils.h"
#include "../BasicDataStructs.h"

typedef struct tagNode
{
	string_t value;
	struct tagNode* next;
} node;

/*
Signle connected list
*/
#define LIST_CLASSNAME "BasicDataStruct.List"
#define __SELF_List__ struct tagList *self
typedef struct tagList
{
	node* head;
	node* tail;
	size_t size;
	void (*push)(__SELF_List__, string_t value);
	void (*pushFront)(__SELF_List__, string_t value);
	node* (*find)(__SELF_List__, string_t query);
	void (*_dispose)(struct tagList** self);
	void (*_clear)(__SELF_List__);
	string_t (*get)(__SELF_List__, int id);
	string_t (*remove)(__SELF_List__, int id);
	//void (*push)(__SELF_List__, string_t value);

} List;

List* NewList();

void _List_pushBack(__SELF_List__, string_t value);
void _List_pushFront(__SELF_List__, string_t value);
node* _List_find(__SELF_List__, string_t query);
void _List_dispose(List **self);
void _List_clear(__SELF_List__);
string_t _List_get(__SELF_List__, int id);
string_t _List_remove(__SELF_List__, int id);

void ListDisplay(List* list, string_t name);
void ForEachInList(List* list, LIST_ITER_PROTOTYPE);