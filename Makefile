# the variable CC will be
CC=gcc
# OPTs will be the options I'll pass to the compiler
# -Wall turns on warning flags:
# -c  Compile or assemble the source files, but do not link
OPTs=-c -Wall

exec: main.o parsing.o util.o
	$(CC) main.o parsing.o util.o -o exec

main.o: main.c util.h parsing.h
	$(CC) $(OPTs) main.c

parsing.o: parsing.c parsing.h util.h
	$(CC) $(OPTs) parsing.c

util.o: util.c util.h
	$(CC) $(OPTs) util.c

clean:
	rm *.o exec

run:
	make exec && ./exec