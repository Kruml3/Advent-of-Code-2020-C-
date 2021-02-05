#include "bits/stdc++.h"

using namespace std;
static int result = 0;
string radky[675];
bool duplitest[675]; 
int main() {
  for(int i=0;i<675;i++)duplitest[i]=false;
  int radek=0;
  ifstream infile("input7.txt");
  string temp;
  while(getline(infile,temp)){
    radky[radek]=temp;
    radek++;
  }
  int hlava=0;
  while(!duplitest[hlava]){
    if(radky[hlava][0]=='a'){
      int k=5;
      int cislo=0;
      while(radky[hlava][k]){
        cislo*=10;
        cislo+=radky[hlava][k]-48;
        k++;
      }
      if(radky[hlava][4]=='+')result+=cislo;else result-=cislo;
      duplitest[hlava]=true;
      hlava++;
    }
    if(radky[hlava][0]=='j'){
      int k=5;
      int cislo=0;
      while(radky[hlava][k]){
        cislo*=10;
        cislo+=radky[hlava][k]-48;
        k++;
      }
      duplitest[hlava]=true;
      if(radky[hlava][4]=='+')hlava+=cislo;else hlava-=cislo;
    }
    if(radky[hlava][0]=='n'){
      duplitest[hlava]=true;
      hlava++;
    }
  }
  cout << result << endl;
  return 0;
}