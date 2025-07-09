#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int t,n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<bool> visited0(26,false);
    vector<bool> visited1(n,false);
    vector<string> cod(n);
    for(int i=0;i<n;i++){
        cin >> cod[i];
    }
    vector<set<int>> si(26);
    vector<set<int>> is(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<cod[i].size();j++){
            si[cod[i][j]-97].insert(i);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<cod[i].size();j++){
            is[i].insert(cod[i][j]-97);
        }
    }
    vector<set<int>> res;
    for(int i=0;i<26;i++){
        set<int> nums;
        queue<int> col1;
        queue<int> col2;
        col1.push(i);
        while(!col1.empty()){
            int to=col1.front();
            col1.pop();
            if(visited0[to]){
                continue;
            }
            visited0[to]=true;
            for(auto u:si[to]){
                nums.insert(u);
                col2.push(u);
            }
            while(!col2.empty()){
                int aa=col2.front();
                col2.pop();
                if(visited1[aa]){
                    continue;
                }
                visited1[aa]=true;
                for(auto k:is[aa]){
                    col1.push(k);
                }
            }
        }
        if(!nums.empty()){
            res.push_back(nums);
        }
    }
    printf("%d",res.size());
}