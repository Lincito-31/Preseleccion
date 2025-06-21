#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n;
bool cmp(string x,string y){
    if(x[0]==y[0]){
        return x[1]<y[1];
    }
    return x[0]<y[0];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n && n){
        vector<string> name(n);
        for(int i=0;i<n;i++){
            cin >> name[i];
        }
        stable_sort(ALL(name),cmp);
        for(int i=0;i<n;i++){
            cout << name[i] << '\n';
        }
        cout << '\n';
    }
}