#include "HikingGroup.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

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
    }else{
        throw invalid_argument("Leader cannot be null");
    }
}

void HikingGroup::setGroupDiscount(double discount) {
    if(discount < 0 || discount > 100) {
        throw invalid_argument("Discount must be between 0 and 100");
    }
    groupDiscount = discount;
}

void HikingGroup::addTourist(shared_ptr<Tourist> tourist) {
    if(!tourist) {
        throw invalid_argument("Tourist cannot be null");
    }
    if (!hasTourist(tourist)) {
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

void HikingGroup::dethroneLeader(shared_ptr<Tourist> newLeader) {
    if (!newLeader) {
        throw invalid_argument("New leader cannot be null");
    }
    
    if (!hasTourist(newLeader)) {
        throw invalid_argument("New leader must be an existing member of the group");
    }
    
    if (newLeader == leader) {
        throw invalid_argument("New leader cannot be the current leader");
    }
    
    shared_ptr<Tourist> oldLeader = leader;
    leader = newLeader;
    
    // Remove the old leader from the group
    auto it = find(tourists.begin(), tourists.end(), oldLeader);
    if (it != tourists.end()) {
        tourists.erase(it);
    }
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
