#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t;
string S,T;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int j=1;j<=t;j++){
        int con=0;
        cin >> S >> T;
        int S1=0,T1=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='1'){
                S1++;
            }
            if(T[i]=='1'){
                T1++;
            }
        }
        if(S1>T1){
            cout << "Case " << j << ": " << -1 << '\n';
        }else{
            for(int i=0;i<S.size() && S1<T1;i++){
                if(S[i]=='?' && T[i]=='1'){
                    S[i]='1';
                    S1++;
                    con++;
                }
            }
            for(int i=0;i<S.size() && S1<T1;i++){
                if(S[i]=='?'){
                    S[i]='1';
                    S1++;
                    con++;
                }
            }
            for(int i=0;i<S.size();i++){
                if(S[i]=='?'){
                    S[i]='0';
                    con++;
                }
            }
            for(int i=0;i<S.size() && S1<T1;i++){
                if(S[i]=='0' && T[i]=='1'){
                    S[i]='1';
                    S1++;
                    con++;
                }
            }
            for(int i=0;i<S.size() && S1<T1;i++){
                if(S[i]=='0'){
                    S[i]='1';
                    S1++;
                    con++;
                }
            }
            int nue=0;
            for(int i=0;i<S.size();i++){
                if(S[i]!=T[i]){
                    nue++;
                }
            }
            con+=nue/2;
            cout << "Case " << j << ": " << con << '\n';
        }
    }
}