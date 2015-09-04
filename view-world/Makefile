CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -Wshadow --std=c++11 -O2 -pipe
OBJDIR=obj
OBJS=$(OBJDIR)/matrix.o $(OBJDIR)/mover.o $(OBJDIR)/geom.o $(OBJDIR)/polyhedron.o


all: $(OBJDIR) $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/matrix.o: matrix.h matrix.cpp
	$(CXX) $(CXXFLAGS) matrix.cpp -c -o$(OBJDIR)/matrix.o

$(OBJDIR)/mover.o: mover.h mover.cpp
	$(CXX) $(CXXFLAGS) mover.cpp -c -o$(OBJDIR)/mover.o

$(OBJDIR)/geom.o: geom.h geom.cpp
	$(CXX) $(CXXFLAGS) geom.cpp -c -o$(OBJDIR)/geom.o

$(OBJDIR)/polyhedron.o: polyhedron.h polyhedron.cpp
	$(CXX) $(CXXFLAGS) polyhedron.cpp -c -o$(OBJDIR)/polyhedron.o

clear:
	rm -Rf $(OBJDIR)
