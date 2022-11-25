#include "LinkedList.h"
#include "../BasicDataStructs.h"

LinkedList* NewLinkedList()
{
	LinkedList* l = initArray(1, sizeof(LinkedList));
	l->head = 0;
	l->tail = 0;
	l->size = 0;
	l->push = _LinkedList_pushBack;
	l->find = _LinkedList_find;
	l->_clear = _LinkedList_clear;
	l->_dispose = _LinkedList_dispose;
	l->get = _LinkedList_get;
	l->remove = _LinkedList_remove;
	return l;
}

void _LinkedList_pushBack(__SELF_LinkedList__, string_t value)
{
	if (self == 0) return panic_NPE(_LinkedList_pushBack, "<List> self");

	c_node* newNode = (c_node*)malloc(sizeof(c_node));

	if (newNode)
	{
		newNode->value = value;
		newNode->next = 0;

		if (self->tail != 0)
			self->tail->next = newNode; // { tail[...]->[new] }
		self->tail = newNode;  // { tail[new] }

		if (self->head == 0)
			self->head = newNode; // { (0)[new] }

		self->size++;
	}
}

c_node* _LinkedList_find(__SELF_LinkedList__, string_t value)
{
	if (self == 0) return panic_NPE(_LinkedList_find, "<List> self");

	c_node* current = 0;
	if (self->head != 0)
		current = self->head;
	while (current != 0)
	{
		if (strcmp(current->value, value) == 0)
			break;
		current = current->next;
	}
	return current;
}

void _LinkedList_clear(__SELF_LinkedList__) {

	if (self == 0) return panic_NPE(_LinkedList_clear, "<List> self");

	c_node* current = self->head;
	c_node* tmp;
	while (current != 0)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	self->head = 0;
	self->tail = 0;
	self->size = 0;
}

string_t _LinkedList_get(__SELF_LinkedList__, int id)
{
	if (self == 0) return panic_NPE(_LinkedList_get, "<List> self");
	if (id == 0) return self->head->value;
	if (id == self->size-1) return self->tail->value;
	c_node* current = self->head;
	for (int i = 0; i < id; i++) {
		if (current == 0)
			return panic_e(
				LINKEDLIST_CLASSNAME, "get(self, index)",
				"element index is outside the bounds of the list"
			);
		current = current->next;
	}
	return current->value;
}

string_t _LinkedList_remove(__SELF_LinkedList__, int id)
{
	if (self == 0) return panic_NPE(_LinkedList_remove, "<List> self");
	if (id == 0) {
		string_t tmp = SUS_str_copy(self->head->value);
		c_node* tmp2 = self->head->next;
		free(self->head);
		self->head = tmp2;
		self->size--;
		return tmp;
	}
	c_node* current = self->head;
	c_node* previous = current;
	for (int i = 0; i < id; i++) {
		if (current == 0)
			return panic_e(
				LINKEDLIST_CLASSNAME, "get(self, index)",
				"element index is outside the bounds of the list"
			);
		previous = current;
		current = current->next;
	}
	string_t shadow = SUS_str_copy(current->value);
	previous->next = current->next;
	free(current);
	if (id == self->size - 1) {
		self->tail = previous;
	}
	self->size--;
	return shadow;
}

void LinkedListDisplay(LinkedList* list, string_t name)
{
	if (list == 0) return panic_NPE(LinkedListDisplay, "<List> list");
	printf("[List]<String> %s: \n{\n", name);
	ForEachInLinkedList(list, __ListElementDisplay);
	printf("\n}\n");
}

void ForEachInLinkedList(LinkedList* list, LIST_ITER_PROTOTYPE)
{
	if (list == 0) return panic_NPE(ForEachInLinkedList, "<List> list");

	c_node* current = list->head;
	while (current != 0)
	{
		next(current->value, (current->next != 0));
		current = current->next;
	}
}

void _LinkedList_dispose(LinkedList** self) {
	if (sizeof(*self) != sizeof(void*)) panic_e(
		LINKEDLIST_CLASSNAME, "dispose(List** l)",
		"'l' param should be ptr to ptr, not ptr to structure!"
	);
	if (*self == 0) return panic_NPE(_LinkedList_dispose, "<List> self");
	_LinkedList_clear(*self);
	free(*self);
	*self = 0;
}
