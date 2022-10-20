#include "NativeCrypto.h"

unsigned __int64 l_rot64(unsigned __int64 n, int s, int len) {
	return (n << s) | (n >> (len - s));
}

unsigned __int64 r_rot64(unsigned __int64 n,int s, int len) {
	return  (n >> s) | (n << (len - s));
}

unsigned char __crypto_chr_hash(unsigned char c) {
	unsigned char c0 = l_rot64(c, 3, 8);
	unsigned char c1 = r_rot64(c, 1, 8);
	unsigned char c2 = c1 + 1;
	unsigned char c3 = (c0 ^ c1) ^ c2;
	c2 = r_rot64(c3, 1, 8);
	c1 = c3 - 0x87;
	return (c0 ^ c1) ^ (c2 ^ c3);
}

