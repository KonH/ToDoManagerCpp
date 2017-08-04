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

#ifdef DEBUG
#	define Debug(x) DebugLog(x)
#else
#	define Debug(x)
#endif

#endif /* debug_h */
