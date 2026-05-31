#pragma once
#include "SleepingPlace.h"
#include "Room.h"
#include <vector>
#include <memory>

using namespace std;

class Hut : public SleepingPlace {
private:
    vector<shared_ptr<Room>> rooms;
    bool hasDiningHall;
    bool hasElectricity;
    bool hasWater;

public:

    Hut(const string& name, double lat, double lon, int alt,
        bool dining = true, bool electricity = true, bool water = true);

    ~Hut();

    Hut(const Hut&) = delete;
    Hut& operator=(const Hut&) = delete;
    
    Hut(Hut&&) noexcept = delete;
    Hut& operator=(Hut&&) noexcept = delete;

    void addRoom(shared_ptr<Room> room);

    int getRoomCount() const;
    shared_ptr<Room> getRoom(int index) const;
    bool getDiningHall() const;
    bool getElectricity() const;
    bool getWater() const;
    string getAmenities() const;
    string getDescription() const override;
    void printInfo() const override;

    void setDiningHall(bool hasDining);
    void setElectricity(bool hasElec);
    void setWater(bool hasWtr);

};

