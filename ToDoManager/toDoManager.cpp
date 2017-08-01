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
	cout << "Items: " << to_string(_items.size()) << endl;
}

ToDoManager::~ToDoManager() {}

void ToDoManager::ProcessLoop() {
	string newName;
	while(true) {
		cout << "Insert new item:" << endl;
		getline(cin, newName);
		if(newName.empty()){
			break;
		}
		ToDoItem newItem(newName);
		_items.push_back(newItem);
		cout << "New item: '" << newItem.name << "'" << endl;
		cout << "Items: " << to_string(_items.size()) << endl;
    }
	cout << "End of work" << endl;
}
