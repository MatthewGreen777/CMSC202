CXX = g++
CXXFLAGS = -Wall -g

proj5: MediaPlayer.o Media.o proj5.cpp Tqueue.cpp
	$(CXX) $(CXXFLAGS) MediaPlayer.o Media.o Tqueue.cpp proj5.cpp -o proj5

MediaPlayer.o: MediaPlayer.cpp  MediaPlayer.h Media.o Tqueue.cpp
	$(CXX) $(CXXFLAGS) -c MediaPlayer.cpp

Media.o: Media.cpp Media.h
	$(CXX) $(CXXFLAGS) -c Media.cpp

Tqueue.o: Tqueue.cpp
	$(CXX) $(CXXFLAGS) -c Tqueue.cpp

run:
	./proj5

run1:
	./proj5 proj5_media.txt

val1:
	valgrind ./proj5 proj5_media.txt

##Use this to clean out your directory
clean: 
	rm *~
	rm *.o

##Use this when you want to test just your Tqueue
ttest: Tqueue.o tqueue_test.cpp
	$(CXX) $(CXXFLAGS) Tqueue.o tqueue_test.cpp -o ttest

##Use this when you want to valgrind your Tqueue tests
ttest2:
	valgrind ./ttest

##Use this when you want to debug your whole project
debug1:
	gdb gdbarg1 --args ./proj5 proj5_media.txt

##Use this when you want to submit your files (from your proj5 directory)
submit:
	cp Tqueue.cpp Media.h Media.cpp MediaPlayer.h MediaPlayer.cpp proj5.cpp ~/afs/umbc.edu/users/j/d/jdixon/pub/cmsc202/$USER
