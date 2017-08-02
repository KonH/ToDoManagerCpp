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
	_commands["rm"]   = &ToDoManager::RemoveItem;
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

void ToDoManager::ProcessCommand(string fullLine) {
	string cmd;
	string content;
	tie(cmd, content) = FindCommandData(fullLine);
	CommandPointer commandHandler = _commands[cmd];
	if (commandHandler == NULL) {
		cout << "Wrong command!" << endl;
		return;
	}
	(this->*commandHandler)(content);
}

void ToDoManager::ShowHelp(string arg) {
	cout << "Commands:" << endl;
	for (auto it = _commands.begin(); it != _commands.end(); it++) {
		cout << "\t" << it->first << endl;
	}
}

void ToDoManager::AddItem(string itemName) {
	if (itemName.empty()) {
		cout << "Item name is required!" << endl;
		return;
	}
	int id = FindNextId();
	ToDoItem newItem(id, itemName);
	_items.push_back(newItem);
	cout << "New item: '" << newItem.ToString() << "'" << endl;
}

void ToDoManager::RemoveItem(string itemIdStr) {
	if (itemIdStr.empty()) {
		cout << "Item id is required!" << endl;
		return;
	}
	int itemId = -1;
	try {
		itemId = stoi(itemIdStr);
	} catch(const exception &e) {
		cout << "Item id is wrong: " << e.what() << endl;
		return;
	}
	bool result = TryRemoveItem(itemId);
	if (result) {
		cout << "Item removed." << endl;
	} else {
		cout << "Item not found!" << endl;
	}
}

bool ToDoManager::TryRemoveItem(int id) {
	for (auto it = _items.begin(); it != _items.end(); it++) {
		if (it->id == id) {
			_items.erase(it);
			return true;
		}
	}
	return false;
}

void ToDoManager::ListItems(string arg) {
	cout << "Items: " << to_string(_items.size()) << endl;
	for (auto it = _items.begin(); it != _items.end(); it++) {
		cout << "\t'" << it->ToString() << "'" << endl;
	}
}

int ToDoManager::FindNextId() {
	int id = 1;
	for (auto it = _items.begin(); it != _items.end(); it++) {
		id = it->id >= id ? it->id + 1 : id;
	}
	return id;
}

tuple<string, string> ToDoManager::FindCommandData(string fullLine) {
	string cmd;
	string content;
	bool isCommandDone = false;
	for (int i = 0; i < fullLine.length(); i++ ) {
		char c = fullLine[i];
		if(!isCommandDone) {
			if(c == ' ') {
				isCommandDone = true;
				continue;
			}
			cmd += c;
		} else {
			content += c;
		}
	}
	return make_tuple(cmd, content);
}
