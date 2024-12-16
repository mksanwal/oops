#include<iostream>
#include<cmath>
using namespace std;

class Quadratic{
    private:
    double a,b,c;

    public: 
    Quadratic(): a(0), b(0), c(0) {}

    Quadratic(double a, double b, double c): a(a), b(b), c(c) {}

    Quadratic operator + (const Quadratic& other){
        return Quadratic( a + other.a, b+other.b, c+other.c);
    }
    
    friend istream& operator >> (istream& in, Quadratic& q){
        cout<<"enter coefficients a,b and c: ";
        in>>q.a>>q.b>>q.c;
        cout<<endl;
        return in;
    }

    friend ostream& operator << (ostream&  out, const Quadratic& q){
        out<<q.a<<"x^2";
        if(q.b>=0) out<<"+";
        out<<q.b<<"x";
        if(q.c>=0) out<<"+";
        out<<q.c;
        out<<endl;
        return out;
    }  

    double eval(double x){
        return (a*x*x) + (b*x) + c;
    }

    void computeSolution(){
        if(a==0){
            if(b==0){
                cout<<(c==0 ? "infinite solutions": "No solution")<<endl;
            } else{
                cout<<"linear solution: "<<-c/b<<endl;
            }
            return;
        }

        double discriminant = (b*b) - (4*a*c);
        if(discriminant>0){
            double root1 = (-b + sqrt(discriminant)/ (2*a));
            double root2 = (-b - sqrt(discriminant)/(2*a));
            cout<<"Solutions are "<<"x1: "<<root1<<"and x2: "<<root2<<endl;
        } else if(discriminant==0){
            double root = -b/(2*a);
            cout<<"One real solution: x= "<<root<<endl;
        } else{
            double realpart= -b/(2*a);
            double imagpart = sqrt(-discriminant)/(2*a);
            cout<<"x1= "<<realpart<<"+"<<imagpart<<" i, x2= "<<realpart<<" - "<<imagpart<<"i"<<endl;
        }

    }

};

int main(){
    Quadratic q1,q2;

      cout << "Enter the first polynomial:\n";
      cin >> q1;
      cout << "Enter the second polynomial:\n";
      cin >> q2;

    cout << "\nFirst Polynomial: " << q1 << endl;
    cout << "Second Polynomial: " << q2 << endl;


    Quadratic sum = q1 + q2;
    cout << "\nSum of the polynomials: " << sum << endl;

    double x = 2;
    cout << "\nValue of the first polynomial at x = " << x << ": " << q1.eval(x) << endl;

        cout << "\nSolutions of the first polynomial:\n";
        q1.computeSolution();

        return 0;


}