#include "pch.h"
#include "cryptoUtils/NativeCrypto.h"
#include <locale.h>

int main() {
	FILE* f;
	openFile_s(&f, "test.txt");
	StringVP svp = NewStringV();
	readAllLines_s(f, svp);
	for (int i = 0; i < svp->size; i++) {
		printf(svp->ptr[i]);
		printf("\n");
	}
}
