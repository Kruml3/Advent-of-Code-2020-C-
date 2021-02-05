#include "bits/stdc++.h"
using namespace std;
string temp;
long long cisla[1000];
int main(){
for(int r=0;r<1000;r++){
	cisla[r]=0;
}
	ifstream infile("input9.txt");
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
	bool dvacetpet = false;
	for(int j=25;j<1000;j++){
		dvacetpet=false;
		for(int k=j-24;k<j;k++){
			for(int l=j-25;l<k;l++){
				if(cisla[j]==cisla[k]+cisla[l])dvacetpet=true;
			}
		}
		if(!dvacetpet)cout << cisla[j];
	}
	return 0;
}