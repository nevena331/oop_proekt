#pragma once
#include <string>

using namespace std;

class Room {
private:
    int bedCount;
    double pricePerBed;
    bool hasOwnBathroom;
    std::string roomNumber;

public:
    Room(int beds, double price, bool bathroom, const std::string& number = "");

    ~Room();

    // Disable copying
    Room(const Room&) = delete;
    Room& operator=(const Room&) = delete;

    // Allow moving
    Room(Room&&) noexcept = default;
    Room& operator=(Room&&) noexcept = default;

    // Getters
    int getBedCount() const;
    double getPricePerBed() const;
    bool hasPrivateBathroom() const;
    std::string getRoomNumber() const;

    // Setters
    void setBedCount(int beds);
    void setPricePerBed(double price);
    void setPrivateBathroom(bool hasPrivate);
    void setRoomNumber(const std::string& number);

    double getTotalPrice() const;

    string getDescription() const;

    void printInfo() const;
};
