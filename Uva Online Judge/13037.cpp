#include <bits/stdc++.h>
using namespace std;
int t,L,R,S,a;
int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case #%d:\n",i);
        scanf("%d%d%d",&L,&R,&S);
        map<int,int> LL,RR,SS;
        while(L--){
            scanf("%d",&a);
            LL[a]++;
        }
        while(R--){
            scanf("%d",&a);
            RR[a]++;
        }
        while(S--){
            scanf("%d",&a);
            SS[a]++;
        }
        int con1=0,con2=0,con3=0,con4=0,con5=0,con6=0;
        for(auto u:LL){
            if(u.second>0){
                if(RR[u.first]==0 && SS[u.first]==0){
                    con1++;
                }else if(RR[u.first]==0){
                    con4++;
                }else if(SS[u.first]==0){
                    con6++;
                }
            }
        }
        for(auto u:RR){
            if(u.second>0){
                if(LL[u.first]==0 && SS[u.first]==0){
                    con3++;
                }else if(LL[u.first]==0){
                    con2++;
                }else if(SS[u.first]==0){
                    con6++;
                }
            }
        }
        for(auto u:SS){
            if(u.second>0){
                if(RR[u.first]==0 && LL[u.first]==0){
                    con5++;
                }else if(RR[u.first]==0){
                    con4++;
                }else if(LL[u.first]==0){
                    con2++;
                }
            }
        }
        con2/=2;
        con4/=2;
        con6/=2;
        printf("%d %d\n%d %d\n%d %d\n",con1,con2,con3,con4,con5,con6);
    }
}