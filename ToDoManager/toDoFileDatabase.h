//
//  toDoFileDatabase.h
//  ToDoManager
//
//  Created by KonH on 03.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#ifndef toDoFileDatabase_h
#define toDoFileDatabase_h

#include "toDoDatabase.h"

class ToDoFileDatabase {
public:
	ToDoFileDatabase(ToDoDatabase* db, string fileName);
	~ToDoFileDatabase();
	vector<ToDoItem> Load();
	void Save(vector<ToDoItem> items);
private:
	ToDoDatabase* _db;
	string _fileName;
};

#endif /* toDoFileDatabase_h */
