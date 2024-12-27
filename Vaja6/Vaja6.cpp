#include <iostream>
#include <time.h>
#include <vector>
#include <chrono>
using namespace std;

void menu() {
	cout << endl;
	cout << "Quick sort - izbira:" << endl;
	cout << endl;
	cout << "1) Generiraj nakljucno zaporedje" << endl;
	cout << "2) Generiraj narascujoce zaporedje" << endl;
	cout << "3) Generiraj padajoce zaporedje" << endl;
	cout << "4) Izpis zaporedja" << endl;
	cout << "5) Preveri ali je zaporedje urejeno" << endl;
	cout << "6) Hitro urejanje brez mediane" << endl;
	cout << "7) Hitro urejanje z mediano" << endl;
	cout << "8) Uredi z izbiranjem" << endl;
	cout << "9) Konec" << endl;
	cout << endl;
	cout << "Izbira: ";
}


void generateRandom(vector<int>& tab, unsigned int N, unsigned int& vrh) {
	if (tab.size() != NULL) {
		tab.clear();
	}

	for (int i = 0; i < N; i++) {
		tab.push_back(rand() % N + 1);
	}

	vrh = tab.size() - 1;
}


void generateAscending(vector<int>& tab, unsigned int N, unsigned int& vrh) {
	if (tab.size() != NULL) {
		tab.clear();
	}

	for (int i = 0; i < N; i++) {
		tab.push_back(i + 1);
	}

	vrh = N - 1;
}


void generateDescending(vector<int>& tab, unsigned int N, unsigned int& vrh) {
	if (tab.size() != NULL) {
		tab.clear();
	}

	for (int i = N; i > 0; i--) {
		tab.push_back(i);
	}

	vrh = N - 1;
}


void print(vector<int>tab) {
	for (int i = 0; i < tab.size(); i++) {
		cout << tab[i] << " ";
	}
}


bool isSorted(vector <int> tab) {
	bool sorted = false;

	for (int i = 1; i < tab.size(); i++) {
		if (tab[i] >= tab[i - 1]) {
			sorted = true;
		}
		else {
			return false;
		}
			
	}

	return sorted;
}


int deli(vector <int>& tab, int& dno, int& vrh) {
	int fixed = tab[dno];
	int l = dno;
	int d = vrh;

	while (l < d) {
		while (tab[l] <= fixed && l < vrh)
			l++;
		while (tab[d] >= fixed && d > dno)
			d--;

		if (l < d)
			std::swap(tab[l], tab[d]);
	}

	std::swap(tab[dno], tab[d]);
	return d;
}

void QuickSort(vector <int>& tab, int dno, int vrh) {
	int j;
	if (dno < vrh) {
		j = deli(tab, dno, vrh);
		QuickSort(tab, dno, j-1);
		QuickSort(tab, j+1, vrh);
	}
}


int deliWithMediana(vector <int>& tab, int& dno, int& vrh) {
	int med = dno + (vrh - dno) / 2;
	std::swap(tab[dno], tab[med]);

	int fixed = tab[dno];
	int l = dno;
	int d = vrh;

	while (l < d) {
		while (tab[l] <= fixed && l < vrh)
			l++;
		while (tab[d] >= fixed && d > dno)
			d--;

		if (l < d)
			std::swap(tab[l], tab[d]);
	}
		
	std::swap(tab[dno], tab[d]);
	return d;
}

void QuickSortWithMediana(vector <int>& tab, int dno, int vrh) {
	int j;
	if (dno < vrh) {
		j = deliWithMediana(tab, dno, vrh);
		QuickSortWithMediana(tab, dno, j - 1);
		QuickSortWithMediana(tab, j + 1, vrh);
	}

}


void SelectionSort(vector <int>& tab, int N) {
	int minIndex;
	for (int i = 0; i < N - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < N; j++) {
			if (tab[j] < tab[minIndex])
				minIndex = j;
		}
		if (minIndex != i)
			std::swap(tab[i], tab[minIndex]);
	}
}


int main() {
	bool running = true;
	int izbira;

	unsigned int N;
	vector<int> tab;
	unsigned int dno = 0;
	unsigned int vrh = 0;

	srand(time(nullptr));
	do {
		cout << endl;
		menu();
		cin >> izbira;
		switch (izbira) {
		case 1:
			cout << "Dolzina nakljucnega zaporedja: ";
			cin >> N;
			generateRandom(tab, N, vrh);
			break;

		case 2:
			cout << "Dolzina narascujocega zaporedja: ";
			cin >> N;
			generateAscending(tab, N, vrh);
			break;

		case 3:
			cout << "Dolzina padajocega zaporedja: ";
			cin >> N;
			generateDescending(tab, N, vrh);
			break;

		case 4:
			if (dno == vrh)
				cout << "Zaporedje je prazno!" << endl;
			else
				print(tab);
			break;

		case 5:
			if (isSorted(tab)) {
				cout << "Zaporedje je urejeno." << endl;
			}
			else {
				cout << "Zaporedje ni urejeno." << endl;
			}
			break;

		case 6:
			if (dno == vrh)
				cout << "Zaporedje je prazno!" << endl;
			else {
				auto start = std::chrono::steady_clock::now();
				QuickSort(tab, dno, vrh);
				auto end = std::chrono::steady_clock::now();
				cout << "Cas sortiranja: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "μs." << endl;
			}

			break;

		case 7:
			if (dno == vrh)
				cout << "Zaporedje je prazno!" << endl;
			else {
				auto start = std::chrono::steady_clock::now();
				QuickSortWithMediana(tab, dno, vrh);
				auto end = std::chrono::steady_clock::now();
				cout << "Cas sortiranja: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "μs." << endl;
			}
			break;

		case 8:
			if (dno == vrh)
				cout << "Zaporedje je prazno!" << endl;
			else {
				auto start = std::chrono::steady_clock::now();
				SelectionSort(tab, N);
				auto end = std::chrono::steady_clock::now();
				cout << "Cas sortiranja: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "μs." << endl;
			}
			break;

		case 9:
			running = false;
			break;

		default:
			cout << "Narobe izbira!" << endl;
			break;
		}
	} while (running);

	return 0;
}
