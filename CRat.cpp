#include "CRat.h"
#include<fstream>
#include <iostream>
#include <string>
#include <cmath>

CRat::CRat(const std::vector < std::pair< int, unsigned int > >& values) {
    fractions = values;
}

CRat::CRat(const char* FileName) {
    std::ifstream inf{ FileName };
    if (!inf) { 
        throw "File error.null pointer"; 
    }
    if (!inf.is_open())
    {
        throw "File can not be opened.";
    }
    //int i = 0;
    int a;
    unsigned int b;
    //while (inf >> a >> b){
    while (not EOF) {
        inf >> a;
        inf >> b;
       fractions.push_back(std::make_pair(a, b));
       if (b == 0) {
           throw "wrong data";
       }
    }
    inf.close(); 
}
int CRat :: output(const char* FileName) {
       
    std::ofstream outf{ FileName };
    if (!outf) return -1;
    for (size_t i = 0; i < fractions.size(); i++){
        outf << fractions[i].first << " " << fractions[i].second << "   ";
    }
    outf.close();
    return 0;
}

CRat::~CRat() {
};

CRat CRat::operator+(const CRat& b) {
    int  n;
    CRat v;
    n = fractions.size();
    for (int i = 0; i < n; i++) {
        if ((fractions[i].first != 0) && (b.fractions[i].first != 0)) {
            v.fractions[i].first = fractions[i].first * b.fractions[i].second + fractions[i].second * b.fractions[i].first;
            v.fractions[i].second = b.fractions[i].second * fractions[i].second;
            int a = v.fractions[i].first;
            int b = v.fractions[i].second;
        }
     }
   
        return v;
 }
    CRat CRat::operator-(const CRat & b) {
        int  n;
        CRat v;
        n = fractions.size();
        for (int i = 0; i < n; i++) {
            if ((fractions[i].first != 0) && (b.fractions[i].first != 0)) {
                v.fractions[i].first = fractions[i].first * b.fractions[i].second - fractions[i].second * b.fractions[i].first;
                v.fractions[i].second = b.fractions[i].second * fractions[i].second;
                int a = v.fractions[i].first;
                int b = v.fractions[i].second;
            }
        }

        return v;
    }
    CRat CRat::operator*(int k) {
        int  n;
        CRat v;
        n = fractions.size();
        for (int i = 0; i < n; i++) {
            v.fractions[i].first = k * fractions[i].first;
            v.fractions[i].second = fractions[i].second;
        }
        v.reduce();
    return v;
    }
    CRat& CRat::reduce() {
        int n = fractions.size();
        for (int i = 0; i < n; i++) {

            int a = fractions[i].first;
            int b = fractions[i].second;
            a = abs(a); b = abs(b);
            while (a != 0 and b != 0) {
                if (a > b) {
                    a = a % b;
                }
                else {
                    b = b % a;
                }
            }
            fractions[i].first = fractions[i].first / (a + b);
            fractions[i].second = fractions[i].second / (a + b);
        }
        
        return *this;
    }
     CRat& CRat :: operator=(const CRat& b) {
         int n = fractions.size();
         for (int i = 0; i < n; i++) {
             fractions[i].first = b.fractions[i].first;
             fractions[i].second = b.fractions[i].second;
         }
         return *this;
     }
     int CRat ::check(const CRat& b,const CRat& a) {
         reduce();
         int n = fractions.size();
         int x = 0;
         for (int i = 0; i < n; i++) {
             if ((a.fractions[i].first == b.fractions[i].first) && (a.fractions[i].second == b.fractions[i].second)) {
                 x += 1;
             }
         }
         return x;
     }