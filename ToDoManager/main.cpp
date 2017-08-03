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

int main(int argc, const char * argv[]) {
	ToDoDatabase db;
	vector<ToDoItem> items;
	ToDoManager manager(items);
	manager.ProcessLoop();
	string content = db.Save(manager.GetItems());
	
	cout << "\"" << content << "\"" << endl;
	ToDoManager manager2(db.Load(content));
	manager.ProcessLoop();
	
	return 0;
}
