//
//  toDoItem.cpp
//  ToDoManager
//
//  Created by KonH on 01.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include <sstream>

#include "toDoItem.h"

ToDoItem::ToDoItem(int itemId, string itemName) {
	id = itemId;
	name = itemName;
}

string ToDoItem::ToString() {
	stringstream ss;
	ss << "[" << to_string(id) << "] " << name << " (" << (done ? "done" : "todo") << ")";
	return ss.str();
}
