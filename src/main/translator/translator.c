#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "bxe.h"

const char *alphabet = "abcdefghijklmnopqrstuvwxyz";

key_bxe determine_key(char *decipherable) {

	char *tofree;
	key_bxe k = 0;

	printf("%s\n", decipherable);
	for (int i = KEY_MIN; i <= KEY_MAX; i++) 
		for (int il = 0; il < strlen(alphabet); il++) {
			if (strcmp(decipherable, (tofree = pls_encipher(*(alphabet + il), i))) == 0) {
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

char **read_from_inptf(void) {

	FILE *f;
	char **fbuf, **fdummy, *dummy;
	int c, n, m, b, d;
	
	b = 0;
	d = 2;
	if ((fbuf = malloc(sizeof(char *) * d)) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < d; i++)
		if ((*(fbuf + i) = malloc(sizeof(char) * d)) == NULL) {
			perror("malloc err");
			exit(EXIT_FAILURE);
		}
	if ((f = fopen(T_INPTF_PATH, "r")) == NULL) {
		if (errno = ENOENT)
			fprintf(stderr, "%s\n", "No file to translate! Maybe run the generator first to make some enciphered text?");
		else
			perror("fopen err");
		exit(EXIT_FAILURE);
	}
	while ((c = fgetc(f)) != EOF) {				//OUTER LOOP CHECKING FOR END OF FILE
		n = 0;
		m = 2;
		ungetc(c, f);
		if (b == d) {
			if ((fdummy = realloc(fbuf, sizeof(char *) * (d *= 2))) == NULL) {
				perror("realloc err");
				exit(EXIT_FAILURE);
			}
			fbuf = fdummy;
			for (int i = d / 2; i < d; i++)
				if ((*(fbuf + i) = malloc(sizeof(char) * m)) == NULL) {
					perror("malloc err");
					exit(EXIT_FAILURE);
			}
		}
		n = 0;
		while ((c = fgetc(f)) != SPACE) {		//INNER LOOP CHECKING FOR END OF CIPHERED WORD
			if (n == m) {
				if ((dummy = realloc(*(fbuf + b), sizeof(char) * (m *= 2))) == NULL) {
					perror("realloc err");
					exit(EXIT_FAILURE);
				}
				*(fbuf + b) = dummy;
			}
			*(*(fbuf + b) + (n++)) = c;
		}
		while ((c = fgetc(f)) == SPACE);
		ungetc(c, f);
		b++;
	}
	if (b == d) {
		if ((fdummy = realloc(fbuf, sizeof(char *) * d + 1)) == NULL) {
			perror("realloc err");
			exit(EXIT_FAILURE);
		}
		fbuf = fdummy;
	}
	*(fbuf + b) = "\0";	
	if (fclose(f) == -1) {
		perror("fclose err");
		exit(EXIT_FAILURE);
	}
	return fbuf;

}

void write_to_outptf(char **read) {

	FILE *f;
	key_bxe k;
	char *deciphered, *temp, *dummy, c;
	int n, m, b, e;
	
	n = b = e = 0;
	m = 2;
	printf("%d\n", ((k = determine_key(*read))));
	if ((f = fopen(T_OUTPTF_PATH, "w")) == NULL) {
		perror("fopen err");
		exit(EXIT_FAILURE);
	}
	if ((deciphered = malloc(sizeof(char) * m)) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	while (strcmp((temp = *(read + (b++))), "\0") == 1) {
		if (n == m) {
			if ((dummy = realloc(deciphered, sizeof(char) * (m *= 2))) == NULL) {
				perror("realloc err");
				exit(EXIT_FAILURE);
			}
			deciphered = dummy;				
		}
		*(deciphered + (n++)) = pls_decipher(temp, k);	
		free(temp);
	}
	free(read);
	*(deciphered + n) = '\0';
	if (fputs(deciphered, f) == -1) {
		perror("fputs err");
		exit(EXIT_FAILURE);
	}
	free(deciphered);
	if (fclose(f) == -1) {
		perror("fclose err");
		exit(EXIT_FAILURE);
	}

}

char *pls_encipher(char c, key_bxe k) {
	
	char *str;
	int cs;
	
	if ((str = malloc(sizeof(char) * (k * 10))) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	switch (CAPITALIZE(c)) {
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

