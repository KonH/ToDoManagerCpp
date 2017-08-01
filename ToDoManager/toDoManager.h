//
//  toDoManager.h
//  ToDoManager
//
//  Created by KonH on 01.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#ifndef toDoManager_h
#define toDoManager_h

#include <map>
#include <vector>

#include "toDoItem.h"

using namespace std;

#define CMD_ADD  1
#define CMD_LIST 2
#define CMD_HELP 3

class ToDoManager {
public:
	ToDoManager();
	~ToDoManager();
	void ProcessLoop();
private:
	map<string, int> _commands;
	vector<ToDoItem> _items;
	void ProcessCommand(string command);
	void ShowHelp();
	void AddItem();
	void ListItems();
};

#endif /* toDoManager_h */
