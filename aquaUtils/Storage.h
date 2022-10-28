#pragma once

#include "ArrayUtils.h"

#define Integer int
#define Long __int64
#define Double double
#define Byte char
#define Bool char

#define True 1
#define False 0

#define _Type_Integer 0x01
#define _Type_Long    0x02
#define _Type_Double  0x03
#define _Type_String  0x04

#define __self Storage *self
#define __self__ struct StorageS* self
// VECTORS

typedef struct StringVS {
	string* ptr;
	int size;
	void (*put) (struct StringVS* self, string value);
	void (*clear)( struct StringVS* self );
	Bool __notnull__; // (self == null) ? 0 : 1
} StringV;

typedef struct IntVS {
	int* ptr;
	int size;
	void (*put) (struct IntVS* self, int value);
	void (*clear)(struct IntVS* self);
	Bool __notnull__; // (self == null) ? 0 : 1
} IntV;

typedef struct LongVS {
	Long* ptr;
	int size;
	void (*put) (struct LongVS* self, __int64 value);
	void (*clear)(struct LongVS* self);
	Bool __notnull__; // (self == null) ? 0 : 1
} LongV;

typedef struct DoubleVS {
	double* ptr;
	int size;
	void (*put) (struct DoubleVS* self, double value);
	void (*clear)(struct DoubleVS* self);
	Bool __notnull__; // (self == null) ? 0 : 1
} DoubleV;

// MAIN TYPE

#define isNull(self) (self.__notnull__ == False)


typedef struct StorageS {

	void (*putInt)    (__self__, int value);
	void (*putLong)   (__self__, Long value);
	void (*putDouble) (__self__, double value);
	void (*putString) (__self__, string value);

	void (*clearInt)    (__self__);
	void (*clearLong)   (__self__);
	void (*clearDouble) (__self__);
	void (*clearString) (__self__);

	void (*free)(__self__);
	Bool __notnull__; // (self == null) ? 0 : 1
	
	IntV    _data32; //store int32
	LongV   _data64; //store int64
	DoubleV _dataDV; //store double
	StringV _dataSB; //store strings


} Storage;

Storage Storage_New();

void InitStringV(StringV* v);
void InitIntV(IntV* v);
void InitLongV(LongV* v);
void InitDoubleV(DoubleV* v);

void Storage_Free(__self);

void Storage_PutInt(__self, int value);
void Storage_PutLong(__self, Long value);
void Storage_PutString(__self, string value);
void Storage_PutDouble(__self, double value);

void __Vector_PutInt(IntV* v, int value);
void __Vector_PutLong(LongV* v, Long value);
void __Vector_PutString(StringV* v, string value);
void __Vector_PutDouble(DoubleV* v, double value);

void Storage_ClearInt(__self);
void Storage_ClearLong(__self);
void Storage_ClearString(__self);
void Storage_ClearDouble(__self);

void __Vector_ClearInt(IntV* v);
void __Vector_ClearLong(LongV* v);
void __Vector_ClearString(StringV* v);
void __Vector_ClearDouble(DoubleV* v);

void* _Storage_FP(void* s, int b_size);

