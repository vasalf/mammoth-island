CXX=g++
SRCDIR=src
INCLUDEDIR=$(SRCDIR)/include
CXXFLAGS=-Wall -Wextra -Werror -Wshadow --std=c++11 -O2  -march=native -pipe -lGL -lGLU -lglut -lGLEW -I$(INCLUDEDIR)
OBJDIR=obj
OBJS=$(OBJDIR)/matrix.o $(OBJDIR)/mover.o $(OBJDIR)/geom.o $(OBJDIR)/polyhedron.o $(OBJDIR)/glmodule.o $(OBJDIR)/render.o $(OBJDIR)/main.o $(OBJDIR)/world.o $(OBJDIR)/draw_world.o $(OBJDIR)/camera.o


all: view-world

view-world: $(OBJDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -oview-world

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/matrix.o: $(INCLUDEDIR)/matrix.h $(SRCDIR)/matrix.cpp
	$(CXX) $(CXXFLAGS) $(SRCDIR)/matrix.cpp -c -o$(OBJDIR)/matrix.o

$(OBJDIR)/mover.o: $(INCLUDEDIR)/mover.h $(SRCDIR)/mover.cpp
	$(CXX) $(CXXFLAGS) $(SRCDIR)/mover.cpp -c -o$(OBJDIR)/mover.o

$(OBJDIR)/geom.o: $(INCLUDEDIR)/geom.h $(SRCDIR)/geom.cpp
	$(CXX) $(CXXFLAGS) $(SRCDIR)/geom.cpp -c -o$(OBJDIR)/geom.o

$(OBJDIR)/polyhedron.o: $(INCLUDEDIR)/polyhedron.h $(SRCDIR)/polyhedron.cpp
	$(CXX) $(CXXFLAGS) $(SRCDIR)/polyhedron.cpp -c -o$(OBJDIR)/polyhedron.o

$(OBJDIR)/glmodule.o: $(SRCDIR)/glmodule.cpp $(INCLUDEDIR)/glvars.h $(INCLUDEDIR)/glheader.h
	$(CXX) $(CXXFLAGS) $(SRCDIR)/glmodule.cpp -c -o$(OBJDIR)/glmodule.o

$(OBJDIR)/render.o: $(SRCDIR)/render.cpp $(INCLUDEDIR)/render.h
	$(CXX) $(CXXFLAGS) $(SRCDIR)/render.cpp -c -o$(OBJDIR)/render.o

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(SRCDIR)/main.cpp -c -o$(OBJDIR)/main.o

$(OBJDIR)/world.o: $(SRCDIR)/world.cpp $(INCLUDEDIR)/world.h
	$(CXX) $(CXXFLAGS) $(SRCDIR)/world.cpp -c -o$(OBJDIR)/world.o

$(OBJDIR)/draw_world.o: $(SRCDIR)/draw_world.cpp $(INCLUDEDIR)/draw_world.h
	$(CXX) $(CXXFLAGS) $(SRCDIR)/draw_world.cpp -c -o$(OBJDIR)/draw_world.o

$(OBJDIR)/camera.o: $(SRCDIR)/camera.cpp $(INCLUDEDIR)/camera.h
	$(CXX) $(CXXFLAGS) $(SRCDIR)/camera.cpp -c -o$(OBJDIR)/camera.o

clean:
	rm -Rf $(OBJDIR)
	rm -Rf view-world
