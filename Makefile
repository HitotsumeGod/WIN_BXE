#makec generated makefile
CC=gcc
ED=gedit
SRC=src/main
DEPS=src/headers -I /usr/local/include
RES=res
LIBPATH=/usr/local/lib
GS=$(SRC)/generator/pilot.c $(SRC)/generator/generator.c
TS=$(SRC)/translator/pilot.c $(SRC)/translator/translator.c

all: generator translator
generator: $(GS) $(RES)
	$(CC) -o $@ $(GS) -I $(DEPS) -L $(LIBPATH) -lsprocr
translator: $(TS) $(DEPS) $(RES)
	$(CC) -o $@ $(TS) -I $(DEPS)
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
