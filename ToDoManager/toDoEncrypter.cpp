//
//  toDoEncrypter.cpp
//  ToDoManager
//
//  Created by KonH on 04.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include "toDoEncrypter.h"

ToDoEncrypter::ToDoEncrypter(string key) {
	_key = key;
}

ToDoEncrypter::~ToDoEncrypter() {}

string ToDoEncrypter::Encrypt(string msg) {
	string tmp(_key);
	while (_key.size() < msg.size()) {
		_key += tmp;
	}
	
	for (int i = 0; i < msg.size(); ++i) {
		msg[i] ^= _key[i];
	}
	
	return msg;
}
string ToDoEncrypter::Decrypt(string msg) {
	return Encrypt(msg);
}
