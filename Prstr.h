#pragma once
#pragma warning(disable : 4996)
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

class ErrorException {

public:

	ErrorException(string error) : m_error(error) {}

	const char* getError() { return m_error.c_str(); }

private:

	string m_error;
};

class Tree {
public:

	virtual void add_tree_class(const Tree& other, Tree*& aBranch);

	virtual void print_tree_class(Tree*& aBranch);

	virtual void delete_tree_class(Tree*& aBranch);

protected:

	int tabs = 0;
	const Tree* field;
	Tree* left;
	Tree* right;
};


class Prstr : public Tree {
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

	void add_tree_class(const Prstr& other, Prstr*& aBranch) {

		if (!aBranch) {

			aBranch = new Prstr;
			aBranch->field = &other;
			aBranch->left = 0;
			aBranch->right = 0;
			return;
		}
		else {

			if (aBranch->field > & other) {

				Tree::add_tree_class(other, aBranch->left);
			}
			else {

				Tree::add_tree_class(other, aBranch->right);
			}
		}
	};

	void print_tree_class(Prstr*& aBranch) {

		if (!aBranch) return;
		tabs++;

		Tree::print_tree_class(aBranch->left);

		for (int i = 0; i < tabs; i++) cout << " ";
		cout << aBranch->field << endl;

		Tree::print_tree_class(aBranch->right);

		tabs--;
	};

	void delete_tree_class(Prstr*& aBranch) {

		if (!aBranch) return;
		Tree::delete_tree_class(aBranch->left);
		Tree::delete_tree_class(aBranch->right);
		delete aBranch;
		return;
	};

	~Prstr();

protected:

	char* pp;
	int len_c = 0;
};