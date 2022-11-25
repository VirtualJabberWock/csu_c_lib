#include "BasicDataStructs.h"

void __ListElementDisplay(string_t element, Bool hasNext)
{
	printf("\t%s", element);
	if (hasNext) printf(", \n");
}