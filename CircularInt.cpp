# include <iostream>
#include "CircularInt.hpp"



// +=
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
//++
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

// +
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
// ==  
bool CircularInt::operator ==(const CircularInt &cr2){
    if ((begin==cr2.begin)&&(end==cr2.end)&&(currnt==cr2.currnt))
        return true;
    return false;
}
bool CircularInt:: operator ==(int const x){
    if (x==this->currnt)
        return true;
    return false;
}
// !=
bool CircularInt::operator !=(const CircularInt &cr2){
    if ((begin==cr2.begin)&&(end==cr2.end)&&(currnt==cr2.currnt))
        return false;
    return true;
}
bool CircularInt::operator !=(int x){
     return x!=*this;
}
// *=
CircularInt & CircularInt::operator *=(const int x){
    int z=currnt;
    for(int i=1;i<x;i++)
  	*this+=z;
    return *this;
}

// -=
CircularInt& CircularInt::operator-=(int y){
       *this=*this-y;
      // CircularInt hour2= *this-y
       return *this;
}
CircularInt&  CircularInt::operator-=(CircularInt y){
        *this=*this-=y.currnt;
        return *this;
}
// --    
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
//  *
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
   
CircularInt & CircularInt::operator *=(CircularInt x){
       *this*=x.currnt;
	return*this;
}
// >  
   bool CircularInt::operator > (CircularInt &b){
    if (currnt>b.currnt) return true;
    return false;
   }
   
   bool CircularInt::operator > (int const x){
    if (currnt>x) return true;
    return false;
}
// <
bool CircularInt::operator < (CircularInt const &b){
    if (currnt<b.currnt) return true;
    return false;
}

bool CircularInt::operator < (int const x){
    if (currnt<x) return true;
    return false;
}
// <=
bool CircularInt::operator <= (CircularInt const &b){
    if (currnt<=b.currnt) return true;
    return false;
}

bool CircularInt::operator <= (int const x) {
    if (currnt <= x) return true;
    return false;
}
// >=
bool CircularInt::operator >=(CircularInt const &b){
    if (currnt>=b.currnt) return true;
    return false;
}
bool CircularInt::operator >= (int const x){
    if (currnt>=x) return true;
    return false;
}
// /
CircularInt CircularInt::operator /(CircularInt& cr2){
    double d=(double)(currnt)/cr2.currnt;
    CircularInt ans{begin,end};
    ans.currnt=(int)d;
    return ans;
}
CircularInt CircularInt::operator /(const int x){
    double d=(double)(currnt)/x;
    CircularInt ans{begin,end};
    ans.currnt=(int)d;
    return ans;
}
// /=
CircularInt & CircularInt::operator /=(const int x){
    (*this)=(*this)/x;
    return *this;
}
// =
CircularInt & CircularInt::operator = (int x){
	currnt=x;
	this->setOnRange();
	return *this; 

}

CircularInt CircularInt::operator=(const CircularInt & cr2){
    begin=cr2.begin;
    end=cr2.end;
    currnt=cr2.currnt;
    return *this;
}  
  

// >>
std:: istream & operator >> (std::istream &is, CircularInt a){
    int tmp;
    is>>tmp;
    if(tmp>a.end || tmp<a.begin){
        throw std::invalid_argument("value not in range\n");
    }
    a.currnt=tmp;
    return is;
}      

// help function
void CircularInt::setOnRange(){
	while (this->currnt <begin || this->currnt>end){
		if(this->currnt>end){
			this->currnt-= (end-begin+1);
		}else if(this->currnt <begin){
			this->currnt-= (end-begin+1);
		}
	} 
}









