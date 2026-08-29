CXX=g++ -std=c++11
CFLAGS=-I. -Wall -Werror
TARGET=engine
OBJS= Gate.o MusicFestivalObserver.o Security.o \
      SoundDesk.o Stage.o Zone.o \

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)