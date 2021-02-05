#include "bits/stdc++.h"
using namespace std;
string temp;
long long cisla[1000];
int main(){
	int jolts=0;
	int jednicky=0;
	int trojky=0;
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
	while(true){
		bool tri=false;
		bool dva = false;
		bool jedna = false;

		for(int i=0;i<94;i++){
			if(cisla[i]-1==jolts){
				jolts+=1;
				jednicky++;
				jedna=true;
				break;
			}
		}
		if(jedna)continue;

		for(int i=0;i<94;i++){
			if(cisla[i]-2==jolts){
				jolts+=2;
				dva=true;
				break;
			}
		}
		if(dva)continue;
		
		for(int i=0;i<94;i++){
			if(cisla[i]-3==jolts){
				jolts+=3;
				trojky++;
				tri=true;
				break;
			}
		}
		if(!tri)break;
	}
	trojky++;
	cout << jednicky << " " << trojky << endl;
	cout << "Part 1: " << trojky*jednicky <<endl;
	return 0;
}