#pragma once

#include "SleepingPlace.h"
#include <memory>
#include <string>

using namespace std;

class Trail {
private:
    shared_ptr<SleepingPlace> start;
    shared_ptr<SleepingPlace> end;
    double lengthKm;
    double elevationGainM;
    double denivelationM; // Net elevation change (can be negative)
    int difficulty; // 1..5

public:
    Trail(shared_ptr<SleepingPlace> startPoint,
          shared_ptr<SleepingPlace> endPoint,
          double length, double elevation, double denivellation, int diff);

    ~Trail();

    // Non-copyable
    Trail(const Trail&) = delete;
    Trail& operator=(const Trail&) = delete;

    // Movable
    Trail(Trail&&) noexcept = default;
    Trail& operator=(Trail&&) noexcept = default;

    shared_ptr<SleepingPlace> getStart() const;
    shared_ptr<SleepingPlace> getEnd() const;

    double getLengthKm() const;
    double getElevationGainM() const;
    double getDenivelationM() const;
    int getDifficulty() const;

    void setStart(shared_ptr<SleepingPlace> newStart);
    void setEnd(shared_ptr<SleepingPlace> newEnd);

    void setLengthKm(double length);
    void setElevationGainM(double elevation);
    void setDenivelationM(double denivellation);
    void setDifficulty(int diff);

    string getDifficultyString() const;
    string getDescription() const;

    void printInfo() const;
};
