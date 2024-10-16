CC=gcc
NASM=nasm
CFLAGS=`pkg-config --cflags --libs gtk+-3.0`
ASMFLAGS=-f elf64

all: app

app: main.o bisiesto.o
	$(CC) -o $@ $^ $(CFLAGS)

main.o: main.c
	$(CC) -c $< $(CFLAGS)

bisiesto.o: bisiesto.asm
	$(NASM) $(ASMFLAGS) $< -o $@

run: app
	./app

clean:
	rm -f *.o app

