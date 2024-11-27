CFLAGS = -ansi -Wall -pedantic
CC = gcc
letters.o: letters.c
	$(CC) $(CFLAGS) -c letters.c

xy_bits.o: xy_bits.c
	$(CC) $(CFLAGS) -c xy_bits.c



clean:
	@echo "Removing EVERYTHING"
	rm -f letters.o letters xy_bits xy_bits.o