#pragma once
#include "pch.h"



typedef struct ChainNode // Node<String> {next,value}
{
	string_t value;
	struct ChainNode* next;
} c_node;

/*
Signle connected list
*/
#define LIST_CLASSNAME "BasicDataStruct.List"
#define __SELF_List__ struct tagList *self
#define LIST_ITER_PROTOTYPE void (*next)(string_t value, Bool hasNext)
typedef struct tagList
{
	c_node* head;
	c_node* tail;
	size_t size;
	void (*push)(__SELF_List__, string_t value);
	c_node* (*find)(__SELF_List__, string_t query);
	void (*_dispose)(__SELF_List__);
	void (*_clear)(__SELF_List__);
	string_t (*get)(__SELF_List__, int id);
	string_t (*remove)(__SELF_List__, int id);
	//void (*push)(__SELF_List__, string_t value);

} List;

List* NewList();

/*
добавление элемента в конец списка V
удаление произвольного элемента из списка V
поиск элемента в списке V
получение размера списка V
вывод всего списка V?
*/

//...List [>

void _List_pushBack(__SELF_List__, string_t value);
c_node* _List_find(__SELF_List__, string_t query);
void _List_dispose(List **self);
void _List_clear(__SELF_List__);
string_t _List_get(__SELF_List__, int id);
string_t _List_remove(__SELF_List__, int id);

void ListDisplay(List* list, string_t name);
void ListElementDisplay(string_t element, Bool hasNext);

//...<]

//...Iterator [>

void ForEachInList(List* list, LIST_ITER_PROTOTYPE);

//...<]