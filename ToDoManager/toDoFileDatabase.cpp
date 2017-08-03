//
//  toDoFileDatabase.cpp
//  ToDoManager
//
//  Created by KonH on 03.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "toDoFileDatabase.h"

ToDoFileDatabase::ToDoFileDatabase(ToDoDatabase* db, string fileName) {
	_db = db;
	_fileName = fileName;
}

ToDoFileDatabase::~ToDoFileDatabase() {

}

vector<ToDoItem> ToDoFileDatabase::Load() {
	ifstream file;
	file.open(_fileName);
	string line;
	stringstream ss;
	while (getline(file, line)) {
		ss << line << '\n';
	}
	file.close();
	string content = ss.str();
	return _db->Load(content);
}

void ToDoFileDatabase::Save(vector<ToDoItem> items) {
	string content = _db->Save(items);
	ofstream file(_fileName);
	file << content;
	file.close();
}
