#include "bits/stdc++.h"
using namespace std;
string temp;
long long cisla[1000];
long long indexy[2] = {0,0};
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
	long long j0=0;
	bool dvacetpet = false;
	for(int j=25;j<1000;j++){
		dvacetpet=false;
		for(int k=j-24;k<j;k++){
			for(int l=j-25;l<k;l++){
				if(cisla[j]==cisla[k]+cisla[l])dvacetpet=true;
			}
		}
		if(!dvacetpet){cout << "Part 1: " << cisla[j] << endl;j0=cisla[j];}
	}
	for(int j=0;j<1000;j++){
		long long soucet = cisla[j];
		for(int k=j+1;cisla[k]+soucet<=j0;k++){
			soucet+=cisla[k];
				if(soucet==j0){
					indexy[0]=j;
					indexy[1]=k;
					break;
				}
			
		}
		if (indexy[0]!=0)break;
	}
	long long max = 0;
	long long min = 25918798;
	for(int l=indexy[0];l<indexy[1];l++){
		if(cisla[l]<min)min=cisla[l];
		if(cisla[l]>max)max=cisla[l];
	}
	cout << "Part 2: " << min+max << endl;
	return 0;
}