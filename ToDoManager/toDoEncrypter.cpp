//
//  toDoEncrypter.cpp
//  ToDoManager
//
//  Created by KonH on 04.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include "toDoEncrypter.h"
#include "debug.h"

ToDoEncrypter::ToDoEncrypter(string key) {
	_key = key;
}

ToDoEncrypter::~ToDoEncrypter() {}

string ToDoEncrypter::Encrypt(const string& msg) {
	Debug("E.Encrypt. Message: ", &msg);
	string tmp(_key);
	while (_key.size() < msg.size()) {
		_key += tmp;
	}
	
	string newMessage;
	for (int i = 0; i < msg.size(); ++i) {
		newMessage += msg[i] ^ _key[i];
	}
	Debug("E:Encrypt. New message: ", &newMessage);
	return newMessage;
}
string ToDoEncrypter::Decrypt(const string& msg) {
	Debug("E.Decrypt. Message: ", &msg);
	return Encrypt(msg);
}
