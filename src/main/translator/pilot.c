#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include "bxe.h"

#define AXXC_LOL

int main(int argc, char *argv[]) {

	amounts *ab;
	char **strs, spc[1];
	double st, ent;

	st = (double) clock() / CLOCKS_PER_SEC;
	spc[0] = NIGHT;
	if ((ab = file_to_strings(T_INPTF_PATH, spc, &strs)) < 0) {
		pstrerror(errno);
		return -1;
	}
	trans_write(strs, ab);
	ent = (double) clock() / CLOCKS_PER_SEC;
	if (ent - st < 1)
		printf("Executed in %.6f milliseconds!\n", 1000 * (ent - st));
	else
		printf("Executed in %.6f seconds!\n", ent - st);
	return 0;

}
