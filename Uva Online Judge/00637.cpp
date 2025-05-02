#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,a,now,state;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n,n){
        cout << "Printing order for " << n << " pages:\n";
        now=state=0;
        if(n%4){
            a=(n+4-n%4)/4;
        }else{
            a=n/4;
        }
        vector<vector<int>> pages(a,{-1,-1,-1,-1});
        for(int i=1;i<=n;i++){
            if(state==0){
                pages[now][1]=i;
                state=1;
            }else if(state==1){
                pages[now][2]=i;
                state=0;
                now++;
                if(now==a){
                    now--;
                    state=3;
                }
            }else if(state==3){
                pages[now][3]=i;
                state=4;
            }else{
                pages[now][0]=i;
                now--;
                state=3;
            }
        }
        for(int i=0;i<a;i++){
            cout << "Sheet " << i+1 << ", front: ";
            if(pages[i][0]==-1){
                cout << "Blank, ";
            }else{
                cout << pages[i][0] << ", ";
            }
            cout << pages[i][1] << '\n';
            if(!(pages[i][3]==-1 && pages[i][2]==-1)){
                cout << "Sheet " << i+1 << ", back : ";
                cout << pages[i][2] << ", ";
                if(pages[i][3]==-1){
                    cout << "Blank\n";
                }else{
                    cout << pages[i][3] << '\n';
                }
            }
        }
    }
}