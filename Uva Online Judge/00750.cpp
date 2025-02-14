#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    bool lol=false;
    while(t--){
        if(lol){
            cout << '\n';
        }
        lol=true;
        cin >> a >> b;
        a--;
        b--;
        vector<int> aevaluar(7);
        for(int i=0;i<7;i++){
            if(i>=a){
                aevaluar[i]=i+1;
            }else{
                aevaluar[i]=i;
            }
        }
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        int con=1;
        do{
            bool xd=true;
            vector<int> config(8);
            config[b]=a;
            for(int i=0;i<7;i++){
                if(i>=b){
                    config[i+1]=aevaluar[i];
                }else{
                    config[i]=aevaluar[i];
                }
            }
            for(int i=1;i<8;i++){
                for(int j=0;j<i;j++){
                    if(abs(config[i]-config[j])==abs(i-j)){
                        xd=false;
                    }
                }
            }
            if(xd){
                if(con>1){
                    cout << "\n";
                }
                if(con<10){
                    cout << ' ';
                }
                cout << con << "      ";
                con++;
                for(int i=0;i<8;i++){
                    cout << config[i]+1;
                    if(i<7){
                        cout << ' ';
                    }
                }
            }
        }while(next_permutation(aevaluar.begin(),aevaluar.end()));
        if(t>0){
            cout << "\n";
        }
    }
    cout << '\n';
}