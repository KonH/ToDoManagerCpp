//
//  toDoDatabase.cpp
//  ToDoManager
//
//  Created by KonH on 03.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include <sstream>
#include "toDoDatabase.h"
#include "debug.h"

ToDoDatabase::ToDoDatabase() {}

ToDoDatabase::~ToDoDatabase() {}

vector<ToDoItem> ToDoDatabase::Load(const string& content) {
	DebugAddr("D:Load. Content: ", &content);
	vector<ToDoItem> items;
	string accumLine;
	vector<string> accumLines;
	for (int i = 0; i < content.length(); i++) {
		char c = content[i];
		if (c != '\n') {
			accumLine += c;
		} else {
			if (!accumLine.empty()) {
				accumLines.push_back(accumLine);
				accumLine.clear();
			}
			if (accumLines.size() == 3) {
				int id = stoi(accumLines[0]);
				string name = accumLines[1];
				bool done = (accumLines[2][0] == '1');
				ToDoItem newItem(id, name);
				newItem.done = done;
				items.push_back(newItem);
				accumLines.clear();
			}
		}
	}
	DebugAddr("D.Load. Items: ", &items);
	return items;
}

string ToDoDatabase::Save(const vector<ToDoItem>& items) {
	DebugAddr("D.Save. Items: ", &items);
	stringstream ss;
	for (auto it = items.begin(); it != items.end(); it++) {
		ss << it->id << '\n' << it->name << '\n' << (it->done ? '1' : '0') << '\n';
	}
	return ss.str();
}
