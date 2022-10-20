#include "pch.h"
#include "cryptoLib/NativeCrypto.h"

int main() {
	for (unsigned char i = 0; i < 255; i++) {
		unsigned char a = __crypto_chr_hash(i);
		printf("[%00x]~%x\n", i, a);
	}
}
