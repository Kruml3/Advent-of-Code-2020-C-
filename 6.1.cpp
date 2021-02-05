#include "bits/stdc++.h"

using namespace std;
int main() {

  ifstream infile("input6.txt");
  string temp;
  int result = 0;
  bool odpoved [26];
  for(int i=0;i<26;i++)odpoved[i]=false;
  while(getline(infile,temp)){
    if(temp==""){
      for(int i=0;i<26;i++){if(odpoved[i])result++;odpoved[i]=false;}
   } 
    int index=0;
    while(temp[index]){
      odpoved[temp[index]-97]=true;
      index++;
    }
  }
  cout <<result <<endl;
  return 0;
}