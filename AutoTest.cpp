  
#include "CRat.h"
#include <iostream>


using namespace std;

void AutoTest() {
	char string[11] = "file_0.txt";
	CRat a = CRat("file_0.txt");
	std::vector < std::pair< int, unsigned int > >  v(1);
	v[0].first = 1; v[0].second = 1;
	std::vector < std::pair< int, unsigned int > >  w(2);
	w[0].first = 1; w[0].second = 1; w[1].first = 0; w[1].second = 1;
	CRat b = CRat(v);
	CRat c = a + b;
	CRat d = b-a;
	CRat e = b*2;
	CRat ai = CRat(w);
	CRat bi = CRat("file_1.txt");
	w[0].first = 2; w[0].second = 1; w[1].first = 0; w[1].second = 1;
	v[0].first = 0; v[0].second = 1;
	CRat ci = CRat(w);
	CRat di = CRat(v);
	v[0].first = 2; v[0].second = 1;
	CRat ei = CRat(v);
	if (a!= ai) {
		cout << "CRat(const char* FileName)  failed";
	}
	if (b!=bi) {
		cout << "CRat(const std::vector < std::pair< int, unsigned int > >& values) failed";
	}
	if (c!=ci) {
		cout << "operator+ failed";
	}
	if (d!=di)  {
		cout << "operator- failed";
	}
	if (e!=ei) {
		cout << "operator* failed";
	}
}
 
