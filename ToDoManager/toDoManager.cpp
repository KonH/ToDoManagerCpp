//
//  toDoManager.cpp
//  ToDoManager
//
//  Created by KonH on 01.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include <iostream>
#include <string>

#include "toDoManager.h"

using namespace std;

ToDoManager::ToDoManager() {
	_commands["add"]  = CMD_ADD;
	_commands["list"] = CMD_LIST;
	_commands["help"] = CMD_HELP;
	
	ShowHelp();
}

ToDoManager::~ToDoManager() {}

void ToDoManager::ProcessLoop() {
	string command;
	while(true) {
		cout << endl;
		cout << "Command:" << endl;
		getline(cin, command);
		if(command.empty()){
			break;
		}
		ProcessCommand(command);
	}
	cout << "End of work" << endl;
}

void ToDoManager::ProcessCommand(string command) {
	switch (_commands[command]) {
		case CMD_ADD:
			AddItem();
			break;

		case CMD_LIST:
			ListItems();
			break;
			
		case CMD_HELP:
			ShowHelp();
			break;
			
		default:
			cout << "Wrong command!" << endl;
			break;
	}
}

void ToDoManager::ShowHelp() {
	cout << "Commands:" << endl;
	for (auto it = _commands.begin(); it != _commands.end(); it++) {
		cout << "\t" << it->first << endl;
	}
}

void ToDoManager::AddItem() {
	string newName;
	cout << "Insert new item:" << endl;
	getline(cin, newName);
	ToDoItem newItem(newName);
	_items.push_back(newItem);
	cout << "New item: '" << newItem.name << "'" << endl;
}

void ToDoManager::ListItems() {
	cout << "Items: " << to_string(_items.size()) << endl;
	for (auto it = _items.begin(); it != _items.end(); it++) {
		cout << "\t'" << it->name << "'" << endl;
	}
}
