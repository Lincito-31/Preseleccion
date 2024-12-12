#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b;
int main(){
    while(true){
        scanf("%d%d",&a,&b);
        if(a==-1 && b==-1){
            break;
        }
        printf("%d\n",min(abs(b-a),min(a,b)+100-max(a,b)));
    }
}