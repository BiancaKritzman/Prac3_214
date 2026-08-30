// just a shell of main for the observer functions for now, we can change it later :p

#include "Zones.h"
#include "MusicZone.h"
#include "VendorZone.h"
#include "Gate.h"
#include "Security.h"
#include "SoundTeam.h"
#include "Merch.h"
#include "Notice.h"

int main() {
    // ---- Phase 1 (SD1): building the composite tree ----
    Zones* mainZone = new Zones("Main Grounds");
    MusicZone* musicZone = new MusicZone("Music Zone");
    VendorZone* vendorZone = new VendorZone("Vendor Zone", 4);
    Gate* gate = new Gate();
    Merch* merchStand = new Merch("DJ Nova");
    SoundTeam* soundTeam = new SoundTeam(); 
    Security* security = new Security(5, "Main Grounds", mainZone);

    mainZone->add(musicZone);
    musicZone->add(gate);
    mainZone->add(vendorZone);
    vendorZone->add(merchStand);

    // ---- Observer registration ----
    mainZone->attach(musicZone);
    musicZone->attach(gate);
    vendorZone->attach(merchStand);

    // ---- SD4 Phase 1: capacity alert cascades down to Gate ----
    security->dispatchToZone("Music Zone");

    // ---- SD4 Phase 2: runtime reassignment ----
    vendorZone->remove(merchStand);
    vendorZone->detach(merchStand);
    musicZone->add(merchStand);
    musicZone->attach(merchStand);

    soundTeam->makeAnnouncement("New merch has arrived for DJ Nova!");

    // ---- Clean shutdown ----
    delete mainZone;     // cascades: deletes musicZone, vendorZone, gate, merchStand
    delete soundTeam;     // not part of the tree — owned by no one, deleted manually
    delete security;

    return 0;
}