#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pprocessor.h"
#include "bxe.h"

#define AXXC_LOL

int main(int argc, char *argv[]) {
	
	amounts *ab;
	char **prim;

	if ((ab = file_to_strings("h", NULL, &prim)) == NULL) {
		fprintf(stderr, "File_to_strings err : %d\n", errno);
		return -1;
	}
	for (int i = 0; i < ab -> strsize; i++)
		printf("%s\n", *(prim + i));
	return 0;

}
