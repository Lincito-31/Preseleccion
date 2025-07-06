#include <bits/stdc++.h>
using namespace std;
int maxi[3],cant[3],now;
int main(){
    ifstream in("mixmilk.in");
    ofstream out("mixmilk.out");
    for(int i=0;i<3;i++){
        in >> maxi[i] >> cant[i];
    }
    for(int i=0;i<100;i++,now++){
        now%=3;
        int x=min(cant[now],maxi[(now+1)%3]-cant[(now+1)%3]);
        cant[now]-=x;
        cant[(now+1)%3]+=x;
    }
    for(int i=0;i<3;i++){
        out << cant[i] << '\n';
    }
}