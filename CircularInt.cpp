//
// Created by Shlomi and Alon

#include "CircularInt.hpp"
using namespace std;

CircularInt& CircularInt:: operator +=(int hour){
    int newtime =currnt+hour;
    int num=end-begin+1;
    while (newtime>end)
        newtime=newtime-num;
    currnt=newtime;
    return *this;
}
CircularInt& CircularInt:: operator +=(CircularInt cr){
    *this+=cr.currnt;
    return *this;
}
CircularInt CircularInt::operator++(){
    CircularInt hour2(begin,end);
    hour2.currnt=currnt;
    *this+=1;
    return hour2;
}
const CircularInt & CircularInt::operator ++(int){  //or should it be int?
    *this+=1;
    return *this;
}
CircularInt CircularInt::operator+(CircularInt y){
    CircularInt hour2(y.begin,y.end);
    hour2.currnt=currnt;
    hour2+=y.currnt;
    return hour2;

}
CircularInt CircularInt::operator +(int y){
    CircularInt hour2(begin,end);
    hour2.currnt=currnt;
    hour2+=y;
    return hour2;
}
// -
CircularInt CircularInt::operator-(int y){
    int newt= currnt-y;
    if (newt<begin || newt>end){
        CircularInt hour2(begin,end);
        int z=end-begin+1;
        hour2.currnt=currnt+(z-y);
        return hour2;}
    else {
        CircularInt hour2(begin,end);
        hour2.currnt=newt;
        return hour2;
    }
}
CircularInt CircularInt::operator-(CircularInt y){
    CircularInt hour2(begin,end);
    hour2.currnt=currnt;
    hour2=hour2-y.currnt;
    return hour2;

}

bool CircularInt:: operator ==(int const x){
    if (x==this->currnt)
        return true;
    return false;
}
bool CircularInt::operator ==(const CircularInt &cr2){
    if ((begin==cr2.begin)&&(end==cr2.end)&&(currnt==cr2.currnt))
        return true;
    return false;
}
bool CircularInt::operator !=(const CircularInt &cr2){
    if ((begin==cr2.begin)&&(end==cr2.end)&&(currnt==cr2.currnt))
        return false;
    return true;
}
bool CircularInt::operator !=(int x){
    return x!=*this;


}
//CircularInt & CircularInt::operator *=(double x){
// int z=currnt;
//  for(int i=1;i<x;i++)
// *this+=z;
//    return *this;
//}

CircularInt& CircularInt::operator-=(int y){
    *this=*this-y;
    // CircularInt hour2= *this-y
    return *this;

}
CircularInt&  CircularInt::operator-=(CircularInt y){
    *this=*this-=y.currnt;
    return *this;

}

CircularInt & CircularInt::operator --(int){
    *this-=1;
    return *this;

}
CircularInt CircularInt::operator --(){
    CircularInt hour2(begin,end);
    hour2.currnt=currnt;
    *this-=1;
    return hour2;

}

CircularInt CircularInt:: operator *(int x){
    CircularInt hour2(begin,end);
    hour2.currnt=currnt;
    hour2*=x;
    return hour2;
}
CircularInt  CircularInt::operator *(CircularInt cr2){
    CircularInt hour2(begin,end);
    hour2.currnt=currnt;
    hour2*=cr2;
    return hour2;
}

//CircularInt & CircularInt::operator *=(CircularInt x){
//    *this*=x.currnt;

//   return*this;
//}

bool CircularInt::operator > (CircularInt &b){
    if (currnt>b.currnt) return true;
    return false;
}
bool CircularInt::operator > (int const x){
    if (currnt>x) return true;
    return false;
}
bool CircularInt::operator < (CircularInt const &b){
    if (currnt<b.currnt) return true;
    return false;
}
bool CircularInt::operator < (int const x){
    if (currnt<x) return true;
    return false;
}
bool CircularInt::operator <= (CircularInt const &b){
    if (currnt<=b.currnt) return true;
    return false;
}
bool CircularInt::operator <= (int const x) {
    if (currnt <= x) return true;
    return false;
}
bool CircularInt::operator >=(CircularInt const &b){
    if (currnt>=b.currnt) return true;
    return false;
}
bool CircularInt::operator >= (int const x){
    if (currnt>=x) return true;
    return false;
}


CircularInt CircularInt::operator=(const CircularInt & old){
    begin=old.begin;
    end=old.end;
    currnt=old.currnt;
    return *this;
}
CircularInt & CircularInt::operator=(int y){
    currnt=y;
    this->getInRange();
    return*this;

}


CircularInt& CircularInt::operator*= (double mult){
    currnt = currnt * mult;
    this->getInRange();
    return *this;
}
CircularInt& CircularInt::operator*= (CircularInt& circ){
    currnt = currnt * circ.currnt;
    this->getInRange();
    return *this;
}
// for *
void CircularInt::getInRange(){
    while(currnt < begin || currnt > end){
        if(currnt > end){
            currnt -= (end-(begin-1));
        }
        else if(currnt < begin){
            currnt += (end-(begin-1));
        }
    }
}
CircularInt::CircularInt(int a,int b, int c){
    begin=a; end=b; currnt=c;
    this->getInRange();
}


//for / from:
//https://github.com/orelshalom/CPP4/blob/master/CircularInt.cpp
CircularInt operator/ (CircularInt cir1, CircularInt const& cir2){
    CircularInt temp {cir1.begin, cir1.end};
    CircularInt temp2 {cir1.begin, cir1.end};
    temp2.currnt = cir1.currnt;
    int c = 0;
    for(int i = cir1.begin; i <= cir1.end; i++){
        temp.currnt = i;
        if(c > 0) break;
        else{
            if((temp*cir2) == cir1){
                temp2.currnt = temp.currnt;
                c++;
            }
        }
    }
    if(c == 0){
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    }
    return temp2;
}
CircularInt operator/= (CircularInt& cir1, CircularInt const& cir2){
    CircularInt temp {cir1.begin, cir1.end};
    int c = 0;
    for(int i = cir1.begin; i <= cir1.end; i++){
        temp.currnt = i;
        if(c > 0) break;
        else{
            if((temp*cir2) == cir1){
                cir1.currnt = temp.currnt;
                c++;
            }
        }
    }
    if(c == 0){
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    }
    return cir1;
}
CircularInt operator/= (CircularInt& cir, int const& num){
    CircularInt temp {cir.begin, cir.end};
    int c = 0;
    for(int i = cir.begin; i <= cir.end; i++){
        temp.currnt = i;
        if(c > 0) break;
        else{
            if((temp*num) == cir){
                cir.currnt = temp.currnt;
                c++;
            }
        }
    }
    if(c == 0){
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    }
    return cir;
}


CircularInt operator/ (CircularInt cir, int const& num){
    CircularInt temp {cir.begin, cir.end};
    CircularInt temp2 {cir.begin, cir.end};
    CircularInt temp3 {cir.begin, cir.end};
    temp2.currnt = cir.currnt;
    temp3.currnt = cir.currnt;
    int c = 0;
    for(int i = cir.begin; i <= cir.end; i++){
        temp.currnt = i;
        if(c > 0) break;
        else{
            if((temp*num) == cir){
                temp2.currnt = temp.currnt;
                c++;
            }
        }
    }
    if(c == 0){
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    }
    temp3.currnt = temp2.currnt;
    return temp3;
}
CircularInt operator/ (int const& num, CircularInt cir){
    CircularInt temp {cir.begin, cir.end};
    CircularInt temp2 {cir.begin, cir.end};
    CircularInt temp3 {cir.begin, cir.end};
    temp2.currnt = cir.currnt;
    int c = 0;
    for(int i = cir.begin; i <= cir.end; i++){
        temp.currnt = i;
        if(c > 0) break;
        else{
            if((temp*cir) == num){
                temp2.currnt = temp.currnt;
                c++;
            }
        }
    }
    if(c == 0){
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    }
    temp3.currnt = temp2.currnt;
    return temp3;
}

istream& operator>> (istream& is, CircularInt& cir){
    int temp;
    is >> temp;
    if(temp>cir.end || temp<cir.begin)
        throw std::invalid_argument( "value not in range\n" );
    cir.currnt = temp;
    return is;
}

ostream& operator<< (ostream& os, const CircularInt& cir){
    return os << cir.currnt;
}
