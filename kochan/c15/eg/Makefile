# choice of compiles
CC=clang
CC=gcc 

# compile with these options usually called CFLAGS
COMPILE.FLAGS+=-g -Wall -Werror -pedantic -ansi --std=c99

# list of binaries to be built
BIN=testmod eg01 eg02 eg03 testmake

all: 	bin
bin:	$(BIN)

clean:
	/bin/rm -f a.out *.o *.a *.core $(BIN)

# binaries
# $@ is lhs
# $< is rhs
testmod: eg0mod1.c eg0mod2.c eg0main.c eg0mod.h
	$(CC) -o $@ $(COMPILE.FLAGS) eg0mod1.c eg0mod2.c eg0main.c

eg01: eg01.c eg01a.c eg01a.h
	$(CC) -o $@ $(COMPILE.FLAGS) eg01.c eg01a.c

eg02: eg02.c eg02a.c
	$(CC) -o $@ $(COMPILE.FLAGS) eg02.c eg02a.c

eg03: eg03.c date.h
	$(CC) -o $@ $(COMPILE.FLAGS) eg03.c

SRC = eg0mod1.c eg0mod2.c eg0main.c
OBJ = eg0mod1.o eg0mod2.o eg0main.o
PROG = testmake

$(PROG): $(OBJ)
	$(CC) $(OBJ) -o $(PROG)

$(OBJ): $(SRC)

