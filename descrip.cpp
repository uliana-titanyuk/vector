#include "Header.h"
using namespace std;


void CRat::Set(int* p, int* q, int n) {
    this->p = p;
    this->q = q;
    this->n = n;
}


int& CRat::operator[](int i) const {
    if (i < 0 || i >= n) {
        printf("Error.Incorrect index\n");
        throw - 1;
    }
    return p[i];
}
int& CRat::operator()(int i) const {
    if (i < 0 || i >= n) {
        printf("Error.Incorrect index\n");
        throw - 1;
    }
    return q[i];
}

CRat::CRat(int* p, int* q, const int n) {
    this->p = new int[n];
    this->q = new int(n);
    this->n = n;
    for (int i = 0; i < n; i++)
        this->p[i] = p[i];
        this->q[i] = q[i];
}


CRat CRat::operator+(const CRat& b) {
    int t = 0;
    CRat r;
    r.p = new int[r.n = n];
    r.q = new int(r.n = n);
    for (int i = r.n - 1; i >= 1; i--) {
        r.p[i] = p[i] * b.q[i] + b.p[i] * q[i];
        r.q[i] = q[i] * b.q[i];
    }
             return r;
             delete[] r.p;
             delete[] r.q;
    }
   

CRat CRat::operator-(const CRat& b) {
    int t = 0;
    CRat r;
    r.p = new int[r.n = n];
    r.q = new int(r.n = n);
    for (int i = r.n - 1; i >= 1; i--) {
        r.p[i] = p[i] * b.q[i] - b.p[i] * q[i];
        r.q[i] = q[i] * b.q[i];
    }
    return r;
    delete[] r.p;
    delete[] r.q;
}
CRat& CRat :: operator=(const CRat& b) {
    for (int i = 0; i < n; i++) {
        p[i] = b.p[i];
        q[i] = b.q[i];
    }
    n = b.n;

    return *this;
};

void CRat::Get()const {
    
    for (int i = 0; i < n; i++) {
        printf("%d", p[i]);
        printf("/");
        printf("%d", q[i]);
    }
    printf("\n");
}
