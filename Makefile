CXX=g++ -std=c++11
CFLAGS=-I. -Wall -Werror
TARGET=eventflow
OBJS= Gate.o Security.o SoundTeam.o Stage.o Zones.o \
      MusicZone.o VendorZone.o Merch.o Refreshments.o \
      Crowd.o Artist.o main.o

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

leak:	
	valgrind --leak-check=full ./eventflow