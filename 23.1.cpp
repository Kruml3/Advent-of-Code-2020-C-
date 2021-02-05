#include "bits/stdc++.h"
using namespace std;
string temp;
int cisla[9];
int cisloKelimku=0;
int cisloTahu=1;
void tah(){
	cout << "Tah: " << cisloTahu << ", cisloKelimku: " <<cisloKelimku<<endl;
	int destination=(cisla[cisloKelimku]+7)%9+1;
	int index=(cisloKelimku+4)%9;
	if(cisla[index]==destination)cout << "cisla = destination = " << destination <<endl;
	while(cisla[index]!=destination){
		if(cisloTahu==10)cout << "cisloKelimku: " << cisloKelimku<< endl;
		if(cisloTahu==10)cout <<"index: " << index << " destination: " << destination << endl;
		if(index==(cisloKelimku+8)%9){
			index=(cisloKelimku+3)%9;
			destination=(destination+7)%9+1;
		}
		index=(index+1)%9;
	}
	int pom1=cisla[(cisloKelimku+1)%9];
	int pom2=cisla[(cisloKelimku+2)%9];
	int pom3=cisla[(cisloKelimku+3)%9];
	int stehovani=cisloKelimku+1;
	while((stehovani+3)%9!=index){
		if(cisloTahu==10)cout << "stehovani: " << stehovani << " index: " <<index <<endl;
		cisla[stehovani%9]=cisla[(stehovani+3)%9];
		stehovani=(stehovani+1)%9;
	}
	cisla[stehovani%9]=cisla[(stehovani+3)%9];
	cisla[(stehovani+1)%9]=pom1;
	cisla[(stehovani+2)%9]=pom2;
	cisla[(stehovani+3)%9]=pom3;

	cisloKelimku=(cisloKelimku+1)%9;
	cisloTahu++;
}
int main(){
	ifstream infile("input23.txt");
	getline(infile,temp);
	for(int i=0;i<9;i++){
		cisla[i]=temp[i]-48;
	}
	for(int j=0;j<9;j++)cout << cisla[j];
		cout << endl;
	for(int i=0;i<100;i++){
		tah();
		for(int j=0;j<9;j++)cout << cisla[j];
		cout <<endl;
	}
	cout << "Part1: ";
	int j=0;while(cisla[j]!=1)j++;
	for(int k=1;k<9;k++)cout << cisla[(j+k)%9];
		cout << endl;
	return 0;
}