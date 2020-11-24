#pragma once

class Tree {
public:

	void add_tree_class(const Tree& other, Tree*& aBranch);

	void print_tree_class(Tree*& aBranch);

	void delete_tree_class(Tree*& aBranch);

protected:

	int tabs = 0;
	const Tree* field;
	Tree* left;
	Tree* right;
};