//
//  main.cpp
//  ToDoManager
//
//  Created by KonH on 01.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include <iostream>

#include "toDoManager.h"
#include "toDoDatabase.h"
#include "toDoFileDatabase.h"

int main(int argc, const char * argv[]) {
	ToDoDatabase db;
	ToDoFileDatabase fileDb(db, "data");
	vector<ToDoItem> items = fileDb.Load();
	
	ToDoManager manager(items);
	manager.ProcessLoop();
	
	fileDb.Save(manager.GetItems());
	
	return 0;
}
