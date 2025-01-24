#include <bits/stdc++.h>
using namespace std;
int a;
vector<bool> criba(65536,false);
vector<int> primos;
int main(){
    criba[0]=criba[1]=true;
    for(int i=2;i*i<65536;i++){
        if(!criba[i]){
            for(int j=i*i;j<65536;j+=i){
                criba[j]=true;
            }
        }
    }
    for(int i=0;i<65536;i++){
        if(!criba[i]){
            primos.push_back(i);
        }
    }
    //6542
    while(scanf("%d",&a)!=EOF){
        if(a<0){
            printf("-1 ");
            a*=-1;
        }
        int con=0;
        for(int i=0;i<6542;i++){
            while(a%primos[i]==0){
                con++;
                a/=primos[i];
            }
            if(con==0){
                continue;
            }
            if(con==1){
                printf("%d ",primos[i]);
            }else{
                printf("%d^%d ",primos[i],con);
            }
            con=0;
        }
        if(a>1){
            printf("%d ",a);
        }
        printf("\n");
    }
}