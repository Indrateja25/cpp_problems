#include<iostream>
using namespace std;
int calc_cyc_len(int n,int *a){
    int count = 1;
    cout<<"n = "<<n<<endl;
    while(n>1){
            cout<<n<<endl;
            if(a[n] != 0)
              return a[n];
            if(n%2)
                n = 3*n+1;
            else
                n /= 2;
            count++;
    }
    return count;
}
int main(){
    int n,top=0;
    cin>>n;
    int a[n+1] = {0};
    for(int i = 1;i<=n;i++){
        a[i] = calc_cyc_len(i,a);
        cout<<"count("<<i<<") = "<<a[i]<<endl;
    }
}
