#include <bits/stdc++.h>
using namespace std;
int t,n;
char A[2005],B[2005];
set<vector<pair<int,int>>> dif;
string temp="";
void solve(int x,int y){
    if(x==n && y==n){
        //procesar
        vector<pair<int,int>> res;
        int last=0;
        for(int i=0;i<2*n;i++){
            if(temp[i]=='+'){
                res.push_back({last,1});
                last++;
            }else if(temp[i]=='0'){
                res.clear();
                last=0;
            }else{
                for(int j=0;j<res.size();j++){
                    res[j].second*=temp[i]-48;
                }
            }
        }
        dif.insert(res);
        return;
    }
    if(x<n){
        temp.push_back(A[x]);
        solve(x+1,y);
        temp.pop_back();
    }
    if(y<n){
        temp.push_back(B[y]);
        solve(x,y+1);
        temp.pop_back();
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        dif.clear();
        scanf("%d",&n);
        scanf("%s%s",A,B);
        solve(0,0);
        printf("%d\n",dif.size());
    }
}