#include <bits/stdc++.h>
using namespace std;
int t,a,con=1;
string st,in;
int main(){
    while(cin >> t){
        getline(cin,st);
        if(t){
            int can=0;
            getline(cin,st);
            stringstream in(st);
            while(in>>a){
                if(!a){
                    can++;
                }
            }
            cout << "Case " << con << ": " << t-2*can << "\n";
            con++;
        }
    }
}