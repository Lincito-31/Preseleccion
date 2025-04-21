#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,t,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        int maxi=0,sum=0,pos=0;
        bool xd=false;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> c;
            sum+=c;
            if(c>maxi){
                xd=true;
                maxi=c;
                pos=i;
            }else if(c==maxi){
                xd=false;
            }
        }
        if(!xd){
            cout << "no winner\n";
        }else if(sum<2*maxi){
            cout << "majority winner " << pos << "\n";
        }else{
            cout << "minority winner " << pos << "\n";
        }
    }
}