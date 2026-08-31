CXX=g++ -std=c++11
CFLAGS=-I. -Wall -Werror
TARGET=engine
OBJS= Gate.o MusicFestivalObserver.o Security.o \
      SoundTeam.o Stage.o Zones.o MusicZone.o VendorZone.o\
	  Crowd.o Artist.o Refreshments.o Merch.o 

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)