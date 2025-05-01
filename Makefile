#makec generated makefile
CC=gcc
ED=subl
SRC=src/main
DEPS=src/headers -I /usr/local/include
RES=res
LIBPATH=/usr/local/lib
GS=$(SRC)/generator/pilot.c $(SRC)/generator/generator.c
TS=$(SRC)/translator/pilot.c $(SRC)/translator/translator.c

all: generator translator
generator: $(GS) $(RES)
	$(CC) -o $@ $(GS) -I $(DEPS) -L $(LIBPATH) -lsprocr -g
translator: $(TS) $(DEPS) $(RES)
	$(CC) -o $@ $(TS) -I $(DEPS)
edit:
	$(ED) src/main/generator/*.c &
	$(ED) src/main/translator/*.c 
	$(ED) src/headers/*
$(RES):
	if ! [ -d $@ ]; then		\
		mkdir $@;		\
	fi
clean: 
	rm -f generator
	rm -f translator
	rm -rf res
