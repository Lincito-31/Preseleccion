#include <bits/stdc++.h>
using namespace std;
int n,a;
vector<int> check;
int main(){
    scanf("%d",&n);
    map<int,int> con;
    while(n--){
        scanf("%d",&a);
        if(con[a+1]>0){
            con[a+1]--;
        }
        con[a]++;
    }
    int cont=0;
    for(auto u:con){
        cont+=u.second;
    }
    printf("%d",cont);
}