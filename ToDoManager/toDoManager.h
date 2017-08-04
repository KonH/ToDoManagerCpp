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
	ToDoManager(const vector<ToDoItem>& items);
	~ToDoManager();
	void ProcessLoop();
	vector<ToDoItem>& GetItems();
private:
	typedef void (ToDoManager::* CommandPointer)(string);
	map<string, CommandPointer> _commands;
	vector<ToDoItem> _items;
	
	// Command handling
	tuple<string, string> FindCommandData(string fullLine);
	void ProcessCommand(string fullLine);
	
	// Utility
	int FindItemId(string itemIdStr);
	ToDoItem* FindItemById(int id);
	int FindNextId();
	bool TryRemoveItem(int id);
	void SetStatus(string arg, bool status);
	
	// Commands
	void ShowHelp(string arg = "");
	void AddItem(string arg);
	void RemoveItem(string arg);
	void ListItems(string arg = "");
	void MarkTodo(string arg);
	void MarkDone(string arg);
	void Clear(string arg);
};

#endif /* toDoManager_h */
