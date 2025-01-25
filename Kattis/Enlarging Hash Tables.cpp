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
    while(true){
        scanf("%d",&a);
        if(a==0){
            break;
        }
        int con=0;
        for(int k=2*a+1;true;k++){
            bool xd=true;
            for(int i=0;i<6542;i++){
                if(primos[i]>=k){
                    break;
                }
                if(k%primos[i]==0){
                    xd=false;
                    break;
                }
            }
            if(xd){
                printf("%d ",k);
                break;
            }
        }
        if(a<65536){
            if(criba[a]){
                printf("(%d is not prime)\n",a);
            }else{
                printf("\n");
            }
        }else{
            bool xd=true;
            for(int i=0;i<6542;i++){
                if(a%primos[i]==0){
                    xd=false;
                    break;
                }
            }
            if(!xd){
                printf("(%d is not prime)\n",a);
            }else{
                printf("\n");
            }
        }
    }
}