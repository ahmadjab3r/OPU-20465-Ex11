CFLAGS = -Wno-implicit-function-declaration

letters.o: letters.c
	@echo "hi"
	gcc $(CFLAGS) -c letters.c
	chmod +x letters.o



clean:
	@echo "Removing EVERYTHING"
	rm -f letters.o letters