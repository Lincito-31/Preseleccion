#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,maxi;
int main(){
    cin >> n;
    vector<pair<int,int>> dist(n);
    for(int i=0;i<n;i++){
        cin >> dist[i].first;
    }
    for(int i=0;i<n;i++){
        cin >> dist[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            maxi=max(maxi,(int)pow(dist[j].first-dist[i].first,2)+(int)pow(dist[j].second-dist[i].second,2));
        }
    }
    cout << maxi;
}