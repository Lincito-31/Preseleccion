/*
ID: simplem2
TASK: crypt1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x,con;
bool used[10];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    cin >> n;
    while(n--){
        cin >> x;
        used[x]=true;
    }
    for(int i=100;i<1000;i++){
        for(int j=10;j<100;j++){
            bool xd=true;
            if(i*j>=10000){
                break;
            }
            int res1=i*j,res2=(j%10)*i,res3=((int)(j/10))*i;
            if(res2>=1000 || res3>=1000){
                continue;
            }
            int a=i,b=j;
            while(a>0 && xd){
                if(!used[a%10]){
                    xd=false;
                    break;
                }
                a/=10;
            }
            while(b>0 && xd){
                if(!used[b%10]){
                    xd=false;
                    break;
                }
                b/=10;
            }
            while(res1>0 && xd){
                if(!used[res1%10]){
                    xd=false;
                    break;
                }
                res1/=10;
            }
            while(res2>0 && xd){
                if(!used[res2%10]){
                    xd=false;
                    break;
                }
                res2/=10;
            }
            while(res3>0 && xd){
                if(!used[res3%10]){
                    xd=false;
                    break;
                }
                res3/=10;
            }
            if(xd){
                con++;
            }
        }
    }
    cout << con << '\n';
}
