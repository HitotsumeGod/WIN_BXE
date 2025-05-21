#makec generated makefile
CC=gcc
SRC=src/main
DEPS=src/headers
BUILD=build
RES=res
GS=$(SRC)/generator/pilot.c $(SRC)/generator/generator.c
TS=$(SRC)/translator/pilot.c $(SRC)/translator/translator.c

all: $(BUILD)/generator $(BUILD)/translator
asm: $(BUILD)/g.s $(BUILD)/t.s
$(BUILD)/generator: $(GS) $(BUILD) $(RES)
	$(CC) -O3 -o $@ $(GS) -I $(DEPS) 
$(BUILD)/translator: $(TS) $(BUILD) $(RES)
	$(CC) -O3 -o $@ $(TS) -I $(DEPS) 
$(BUILD)/g.s: $(GS) $(BUILD)
	$(CC) -S -O3 -o $(BUILD)/pg.s $(SRC)/generator/pilot.c -I $(DEPS) -fno-asynchronous-unwind-tables -masm=intel
	$(CC) -S -O3 -o $(BUILD)/g.s $(SRC)/generator/generator.c -I $(DEPS) -fno-asynchronous-unwind-tables -masm=intel
$(BUILD)/t.s: $(TS) $(BUILD)
	$(CC) -S -O3 -o $(BUILD)/pt.s $(SRC)/translator/pilot.c -I $(DEPS) -fno-asynchronous-unwind-tables -masm=intel
	$(CC) -S -O3 -o $(BUILD)/t.s $(SRC)/translator/translator.c -I $(DEPS) -fno-asynchronous-unwind-tables -masm=intel
$(BUILD):
	if ! [ -d $@ ]; then		\
		mkdir $@;		\
	fi
$(RES):
	if ! [ -d $@ ]; then		\
		mkdir $@;		\
	fi
clean:	
	rm -rf $(BUILD)
	rm -rf $(RES)
