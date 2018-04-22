//
// Created by Shlomi and Alon
//

#ifndef UNTITLED2_CIRCULARINT_HPP
#define UNTITLED2_CIRCULARINT_HPP
#include <iostream>
using namespace std;
class CircularInt {
    private:
        //int begin,end;
    public:
        int begin,end,currnt; //  to add cycle=end-begin+1?
        CircularInt (int a,int b);
        CircularInt operator=(const CircularInt & old);
        ~CircularInt();
        friend ostream & operator << (ostream &output, const CircularInt a);
        // +
        CircularInt & operator +=(const int cr);
        CircularInt & operator ++(); //postfix
        const CircularInt & operator ++(int);  //prefix
        CircularInt operator + (CircularInt y);
        CircularInt  operator +(int y);
        friend CircularInt operator+(int x,CircularInt y);
        // -
        CircularInt operator-=(int y); //TODO
        CircularInt operator-(int y);
        CircularInt operator-();
        CircularInt operator-(CircularInt y);
        CircularInt operator--(int y);// TODO: cheak if works

        // == and !=
        bool operator ==(const CircularInt& cr2);  //works!!! //do i need  friend?
        bool operator !=(const CircularInt& cr2);   //do i need friend?

        //*
        CircularInt & operator *(const int x);
        CircularInt & operator *=(const int x);

        // /
        CircularInt & operator /(const int x);
        CircularInt & operator /=(const int x);

//        bool operator <(int x);
//        CircularInt & operator -(const CircularInt hour);
//        CircularInt & operator - (int num, CircularInt hour){};
//        CircularInt & operator - (CircularInt hour, CircularInt hour){};
//TODO: need more operators

};

inline CircularInt operator-(int x,CircularInt y){
    int z= y.end-y.begin+1;
    y.currnt= x+(z-y.currnt);
    return y;
}


inline CircularInt operator+(int x,CircularInt y){

    return y+x;

}

#endif //UNTITLED2_CIRCULARINT_HPP
