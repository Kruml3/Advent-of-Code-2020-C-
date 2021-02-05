#include "bits/stdc++.h"

using namespace std;
static int result = 0;
int m=0;
string verify[500];
void predchudci(string tento){
  ifstream infile("input7.txt");
  string temp;
  string ancestors[100];
  int anci=0;
  regex r("[0-9] " + tento + " bag");
  while(getline(infile,temp)){
    if(regex_search(temp,r)){
      result++;
      string s = "";
      int i=0;
      while(temp[i]!=' '){
        s+=temp[i];
        i++;
      }
      s+=temp[i];i++;
      while(temp[i]!=' '){
        s+=temp[i];
        i++;
      }
      anci++;
      bool uzmame=false;
      for(int k=0;k<500;k++){
        if(s==verify[k])uzmame=true;
      }
      if(!uzmame){
        verify[m]=s;
        m++;
      }

      predchudci(s);
    }
  }

  return;
}
int main() {

  predchudci("shiny gold");
  cout <<m <<endl;
  return 0;
}