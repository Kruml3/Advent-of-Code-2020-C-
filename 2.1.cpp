#include <fstream>
#include <string>
using namespace std;

int main() {
  int pocetSpravne = 0;
  int pocetSpatne = 0;	
  ifstream infile("input2.txt");
  string temp;
  while(!infile.eof()){
    infile.getline(temp,256);
  	int x1 = 0;
  	int x2 = 0;
  	char hledame = ' ';
  	int mame = 0;
  	int i = 0;
  	while(temp[i]!='-'){
  		x1 = x1*10;
  		x1 += (int)temp[i]-48;
  		i++;
  	}
  	i++;
  	while(temp[i]!='-'){
  		x2 = x2*10;
  		x2 += (int)temp[i]-48;
  		i++;
  	}
  	i++;i++;
  	hledame = temp[i];
  	while(temp[i]){
  		if(temp[i]==hledame)mame++;
  		i++;
  	}
  	if((mame<=x2)&&(mame>=x1))pocetSpravne++;
  	else pocetSpatne++;
  }
}

