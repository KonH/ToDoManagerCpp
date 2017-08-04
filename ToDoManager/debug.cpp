//
//  debug.cpp
//  ToDoManager
//
//  Created by KonH on 04.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#include <iostream>
#include "debug.h"

void DebugLog(string message) {
	cout << "DEBUG: " << message << endl;
}

void DebugAddrLog(string message, const void* p) {
	cout << "DEBUG: " << message << p << endl;
}
