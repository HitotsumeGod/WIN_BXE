#include <stdio.h>
#include "bxe.h"

#define AXXC_LOL

int main(int argc, char *argv[]) {
	
	char **prim;
	
	if (argc != 2) {
		printf("%s\n", "2 args bruh");
		return 1;	
	}
	set_random_key();
	printf("%s\n", "Random key set.");
	prep_file(argv[1]);
	printf("%s\n", "Input file prepped.");
	prim = read_from_inptf();
	printf("%s\n", "Reading complete.");
	write_to_outptf(prim);
	printf("%s\n", "Execution completed.");
	return 0;

}
