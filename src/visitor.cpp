#include "visitor.h"

FightResult NPCVisitor::fight(NPC& a, NPC& b) {
    std::string msg;
    FightResult result;

    if (a.getType() == "Elf" && b.getType() == "Bandit") {
        msg = a.getName() + " kills " + b.getName();
        result = FightResult::FirstWins;
    } else if (a.getType() == "Bear" && b.getType() == "Bandit") {
        msg = a.getName() + " and " + b.getName() + " both die";
        result = FightResult::BothDie;
    } else if (a.getType() == "Bear" && b.getType() == "Elf") {
        msg = a.getName() + " kills " + b.getName();
        result = FightResult::FirstWins;
    } else if (a.getType() == "Bandit" && b.getType() == "Bandit") {
        msg = a.getName() + " kills " + b.getName();
        result = FightResult::FirstWins;
    } else {
        msg = a.getName() + " fights " + b.getName();
        result = FightResult::SecondWins;
    }

    for (auto obs : observers) obs->onNotify(msg);
    a.notify(msg);
    b.notify(msg);

    return result;
}
