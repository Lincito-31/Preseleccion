#include "aliens.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
vector<pair<int,int>> res;
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.first==y.first){
        return x.second>y.second;
    }
    return x<y;
}
pair<int,int> solve(int x){
    
}
ll take_photos(int n,int m,int k,vector<int> r,vector<int> c){
    vector<pair<int,int>> points(n);
    for(int i=0;i<n;i++){
        points[i]={min(r[i],c[i]),abs(r[i]-c[i])+1};
    }
    sort(ALL(points),cmp);
    res.push_back(points[0]);
    for(int i=1;i<n;i++){
        if(points[i].second+points[i].first>res.back().first+res.back().second){
            res.push_back(points[i]);
        }
    }
    sort(ALL(res));
    ll iz=0,de=1e9;
    while(iz<de){
        solve((iz+de)>>1);
    }
}
