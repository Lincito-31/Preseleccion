#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> a >> b,a||b){
        if(min(a,b)==0){
            cout << 0;
        }else if(min(a,b)>=3){
            cout << (int)((b+1)/2)*(int)((a+1)/2)+(int)(b/2)*(int)(a/2);
        }else if(min(a,b)==1){
            cout << max(a,b);
        }else{
            if(max(a,b)%4==1){
                cout << max(a,b)+1;
            }else{
                if(max(a,b)%4==0){
                    cout << max(a,b);
                }else{
                    cout << max(a,b)+4-max(a,b)%4;
                }
            }
        }
        cout << " knights may be placed on a "<< a <<" row " << b << " column board.\n";
    }
}