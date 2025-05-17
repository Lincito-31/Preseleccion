#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t,n,a;
ll con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        con=0;
        vector<int> par,impar;
        for(int i=0;i<n;i++){
            cin >> a;
            if(i%2){
                impar.push_back(a);
            }else{
                par.push_back(a);
            }
        }
        intset f;
        if(n%2){
            //priorizar impar
            for(int i=0;i<impar.size();i++){
                con+=f.size()-f.order_of_key(impar[i]);
                f.insert(impar[i]);
            }
            sort(ALL(impar));
            if(con%2){
                swap(par[0],par[1]);
            }
            con=0;
            f.clear();
            for(int i=0;i<par.size();i++){
                con+=f.size()-f.order_of_key(par[i]);
                f.insert(par[i]);
            }
            sort(ALL(par));
            if(con%2){
                swap(par[par.size()-1],par[par.size()-2]);
            }
        }else{
            //priorizar par
            for(int i=0;i<par.size();i++){
                con+=f.size()-f.order_of_key(par[i]);
                f.insert(par[i]);
            }
            sort(ALL(par));
            if(con%2){
                swap(impar[0],impar[1]);
            }
            con=0;
            f.clear();
            for(int i=0;i<impar.size();i++){
                con+=f.size()-f.order_of_key(impar[i]);
                f.insert(impar[i]);
            }
            sort(ALL(impar));
            if(con%2){
                swap(impar[impar.size()-1],impar[impar.size()-2]);
            }
        }
        for(int i=0;i<par.size();i++){
            cout << par[i] << ' ';
            if(i<impar.size()){
                cout << impar[i] << ' ';
            }
        }
        cout << '\n';
    }
}