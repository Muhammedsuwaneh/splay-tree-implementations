/**
*@file SplayNode.h
*@Author Muhammed Suwaneh
*@date 12 January, 2021
*/
#include <iostream>

struct SplayNode {
	int key;
	SplayNode* left, *right;
	SplayNode(int key): key(key), left(NULL), right(NULL) {}
};