  
#include "Header.h"

using namespace std;

void AutoTest() {
    bool m,n;
    CRat A;
    CRat B;
    int* p = new int[3];
    int* q = new int(3);
    m = true;
    p[0] = 2;
    p[1] = 2;
    p[2] = 0;
    q[0] = 1;
    q[1] = 1;
    q[2] = 1;
    A.Set(p, q, 3);
    int* pi = new int[3];
    int* qi = new int(3);
    m = true;
    pi[0] = 1;
    pi[1] = 0;
    pi[2] = 3;
    qi[0] = 1;
    qi[1] = 1;
    qi[2] = 1;
    B.Set(pi, qi, 3);
    CRat C = A + B;
    C.Get();
    CRat D = A - B;
    D.Get();
    if (C.P()[0] == 1 && C.P()[1] == 1 && C.P()[2] == 7  && D.P()[0] == 3 && D.P()[1] == 2 && D.P()[2] == 3 ) {
        cout << "AutoTest passed..." << endl;
    }
    else {
        cout << "AutoTest falled..." << endl;
    }
}