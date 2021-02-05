#include "bits/stdc++.h"
using namespace std;
string temp;
int result=0;
long long loop1=1;
long long loop2=1;
long long nacitani;
long long cislo1=0;
long long cislo2=0;
long long subject1=7;
long long subject2=7;
long long s1;
long long s2;
long long nactilong(string str,int pozice){
    if(pozice>str.size())return -1;
    bool zacatek = false;
    long long res = 0;
    for(int i=pozice;str[i];i++){
        if((str[i]>=48)&&(str[i]<=57)){
            zacatek=true;
            res*=10;
            res+=str[i]-48;
            continue;
        }
        if(zacatek){
            pozice=i;
            return res;
        }
    }
    pozice=str.size();
    if(zacatek)return res;
    return -1;
}
int main(){
	ifstream infile("input25.txt");
	getline(infile,temp);
	nacitani=nactilong(temp,0);
	cislo1=nacitani;
	getline(infile,temp);
	nacitani=nactilong(temp,0);
	cislo2=nacitani;
	while(subject1!=cislo1){
		subject1*=7;
		subject1=subject1%20201227;
		loop1++;
	}while(subject2!=cislo2){
		subject2*=7;
		subject2=subject2%20201227;
		loop2++;
	}
	s1=cislo1;
	s2=cislo2;
	cout << loop1 <<" " << loop2 <<endl;
	for(int i=0;i<loop1-1;i++){
		cislo2*=s2;
		cislo2=cislo2%20201227;
	}
	for(int i=0;i<loop2-1;i++){
		cislo1*=s1;
		cislo1=cislo1%20201227;
	}
	cout << cislo1 << " " <<cislo2 << endl;
	return 0;
}