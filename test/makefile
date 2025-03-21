TARGET    = $(BIN_DIR)/product_test.out
OBJ_DIR = ../build/obj
BIN_DIR = ../build/bin
OBJS      = $(OBJ_DIR)/product.o $(OBJ_DIR)/product_test.o $(OBJ_DIR)/unity.o
INC_DIR   = ../inc
SRC_DIR   = ../src
UNITY_DIR = ../unity
CFLAGS    = -Wall -I$(INC_DIR) -I$(SRC_DIR) -I$(UNITY_DIR)

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	gcc $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/product.o: $(SRC_DIR)/product.c $(INC_DIR)/product.h
	mkdir -p $(OBJ_DIR)
	gcc -c $(CFLAGS) $(SRC_DIR)/product.c -o $(OBJ_DIR)/product.o

$(OBJ_DIR)/product_test.o: product_test.c $(INC_DIR)/product.h $(UNITY_DIR)/unity.h
	gcc -c $(CFLAGS) product_test.c -o $(OBJ_DIR)/product_test.o

$(OBJ_DIR)/unity.o: $(UNITY_DIR)/unity.c $(UNITY_DIR)/unity.h
	gcc -c $(CFLAGS) $(UNITY_DIR)/unity.c -o $(OBJ_DIR)/unity.o

.PHONY: clean
clean:
	rm -rf ../build/*

.PHONY: test
test:
	./$(TARGET)
