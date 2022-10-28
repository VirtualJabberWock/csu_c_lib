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
	sb.add(&sb, "\nC�������� �����!!!");
	sb.add(&sb, "\n�� ����� ������ ������������ �����");
	sb.add(&sb, " ");
	sb.add(&sb, "��� ���!");
	printf(sb.buildAndDispose(&sb));
	printf("\n\n");

	InitStringBuilder(&sb, "����� ������ � ���������� ������!\n");

	sb.add(_, "� �����")->add(_, " ��������� ")->add(_, "�������!");

	printf(sb.buildAndDispose(&sb));
	printf("\n\n");

}
