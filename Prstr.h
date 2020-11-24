#pragma once
#pragma warning(disable : 4996)
#include <cstring>
#include <iostream>
#include <fstream>
#include "Tree.h"

using namespace std;

class ErrorException {

public:

	ErrorException(string error) : m_error(error) {}

	const char* getError() { return m_error.c_str(); }

private:

	string m_error;
};


class Prstr {
public:

	Prstr();

	Prstr(const char* other);

	Prstr(const Prstr& other);

	int setpp(const char* other);

	const char* getpp();

	char* sum(const char* s);

	int search(const char* s);

	Prstr& operator=(const Prstr& other);

	Prstr& operator+(const Prstr& other);

	Prstr operator+(const char* other);

	friend bool operator == (const Prstr& pp, const Prstr& other);

	friend bool operator == (const Prstr& pp, const char* other);

	friend std::ostream& operator<< (std::ostream& out, const Prstr& pp);

	friend std::istream& operator>> (std::istream& is, Prstr& pp);

	bool read_binary(fstream& filename);

	bool write_binary(fstream& filename);

	virtual void add_tree_class(const Prstr& other, Prstr*& aBranch) {

		if (!aBranch) {

			aBranch = new Prstr;
			aBranch->field = &other;
			aBranch->left = 0;
			aBranch->right = 0;
			return;
		}
		else {

			if (aBranch->field > & other) {

				Prstr::add_tree_class(other, aBranch->left);
			}
			else {

				Prstr::add_tree_class(other, aBranch->right);
			}
		}
	};

	virtual void print_tree_class(Prstr*& aBranch) {

		if (!aBranch) return;
		tabs++;

		Prstr::print_tree_class(aBranch->left);

		for (int i = 0; i < tabs; i++) cout << " ";
		cout << aBranch->field << endl;

		Prstr::print_tree_class(aBranch->right);

		tabs--;
	};

	virtual void delete_tree_class(Prstr*& aBranch) {

		if (!aBranch) return;
		Prstr::delete_tree_class(aBranch->left);
		Prstr::delete_tree_class(aBranch->right);
		delete aBranch;
		return;
	};

	~Prstr();

protected:

	char* pp;
	int len_c = 0;
	int tabs = 0;
	const Prstr* field;
	Prstr* left;
	Prstr* right;
};