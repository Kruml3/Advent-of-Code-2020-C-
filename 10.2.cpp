#include "bits/stdc++.h"
using namespace std;
string temp;
long long result = 1;
long long cisla[1000];
int main(){
	int jolts=0;
	int jednicky=0;
	int trojky=0;
	int diff[94];
	for(int r=0;r<1000;r++){
		cisla[r]=0;
	}
	ifstream infile("input10.txt");
	int s=0;
	while(getline(infile,temp)){
		int i=0;
		while(temp[i]){
			cisla[s]*=10;
			cisla[s]+=temp[i]-48;
			i++;
		}
		s++;
	}
	int diffIndex=0;
	int pocetjednicek[50];
	for(int i=0;i<50;i++){
		pocetjednicek[i]=0;
	}
		int skupina = 0;
	while(true){
		bool tri=false;
		bool dva = false;
		bool jedna = false;
		for(int i=0;i<94;i++){
			if(cisla[i]-1==jolts){
				jolts+=1;
				diff[diffIndex]=1;
				diffIndex++;
				jedna=true;
				pocetjednicek[skupina]++;
				break;
			}
		}
		if(jedna)continue;

		for(int i=0;i<94;i++){
			if(cisla[i]-2==jolts){
				jolts+=2;
				diff[diffIndex]=2;
				diffIndex++;
				dva=true;
				skupina++;
				break;
			}
		}
		if(dva)continue;
		for(int i=0;i<94;i++){
			if(cisla[i]-3==jolts){
				jolts+=3;
				diff[diffIndex]=3;
				diffIndex++;
				tri=true;
				skupina++;
				break;
			}
		}
		if(!tri)break;
	}
	for(int j=0;j<=skupina;j++){
		switch(pocetjednicek[j]){
			case 2: result*=2;
					break;
			case 3: result*=4;
					break;
			case 4: result*=7;
					break; 
		}
	}
	cout << endl << "Part 2: " << result <<endl;
	return 0;
}