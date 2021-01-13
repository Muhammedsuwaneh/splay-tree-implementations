/**
*@file Splay.cpp
*@Author Muhammed Suwaneh
*@date 12 January, 2021
*/
#include <iostream>
#include "Splay.h"

using namespace std;

//! erases all tree nodes to avoid memory leaking
void Splay::eraseTreeNodes(SplayNode* node) {

	if (node == NULL) return;
	eraseTreeNodes(node->right);
	eraseTreeNodes(node->left);
	delete node;
}//! end-eraseTreeNodes

//! performs splay operations
void Splay::splay(stack<SplayNode*>& S) {
	  
	while (S.size() > 1) {
		SplayNode* x = S.top(); S.pop();
		SplayNode* p = S.top(); S.pop();
		SplayNode* g = NULL;

		if (!S.empty()) { 
			g = S.top(); S.pop();
		}
		SplayNode* pg = NULL;
		if (!S.empty())
			pg = S.top();

		//! rotations
		if(g == NULL) {
			//! single rotations 

			//! perform a Zig operation
			if (x == p->left) {
				p->left = x->right;
				x->right = p;
			}
			//! perform a Zag operation
			else {
				p->right = x->left;
				x->left = p;
			}
			root = x;
			break;
		}

		else {

			//! double rotations
			if (p == g->left) {

				//! zig-zig
				if (x == p->left) {
					p->left = p->right;
					p->right = g;
					p->left = x->right;
					x->right = p;
				}
				//! zig-zag
				else {

					g->left = x->right;
					x->right = g;
					p->right = x->left;
					x->left = p;
				}
			}

			else {

				//! zig-zag
				if(x == p->right) {
					g->right = p->left;
					p->left = g;
					p->right = x->left;
					x->left = p;
				}
				//! zag-zig
				else {
					g->right = x->left;
					x->left = g;
					p->left = x->right;
					x->right = p;
				}
			}

			if (pg == NULL) { root = x; break; }
			else if (g == pg->left) pg->left = x;
			else pg->right = x;

			S.push(x);
		}
	}//! end-while
}//!end-splay

//! finds a node based on given key
bool Splay::find(int key) {
	stack<SplayNode*> S;
	SplayNode* p = root;

	while (p) {
		S.push(p);
		if (key == p->key) {
			splay(S);
			return true;
		}
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	return false;
}

//! finds the min node in tree
int Splay::min() {

	if (root == NULL) throw exception("Splay::min - Tree is empty");

	SplayNode* p = root;
	while (p->left != NULL) p = p->left;

	return p->key;
}

//! finds max node in tree
int Splay::max() {

	if (root == NULL) throw exception("Splay::max - Tree is empty");

	SplayNode* p = root;
	while (p->right != NULL) p = p->right;

	return p->key;
}

void Splay::add(int key) {
	SplayNode* q = NULL;
	SplayNode* p = root;
	while (p) {

		q = p;
		if (p->key == key)
			return;
		else if (key < p->key)
			p = p->left;
		else
			p = p->right;
	}
	SplayNode* node = new SplayNode(key);
	if (root == NULL) root = node;
	else if (key < q->key) q->left = node;
	else q->right = node;
}

void Splay::remove(int key) {
	SplayNode* pp = NULL;
	SplayNode* p = root;

	while (p && p->key != key) {
		pp = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	if (p == NULL) return;

	if (p->left && p->right) {

		SplayNode* qp = p;
		SplayNode* q = p->left;

		while (q->right) {
			qp = q;
			q = q->right;
		}
		p->key = q->key;
		pp = qp;
		p = q;
	}

	if (p == root) {
		root = root->left ? root->left : root->right;
		delete p;
		return;
	}
	if (p == pp->left) pp->left = p->left ? p->left : p->right;
	else pp->right = p->left ? p->left : p->right;

	delete p;
}

//! prints all tree nodes
void Splay::print() {
	
	cout << "Splay Tree Keys" << endl;
	cout << "[ ";
	printAux(root);
	cout << " ]" << endl;
	cout << "\b\b " << endl;
}
void Splay::printAux(SplayNode* node) {
	if (node == NULL) return;
	printAux(node->left);
	cout << ", " << node->key;
	printAux(node->right);
}
//! prints tree nodes in each level
void Splay::printLevelByLevel() {

	vector<vector<int>> keys;
	getKeysLevelByLevel(root, 0, keys);

	cout << "Splay tree level by level" << endl;
	for (int i = 0; i < keys.size(); i++) {

		cout << "Level " << i << ": ";
		for (auto key : keys[i]) 
			cout << key << " ";

		cout << endl;
	}
}
//! prints nodes in each level
void Splay::getKeysLevelByLevel(SplayNode* node, int level, vector<vector<int>>& keys) {
	if (node == NULL) return;
	if (level >= (int)keys.size()) keys.push_back(vector<int>{node->key});
	else keys[level].push_back(node->key);

	getKeysLevelByLevel(node->left, level + 1, keys);
	getKeysLevelByLevel(node->right, level + 1, keys);
}

