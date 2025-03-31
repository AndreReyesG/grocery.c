TARGET    = $(BIN_DIR)/test.out
OBJ_DIR = ../build/obj
BIN_DIR = ../build/bin
OBJS      = $(OBJ_DIR)/product.o \
			$(OBJ_DIR)/test.o \
			$(OBJ_DIR)/unity.o \
			$(OBJ_DIR)/category.o \
			$(OBJ_DIR)/category_test.o \
			$(OBJ_DIR)/product_test.o \
			$(OBJ_DIR)/helper.o
INC_DIR   = ../inc
SRC_DIR   = ../src
UNITY_DIR = ../unity
CFLAGS    = -Wall -I$(INC_DIR) -I$(SRC_DIR) -I$(UNITY_DIR)

# TODO: automatizar los prerequisitos de todos los targets

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	gcc $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/product.o: $(SRC_DIR)/product.c $(INC_DIR)/product.h
	mkdir -p $(OBJ_DIR)
	gcc -c $(CFLAGS) $(SRC_DIR)/product.c -o $(OBJ_DIR)/product.o

$(OBJ_DIR)/test.o: test.c $(INC_DIR)/product.h $(INC_DIR)/category_test.h $(INC_DIR)/product_test.h $(UNITY_DIR)/unity.h
	gcc -c $(CFLAGS) test.c -o $(OBJ_DIR)/test.o

$(OBJ_DIR)/unity.o: $(UNITY_DIR)/unity.c $(UNITY_DIR)/unity.h
	gcc -c $(CFLAGS) $(UNITY_DIR)/unity.c -o $(OBJ_DIR)/unity.o

$(OBJ_DIR)/category.o: $(SRC_DIR)/category.c $(INC_DIR)/category.h
	gcc -c $(CFLAGS) $(SRC_DIR)/category.c -o $(OBJ_DIR)/category.o

$(OBJ_DIR)/category_test.o: category_test.c $(INC_DIR)/category.h $(INC_DIR)/helper.h $(UNITY_DIR)/unity.h
	gcc -c $(CFLAGS) category_test.c -o $(OBJ_DIR)/category_test.o

$(OBJ_DIR)/product_test.o: product_test.c $(INC_DIR)/product.h $(INC_DIR)/helper.h $(UNITY_DIR)/unity.h
	gcc -c $(CFLAGS) product_test.c -o $(OBJ_DIR)/product_test.o

$(OBJ_DIR)/helper.o: helper.c $(INC_DIR)/helper.h
	gcc -c $(CFLAGS) helper.c -o $(OBJ_DIR)/helper.o
.PHONY: clean
clean:
	rm -rf ../build/*

.PHONY: test
test:
	./$(TARGET)
