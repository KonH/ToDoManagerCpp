//
//  toDoEncryptedDatabase.cpp
//  ToDoManager
//
//  Created by KonH on 03.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include "toDoEncryptedDatabase.h"

ToDoEncryptedDatabase::ToDoEncryptedDatabase(string key) {
	_key = key;
}

string ToDoEncryptedDatabase::Encrypt(string msg) {
	string tmp(_key);
	while (_key.size() < msg.size()) {
		_key += tmp;
	}
	
	for (int i = 0; i < msg.size(); ++i) {
		msg[i] ^= _key[i];
	}
	
	return msg;
}
string ToDoEncryptedDatabase::Decrypt(string msg) {
	return Encrypt(msg);
}

vector<ToDoItem> ToDoEncryptedDatabase::Load(string content) {
	string decryptedContent = Decrypt(content);
	return ToDoDatabase::Load(decryptedContent);
}

string ToDoEncryptedDatabase::Save(vector<ToDoItem> items) {
	string content = ToDoDatabase::Save(items);
	string encryptedContent = Encrypt(content);
	return encryptedContent;
}
