#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int psum[1000001],n,x,y,con;
string a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> a){
        cout << "Case " << ++con << ":\n";
        psum[0]=0;
        for(int i=0;i<a.size();i++){
            psum[i+1]=psum[i];
            if(a[i]=='1'){
                psum[i+1]++;
            }
        }
        cin >> n;
        while(n--){
            cin >> x >> y;
            if(psum[y+1]-psum[x]==0 || psum[y+1]-psum[x]==y-x+1){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
    }
}