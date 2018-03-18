#include<iostream>
using namespace std;
int sum(int *a,int i,int j){
    int c =0;
    for(int k=i;k<=j;k++)
        c += a[k];
    return c;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int start=0,i=1,End = 1;
    while(i<n){
        cout<<"start = "<<start<<" i = "<<i<<" sum = "<<sum(a,start,i)<<endl;
        if(sum(a,start,i)<0){
            if(a[i] > 0){
                start = i;
                i++;
            }
            else {
                start = i+1;
                i = start+1;
            }
        }
        else{
            End = i;
            i++;
        }
    }
    cout<<"start = "<<start<<" End = "<<End;
}
