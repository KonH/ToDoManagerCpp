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

using namespace std;

void DebugLog(string message);
void DebugAddrLog(string message, void const* p);

#ifdef DEBUG
#	define Debug(x) DebugLog((x))
#	define DebugAddr(x, y) DebugAddrLog((x), (y))
#else
#	define Debug(x)
#	define DebugAddr(x, y) DebugAddrLog((x), (y))
#endif

#endif /* debug_h */
