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
	bool operator!=(const CRat& a);
private:
	CRat() {};

	std::vector < std::pair< int, unsigned int > > fractions;
	void reduce();

};

