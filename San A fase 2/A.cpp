#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
int t,a,b;
string st;
pair<pair<int,int>,string> x;
bool cmp(pair<pair<int,int>,string> aa,pair<pair<int,int>,string> bb){
    if(aa.first==bb.first){
        return aa.second<=bb.second;
    }
    if(aa.first.first==bb.first.first){
        return aa.first.second<bb.first.second;
    }
    return aa.first.first>bb.first.first;
}
bool cmp2(pair<pair<int,int>,string> aa,pair<pair<int,int>,string> bb){
    return aa.second<bb.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    vector<pair<pair<int,int>,string>> per(10);
    for(int i=1;i<=t;i++){
        for(int j=0;j<10;j++){
            cin >> per[j].second >> per[j].first.first >> per[j].first.second;
        }
        sort(ALL(per),cmp);
        /*for(int j=0;j<10;j++){
            cout << per[j].second << endl;
        }*/
        vector<pair<pair<int,int>,string>> eqa(5);
        vector<pair<pair<int,int>,string>> eqb(5);
        for(int j=0;j<5;j++){
            eqa[j]=per[j];
        }
        for(int j=0;j<5;j++){
            eqb[j]=per[j+5];
        }
        sort(ALL(eqa),cmp2);
        sort(ALL(eqb),cmp2);
        cout << "Case " << i << ":\n";
        cout << "(";
        for(int j=0;j<4;j++){
            cout << eqa[j].second << ", ";
        }
        cout << eqa[4].second << ")\n";
        cout << "(";
        for(int j=0;j<4;j++){
            cout << eqb[j].second << ", ";
        }
        cout << eqb[4].second << ")\n";
    }
}