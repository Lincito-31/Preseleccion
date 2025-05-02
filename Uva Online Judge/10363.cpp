#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int t,x,o;
bool wino,winx;
string a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        wino=winx=false;
        x=o=0;
        cin >> a >> b >> c;
        for(int i=0;i<3;i++){
            if(a[i]=='O'){
                o++;
            }
            if(a[i]=='X'){
                x++;
            }
            if(b[i]=='O'){
                o++;
            }
            if(b[i]=='X'){
                x++;
            }
            if(c[i]=='O'){
                o++;
            }
            if(c[i]=='X'){
                x++;
            }
        }
        if(x==o || x==o+1){
            string res="OOO";
            char O='O';
            if(a==res || b==res || c==res){
                wino=true;
            }
            if(a[0]==O){
                if(b[0]==O && c[0]==O){
                    wino=true;
                }
                if(b[1]==O && c[2]==O){
                    wino=true;
                }
            }
            if(a[1]==O){
                if(b[1]==O && c[1]==O){
                    wino=true;
                }
            }
            if(a[2]==O){
                if(b[2]==O && c[2]==O){
                    wino=true;
                }
                if(b[1]==O && c[0]==O){
                    wino=true;
                }
            }
            res="XXX";
            O='X';
            if(a==res || b==res || c==res){
                winx=true;
            }
            if(a[0]==O){
                if(b[0]==O && c[0]==O){
                    winx=true;
                }
                if(b[1]==O && c[2]==O){
                    winx=true;
                }
            }
            if(a[1]==O){
                if(b[1]==O && c[1]==O){
                    winx=true;
                }
            }
            if(a[2]==O){
                if(b[2]==O && c[2]==O){
                    winx=true;
                }
                if(b[1]==O && c[0]==O){
                    winx=true;
                }
            }
            if(winx && wino){
                cout << "no\n";
            }else{
                if((wino && x>o)||(winx && x==o)){
                    cout << "no\n";
                }else{
                    cout << "yes\n";
                }
            }
        }else{
            cout << "no\n";
        }
    }
}