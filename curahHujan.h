#ifndef CURAH_HUJAN_H
#define CURAH_HUJAN_H

#include <iostream>
using namespace std;

struct Node {
	int hari;
	int jam;
	int curahHujan;
	Node* next;
	Node* prev;

	Node(int h, int j, int c);
};

class Curah_Hujan {
private:
	struct jamNode {
		int jam;
		int curahHujan;
		jamNode* next;
	};

	struct hariNode {
		int hari;
		jamNode* headJam;
		hariNode* next;
	};

	hariNode* headHari;

public:
	Node* head;
	Node* tail;
	int size;

	Curah_Hujan();

	void printData();
	hariNode* insertHari(int hari);
	hariNode* searchHari(int cariHari);
	void insertJam(hariNode* hari, int jam, int curah);
	void tambahDataHujan(int hari);
};

#endif
