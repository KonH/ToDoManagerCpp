//
//  toDoEncrypter.h
//  ToDoManager
//
//  Created by KonH on 04.08.17.
//  Copyright © 2017 KonH. All rights reserved.
//

#ifndef toDoEncrypter_h
#define toDoEncrypter_h

#include <string>

using namespace std;

class ToDoEncrypter {
public:
	ToDoEncrypter(string key);
	~ToDoEncrypter();
	string Encrypt(string msg);
	string Decrypt(string msg);
private:
	string _key;
};


#endif /* toDoEncrypter_h */
