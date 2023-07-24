#include "Command.h"
#include "Room.h"
#include "Gateway.h"
#include <iostream>

void NorthCommand::execute(Player* player, std::vector<std::string>& args) {
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (roomParent) {
		Entity* gate = roomParent->getGatewayDirection("north");
		if (gate) player->moveToGateway((Gateway*)gate);
		else std::cout << "You cannot go north from here." << std::endl;
	}
	else {
		std::cout << "You cannot go north from here." << std::endl;
	}
}

void SouthCommand::execute(Player* player, std::vector<std::string>& args) {
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (roomParent) {
		Entity* gate = roomParent->getGatewayDirection("south");
		if (gate) player->moveToGateway((Gateway*)gate);
		else std::cout << "You cannot go south from here." << std::endl;
	}
	else {
		std::cout << "You cannot go south from here." << std::endl;
	}
}

void EastCommand::execute(Player* player, std::vector<std::string>& args) {
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (roomParent) {
		Entity* gate = roomParent->getGatewayDirection("east");
		if (gate) player->moveToGateway((Gateway*)gate);
		else std::cout << "You cannot go east from here." << std::endl;
	}
	else {
		std::cout << "You cannot go east from here." << std::endl;
	}
}

void WestCommand::execute(Player* player, std::vector<std::string>& args) {
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (roomParent) {
		Entity* gate = roomParent->getGatewayDirection("west");
		if (gate) player->moveToGateway((Gateway*)gate);
		else std::cout << "You cannot go west from here." << std::endl;
	}
	else {
		std::cout << "You cannot go west from here." << std::endl;
	}
}

void UpCommand::execute(Player* player, std::vector<std::string>& args) {
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (roomParent) {
		Entity* gate = roomParent->getGatewayDirection("up");
		if (gate) player->moveToGateway((Gateway*)gate);
		else std::cout << "You cannot go up from here." << std::endl;
	}
	else {
		std::cout << "You cannot go up from here." << std::endl;
	}
}

void DownCommand::execute(Player* player, std::vector<std::string>& args) {
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (roomParent) {
		Entity* gate = roomParent->getGatewayDirection("down");
		if (gate) player->moveToGateway((Gateway*)gate);
		else std::cout << "You cannot go down from here." << std::endl;
	}
	else {
		std::cout << "You cannot go down from here." << std::endl;
	}
}

void LookCommand::execute(Player* player, std::vector<std::string>& args) {
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (roomParent) {
		roomParent->look();
	}
}

void TakeCommand::execute(Player* player, std::vector<std::string>& args) {
	std::cout << "south" << std::endl;
}

void DropCommand::execute(Player* player, std::vector<std::string>& args) {
	std::cout << "south" << std::endl;
}

void ThrowCommand::execute(Player* player, std::vector<std::string>& args) {
	std::cout << "south" << std::endl;
}

void InventoryCommand::execute(Player* player, std::vector<std::string>& args) {
	std::cout << "south" << std::endl;
}

void ExamineCommand::execute(Player* player, std::vector<std::string>& args) {
	std::cout << "south" << std::endl;
}

void OpenCommand::execute(Player* player, std::vector<std::string>& args) {
	std::string door = concatVectorTillEnd(args, 1);
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (roomParent) {
		Entity* entity = roomParent->getGateway(door);
		Gateway* gate = dynamic_cast<Gateway*>(entity);
		if (gate) gate->openGateway();
		else std::cout << "You cannot open it." << std::endl;
	}
	else {
		std::cout << "You cannot open it." << std::endl;
	}
}

void CloseCommand::execute(Player* player, std::vector<std::string>& args) {
	std::string door = concatVectorTillEnd(args, 1);
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (roomParent) {
		Entity* entity = roomParent->getGateway(door);
		Gateway* gate = dynamic_cast<Gateway*>(entity);
		if (gate) gate->closeGateway();
		else std::cout << "You cannot close it." << std::endl;
	}
	else {
		std::cout << "You cannot close it." << std::endl;
	}
}

void AttackCommand::execute(Player* player, std::vector<std::string>& args) {
	std::cout << "south" << std::endl;
}

void DrinkCommand::execute(Player* player, std::vector<std::string>& args) {
	std::cout << "south" << std::endl;
}

void EatCommand::execute(Player* player, std::vector<std::string>& args) {
	std::cout << "south" << std::endl;
}
std::string Command::concatVectorTillEnd(std::vector<std::string>& args, int first) {
	if (args.size() > first+1) {
		std::string phrase = args[first];
		for (size_t i = 2; i < args.size(); ++i) {
			phrase += " " + args[i];
		}
		return phrase;
	}
	return "false";
}