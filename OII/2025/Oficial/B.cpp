#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,can,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    can=1<<n;
    vector<bool> porsi(can,true);
    vector<int> vec(can);
    for(int i=0;i<can;i++){
        cin >> vec[i];
    }
    if(vec[0]==1 || vec.back()==0){
        cout << -1;
        return 0;
    }
    for(int i=0;i<can;i++){
        if(vec[i]==1){
            if(__builtin_popcount(i)==1){
                con++;
            }
            for(int j=0;j<15;j++){
                if((i|(1<<j))<can){
                    if(vec[i|(1<<j)]==0){
                        cout << -1;
                        return 0;
                    }else{
                        porsi[i|(1<<j)]=false;
                    }
                }
            }
        }
    }
    cout << "2\n0 1\n1 0";
}