#include "factory.h"

// Создание NPC по типу
std::shared_ptr<NPC> NPCFactory::create(const std::string& type,
                                        const std::string& name,
                                        int x, int y) {
    if (type == "Bear") return std::make_shared<Bear>(name, x, y);
    if (type == "Elf") return std::make_shared<Elf>(name, x, y);
    if (type == "Bandit") return std::make_shared<Bandit>(name, x, y);
    return nullptr;
}

// Сохранение NPC в файл
void NPCFactory::saveToFile(const std::vector<std::shared_ptr<NPC>>& npcs,
                            const std::string& filename) {
    std::ofstream fout(filename);
    for (auto& npc : npcs)
        fout << npc->getType() << " " << npc->getName() << " "
             << npc->getX() << " " << npc->getY() << "\n";
}

// Загрузка NPC из файла
std::vector<std::shared_ptr<NPC>> NPCFactory::loadFromFile(const std::string& filename) {
    std::vector<std::shared_ptr<NPC>> result;
    std::ifstream fin(filename);
    std::string type, name;
    int x, y;
    while (fin >> type >> name >> x >> y)
        result.push_back(create(type, name, x, y));
    return result;
}
