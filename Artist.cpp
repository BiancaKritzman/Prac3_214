#include "Artist.h"

Artist::Artist(std::string zoneName, bool isLive, std::string artistName, std::string genre)
    : MusicZone(std::move(zoneName), isLive), artistName(std::move(artistName)), genre(std::move(genre)) {}

void Artist::describe() {
    std::cout << artistName << " performing some of the best of " << genre << "\n";
}