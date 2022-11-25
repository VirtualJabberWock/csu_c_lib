#pragma once
#include "..\aquaUtils\StringUtils.h"
#include "CryptoField.h";

CryptoF field;

void ACRYPTO_DisposeInstance(); //VERY IMPORTANT

string_t hashPassword(string_t a);
string_t hashString(string_t a);

/*
@private
*/
string_t hashToHexString(unsigned char* in);

