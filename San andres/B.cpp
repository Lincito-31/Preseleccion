#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int t,a;
vector<bool> criba(1000,true);
vector<int> res[1000];
vi calc(int x){
    vi num;
    int now=1;
    for(int i=0;i<40;i++){
        now*=10;
        int y=now/x;
        num.push_back(y);
        now%=x;
    }
    return num;
}
int main(){
    criba[0]=false;
    criba[1]=false;
    for(int i=2;i<1000;i++){
        if(criba[i]){
            for(int j=i+i;j<1000;j+=i){
                criba[j]=false;
            }
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&a);
        if(!criba[a]){
            printf("%d: -1\n",a);
        }else{
            printf("%d: ",a);
            if(!res[a].empty()){
                for(auto u:res[a]){
                    printf("%d ",u);
                }
            }else{
                res[a]=calc(a);
                for(auto u:res[a]){
                    printf("%d ",u);
                }
            }
            printf("\n");
        }
    }
}