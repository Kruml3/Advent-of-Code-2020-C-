#include "bits/stdc++.h"
using namespace std;
string temp;
long long result;
long long cisla[1000];
int N=10;
int mezery[10] = {0,0,13,23,41,42,52,54,60,71};
void rekurze(long long modulo,long long zbytek,int dalsiCislo, int jehoZbytek, int krok){
	if(krok==N)return;
	int dc;int jm;
	if(krok<N)dc=cisla[krok+1];jm=mezery[krok+1];
	for(int j=0;j<dalsiCislo;j++){
		if(dalsiCislo-((j*modulo+zbytek)%dalsiCislo) == jehoZbytek%dalsiCislo){
			result = j*modulo+zbytek;
			rekurze(modulo*dalsiCislo,j*modulo+zbytek,dc,jm,krok+1);
			return;
	}}}
int main(){
	ifstream infile("input13.txt");
	int s=-1;
	while(getline(infile,temp)){
		int i=0;s++;
		while(temp[i]){
			if(temp[i]=='x'){i++;s--;continue;}
			if(temp[i]==','){i++;s++;continue;}
			cisla[s]*=10;cisla[s]+=temp[i]-48;i++;
	}}
	rekurze(cisla[1],mezery[1],cisla[2],mezery[2],2);
	cout << "Part 2: " <<result << endl;
	return 0;
}