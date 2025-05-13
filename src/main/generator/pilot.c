#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "bxe.h"

#define AXXC_LOL

int main(int argc, char *argv[]) {

	amounts *ab;
	char *prim;
	double st, ent;
	
	st = (double) clock() / CLOCKS_PER_SEC;
	if (argc > 2) {
		fprintf(stderr, "%s\n", "--- Usage : ./generator <filename> ---");
		return EXIT_FAILURE;
	} else if (argc > 1)
		prep_file(argv[1]);
	if ((ab = file_to_single_string(G_INPTF_PATH, &prim)) == NULL) {
		pstrerror(errno);
		return -1;
	}
	set_random_key();
	gen_write(prim, ab);
	ent = (double) clock() / CLOCKS_PER_SEC;
	if (ent - st < 1)
		printf("Executed in %.6f milliseconds!\n", 1000 * (ent - st));
	else
		printf("Executed in %.6f seconds!\n", ent - st);
	return 0;

}
