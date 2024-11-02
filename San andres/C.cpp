#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,a;
vector<bool> visited(20005,false);
vi dsu(20005);
vi tam(20005,0);
int calc(int x){
    visited[x]=true;
    if(dsu[x]==x){
        return tam[x]=1;
    }
    if(tam[x]!=0){
        return tam[x];
    }
    return tam[x]=1+calc(dsu[x]);
}
int main(){
    scanf("%d",&n);
    //vector<int> sup(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        a--;
        if(a==-2){
            dsu[i]=i;
        }else{
            dsu[i]=a;
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        if(visited[i]){
            continue;
        }
        maxi=max(maxi,calc(i));
    }
    printf("%d",maxi);
}