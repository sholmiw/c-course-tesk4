//
// Created by Shlomi and Alon
//

#ifndef UNTITLED2_CIRCULARINT_HPP
#define UNTITLED2_CIRCULARINT_HPP
#include <iostream>
using namespace std;
# include <iostream>
#include <string>
#pragma once

class CircularInt {
public:
    int begin,end,currnt;


    CircularInt (int a,int b): begin(a),end(b),currnt(a){}
    CircularInt (int a,int b,int c);

    CircularInt(int begin);

    CircularInt & operator +=(int hour);
    CircularInt  operator ++();
    friend CircularInt operator-(int x,CircularInt y);
    CircularInt operator-(int y);
    CircularInt operator-(CircularInt y);
    CircularInt  operator +(CircularInt y);
    CircularInt  operator +(int y);
    friend CircularInt operator+(int x,CircularInt y);
    const CircularInt & operator ++(int);
    bool operator ==(const CircularInt& cr2);
    bool operator !=(const CircularInt& cr2);
    //  CircularInt & operator *=(double x);
    CircularInt& operator +=(CircularInt cr);
    friend CircularInt& operator +=(int a, CircularInt& cr);
    CircularInt& operator-=(CircularInt y);
    CircularInt& operator-=(int y);
    CircularInt  operator --();
    CircularInt & operator --(int);
    bool operator ==(int x);
    friend bool operator !=(int x, CircularInt& cr2);
    friend bool operator ==(int x, CircularInt& cr2);
    bool operator !=(int x);
    friend CircularInt operator *=(const int x, CircularInt cr2);
    // CircularInt & operator *=(CircularInt x);
    CircularInt  operator *(int x);
    CircularInt  operator *(CircularInt cr2);
    friend CircularInt  operator *(int x, CircularInt& cr2);
    bool operator > (CircularInt &b);
    friend bool operator > (int const x,CircularInt const &a);
    bool operator > (int const x);
    bool operator < (CircularInt const &b);
    bool operator < (int const x);
    friend bool operator < (int const x,CircularInt const &a);
    bool operator <= (CircularInt const &b);
    bool operator <= (int const x);
    friend bool operator <= (int const x,CircularInt const &a);
    bool operator >=(CircularInt const &b);
    bool operator >= (int const x);
    friend bool operator >= (int const x,CircularInt const &a);
//    CircularInt operator /(CircularInt& cr2);
//    CircularInt operator /(const int x);
//   friend CircularInt operator /(int x,CircularInt& cr2);
    CircularInt & operator /=( int x);
    friend std::ostream& operator<< (std::ostream& os, const CircularInt& c);
    friend std::istream& operator>> (std::istream& is, CircularInt& c);
    CircularInt operator=(const CircularInt & old);
    CircularInt& operator=(int y);
//with the help of https://github.com/JosephGolubchik/Cpp_Ex5/blob/master/CircularInt.cpp
    CircularInt& operator*= (double mult);
    CircularInt& operator*= (CircularInt& circ);
    void getInRange();


    double operator / (int divi);

    double operator / (CircularInt& circ);









};
//inline int operator / (int base, CircularInt& cir1){
//    CircularInt temp {cir1.begin, cir1.end, cir1.currnt};
//    int ans = base / (cir1.currnt);
//    temp.currnt=ans;
//    temp.getInRange();
//    ans = temp.currnt;
//    return ans;
//}


inline std::istream& operator>> (std::istream& is, CircularInt& c){
    int temp;
    is >> temp;
    c.currnt = temp;
    return is;
}

inline std::ostream& operator<< (std::ostream& os, const CircularInt& c){
    return os << c.currnt;
}

inline CircularInt operator-(int x,CircularInt y){
    int newt= x-y.currnt;
    if (newt<y.begin || newt>y.end){
        int z= y.end-y.begin+1;
        y.currnt= x+(z-y.currnt);
        return y;}
    else {
        CircularInt hour2(y.begin,y.end);
        hour2.currnt=newt;
        return hour2;
    }

}

inline CircularInt operator+(int x,CircularInt y){

    return y+x;

}

inline CircularInt& operator +=(int a, CircularInt& cr){
    cr+=a;
    return cr;

}

inline bool operator !=(int  x,CircularInt& cr2){
    if (x==cr2.currnt)
        return false;
    return true;
}
inline bool operator ==(int x, CircularInt& cr2){

    return cr2==x;
}


inline CircularInt operator *=(const int x, CircularInt cr2){
    cr2*=x;
    return cr2;
}

inline CircularInt  operator *(int x, CircularInt& cr2){
    cr2=x*=cr2;
    return cr2;

}

inline bool operator > (int const x,CircularInt const &a){
    if (x>a.currnt) return true;
    return false;
}

inline bool operator < (int const x,CircularInt const &a){
    if (x<a.currnt) return true;
    return false;
}

inline bool operator <= (int const x,CircularInt const &a){
    if (x<=a.currnt) return true;
    return false;
}

inline bool operator >= (int const x,CircularInt const &a){
    if (x>=a.currnt) return true;
    return false;
}

inline CircularInt operator /(int x,CircularInt& cr2){
    int z=cr2.currnt;
    cr2.currnt=x;
    return cr2/z;

}

#endif //UNTITLED2_CIRCULARINT_HPP
