#pragma once

#include "SleepingPlace.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Tourist {
private:
    string name;
    string phone;
    vector<shared_ptr<SleepingPlace>> visitedPlaces;

public:
    Tourist(const string& name, const string& phone);

    ~Tourist();

    Tourist(const Tourist&) = delete;
    Tourist& operator=(const Tourist&) = delete;

    Tourist(Tourist&&) noexcept = default;
    Tourist& operator=(Tourist&&) noexcept = default;

    // Getters
    string getName() const;
    string getPhone() const;
    int getVisitedCount() const;

    shared_ptr<SleepingPlace> getVisitedPlace(int index) const;

    // Setters
    void setName(const string& newName);
    void setPhone(const string& newPhone);

    void addVisitedPlace(shared_ptr<SleepingPlace> place);

    bool hasVisited(shared_ptr<SleepingPlace> place) const;

    void printInfo() const;

    string getDescription() const;
};
