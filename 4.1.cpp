#include "bits/stdc++.h"

using namespace std;
bool vsechny(bool b1,bool b2,bool b3,bool b4,bool b5,bool b6,bool b7){
  if((b1)&&(b2)&&(b3)&&(b4)&&(b5)&&(b6)&&(b7)){
    return true;
  }
  else return false;
}
int main() {

  ifstream infile("input4.txt");
  string temp;
  int pocetValidnich = 0;
  bool byr=0;
  bool iyr=0;
  bool eyr=0;
  bool hgt=0;
  bool hcl=0;
  bool ecl=0;
  bool pid=0;
  bool cid=0;
  smatch m;
  regex rbyr("byr:");
  regex riyr("iyr:");
  regex reyr("eyr:");
  regex rhgt("hgt:");
  regex rhcl("hcl:");
  regex recl("ecl:");
  regex rpid("pid:");

  while(getline(infile,temp)){
    if(temp==""){
      cout << byr << iyr <<eyr << hgt << hcl << ecl << pid << endl;
      if(vsechny(byr,iyr,eyr,hgt,hcl,ecl,pid)){pocetValidnich++;cout <<"valid" <<endl;}
      else cout << "invalid" <<endl;
    byr=0;
    iyr=0;
    eyr=0;
    hgt=0;
    hcl=0;
    ecl=0;
    pid=0;
    cid=0;
    }
    if(regex_search(temp,rbyr))byr=true;
    if(regex_search(temp,riyr))iyr=true;
    if(regex_search(temp,reyr))eyr=true;
    if(regex_search(temp,rhgt))hgt=true;
    if(regex_search(temp,rhcl))hcl=true;
    if(regex_search(temp,recl))ecl=true;
    if(regex_search(temp,rpid))pid=true;

  }
  cout << pocetValidnich << endl;
  return 0;
}

