#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    bool lol=false;
    while(cin >> N && N){
        if(lol){
            cout << "\n";
        }
        lol=true;
        bool xd=false;
        for(int i=1234;i*N<1000000;i++){
            int j=i*N;
            string x=to_string(i);
            string y=to_string(j);
            string z=x+y;
            if(x.size()==4){
                z.push_back('0');
            }
            sort(z.begin(),z.end());
            if(z=="0123456789"){
                xd=true;
                cout << y << " / ";
                if(x.size()==4){
                    cout << '0';
                }
                cout << x << " = " << N << "\n";
            }
        }
        if(!xd){
            cout << "There are no solutions for " << N << ".\n";
        }
    }
}