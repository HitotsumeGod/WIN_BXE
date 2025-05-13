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

	if (strcmp(decipherable, "||||") == 0)
		return 32;
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
        for (int i = 0; i < d; i++) 
                if ((*(strs + i) = malloc(sizeof(char) * m)) == NULL) {
                        errno = MALLOC_ERR;
                        return NULL;
                }
        if ((f = fopen(fname, "r")) == NULL) { 
                errno = FOPEN_ERR;
                return NULL;
        }
        while ((c = fgetc(f)) != EOF) {
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
                }
                while ((c = fgetc(f)) != EOF) {
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
			}
                        *(*(strs + b) + (n++)) = c;
                }
                if (n == m++) {
                        if ((dummy = realloc(*(strs + b), sizeof(char) * m)) == NULL) {
                                errno = REALLOC_ERR;
                                return NULL;
                        }
                        *(strs + b) = dummy;
                }
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
	char c;
	key_bxe k;
	
	k = 0;
	for (int i = 0; i < a -> strsize; i++) 
		if (strcmp(*(buf + i), "||||") != 0) {
			k = determine_key(*buf + i);
			if (k)
				break;
		}
	if (!k) {
		fprintf(stderr, "%s\n", "file is just spaces bruh");
		exit(EXIT_FAILURE);
	}
	printf("The key is %d!\n", k);
	if ((f = fopen(T_OUTPTF_PATH, "w")) == NULL) {
		perror("fopen err");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < a -> strsize; i++) {
		if ((c = pls_decipher(*(buf + i), k)) == '?') {
			fprintf(stderr, "%s\n", "pls_decipher error: Unknown character to be read.");
			fprintf(stderr, "Erroneous string : %s\n", *(buf + i));
			exit(EXIT_FAILURE);
		}
			if (c < 91 && c > 64) {
				if (fputc(LOWERCASE(c), f) == EOF) {
					perror("fputc err");
					exit(EXIT_FAILURE);
				}
			} else if ((c < 123 && c > 96) || c == 32) {
				if (fputc(c, f) == EOF) {
					perror("fputc err");
					exit(EXIT_FAILURE);
				}
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
                case ' ':
                        for (cs = 0; cs < 4; cs++)
                                *(str + cs) = SPACE;
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
