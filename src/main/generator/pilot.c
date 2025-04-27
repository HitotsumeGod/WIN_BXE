#include <stdio.h>
#include <stdlib.h>
#include "bxe.h"

#define AXXC_LOL

int main(int argc, char *argv[]) {
	
	char *prim;
	size_t t;
	
	if (argc != 2) {
		printf("%s\n", "2 args bruh");
		return 1;	
	}
	prim = malloc(sizeof(char) * 2);
	set_random_key();
	printf("%s\n", "Random key set.");
	prep_file(argv[1]);
	printf("%s\n", "Input file prepped.");
	t = read_from_inptf(&prim);
	printf("%s\n", "Reading complete.");
	write_to_outptf(prim, t);
	printf("%s\n", "Execution completed.");
	return 0;

}
