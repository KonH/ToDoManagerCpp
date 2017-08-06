//
//  toDoManager.cpp
//  ToDoManager
//
//  Created by KonH on 01.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>

#include "toDoManager.h"
#include "debug.h"

using namespace std;

ToDoManager::ToDoManager(const vector<ToDoItem>& items) {
	Debug("M.ctor(). Items: ", &items);
	_items = items;
	
	_commands["add"]   = &ToDoManager::AddItem;
	_commands["rm"]    = &ToDoManager::RemoveItem;
	_commands["list"]  = &ToDoManager::ListItems;
	_commands["help"]  = &ToDoManager::ShowHelp;
	_commands["todo"]  = &ToDoManager::MarkTodo;
	_commands["done"]  = &ToDoManager::MarkDone;
	_commands["clear"] = &ToDoManager::Clear;
	
	ShowHelp();
}

ToDoManager::~ToDoManager() {}

vector<ToDoItem>& ToDoManager::GetItems() {
	Debug("M.GetItems: Items: ", &_items);
	return _items;
}

// Command handling

void ToDoManager::ProcessLoop() {
	string command;
	while(true) {
		cout << endl;
		cout << "Command:" << endl;
		getline(cin, command);
		if (command.empty()) {
			break;
		}
		ProcessCommand(command);
	}
	cout << "End of work" << endl;
}

tuple<string, string> ToDoManager::FindCommandData(string fullLine) {
	string cmd;
	string content;
	bool isCommandDone = false;
	for (int i = 0; i < fullLine.length(); i++ ) {
		char c = fullLine[i];
		if (!isCommandDone) {
			if (c == ' ') {
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

// Utility

int ToDoManager::FindItemId(string itemIdStr) {
	if (itemIdStr.empty()) {
		cout << "Item id is required!" << endl;
		return -1;
	}
	int itemId = -1;
	try {
		itemId = stoi(itemIdStr);
	} catch(const exception &e) {
		cout << "Item id is wrong: " << e.what() << endl;
	}
	return itemId;
}

ToDoItem* ToDoManager::FindItemById(int id) {
	auto iter = find_if(
		_items.begin(), _items.end(),
		[id](ToDoItem& item) { return item.id == id; }
	);
	return &(*iter);
}

int ToDoManager::FindNextId() {
	int id = 1;
	for_each(
		_items.begin(),
		_items.end(),
		[&id](ToDoItem& item) { id = item.id >= id ? item.id + 1 : id; }
	);
	return id;
}

bool ToDoManager::TryRemoveItem(int id) {
	auto it = _items.begin();
	while (it != _items.end()) {
		if (it->id == id) {
			_items.erase(it);
			return true;
		}
		it++;
	}
	return false;
}

void ToDoManager::SetStatus(string itemIdStr, bool status) {
	int itemId = FindItemId(itemIdStr);
	if (itemId < 0) {
		return;
	}
	ToDoItem* item = FindItemById(itemId);
	if(item != NULL) {
		item->done = status;
		cout << item->ToString() << endl;
	} else {
		cout << "Item not found!";
	}
}


// Commands

void ToDoManager::ShowHelp(string arg) {
	cout << "Commands:" << endl;
	auto it = _commands.begin();
	while (it != _commands.end()) {
		cout << "\t" << it->first << endl;
		it++;
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
	int itemId = FindItemId(itemIdStr);
	if (itemId < 0) {
		return;
	}
	bool result = TryRemoveItem(itemId);
	if (result) {
		cout << "Item removed." << endl;
	} else {
		cout << "Item not found!" << endl;
	}
}

void ToDoManager::MarkTodo(string arg) {
	SetStatus(arg, false);
}

void ToDoManager::MarkDone(string arg) {
	SetStatus(arg, true);
}

void ToDoManager::ListItems(string arg) {
	cout << "Items: " << to_string(_items.size()) << endl;
	auto it = _items.begin();
	while (it != _items.end()) {
		cout << "\t'" << it->ToString() << "'" << endl;
		it++;
	}
}

void ToDoManager::Clear(string arg) {
	_items.erase(
		remove_if(
			_items.begin(), _items.end(),
			[](ToDoItem item) { return item.done; }
		),
		_items.end());
}
