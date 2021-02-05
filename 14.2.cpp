#include "bits/stdc++.h"
using namespace std;
string temp;
long long result;
int maska[36];
long long cislo;
long long cisla[1000000];
long long adresy[1000000];
bool adr[36];
long long max36 = 2;
int pocetAdres=0;
void zapisDoAdresy(long long cislo,long long adresa){
	int index;
	index=pocetAdres;
	pocetAdres++;
	for(int i=0;i<pocetAdres;i++){
		if(adresy[i]==adresa){
			index=i;
			pocetAdres--;
			break;
		}
	}
	adresy[index]=adresa;
	cisla[index]=cislo;
}
int main(){
	for(int i=0;i<34;i++)max36*=2;
	ifstream infile("input14.txt");
	int s=-1;
	while(getline(infile,temp)){
		if(temp[1]=='a'){
			for(int i=7;i<43;i++){
				if(temp[i]=='1')maska[i-7]=1;
				if(temp[i]=='0')maska[i-7]=0;
				if(temp[i]=='X')maska[i-7]=2;
			}
		}
		if(temp[1]=='e'){
			int adresa=0;
			int i=0;
			while(temp[i]!='[')i++;
			i++;
			while(temp[i]!=']'){
				adresa*=10;
				adresa+=temp[i]-48;
				i++;
			}
			cislo=0;
			while(temp[i]!='=')i++;
			i+=2;
			while(temp[i]){
				cislo*=10;
				cislo+=temp[i]-48;
				i++;
			}
			long long maxx=max36;
			for(int i=0;i<36;i++){
				if(adresa>=maxx){
					adr[i]=true;
					adresa-=maxx;
				}
				else adr[i]=false;
				maxx/=2;
			}
			maxx=max36;
			int floatingy=1;
			int pocetFloatingu=0;
			long long zakladniAdresa = 0;
			for(int i=0;i<36;i++){
				if((maska[i]==1)||((adr[i])&&(maska[i]==0))){
					zakladniAdresa+=maxx;
				}
				if(maska[i]==2){
					pocetFloatingu++;
					floatingy*=2;
				}
				maxx/=2;
			}
			int kdeSeFloatuje[pocetFloatingu];
			int r=0;
			for(int i=0;i<36;i++){
				if(maska[i]==2){
					kdeSeFloatuje[r]=i;
					r++;
				}
			}
			long long floatingAdresy[floatingy];
			floatingAdresy[0]=zakladniAdresa;
			int p=floatingy;
			int aktualniFloatingy=1;
			for(int i=0;i<pocetFloatingu;i++){
				maxx=max36;
				for(int j=0;j<kdeSeFloatuje[i];j++){
					maxx/=2;
				}
				for(int j=0;j<aktualniFloatingy;j++){
					floatingAdresy[j*p+p/2]=floatingAdresy[j*p]+maxx;
				}
				aktualniFloatingy*=2;
				p/=2;
			}

			for(int i=0;i<floatingy;i++){
				zapisDoAdresy(cislo,floatingAdresy[i]);
			}


		}
		
		
	}
	for(int k=0;k<pocetAdres;k++){
		result+=cisla[k];
	}
	cout << "Part 2: " <<result << endl;
	return 0;
}