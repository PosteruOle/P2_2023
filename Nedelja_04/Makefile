izvrsni: polinom.o polinom_main.o
	gcc polinom.o polinom_main.o -o izvrsni
polinom.o: polinom.c polinom.h
	gcc -c -Wall polinom.c -o polinom.o
polinom_main.o: polinom_main.c
	gcc -c -Wall polinom_main.c -o polinom_main.o

.PHONY: clean

clean: 
	rm izvrsni