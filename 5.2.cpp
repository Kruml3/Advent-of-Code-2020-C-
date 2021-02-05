#include "bits/stdc++.h"

using namespace std;
int main() {

  ifstream infile("input5.txt");
  string temp;
  int id;
  int hghid;
  int index = 0;
  bool missing [1024];
  bool start=false;
  for(int k=0;k<1024;k++)missing[k]=true;
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
  for(int l=0;l<1024;l++){
    if(!missing[l])start=true;
    else if(start){cout << endl << l << endl;break;}
  }
  return 0;
}