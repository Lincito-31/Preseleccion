#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int t,x,res,diag1,diag2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        res=1e9;
        vector<bool> used(75,false);
        vector<pair<int,int>> rc(75);
        vector<int> row(5,0),col(5,0);
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(i==2 && j==2){
                    continue;
                }
                cin >> x;
                used[--x]=true;
                rc[x]={i,j};
            }
        }
        row[2]=col[2]=diag1=diag2=1;
        for(int i=0;i<75;i++){
            cin >> x;
            if(used[--x]){
                row[rc[x].first]++;
                col[rc[x].second]++;
                if(rc[x].first-rc[x].second==0){
                    diag1++;
                }
                if(rc[x].first+rc[x].second==4){
                    diag2++;
                }
                if(row[rc[x].first]==5 || col[rc[x].second]==5 || diag1==5 || diag2==5){
                    res=min(res,i+1);
                }
            }
        }
        cout << "BINGO after " << res << " numbers announced\n";
    }
}