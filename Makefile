all: sed_simple
.PHONY: test
sed_simple: main.o func.o
        gcc -o sed_simple main.o func.o

main.o: main.c
        gcc -c main.c

func.o: func.c
        gcc -c func.c

test: sed_simple
        ./sed_simple input.txt -i -f FUCK
clean:
        rm sed_simple *.o