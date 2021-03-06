/*
 * DeerAction.cpp
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle
 */

#include "DeerAction.h"

QueryResult DeerAction::query(){
	std::cout << "The deer action card allows a player to select another player to trade goals with. ";
	std::cout << "Enter the name of the player you'd like to trade with";
	std::string name;
	std::cin >> name;
	QueryResult result(name);
	return result;
}

void DeerAction::perform(Table& table, Player* player, QueryResult queryResult){
	std::shared_ptr<Player> playerToTrade = table.getPlayerWithName(queryResult.getName());
	if(!playerToTrade){				//if no player was found with the name, alert the player and do not perform
		std::cout << "Invalid Player to trade with." << std::endl;
		return;
	}
	std::string playerSA  = player->getSecretAnimal();
	std::string tradeSA = playerToTrade->swapSecretAnimal(playerSA);
	player->swapSecretAnimal(tradeSA);
}
