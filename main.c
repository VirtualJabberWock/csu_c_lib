#include "pch.h"
#include "cryptoUtils/NativeCrypto.h"
#include <locale.h>

int main() {

	setlocale(LC_ALL, "Russian");
	StringBuilder sb;
	InitStringBuilder(&sb, "");
	StringBuilder* _ = &sb;
	sb.add(&sb, "Hello, ");
	sb.add(&sb, "World!");
	printf(sb.build(&sb));
	printf("\n\n");
	sb.add(&sb, "\nCледующая линия!!!");
	sb.add(&sb, "\nМы можем делать конкатенацию строк");
	sb.add(&sb, " ");
	sb.add(&sb, "вот так!");
	printf(sb.buildAndDispose(&sb));
	printf("\n\n");

	InitStringBuilder(&sb, "Можем начать с конкретной строки!\n");

	sb.add(_, "А потом")->add(_, " соеденить ")->add(_, "цепочку!");

	printf(sb.buildAndDispose(&sb));
	printf("\n\n");

}
