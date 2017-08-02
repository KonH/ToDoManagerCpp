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

class ToDoManager {
public:
	ToDoManager();
	~ToDoManager();
	void ProcessLoop();
private:
	typedef void (ToDoManager::* CommandPointer)(string);
	map<string, CommandPointer> _commands;
	vector<ToDoItem> _items;
	void ProcessCommand(string fullLine);
	void ShowHelp(string arg = "");
	void AddItem(string arg);
	void ListItems(string arg = "");
	int FindNextId();
	tuple<string, string> FindCommandData(string fullLine);
};

#endif /* toDoManager_h */
