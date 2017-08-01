//
//  toDoManager.h
//  ToDoManager
//
//  Created by KonH on 01.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#ifndef toDoManager_h
#define toDoManager_h

#include <vector>

#include "toDoItem.h"

class ToDoManager {
public:
	ToDoManager();
	~ToDoManager();
	void ProcessLoop();
private:
	std::vector<ToDoItem> _items;
};

#endif /* toDoManager_h */
