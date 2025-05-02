#include <bits/stdc++.h>
using namespace std;
int t,n;
string s,nue,nue2;
map<string,pair<string,bool>> op;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int j=0;j<t;j++){
        cout << "Expression #" << j+1 << ": ";
        cin >> n;
        op.clear();
        cin.ignore();
        while(n--){
            nue=nue2="";
            getline(cin ,s);
            for(int i=0;i<s.size();i++){
                if(s[i]==' '){
                    continue;
                }
                nue.push_back(s[i]);
            }
            s=nue;
            nue="";
            for(int i=0;i<s.size();i++){
                if(s[i]=='='){
                    for(int j=i+1;j<s.size();j++){
                        nue2.push_back(s[j]);
                    }
                    //op[nue]=nue2;
                    break;
                }
                nue.push_back(s[i]);
            }
            string first="",second="";
            bool mas=false;
            int i=0;
            for(;nue2[i]!='+' && nue2[i]!='*';i++){
                first.push_back(nue2[i]);
            }
            if(nue2[i]=='+'){
                mas=true;
            }
            i++;
            for(;i<nue2.size();i++){
                second.push_back(nue2[i]);
            }
            if(first[0]>='0' && first[0]<='9' && second[0]>='0' && second[0]<='9'){
                if(mas){
                    op[nue]={first+"+"+second,true};
                }else{
                    op[nue]={first+"*"+second,false};
                }
            }else if(first[0]>='0' && first[0]<='9'){
                if(mas){
                    if(op[second].second){
                        op[nue]={first+"+("+op[second].first+")",true};
                    }else{
                        op[nue]={first+"+"+op[second].first,true};
                    }
                }else{
                    op[nue]={first+"*("+op[second].first+")",false};
                }
            }else if(second[0]>='0' && second[0]<='9'){
                if(mas){
                    op[nue]={op[first].first+"+"+second,true};
                }else{
                    if(op[first].second){
                        op[nue]={"("+op[first].first+")*"+second,false};
                    }else{
                        op[nue]={op[first].first+"*"+second,false};
                    }
                }
            }else{
                if(mas){
                    op[nue]={"",true};
                    op[nue].first+=op[first].first+"+";
                    if(op[second].second){
                        op[nue].first+="("+op[second].first+")";
                    }else{
                        op[nue].first+=op[second].first;
                    }
                }else{
                    op[nue]={"",false};
                    if(op[first].second){
                        op[nue].first+="("+op[first].first+")*";
                    }else{
                        op[nue].first+=op[first].first+"*";
                    }
                    op[nue].first+="("+op[second].first+")";
                }
            }
            if(n==0){
                cout << op[nue].first << '\n';
            }
        }
    }
}