#include "pch.h"
#include "aquaUtils/ExtendedTypes.h"
#include "aquaUtils/BasicDataStructs.h"

int main() {
	List* list = NewList();
	list->push(list, "Joker");
	list->push(list, "Baker");
	list->push(list, "Aes");
	list->push(list, "Okay");
	list->pushFront(list, "Something");
	ListBubbleSort(list, 0);
	ListDisplay(list, "Test");
}
