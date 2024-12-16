#include<iostream>
using namespace std;


class Complex{
    public:
    double real;
    double imag;

    public:
    Complex();
    
    friend istream & operator >> (istream & , Complex &);
    friend ostream & operator << (ostream &, const Complex &);

    Complex operator + (Complex);
    Complex operator * (Complex);

};

Complex:: Complex()
{
    real = 0;
    imag = 0;
}

istream & operator >> (istream & ,  Complex & i){
    cin >> i.real >> i.imag;
    return cin;
}

ostream & operator << (ostream &, const Complex & d){
    cout<< d.real <<  "+" << d.imag << "i" << endl;
    return cout;
}

Complex Complex::operator + (Complex c1){
    Complex temp;
    temp.real = real + c1.real;
    temp.imag = imag + c1.imag;
    return temp;
}

Complex Complex::operator * (Complex c2){
    Complex tmp;
    tmp.real = real * c2.real - imag * c2.imag;
    tmp.imag = real * c2.imag + imag * c2.real;
    return tmp;
}

int main(){
    Complex c1, c2 ,c3, c4;

    cout<<"Enter Real and Imaginary Part of the Complex Number1: ";
    cin>>c1;

    cout<<"Enter real and imaginary parts of complex c2: ";
    cin>>c2;

    cout<<endl;
    
    cout<<"Complex Number 1: "<<c1<<endl;
    cout<<"Complex Number 2: "<<c2<<endl;

    c3 = c1 + c2;
    cout<<" Addition is: "<<c3<<endl;

    c4 = c1*c2;
    cout<<"Multiplication is: "<<c4<<endl;

    return 0;
}


