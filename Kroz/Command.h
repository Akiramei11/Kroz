#pragma once
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

class Command
{
public:
    virtual void execute(Player* player, std::vector<std::string>& args) = 0;
    virtual ~Command() {}

    std::string concatVectorTillEnd(std::vector<std::string>& args, int first);
    std::pair<std::string, std::string> concatVectorToPron(std::vector<std::string>& args, int first);
};

class NorthCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class SouthCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class EastCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class WestCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class UpCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class DownCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class LookCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class TakeCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class DropCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class PutCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class InventoryCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class ExamineCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class OpenCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class CloseCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class AttackCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class ConsumeCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

class StatusCommand : public Command {
public:
    void execute(Player* player, std::vector<std::string>& args) override;
};

