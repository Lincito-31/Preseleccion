#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,now;
int main(){
    ifstream in("cowqueue.in");
    ofstream out("cowqueue.out");
    in >> n;
    vector<pair<int,int>> time(n);
    for(int i=0;i<n;i++){
        in >> time[i].first >> time[i].second;
    }
    sort(ALL(time));
    for(int i=0;i<n;i++){
        now=max(now,time[i].first)+time[i].second;
    }
    out << now;
}