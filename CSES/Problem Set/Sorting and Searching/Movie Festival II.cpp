#include <bits/stdc++.h>
using namespace std;
int n,k,a,b,con=0;
int main(){
    scanf("%d%d",&n,&k);
    vector<pair<int,int>> movie(n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&movie[i].second,&movie[i].first);
    }
    sort(movie.begin(),movie.end());
    multiset<int> people;
    for(int i=0;i<k;i++){
        people.insert(0);
    }
    for(int i=0;i<n;i++){
        auto p=people.upper_bound(movie[i].second);
        if(p==people.begin()){
            continue;
        }
        p--;
        people.erase(p);
        people.insert(movie[i].first);
        con++;
    }
    printf("%d",con);
}