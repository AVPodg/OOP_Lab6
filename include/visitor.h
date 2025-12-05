#pragma once
#include "npc.h"
#include "observer.h"
#include <vector>

class NPCVisitor {
    std::vector<Observer*> observers;
public:
    NPCVisitor() = default;
    NPCVisitor(const std::vector<Observer*>& obs) : observers(obs) {}

    FightResult fight(NPC& a, NPC& b);
};
