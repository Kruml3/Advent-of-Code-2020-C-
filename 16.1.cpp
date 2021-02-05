#include "bits/stdc++.h"
using namespace std;
string temp;
long long result;
long long cisla[1000];
int main(){
	for(int r=0;r<1000;r++){
		cisla[r]=0;
	}
	ifstream infile("input16.txt");
	int s=-1;
	int cislo;
	bool jedem=false;
	while(getline(infile,temp)){
		if(temp=="nearby tickets:"){
			s++;
			jedem=true;
			continue;
		}
		if(!jedem){s++;continue;}
		int i=0;
		s++;
		while(temp[i]){
			if(temp[i]==','){
				if((cislo<25)||(cislo>971)){
					result+=cislo;
					cout << s << endl;
					cislo=0;
					i++;
					continue;
				}
				cislo=0;i++;continue;
			}

			cislo*=10;
			cislo+=temp[i]-48;
			i++;
		}
		if((cislo<25)||(cislo>971)){
				result+=cislo;
				cislo=0;
				i++;
				continue;
		}
		cislo=0;

	}
	cout << "Part 1: " <<result << endl;
	return 0;
}