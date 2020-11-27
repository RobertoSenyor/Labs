#include "Prstr.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>

#pragma once
#pragma warning(disable : 4996)

class StringNumber : public Prstr {
public:

	StringNumber() : Prstr() {}

	StringNumber(const StringNumber& other) : Prstr(other) {}

	StringNumber(const char* other) : Prstr(other) {}

	virtual void to_string() {
	
		len_c = strlen(pp);

		for (int i = 0; i < len_c; i++) {

			a = (int)pp[i];
			itoa(a, buf, 8);

			ostringstream os;
			os << buf;
			cout << "@ " << pp[i] << " @" << " - " << os.str() << endl;
		}

		free(buf);

		ostringstream oss;
		oss << len_c;
		cout << "string: " << pp << endl << "lenth of string: " << oss.str() << endl;
	}

	void toint();

private:

	char* buf = new char[64];
	int a;
};