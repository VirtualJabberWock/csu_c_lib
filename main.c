#include "pch.h"
#include "aquaUtils/ExtendedTypes.h"
#include "aquaUtils/BasicDataStructs.h"

int main() {
	HashMap* hmap = NewHashMap();
	hmap->put(hmap, "name", "Aqua");
	hmap->put(hmap, "surname", "Haze");
	hmap->put(hmap, "number", "+79525160897");
	hmap->put(hmap, "Abc", "Collision Check!");
	hmap->put(hmap, "abc", "Collision Check!?");
	DataBox* box = DissectHashMap(hmap);
	box->display(box);
}
