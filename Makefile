default: hw19.o other.o
	gcc -o hw19 hw19.c
	gcc -o other other.c
hw19.o: hw19.c
	gcc -c hw19.c
other.o: other.c
	gcc -c other.c
run:
	./hw19