#include <iostream>
#include <fstream>

using namespace std;

void trierTab(int* tab, int taille);
void afficherTab(int* tab, int taille);
bool egalite(int tab1[], int tab2[], int taille);
bool egalitePtr(int* tab1, int* tab2, int taille);
int* concatenerTab(int* tab1, int* tab2, int taille);

int main() {
	const int NB_ELEMENTS = 10;
	int tableau1[] = { 22, 44, 12, 61, 4, 99, 33, 17, 15, 123 };
	int tableau2[] = { 22, 33, 44, 61, 4, 99, 12, 17, 123, 15 };
	int tableau3[] = { 22, 44, 12, 61, 4, 99, 33, 17, 15, 123 };


	int* tableau4 = concatenerTab(tableau1, tableau2, NB_ELEMENTS);
	afficherTab(tableau1, NB_ELEMENTS);
	afficherTab(tableau2, NB_ELEMENTS);
	afficherTab(tableau3, NB_ELEMENTS);
	afficherTab(tableau4, NB_ELEMENTS * 2);

	cout << "Tableau1 et tableau2 sont " << (egalite(tableau1, tableau2, NB_ELEMENTS) ? "egaux" : "differents") << endl;

	cout << "Tableau1 et tableau3 sont " << (egalite(tableau1, tableau3, NB_ELEMENTS) ? "egaux" : "differents") << endl;

	cout << "Tableau1 et tableau2 sont " << (egalitePtr(tableau1, tableau2, NB_ELEMENTS) ? "egaux" : "differents") << endl;

	cout << "Tableau1 et tableau3 sont " << (egalitePtr(tableau1, tableau3, NB_ELEMENTS) ? "egaux" : "differents") << endl;

	trierTab(tableau1, NB_ELEMENTS);
	trierTab(tableau2, NB_ELEMENTS);
	trierTab(tableau3, NB_ELEMENTS);
	trierTab(tableau4, NB_ELEMENTS * 2);

	afficherTab(tableau1, NB_ELEMENTS);
	afficherTab(tableau2, NB_ELEMENTS);
	afficherTab(tableau3, NB_ELEMENTS);
	afficherTab(tableau4, NB_ELEMENTS * 2);

	cout << "Tableau1 et tableau2 sont " << (egalitePtr(tableau1, tableau2, NB_ELEMENTS) ? "egaux" : "differents") << endl;

	cout << "Tableau1 et tableau3 sont " << (egalitePtr(tableau1, tableau3, NB_ELEMENTS) ? "egaux" : "differents") << endl;

	return 0;
}

void trierTab(int* tab, int taille) {
	for (int i = 0; i < taille; i++) {
		for (int j = i + 1; j < taille; j++) {
			if (tab[i] > tab[j]) {
				int temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
		}
	}
}

void afficherTab(int* tab, int taille) {
	for (int i = 0; i < taille; i++) {
		cout << *(tab + i) << " ";
	}
	cout << endl;
}


bool egalite(int tab1[], int tab2[], int taille) {
	for (int i = 0; i < taille; i++) {
		if (tab1[i] != tab2[i]) {
			return false;
		}
	}
	return true;
}


bool egalitePtr(int* tab1, int* tab2, int taille) {
	for (int i = 0; i < taille; i++) {
		if (*(tab1 + i) != *(tab2 + i)) {
			return false;
		}
	}
	return true;
}

int* concatenerTab(int* tab1, int* tab2, int taille) {
	int* tab3 = new int[taille * 2];
	for (int i = 0; i < taille; i++) {
		*(tab3 + i) = *(tab1 + i);
		*(tab3 + i + taille) = *(tab2 + i);
	}
	afficherTab(tab3, taille * 2);
	return tab3;
}



