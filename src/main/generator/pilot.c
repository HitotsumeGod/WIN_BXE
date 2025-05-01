#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "bxe.h"

#define AXXC_LOL

int main(int argc, char *argv[]) {
	
	amounts *ab;
	struct stat st;
	char *prim;

	if (stat(G_INPTF_PATH, &st) == -1)
		if (errno == ENOENT)
			prep_file(argv[1]);
	if ((ab = file_to_single_string(G_INPTF_PATH, &prim)) == NULL) {
		fprintf(stderr, "File_to_single_string err : %d\n", errno);
		return -1;
	}
	set_random_key();
	write_to_outptf(prim, ab);
	return 0;

}
