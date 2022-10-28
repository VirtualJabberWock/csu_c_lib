#include <stdio.h>
#include "ArrayUtils.h"
#include "Storage.h"
#include "StringUtils.h"

// TODO EVERY PUT FOR EVERY FUNC

Storage Storage_New()
{
	Storage self;
	//DATA
	self.__notnull__ = True;
	//

	IntV intV;
	intV.size = 0; intV.ptr = initList(0, 4);
	self._data32 = intV;
	LongV longV;
	longV.size = 0; longV.ptr = initList(0, 8);
	self._data64 = longV;
	DoubleV dV;
	dV.size = 0; dV.ptr = initList(0, 8);
	self._dataDV = dV;
	StringV sV;
	sV.size = 0; sV.ptr = initBucket(0);
	self._dataSB = sV;

	self.putInt = Storage_PutInt;
	self.putLong = Storage_PutLong;
	self.putString = Storage_PutString;
	self.putDouble = Storage_PutDouble;

	self.clearInt = Storage_ClearInt;
	self.clearLong = Storage_ClearLong;
	self.clearString = Storage_ClearString;
	self.clearDouble = Storage_ClearDouble;

	self.free = Storage_Free;

	return self;
}

void InitStringV(StringV* v)
{
	v->__notnull__ = 1;
	v->put = __Vector_PutString;
	v->clear = __Vector_ClearString;
	v->size = 0;
	v->ptr = initBucket(0);
}

void InitIntV(IntV* v)
{
	v->__notnull__ = 1;
	v->put = __Vector_PutInt;
	v->clear = __Vector_ClearInt;
	v->size = 0;
	v->ptr = initList(0, sizeof(int));
}

void InitLongV(LongV* v)
{
	v->__notnull__ = 1;
	v->put = __Vector_PutLong;
	v->clear = __Vector_ClearLong;
	v->size = 0;
	v->ptr = initList(0, sizeof(Long));
}

void InitDoubleV(DoubleV* v)
{
	v->__notnull__ = 1;
	v->put = __Vector_PutDouble;
	v->clear = __Vector_ClearDouble;
	v->size = 0;
	v->ptr = initList(0, sizeof(double));
}

void Storage_Free(__self) {

	if (self == 0) return;
	if (!self->__notnull__) return;
	void* ptr0 = (*self)._data32.ptr;
	void* ptr1 = (*self)._data64.ptr;
	void* ptr2 = (*self)._dataDV.ptr;
	void* ptr3 = (*self)._dataSB.ptr;

	if ((*self)._data32.ptr != 0) free(ptr0);
	if ((*self)._dataDV.ptr != 0) free(ptr2);
	if ((*self)._data64.ptr != 0) free(ptr1);
	if ((*self)._dataSB.ptr != 0)
		freeBucket(ptr3, (*self)._dataSB.size);
	(*self).__notnull__ = False;
	
	
}

// PUT

void Storage_PutInt(__self, int value)
{
	putToIntList(&(self->_data32.ptr), &(self->_data32.size), value);
}

void Storage_PutLong(__self, Long value)
{
	putTo64List(&(self->_data64.ptr), &(self->_data64.size), value);
}

void Storage_PutString(__self, string value)
{
	string a = str_copy(value);
	pushToBucket(&(self->_dataSB.ptr), &(self->_dataSB.size), a);
}

void Storage_PutDouble(__self, double value)
{
	putToDoubleList(&(self->_dataDV.ptr), &(self->_dataDV.size), value);
}

void __Vector_PutInt(IntV* v, int value)
{
	putToIntList(&(v->ptr), &(v->size), value);
}
void __Vector_PutLong(LongV* v, Long value)
{
	putTo64List(&(v->ptr), &(v->size), value);
}
void __Vector_PutString(StringV* v, string value)
{
	string a = str_copy(value);
	pushToBucket(&(v->ptr), &(v->size), a);
}
void __Vector_PutDouble(DoubleV* v, double value)
{
	putToDoubleList(&(v->ptr), &(v->size), value);
}

// CLEAR

void Storage_ClearInt(__self) { __Vector_ClearInt(&(self->_data32)); }
void Storage_ClearLong(__self) { __Vector_ClearInt(&(self->_data64)); }
void Storage_ClearString(__self) { __Vector_ClearInt(&(self->_dataSB)); }
void Storage_ClearDouble(__self) { __Vector_ClearInt(&(self->_dataDV)); }

void __Vector_ClearInt(IntV* v)
{
	v->ptr = (int*)_Storage_FP(v->ptr, sizeof(int));
	v->size = 0;
}
void __Vector_ClearLong(LongV* v)
{
	v->ptr = (Long*)_Storage_FP(v->ptr, sizeof(__int64));
	v->size = 0;
}
void __Vector_ClearDouble(DoubleV* v)
{
	v->ptr = (double*)_Storage_FP(v->ptr, sizeof(double));
	v->size = 0;
}
void __Vector_ClearString(StringV* v)
{
	freeBucket(v->ptr, v->size);
	v->ptr = initBucket(0);
	v->size = 0;
}

void* _Storage_FP(void* ptr, int b_size) // free pointer
{
	if (ptr != 0) {
		printf("%p, %d\n", ptr, b_size);
		free(ptr);
	}
	return initList(1, b_size);
}
