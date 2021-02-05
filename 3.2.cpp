#include "bits/stdc++.h"

using namespace std;
long long stromy(int right, int down){
  ifstream infile("input3.txt");
  string temp;
  int pocetStromu = 0;
  int poradi = right;
  getline(infile,temp);
  while(getline(infile,temp)){
    for(int i=0;i<down-1;i++)
      getline(infile,temp);
  if(poradi>30)poradi-=31;
  if(temp[poradi]=='#')pocetStromu++;
  poradi+=right;
  }
  cout << pocetStromu  <<endl;
  return pocetStromu;
}
int main() {
  long long answer = stromy(1,1)*stromy(1,2)*stromy(3,1)*stromy(5,1)*stromy(7,1);
  cout <<answer;
  return 0;
}

