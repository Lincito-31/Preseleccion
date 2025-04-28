#include <bits/stdc++.h>
using namespace std;
int n,m,c,sum,used,cap[20],maxi,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n >> m >> c,n||m||c){
        cout << "Sequence " << ++con << '\n';
        maxi=sum=used=0;
        for(int i=0;i<n;i++){
            cin >> cap[i];
        }
        while(m--){
            cin >> n;
            if(used&(1<<(--n))){
                used-=(1<<n);
                sum-=cap[n];
            }else{
                sum+=cap[n];
                used+=(1<<n);
                maxi=max(maxi,sum);
            }
        }
        if(maxi>c){
            cout << "Fuse was blown.\n\n";
        }else{
            cout << "Fuse was not blown.\nMaximal power consumption was " << maxi << " amperes.\n\n";
        }
    }
}