#include "bits/stdc++.h"
using namespace std;
string temp;
const int N = 1000000;
int cisloKelimku=0;
long cisloTahu=1;
int nacitani[9];
struct polozka{
	int cislo;
	polozka*dalsi;
	polozka*predchozi;
};
polozka seznam[N];

void tah(){

	/*for(int i=0;i<50;i++){
		cout << seznam[i].predchozi->cislo << "/" << seznam[i].cislo << "/" << seznam[i].dalsi->cislo << " ";
	}
	cout << endl;*/
	int destination=(seznam[cisloKelimku].cislo+N-2)%N+1;
	while((seznam[cisloKelimku].dalsi->cislo==destination)||(seznam[cisloKelimku].dalsi->dalsi->cislo==destination)||(seznam[cisloKelimku].dalsi->dalsi->dalsi->cislo==destination))destination=(destination+N-2)%N+1;
	
	/*if(cisloTahu<100){
		cout << "Tah: " << cisloTahu << ", cisloKelimku: " <<cisloKelimku<<endl;
		cout << " destination: " << destination <<endl;
	}*/
	if(cisloTahu%100000==0){
		cout << cisloTahu/100000 <<endl;
	}
	polozka * pom1 = seznam[cisloKelimku].dalsi;
	polozka * pom2 = seznam[cisloKelimku].dalsi->dalsi->dalsi;
	polozka * pom3 = seznam[destination-1].dalsi;
	seznam[cisloKelimku].dalsi=seznam[cisloKelimku].dalsi->dalsi->dalsi->dalsi;
	seznam[cisloKelimku].dalsi->predchozi=&seznam[cisloKelimku];
	seznam[destination-1].dalsi=pom1;
	pom1->predchozi=&seznam[destination-1];
	pom2->dalsi=pom3;
	pom3->predchozi=pom2;
	cisloKelimku=seznam[cisloKelimku].dalsi->cislo-1;
	//cout << seznam[cisloKelimku].predchozi->cislo << "/" << seznam[cisloKelimku].cislo << "/" <<seznam[cisloKelimku].dalsi->cislo << endl;
	cisloTahu++;
	
}
int main(){
	ifstream infile("input23.txt");
	getline(infile,temp);
	for(int i=0;i<N;i++){
		seznam[i].cislo=i+1;
		seznam[i].predchozi=&seznam[(i+N-1)%N];
		seznam[i].dalsi =&seznam[(i+1)%N];
	}
	for(int i=0;i<9;i++){
		nacitani[i]=temp[i]-48;
	}
	cisloKelimku=temp[0]-48;
	cisloKelimku=(cisloKelimku-2)%N+1;
	//cout << "cK: " <<cisloKelimku <<endl; 
	for(int i=0;i<9;i++){
		if(i<8){
			seznam[nacitani[i]-1].dalsi=&seznam[nacitani[i+1]-1];
		}
		if(i>0){
			seznam[nacitani[i]-1].predchozi=&seznam[nacitani[i-1]-1];
		}
	}
	seznam[N-1].dalsi=&seznam[nacitani[0]-1];
	seznam[nacitani[0]-1].predchozi=&seznam[N-1];
	seznam[nacitani[8]-1].dalsi=&seznam[9];
	seznam[9].predchozi=&seznam[nacitani[8]-1];
	/*for(int i=0;i<50;i++){
		cout << seznam[i].cislo << " ";
	}
	cout <<endl;*/
	for(long i=0;i<10000000;i++){
		tah();
		//for(int j=0;j<9;j++)cout << cisla[j];
		//cout <<endl;
	}
	long long result=1;
	result*=seznam[0].dalsi->cislo;
	cout <<seznam[0].dalsi->cislo <<endl;
	result*=seznam[0].dalsi->dalsi->cislo;
	cout <<seznam[0].dalsi->dalsi->cislo<<endl;
	cout << "Part2: "<< result << endl;
	return 0;
}