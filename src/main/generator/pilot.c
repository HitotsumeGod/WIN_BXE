#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "bxe.h"

#define AXXC_LOL

int main(int argc, char *argv[]) {
	
	amounts *ab;
	char *prim;

	if (argc > 2) {
		fprintf(stderr, "%s\n", "--- Usage : ./generator <filename> ---");
		return EXIT_FAILURE;
	} else if (argc > 1)
		prep_file(argv[1]);
	if ((ab = file_to_single_string(G_INPTF_PATH, &prim, DOUBLE)) == NULL) {
		fprintf(stderr, "File_to_single_string err : %d\n", errno);
		return -1;
	}
	set_random_key();
	gen_write(prim, ab);
	return 0;

}
