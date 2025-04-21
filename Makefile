#makec generated makefile
CC=gcc
SRC=src/main
DEPS=src/headers
RES=res
SRS=$(SRC)/pilot.c $(SRC)/generator.c

pilot: $(SRS) $(DEPS) $(RES)
	$(CC) -o $@ $(SRS) -I $(DEPS)
$(RES):
	if ! [ -d $@ ]; then		\
		mkdir $@;		\
	fi
clean: 
	rm -f pilot
	rm -rf res
