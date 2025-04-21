#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int w,l,n,a;
char t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> l >> w && (w+l)){
        cin >> n;
        int x=0,y=0,tx=0,ty=0;
        while(n--){
            cin >> t >> a;
            if(t=='u'){
                ty+=a;
                y=min(y+a,w-1);
            }else if(t=='d'){
                ty-=a;
                y=max(0,y-a);
            }else if(t=='l'){
                tx-=a;
                x=max(0,x-a);
            }else{
                tx+=a;
                x=min(x+a,l-1);
            }
        }
        cout << "Robot thinks " << tx << ' ' << ty << '\n';
        cout << "Actually at " << x << ' ' << y << "\n\n";
    }
}