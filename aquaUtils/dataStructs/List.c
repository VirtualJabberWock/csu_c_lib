#include "List.h"
#include "../BasicDataStructs.h"

List* NewList()
{
	List* l = initArray(1, sizeof(List));
	l->head = 0;
	l->tail = 0;
	l->size = 0;

	l->push = _List_pushBack;
	l->pushFront = _List_pushFront;
	l->find = _List_find;
	l->_clear = _List_clear;
	l->_dispose = _List_dispose;
	l->get = _List_get;
	l->remove = _List_remove;
	return l;
}

void _List_pushBack(__SELF_List__, string_t value)
{
	panic("Not implemented FUNCTION");
}

void _List_pushFront(__SELF_List__, string_t value)
{
	panic("Not implemented FUNCTION");
}

node* _List_find(__SELF_List__, string_t value)
{
	panic("Not implemented FUNCTION");

}

void _List_clear(__SELF_List__) {

	panic("Not implemented FUNCTION");

}

string_t _List_get(__SELF_List__, int id)
{
	panic("Not implemented FUNCTION");

}

string_t _List_remove(__SELF_List__, int id)
{
	panic("Not implemented FUNCTION");

}

void ListDisplay(List* list, string_t name)
{
	panic("Not implemented FUNCTION");
}

void ForEachInList(List* list, LIST_ITER_PROTOTYPE)
{
	panic("Not implemented FUNCTION");

}

void _List_dispose(List** self) {

	panic("Not implemented FUNCTION");

}
