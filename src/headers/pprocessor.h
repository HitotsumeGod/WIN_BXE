#ifndef __PPROCESSOR_H__
#define __PPROCESSOR_H__

#include <stddef.h>

#define MALLOC_ERR -2
#define REALLOC_ERR -3
#define FOPEN_ERR -4
#define FCLOSE_ERR -5

typedef struct {
	size_t strsize;
	size_t nmallocd;
} amounts;

typedef enum {
	DOUBLE,
	PLUS_TWO,
	PLUS_FOUR
} realloc_mode;

#ifdef _STDIO_H
#ifdef _STDLIB_H
#define pstrerror(errnum) 													\
	char *errstr;														\
	switch (errnum) {													\
	case MALLOC_ERR:													\
		errstr = "MALLOC_ERR";												\
		break;														\
	case REALLOC_ERR:													\
		errstr = "REALLOC_ERR";												\
		break;														\
	case FOPEN_ERR:														\
		errstr = "FOPEN_ERR";												\
		break;														\
	case FCLOSE_ERR:													\
		errstr = "FCLOSE_ERR";												\
		break;														\
	default:														\
		fprintf(stderr, "|||||||| IMPROPER ERROR CODE PASSED TO PSTRERROR ||||||||\nQuitting...\n");			\
		exit(EXIT_FAILURE);												\
	}															\
	fprintf(stderr, "|||||||| PROGRAM HAS ENCOUNTERED %s ||||||||\nQuitting...\n", errstr);	
#endif
#endif

extern amounts *console_to_single_string(char *filename, char **ptr_to_strbuf);
extern amounts *console_to_strings(char *filename, char ***ptr_to_strbuf);
extern amounts *file_to_single_string(char *filename, char **ptr_to_strbuf);
extern amounts *file_to_strings(char *filename, char *delim, char ***ptr_to_strbuf);

#endif //__PPROCESSOR_H__
