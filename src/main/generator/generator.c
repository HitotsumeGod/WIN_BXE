#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include "bxe.h"

key_bxe tkey;

void set_random_key(void) { srand(time(NULL)); tkey = RANDOMRANGE(KEY_MAX, KEY_MIN); printf("Random key is %d\n", tkey); }

void prep_file(char *fname) {

	FILE* f;
	char *fbuf, *fdummy;
	size_t fsize;
	
	if ((f = fopen(fname, "rb")) == NULL) {
		perror("fopen err");
		exit(EXIT_FAILURE);
	}
	if (fseek(f, 0, SEEK_END) == -1) {
		perror("fseek err");
		exit(EXIT_FAILURE);
	}
	fsize = ftell(f);
	rewind(f);
	if ((fbuf = malloc(sizeof(char) * fsize)) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	if (fread(fbuf, sizeof(char), fsize, f) != fsize) {
		perror("fread err");
		exit(EXIT_FAILURE);
	}
	if (fclose(f) == -1) {
		perror("fclose err");
		exit(EXIT_FAILURE);
	}
	/*if (unlink(fname) == -1) {
		perror("unlink err");
		exit(EXIT_FAILURE);
	}*/
	if ((f = fopen(G_INPTF_PATH, "wb")) == NULL) {
		perror("fopen err");
		exit(EXIT_FAILURE);
	}
	if (fwrite(fbuf, sizeof(char), fsize, f) != fsize) {
		perror("fwrite err");
		exit(EXIT_FAILURE);
	}
	free(fbuf);
	if (fclose(f) == -1) {
		perror("fclose err");
		exit(EXIT_FAILURE);
	}

}


void write_to_outptf(char **buf) {

	FILE *f;
	int n;
	size_t buflen;
	
	n = 0;
	if ((f = fopen(G_OUTPTF_PATH, "w")) == NULL) {
		perror("fopen err");
		exit(EXIT_FAILURE);
	}
	while (strcmp("\0", *(buf + (n++))) != 0);
	buflen = --n;
	for (int i = 0; i < buflen; i++) {
		if (fputs(*(buf + i), f) == EOF) {
			perror("fputs err");
			exit(EXIT_FAILURE);
		}
		free(*(buf + i));
	}
	free(buf);
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

