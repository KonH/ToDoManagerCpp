//
//  debug.h
//  ToDoManager
//
//  Created by KonH on 04.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#ifndef debug_h
#define debug_h

#include <string>
#include <iostream>

using namespace std;

template <typename X>
void DebugLog(X x) {
	cout << "DEBUG: " << x << endl;
}

template<typename X, typename Y>
void DebugLog(X x, Y y) {
	cout << "DEBUG: " << x << y << endl;
}

#ifdef DEBUG
#	define Debug(...) DebugLog(__VA_ARGS__)
#else
#	define Debug(...)
#endif

#endif /* debug_h */
