MF=     Makefile

CC=     g++

CFLAGS= -g -D_USE_64 -msse3 -O3 -fomit-frame-pointer -funroll-loops 

LFLAGS= -std=c++11 -DNDEBUG -I ./libFLASM/include -L ./libFLASM/lib -lflasm -Wl,-rpath=$(PWD)/libFLASM/lib -I ./include/

EXE=    dbflasm

SRC=    main.cc utils.cc ngram.cc debruijn.cc functions.cc

HD=     main.h Makefile

#
# No need to edit below this line 
#


.SUFFIXES:
.SUFFIXES: .cc .o

OBJ=	$(SRC:.cc=.o)

.cc.o:
	$(CC) $(CFLAGS)-c $(LFLAGS) $<

all:	$(EXE)

$(EXE):	$(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LFLAGS)

$(OBJ):	$(MF) $(HD)

clean:
	rm -f $(OBJ) $(EXE)

