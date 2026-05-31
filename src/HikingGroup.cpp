#include "HikingGroup.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

HikingGroup::HikingGroup(shared_ptr<Tourist> groupLeader, double discount)
    : leader(groupLeader), groupDiscount(discount) {
    if (groupLeader) {
        tourists.push_back(groupLeader);
    }
    if (groupDiscount < 0) groupDiscount = 0;
    if (groupDiscount > 100) groupDiscount = 100;
}

HikingGroup::~HikingGroup() {}

shared_ptr<Tourist> HikingGroup::getLeader() const {
    return leader;
}

int HikingGroup::getTouristCount() const {
    return tourists.size();
}

double HikingGroup::getGroupDiscount() const {
    return groupDiscount;
}

shared_ptr<Tourist> HikingGroup::getTourist(int index) const {
    if (index >= 0 && index < tourists.size()) {
        return tourists[index];
    }
    return nullptr;
}

void HikingGroup::setLeader(shared_ptr<Tourist> newLeader) {
    if (newLeader) {
        leader = newLeader;
    }
}

void HikingGroup::setGroupDiscount(double discount) {
    groupDiscount = discount;
    if (groupDiscount < 0) groupDiscount = 0;
    if (groupDiscount > 100) groupDiscount = 100;
}

void HikingGroup::addTourist(shared_ptr<Tourist> tourist) {
    if (tourist && !hasTourist(tourist)) {
        tourists.push_back(tourist);
    }
}

bool HikingGroup::removeTourist(shared_ptr<Tourist> tourist) {
    if (!tourist) return false;
    
    auto it = find(tourists.begin(), tourists.end(), tourist);
    if (it != tourists.end()) {
        // Don't remove the leader
        if (*it == leader) return false;
        tourists.erase(it);
        return true;
    }
    return false;
}

bool HikingGroup::hasTourist(shared_ptr<Tourist> tourist) const {
    if (!tourist) return false;
    for (const auto& t : tourists) {
        if (t == tourist) return true;
    }
    return false;
}

double HikingGroup::calculateGroupPrice(double basePrice) const {
    return basePrice * (1.0 - (groupDiscount / 100.0));
}

string HikingGroup::getDescription() const {
    return "Hiking Group led by " + leader->getName() + " with " + to_string(tourists.size()) + " members";
}

void HikingGroup::printInfo() const {
    cout << "╔═══════════════════════════════════════════╗\n";
    cout << "║ Hiking Group Information\n";
    cout << "╟───────────────────────────────────────────╢\n";
    cout << "║ Leader: " << leader->getName() << "\n";
    cout << "║ Members: " << tourists.size() << "\n";
    cout << "║ Group Discount: " << fixed << setprecision(2) << groupDiscount << "%\n";
    cout << "║ Members List:\n";
    for (int i = 0; i < tourists.size(); ++i) {
        cout << "║   " << (i + 1) << ". " << tourists[i]->getName();
        if (tourists[i] == leader) cout << " (Leader)";
        cout << "\n";
    }
    cout << "╚═══════════════════════════════════════════╝\n";
}
