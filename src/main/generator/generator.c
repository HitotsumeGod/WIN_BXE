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
	if (unlink(fname) == -1) {
		perror("unlink err");
		exit(EXIT_FAILURE);
	}
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

amounts *file_to_single_string(char *fname, char **buf) {

        amounts *a;
	struct stat *ss;
        FILE *f;
        char *str, *dummy;
        int c, n, m;

        n = 0;
        m = 2;
        if ((str = malloc(sizeof(char) * m)) == NULL || (a = malloc(sizeof(amounts))) == NULL) {
                errno = MALLOC_ERR;
                return NULL;
        }
        if ((f = fopen(fname, "r")) == NULL) {
                errno = FOPEN_ERR;
                return NULL;
        }
        while ((c = fgetc(f)) != EOF) {
                if (n == m) {
                        if ((dummy = realloc(str, sizeof(char) * (m *= 2))) == NULL) {
                                errno = REALLOC_ERR;
                                return NULL;
                        }
                        str = dummy;
                }
                *(str + (n++)) = c;
        }
        if (n == m++) {
                if ((dummy = realloc(str, sizeof(char) * m)) == NULL) {
                        errno = REALLOC_ERR;
                        return NULL;
                }
                str = dummy;
        }
        if (fclose(f) == -1) {
                errno = FCLOSE_ERR;
                return NULL;
        }
        *(str + (n--)) = '\0';
        *buf = str;
        a -> strsize = n;
        a -> nmallocd = m;
        return a;

}


void gen_write(char *buf, amounts *a) {

	FILE *f;
	char **enciphered_strs;
	int n;
	
	if ((enciphered_strs = malloc(sizeof(char *) * (a -> strsize * 2))) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	if ((f = fopen(G_OUTPTF_PATH, "w")) == NULL) {
		perror("fopen err");
		exit(EXIT_FAILURE);
	}
	n = 0;
	for (int i = 0; i < a -> strsize; i++) {
		if (*(buf + i) < 123 && *(buf + i) > 96) {
			if (fputs((*(enciphered_strs + (n++)) = pls_encipher(CAPITALIZE(*(buf + i)), tkey)), f) == EOF) {
				perror("fputs err");
				exit(EXIT_FAILURE);
			}
		} else if ((*(buf + i) < 91 && *(buf + i) > 64) || *(buf + i) == 32) {
			if (fputs((*(enciphered_strs + (n++)) = pls_encipher(*(buf + i), tkey)), f) == EOF) {
				perror("fputs err");
				exit(EXIT_FAILURE);
			}
		} else
			continue;
		if (fputs((*(enciphered_strs + (n++)) = pls_encipher(NIGHT, tkey)), f) == EOF) {
			perror("fputs err");
			exit(EXIT_FAILURE);
		}
	}
	for (int i = 0; i < n; i++)
		free(*(enciphered_strs + i));
	free(enciphered_strs);
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
	
	if ((str = malloc(sizeof(char) * (k * 10))) == NULL) {
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
		case ' ':
			for (cs = 0; cs < 4; cs++)
				*(str + cs) = SPACE;
			*(str + cs) = '\0';
			break;
		case NIGHT:
			BXE_NIGHT(k, str);
			break;
		default:
			free(str);
			fprintf(stderr, "Erroneous encipher call with character [[ %d ]]. Ensure that no non-alphabet characters are being read in. \n", c);
			exit(EXIT_FAILURE);
	}
	return str;

}

