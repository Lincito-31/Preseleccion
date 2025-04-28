#include <bits/stdc++.h>
using namespace std;
int t,n,mile,juice,a;
int main(){
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case " << i << ": ";
        cin >> n;
        mile=juice=0;
        while(n--){
            cin >> a;
            mile+=10*(int)(1+a/30);
            juice+=15*(int)(1+a/60);
        }
        if(mile<juice){
            cout << "Mile " << mile << '\n';
        }else if(mile==juice){
            cout << "Mile Juice " << mile << '\n';
        }else{
            cout << "Juice " << juice << '\n';
        }
    }
}