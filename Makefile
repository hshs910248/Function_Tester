INC_DIR = include
SRC_DIR = src
OBJ_DIR = build
LIB_DIR = lib
OBJSLIB = $(OBJ_DIR)/transpose.o\
		$(OBJ_DIR)/tensor_util.o\
		$(OBJ_DIR)/transpose_handle.o\
		$(OBJ_DIR)/_132handle.o\
		$(OBJ_DIR)/_213handle.o\
		$(OBJ_DIR)/_312handle.o\
		$(OBJ_DIR)/_321handle.o\
		$(OBJ_DIR)/_231handle.o
OBJTEST = $(OBJ_DIR)/test_transpose.o
CC = g++
CPPFLAGS = -I$(INC_DIR) -std=c++14 -O3

all: mkdir lib/libtranspose.a test_transpose

mkdir:
	mkdir -p $(OBJ_DIR)

test_transpose: lib/libtranspose.a $(OBJTEST)
	$(CC) -o $@ $^ -L$(LIB_DIR) -ltranspose

lib/libtranspose.a: $(OBJSLIB)
	mkdir -p $(LIB_DIR)
	rm -f lib/libtranspose.a
	ar -cvq lib/libtranspose.a $(OBJSLIB)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(OBJ_DIR)/%.d
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp
	@echo "$(CC) -MM $(CPPFLAGS) $< > $@"
	@$(CC) -MM $(CPPFLAGS) $< > $@.tmp
	@sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp > $@
	@rm -f $@.tmp
	
-include $(OBJSLIB:.o=.d)
	
clean:
	rm -f $(OBJ_DIR)/* lib/* $(EXEC)
