#include <bits/stdc++.h>
using namespace std;
map<string,string> pare;
int n,con;
string cow1,cow2,a,b;
int main(){
    ifstream in("family.in");
    ofstream out("family.out");
    in >> n >> cow1 >> cow2;
    while(n--){
        in >> a >> b;
        pare[b]=a;
    }
    string first=cow1;
    con=0;
    while(pare.count(first)){
        first=pare[first];
        con++;
        if(first==cow2){
            if(con==1){
                out << cow2 << " is the mother of " << cow1;
            }else{
                out << cow2 << " is the ";
                for(int i=0;i<con-2;i++){
                    out << "great-";
                }
                out << "grand-mother of " << cow1;
            }
            return 0;
        }
    }
    first=cow2;
    con=0;
    while(pare.count(first)){
        first=pare[first];
        con++;
        if(first==cow1){
            if(con==1){
                out << cow1 << " is the mother of " << cow2;
            }else{
                out << cow1 << " is the ";
                for(int i=0;i<con-2;i++){
                    out << "great-";
                }
                out << "grand-mother of " << cow2;
            }
            return 0;
        }
    }
    if(pare.count(cow1)){
        string second=pare[cow1];
        first=cow2;
        con=0;
        while(pare.count(first)){
            first=pare[first];
            con++;
            if(first==second){
                if(con==1){
                    out << "SIBLINGS";
                }else{
                    out << cow1 << " is the ";
                    for(int i=0;i<con-2;i++){
                        out << "great-";
                    }
                    out << "aunt of " << cow2;
                }
                return 0;
            }
        }
    }
    if(pare.count(cow2)){
        string second=pare[cow2];
        first=cow1;
        con=0;
        while(pare.count(first)){
            first=pare[first];
            con++;
            if(first==second){
                if(con==1){
                    out << "SIBLINGS";
                }else{
                    out << cow2 << " is the ";
                    for(int i=0;i<con-2;i++){
                        out << "great-";
                    }
                    out << "aunt of " << cow1;
                }
                return 0;
            }
        }
    }
    first=cow1;
    string second=cow2;
    while(pare.count(first)){
        first=pare[first];
    }
    while(pare.count(second)){
        second=pare[second];
    }
    if(first==second){
        out << "COUSINS";
        return 0;
    }
    out << "NOT RELATED";
}