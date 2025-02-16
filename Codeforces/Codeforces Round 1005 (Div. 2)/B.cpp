#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t=1,n,a;
int main(){
    FASTIO;
    cin >> t;
    while(t--){
        cin >> n;
        vi nums(n);
        vi con(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
            con[--nums[i]]++;
        }
        int maxi=0,rex=-1,rey=-1,x,cont=0;
        x=0;
        for(int i=0;i<n;i++){
            if(con[nums[i]]==1){
                cont++;
            }else{
                if(maxi<cont){
                    maxi=cont;
                    rex=x+1;
                    rey=i;
                }
                x=i+1;
                cont=0;
            }
        }
        if(cont>0){
            if(maxi<cont){
                maxi=cont;
                rex=x+1;
                rey=n;
            }
            cont=0;
        }
        if(rex==-1){
            cout << "0\n";
        }else{
            cout << rex << " " << rey << "\n";
        }
    }
}
