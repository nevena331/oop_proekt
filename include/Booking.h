#pragma once

#include "Tourist.h"
#include "SleepingPlace.h"
#include <memory>
#include <string>
#include <ctime>

using namespace std;

class Booking {
private:
    shared_ptr<Tourist> tourist;
    shared_ptr<SleepingPlace> place;
    time_t bookingDate;
    double finalPrice;

public:
    Booking(shared_ptr<Tourist> tour, shared_ptr<SleepingPlace> sleepingPlace, 
            double price);

    virtual ~Booking();

    Booking(const Booking&) = delete;
    Booking& operator=(const Booking&) = delete;

    Booking(Booking&&) noexcept = default;
    Booking& operator=(Booking&&) noexcept = default;

    // Getters
    shared_ptr<Tourist> getTourist() const;
    shared_ptr<SleepingPlace> getPlace() const;
    time_t getBookingDate() const;
    double getFinalPrice() const;

    // Setters
    void setFinalPrice(double price);

    string getBookingDateString() const;

    void printInfo() const;

    string getDescription() const;
};
