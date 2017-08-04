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
#include "toDoEncryptedDatabase.h"
#include "toDoFileDatabase.h"

int main(int argc, const char * argv[]) {
	cout << "Data file: " << endl;
	string fileName;
	getline(cin, fileName);
	cout << "Data key:" << endl;
	string key;
	getline(cin, key);
	ToDoEncrypter encrypter(key);
	ToDoEncryptedDatabase db(&encrypter);
	ToDoFileDatabase fileDb(&db, fileName);
	vector<ToDoItem> items = fileDb.Load();
	
	ToDoManager manager(items);
	manager.ProcessLoop();
	
	fileDb.Save(manager.GetItems());
	
	return 0;
}
