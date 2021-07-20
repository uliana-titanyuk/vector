#pragma once
#include <vector>

class CRat {

public:

	//конструкторы, деструктор, операторы присваивания, сложения, вычитания, скалярного умножения
	CRat(const std::vector < std::pair< int, unsigned int > >& values);
	CRat(const char* FileName);

	~CRat();

	int output(const char* FileName);
	CRat& operator=(const CRat& b);
	CRat operator+(const CRat& b);
	CRat operator-(const CRat& b);
	CRat operator*(int b);
	int check(const CRat& b, const CRat& a);
private:
	CRat() {};

	std::vector < std::pair< int, unsigned int > > fractions;
	CRat& reduce();

};
void AutoTest();
