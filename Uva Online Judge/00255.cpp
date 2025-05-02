#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a,c,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> a >> b >> c){
        if(a==b){
            cout << "Illegal state\n";
        }else if(b==c || (!((b%8==c%8)||(b/8==c/8)))||((b%8==c%8)&&(c%8==a%8)&&((b>=a&&a>=c)||(c>=a&&a>=b)))||((b/8==c/8)&&(c/8==a/8)&&((b>=a&&a>=c)||(c>=a&&a>=b)))){
            cout << "Illegal move\n";
        }else if((((c/8)==(a/8))&&(((c%8-1)==(a%8))||((c%8+1)==(a%8))))||(((c%8)==(a%8))&&((c/8+1)==(a/8) || (c/8-1)==(a/8)))){
            cout << "Move not allowed\n";
        }else if((a==0&&c==9)||(a==7&&c==14)||(a==56&&c==49)||(a==63&&c==54)){
            cout << "Stop\n";
        }else{
            cout << "Continue\n";
        }
    }
}