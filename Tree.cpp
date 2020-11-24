#include "Tree.h"
#include<iostream>

using namespace std;

void Tree::add_tree_class(const Tree& other, Tree*& aBranch) {

	if (!aBranch) {

		aBranch = new Tree;
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
}


void Tree::print_tree_class(Tree*& aBranch) {

	if (!aBranch) return;
	tabs++;

	Tree::print_tree_class(aBranch->left);

	for (int i = 0; i < tabs; i++) cout << " ";
	cout << aBranch->field << endl;

	Tree::print_tree_class(aBranch->right);

	tabs--;
}


void Tree::delete_tree_class(Tree*& aBranch) {

	if (!aBranch) return;
	Tree::delete_tree_class(aBranch->left);
	Tree::delete_tree_class(aBranch->right);
	delete aBranch;
	return;
}
