#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,cant[3],con,last=7;
int main(){
    ifstream in("measurement.in");
    ofstream out("measurement.out");
    in >> n;
    vector<tuple<int,string,string>> cows(n);
    for(int i=0;i<n;i++){
        in >> get<0>(cows[i]) >> get<1>(cows[i]) >> get<2>(cows[i]);
    }
    sort(ALL(cows));
    for(int i=0;i<n;i++){
        if(get<1>(cows[i])=="Mildred"){
            cant[0]+=stoi(get<2>(cows[i]));
        }else if(get<1>(cows[i])=="Elsie"){
            cant[1]+=stoi(get<2>(cows[i]));
        }else{
            cant[2]+=stoi(get<2>(cows[i]));
        }
        int maxi=max({cant[0],cant[1],cant[2]});
        int num=0;
        if(cant[0]==maxi){
            num+=1;
        }
        if(cant[1]==maxi){
            num+=2;
        }
        if(cant[2]==maxi){
            num+=4;
        }
        if(num!=last){
            con++;
            last=num;
        }
    }
    out << con;
}