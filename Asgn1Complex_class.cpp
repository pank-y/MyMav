//Author : Pankaj Yadav
#include<iostream>
using namespace std;
class Complex{
	int real;
	int img;
	public:
	int GetReal(){				// getter/accessor mem fuc
		return real;
	}
	int GetImg(){	
		return img;	//	 to make code less lengthy
	}
	void SetReal(int r){			// setter/mutator  mem fuction
		real=r;
	}
	void SetImg(int i){
		img=i;
	}
	/*		actually assignment............................not intilization
	Complex(){				// default constructor
		real=0;
		imp=0;
	}
	*Complex(int r,int i){			// parameterised constructor
		real=r;
		img=i;
	}
	*/
	Complex(): real(0),img(0){} //correct way of initiazing--in this will not cause prob if we got const data mem in class
	Complex(int r,int i):real(r),img(i){}
	Complex(const Complex &s): real(s.real),img(s.img){}		// called SHALLOW COPY ...copy constructor
	Complex operator+(const Complex &c){	//  c is alias to passing object of Complex Class
		Complex a;		// result		let's assume a=b+c as an example    a-->result
		a.real=real+c.real;		// b--> b.operator+
		a.img=img+c.img;		// in argument c-->c.real and c.img
		return a;
	}
	Complex operator-(const Complex &c){
		Complex a;
		a.real=real-c.real;
		a.img=img-c.img;
		return a;
	}
	Complex operator*(const Complex &c){
		Complex a;
		a.real=real*c.real;
		a.img=img*c.img;
		return a;
	}
	Complex operator/(const Complex &c){
		Complex a;
		a.real=real/c.real;
		a.img=img/c.img;
		return a;
	}
	const Complex &operator++(){
	       ++real;// pre operator overlaoding 
	       return *this;
	}
	Complex operator++(int){ 		// post increment overloading 
		Complex result(*this);		// cannnot do result = real;  as real is int and result is Complex type
		real++;			// ++ real can be used 
		return result;
	}
	
	
};
int main(){
		Complex c,c1(1,2),c2(10,20);	// initilizing .......Complex c1={1,2} not allowed since can't access directly
//	c.real=c1.GetReal()+c2.GetReal();  we are getting the real values of c1 and c2 but not able to store in c since private 
c.SetReal(c1.GetReal()+c2.GetReal());
c.SetImg(c1.GetImg()+c2.GetImg());
cout<<"c.real="<<c.GetReal()<<endl<<"c.img="<<c.GetImg()<<endl;
Complex d(c);//or Complex d=c...same...here now we making copy of c in d using copy constructor
cout<<"d complex values:    "<<d.GetReal()<<"   "<<d.GetImg()<<endl;

cout<<"now we use overlaoded operator to do basic operationd mutator"<<endl;
Complex e,e1(100,200),e2(10,20);
cout<<"e1(100,200) and e2(10,20) and the basic operations are: "<<endl;
e=e1+e2;	// meaing e=e1.operator+(&e2);
cout<<"Add e1+e2"<<"e.real="<<e.GetReal()<<"e.img="<<e.GetImg()<<endl;

e=e1-e2;
cout<<"Substract e1-e2"<<"e.real="<<e.GetReal()<<"e.img="<<e.GetImg()<<endl;
e=e1*e2;
cout<<"Multtiply e1*e2"<<"e.real="<<e.GetReal()<<"e.img="<<e.GetImg()<<endl;
e=e1/e2;
cout<<"Divide e1/e2"<<"e.real="<<e.GetReal()<<"e.img="<<e.GetImg()<<endl;
++e;
cout<<"Pre-Incemented e(10,10) result is Real part= "<<endl<<e.GetReal()<<" and Img part = "<<e.GetReal()<<endl;
Complex f=e++;
cout<<"f=e++ doing post increment Value of f is ="<<f.GetReal()<<" and "<<f.GetImg()<<endl;
cout<<"Now Value of e is = "<<"e.real="<<e.GetReal()<<" and e.img="<<e.GetImg()<<endl;
return 0;
}
