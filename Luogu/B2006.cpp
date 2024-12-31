#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
float x,a,y,b;
int main(){
    scanf("%f%f%f%f",&x,&a,&y,&b);
    printf("%.2f",(b*y-a*x)/(b-a));
}