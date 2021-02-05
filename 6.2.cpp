#include "bits/stdc++.h"

using namespace std;
int main() {

  ifstream infile("input6.txt");
  string temp;
  int result = 0;
  bool odpoved [26];
  for(int i=0;i<26;i++)odpoved[i]=true;
  while(getline(infile,temp)){
    if(temp==""){
      for(int i=0;i<26;i++){if(odpoved[i])result++;odpoved[i]=true;}
        continue;
   } 
    for(int i=0;i<26;i++){
      char c = i+97;
      string s = {c};
      regex rs(s);
      if(!(regex_search(temp,rs))){
        odpoved[i]=false;
      }
    }
  }
  cout <<result <<endl;
  return 0;
}