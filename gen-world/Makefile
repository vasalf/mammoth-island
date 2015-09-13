CXX=g++
SRCDIR=src
INCLUDEDIR=$(SRCDIR)/include
CXXFLAGS=-Wall -Wextra -Werror -Wshadow --std=c++11 -g  -march=native -pipe -I$(INCLUDEDIR)
OBJDIR=obj
OBJS=$(OBJDIR)/main.o $(OBJDIR)/world.o
GENERATORS=gen-random gen-gradient

all: gen-random gen-gradient

gen-random: $(OBJDIR) $(OBJS) $(OBJDIR)/gen-random.o
	$(CXX) $(CXXFLAGS) $(OBJS) $(OBJDIR)/gen-random.o -ogen-random

$(OBJDIR)/gen-random.o: $(SRCDIR)/gen-random.cpp
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/gen-random.cpp -o$(OBJDIR)/gen-random.o

gen-gradient: $(OBJDIR) $(OBJS) $(OBJDIR)/gen-gradient.o
	$(CXX) $(CXXFLAGS) $(OBJS) $(OBJDIR)/gen-gradient.o -ogen-gradient

$(OBJDIR)/gen-gradient.o: $(SRCDIR)/gen-gradient.cpp
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/gen-gradient.cpp -o$(OBJDIR)/gen-gradient.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.cpp -o$(OBJDIR)/main.o

$(OBJDIR)/world.o: $(SRCDIR)/world.cpp $(INCLUDEDIR)/world.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/world.cpp -o$(OBJDIR)/world.o

clean:
	rm -Rf $(GENERATORS)
	rm -Rf $(OBJDIR)
	
