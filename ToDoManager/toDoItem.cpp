//
//  toDoItem.cpp
//  ToDoManager
//
//  Created by KonH on 01.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include "toDoItem.h"

ToDoItem::ToDoItem(int itemId, string itemName) {
	id = itemId;
	name = itemName;
}

string ToDoItem::ToString() {
	return "[" + to_string(id) + "] " + name + " (" + (done ? "done" : "todo") + ")";
}
