#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef pair<int,int> pii;
int n,mat[1002][1002],psum[1002][1002],con,canti;
pair<pii,pii> bound[1000001];
bool imposible[1000001];
int main(){
    ifstream fin("art.in");
    ofstream fout("art.out");
    fin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            fin >> mat[i][j];
            if(mat[i][j]==0){
                continue;
            }
            if(bound[mat[i][j]]==make_pair(make_pair(0,0),make_pair(0,0))){
                bound[mat[i][j]]={{i,j},{i,j}};
                con++;
            }
            bound[mat[i][j]].first.first=min(bound[mat[i][j]].first.first,i);
            bound[mat[i][j]].first.second=min(bound[mat[i][j]].first.second,j);
            bound[mat[i][j]].second.first=max(bound[mat[i][j]].second.first,i);
            bound[mat[i][j]].second.second=max(bound[mat[i][j]].second.second,j);
        }
    }
    for(int i=1;i<=n*n;i++){
        if(bound[i]==make_pair(make_pair(0,0),make_pair(0,0))){
            continue;
        }
        //out << bound[i].first.first << ' ' << bound[i].first.second << ' ' << bound[i].second.first << ' ' << bound[i].second.second << '\n';
        psum[bound[i].first.first][bound[i].first.second]++;
        psum[bound[i].first.first][bound[i].second.second+1]--;
        psum[bound[i].second.first+1][bound[i].first.second]--;
        psum[bound[i].second.first+1][bound[i].second.second+1]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            psum[i][j]+=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
            if(psum[i][j]>1){
                imposible[mat[i][j]]=true;
            }
        }
    }
    if(con==1){
        fout << n*n-1;
        return 0;
    }
    for(int i=1;i<=n*n;i++){
        if(!imposible[i]){
            canti++;
        }
    }
    fout << canti;
}