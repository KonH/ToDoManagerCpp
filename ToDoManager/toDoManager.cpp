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

void free() {}

ToDoManager::ToDoManager() {
	_commands["add"]  = &ToDoManager::AddItem;
	_commands["list"] = &ToDoManager::ListItems;
	_commands["help"] = &ToDoManager::ShowHelp;
	
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
	CommandPointer commandHandler = _commands[command];
	if (commandHandler == NULL) {
		cout << "Wrong command!" << endl;
		return;
	}
	(this->*commandHandler)();
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
