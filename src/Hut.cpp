#include "Hut.h"
#include "Room.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

Hut::Hut(const string& name, double lat, double lon, int alt,
         bool dining, bool electricity, bool water)
    : SleepingPlace(name, lat, lon, alt),
      hasDiningHall(dining),
      hasElectricity(electricity),
      hasWater(water) {}

Hut::~Hut() {}

void Hut::addRoom(shared_ptr<Room> room) {
    if (room) {
        rooms.push_back(room);
    }else {
        throw invalid_argument("Cannot add a null room");
    }
}

int Hut::getRoomCount() const {
    return rooms.size();
}

shared_ptr<Room> Hut::getRoom(int index) const {
    if (index >= 0 && index < static_cast<int>(rooms.size())) {
        return rooms[index];
    }
    return nullptr;
}

bool Hut::getDiningHall() const {
    return hasDiningHall;
}

bool Hut::getElectricity() const {
    return hasElectricity;
}

bool Hut::getWater() const {
    return hasWater;
}

void Hut::setDiningHall(bool hasDining) {
    hasDiningHall = hasDining;
}

void Hut::setElectricity(bool hasElec) {
    hasElectricity = hasElec;
}

void Hut::setWater(bool hasWtr) {
    hasWater = hasWtr;
}

string Hut::getDescription() const {
    return "Hut with amenities and " + to_string(rooms.size()) + " rooms";
}

string Hut::getAmenities() const {
    string amenities = "";
    amenities += (hasDiningHall ? "✓ Dining hall" : "✗ Dining hall");
    amenities += " | ";
    amenities += (hasElectricity ? "✓ Electricity" : "✗ Electricity");
    amenities += " | ";
    amenities += (hasWater ? "✓ Water" : "✗ Water");
    return amenities;
}

void Hut::printInfo() const {
    cout << "\n╔══════════════════════════════════════════════════╗\n";
    cout << "║           HUT: " << left << setw(31) << name << "║\n";
    cout << "╟──────────────────────────────────────────────────╢\n";
    cout << "║ Location: " << fixed << setprecision(4)
              << latitude << "°, " << longitude << "° | Altitude: "
              << altitude << " m\n";
    cout << "║ Amenities: " << getAmenities() << "\n";
    cout << "║ Rooms: " << rooms.size() << "\n";
    
    if (!rooms.empty()) {
        cout << "╟──────────────────────────────────────────────────╢\n";
        cout << "║ ROOMS:\n";
        for (size_t i = 0; i < rooms.size(); ++i) {
            if (rooms[i]) {
                cout << "║   " << (i + 1) << ". Room - "
                          << rooms[i]->getBedCount() << " beds\n";
            }
        }
    }
    
    cout << "╚══════════════════════════════════════════════════╝\n";
}
