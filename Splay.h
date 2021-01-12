/**
*@file Splay.h
*@Author Muhammed Suwaneh
*@date 12 January, 2021
*/
#ifndef _SPLAY_
#define _SPLAY_
#include <iostream>
#include <vector>
#include <stack>
#include "SplayNode.h"

using namespace std;
class Splay
{
private:
	SplayNode* root;

	void printAux(SplayNode* node);
	void eraseTreeNodes(SplayNode* node);
	void getKeysLevelByLevel(SplayNode* node, int level, vector<vector<int>>& keys);
	void splay(stack<SplayNode*>& S);
public:
	Splay() { root = NULL; }
	~Splay() { eraseTreeNodes(root); root = NULL; }
	bool find(int key);
	int min();
	int max();
	void add(int key);
	void remove(int key);
	void print();
	void printLevelByLevel();
};

#endif //! _SPLAY_

