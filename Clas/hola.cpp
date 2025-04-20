#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main(){
    //while(condicion)
    //for(variable;condicion;incremento)
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}