#include "Trail.h"
#include <iostream>
#include <iomanip>

using namespace std;

Trail::Trail(shared_ptr<SleepingPlace> startPoint, shared_ptr<SleepingPlace> endPoint,
             double length, double elevation, int diff)
    : start(startPoint), end(endPoint), lengthKm(length), elevationGainM(elevation), difficulty(diff) {}

Trail::~Trail() {}

shared_ptr<SleepingPlace> Trail::getStart() const {
    return start;
}

shared_ptr<SleepingPlace> Trail::getEnd() const {
    return end;
}

double Trail::getLengthKm() const {
    return lengthKm;
}

double Trail::getElevationGainM() const {
    return elevationGainM;
}

int Trail::getDifficulty() const {
    return difficulty;
}

void Trail::setStart(shared_ptr<SleepingPlace> newStart) {
    start = newStart;
}

void Trail::setEnd(shared_ptr<SleepingPlace> newEnd) {
    end = newEnd;
}

void Trail::setLengthKm(double length) {
    if (length > 0) lengthKm = length;
}

void Trail::setElevationGainM(double elevation) {
    if (elevation >= 0) elevationGainM = elevation;
}

void Trail::setDifficulty(int diff) {
    if (diff >= 1 && diff <= 5) difficulty = diff;
}

string Trail::getDifficultyString() const {
    switch (difficulty) {
        case 1: return "Very Easy";
        case 2: return "Easy";
        case 3: return "Moderate";
        case 4: return "Hard";
        case 5: return "Very Hard";
        default: return "Unknown";
    }
}

string Trail::getDescription() const {
    return "Trail from " + start->getName() + " to " + end->getName();
}

void Trail::printInfo() const {
    cout << "╔═══════════════════════════════════════════╗\n";
    cout << "║ Trail Information\n";
    cout << "╟───────────────────────────────────────────╢\n";
    cout << "║ From: " << start->getName() << "\n";
    cout << "║ To: " << end->getName() << "\n";
    cout << "║ Length: " << fixed << setprecision(2) << lengthKm << " km\n";
    cout << "║ Elevation Gain: " << elevationGainM << " m\n";
    cout << "║ Difficulty: " << getDifficultyString() << " (" << difficulty << "/5)\n";
    cout << "╚═══════════════════════════════════════════╝\n";
}
