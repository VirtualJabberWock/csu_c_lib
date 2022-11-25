#include "pch.h"
#include "aquaUtils/ExtendedTypes.h"
#include "aquaUtils/BasicDataStructs.h"

int main() {

    LinkedList* list = NewLinkedList();

    list->push(list, "Hello");
    list->push(list, "Test");
    list->push(list, "Yes");
    list->remove(list, 1);
    LinkedListDisplay(list, "TestList");

}