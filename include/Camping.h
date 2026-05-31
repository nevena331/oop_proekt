#pragma once

#include "SleepingPlace.h"

using namespace std;

class Camping : public SleepingPlace {
private:
    int tentCapacity;
    int groundSpaces;
    double tripodFee;
    string campingType;

public:

    Camping(const string& name, double lat, double lon, int alt,
            int tents, int spaces, double tripodFeeAmount, const string& type = "планински");

    virtual ~Camping();

    Camping(const Camping&) = delete;
    Camping& operator=(const Camping&) = delete;
    
    Camping(Camping&&) noexcept = delete;
    Camping& operator=(Camping&&) noexcept = delete;

    // Getters
    int getTentCapacity() const;
    int getGroundSpaces() const;
    double getTripodFee() const;
    string getCampingType() const;
    int getTotalCapacity() const;
    string getDescription() const override;
    string getFacilitiesInfo() const;
    
    double calculateTentIncome(int numOfTents) const;
    
    void printInfo() const override;
    // Setters
    void setTentCapacity(int tents);
    void setGroundSpaces(int spaces);
    void setTripodFee(double fee);
    void setCampingType(const string& type);
    
};

