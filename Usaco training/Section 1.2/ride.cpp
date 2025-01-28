/*
ID: simplem2
TASK: ride
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
char str1[10],str2[10];
int main(){
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    scanf("%s%s",str1,str2);
    string A(str1),B(str2);
    int x=1,y=1;
    for(int i=0;i<A.size();i++){
        x*=A[i]-'A'+1;
        x%=47;
    }
    for(int i=0;i<B.size();i++){
        y*=B[i]-'A'+1;
        y%=47;
    }
    if(x==y){
        printf("GO\n");
    }else{
        printf("STAY\n");
    }
}