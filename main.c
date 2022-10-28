#include "pch.h"
#include "cryptoUtils/NativeCrypto.h"
#include <Windows.h>

int main() {
	StringBuilder sb;
	InitStringBuilder(&sb, "");
	sb.append(&sb, "Hello, ");
	sb.append(&sb, "World");
	sb.append(&sb, "!");
	printf(sb.build(&sb));
	printf("\n\n\n");
	sb.append(&sb, "\nAnd another line!!!");
	printf(sb.buildAndDispose(&sb));
	printf("\n\n\n");
}
