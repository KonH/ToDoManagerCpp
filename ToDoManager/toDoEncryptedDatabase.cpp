//
//  toDoEncryptedDatabase.cpp
//  ToDoManager
//
//  Created by KonH on 03.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include "toDoEncryptedDatabase.h"

ToDoEncryptedDatabase::ToDoEncryptedDatabase(ToDoEncrypter* encrypter) {
	_encrypter = encrypter;
}

ToDoEncryptedDatabase::~ToDoEncryptedDatabase() {}

vector<ToDoItem> ToDoEncryptedDatabase::Load(string content) {
	string decryptedContent = _encrypter->Decrypt(content);
	return ToDoDatabase::Load(decryptedContent);
}

string ToDoEncryptedDatabase::Save(vector<ToDoItem> items) {
	string content = ToDoDatabase::Save(items);
	string encryptedContent = _encrypter->Encrypt(content);
	return encryptedContent;
}
