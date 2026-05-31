#pragma once

#include "Tourist.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class HikingGroup {
private:
    vector<shared_ptr<Tourist>> tourists;
    shared_ptr<Tourist> leader;
    double groupDiscount;  // percentage 0-100

public:
    HikingGroup(shared_ptr<Tourist> groupLeader, double discount = 0.0);

    virtual ~HikingGroup();

    HikingGroup(const HikingGroup&) = delete;
    HikingGroup& operator=(const HikingGroup&) = delete;

    HikingGroup(HikingGroup&&) noexcept = default;
    HikingGroup& operator=(HikingGroup&&) noexcept = default;

    // Getters
    shared_ptr<Tourist> getLeader() const;
    int getTouristCount() const;
    double getGroupDiscount() const;

    shared_ptr<Tourist> getTourist(int index) const;
    
    void printInfo() const;

    string getDescription() const;

    // Setters
    void setLeader(shared_ptr<Tourist> newLeader);
    void setGroupDiscount(double discount);

    void addTourist(shared_ptr<Tourist> tourist);

    bool removeTourist(shared_ptr<Tourist> tourist);

    bool hasTourist(shared_ptr<Tourist> tourist) const;

    void dethroneLeader(shared_ptr<Tourist> newLeader);

    double calculateGroupPrice(double basePrice) const;
};
