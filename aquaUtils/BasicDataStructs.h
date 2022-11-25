#include "dataStructs/LinkedList.h"
#include "dataStructs/List.h"
#include "DebugUtils.h"
#include "ArrayUtils.h"
#include "AquaTypes.h"

#define LIST_ITER_PROTOTYPE void (*next)(string_t value, Bool hasNext)

void __ListElementDisplay(string_t element, Bool hasNext); // put to DefaultList.h 

//TODO: fix the headers levels and other thigns like this