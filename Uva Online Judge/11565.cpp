#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,A,B,C;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N;
    while(N--){
        cin >> A >> B >> C;
        bool xd=false;
        for(int i=-sqrt(C)-1;i<A && !xd;i++){
            for(int j=max(-(int)sqrt(C+i)-1,i+1);i+j<A && (A-i-j)>j && !xd && !(j>0 && i*i+2*j*j>=C);j++){
                int k=A-i-j;
                if(i*j*k==B && i*i+j*j+k*k==C){
                    cout << i << " " << j << " " << k << "\n";
                    xd=true;
                }
            }
        }
        if(!xd){
            cout << "No solution.\n";
        }
    }
}