
#include "CRat.h"
#include<fstream>
#include <iostream>
#include <string>
#include <cmath>

CRat::CRat(const std::vector < std::pair< int, unsigned int > >& values) {
    fractions = values;
}

#include "CRat.h"
#include<fstream>
#include <iostream>
#include <string>
#include <cmath>

CRat::CRat(const std::vector < std::pair< int, unsigned int > >& values) {
    fractions = values;
}

CRat::CRat(const char* FileName) {
    if (FileName) {
        throw "File error.null pointer";
    }
    std::ifstream inf{ FileName };
    
    if (!inf.is_open())
    {
        throw "File can not be opened.";
    }
    //int i = 0;
    int a;
    unsigned int b;
    //while (inf >> a >> b){
    while ((inf >> a)&&(inf >> b)) {
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
    size_t n = std::min(fractions.size(), b.fractions.size());
    CRat v;
    for (size_t i = 0; i < n; i++) {
        std::pair <int, unsigned int> p=std::make_pair(fractions[i].first * b.fractions[i].second + fractions[i].second * b.fractions[i].first,b.fractions[i].second * fractions[i].second);
        v.fractions.push_back(p);
    }
    if (n < fractions.size())
    {
        for (size_t i = 0; i < fractions.size(); i++) {
            v.fractions.push_back(fractions[i]);
        }
    }
        if (n < fractions.size())
        {
            for (size_t i = 0; i < b.fractions.size(); i++) {
                v.fractions.push_back(b.fractions[i]);
            }
        }
        return v;
 }


CRat CRat::operator-(const CRat & b) {
        size_t n = std::min(fractions.size(), b.fractions.size());
        CRat v;
        for (size_t i = 0; i < n; i++) {
            std::pair <int, unsigned int> p = std::make_pair(fractions[i].first * b.fractions[i].second - fractions[i].second * b.fractions[i].first, b.fractions[i].second * fractions[i].second);
            v.fractions.push_back(p);
        }
        if (n < fractions.size())
        {
            for (size_t i = 0; i < fractions.size(); i++) {
                v.fractions.push_back(fractions[i]);
            }
        }
        if (n < fractions.size())
        {
            for (size_t i = 0; i < b.fractions.size(); i++) {
                v.fractions.push_back(b.fractions[i]);
            }
        }
        return v;
}


CRat CRat::operator*(int k) {
CRat v;
size_t n = fractions.size();
for (size_t i = 0; i < n; i++) {
    v.fractions.push_back(std::make_pair(fractions[i].first * k , fractions[i].second));
}
v.reduce();
return v;
            }
void CRat::reduce() {
    size_t n = fractions.size();
    for (size_t i = 0; i < n; i++) {
        unsigned int a = abs(fractions[i].first);
        unsigned int b = fractions[i].second;
        while ((a != 0)&& ( b != 0)) {
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
}


CRat& CRat::operator=(const CRat & b){
int n = fractions.size();
for (int i = 0; i < n; i++) {
 fractions[i].first = b.fractions[i].first;
 fractions[i].second = b.fractions[i].second;
}
return *this;
}


 bool CRat :: operator!=(const CRat & b) {
  size_t n = fractions.size();
  if (n == b.fractions.size()) {
   return false;
  }
 int k = 0;
 for (size_t i = 0; i < n; i++) {
   if (fractions[i].first * b.fractions[i].second == fractions[i].second * b.fractions[i].first) {
    k += 1;
   }
 }
if (k == n)
{
 return false;
}
return true;
 }
        
 
