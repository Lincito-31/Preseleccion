#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr,now,res;
vector<bool> used;
bool xd;
void solve(int x,int last){
    if(x==n){
        xd=true;
        res=now;
        return;
    }
    if(x==0){
        for(int i=1;i<=n;i++){
            if(!used[i]){
                used[i]=true;
                now.push_back(i);
                solve(x+1,i);
                now.pop_back();
                used[i]=false;
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            if(!used[i]){
                if(last+i==arr[x]){
                    used[i]=true;
                    now.push_back(i);
                    solve(x+1,i);
                    now.pop_back();
                    used[i]=false;
                }
            }
        }
    }
}
int main(){
    ifstream in("photo.in");
    ofstream out("photo.out");
    in >> n;
    arr.resize(n);
    used.resize(n+1);
    for(int i=1;i<n;i++){
        in >> arr[i];
    }
    solve(0,0);
    out << res[0];
    for(int i=1;i<n;i++){
        out << ' ' << res[i];
    }
    out << '\n';
}