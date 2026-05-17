#include <iostream>
#include "SleepingPlace.h"
#include "Hut.h"
#include "Camping.h"
#include "Room.h"

int main() {
    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║    HIKING MANAGEMENT SYSTEM - CHECKPOINT 2        ║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n";

    // Create Hut
    Hut hutRila("Rila Monastery Hut", 42.1354, 23.6552, 2298, true, true, true);

    // Add rooms to hut
    auto room1 = std::make_shared<Room>(2, 45.0, false, "101");
    auto room2 = std::make_shared<Room>(4, 35.0, true, "102");
    auto room3 = std::make_shared<Room>(3, 40.0, false, "201");

    hutRila.addRoom(room1);
    hutRila.addRoom(room2);
    hutRila.addRoom(room3);

    std::cout << "\n=== HUT INFORMATION ===\n";
    hutRila.printInfo();

    // Create Camping
    Camping campingBorovets("Borovets Mountain Camp", 42.6988, 23.2000, 1356, 50, 20, 25.0, "планински");

    std::cout << "\n=== CAMPING INFORMATION ===\n";
    campingBorovets.printInfo();

    // Demonstrate polymorphism
    std::cout << "\n=== POLYMORPHIC USAGE ===\n";
    SleepingPlace* places[] = {&hutRila, &campingBorovets};
    
    for (int i = 0; i < 2; ++i) {
        std::cout << "\nPlace " << (i + 1) << ":\n";
        std::cout << "  Name: " << places[i]->getName() << "\n";
        std::cout << "  Description: " << places[i]->getDescription() << "\n";
        std::cout << "  Altitude: " << places[i]->getAltitude() << " m\n";
    }

    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║              DEMO COMPLETED SUCCESSFULLY           ║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n\n";

    return 0;
}
