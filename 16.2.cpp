#include "bits/stdc++.h"
using namespace std;
string temp;
int pos = 0;
long long result = 1;
const int N = 20;
int * limity[N];
int mojecisla[N];
int cisla[N];
bool * kombinace[N];

int nactiint(string str,int pozice){
	bool zacatek = false;
	int res = 0;
	for(int i=pozice;str[i];i++){
		if((str[i]>=48)&&(str[i]<=57)){
			zacatek=true;
			res*=10;
			res+=str[i]-48;
			continue;
		}
		if(zacatek){
			pos=i;
			return res;
		}
	}
	return res;
}

int main(){
	for(int r=0;r<N;r++){
		limity[r]= new int[4];
		for(int s=0;s<4;s++){
			limity[r][s]=0;
		}
		kombinace[r]= new bool[N];
		for(int s=0;s<N;s++){
			kombinace[r][s]=true;
		}
		cisla[r]=0;
	}
	ifstream infile("input16.txt");
	int line=0;
	while(getline(infile,temp)){
		if(line<N){
			pos=0;
			for(int j=0;j<4;j++){
				limity[line][j] = nactiint(temp,pos);
			}
		cout <<endl;
		}
		if(line==N+2){
			pos=0;
			for(int j=0;j<N;j++){
				mojecisla[j] = nactiint(temp,pos);
			}
		}
		bool dalsi = false;
		if(line>N+4){
			pos=0;
			for(int j=0;j<N;j++){
				int z = nactiint(temp,pos);
				if((z<25)||(z>971)){
					dalsi=true;
				}
			}
			if(!dalsi){
				pos=0;
				cout << "halo" <<endl;
				for(int j=0;j<N;j++){
					int z = nactiint(temp,pos);
					cout << z << " ";
					for(int k=0;k<N;k++){
						if((z<limity[k][0])||((z>limity[k][1])&&(z<limity[k][2]))||(z>limity[k][3]))kombinace[k][j]=false;
					}
				}
			}
		}
		line++;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << kombinace[i][j]; 
		}
		cout <<endl;
	}
	for(int l=0;l<N-1;l++){
		for(int i=0;i<N;i++){
			int soucet=0;
			int index=0;
			for(int j=0;j<N;j++){
				soucet+=kombinace[i][j]; 
				if(kombinace[i][j])index=j;
			}
			if(soucet==1){
				for(int j=0;j<N;j++){
					kombinace[j][index]=false;
				}
				if(i<6)result*=mojecisla[index];
			}
		}
	}
	cout << "Part 2: " <<result << endl;
	return 0;
}