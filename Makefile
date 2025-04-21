#makec generated makefile
CC=gcc
ED=gedit
SRC=src/main
DEPS=src/headers
RES=res
GS=$(SRC)/generator/pilot.c $(SRC)/generator/generator.c $(SRC)/translator/translator.c

all: generator translator
generator: $(GS) $(DEPS) $(RES)
	$(CC) -o $@ $(GS) -I $(DEPS)
translator: $(DEPS) $(RES)
	$(CC) -o $@ $(SRC)/translator/pilot.c $(SRC)/translator/translator.c -I $(DEPS)
edit:
	gedit src/main/generator/*.c &
	gedit src/main/translator/*.c 
	gedit src/headers/*
$(RES):
	if ! [ -d $@ ]; then		\
		mkdir $@;		\
	fi
clean: 
	rm -f generator
	rm -f translator
	rm -rf res
