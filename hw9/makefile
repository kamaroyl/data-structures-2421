#./Bank  (or whatever you call the TARGET)

CC = g++
CXXFLAGS = -g -std=c++11

ODIR=obj
SRC=src
TARGET=Dictionary

_OBJ = MyHashTable.o StringUtil.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_MAIN = main.o
MAIN = $(patsubst %,$(ODIR)/%,$(_MAIN))

$(ODIR)/%.o: $(SRC)/%.cpp
	mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ) $(MAIN)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY:  clean

clean:
	rm -rf $(ODIR) *~ core
	rm $(TARGET)
