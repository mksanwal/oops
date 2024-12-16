#include<bits/stdc++.h>
using namespace std;

string addbinary(string b1, string b2){
    stack<int> s1,s2,resultst;
    for(char &i : b1) s1.push(i-'0');
    for(char &i : b2) s2.push(i-'0');

    int carry=0;
    while(!s1.empty() || !s2.empty() || carry!=0){
        int sum = carry;

        if(!s1.empty()){
            sum+=s1.top();
            s1.pop();
        }

        if(!s2.empty()){
            sum+=s2.top();
            s2.pop();
        }

        resultst.push(sum%2);
        carry = sum/2;
    }

    string result;
    while(!resultst.empty()){
        result += (resultst.top() + '0');
        resultst.pop();
    }
    return result;


}

int main(){
    string binary1,binary2;
    cout<<"Enter first binary number: ";
    cin>>binary1;
    cout<<endl;
    cout<<"Enter second binary number: ";
    cin>>binary2;
    cout<<endl;
    cout<<"Sum of the two binary numbers is: "<<addbinary(binary1,binary2)<<endl;
    

}