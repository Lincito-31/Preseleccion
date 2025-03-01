#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> ord(n),dwarves(n),elves(n);
    for(int i=0;i<n;i++){
        cin >> ord[i];
    }
    for(int i=0;i<n;i++){
        cin >> dwarves[i];
    }
    for(int i=0;i<n;i++){
        cin >> elves[i];
    }
    sort(dwarves.begin(),dwarves.end());
    sort(elves.begin(),elves.end());
    int iz=0;
    int con=0;
    for(int i=0;i<n;i++){
        if(elves[i]>dwarves[iz]){
            iz++;
            con++;
        }
    }
    cout << con;
}