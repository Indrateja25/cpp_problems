#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int Size;
    cin>>Size;
    vector <int> v(Size);

    for(int i=0;i<Size;i++)
        cin>>v[i];
    cout<<"Vector is : ";
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    int temp,c=1;
    while(!v.empty()){
      rotate(v.begin(),v.begin()+v.size()-1,v.end());
      if(v.size() > c)
         v.erase(v.end()-1,v.end());
       else
         v.erase(v.begin(),v.begin()+1);
      cout<<endl<<"after rot no "<<c<<": ";
      for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
        temp = v[0];
    }
    cout<<temp<<endl;
}
