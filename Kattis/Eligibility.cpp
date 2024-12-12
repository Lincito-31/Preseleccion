#include <bits/stdc++.h>
using namespace std;
int n,courses;
string line,in,name,studies,birthday;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    getline(cin,line);
    while(n--){
        getline(cin,line);
        stringstream in(line);
        in >> name >> studies >> birthday >> courses;
        int year1=stoi(studies.substr(0,4));
        int year2=stoi(birthday.substr(0,4));
        int elegibility=0;
        if(year1>=2010 || year2>=1991){
            elegibility=1;
        }else if(courses>=41){
            elegibility=2;
        }
        cout << name << " ";
        if(elegibility==1){
            cout << "eligible\n";
        }else if(elegibility==2){
            cout << "ineligible\n";
        }else{
            cout << "coach petitions\n";
        }
    }
}