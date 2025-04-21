#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bxe.h"

const char *alphabet = "abcdefghijklmnopqrstuvwxyz";

char pls_decipher(char *decipherable, key_bxe k) {}

key_bxe determine_key(char *decipherable) {

	char *tofree;
	key_bxe k = 0;

	for (int i = KEY_MIN; i <= KEY_MAX; i++) 
		for (int il = 0; il < strlen(alphabet); il++) {
			printf("%c from %d\n", *(alphabet + il), i);
			if (strcmp(decipherable, (tofree = pls_encipher(*(alphabet + il), i))) == 0) {
				free(tofree);
				return i;
			} else
				free(tofree);
		}
	return k;

}
