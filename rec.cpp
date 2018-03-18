#include<iostream>
#include<algorithm>
using namespace std;
int Rec(int n){
  cout<<"n = "<<n<<endl;
  if(n==0)
      return 1;
  return  n*Rec(n-1);
}
int main(){
    /*cout<<Rec(10)<<endl;
    cout<<Rec(7)<<endl;
    cout<<Rec(8)<<endl;
    cout<<Rec(9)<<endl;
    cout<<Rec(4);
    */

    //array Declarations
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int r[n] = {0},carry = 1;
    for(int i=n-1;i>=0;i--){
        r[i] = a[i]+carry;
        if(r[i]==10){
            carry = 1;
        }
        else
            carry =0;
        r[i] = r[i]%10;
    }
    sort(r,r+n);
    if(carry == 1){
        int r[n+1] = {1,0};
        for(int i=0;i<n+1;i++)
        cout<<r[i];
    }
    else{
        for(int i=0;i<n;i++)
        cout<<r[i];
    }
}
