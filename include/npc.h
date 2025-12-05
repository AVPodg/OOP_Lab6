#pragma once
#include <string>
#include <vector>
#include "observer.h"

class NPCVisitor;

enum class FightResult { FirstWins, SecondWins, BothDie };

class NPC {
protected:
    std::string name;
    int x, y;
    std::vector<Observer*> observers;

public:
    NPC(const std::string& name_, int x_, int y_);
    virtual ~NPC();

    virtual std::string getType() const = 0;
    std::string getName() const;
    int getX() const;
    int getY() const;

    void attach(Observer* obs);
    void detach(Observer* obs);
    void notify(const std::string& event);

    virtual FightResult accept(NPCVisitor& visitor, NPC& other) = 0; // изменено на FightResult
};

class Bear : public NPC {
public:
    Bear(const std::string& name_, int x_, int y_);
    std::string getType() const override;
    FightResult accept(NPCVisitor& visitor, NPC& other) override;
};

class Elf : public NPC {
public:
    Elf(const std::string& name_, int x_, int y_);
    std::string getType() const override;
    FightResult accept(NPCVisitor& visitor, NPC& other) override;
};

class Bandit : public NPC {
public:
    Bandit(const std::string& name_, int x_, int y_);
    std::string getType() const override;
    FightResult accept(NPCVisitor& visitor, NPC& other) override;
};
