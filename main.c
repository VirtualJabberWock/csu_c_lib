#include "pch.h"

int CoolFunc(int a);

int main() {
	printf("%d\n", CoolFunc(10));
	printf("%d\n", CoolFunc(CoolFunc(11)));
	panic_NPE(CoolFunc, "<type> varName");
}

int CoolFunc(int a) {
	if (a == 0) return 1;
	a = a ^ 7;
	if (a == 3) return 0;
	if (a > 3) return -1;
	if (a < 3) return a;
}
