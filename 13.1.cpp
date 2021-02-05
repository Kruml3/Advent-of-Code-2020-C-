#include "bits/stdc++.h"
using namespace std;
string temp;
long long result;
long long cisla[1000];
int main(){
	for(int r=0;r<1000;r++){
		cisla[r]=0;
	}
	ifstream infile("input13.txt");
	int s=-1;
	while(getline(infile,temp)){
		int i=0;
		s++;
		while(temp[i]){
			if(temp[i]=='x'){i++;s--;continue;}
			if(temp[i]==','){i++;s++;continue;}
			cisla[s]*=10;
			cisla[s]+=temp[i]-48;
			i++;
		}

	}
	for(int j=1;j<=s;j++){
		cout << cisla[j] << " ";
	}
	cout << endl;
	int min = 5000;
	int kde = 0;
	for(int j=1;j<=s;j++){
		if(cisla[j]-cisla[0]%cisla[j]<min){min=cisla[j]-cisla[0]%cisla[j];kde=j;}
	}
	cout << "min " << 17-1008832%17 <<endl;
	result = min*cisla[kde];
	cout << "Part 1: " <<result << endl;
	return 0;
}