#include "npc.h"
#include "visitor.h"
#include "observer.h"
#include "factory.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    auto elf = std::make_shared<Elf>("Legolas", 0, 0);
    auto bandit = std::make_shared<Bandit>("Goblin", 1, 1);
    auto bear = std::make_shared<Bear>("Baloo", 2, 2);

    FileLogger logger("log.txt");
    elf->attach(&logger);
    bandit->attach(&logger);
    bear->attach(&logger);

    NPCVisitor visitor;

    FightResult res1 = elf->accept(visitor, *bandit);
    FightResult res2 = bear->accept(visitor, *bandit);

    std::cout << "Fight results:\n";
    std::cout << "Elf vs Bandit: " << static_cast<int>(res1) << "\n";
    std::cout << "Bear vs Bandit: " << static_cast<int>(res2) << "\n";

    std::vector<std::shared_ptr<NPC>> npcs = {elf, bandit, bear};
    NPCFactory::saveToFile(npcs, "npcs.txt");

    auto loaded = NPCFactory::loadFromFile("npcs.txt");
    std::cout << "Loaded NPCs:\n";
    for (auto& n : loaded)
        std::cout << n->getType() << " " << n->getName() << "\n";

    return 0;
}
