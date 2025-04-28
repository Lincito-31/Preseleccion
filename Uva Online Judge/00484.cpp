#include <bits/stdc++.h>
using namespace std;
int a,n;
map<int,int> con;
vector<int> ord;
int main(){
    while(scanf("%d",&a)!=EOF){
        if(con[a]==0){
            ord.push_back(a);
        }
        con[a]++;
    }
    n=ord.size();
    for(int i=0;i<n;i++){
        printf("%d %d\n",ord[i],con[ord[i]]);
    }
}