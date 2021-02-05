#include "bits/stdc++.h"

using namespace std;
int main() {

  ifstream infile("input4.txt");
  string temp;
  int pocetValidnich = 0;
  bool byr=0;bool iyr=0;bool eyr=0;bool hgt=0;bool hcl=0;bool ecl=0;bool pid=0;bool cid=0;
  
  regex rbyr("byr:(19[2-9][0-9]|200[0-2])");
  regex riyr("iyr:20(1[0-9]|20)");
  regex reyr("eyr:20(2[0-9]|30)");
  regex rhgt("hgt:(59|6[0-9]|7[0-6])in");
  regex rhgt2("hgt:(1[5-8][0-9]|19[0-3])cm");
  regex rhcl("hcl:#([a-f0-9]{6}(?![0-9a-f]))");
  regex recl("ecl:(amb|blu|brn|gry|grn|hzl|oth)");
  regex rpid("pid:([0-9]{9})(?![0-9])");

  while(getline(infile,temp)){
    if(temp==""){
      if((byr)&&(iyr)&&(eyr)&&(hgt)&&(hcl)&&(ecl)&&(pid)){pocetValidnich++;cout <<"valid" <<endl;}
      else cout << "invalid" <<endl;
      byr=0;iyr=0;eyr=0;hgt=0;hcl=0;ecl=0;pid=0;cid=0;
    }
    if(regex_search(temp,rbyr))byr=true;if(regex_search(temp,riyr))iyr=true;if(regex_search(temp,reyr))eyr=true;if(regex_search(temp,rhgt))hgt=true;
    if(regex_search(temp,rhgt2))hgt=true;if(regex_search(temp,rhcl))hcl=true;if(regex_search(temp,recl))ecl=true;if(regex_search(temp,rpid))pid=true;

  }
  cout << pocetValidnich << endl;
  return 0;
}