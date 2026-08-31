#include "Zones.h"
#include "MusicZone.h"
#include "VendorZone.h"
#include "Gate.h"
#include "Stage.h"
#include "Security.h"
#include "SoundTeam.h"
#include "Merch.h"
#include "Refreshments.h"
#include "Crowd.h"
#include "Artist.h"

int main() {
    // build composite tree
    Zones* mainZone = new Zones("Main Grounds");
    MusicZone* musicZone = new MusicZone("Music Zone", true);
    VendorZone* vendorZone = new VendorZone("Vendor Zone", 4);

    Gate* gate = new Gate(true, "G1");
    Stage* stage = new Stage("Billie Eilish");
    Crowd* crowd = new Crowd("Main Stage Crowd", true, 500);
    Artist* artist = new Artist("Main Stage Artist", true, "Billie Eilish", "Pop");

    Merch* merchStand = new Merch("Merch Stall", 1, "Billie Eilish");
    Refreshments* refreshments = new Refreshments("Refreshments Stall", 1, "Festival Foods", 200, vendorZone);

    SoundTeam* soundTeam = new SoundTeam();
    Security* security = new Security(5, "Main Grounds", mainZone);

    mainZone->add(musicZone);
    mainZone->add(vendorZone);

    musicZone->add(gate);
    musicZone->add(stage);
    musicZone->add(crowd);
    musicZone->add(artist);

    vendorZone->add(merchStand);
    vendorZone->add(refreshments);

    // registering observers 
    mainZone->attach(musicZone);
    mainZone->attach(vendorZone);
    mainZone->attach(soundTeam);

    musicZone->attach(gate);
    musicZone->attach(stage);

    vendorZone->attach(merchStand);
    vendorZone->attach(refreshments);

    // capacity alert notice
    security->dispatchToZone("Music Zone");

    // runtime reassignment of merchStand from vendorZone to musicZone
    vendorZone->remove(merchStand);
    vendorZone->detach(merchStand);
    musicZone->add(merchStand);
    musicZone->attach(merchStand);

    soundTeam->makeAnnouncement("New merch has arrived for Billie Eilish!");

    // more notice types
    Notice gateOpenNotice{"GATE_OPEN", "Music Zone", "Manual override: reopen gate", 0, 0};
    mainZone->notify(gateOpenNotice);

    Notice gateCloseNotice{"GATE_CLOSE", "Music Zone", "Manual override: close gate", 0, 0};
    mainZone->notify(gateCloseNotice);

    Notice scheduleNotice{"BROADCAST_SCHEDULE", "Music Zone", "Billie Eilish now on at 8PM", 0, 0};
    mainZone->notify(scheduleNotice);

    Notice merchNotice{"ANNOUNCE_MERCH", "Music Zone", "Billie Eilish", 0, 0};
    mainZone->notify(merchNotice);

    Notice theftNotice{"REPORT_THEFT", "Vendor Zone", "Reported at Refreshments stall", 0, 0};

vendorZone->attach(security);
vendorZone->attach(soundTeam);

refreshments->reportTheft("A cooler of drinks");


    // composite traversal and description
    std::cout << "\n--- Full event structure ---\n";
    mainZone->describe();

    // deletes
    delete mainZone;    // cascades through musicZone, vendorZone, and everything they still own
    delete soundTeam;   // not part of the tree — owned by no one
    delete security;

    return 0;
}

//Root destruction for 2.3

// #include <iostream>
// #include "Zones.h"
// #include "VendorZone.h"
// #include "MusicZone.h"
// #include "Gate.h"
// #include "Stage.h"
// #include "Security.h"
// #include "SoundTeam.h"

// int main() {
//     std::cout << "--- Constructing Composite Hierarchy ---\n";

//     //root
//     Zones* mainFestivalZone = new Zones("Main Festival Grounds");

//     //composite
//     VendorZone* vendorArea = new VendorZone("Vendor Alley", 12);
//     MusicZone* mainStageZone = new MusicZone("Main Stage Zone", true);

//     //leaves
//     Gate* mainGate = new Gate(true);
//     Stage* mainStage = new Stage("The Midnight Echoes");
//     SoundTeam* soundTeam = new SoundTeam();
//     Security* securityTeam = new Security(5, "Vendor Alley", mainFestivalZone);

//     //build Subtrees
//     vendorArea->add(securityTeam);      
//     mainStageZone->add(mainStage);  
//     mainStageZone->add(soundTeam);    

//     //build Root Tree
//     mainFestivalZone->add(vendorArea);    
//     mainFestivalZone->add(mainStageZone); 
//     mainFestivalZone->add(mainGate);     

//     //observers (Non-owning references)
//     mainFestivalZone->attach(mainGate);
//     mainFestivalZone->attach(securityTeam);

//     std::cout << "\n--- Describing Hierarchy ---\n";
//     mainFestivalZone->describe();

//     std::cout << "\n--- Destroying Root Composite ---\n";
//     //recursively deletes vendorArea, mainStageZone, mainGate,
//     //securityTeam, mainStage, and soundTeam exactly once.
//     delete mainFestivalZone;

//     return 0;
// }