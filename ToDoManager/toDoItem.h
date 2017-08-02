//
//  toDoItem.h
//  ToDoManager
//
//  Created by KonH on 01.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#ifndef toDoItem_h
#define toDoItem_h

#include <string>

using namespace std;

struct ToDoItem {
	int id;
	string name;
	bool done;
	ToDoItem(int id, string itemName);
	string ToString();
};

#endif /* toDoItem_h */
