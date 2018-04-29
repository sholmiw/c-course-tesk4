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
    // +=
    CircularInt & operator +=(int hour);
    CircularInt& operator +=(CircularInt cr);
    friend CircularInt& operator +=(int a, CircularInt& cr);
    // ++
    CircularInt  operator ++();
    const CircularInt & operator ++(int);
    // -
    friend CircularInt operator-(int x,CircularInt y);
    CircularInt operator-(int y);
    CircularInt operator-(CircularInt y);
    // +
    CircularInt  operator +(CircularInt y);
    CircularInt  operator +(int y);
    friend CircularInt operator+(int x,CircularInt y);
    // ==
    bool operator ==(const CircularInt& cr2);
    bool operator ==(int x);
    friend bool operator ==(int x, CircularInt& cr2);
    // !=
    bool operator !=(const CircularInt& cr2);
    friend bool operator !=(int x, CircularInt& cr2);
    bool operator !=(int x);


    // -=
    CircularInt& operator-=(CircularInt y);
    CircularInt& operator-=(int y);
    // --
    CircularInt  operator --();
    CircularInt & operator --(int);

    // *=
    friend CircularInt operator *=(const int x, CircularInt cr2);

    // *
    CircularInt  operator *(int x);
    CircularInt  operator *(CircularInt cr2);
    friend CircularInt  operator *(int x, CircularInt& cr2);
    // >
    bool operator > (CircularInt &b);
    friend bool operator > (int const x,CircularInt const &a);
    bool operator > (int const x);
    // <
    bool operator < (CircularInt const &b);
    bool operator < (int const x);
    friend bool operator < (int const x,CircularInt const &a);
    // <=
    bool operator <= (CircularInt const &b);
    bool operator <= (int const x);
    friend bool operator <= (int const x,CircularInt const &a);
    // >=
    bool operator >=(CircularInt const &b);
    bool operator >= (int const x);
    friend bool operator >= (int const x,CircularInt const &a);


    // << and  >>
    friend istream& operator>> (istream& is, CircularInt& c);
    friend ostream& operator<< (ostream& os, const CircularInt& c);
    // =
    CircularInt operator=(const CircularInt & old);
    CircularInt& operator=(int y);

//with the help of https://github.com/JosephGolubchik/Cpp_Ex5/blob/master/CircularInt.cpp
    CircularInt& operator*= (double mult);
    CircularInt& operator*= (CircularInt& circ);
    void getInRange() ;

    // /
    //friend CircularInt operator /(int x,CircularInt& cr2);
    // /=
//    CircularInt & operator /=( int x);
//    double  operator / (int divi);
//    double operator / (CircularInt& circ);
//   CircularInt operator / (CircularInt& cr2);
//    CircularInt operator /(const int x);
    friend CircularInt operator/ (CircularInt c1, CircularInt const& c2);
    friend CircularInt operator/ (CircularInt c, int const& num);
    friend CircularInt operator/ (int const& num, CircularInt c);
    friend CircularInt operator/= (CircularInt& c1, CircularInt const& c2);
    friend CircularInt operator/= (CircularInt& c, int const& num);

};



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



#endif //UNTITLED2_CIRCULARINT_HPP
////



//
//
//CircularInt& CircularInt::operator/= (int divi){
//    if(currnt % divi != 0){
//        string message = "There is no number x in {" + to_string(begin) + ","
//                         + to_string(end) +"} such that x*" + to_string(divi) + "=" + to_string(currnt);
//        throw message;
//    }
//    else{
//        currnt = currnt / divi;
//        this->getInRange();
//        return *this;
//    }
//}
//
//double CircularInt::operator/ (CircularInt& circ){
//
//    if(currnt % circ.currnt != 0){
//        string message = "There is no number x in {" + to_string(begin) + ","
//                         + to_string(end) +"} such that x*" + to_string(circ.currnt) + "=" + to_string(currnt);
//        throw message;
//    }
//    else{
//        CircularInt temp {begin, end, currnt};
//        int ans = currnt / circ.currnt;
//        temp.currnt=ans;
//        temp.getInRange();
//        ans = temp.currnt;
//        return ans;
//    }
//}
//double CircularInt::operator/ (int divi){
//    if(currnt % divi != 0){
//        string message = "There is no number x in {" + to_string(begin) + ","
//                         + to_string(end) +"} such that x*" + to_string(divi) + "=" + to_string(currnt);
//        throw message;
//    }
//    else{
//        CircularInt temp {begin, end, currnt};
//        int ans = currnt / divi;
//        temp.currnt=ans;
//        temp.getInRange();
//        ans = temp.currnt;
//        return ans;
//    }
//}
//int operator/ (int base, CircularInt& circ){
//    CircularInt temp {circ.begin, circ.end, circ.currnt};
//    int ans = base / (circ.currnt);
//    temp.currnt=ans;
//    temp.getInRange();
//    ans = temp.currnt;
//    return ans;
//}
//
