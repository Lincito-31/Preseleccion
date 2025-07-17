#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t,n,m,maxi;
bool cmp(pii x,pii y){
    if(x.second==y.second){
        return x.first<y.first;
    }
    return x.second<y.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        int mat[n][m];
        vector<int> cont(100);
        vector<pii> posnums[100];
        maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j];
                posnums[--mat[i][j]].push_back({i,j});
                maxi=max(maxi,mat[i][j]);
                cont[mat[i][j]]++;
            }
        }
        sort(ALL(posnums[maxi]));
        int asegr=-1,asegc=-1;
        for(int i=1;i<posnums[maxi].size();i++){
            if(posnums[maxi][i].first==posnums[maxi][i-1].first){
                asegr=posnums[maxi][i].first;
                break;
            }
        }
        sort(ALL(posnums[maxi]),cmp);
        for(int i=1;i<posnums[maxi].size();i++){
            if(posnums[maxi][i].second==posnums[maxi][i-1].second){
                asegc=posnums[maxi][i].second;
                break;
            }
        }
        if(asegr!=-1){
            for(int j=0;j<m;j++){
                if(mat[asegr][j]==maxi){
                    cont[mat[asegr][j]]--;
                    mat[asegr][j]--;
                }
            }
        }
        if(asegc!=-1){
            for(int i=0;i<n;i++){
                if(mat[i][asegc]==maxi){
                    cont[mat[i][asegc]]--;
                    mat[i][asegc]--;
                }
            }
        }
        if(asegr!=-1 && asegc!=-1){
            if(cont[maxi]>0){
                cout << maxi+1 << '\n';
            }else{
                cout << maxi << '\n';
            }
        }else if(asegr!=-1 || asegc!=-1){
            if(cont[maxi]>1){
                cout << maxi+1 << '\n';
            }else{
                cout << maxi << '\n';
            }
        }else{
            if(cont[maxi]>2){
                cout << maxi+1 << '\n';
            }else{
                cout << maxi << '\n';
            }
        }
    }
}