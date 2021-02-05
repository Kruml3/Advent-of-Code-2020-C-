#include "bits/stdc++.h"

using namespace std;

int main() {
  ifstream infile("input3.txt");
  string temp;
  int pocetStromu = 0;
  int poradi = 3;
  getline(infile,temp);
  while(getline(infile,temp)){
  	if(poradi>30){poradi-=31;cout << endl;}
  	cout << temp[poradi];
  if(temp[poradi]=='#')pocetStromu++;
  poradi+=3;
  }
  cout << pocetStromu << endl;
  return 0;
}

