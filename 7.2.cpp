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
long long naslednici(string s){
  long long kolik = 0;
  ifstream infile("input.txt");
  string temp;
  regex r(s + " bags contain");
  int nasobek=0;
  while(getline(infile,temp)){
    if(regex_search(temp,r)){
        size_t zacatek = temp.find("contain");
        int index=zacatek+6;
      while(temp[index]!='.'){
        string s2="";
        index+=2;
        if(temp[index]=='n')return 1;
        while(temp[index]!=' '){
          nasobek=temp[index]-48;
          index++;
        }
        index++;
        while(temp[index]!=' '){
          s2+=temp[index];
          index++;
        }
        s2+=temp[index];
        index++;
        while(temp[index]!=' '){
          s2+=temp[index];
          index++;
        }
        cout << nasobek << " krat " << s2 <<endl;
        kolik+=nasobek*naslednici(s2);
        while((temp[index]!='.')&&(temp[index]!=','))index++;

      }
    }
  }
  kolik++;
  cout << kolik <<endl;
  return kolik;
}
int main() {

  predchudci("shiny gold");
  cout <<m <<endl;
  cout << naslednici("shiny gold") -1 << endl;
  return 0;
}