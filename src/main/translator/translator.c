#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "bxe.h"

const char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

key_bxe determine_key(char *decipherable) {

	char *tofree;
	key_bxe k = 0;

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

amounts *file_to_strings(char *fname, char *delim, char ***buf) {

        amounts *a;
        FILE *f;
        char **strs, **fdummy, *dummy;
        int c, n, m, b, d;
	bool mdelim;

        b = 0;
        m = d = 2;
	mdelim = false;
	if (!delim) {
		if ((delim = malloc(sizeof(char))) == NULL) {
			errno = MALLOC_ERR;
			return NULL;
		}
		*delim = '\n';
		mdelim = true;
	}
        if ((strs = malloc(sizeof(char *) * d)) == NULL || (a = malloc(sizeof(amounts))) == NULL) {
                errno = MALLOC_ERR;
                return NULL;
        }
	//printf("\nInitial toplevel array malloc is %zu bytes.\n", sizeof(char *) * d);
        for (int i = 0; i < d; i++) 
                if ((*(strs + i) = malloc(sizeof(char) * m)) == NULL) {
                        errno = MALLOC_ERR;
                        return NULL;
                }
	//printf("\n%d lower arrays are each malloc'd %zu bytes.\n", d, sizeof(char) * m);
        if ((f = fopen(fname, "r")) == NULL) { 
                errno = FOPEN_ERR;
                return NULL;
        }
        while ((c = fgetc(f)) != EOF) {
		//printf("\nTLoop iteration %d.\n", b + 1);
                n = 0;
		m = 2;
                ungetc(c, f);
                if (b == d) {
                        if ((fdummy = realloc(strs, sizeof(char *) * (d *= 2))) == NULL) {
                                errno = REALLOC_ERR;
                                return NULL;
                        }
                        strs = fdummy;
                        for (int i = d / 2; i < d; i++)
                                if ((*(strs + i) = malloc(sizeof(char) * m)) == NULL) {
                                        errno = MALLOC_ERR;
                                        return NULL;
                                }
			//printf("\nTL reallocates to %zu bytes.\n", sizeof(char *) * d);
                }
                while ((c = fgetc(f)) != EOF) {
			//printf("\nLLoop iteration %d.\n", n + 1);
                        if (c == *delim) {
				while ((c = fgetc(f)) == *delim);
				ungetc(c, f);
				break;
			} if (n == m) {
                                if ((dummy = realloc(*(strs + b), sizeof(char) * (m *= 2))) == NULL) {
                                        errno = REALLOC_ERR;
                                        return NULL;
                                }
                                *(strs + b) = dummy;
                        	//printf("\nLL %d reallocates to %zu bytes.\n", b, sizeof(char) * m);
			}
			//printf("\nCharacter is placed into LL %d at position %d.\n", b, n);
                        *(*(strs + b) + (n++)) = c;
                }
                if (n == m++) {
                        if ((dummy = realloc(*(strs + b), sizeof(char) * m)) == NULL) {
                                errno = REALLOC_ERR;
                                return NULL;
                        }
			//printf("\nLL %d reallocates to %zu bytes outside of mini loop.\n", b, sizeof(char) * m + 1);
                        *(strs + b) = dummy;
                }
		//printf("\nNull byte is placed into LL %d at position %d.\n", b, n);
                *(*(strs + (b++)) + n) = '\0';
        }
	if (mdelim)
		free(delim);
        if (fclose(f) == -1) {
                errno = FCLOSE_ERR;
                return NULL;
        }
        *buf = strs;
        a -> strsize = b;
        a -> nmallocd = d;
        return a;

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
		if (fputc(LOWERCASE(pls_decipher(*(buf + i), k)), f) == EOF) {
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
