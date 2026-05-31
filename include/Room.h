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

    Room(const Room&) = delete;
    Room& operator=(const Room&) = delete;
    
    Room(Room&&) noexcept = delete;
    Room& operator=(Room&&) noexcept = delete;


    // Getters
    int getBedCount() const;
    double getPricePerBed() const;
    bool hasPrivateBathroom() const;
    std::string getRoomNumber() const;
    
    double getTotalPrice() const;

    string getDescription() const;

    void printInfo() const;
    
    // Setters
    void setBedCount(int beds);
    void setPricePerBed(double price);
    void setPrivateBathroom(bool hasPrivate);
    void setRoomNumber(const std::string& number);

};
