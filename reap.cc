#include<iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> A;
    A.push_back(3);
    A.push_back(4);
    A.push_back(1);
    A.push_back(1);
    A.push_back(2);
    int i,xor1=0,xor2=1;
    cout<<"xor1:\n";
    for(i=0;i<A.size();i++)
    {
        cout<<xor1<<" ";
        xor1^=A[i];
        cout<<A[i]<<" "<<xor1<<endl;
    }
    int n=A.size();
    cout<<"xor2:\n";
    for(i=2;i<=(n-1);i++)
    {
        cout<<xor2<<" ";
        xor2^=i;
        cout<<A[i]<<" "<<xor2<<endl;
    }

    int repeat;
    repeat=xor1^xor2;
    cout<<"repeat = "<<repeat;
}
