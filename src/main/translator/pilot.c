#include <stdio.h>
#include "bxe.h"

#define AXXC_LOL

int main(int argc, char *argv[]) {

	amounts *ab;
	char **strs;
	char spc[1];

	spc[0] = NIGHT;
	if ((ab = file_to_strings(T_INPTF_PATH, spc, &strs)) < 0) {
		perror("file_to_strings err");
		return -1;
	}
	trans_write(strs, ab);

}
