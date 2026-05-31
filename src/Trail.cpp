#include "Trail.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

Trail::Trail(shared_ptr<SleepingPlace> startPoint, shared_ptr<SleepingPlace> endPoint,
             double length, double elevation, double denivellation, int diff)
    : start(startPoint), end(endPoint), lengthKm(length), elevationGainM(elevation), denivelationM(denivellation), difficulty(diff) {}

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

double Trail::getDenivelationM() const {
    return denivelationM;
}

int Trail::getDifficulty() const {
    return difficulty;
}

void Trail::setStart(shared_ptr<SleepingPlace> newStart) {
    if (!newStart){
        throw invalid_argument("Start point cannot be null");
    }
    start = newStart;
}

void Trail::setEnd(shared_ptr<SleepingPlace> newEnd) {
    if (!newEnd){
        throw invalid_argument("End point cannot be null");
    }
    end = newEnd;
}

void Trail::setLengthKm(double length) {
    if (length > 0) lengthKm = length;
    else throw invalid_argument("Length must be positive");
}

void Trail::setElevationGainM(double elevation) {
    if (elevation >= 0) elevationGainM = elevation;
    else throw invalid_argument("Elevation gain cannot be negative");
}

void Trail::setDenivelationM(double denivellation) {
    denivelationM = denivellation;
}

void Trail::setDifficulty(int diff) {
    if (diff >= 1 && diff <= 5) difficulty = diff;
    else throw invalid_argument("Difficulty must be between 1 and 5");
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
    cout << "║ Denivelation: " << denivelationM << " m\n";
    cout << "║ Difficulty: " << getDifficultyString() << " (" << difficulty << "/5)\n";
    cout << "╚═══════════════════════════════════════════╝\n";
}
