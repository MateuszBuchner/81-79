#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


const int SIZE = 2000;
double tab[SIZE][3];



bool jestCwiartka(double x, double y, double r) {
  return (abs(x) > r && abs(y) > r);
}

void z1() {
  cout << "Zadanie 1:" << endl;
  int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter0 = 0;
  for (int i = 0; i < SIZE; i++) {
    float x = tab[i][0], y = tab[i][1], r = tab[i][2];
    if (jestCwiartka(x, y, r)) {
      if (x > 0 && y > 0) counter1++;
      if (x < 0 && y > 0) counter2++;
      if (x < 0 && y < 0) counter3++;
      if (x > 0 && y < 0) counter4++;
    }
    else counter0++;
  }
  cout << "I: " << counter1 << endl;
  cout << "II: " << counter2 << endl;
  cout << "III: " << counter3 << endl;
  cout << "IV: " << counter4 << endl;
  cout << "0: " << counter0 << endl;
  cout << endl;
}


bool saLustrzane(double x1, double y1, double r1, double x2, double y2, double r2) {
	if (r1 != r2) return false;
	if (x1 == x2 && y1 == y2) return false;
	if (abs(x1) == abs(x2) && y1 == y2) return true;
	if (abs(y1) == abs(y2) && x1 == x2) return true;
	return false;
}

void z2() {
	cout << "Zadanie 2:" << endl;
	int counter = 0;
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (saLustrzane(tab[i][0], tab[i][1], tab[i][2], tab[j][0], tab[j][1], tab[j][2])) {
				counter++;
			}
		}
	}
	cout << counter << endl << endl;
}

int main() {
  ifstream in("okregi.txt");
  double a, b, c;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b >> c;
    tab[i][0] = a;
    tab[i][1] = b;
    tab[i][2] = c;
  }
  in.close();
  
  z1();
  z2();

}
