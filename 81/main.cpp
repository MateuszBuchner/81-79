#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

const int SIZE = 100;
int tab[SIZE][6];



void z1() {
	cout << "Zadanie 1:" << endl;
	int counter = 0;
	bool flag;
	for (int i = 0; i < SIZE; i++) {
		flag = true;
		for (int j = 0; j < 6; j++) {
			if (tab [i][j] <= 0) flag = false;
		}
		if (flag) counter++;
	}
	cout << counter << endl << endl;
}

void z2() {
	cout << "Zadanie 2:" << endl;
	int counter = 0;
	for (int i = 0; i < SIZE; i++) {
		int x1 = tab[i][0];
		int y1 = tab[i][1];
		int x2 = tab[i][2];
		int y2 = tab[i][3];
		int x3 = tab[i][4];
		int y3 = tab[i][5];
		if ((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)) { 
			counter++;
		}
	}
	cout << counter << endl << endl;
}


void z3() {
	cout << "Zadanie 3:" << endl;
	double max = 0;
	int xa, ya, xb, yb, xc, yc;
	double d1, d2, d3;
	double obwod;
	for (int i = 0; i < SIZE; i++) {
		d1 = sqrt(pow(tab[i][0] - tab[i][2], 2) + pow(tab[i][1] - tab[i][3], 2));
		d2 = sqrt(pow(tab[i][0] - tab[i][4], 2) + pow(tab[i][1] - tab[i][5], 2));
		d3 = sqrt(pow(tab[i][2] - tab[i][4], 2) + pow(tab[i][3] - tab[i][5], 2));
		obwod = d1 + d2 + d3;
		if (obwod > max) {
			max = obwod;
			xa = tab[i][0];
			ya = tab[i][1];
			xb = tab[i][2];
			yb = tab[i][3];
			xc = tab[i][4];
			yc = tab[i][5];
		} 
	}
	cout << xa << ", " << ya << "; " << xb << ", " << yb << "; " << xc << ", " << yc << endl;
	cout << "Obwod: " << setprecision(5) << max << endl << endl;
}



int main() {
	ifstream in("wierzcholki.txt");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < 6; j++) {
			in >> tab[i][j];
		}
	}
	in.close();
	
	z1();
	z2();
	
	in.open("wierzcholkiTR.txt");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < 6; j++) {
			in >> tab[i][j];
		}
	}
	in.close();
	
	z3();

}
