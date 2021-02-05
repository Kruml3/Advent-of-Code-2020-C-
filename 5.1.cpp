#include "bits/stdc++.h"

using namespace std;
int main() {

  ifstream infile("input5.txt");
  string temp;
  int id;
  int hghid;
  int index = 0;
  while(getline(infile,temp)){
    int increment = 512;
    id=0;
    index=0;
    while(temp[index]){
      if((temp[index]=='B')||(temp[index]=='R'))
      id+=increment;
      increment=increment/2;
      index++;
    }
    if(id>hghid)hghid=id;
    missing[id]=false;
  }
  cout << hghid <<endl;
  return 0;
}