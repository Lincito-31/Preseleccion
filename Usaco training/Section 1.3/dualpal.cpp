/*
ID: simplem2
TASK: dualpal
LANG: C++
*/
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,con,k;
bool pal(int x,int base){
    vector<int> temp;
    while(x>0){
        temp.push_back(x%base);
        x/=base;
    }
    vector<int> rev(temp);
    reverse(ALL(rev));
    if(temp==rev){
        return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    fin >> n >> k;
    for(int i=k+1;con<n;i++){
        int can=0;
        for(int j=2;j<=10;j++){
            if(pal(i,j)){
                can++;
            }
        }
        if(can>=2){
            fout << i << '\n';
            con++;
        }
    }
}
