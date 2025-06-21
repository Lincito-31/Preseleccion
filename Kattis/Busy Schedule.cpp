#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n && n){
        vector<vector<int>> time(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            cin >> st;
            if(st[1]==':'){
                time[i][1]=st[0]-48;
                time[i][2]=10*(st[2]-48)+st[3]-48;
            }else{
                time[i][1]=10*(st[0]-48)+st[1]-48;
                time[i][2]=10*(st[3]-48)+st[4]-48;
            }
            time[i][1]%=12;
            cin >> st;
            time[i][0]=st=="p.m.";
        }
        sort(ALL(time));
        for(int i=0;i<n;i++){
            if(time[i][1]==0){
                time[i][1]=12;
            }
            cout << time[i][1] << ':';
            if(time[i][2]<10){
                cout << 0;
            }
            cout << time[i][2];
            if(time[i][0]){
                cout << " p.m.\n";
            }else{
                cout << " a.m.\n";
            }
        }
        cout << '\n';
    }
}