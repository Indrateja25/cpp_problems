#include<iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>a) {
    int carry = 1;
    for(int i=a.size()-1 ;i>=0;i--){
        a[i] += carry;
        if(a[i] == 10){
            a[i] = 0;
            carry = 1;
        }
        else
            carry = 0;
    }
    if(!carry)
        return a;
    vector<int>v;
    v[0] = 1;
    for(int i=0;i<a.size();i++)
          v[i+1] = 0;
    return v;
}

int main(){
   vector<int>a;
   for(int i=0;i<a.size();i++)
    cout<<a[i];
  for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
  cout<<endl;
    a = plusOne(a);
  for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
}
