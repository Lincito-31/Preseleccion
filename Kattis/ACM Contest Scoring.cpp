#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,sum=0,canti=0,arr[26];
char letter;
string VE;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n && n!=-1){
        cin >> letter >> VE;
        if(VE=="wrong"){
            arr[letter-'A']+=20;
        }else{
            sum+=arr[letter-'A'];
            sum+=n;
            canti++;
        }
    }
    cout << canti << ' ' << sum;
}