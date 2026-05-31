#pragma once

#include <string>

using namespace std;

class SleepingPlace {
protected:
    string name;           
    double latitude;
    double longitude;
    int altitude;

public:
    SleepingPlace(const string& name, double lat, double lon, int alt);

    virtual ~SleepingPlace();

    SleepingPlace(const SleepingPlace&) = delete;
    SleepingPlace& operator=(const SleepingPlace&) = delete;
    
    SleepingPlace(SleepingPlace&&) noexcept = delete;
    SleepingPlace& operator=(SleepingPlace&&) noexcept = delete;

    // Getters
    string getName() const;
    double getLatitude() const;
    double getLongitude() const;
    int getAltitude() const;

    // Setters
    void setName(const string& newName);
    void setCoordinates(double lat, double lon);
    void setAltitude(int alt);

    virtual string getDescription() const = 0;

    virtual void printInfo() const;
};


