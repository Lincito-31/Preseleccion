#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,M;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> N >> M && N){
        vector<pair<pair<int,int>,int>> cont(M);
        vector<int> per(N);
        for(int i=0;i<N;i++){
            per[i]=i;
        }
        for(int i=0;i<M;i++){
            cin >> cont[i].first.first >> cont[i].first.second >> cont[i].second;
        }
        int con=0;
        do{
            bool xd=true;
            vector<int> pos(N);
            for(int i=0;i<N;i++){
                pos[per[i]]=i;
            }
            for(int i=0;i<M && xd;i++){
                if(cont[i].second<0){
                    if(abs(pos[cont[i].first.first]-pos[cont[i].first.second])<-cont[i].second){
                        xd=false;
                    }
                }else{
                    if(abs(pos[cont[i].first.first]-pos[cont[i].first.second])>cont[i].second){
                        xd=false;
                    }
                }
            }
            if(xd){
                con++;
            }
        }while(next_permutation(per.begin(),per.end()));
        cout << con << "\n";
    }
}