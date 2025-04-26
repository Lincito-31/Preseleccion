#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,space[100],weight[2000],used[100],reused[2000],x,sobra;
queue<int> entrance;
ll sum=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> space[i];
    }
    for(int i=0;i<m;i++){
        cin >> weight[i];
    }
    sobra=n;
    m*=2;
    while(m--){
        cin >> x;
        if(x>0){
            entrance.push(x-1);
        }else{
            sobra++;
            used[reused[-x-1]]=false;
        }
        while(!entrance.empty()&&sobra){
            x=entrance.front();
            entrance.pop();
            for(int i=0;i<n;i++){
                if(!used[i]){
                    used[i]=true;
                    reused[x]=i;
                    sum+=weight[x]*space[i];
                    sobra--;
                    break;
                }
            }
        }
    }
    cout << sum;
}