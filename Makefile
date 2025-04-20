#makec generated makefile
CC=gcc
SRC=src/main
DEPS=src/headers
SRS=$(SRC)/pilot.c $(SRC)/generator.c

pilot: $(SRS)
	$(CC) -o $@ $^ -I $(DEPS)
clean: pilot
	rm -f $^
