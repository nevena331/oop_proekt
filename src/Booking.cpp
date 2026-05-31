#include "Booking.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

Booking::Booking(shared_ptr<Tourist> tour, shared_ptr<SleepingPlace> sleepingPlace, 
                 double price)
    : tourist(tour), place(sleepingPlace), finalPrice(price) {
    bookingDate = time(nullptr);
}

Booking::~Booking() {}

shared_ptr<Tourist> Booking::getTourist() const {
    return tourist;
}

shared_ptr<SleepingPlace> Booking::getPlace() const {
    return place;
}

time_t Booking::getBookingDate() const {
    return bookingDate;
}

double Booking::getFinalPrice() const {
    return finalPrice;
}

void Booking::setFinalPrice(double price) {
    if (price >= 0) finalPrice = price;
}

string Booking::getBookingDateString() const {
    time_t raw = bookingDate;
    struct tm* timeinfo = localtime(&raw);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return string(buffer);
}

string Booking::getDescription() const {
    return "Booking for " + tourist->getName() + " at " + place->getName();
}

void Booking::printInfo() const {
    cout << "╔═══════════════════════════════════════════╗\n";
    cout << "║ Booking Information\n";
    cout << "╟───────────────────────────────────────────╢\n";
    cout << "║ Tourist: " << tourist->getName() << "\n";
    cout << "║ Phone: " << tourist->getPhone() << "\n";
    cout << "║ Place: " << place->getName() << "\n";
    cout << "║ Booking Date: " << getBookingDateString() << "\n";
    cout << "║ Final Price: " << fixed << setprecision(2) << finalPrice << " BGN\n";
    cout << "╚═══════════════════════════════════════════╝\n";
}
