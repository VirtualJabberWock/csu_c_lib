#include <stdio.h>
#include "ArrayUtils.h"
#include "AquaTypes.h"
#include "StringUtils.h"

StringVP NewStringV()
{
	StringV sv;
	InitStringV(&sv);
	return &sv;
}

IntVP NewIntV()
{
	IntV iv;
	InitIntV(&iv);
	return &iv;
}

void InitStringV(StringV* v)
{
	v->__notnull__ = 1;
	v->put = _Default_Vector_PutString;
	v->clear = _Default_Vector_ClearString;
	v->size = 0;
	v->ptr = initBucket(0);
}

void InitIntV(IntV* v)
{
	v->__notnull__ = 1;
	v->put = _Default_Vector_PutInt;
	v->clear = _Default_Vector_ClearInt;
	v->size = 0;
	v->ptr = initArray(0, sizeof(int));
}

void InitLongV(LongV* v)
{
	v->__notnull__ = 1;
	v->put = _Default_Vector_PutLong;
	v->clear = _Default_Vector_ClearLong;
	v->size = 0;
	v->ptr = initArray(0, sizeof(__int64));
}

void InitDoubleV(DoubleV* v)
{
	v->__notnull__ = 1;
	v->put = _Default_Vector_PutDouble;
	v->clear = _Default_Vector_ClearDouble;
	v->size = 0;
	v->ptr = initArray(0, sizeof(double));
}

void InitStringBuilder(StringBuilder* builder, string base_nt)
{
	builder->buffer = initArray(0, sizeof(char));
	builder->b_size = 0;
	if (SUS_getStringLength(base_nt) > 0) {
		int j = 0;
		while (base_nt[j] != '\0') {
			pushToCharArray(&(builder->buffer), &builder->b_size, base_nt[j]);
			j++;
		}
	}
	builder->add = _Default_SB_Append;
	builder->trim = _Default_SB_Trim;
	builder->build = _Default_SB_Build;
	builder->buildAndDispose = _Default_SB_BuildAndDispose;
	builder->__notnull__ = 1;
}

void _Default_Vector_PutInt(IntV* v, int value)
{
	putToIntArray(&(v->ptr), &(v->size), value);
}

void _Default_Vector_PutLong(LongV* v, __int64 value)
{
	putTo64Array(&(v->ptr), &(v->size), value);
}

void _Default_Vector_PutString(StringV* v, string value)
{
	string a = SUS_str_copy(value);
	pushToBucket(&(v->ptr), &(v->size), a);
}

void _Default_Vector_PutDouble(DoubleV* v, double value)
{
	putToDoubleArray(&(v->ptr), &(v->size), value);
}

void _Default_Vector_ClearInt(IntV* v)
{
	if (v->ptr != 0) free(v->ptr);
	v->ptr = (int*)initArray(0, sizeof(int));
	v->size = 0;
}
void _Default_Vector_ClearLong(LongV* v)
{
	if (v->ptr != 0) free(v->ptr);
	v->ptr = (__int64*)initArray(0, sizeof(__int64));
	v->size = 0;
}
void _Default_Vector_ClearDouble(DoubleV* v)
{
	if (v->ptr != 0) free(v->ptr);
	v->ptr = (double*)initArray(0, sizeof(double));
	v->size = 0;
}
void _Default_Vector_ClearString(StringV* v)
{
	freeBucket(v->ptr, v->size);
	v->ptr = initBucket(0);
	v->size = 0;
}

StringBuilder* _Default_SB_Append(StringBuilder* sb, string str) {
	if (sb->buffer == 0) panic_NPE();
	int i = 0;
	while (str[i] != '\0') {
		pushToCharArray(&(sb->buffer), &(sb->b_size), str[i]);
		i++;
	}
	return sb;
}

void _Default_SB_Trim(StringBuilder* sb) {
	if (sb->buffer == 0) panic_NPE();
	sb->buffer = SUS_trim(sb->buffer);
}

string _Default_SB_Build(StringBuilder* sb) {
	if (sb->buffer == 0) panic_NPE();
	return SUS_str_lock(sb->buffer, sb->b_size);
}

string _Default_SB_BuildAndDispose(StringBuilder* sb) {
	if (sb->buffer == 0) panic_NPE();
	string r = buildString(sb->buffer, sb->b_size);
	sb->buffer = initArray(0, sizeof(char));
	sb->b_size = 0;
	return r;
}