#include "Room.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using namespace std;

Room::Room(int beds, double price, bool bathroom, const string& number)
    : bedCount(beds), pricePerBed(price), hasOwnBathroom(bathroom), roomNumber(number) {}

Room::~Room() {}

int Room::getBedCount() const {
    return bedCount;
}

double Room::getPricePerBed() const {
    return pricePerBed;
}

bool Room::hasPrivateBathroom() const {
    return hasOwnBathroom;
}

string Room::getRoomNumber() const {
    return roomNumber;
}

void Room::setBedCount(int beds) {
    if (beds > 0) {
        bedCount = beds;
    }else{
        throw invalid_argument("Bed count must be positive.");
    }
}

void Room::setPricePerBed(double price) {
    if (price >= 0) {
        pricePerBed = price;
    }else{
        throw invalid_argument("Price per bed cannot be negative.");
    }
}

void Room::setPrivateBathroom(bool hasPrivate) {
    hasOwnBathroom = hasPrivate;
}

void Room::setRoomNumber(const string& number) {
    if(number.empty()){
        throw invalid_argument("Room number cannot be empty.");
    }
    roomNumber = number;
}

double Room::getTotalPrice() const {
    return bedCount * pricePerBed;
}

string Room::getDescription() const {
    ostringstream oss;
    oss << bedCount << " beds, " << fixed << setprecision(2)
        << pricePerBed << " BGN/bed";
    if (hasOwnBathroom) {
        oss << ", with private WC";
    }
    return oss.str();
}

void Room::printInfo() const {
    cout << "\n  ┌─ ROOM " << roomNumber << " ─┐\n";
    cout << "  │ Beds: " << bedCount << "\n";
    cout << "  │ Price per bed: " << fixed << setprecision(2)
              << pricePerBed << " EUR\n";
    cout << "  │ Total price: " << fixed << setprecision(2)
              << getTotalPrice() << " EUR\n";
    cout << "  │ WC: " << (hasOwnBathroom ? "✓ Private" : "✗ Shared")
              << "\n";
    cout << "  └─────────────────────┘\n";
}
