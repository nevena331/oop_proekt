#include "SleepingPlace.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

SleepingPlace::SleepingPlace(const string& name, double lat, double lon, int alt)
    : name(name), latitude(lat), longitude(lon), altitude(alt) {}

SleepingPlace::~SleepingPlace() {}

string SleepingPlace::getName() const {
    return name;
}

double SleepingPlace::getLatitude() const {
    return latitude;
}

double SleepingPlace::getLongitude() const {
    return longitude;
}

int SleepingPlace::getAltitude() const {
    return altitude;
}

void SleepingPlace::setName(const string& newName) {
    if (newName.empty()) {
        throw invalid_argument("SleepingPlace name cannot be empty");
    }
    name = newName;
}

void SleepingPlace::setCoordinates(double lat, double lon) {
    if (lat < -90 || lat > 90) {
        throw invalid_argument("Latitude must be between -90 and 90 degrees");
    }
    if (lon < -180 || lon > 180) {
        throw invalid_argument("Longitude must be between -180 and 180 degrees");
    }
    latitude = lat;
    longitude = lon;
}

void SleepingPlace::setAltitude(int alt) {
    if(alt >= -430) {
        altitude = alt;
    }
}



void SleepingPlace::printInfo() const {
    cout << "╔═══════════════════════════════════════════╗\n";
    cout << "║ " << left << setw(39) << name << " ║\n";
    cout << "╟───────────────────────────────────────────╢\n";
    cout << "║ Coordinates: " << fixed << setprecision(4)
              << latitude << "°, " << longitude << "°\n";
    cout << "║ Altitude: " << altitude << " m\n";
    cout << "║ Description: " << getDescription() << "\n";
    cout << "╚═══════════════════════════════════════════╝\n";
}
