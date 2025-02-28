#include <bits/stdc++.h>
using namespace std;
bitset<100000001> criba;
bitset<100000001> res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //usando congruencia tenemos que
    //n=12m+6 || n=12m+10
    criba[1]=criba[0]=1;
    for(int i=4;i<=100000000;i+=2){
        criba[i]=1;
    }
    for(int i=3;i*i<=100000000;i+=2){
        if(!criba[i]){
            for(int j=i*i;j<=100000000;j+=i){
                criba[j]=1;
            }
        }
    }
    long long suma=0;
    for(int i=0;i<100000000;i++){
        int x=12*i+6;
        bool xd=true;
        for(int j=1;j*j<=x;j++){
            if(x%j==0){
                if(criba[j+x/j]){
                    xd=false;
                    break;
                }
            }
        }
        if(xd){
            suma+=x;
        }
        x+=4;
        xd=true;
        for(int j=1;j*j<=x;j++){
            if(x%j==0){
                if(criba[j+x/j]){
                    xd=false;
                    break;
                }
            }
        }
        if(xd){
            suma+=x;
        }
    }
    //1739023853134
    //sumando 1 y 2 seria
    cout << suma+3;
    //1739023853137
}
