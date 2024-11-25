#include <bits/stdc++.h>
using namespace std;
double x,y;
int main(){
    scanf("%lf%lf",&x,&y);
    double res=pow(x-y,2)/pow(x,2)*100;
    printf("%.8lf",res);
}