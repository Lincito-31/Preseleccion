#include "vectorfunctions.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
void backwards(vector<int>& vec){reverse(ALL(vec));}
vector<int> everyOther(const vector<int>& vec){
    vector<int> res;
    for(int i=0;i<vec.size();i+=2){
        res.push_back(vec[i]);
    }
    return res;
}
int smallest(const vector<int>& vec){
    int mini=vec[0];
    for(int i=1;i<vec.size();i++){
        mini=min(mini,vec[i]);
    }
    return mini;
}
int sum(const vector<int>& vec){
    int sum=0;
    for(int i=0;i<vec.size();i++){
        sum+=vec[i];
    }
    return sum;
}
int veryOdd(const vector<int>& vec){
    int con=0;
    for(int i=1;i<vec.size();i+=2){
        if(vec[i]%2){
            con++;
        }
    }
    return con;
}