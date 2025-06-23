#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef long long ll;
ll n,maxi;
int main(){
    ifstream in("triangles.in");
    ofstream out("triangles.out");
    in >> n;
    pll points[n];
    for(int i=0;i<n;i++){
        in >> points[i].first >> points[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i || points[i].second!=points[j].second){
                continue;
            }
            for(int k=0;k<n;k++){
                if(k==j || k==i || points[i].first!=points[k].first){
                    continue;
                }
                maxi=max(maxi,abs(points[i].first-points[j].first)*abs(points[i].second-points[k].second));
            }
        }
    }
    out << maxi;
}