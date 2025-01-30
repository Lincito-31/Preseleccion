#include <bits/stdc++.h>
using namespace std;
int l,n,a;
int main(){
    scanf("%d",&l);
    scanf("%d",&n);
    int resmini=0,resmaxi=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        resmini=max(resmini,min(a,l+1-a));
        resmaxi=max(resmaxi,max(a,l+1-a));
    }
    printf("%d %d",resmini,resmaxi);
}