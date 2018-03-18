#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int a[n],k;
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
     cout<<"Enter k: ";
     cin>>k;

    int temp;
    for(int i=0;i<n-k;i++)
        a[i+k] = a[i];
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    for(int i=n-k+1;i<n;i++)
        a[i-k-1] = a[i];
}
