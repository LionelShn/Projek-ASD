#include "CurahHujan.h"

Node::Node(int h, int j, int c) {
	hari = h;
	jam = j;
	curahHujan = c;
	next = nullptr;
	prev = nullptr;
}

Curah_Hujan::Curah_Hujan() {
	head = nullptr;
	tail = nullptr;
	size = 0;
	headHari = nullptr;
}

Curah_Hujan::hariNode* Curah_Hujan::insertHari(int hari) {
	hariNode* newHari = new hariNode();
	newHari->hari = hari;
	newHari->headJam = nullptr;
	newHari->next = nullptr;

	if (headHari == nullptr) {
		headHari = newHari;
	}
	else {
		hariNode* temp = headHari;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newHari;
	}
	return newHari;
}

Curah_Hujan::hariNode* Curah_Hujan::searchHari(int cariHari) {
	hariNode* current = headHari;
	while (current != nullptr) {
		if (current->hari == cariHari) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

void Curah_Hujan::insertJam(hariNode* hari, int jam, int curah) {
	jamNode* newJam = new jamNode();
	newJam->jam = jam;
	newJam->curahHujan = curah;
	newJam->next = nullptr;

	if (hari->headJam == nullptr) {
		hari->headJam = newJam;
	}
	else {
		jamNode* current = hari->headJam;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newJam;
	}
}

void Curah_Hujan::tambahDataHujan(int hari) {
	char jawaban;
	cout << "Apakah hari ke-" << hari << " turun hujan? (y/n): ";
	cin >> jawaban;

	if (jawaban == 'n') {
		hariNode* h = searchHari(hari);
		if (h == nullptr) {
			insertHari(hari);
		}
		return;
	}

	hariNode* h = searchHari(hari);
	if (h == nullptr) {
		h = insertHari(hari);
	}

	int jam;
	int curah;
	char lanjut = 'y';

	cout << "Jam berapa turun hujan: ";
	cin >> jam;

	while (lanjut == 'y') {
		cout << "Masukkan curah hujan (dalam bentuk mm) jam " << jam << ": ";
		cin >> curah;
		jam++;

		insertJam(h, jam, curah);

		cout << "Apakah hujan masih lanjut? (y/n): ";
		cin >> lanjut;
	}
}

void Curah_Hujan::printData() {
	if (headHari == nullptr) {
		cout << "Data Kosong" << endl;
		return;
	}

	hariNode* hariTemp = headHari;
	while (hariTemp != nullptr) {
		cout << "Hari ke-" << hariTemp->hari << ":" << endl;

		jamNode* jamTemp = hariTemp->headJam;
		if (jamTemp == nullptr) {
			cout << "Tidak ada hujan" << endl;
		}
		else {
			while (jamTemp != nullptr) {
				cout << "Jam " << jamTemp->jam << " Curah Hujan: " << jamTemp->curahHujan << " mm" << endl;
				jamTemp = jamTemp->next;
			}
		}
		hariTemp = hariTemp->next;
		cout << "_ _ _ _ _ _ _ _ _ _ _" << endl;
	}
}
