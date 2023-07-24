#include "Command.h"
#include "Room.h"
#include "Gateway.h"
#include "Item.h"
#include "NPC.h"
#include <iostream>
#include <set>

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
	std::string toTake = concatVectorTillEnd(args, 1);
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (Entity* ent = roomParent->deepSearch(toTake)) {
		if (Item* item = dynamic_cast<Item*>(ent)) {
			player->takeItem(item);
		}
	}
	
}

void DropCommand::execute(Player* player, std::vector<std::string>& args) {
	std::string toDrop = concatVectorTillEnd(args, 1);
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (Entity* ent = roomParent->deepSearch(toDrop)) {
		if (Item* item = dynamic_cast<Item*>(ent)) {
			player->dropItem(item);
		}
	}
}

void PutCommand::execute(Player* player, std::vector<std::string>& args) {
	std::cout << "Coming up soon!" << std::endl;
}

void InventoryCommand::execute(Player* player, std::vector<std::string>& args) {
	player->listInventory();
}

void ExamineCommand::execute(Player* player, std::vector<std::string>& args) {
	std::string toExamine = concatVectorTillEnd(args, 1);
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	Entity* entity = roomParent->getElement(toExamine);
	if (entity) entity->examine();
	else {
		if (Entity* ent = roomParent->deepSearch(toExamine)) {
			ent->examine();
		}
	}
}

void OpenCommand::execute(Player* player, std::vector<std::string>& args) {
	std::string door = concatVectorTillEnd(args, 1);
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (roomParent) {
		Entity* entity = roomParent->getGateway(door);
		Gateway* gate = dynamic_cast<Gateway*>(entity);
		if (gate) {
			gate->openGateway();
			return;
		}
		Item* item = dynamic_cast<Item*>(entity);
		if (item) {
			item->setOpen(true);
			return;
		}
		std::cout << "You cannot open it." << std::endl;
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
	auto toAttack = concatVectorToPron(args, 1);
	Room* roomParent = dynamic_cast<Room*>(player->getParent());
	if (Entity* ent = roomParent->deepSearch(toAttack.first)) {
		if (Creature* npc = dynamic_cast<Creature*>(ent)) {
			Entity* ent2 = player->deepSearch(toAttack.second);
			if (Item* weapon = dynamic_cast<Item*>(ent2))
				player->attack(npc, weapon);
			else std::cout << "Don't have this weapon." << std::endl;
		}
		else std::cout << "Creature not here." << std::endl;
	}
	else std::cout << "Creature not here." << std::endl;
}

void ConsumeCommand::execute(Player* player, std::vector<std::string>& args) {
	std::string consumable = concatVectorTillEnd(args, 1);
	Entity* cons = player->deepSearch(consumable);
	if (Item* heal = dynamic_cast<Item*>(cons)) {
		int health = player->getHealth() + heal->getHealing();
		player->setHealth(health);
	}
}

void StatusCommand::execute(Player* player, std::vector<std::string>& args) {
	std::cout << "Health: " << player->getHealth() << std::endl;
}

void UseCommand::execute(Player* player, std::vector<std::string>& args) {
	auto unlock = concatVectorToPron(args, 1);
	Entity* keyaux = player->deepSearch(unlock.first);
	Entity* door = player->getParent()->deepSearch(unlock.second);
	if (Item* key = dynamic_cast<Item*>(keyaux)) {
		door->unlock(key);
	}
}

std::string Command::concatVectorTillEnd(std::vector<std::string>& args, int first) {
	if (args.size() > first) {
		std::string phrase = args[first];
		for (size_t i = first+1; i < args.size(); ++i) {
			phrase += " " + args[i];
		}
		return phrase;
	}
	return "false";
}


std::pair<std::string, std::string> Command::concatVectorToPron(std::vector<std::string>& args, int first) {
	if (args.size() > first) {
		size_t aux = 0;
		std::string phrase1 = args[first];
		const std::set<std::string> validPron = { "with", "on" };
		for (size_t i = first+1; i < args.size(); ++i) {
			if (validPron.find(args[i]) != validPron.end()) {
				aux = i + 1;
				break;
			}
			phrase1 += " " + args[i];
		}
		std::string phrase2 = args[aux];
		for (size_t i = aux+1; i < args.size(); ++i) {
			phrase2 += " " + args[i];
		}
		return std::make_pair(phrase1, phrase2);
	}
	return std::make_pair("", "");
}