#./FinalProject (or whatever you call the TARGET)

CC = g++
CXXFLAGS = -g -std=c++11

ODIR=obj
SRC=src
TARGET=FinalProject

_OBJ = Actor.o Picture.o ActorComparator.o PictureComparator.o ActorFilter.o ActorFilterAward.o ActorFilterFilm.o ActorFilterName.o ActorFilterWinner.o ActorFilterYear.o PictureFilter.o PictureFilterDuration.o PictureFilterGenre1.o PictureFilterGenre2.o PictureFilterMetacritic.o PictureFilterMonth.o PictureFilterName.o PictureFilterNominations.o PictureFilterRating.o PictureFilterSynopsis.o PictureFilterYear.o TreeManager.o CsvParser.o  CsvWriter.o Cli.o MenuBase.o ActorMenu.o AddActorMenu.o AddPictureMenu.o DeleteActorMenu.o DeletePictureMenu.o EditActorMenu.o EditPictureMenu.o MainMenu.o PictureMenu.o SearchActorMenu.o SearchPictureMenu.o ToFileActorMenu.o ToFilePictureMenu.o ExitMenu.o Database.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_MAIN = main.o
SUBDIRS = src lib
MAIN = $(patsubst %,$(ODIR)/%,$(_MAIN))
.PHONY: subdirs $(SUBDIRS)
subdires: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

$(ODIR)/%.o: $(SRC)/%.cpp
	mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ) $(MAIN)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY:  clean

clean:
	rm -rf $(ODIR) *~ core
	rm $(TARGET)
