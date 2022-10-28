#include "pch.h"
#include "cryptoUtils/NativeCrypto.h"
#include <Windows.h>

int main() {

	StringBuilder sb;
	InitStringBuilder(&sb, "");
	sb.add(&sb, "Hello, ");
	sb.add(&sb, "World!");
	printf(sb.build(&sb));
	printf("\n\n");
	sb.add(&sb, "\nAnd another line!!!");
	sb.add(&sb, "\nYes we do string concatenation like");
	sb.add(&sb, " ");
	sb.add(&sb, "this!");
	printf(sb.buildAndDispose(&sb));
	printf("\n\n");

	InitStringBuilder(&sb, "Also we can start with some string!\n");
	sb.add(&sb, "And")->add(&sb, " do it ")->add(&sb, "like a chain");
	printf(sb.buildAndDispose(&sb));
	printf("\n\n");

}
