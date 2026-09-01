#include "Artist.h"

Artist::Artist(std::string zoneName, bool isLive, std::string artistName, std::string genre)
    : MusicZone(std::move(zoneName), isLive), genre(std::move(genre)), artistName(std::move(artistName)) {}
    
void Artist::describe() {
    std::cout << artistName << " performing some of the best of " << genre << "\n";
}