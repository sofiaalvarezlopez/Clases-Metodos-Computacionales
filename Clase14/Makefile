DIR = .
CXX = g++
CFLAGS = -std=c++11 -Wall -I$(INCDIR)
#CFLAGS = -std=c++1z -Wall -I$(INCDIR)

SRCDIR = $(DIR)/src
INCDIR = $(DIR)/inc
OBJDIR = $(DIR)/obj
EXE = Herencia

OBJECT = $(OBJDIR)/main.o $(OBJDIR)/TVector.o

all: $(EXE)

$(EXE): $(OBJECT)
	$(CXX) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	@rm $(EXE) $(OBJDIR)/*
