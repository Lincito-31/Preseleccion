#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
vi tam,dad;
set<int> insertados;
int n;
int findx(int a){
    if(dad[a]==a){
        return a;
    }
    return dad[a]=findx(a);
}
void unionx(int a,int b){
    if(findx(a)==findx(b)){
        return;
    }
    if(tam[a]<tam[b]){
        dad[a]=b;
        tam[b]+=tam[a];
    }else{
        dad[b]=a;
        tam[a]+=tam[b];
    }
}
int main(){
    scanf("%d",&n);
    vpii nums(n);
    tam.assign(n,1);
    dad.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i].first);
        nums[i].second=i;
        dad[i]=i;
    }
    sort(REV(nums));
    int con=1;
    int i=0;
    while(con<=n){
        insertados.insert(nums[i].second);
        if(insertados.find(nums[i].second+1)!=insertados.end()){
            unionx(nums[i].second,nums[i].second+1);
        }
        if(insertados.find(nums[i].second-1)!=insertados.end()){
            unionx(nums[i].second,nums[i].second-1);
        }
        int tama=tam[findx(nums[i].second)];
        if(tama>=con){
            printf("%d ",nums[i].first);
            con++;
            i--;
        }
        i++;
        if(i>=n){
            i--;
        }
    }
}