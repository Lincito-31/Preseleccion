#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
string x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> x;
        int conx=0,cony=0;
        string res=x;
        bool S=false,N=false,W=false,E=false;
        bool ap=false,dd=false;
        for(int i=0;i<n;i++){
            switch(x[i]){
                case 'N':
                    if(N){
                        ap=true;
                        res[i]='H';
                        N=false;
                    }else{
                        dd=true;
                        res[i]='R';
                        N=true;
                    }
                    break;
                case 'S':
                    if(S){
                        ap=true;
                        res[i]='H';
                        S=false;
                    }else{
                        dd=true;
                        res[i]='R';
                        S=true;
                    }
                    break;
                case 'W':
                    if(W){
                        dd=true;
                        res[i]='R';
                        W=false;
                    }else{
                        ap=true;
                        res[i]='H';
                        W=true;
                    }
                    break;
                default:
                    if(E){
                        dd=true;
                        res[i]='R';
                        E=false;
                    }else{
                        ap=true;
                        res[i]='H';
                        E=true;
                    }
                    break;
            }
            x[i]=' ';
        }
        if(E==W && S==N && ap && dd){
            cout << res << "\n";
        }else{
            cout << "NO\n";
        }
    }
}