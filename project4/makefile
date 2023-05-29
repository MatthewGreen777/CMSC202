CXX = g++
CXXFLAGS = -Wall -g
OBJECTS = Game.o Room.o Entity.o Zombie.o Plant.o Buckethead.o Engineer.o Imp.o Chomper.o Sunflower.o Peashooter.o
IODIR =../../proj4_IO

proj4: $(OBJECTS) proj4.cpp
	$(CXX) $(CXXFLAGS) $(OBJECTS) proj4.cpp -o proj4

Game.o: Game.h Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Room.o: Room.cpp Room.h
	$(CXX) $(CXXFLAGS) -c Room.cpp

Engineer.o: Engineer.cpp Engineer.h Zombie.o
	$(CXX) $(CXXFLAGS) -c Engineer.cpp

Buckethead.o: Buckethead.cpp Buckethead.h Zombie.o
	$(CXX) $(CXXFLAGS) -c Buckethead.cpp

Imp.o: Imp.cpp Imp.h Zombie.o
	$(CXX) $(CXXFLAGS) -c Imp.cpp

Chomper.o: Chomper.cpp Chomper.h Plant.o
	$(CXX) $(CXXFLAGS) -c Chomper.cpp

Sunflower.o: Sunflower.cpp Sunflower.h Plant.o
	$(CXX) $(CXXFLAGS) -c Sunflower.cpp

Peashooter.o: Peashooter.cpp Peashooter.h Plant.o
	$(CXX) $(CXXFLAGS) -c Peashooter.cpp

Plant.o: Plant.cpp Plant.h Entity.o
	$(CXX) $(CXXFLAGS) -c Plant.cpp

Zombie.o: Zombie.cpp Zombie.h Entity.o
	$(CXX) $(CXXFLAGS) -c Zombie.cpp

Entity.o: Entity.cpp Entity.h
	$(CXX) $(CXXFLAGS) -c Entity.cpp

clean:
	rm *.o*
	rm *~ 

run1:
	./proj4 map1_data.txt

run2:
	./proj4 map2_data.txt

val1:
	valgrind ./proj4 map1_data.txt

val2:
	valgrind ./proj4 map2_data.txt

ta1:
	./proj4 $(IODIR)/ta1_data.txt

vta1:
	valgrind ./proj4 $(IODIR)/ta1_data.txt
