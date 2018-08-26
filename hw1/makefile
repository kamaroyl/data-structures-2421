#./GuessingGame  (or whatever you call the TARGET)

CC = g++
CXXFLAGS = -g -std=c++11

ODIR=obj
SRC=src

_OBJ = GuessingGame.o main.o Util.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRC)/%.cpp 
	$(CC) -c -o $@ $< $(CXXFLAGS)

GuessingGame: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY:  clean

clean:
	rm -f $(ODIR)/*.o *~ core
