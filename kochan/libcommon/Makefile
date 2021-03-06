# choice of compiles
CC=clang
CC=gcc 

# preprocess with these options usually called CPPFLAGS
PREPROCESSOR.FLAGS=-DLAB -DDEBUG
TESTBIN.PREPROCESSOR.FLAGS=-DLIBTEST -DTEST

# compile with these options usually called CFLAGS
COMPILE.FLAGS+=-g -Wall -pedantic -ansi --std=c99 # -Werror=unused-but-set-variable
# COMPILE.FLAGS+=-g -Wall -Wextra -Werror -pedantic -ansi --std=c99 # -Werror=unused-but-set-variable

# search for user header files in these directories
INCDIR=-I.

# add this to compile flags
COMPILE.FLAGS+=$(INCDIR)

# link time search for libraries in these directories
LINK.LIBDIRS=

# list of libraries to link with 
LINK.LIBS=

# link with these flags usually called LDFLAGS
LINK.FLAGS=$(LINK.LIBDIRS) $(LINK.LIBS)

# list of binaries to be built
BIN=
TESTBIN=test_libari test_libbase test_libinput

# list of libraries to be built
LIB=libinteger.a libreal.a libarray.a libmatrix.a libbase.a libinput.a

#
# default target - compile libraries and then binaries
#

all: 	lib bin 

lib: 	$(LIB)

bin:	$(BIN) $(TESTBIN)

# clean up and build everything again
rebuild: build

build:	clean all

clean:
	/bin/rm -f a.out *.o *.a *.core *.stackdump $(BIN) $(TESTBIN) $(LIB)
#
# end of Makefile template
#

test_libari: libari.c libari.h
	$(CC) -o $@ $(PREPROCESSOR.FLAGS) $(COMPILE.FLAGS) $(TESTBIN.PREPROCESSOR.FLAGS) libari.c -L. -linteger

test_libbase: libbase.c libbase.h
	$(CC) -o $@ $(PREPROCESSOR.FLAGS) $(COMPILE.FLAGS) $(TESTBIN.PREPROCESSOR.FLAGS) libbase.c -L. -larray -linteger

test_libinput: libinput.c libinput.h
	$(CC) -o $@ $(PREPROCESSOR.FLAGS) $(COMPILE.FLAGS) $(TESTBIN.PREPROCESSOR.FLAGS) libinput.c -L. -larray -linteger

# integer number library
libinteger.a: libnumi.o
	ar crs $@ libnumi.o

libnumi.o: libnumi.c
	$(CC) -o $@ $(PREPROCESSOR.FLAGS) $(COMPILE.FLAGS) -c $< 

# real number library
libreal.a: libnumf.o libnumd.o
	ar crs $@ libnumf.o libnumd.o

libnumf.o: libnumf.c
	$(CC) -o $@ $(PREPROCESSOR.FLAGS) $(COMPILE.FLAGS) -c $< 

libnumd.o: libnumd.c
	$(CC) -o $@ $(PREPROCESSOR.FLAGS) $(COMPILE.FLAGS) -c $<

# array library
libarray.a: libari.o libarc.o
	ar crs $@ libari.o libarc.o

# array renamed
libari.o: libari.c
	$(CC) -o $@ $(PREPROCESSOR.FLAGS) $(COMPILE.FLAGS) -c $< 

libarc.o: libarc.c
	$(CC) -o $@ $(PREPROCESSOR.FLAGS) $(COMPILE.FLAGS) -c $<

# matrix library
libmatrix.a: libmxi.o
	ar crs $@ libmxi.o

libmxi.o: libmxi.c
	$(CC) -o $@ $(PREPROCESSOR.FLAGS) $(COMPILE.FLAGS) -c $<

# base library
libbase.a: libbase.o
	ar crs $@ libbase.o

libbase.o: libbase.c
	$(CC) -o $@ $(PREPROCESSOR.FLAGS) $(COMPILE.FLAGS) -c $<

# inputs library
libinput.a: libinput.o
	ar crs $@ libinput.o

libinput.o: libinput.c
	$(CC) -o $@ $(PREPROCESSOR.FLAGS) $(COMPILE.FLAGS) -c $<

