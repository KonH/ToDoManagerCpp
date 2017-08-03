//
//  toDoEncryptedDatabase.h
//  ToDoManager
//
//  Created by KonH on 03.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#ifndef toDoEncryptedDatabase_h
#define toDoEncryptedDatabase_h

#include <string>

#include "toDoDatabase.h"

using namespace std;

class ToDoEncryptedDatabase: public ToDoDatabase {
public:
	ToDoEncryptedDatabase(string key);
	vector<ToDoItem> Load(string content);
	string Save(vector<ToDoItem> items);
private:
	string _key;
	string Encrypt(string msg);
	string Decrypt(string msg);
};

#endif /* toDoEncryptedDatabase_h */
