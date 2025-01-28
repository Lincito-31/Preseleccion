/*
ID: simplem2
LANG: C++
TASK: friday
*/
#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    scanf("%d",&N);
    vector<int> day(7);
    int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int now=1;
    for(int i=1900;i<1900+N;i++){
        int nowmonth=0;
        while(nowmonth<12){
            now=(now+12)%7;
            day[now]++;
            now=(now+month[nowmonth]-12)%7;
            if((nowmonth==1)&&((i%400==0)||((i%4==0)&&(i%100!=0)))){
                now++;
                now%=7;
            }
            nowmonth++;
        }
    }
    printf("%d",day[6]);
    for(int i=0;i<6;i++){
        printf(" %d",day[i]);
    }
    printf("\n");
}