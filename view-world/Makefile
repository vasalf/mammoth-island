CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -Wshadow --std=c++11 -g  -march=native -pipe -lGL -lGLU -lglut -lGLEW
OBJDIR=obj
OBJS=$(OBJDIR)/matrix.o $(OBJDIR)/mover.o $(OBJDIR)/geom.o $(OBJDIR)/polyhedron.o $(OBJDIR)/glmodule.o $(OBJDIR)/render.o $(OBJDIR)/main.o


all: view-world

view-world: $(OBJDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -oview-world

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

$(OBJDIR)/glmodule.o: glmodule.cpp glvars.h glheader.h
	$(CXX) $(CXXFLAGS) glmodule.cpp -c -o$(OBJDIR)/glmodule.o

$(OBJDIR)/render.o: render.cpp render.h
	$(CXX) $(CXXFLAGS) render.cpp -c -o$(OBJDIR)/render.o

$(OBJDIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -c -o$(OBJDIR)/main.o

clear:
	rm -Rf $(OBJDIR)
	rm -Rf view-world
