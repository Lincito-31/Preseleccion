#include <iostream>
using namespace std;
int n,q,j=0,u=0,o=0;
int main(){
    cin>>n>>q;
    int s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++){
        while(u<q && j<n){u+=s[j];j++;}
        if(u==q)o++;
        u-=s[i];
    }
    cout<<o;
}