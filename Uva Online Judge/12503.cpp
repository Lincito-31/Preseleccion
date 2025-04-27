#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int t,n,a[100],now,x;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        now=0;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> s;
            if(s=="LEFT"){
                a[i]=-1;
                now--;
            }else if(s=="RIGHT"){
                a[i]=1;
                now++;
            }else{
                cin >> s >> x;
                now+=a[i]=a[--x];
            }
        }
        cout << now << '\n';
    }
}