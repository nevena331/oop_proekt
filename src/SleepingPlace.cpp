#include "SleepingPlace.h"
#include <iostream>
#include <iomanip>

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
    name = newName;
}

void SleepingPlace::setCoordinates(double lat, double lon) {
    latitude = lat;
    longitude = lon;
}

void SleepingPlace::setAltitude(int alt) {
    altitude = alt;
}

void SleepingPlace::printInfo() const {
    cout << "╔═══════════════════════════════════════════╗\n";
    cout << "║ " << left << setw(39) << name << " ║\n";
    cout << "╟───────────────────────────────────────────╢\n";
    cout << "║ Координати: " << fixed << setprecision(4)
              << latitude << "°, " << longitude << "°\n";
    cout << "║ Височина: " << altitude << " м\n";
    cout << "║ Описание: " << getDescription() << "\n";
    cout << "╚═══════════════════════════════════════════╝\n";
}
