#ifndef __BXE_H__
#define __BXE_H__

#include <stdint.h>

#define RANDOMRANGE(max, min) rand() % (max + 1 - min) + min

#ifndef AXXC_LOL
	#define NIGHT '`'
	#define DOUBLE_NIGHT '@'
	#define SPACE '|'
	#define CAPITALIZE(c) c - 32
	#define LOWERCASE(c) c + 32
	#define KEY_MAX 50
	#define KEY_MIN 2
	#define G_INPTF_PATH "res/g_inptf.bxe"
	#define G_OUTPTF_PATH "res/g_outptf.bxe"
	
	#define BXE_A(key, decipherable) 					\
		cs = 0;								\
		*(decipherable + (cs++)) = '<';					\
		for (int i = 0; i < key + 2; i++)				\
			*(decipherable + (cs++)) = '$';				\
		for (int i = 0; i < key * 2; i++)				\
			*(decipherable + (cs++)) = '^';				\
		*(decipherable + cs) = '\0';			
	#define BXE_B(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '?';				\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '!';				\
		*(decipherable + cs) = '\0';
	#define BXE_C(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < 3; i++)					\
			*(decipherable + (cs++)) = '^';				\
		for (int i = 0; i < key + 1; i++)				\
			*(decipherable + (cs++)) = '!';				\
		*(decipherable + cs) = '\0';			
	#define BXE_D(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '*';				\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '<';				\
		for (int i = 0; i < key + 3; i++)				\
			*(decipherable + (cs++)) = '*';				\
		*(decipherable + cs) = '\0';
	#define BXE_E(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < key + 5; i++)				\
			*(decipherable + (cs++)) = '%';				\
		*(decipherable + (cs++)) = '!';					\
		*(decipherable + (cs++)) = '$';					\
		*(decipherable + (cs++)) = '!';					\
		*(decipherable + cs) = '\0';			
	#define BXE_F(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < 3; i++)					\
			*(decipherable + (cs++)) = '>';				\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '$';				\
		*(decipherable + (cs++)) = '!';					\
		*(decipherable + cs) = '\0';			
	#define BXE_G(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < (key * 2) + 24; i++)			\
			*(decipherable + (cs++)) = '*';				\
		*(decipherable + (cs++)) = '&';					\
		*(decipherable + cs) = '<';					
	#define BXE_H(key, decipherable)					\
		cs = 0; 							\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '!';				\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '$';				\
		*(decipherable + (cs++)) = '!';					\
		*(decipherable + cs) = '\0';			
	#define BXE_I(key, decipherable)					\
		cs = 0;								\
		*(decipherable + (cs++)) = '%';					\
		*(decipherable + (cs++)) = '^';					\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '^';				\
		*(decipherable + (cs++)) = '%';					\
		*(decipherable + cs) = '\0';			
	#define BXE_J(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < (key / 2) + 16; i++)			\
			*(decipherable + (cs++)) = '?';				\
		*(decipherable + (cs++)) = '*';					\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '^';				\
		*(decipherable + (cs++)) = '*';					\
		*(decipherable + cs) = '\0';			
	#define BXE_K(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '^';				\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '*';				\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '&';				\
		*(decipherable + (cs++)) = '*';					\
		*(decipherable + cs) = '\0';			
	#define BXE_L(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '!';				\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '$';				\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '%';				\
		for (int i = 0; i < 3; i++)					\
			*(decipherable + (cs++)) = '^';				\
		for (int i = 0; i < key + 7; i++)				\
			*(decipherable + (cs++)) = '>';				\
		*(decipherable + cs) = '\0';			
	#define BXE_M(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '&';				\
		*(decipherable + (cs++)) = '^';					\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '$';				\
		*(decipherable + cs) = '\0';						
	#define BXE_N(key, decipherable)					\
		cs = 0;								\
		*(decipherable + (cs++)) = '&';					\
		*(decipherable + (cs++)) = '^';					\
		for (int i = 0; i < key * 3; i++)				\
			*(decipherable + (cs++)) = '^';				\
		*(decipherable + cs) = '\0';			
	#define BXE_O(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '<';				\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '*';				\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '>';				\
		*(decipherable + (cs++)) = '&';					\
		*(decipherable + cs) = '\0';			
	#define BXE_P(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < 4; i++)					\
			*(decipherable + (cs++)) = '<';				\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '!';				\
		*(decipherable + cs) = '\0';			
	#define BXE_Q(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < (key - (key / 2) + (key / 4)); i++)		\
			*(decipherable + (cs++)) = '*';				\
		*(decipherable + (cs++)) = '&';					\
		*(decipherable + (cs++)) = '^';					\
		*(decipherable + cs) = '\0';				
	#define BXE_R(key, decipherable)					\
		cs = 0; 							\
		*(decipherable + (cs++)) = '!';					\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '$';				\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '!';				\
		*(decipherable + cs) = '\0';			
	#define BXE_S(key, decipherable)					\
		cs = 0;								\
		*(decipherable + (cs++)) = '?';					\
		*(decipherable + (cs++)) = '>';					\
		for (int i = 0; i < key + 22; i++)				\
			*(decipherable + (cs++)) = '?';				\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '!';				\
		*(decipherable + cs) = '\0';			
	#define BXE_T(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '%';				\
		for (int i = 0; i < key + 1; i++)				\
			*(decipherable + (cs++)) = '&';				\
		*(decipherable + cs) = '\0';			
	#define BXE_U(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < 4; i++)					\
			*(decipherable + (cs++)) = '!';				\
		*(decipherable + (cs++)) = '<';					\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '$';				\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '<';				\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '!';				\
		*(decipherable + cs) = '\0';
	#define BXE_V(key, decipherable)					\
		cs = 0;								\
		*(decipherable + (cs++)) = '*';					\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '^';				\
		for (int i = 0; i < key + 12; i++)				\
			*(decipherable + (cs++)) = '>';				\
		*(decipherable + cs) = '\0';
	#define BXE_W(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < key * 4; i++)				\
			*(decipherable + (cs++)) = '$';				\
		*(decipherable + cs) = '\0';
	#define BXE_X(key, decipherable)					\
		cs = 0;								\
		*(decipherable + (cs++)) = '<';					\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '>';				\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '$';				\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '%';				\
		*(decipherable + cs) = '\0';
	#define BXE_Y(key, decipherable)					\
		cs = 0;								\
		*(decipherable + (cs++)) = '!';					\
		for (int i = 0; i < 2; i++)					\
			*(decipherable + (cs++)) = '>';				\
		*(decipherable + (cs++)) = '$';					\
		for (int i = 0; i < key * 2; i++)				\
			*(decipherable + (cs++)) = '!';				\
		*(decipherable + cs) = '\0';
	#define BXE_Z(key, decipherable)					\
		cs = 0;								\
		for (int i = 0; i < 4; i++)					\
			*(decipherable + (cs++)) = '?';				\
		*(decipherable + (cs++)) = '!';					\
		for (int i = 0; i < key; i++)					\
			*(decipherable + (cs++)) = '$';				\
		*(decipherable + (cs++)) = '?';					\
		*(decipherable + cs) = '\0';
		
#endif

typedef uint8_t key_bxe;

extern const char *alphabet;

extern void set_random_key(void);
extern void prep_file(char *filename);
extern char **read_from_inptf(void);
extern void write_to_outptf(char **buffer_read);
char *pls_encipher(char tocipher, key_bxe key);
char pls_decipher(char *deciferable, key_bxe key);
key_bxe determine_key(char *deciferable); 

#endif //__BXE_H__
