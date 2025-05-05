/*
ID: simplem2
TASK: palsquare
LANG: C++
*/
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n;
vector<char> touse;
char base[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
bool pal(int x){
    vector<char> temp;
    while(x>0){
        temp.push_back(base[x%n]);
        x/=n;
    }
    vector<char> rev(temp);
    reverse(ALL(rev));
    touse=rev;
    if(temp==rev){
        return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream in("palsquare.in");
    ofstream out("palsquare.out");
    in >> n;
    for(int i=1;i<=300;i++){
        if(pal(i*i)){
            pal(i);
            for(int j=0;j<touse.size();j++){
                out << touse[j];
            }
            out << ' ';
            pal(i*i);
            for(int j=0;j<touse.size();j++){
                out << touse[j];
            }
            out << '\n';
        }
    }
}
