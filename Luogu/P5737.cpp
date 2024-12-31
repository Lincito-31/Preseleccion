#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    int con=0;
    for(int i=n;i<=m;i++){
        if(i%400==0){
            con++;
        }else if(i%100==0){
            continue;
        }else if(i%4==0){
            con++;
        }
    }
    printf("%d\n",con);
    for(int i=n;i<=m;i++){
        if(i%400==0){
            printf("%d ",i);
        }else if(i%100==0){
            continue;
        }else if(i%4==0){
            printf("%d ",i);
        }
    }
}