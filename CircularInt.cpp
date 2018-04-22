//
// Created by Shlomi and Alon
//

#include "CircularInt.hpp"

CircularInt::CircularInt (int a,int b){
    begin=a;
    end=b;
    currnt=begin;
}
CircularInt::~CircularInt(){};
std::ostream & operator << (std::ostream &output,CircularInt a){
    return output << a.currnt;
}
CircularInt& CircularInt:: operator +=(int hour){
    int newtime =currnt+hour;
    int num=end-begin+1;
    while (newtime>end)
        newtime=newtime-num;
    currnt=newtime;
    return *this;
}
CircularInt& CircularInt:: operator ++(){
    this->currnt+=1;
    return *this;
}

const CircularInt & CircularInt::operator ++(int){  //or should it be int?
    CircularInt cpy(*this);
    this->currnt+=1;
    return cpy;
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
CircularInt & CircularInt::operator *(const int x){
    currnt=(currnt*x)%end;
    return *this;
}


CircularInt & CircularInt::operator *=(const int x){
    (*this)=(*this)*x;
    return *this;
}

CircularInt & CircularInt::operator /(const int x){
    double d=(double)(currnt)/x;
    if (d !=int(d)){
        throw string ("There is no number x in {"+ to_string(begin) + "," +to_string(end) + "} such that x*" + to_string(x) + "=" + to_string(currnt));
    }
    CircularInt ans{begin,end};
    ans.currnt=(int)d;
    return ans;
}
CircularInt & CircularInt::operator /=(const int x){
    (*this)=(*this)/x;
    return *this;
}


CircularInt CircularInt::operator+(CircularInt y){
    CircularInt hour2(y.begin,y.end);
    hour2.currnt=currnt;
    hour2+=y.currnt;
    return hour2;

}

CircularInt CircularInt::operator-(int y){
    CircularInt hour2(begin,end);
    int z=end-begin+1;
    hour2.currnt=currnt+(z-y);
    return hour2;
}
CircularInt CircularInt::operator-(){
    CircularInt ans(begin,end);
    int holder= (end-currnt)-begin;
    ans+=holder;
    return ans;
}
CircularInt CircularInt::operator +(int y){
    CircularInt hour2(begin,end);
    hour2.currnt=currnt;
    hour2+=y;
    return hour2;
}

CircularInt CircularInt::operator-(CircularInt y){
    CircularInt hour2(begin,end);
    hour2.currnt=currnt;
    hour2=hour2-y.currnt;
    return hour2;

}
CircularInt CircularInt::operator--(int ){
    this->currnt-=1;
    return *this;
}
CircularInt CircularInt::operator-=(const int x){
    if(x>0){
        int diffrance=currnt-x;
        currnt=end- (diffrance%end);
        return *this;
    }else return (*this)+= (x*-1);
}
//TODO: implement this: (and more operator)
CircularInt CircularInt::operator=(const CircularInt & old){
    begin=old.begin;
    end=old.end;
    currnt=old.currnt;
    return *this;
}