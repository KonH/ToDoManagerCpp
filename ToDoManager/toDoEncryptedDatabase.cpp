//
//  toDoEncryptedDatabase.cpp
//  ToDoManager
//
//  Created by KonH on 03.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include "toDoEncryptedDatabase.h"
#include "debug.h"

ToDoEncryptedDatabase::ToDoEncryptedDatabase(ToDoEncrypter* encrypter) {
	_encrypter = encrypter;
}

ToDoEncryptedDatabase::~ToDoEncryptedDatabase() {}

vector<ToDoItem> ToDoEncryptedDatabase::Load(const string& content) {
	Debug("ED.Load. Content: ", &content);
	string decryptedContent = _encrypter->Decrypt(content);
	Debug("ED.Load. Decrypted content: ", &decryptedContent);
	return ToDoDatabase::Load(decryptedContent);
}

string ToDoEncryptedDatabase::Save(const vector<ToDoItem>& items) {
	Debug("ED.Save: Items: ", &items);
	string content = ToDoDatabase::Save(items);
	Debug("ED.Save: Content: ", &content);
	string encryptedContent = _encrypter->Encrypt(content);
	Debug("ED.Save: Encrypted content: ", &encryptedContent);
	return encryptedContent;
}
