#pragma once

#include "SleepingPlace.h"
#include <memory>
#include <string>

class Trail {
private:
    std::shared_ptr<SleepingPlace> start;
    std::shared_ptr<SleepingPlace> end;
    double lengthKm;
    double elevationGainM;
    int difficulty; // 1..5

public:
    Trail(std::shared_ptr<SleepingPlace> startPoint,
          std::shared_ptr<SleepingPlace> endPoint,
          double length, double elevation, int diff);

    ~Trail();

    // Non-copyable
    Trail(const Trail&) = delete;
    Trail& operator=(const Trail&) = delete;

    // Movable
    Trail(Trail&&) noexcept = default;
    Trail& operator=(Trail&&) noexcept = default;

    std::shared_ptr<SleepingPlace> getStart() const;
    std::shared_ptr<SleepingPlace> getEnd() const;

    double getLengthKm() const;
    double getElevationGainM() const;
    int getDifficulty() const;

    void setStart(std::shared_ptr<SleepingPlace> newStart);
    void setEnd(std::shared_ptr<SleepingPlace> newEnd);

    void setLengthKm(double length);
    void setElevationGainM(double elevation);
    void setDifficulty(int diff);

    std::string getDifficultyString() const;
    std::string getDescription() const;

    void printInfo() const;
};
