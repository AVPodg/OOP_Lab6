#pragma once
#include "npc.h"
#include <memory>
#include <vector>
#include <string>
#include <fstream>

class NPCFactory {
public:
    // Объявления функций без тела
    static std::shared_ptr<NPC> create(const std::string& type,
                                       const std::string& name,
                                       int x, int y);

    static void saveToFile(const std::vector<std::shared_ptr<NPC>>& npcs,
                           const std::string& filename);

    static std::vector<std::shared_ptr<NPC>> loadFromFile(const std::string& filename);
};
