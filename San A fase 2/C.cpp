#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
ll X,Y,Z;
int E;
int main(){
    scanf("%lld %lld %lld %d",&X,&Y,&Z,&E);
    ll tiemp=0;
    bool xd;
    vll use(3,0);
    vll nums(E);
    for(int i=0;i<E;i++){
        scanf("%lld",&nums[i]);
    }
    for(int i=0;i<E;i++){
        xd=false;
        for(int j=0;j<10;j++){
            if(use[0]==0){
                if(X>=nums[i]){
                    use[0]=nums[i];
                    break;
                }
            }
            if(use[1]==0){
                if(Y>=nums[i]){
                    use[1]=nums[i];
                    break;
                }
            }
            if(use[2]==0){
                if(Z>=nums[i]){
                    use[2]=nums[i];
                    break;
                }
            }
            ll ayu=1e18;
            if(use[0]>0){
                ayu=min(ayu,use[0]);
            }
            if(use[1]>0){
                ayu=min(ayu,use[1]);
            }
            if(use[2]>0){
                ayu=min(ayu,use[2]);
            }
            if(ayu==1e18){
                xd=true;
                break;
            }
            if(use[0]>0){
                X-=ayu;
                use[0]-=ayu;
            }
            if(use[1]>0){
                Y-=ayu;
                use[1]-=ayu;
            }
            if(use[2]>0){
                Z-=ayu;
                use[2]-=ayu;
            }
            tiemp+=ayu;
        }
        if(xd){
            break;
        }
    }
    if(!xd){
        printf("%lld",tiemp);
    }else{
        printf("-1");
    }
}