#include "Camping.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using namespace std;

Camping::Camping(const string& name, double lat, double lon, int alt,
                 int tents, int spaces, double tripodFeeAmount, const string& type)
    : SleepingPlace(name, lat, lon, alt),
      tentCapacity(tents),
      groundSpaces(spaces),
      tripodFee(tripodFeeAmount),
      campingType(type) {}

Camping::~Camping() {}

int Camping::getTentCapacity() const {
    return tentCapacity;
}

int Camping::getGroundSpaces() const {
    return groundSpaces;
}

double Camping::getTripodFee() const {
    return tripodFee;
}

string Camping::getCampingType() const {
    return campingType;
}

void Camping::setTentCapacity(int tents) {
    if (tents >= 0) {
        tentCapacity = tents;
    }
}

void Camping::setGroundSpaces(int spaces) {
    if (spaces >= 0) {
        groundSpaces = spaces;
    }else{
        throw invalid_argument("Ground spaces cannot be negative.");
    }
}

void Camping::setTripodFee(double fee) {
    if (fee >= 0) {
        tripodFee = fee;
    }else{
        throw invalid_argument("Tripod fee cannot be negative.");
    }
}

void Camping::setCampingType(const string& type) {
    campingType = type;
}

int Camping::getTotalCapacity() const {
    return tentCapacity + groundSpaces;
}

double Camping::calculateTentIncome(int numOfTents) const {
    return numOfTents * tripodFee;
}

string Camping::getDescription() const {
    ostringstream oss;
    oss << "Camping - " << campingType << " | "
        << tentCapacity << " tents, " << groundSpaces << " spaces";
    return oss.str();
}

string Camping::getFacilitiesInfo() const {
    ostringstream oss;
    oss << "Tents: " << tentCapacity << " | "
        << "Spaces: " << groundSpaces << " | "
        << "Fee: " << fixed << setprecision(2)
        << tripodFee << " BGN";
    return oss.str();
}

void Camping::printInfo() const {
    cout << "\n╔═══════════════════════════════════════════════╗\n";
    cout << "║           CAMPING: " << left << setw(20) << name << "║\n";
    cout << "╟───────────────────────────────────────────────╢\n";
    cout << "║ Location: " << fixed << setprecision(4)
              << latitude << "°, " << longitude << "° | Altitude: "
              << altitude << " m\n";
    cout << "║ Type: " << left << setw(39) << campingType << "║\n";
    cout << "║ Capacity: " << tentCapacity << " tents + "
              << groundSpaces << " spaces = " << getTotalCapacity() << " total\n";
    cout << "║ Tripod fee: " << fixed << setprecision(2)
              << tripodFee << " EUR\n";
    cout << "╚═══════════════════════════════════════════════╝\n";
}
