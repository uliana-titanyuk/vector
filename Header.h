#pragma once
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>
void AutoTest();
void AutoTest();


class CRat {
	int* p;
	int* q;
	int n;
public:
	int* P()const {
		return p;
	}
	int lenght()const {
		return n;
	}
	int* Q()const {
		return q;
	}
	CRat() {
		SetZero();
	}
	~CRat() {
		Clean();
	}
	CRat(const CRat& b) {
		CopyOnly(b);
	}
	CRat& operator=(const CRat& b) {
		if (this != &b) {
			Clean();
			CopyOnly(b);
		}
		return *this;
	}
	void Set(int* p, int* q, int n);
	void Clean() {
		delete[] p;
		delete[] q;
		SetZero();
	}
	void SetZero() {
		p = NULL;
		q = NULL;
		n = 0;
	}
	void CopyOnly(const CRat& b) {
		n = b.n;
		p = new int[n];
		q = new int[n];
		for (int i = 0; i < n; i++){
			p[i] = b.p[i];
		    q[i] = b.q[i];
	}
	}
	CRat(int* p, int* q, const int n);
	CRat operator+(const CRat& b);
	CRat operator-(const CRat& b);
	CRat& operator=(const CRat& b);
	int& operator[](int i) const;
	int& operator()(int i) const;
	void GetNumber()const;
};
