#include "Camping.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Camping::Camping(const std::string& name, double lat, double lon, int alt,
                 int tents, int spaces, double tripodFeeAmount, const std::string& type)
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

std::string Camping::getCampingType() const {
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
    }
}

void Camping::setTripodFee(double fee) {
    if (fee >= 0) {
        tripodFee = fee;
    }
}

void Camping::setCampingType(const std::string& type) {
    campingType = type;
}

int Camping::getTotalCapacity() const {
    return tentCapacity + groundSpaces;
}

double Camping::calculateTentIncome(int numOfTents) const {
    return numOfTents * tripodFee;
}

std::string Camping::getDescription() const {
    std::ostringstream oss;
    oss << "Camping - " << campingType << " | "
        << tentCapacity << " tents, " << groundSpaces << " spaces";
    return oss.str();
}

std::string Camping::getFacilitiesInfo() const {
    std::ostringstream oss;
    oss << "Tents: " << tentCapacity << " | "
        << "Spaces: " << groundSpaces << " | "
        << "Fee: " << std::fixed << std::setprecision(2)
        << tripodFee << " BGN";
    return oss.str();
}

void Camping::printInfo() const {
    std::cout << "\n╔═══════════════════════════════════════════════╗\n";
    std::cout << "║           CAMPING: " << std::left << std::setw(20) << name << "║\n";
    std::cout << "╟───────────────────────────────────────────────╢\n";
    std::cout << "║ Location: " << std::fixed << std::setprecision(4)
              << latitude << "°, " << longitude << "° | Altitude: "
              << altitude << " m\n";
    std::cout << "║ Type: " << std::left << std::setw(39) << campingType << "║\n";
    std::cout << "║ Capacity: " << tentCapacity << " tents + "
              << groundSpaces << " spaces = " << getTotalCapacity() << " total\n";
    std::cout << "║ Tripod fee: " << std::fixed << std::setprecision(2)
              << tripodFee << " BGN\n";
    std::cout << "╚═══════════════════════════════════════════════╝\n";
}
