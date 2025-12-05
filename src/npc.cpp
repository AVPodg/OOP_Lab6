#include "npc.h"
#include "visitor.h"
#include <algorithm>

NPC::NPC(const std::string& name_, int x_, int y_) : name(name_), x(x_), y(y_) {}
NPC::~NPC() {}
std::string NPC::getName() const { return name; }
int NPC::getX() const { return x; }
int NPC::getY() const { return y; }

void NPC::attach(Observer* obs) { observers.push_back(obs); }

void NPC::detach(Observer* obs) {
    observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
}

void NPC::notify(const std::string& event) {
    for (auto obs : observers)
        obs->onNotify(event);
}

// Bear
Bear::Bear(const std::string& name_, int x_, int y_) : NPC(name_, x_, y_) {}
std::string Bear::getType() const { return "Bear"; }
FightResult Bear::accept(NPCVisitor& visitor, NPC& other) { 
    return visitor.fight(*this, other); 
}

// Elf
Elf::Elf(const std::string& name_, int x_, int y_) : NPC(name_, x_, y_) {}
std::string Elf::getType() const { return "Elf"; }
FightResult Elf::accept(NPCVisitor& visitor, NPC& other) { 
    return visitor.fight(*this, other); 
}

// Bandit
Bandit::Bandit(const std::string& name_, int x_, int y_) : NPC(name_, x_, y_) {}
std::string Bandit::getType() const { return "Bandit"; }
FightResult Bandit::accept(NPCVisitor& visitor, NPC& other) { 
    return visitor.fight(*this, other); 
}
