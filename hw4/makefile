#./MyVector  (or whatever you call the TARGET)

CC = g++
CXXFLAGS = -g -std=c++11

ODIR=obj
SRC=src
TEST=test

_OBJ = MyVector.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_MAIN = main.o
MAIN = $(patsubst %,$(ODIR)/%,$(_MAIN))

$(ODIR)/%.o: $(SRC)/%.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

MyVector: $(OBJ) $(MAIN)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY:  clean

clean:
	rm -f $(ODIR)/*.o *~ core
