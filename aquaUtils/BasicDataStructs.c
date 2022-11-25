#include "BasicDataStructs.h"

List* NewList()
{
	List* l = initArray(1, sizeof(List));
	l->head = 0;
	l->tail = 0;
	l->size = 0;
	l->push = _List_pushBack;
	l->find = _List_find;
	l->_clear = _List_clear;
	l->_dispose = _List_dispose;
	l->get = _List_get;
	l->remove = _List_remove;
	return l;
}

void _List_pushBack(__SELF_List__, string_t value)
{
	if (self == 0) return panic_NPE(_List_pushBack, "<List> self");

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

c_node* _List_find(__SELF_List__, string_t value)
{
	if (self == 0) return panic_NPE(_List_find, "<List> self");

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

void _List_clear(__SELF_List__) {

	if (self == 0) return panic_NPE(_List_clear, "<List> self");

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

string_t _List_get(__SELF_List__, int id)
{
	if (self == 0) return panic_NPE(_List_get, "<List> self");
	if (id == 0) return self->head->value;
	if (id == self->size-1) return self->tail->value;
	c_node* current = self->head;
	for (int i = 0; i < id; i++) {
		if (current == 0)
			return panic_e(
				LIST_CLASSNAME, "get(self, index)",
				"element index is outside the bounds of the list"
			);
		current = current->next;
	}
	return current->value;
}

string_t _List_remove(__SELF_List__, int id)
{
	if (self == 0) return panic_NPE(_List_remove, "<List> self");
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
				LIST_CLASSNAME, "get(self, index)",
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

void ListDisplay(List* list, string_t name)
{
	if (list == 0) return panic_NPE(ListDisplay, "<List> list");
	printf("[List]<String> %s: \n{\n", name);
	ForEachInList(list, ListElementDisplay);
	printf("\n}\n");
}

void ListElementDisplay(string_t element, Bool hasNext)
{
	printf("\t%s", element);
	if (hasNext) printf(", \n");
}

void ForEachInList(List* list, LIST_ITER_PROTOTYPE)
{
	if (list == 0) return panic_NPE(ForEachInList, "<List> list");

	c_node* current = list->head;
	while (current != 0)
	{
		next(current->value, (current->next != 0));
		current = current->next;
	}
}

void _List_dispose(List** self) {
	if (sizeof(*self) != sizeof(void*)) panic_e(
		LIST_CLASSNAME, "dispose(List** l)",
		"'l' param should be ptr to ptr, not ptr to structure!"
	);
	if (*self == 0) return panic_NPE(_List_dispose, "<List> self");
	_List_clear(*self);
	free(*self);
	*self = 0;
}
