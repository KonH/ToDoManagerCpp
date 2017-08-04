//
//  toDoDatabase.h
//  ToDoManager
//
//  Created by KonH on 03.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#ifndef toDoDatabase_hpp
#define toDoDatabase_hpp

#include <string>
#include <vector>

#include "toDoItem.h"

using namespace std;

class ToDoDatabase {
public:
	ToDoDatabase();
	~ToDoDatabase();
	virtual vector<ToDoItem> Load(const string& content);
	virtual string Save(const vector<ToDoItem>& items);
};


#endif /* toDoDatabase_h */
