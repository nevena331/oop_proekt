#pragma once

#include "SleepingPlace.h"


class Camping : public SleepingPlace {
private:
    int tentCapacity;
    int groundSpaces;
    double tripodFee;
    std::string campingType;

public:

    Camping(const std::string& name, double lat, double lon, int alt,
            int tents, int spaces, double tripodFeeAmount, const std::string& type = "планински");

    virtual ~Camping();

    Camping(const Camping&) = delete;
    Camping& operator=(const Camping&) = delete;

    Camping(Camping&&) noexcept = default;
    Camping& operator=(Camping&&) noexcept = default;

    // Getters
    int getTentCapacity() const;
    int getGroundSpaces() const;
    double getTripodFee() const;
    std::string getCampingType() const;

    // Setters
    void setTentCapacity(int tents);
    void setGroundSpaces(int spaces);
    void setTripodFee(double fee);
    void setCampingType(const std::string& type);

    int getTotalCapacity() const;

    double calculateTentIncome(int numOfTents) const;

    std::string getDescription() const override;
    void printInfo() const override;
    std::string getFacilitiesInfo() const;
};

