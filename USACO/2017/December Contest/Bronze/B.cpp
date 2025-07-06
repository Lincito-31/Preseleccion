#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n;
int main(){
    ifstream in("shuffle.in");
    ofstream out("shuffle.out");
    in >> n;
    int ord[n],orden[n],res[n],orden1[n],orden2[n];
    for(int i=0;i<n;i++){
        in >> ord[i];
        ord[i]--;
    }
    for(int i=0;i<n;i++){
        in >> orden[i];
    }
    for(int i=0;i<n;i++){
        orden1[i]=orden[ord[i]];
    }
    for(int i=0;i<n;i++){
        orden2[i]=orden1[ord[i]];
    }
    for(int i=0;i<n;i++){
        out << orden2[ord[i]] << '\n';
    }
}