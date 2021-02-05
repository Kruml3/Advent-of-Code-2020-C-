#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main() {
  int pocetSpravne = 0;
  int pocetSpatne = 0;
  ifstream infile("input2.txt");
  string temp;
  while(getline(infile,temp)){
    int mame = 0;
    int x1 = 0;
    int x2 = 0;
    char hledame = ' ';
    int i = 0;
    while(temp[i]!='-'){
        x1 = x1*10;
        x1 += (int)temp[i]-48;
        i++;
    }
    i++;
    while(temp[i]!=' '){
        x2 = x2*10;
        x2 += (int)temp[i]-48;
        i++;
    }
    i++;
    hledame = temp[i];
    i+=3;
    int poradi=1;
    while(temp[i]){
        if((temp[i]==hledame)&&(poradi==x1))mame++;
        if((temp[i]==hledame)&&(poradi==x2))mame++;
        i++;
        poradi++;
    }
    cout << x1 << " " << x2 << " " <<mame<< endl;
    if(mame==1){pocetSpravne++;cout << "spravne" << endl;}
    else {pocetSpatne++;cout << "spatne" << endl;};
  }
  cout << pocetSpatne << endl;
  cout << pocetSpravne << endl;
  return 0;
}

