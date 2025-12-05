#include "gtest/gtest.h"
#include "../include/npc.h"
#include "../include/observer.h"
#include "../include/factory.h"
#include "../include/visitor.h"

#include <fstream>
#include <memory>
#include <vector>
#include <string>

// Вспомогательный класс для тестов, чтобы не писать в файл
class TestLogger : public Observer {
public:
    std::vector<std::string> events;
    void onNotify(const std::string& event) override {
        events.push_back(event);
    }
};

// =========================
// NPC Creation Tests
// =========================
TEST(NPCCreation, CreateNPCs) {
    auto elf = std::make_shared<Elf>("Legolas", 1, 2);
    auto bear = std::make_shared<Bear>("Baloo", 3, 4);
    auto bandit = std::make_shared<Bandit>("Goblin", 5, 6);

    EXPECT_EQ(elf->getName(), "Legolas");
    EXPECT_EQ(elf->getX(), 1);
    EXPECT_EQ(elf->getY(), 2);
    EXPECT_EQ(elf->getType(), "Elf");

    EXPECT_EQ(bear->getType(), "Bear");
    EXPECT_EQ(bandit->getType(), "Bandit");
}

// =========================
// Observer / Logging Tests
// =========================
TEST(NPCObserver, NotifyObservers) {
    auto elf = std::make_shared<Elf>("Legolas", 0, 0);
    TestLogger logger;
    elf->attach(&logger);

    NPCVisitor visitor;
    auto bandit = std::make_shared<Bandit>("Goblin", 1, 1);

    elf->accept(visitor, *bandit);

    EXPECT_FALSE(logger.events.empty());
    EXPECT_NE(logger.events[0].find("Legolas"), std::string::npos);  // Проверяем, что имя есть в логе
    EXPECT_NE(logger.events[0].find("Goblin"), std::string::npos);
}

// =========================
// Fight / Visitor Tests
// =========================
TEST(NPCVisitorTest, FightResults) {
    auto elf = std::make_shared<Elf>("Legolas", 0, 0);
    auto bandit = std::make_shared<Bandit>("Goblin", 1, 1);
    auto bear = std::make_shared<Bear>("Baloo", 2, 2);

    NPCVisitor visitor;

    FightResult res1 = elf->accept(visitor, *bandit);
    FightResult res2 = bear->accept(visitor, *bandit);
    FightResult res3 = bandit->accept(visitor, *bandit);

    EXPECT_EQ(res1, FightResult::FirstWins);  // Elf kills Bandit
    EXPECT_EQ(res2, FightResult::BothDie);    // Bear vs Bandit
    EXPECT_EQ(res3, FightResult::FirstWins);  // Bandit vs Bandit
}

// =========================
// Factory Tests
// =========================
TEST(NPCFactoryTest, SaveLoad) {
    auto elf = std::make_shared<Elf>("Legolas", 0, 0);
    auto bandit = std::make_shared<Bandit>("Goblin", 1, 1);
    auto bear = std::make_shared<Bear>("Baloo", 2, 2);

    std::vector<std::shared_ptr<NPC>> npcs = {elf, bandit, bear};
    NPCFactory::saveToFile(npcs, "test_npcs.txt");

    auto loaded = NPCFactory::loadFromFile("test_npcs.txt");
    ASSERT_EQ(loaded.size(), 3);

    EXPECT_EQ(loaded[0]->getName(), "Legolas");
    EXPECT_EQ(loaded[0]->getType(), "Elf");
    EXPECT_EQ(loaded[1]->getName(), "Goblin");
    EXPECT_EQ(loaded[1]->getType(), "Bandit");
    EXPECT_EQ(loaded[2]->getName(), "Baloo");
    EXPECT_EQ(loaded[2]->getType(), "Bear");
}

// =========================
// Edge Case: No Observers
// =========================
TEST(NPCObserver, NoObserversDoesNotCrash) {
    auto elf = std::make_shared<Elf>("Legolas", 0, 0);
    NPCVisitor visitor;
    auto bandit = std::make_shared<Bandit>("Goblin", 1, 1);

    // Должно работать даже без прикрепленных наблюдателей
    EXPECT_NO_THROW({
        elf->accept(visitor, *bandit);
    });
}
