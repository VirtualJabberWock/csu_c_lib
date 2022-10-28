#include "pch.h"
#include "cryptoUtils/NativeCrypto.h"
#include "aquaUtils/Storage.h"

int main() {
	IntV v;
	InitIntV(&v);
	v.put(&v, 10);
	v.put(&v, 111);
	v.put(&v, 123);
	v.put(&v, 412);
	printf("%d", v.ptr[2]);
	printf(" ~ third element from array[%d]", v.size);
	v.clear(&v); //todo fix error
}
