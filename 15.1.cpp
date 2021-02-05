#include "bits/stdc++.h"
using namespace std;
string temp;
ofstream outfile("output.txt");
long long result;
const long N = 30000000;
long cisla[N];
long adresa[N];
int main(){
	for(int i=0;i<N;i++){
		cisla[i]=0;
		adresa[i]=-1;
	}
	cisla[0]=1;
	cisla[1]=12;
	cisla[2]=0;
	cisla[3]=20;
	cisla[4]=8;
	cisla[5]=16;
	adresa[0]=2;
	adresa[1]=0;
	adresa[8]=4;
	adresa[12]=1;
	adresa[16]=5;
	adresa[20]=3;
	int age=0;
	for(int j=6;j<N;j++){
		if(adresa[cisla[j-1]]==-1)age=0;
		else age=j-1-adresa[cisla[j-1]];
		adresa[cisla[j-1]]=j-1;
		cisla[j]=age;
	}
	cout << "Part 1: " <<cisla[2019] <<endl;
	cout << "Part 2: " <<cisla[N-1] << endl;
	return 0;
}