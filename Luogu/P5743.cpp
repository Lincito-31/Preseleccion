#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n,can=1;
int main(){
    scanf("%d",&n);
    while(--n){
        can++;
        can*=2;
    }
    printf("%d",can);
}