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
#include "toDoEncrypter.h"

using namespace std;

class ToDoEncryptedDatabase: public ToDoDatabase {
public:
	ToDoEncryptedDatabase(ToDoEncrypter* encrypter);
	~ToDoEncryptedDatabase();
	vector<ToDoItem> Load(const string& content);
	string Save(const vector<ToDoItem>& items);
private:
	ToDoEncrypter* _encrypter;
};

#endif /* toDoEncryptedDatabase_h */
