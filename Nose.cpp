#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int,int> list;
int a;
vector<int> arr;
int main()
{ while(!cin.eof())
  { cin >> a;
    if(!list.count(a)) {arr.push_back(a); list[a] = 1;}
    else list[a]++;
  }
  for(int i = 0; i < arr.size(); i++) 
  { cout << arr[i] << ' ' << list[arr[i]] << '\n';}
}