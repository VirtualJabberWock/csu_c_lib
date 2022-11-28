#include "pch.h"
#include "aquaUtils/ExtendedTypes.h"
#include "aquaUtils/BasicDataStructs.h"

int main() {
	List* list = NewList();
	list->push(list, "Joker");
	list->push(list, "Baker");
	list->push(list, "Aes");
	list->push(list, "Okay");
	list->push(list, "Center");
	string_t a = list->remove(list, 5);
	printf("%s", a);
	list->push(list, "E Corp.");
	list->push(list, "Mr. Robot");
	list->push(list, "Sam Sepiol");
	list->push(list, "Nevermind");
	list->_dispose(&list);
	LinkedListDisplay(list, "Test");
}
