#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
string l,r;
int t,cant;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cant=0;
        cin >> l >> r;
        reverse(ALL(l));
        reverse(ALL(r));
        while(l.size()<r.size()){
            l.push_back('0');
        }
        while(r.size()<l.size()){
            r.push_back('0');
        }
        reverse(ALL(l));
        reverse(ALL(r));
        int pos=-1;
        for(int i=0;i<l.size();i++){
            if(l[i]==r[i]){
                cant+=2;
            }else if(l[i]==r[i]-1){
                cant++;
                pos=i+1;
                break;
            }else{
                break;
            }
        }
        if(pos!=-1){
            for(;pos<l.size();pos++){
                if(l[pos]=='9' && r[pos]=='0'){
                    cant++;
                }else{
                    break;
                }
            }
        }
        cout << cant << '\n';
    }
}