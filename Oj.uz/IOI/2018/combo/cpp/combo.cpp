#include "combo.h"
#include <bits/stdc++.h>
using namespace std;
string S;
string guess_sequence(int N) {
  if(press("AB")){
    if(press("A")){
      S="A";
      if(N==1){
        return S;
      }
      while(S.size()<N-1){
        int x=press(S+"B"+S+"XB"+S+"XX"+S+"XY");
        if(x==S.size()+2){
          S.push_back('X');
        }else if(x==S.size()+1){
          S.push_back('B');
        }else{
          S.push_back('Y');
        }
      }
      if(press(S+"B")==S.size()+1){
        S.push_back('B');
      }else if(press(S+"X")==S.size()+1){
        S.push_back('X');
      }else{
        S.push_back('Y');
      }
    }else{
      S="B";
      if(N==1){
        return S;
      }
      while(S.size()<N-1){
        int x=press(S+"A"+S+"XA"+S+"XX"+S+"XY");
        if(x==S.size()+2){
          S.push_back('X');
        }else if(x==S.size()+1){
          S.push_back('A');
        }else{
          S.push_back('Y');
        }
      }
      if(press(S+"A")==S.size()+1){
        S.push_back('A');
      }else if(press(S+"X")==S.size()+1){
        S.push_back('X');
      }else{
        S.push_back('Y');
      }
    }
  }else{
    if(press("X")){
      S="X";
      if(N==1){
        return S;
      }
      while(S.size()<N-1){
        int x=press(S+"A"+S+"BA"+S+"BB"+S+"BY");
        if(x==S.size()+2){
          S.push_back('B');
        }else if(x==S.size()+1){
          S.push_back('A');
        }else{
          S.push_back('Y');
        }
      }
      if(press(S+"A")==S.size()+1){
        S.push_back('A');
      }else if(press(S+"B")==S.size()+1){
        S.push_back('B');
      }else{
        S.push_back('Y');
      }
    }else{
      S="Y";
      if(N==1){
        return S;
      }
      while(S.size()<N-1){
        int x=press(S+"A"+S+"BA"+S+"BB"+S+"BX");
        if(x==S.size()+2){
          S.push_back('B');
        }else if(x==S.size()+1){
          S.push_back('A');
        }else{
          S.push_back('X');
        }
      }
      if(press(S+"A")==S.size()+1){
        S.push_back('A');
      }else if(press(S+"B")==S.size()+1){
        S.push_back('B');
      }else{
        S.push_back('X');
      }
    }
  }
  return S;
}
