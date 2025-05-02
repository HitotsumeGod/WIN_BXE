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
	$(CC) -o $@ $(GS) -I $(DEPS) -L $(LIBPATH) -lsprocr 
translator: $(TS) $(RES)
	$(CC) -o $@ $(TS) -I $(DEPS) -L $(LIBPATH) -lsprocr
g.s: $(GS) 
	$(CC) -S $^ -I $(DEPS) -fno-asynchronous-unwind-tables -fno-ident -fomit-frame-pointer -masm=intel
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
	rm -f *.s
	rm -f *.o
	rm -rf res
