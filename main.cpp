/**
*@file main.cpp
*@Author Muhammed Suwaneh
*@date 12 January, 2021
*/

#include <iostream>
#include "Splay.h"

using namespace std;
void TestSplayTree();
//void TestTrie();

int main() {
	TestSplayTree();
	system("pause");
	return 0;
}

void TestSplayTree() {
	try {
		Splay spl;
		spl.add(15); cout << "Adding 15...." << endl;
		spl.add(6); cout << "Adding 6...." << endl;
		spl.add(18); cout << "Adding 18...." << endl;
		spl.add(3); cout << "Adding 3...." << endl;
		spl.add(12); cout << "Adding 12...." << endl;
		spl.add(10); cout << "Adding 10...." << endl;
		spl.add(14); cout << "Adding 14...." << endl;

		spl.printLevelByLevel();
		spl.print();

		//! zig-zag search
		cout << "-------------------------------------" << endl;
		spl.find(12); cout << "Searching for 12..." << endl;
		spl.printLevelByLevel();
		spl.print();

		//! zig-zig search
		cout << "-------------------------------------" << endl;
		spl.find(3); cout << "Searching for 3..." << endl;
		spl.printLevelByLevel();
		spl.print();

		//! zag search
		cout << "-------------------------------------" << endl;
		spl.find(6); cout << "Searching for 6..." << endl;
		spl.printLevelByLevel();
		spl.print();

		//! zag-zig then zag search
		cout << "-------------------------------------" << endl;
		spl.find(14); cout << "Searching for 14..." << endl;
		spl.printLevelByLevel();
		spl.print();

		//! zag-zag search
		cout << "-------------------------------------" << endl;
		spl.find(18); cout << "Searching for 18..." << endl;
		spl.printLevelByLevel();
		spl.print();

		//! zig-zag then zig-zig search
		cout << "-------------------------------------" << endl;
		spl.find(12); cout << "Searching for 12..." << endl;
		spl.printLevelByLevel();
		spl.print();

		cout << "-------------------------------------------" << endl;
	}
	catch (exception& e) {
		cout << "Exception thrown: " << e.what() << endl;
	}
}