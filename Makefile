CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`
TARGET = app
SRC = main.c
ASM_SRC = bisiesto.asm
GLADE_FILE = Menu.glade

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC) $(ASM_SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(ASM_OBJ) $(LIBS)

$(ASM_OBJ): $(ASM_SRC)
	nasm -f elf64 $(ASM_SRC) -o bisiesto.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) bisiesto.o

