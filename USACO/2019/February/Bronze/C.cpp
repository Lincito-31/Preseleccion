#include <bits/stdc++.h>
using namespace std;
int n,a,b,finm,finM=1e9,inim,iniM=1e9;
string s;
bool xd;
int main(){
    ifstream in("traffic.in");
    ofstream out("traffic.out");
    in >> n;
    vector<tuple<string,int,int>> sensors(n);
    for(int i=0;i<n;i++){
        in >> s >> a >> b;
        sensors[i]={s,a,b};
    }
    for(int i=0;i<n;i++){
        if(get<0>(sensors[i])=="on"){
            finm+=get<1>(sensors[i]);
            finM+=get<2>(sensors[i]);
        }else if(get<0>(sensors[i])=="off"){
            finm-=get<2>(sensors[i]);
            finM-=get<1>(sensors[i]);
            finm=max(finm,0);
        }else{
            finm=max(finm,get<1>(sensors[i]));
            finM=min(finM,get<2>(sensors[i]));
        }
    }
    for(int i=n-1;i>=0;i--){
        if(get<0>(sensors[i])=="off"){
            inim+=get<1>(sensors[i]);
            iniM+=get<2>(sensors[i]);
        }else if(get<0>(sensors[i])=="on"){
            inim-=get<2>(sensors[i]);
            iniM-=get<1>(sensors[i]);
            inim=max(inim,0);
        }else{
            inim=max(inim,get<1>(sensors[i]));
            iniM=min(iniM,get<2>(sensors[i]));
        }
    }
    out << inim << ' ' << iniM << '\n';
    out << finm << ' ' << finM << '\n';
}