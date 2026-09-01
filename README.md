# Prac3_214
Core topics: Observer, Composite, UML sequence diagrams, Doxygen, Git/GitHub

# Members
Bianca Kritzman
Lillian Muller
Hayley Nel

# Makefile
Runs with make all
./EventFlow

# Event concept
A music festival where everything functions smoothly, the SoundTeams gets messages when artists are done performing so they can call the new artists up on stage. There are max capacities for each stage and when that capacity is reached then the gates 
for that stage will be closed. The gates stay open if the stage is not at max capacity yet. There are different zones inside the music festival, the vendor zone has refreshments and merch
stands. If merch goes up for sale there will be a message sent to the SoundTeam and they will make an announcement saying that
there is merch for a specific artist. If there is theft then there will be a message sent to the security team and they will be deployed in the VendorZone to try stop the thief.
There is also a way to get the Schedule for all the artists when there is an update of the schedule.

# Doxygen

# Architecture overview
MusicFestivalObserver class has classes inheriting from it, Stage, Security, SoundTeam and Zones. Gate inherits from Stage. MusicZone and VendorZone inherits from Zones and Crowd and Artist inherits from MusicZone and Refreshment and Merch inherits from VendorZone.

# Using Push Observer

# Notice in UML is an struct