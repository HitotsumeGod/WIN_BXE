#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "bxe.h"

const char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

key_bxe determine_key(char *decipherable) {

	char *tofree;
	key_bxe k = 0;

	printf("%s\n", decipherable);
	for (int i = KEY_MIN; i <= KEY_MAX; i++) 
		for (int il = 0; il < strlen(alphabet); il++) {
			if (strcmp(decipherable, (tofree = pls_encipher(*(alphabet + il), i))) == 0) {
				printf("Tofree : %s\n", tofree);
				free(tofree);
				return i;
			} else
				free(tofree);
		}
	return k;

}

char pls_decipher(char *decipherable, key_bxe k) {

	char *tofree;
	for (int i = 0; i < strlen(alphabet); i++)
		if (strcmp(decipherable, (tofree = pls_encipher(*(alphabet + i), k))) == 0) {
			free(tofree);
			return *(alphabet + i);
		} else
			free(tofree);
	return '?';

}

void trans_write(char **buf, amounts *a) {

	FILE *f;
	key_bxe k;
	
	k = determine_key(*buf);
	printf("The key is %d!\n", k);
	if ((f = fopen(T_OUTPTF_PATH, "w")) == NULL) {
		perror("fopen err");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < a -> strsize; i++) {
		if (fputc(pls_decipher(*(buf + i), k), f) == EOF) {
			perror("fputc err");
			exit(EXIT_FAILURE);
		}
		free(*(buf + i));
	}
	for (int i = a -> strsize; i < a -> nmallocd; i++)
		free(*(buf + i));
	free(buf);
	free(a);
	if (fclose(f) == -1) {
		perror("fclose err");
		exit(EXIT_FAILURE);
	}
	

}

char *pls_encipher(char c, key_bxe k) {
	
	char *str;
	int cs;
	
	if ((str = malloc(sizeof(char) * (k * 30))) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	switch (c) {
		case 'A':
			BXE_A(k, str);
			break;
		case 'B':
			BXE_B(k, str);
			break;
		case 'C':
			BXE_C(k, str);
			break;
		case 'D':
			BXE_D(k, str);
			break;
		case 'E':
			BXE_E(k, str);
			break;
		case 'F':
			BXE_F(k, str);
			break;
		case 'G':
			BXE_G(k, str);
			break;
		case 'H':
			BXE_H(k, str);
			break;
		case 'I':
			BXE_I(k, str);
			break;
		case 'J':
			BXE_J(k, str);
			break;
		case 'K':
			BXE_K(k, str);
			break;
		case 'L':
			BXE_L(k, str);
			break;
		case 'M':
			BXE_M(k, str);
			break;
		case 'N':
			BXE_N(k, str);
			break;
		case 'O':
			BXE_O(k, str);
			break;
		case 'P':
			BXE_P(k, str);
			break;
		case 'Q':
			BXE_Q(k, str);
			break;
		case 'R':
			BXE_R(k, str);
			break;
		case 'S':
			BXE_S(k, str);
			break;
		case 'T':
			BXE_T(k, str);
			break;
		case 'U':
			BXE_U(k, str);
			break;
		case 'V':
			BXE_V(k, str);
			break;
		case 'W':
			BXE_W(k, str);
			break;
		case 'X':
			BXE_X(k, str);
			break;
		case 'Y':
			BXE_Y(k, str);
			break;
		case 'Z':
			BXE_Z(k, str);
			break;
		default:
			fprintf(stderr, "%s\n", "kinda sorta maybe");
			str = "";
	}
	return str;

}
