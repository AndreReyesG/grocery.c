TARGET = $(BIN_DIR)/main.out
OBJ_DIR = ../build/obj
BIN_DIR = ../build/bin
INC_DIR = ../inc
OBJS      = $(OBJ_DIR)/main.o \
			$(OBJ_DIR)/product.o \
			$(OBJ_DIR)/category.o
CFLAGS = -Wall -I$(INC_DIR)

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	gcc $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/main.o: main.c $(INC_DIR)/product.h $(INC_DIR)/category.h
	mkdir -p $(OBJ_DIR)
	gcc -c $(CFLAGS) main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/product.o: product.c $(INC_DIR)/product.h
	gcc -c $(CFLAGS) product.c -o $(OBJ_DIR)/product.o

$(OBJ_DIR)/category.o: category.c $(INC_DIR)/category.h
	gcc -c $(CFLAGS) category.c -o $(OBJ_DIR)/category.o

.PHONY: clean
clean:
	rm -rf ../build/*

.PHONY: run
run:
	./$(TARGET)
