#include<iostream>
using namespace std;

class Convert{
    protected:
    double val1;
    double val2;

    public:
    Convert(double initial=0): val1(initial),val2(0) {}

    double getinit() const{
        return val1;
    }

    double getconv() const{
        return val2;
    }

    virtual void compute() = 0;

    virtual ~Convert() {}
};

class CelToFah : public Convert{
    public:
    CelToFah(double celsius) : Convert(celsius) {}
        void compute() override{
                val2 = (val1 * 9.0/5.0) + 32;
        }
};

class KilometersToMiles : public Convert {
public:
    KilometersToMiles(double kilometers) : Convert(kilometers) {}

    void compute() override {
        val2 = val1 * 0.621371;
    }
};

int main(){
    double value;

    cout<<"enter the temp in celsius: ";
    cin>>value;
    cout<<endl;
    CelToFah tempconvert(value);
    tempconvert.compute();
    cout<<"Temperature in fahrenheit: "<<tempconvert.getconv()<<endl;

    cout<<"Enter the distance in km: ";
    cin>>value;
    cout<<endl;
    KilometersToMiles distconvert(value);
    distconvert.compute();
    cout<<"Distance in miles is: "<<distconvert.getconv()<<endl;

    return 0;
}