#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include "SleepingPlace.h"
#include "Hut.h"
#include "Camping.h"
#include "Room.h"
#include "Trail.h"

int testsPassed = 0;
int testsFailed = 0;

void printTestHeader(const std::string& testName) {
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║ TEST: " << std::left << std::setw(31) << testName << "║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
}

void assertTest(bool condition, const std::string& message) {
    if (condition) {
        std::cout << "✓ " << message << "\n";
        testsPassed++;
    } else {
        std::cout << "✗ FAILED: " << message << "\n";
        testsFailed++;
    }
}

// ===== Room Tests =====
void testRoom() {
    printTestHeader("Room Class");
    
    Room room(4, 50.0, true, "205");
    
    assertTest(room.getBedCount() == 4, "Constructor sets bed count");
    assertTest(std::abs(room.getPricePerBed() - 50.0) < 0.01, "Constructor sets price per bed");
    assertTest(room.hasPrivateBathroom() == true, "Constructor sets bathroom flag");
    assertTest(room.getRoomNumber() == "205", "Constructor sets room number");
    
    assertTest(std::abs(room.getTotalPrice() - 200.0) < 0.01, "getTotalPrice() = 4 * 50 = 200");
    
    room.setBedCount(6);
    assertTest(room.getBedCount() == 6, "setBedCount() works");
    assertTest(std::abs(room.getTotalPrice() - 300.0) < 0.01, "getTotalPrice() updates = 6 * 50 = 300");
    
    room.setPricePerBed(40.0);
    assertTest(std::abs(room.getPricePerBed() - 40.0) < 0.01, "setPricePerBed() works");
    assertTest(std::abs(room.getTotalPrice() - 240.0) < 0.01, "getTotalPrice() updates = 6 * 40 = 240");
    
    room.setPrivateBathroom(false);
    assertTest(room.hasPrivateBathroom() == false, "setPrivateBathroom() works");
    
    room.setRoomNumber("301");
    assertTest(room.getRoomNumber() == "301", "setRoomNumber() works");
    
    std::string desc = room.getDescription();
    assertTest(desc.find("6") != std::string::npos, "getDescription() contains bed count");
    assertTest(desc.find("40") != std::string::npos, "getDescription() contains price");
    
    std::cout << "\nRoom description: " << desc << "\n";
    room.printInfo();
}

// ===== Hut Tests =====
void testHut() {
    printTestHeader("Hut Class");
    
    Hut hut("Musala Peak Hut", 42.5, 23.8, 2925, true, true, true);
    
    assertTest(hut.getName() == "Musala Peak Hut", "Constructor sets name");
    assertTest(std::abs(hut.getLatitude() - 42.5) < 0.01, "Constructor sets latitude");
    assertTest(std::abs(hut.getLongitude() - 23.8) < 0.01, "Constructor sets longitude");
    assertTest(hut.getAltitude() == 2925, "Constructor sets altitude");
    
    assertTest(hut.getDiningHall() == true, "Constructor sets dining hall flag");
    assertTest(hut.getElectricity() == true, "Constructor sets electricity flag");
    assertTest(hut.getWater() == true, "Constructor sets water flag");
    
    assertTest(hut.getRoomCount() == 0, "Initially has 0 rooms");
    
    auto room1 = std::make_shared<Room>(3, 45.0, true, "101");
    auto room2 = std::make_shared<Room>(2, 55.0, false, "102");
    auto room3 = std::make_shared<Room>(4, 40.0, true, "201");
    
    hut.addRoom(room1);
    assertTest(hut.getRoomCount() == 1, "addRoom() increases room count to 1");
    
    hut.addRoom(room2);
    hut.addRoom(room3);
    assertTest(hut.getRoomCount() == 3, "addRoom() increases room count to 3");
    
    auto retrievedRoom = hut.getRoom(0);
    assertTest(retrievedRoom != nullptr, "getRoom(0) returns valid pointer");
    assertTest(retrievedRoom->getBedCount() == 3, "getRoom(0) returns first room");
    
    retrievedRoom = hut.getRoom(1);
    assertTest(retrievedRoom->getBedCount() == 2, "getRoom(1) returns second room");
    
    assertTest(hut.getRoom(5) == nullptr, "getRoom(5) returns nullptr for invalid index");
    
    hut.setDiningHall(false);
    assertTest(hut.getDiningHall() == false, "setDiningHall() works");
    
    hut.setElectricity(false);
    assertTest(hut.getElectricity() == false, "setElectricity() works");
    
    hut.setWater(false);
    assertTest(hut.getWater() == false, "setWater() works");
    
    std::string desc = hut.getDescription();
    assertTest(desc.find("3") != std::string::npos, "getDescription() contains room count");
    
    std::cout << "\nHut description: " << desc << "\n";
    std::cout << "Hut amenities: " << hut.getAmenities() << "\n";
    hut.printInfo();
}

// ===== Camping Tests =====
void testCamping() {
    printTestHeader("Camping Class");
    
    Camping camping("Mountain Camp", 43.2, 24.5, 1500, 100, 50, 30.0, "планински");
    
    assertTest(camping.getName() == "Mountain Camp", "Constructor sets name");
    assertTest(std::abs(camping.getLatitude() - 43.2) < 0.01, "Constructor sets latitude");
    assertTest(std::abs(camping.getLongitude() - 24.5) < 0.01, "Constructor sets longitude");
    assertTest(camping.getAltitude() == 1500, "Constructor sets altitude");
    
    assertTest(camping.getTentCapacity() == 100, "Constructor sets tent capacity");
    assertTest(camping.getGroundSpaces() == 50, "Constructor sets ground spaces");
    assertTest(std::abs(camping.getTripodFee() - 30.0) < 0.01, "Constructor sets tripod fee");
    assertTest(camping.getCampingType() == "планински", "Constructor sets camping type");
    
    assertTest(camping.getTotalCapacity() == 150, "getTotalCapacity() = 100 + 50 = 150");
    
    assertTest(std::abs(camping.calculateTentIncome(50) - 1500.0) < 0.01, "calculateTentIncome(50) = 50 * 30 = 1500");
    assertTest(std::abs(camping.calculateTentIncome(100) - 3000.0) < 0.01, "calculateTentIncome(100) = 100 * 30 = 3000");
    
    camping.setTentCapacity(80);
    assertTest(camping.getTentCapacity() == 80, "setTentCapacity() works");
    
    camping.setGroundSpaces(60);
    assertTest(camping.getGroundSpaces() == 60, "setGroundSpaces() works");
    assertTest(camping.getTotalCapacity() == 140, "getTotalCapacity() updates = 80 + 60 = 140");
    
    camping.setTripodFee(35.0);
    assertTest(std::abs(camping.getTripodFee() - 35.0) < 0.01, "setTripodFee() works");
    assertTest(std::abs(camping.calculateTentIncome(50) - 1750.0) < 0.01, "calculateTentIncome() updates = 50 * 35 = 1750");
    
    camping.setCampingType("морски");
    assertTest(camping.getCampingType() == "морски", "setCampingType() works");
    
    std::string desc = camping.getDescription();
    assertTest(desc.find("80") != std::string::npos, "getDescription() contains tent capacity");
    assertTest(desc.find("60") != std::string::npos, "getDescription() contains ground spaces");
    
    std::cout << "\nCamping description: " << desc << "\n";
    std::cout << "Camping facilities: " << camping.getFacilitiesInfo() << "\n";
    camping.printInfo();
}

// ===== SleepingPlace (via Hut) Tests =====
void testSleepingPlace() {
    printTestHeader("SleepingPlace Base Class (via Hut)");
    
    Hut hut("Test Hut", 42.0, 23.0, 2000);
    
    assertTest(hut.getName() == "Test Hut", "getName() works");
    assertTest(std::abs(hut.getLatitude() - 42.0) < 0.01, "getLatitude() works");
    assertTest(std::abs(hut.getLongitude() - 23.0) < 0.01, "getLongitude() works");
    assertTest(hut.getAltitude() == 2000, "getAltitude() works");
    
    hut.setName("Updated Hut");
    assertTest(hut.getName() == "Updated Hut", "setName() works");
    
    hut.setCoordinates(43.0, 24.0);
    assertTest(std::abs(hut.getLatitude() - 43.0) < 0.01, "setCoordinates() updates latitude");
    assertTest(std::abs(hut.getLongitude() - 24.0) < 0.01, "setCoordinates() updates longitude");
    
    hut.setAltitude(2500);
    assertTest(hut.getAltitude() == 2500, "setAltitude() works");
    
    hut.printInfo();
}

// ===== Polymorphism Tests =====
void testPolymorphism() {
    printTestHeader("Polymorphism & Virtual Methods");
    
    Hut hut("Poly Test Hut", 42.0, 23.0, 2000);
    Camping camping("Poly Test Camp", 43.0, 24.0, 1500, 50, 25, 25.0);
    
    SleepingPlace* places[] = {&hut, &camping};
    
    std::string desc1 = places[0]->getDescription();
    std::string desc2 = places[1]->getDescription();
    
    assertTest(places[0]->getDescription() == hut.getDescription(), 
               "Polymorphism: places[0]->getDescription() calls Hut::getDescription()");
    assertTest(places[1]->getDescription() == camping.getDescription(), 
               "Polymorphism: places[1]->getDescription() calls Camping::getDescription()");
    
    assertTest(places[0]->getAltitude() == 2000, "Polymorphism: getAltitude() works on Hut pointer");
    assertTest(places[1]->getAltitude() == 1500, "Polymorphism: getAltitude() works on Camping pointer");
    
    std::cout << "\nPolymorphic calls through base class pointers:\n";
    std::cout << "places[0]->getDescription(): " << places[0]->getDescription() << "\n";
    std::cout << "places[1]->getDescription(): " << places[1]->getDescription() << "\n";
}

// ===== Trail Tests =====
void testTrail() {
    printTestHeader("Trail Class");
    
    // Create sleeping places for trail endpoints
    auto hut1 = std::make_shared<Hut>("Rila Hut", 42.1354, 23.6552, 2298, true, true, true);
    auto hut2 = std::make_shared<Hut>("Pirin Hut", 41.75, 23.5, 2150, true, false, true);
    
    // Create trail with positive denivelation (net downhill)
    Trail trail1(hut1, hut2, 15.5, 500.0, -148.0, 3);
    
    assertTest(trail1.getStart()->getName() == "Rila Hut", "Constructor sets start point");
    assertTest(trail1.getEnd()->getName() == "Pirin Hut", "Constructor sets end point");
    assertTest(std::abs(trail1.getLengthKm() - 15.5) < 0.01, "Constructor sets length");
    assertTest(std::abs(trail1.getElevationGainM() - 500.0) < 0.01, "Constructor sets elevation gain");
    assertTest(std::abs(trail1.getDenivelationM() - (-148.0)) < 0.01, "Constructor sets denivelation");
    assertTest(trail1.getDifficulty() == 3, "Constructor sets difficulty");
    
    // Test denivelation with positive value (net uphill)
    Trail trail2(hut1, hut2, 12.0, 600.0, 450.0, 4);
    assertTest(std::abs(trail2.getDenivelationM() - 450.0) < 0.01, "Denivelation can be positive (net uphill)");
    
    // Test difficulty string
    assertTest(trail1.getDifficultyString() == "Moderate", "getDifficultyString() returns correct value for 3");
    assertTest(trail2.getDifficultyString() == "Hard", "getDifficultyString() returns correct value for 4");
    
    // Test setters
    trail1.setLengthKm(16.0);
    assertTest(std::abs(trail1.getLengthKm() - 16.0) < 0.01, "setLengthKm() works");
    
    trail1.setElevationGainM(520.0);
    assertTest(std::abs(trail1.getElevationGainM() - 520.0) < 0.01, "setElevationGainM() works");
    
    trail1.setDenivelationM(-160.0);
    assertTest(std::abs(trail1.getDenivelationM() - (-160.0)) < 0.01, "setDenivelationM() works with negative values");
    
    trail1.setDifficulty(2);
    assertTest(trail1.getDifficulty() == 2, "setDifficulty() works");
    assertTest(trail1.getDifficultyString() == "Easy", "getDifficultyString() updates after difficulty change");
    
    // Test getDescription
    std::string desc = trail1.getDescription();
    assertTest(desc.find("Rila Hut") != std::string::npos, "getDescription() contains start name");
    assertTest(desc.find("Pirin Hut") != std::string::npos, "getDescription() contains end name");
    
    std::cout << "\nTrail description: " << desc << "\n";
    std::cout << "Trail 1 info:\n";
    trail1.printInfo();
    std::cout << "Trail 2 info:\n";
    trail2.printInfo();
    
    // Test error conditions
    try {
        trail1.setLengthKm(-5.0);
        assertTest(false, "setLengthKm() should reject negative length");
    } catch (const std::invalid_argument&) {
        assertTest(true, "setLengthKm() rejects negative length");
    }
    
    try {
        trail1.setElevationGainM(-100.0);
        assertTest(false, "setElevationGainM() should reject negative elevation");
    } catch (const std::invalid_argument&) {
        assertTest(true, "setElevationGainM() rejects negative elevation");
    }
    
    try {
        trail1.setDifficulty(6);
        assertTest(false, "setDifficulty() should reject difficulty > 5");
    } catch (const std::invalid_argument&) {
        assertTest(true, "setDifficulty() rejects difficulty > 5");
    }
    
    try {
        trail1.setDifficulty(0);
        assertTest(false, "setDifficulty() should reject difficulty < 1");
    } catch (const std::invalid_argument&) {
        assertTest(true, "setDifficulty() rejects difficulty < 1");
    }
}

// ===== Integration Test =====
void testIntegration() {
    printTestHeader("Integration Test - Complete System");
    
    // Create multiple sleeping places
    Hut hut1("Rila Monastery", 42.1354, 23.6552, 2298, true, true, true);
    Hut hut2("Pirin Hut", 41.75, 23.5, 2150, true, false, true);
    Camping camp1("Borovets Camp", 42.6988, 23.2000, 1356, 50, 20, 25.0, "планински");
    
    // Add rooms to huts
    auto room1 = std::make_shared<Room>(4, 50.0, true, "101");
    auto room2 = std::make_shared<Room>(3, 45.0, false, "102");
    hut1.addRoom(room1);
    hut1.addRoom(room2);
    
    auto room3 = std::make_shared<Room>(2, 60.0, true, "201");
    hut2.addRoom(room3);
    
    assertTest(hut1.getRoomCount() == 2, "Hut1 has 2 rooms");
    assertTest(hut2.getRoomCount() == 1, "Hut2 has 1 room");
    
    // Calculate revenues
    double totalHut1Revenue = hut1.getRoom(0)->getTotalPrice() + hut1.getRoom(1)->getTotalPrice();
    double expectedHut1Revenue = 200.0 + 135.0; // 4*50 + 3*45
    assertTest(std::abs(totalHut1Revenue - expectedHut1Revenue) < 0.01, 
               "Total Hut1 revenue calculation");
    
    double campRevenue = camp1.calculateTentIncome(30);
    assertTest(std::abs(campRevenue - 750.0) < 0.01, "Camp revenue for 30 tents");
    
    // Polymorphic collection
    SleepingPlace* places[] = {&hut1, &hut2, &camp1};
    int totalAltitude = 0;
    for (int i = 0; i < 3; ++i) {
        totalAltitude += places[i]->getAltitude();
    }
    
    assertTest(totalAltitude == 2298 + 2150 + 1356, "Total altitude of all sleeping places");
    
    std::cout << "\nSystem summary:\n";
    std::cout << "Total places: 3\n";
    std::cout << "Total rooms: " << (hut1.getRoomCount() + hut2.getRoomCount()) << "\n";
    std::cout << "Total altitude: " << totalAltitude << " m\n";
}

int main() {
    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║       COMPREHENSIVE TEST SUITE FOR PROJECT         ║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n";
    
    try {
        testRoom();
        testHut();
        testCamping();
        testSleepingPlace();
        testPolymorphism();
        testTrail();
        testIntegration();
    } catch (const std::exception& e) {
        std::cout << "\n✗ EXCEPTION CAUGHT: " << e.what() << "\n";
        testsFailed++;
    }
    
    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║                   TEST SUMMARY                    ║\n";
    std::cout << "╟────────────────────────────────────────────────────╢\n";
    std::cout << "║ Passed: " << std::left << std::setw(40) << testsPassed << "║\n";
    std::cout << "║ Failed: " << std::left << std::setw(40) << testsFailed << "║\n";
    std::cout << "║ Total:  " << std::left << std::setw(40) << (testsPassed + testsFailed) << "║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n";
    
    if (testsFailed == 0) {
        std::cout << "\n🎉 ALL TESTS PASSED! 🎉\n\n";
        return 0;
    } else {
        std::cout << "\n❌ SOME TESTS FAILED\n\n";
        return 1;
    }
}
