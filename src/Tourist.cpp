#include "Tourist.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tourist::Tourist(const string& name, const string& phone)
    : name(name), phone(phone) {}

Tourist::~Tourist() {}

string Tourist::getName() const {
    return this->name;
}

string Tourist::getPhone() const {
    return this->phone;
}

int Tourist::getVisitedCount() const {
    return this->visitedPlaces.size();
}

shared_ptr<SleepingPlace> Tourist::getVisitedPlace(int index) const {
    if (index >= 0 && index < visitedPlaces.size()) {
        return this->visitedPlaces[index];
    }
    return nullptr;
}

void Tourist::setName(const string& newName) {
    name = newName;
}

void Tourist::setPhone(const string& newPhone) {
    phone = newPhone;
}

void Tourist::addVisitedPlace(shared_ptr<SleepingPlace> place) {
    if (place && !hasVisited(place)) {
        visitedPlaces.push_back(place);
    }
}

bool Tourist::hasVisited(shared_ptr<SleepingPlace> place) const {
    if (!place) return false;
    for (const auto& p : visitedPlaces) {
        if (p == place) return true;
    }
    return false;
}

string Tourist::getDescription() const {
    return "Tourist " + name + " has visited " + to_string(visitedPlaces.size()) + " places";
}

void Tourist::printInfo() const {
    cout << "╔═══════════════════════════════════════════╗\n";
    cout << "║ Tourist Information\n";
    cout << "╟───────────────────────────────────────────╢\n";
    cout << "║ Name: " << name << "\n";
    cout << "║ Phone: " << phone << "\n";
    cout << "║ Visited Places: " << visitedPlaces.size() << "\n";
    for (int i = 0; i < visitedPlaces.size(); ++i) {
        cout << "║   " << (i + 1) << ". " << visitedPlaces[i]->getName() << "\n";
    }
    cout << "╚═══════════════════════════════════════════╝\n";
}
