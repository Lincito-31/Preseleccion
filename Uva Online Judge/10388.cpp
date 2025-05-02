#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int t,i,j,a,con;
string jane,jhon,jane1,jhon1;
bool xd,lol;
int main(){
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        if(lol){
            cout << '\n';
        }
        lol=true;
        xd=false;
        jane1=jhon1="";
        cin >> jane >> jhon;
        reverse(ALL(jane));
        reverse(ALL(jhon));
        for(int k=0;k<1000;k++){
            if(jane.empty()){
                jane=jane1;
                reverse(ALL(jane));
                jane1="";
            }
            if(jhon.empty()){
                jhon=jhon1;
                reverse(ALL(jhon));
                jhon1="";
            }
            jane1.push_back(jane.back());
            jhon1.push_back(jhon.back());
            if(jane.back()==jhon.back()){
                con=random()/141%2;
                if(con==1){
                    jhon1+=jane1;
                    jane1="";
                    reverse(ALL(jhon1));
                    cout << "Snap! for John: " << jhon1 << '\n';
                    reverse(ALL(jhon1));
                }else{
                    jane1+=jhon1;
                    jhon1="";
                    reverse(ALL(jane1));
                    cout << "Snap! for Jane: " << jane1 << '\n';
                    reverse(ALL(jane1));
                }
            }
            jane.pop_back();
            jhon.pop_back();
            if(jane1.empty() && jane.empty()){
                cout << "John wins.\n";
                xd=true;
                break;
            }
            if(jhon1.empty() && jhon.empty()){
                cout << "Jane wins.\n";
                xd=true;
                break;
            }
        }
        if(!xd){
            cout << "Keeps going and going ...\n";
        }
    }
}