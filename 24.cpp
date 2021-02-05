#include "bits/stdc++.h"
using namespace std;
string temp;
int result=0;
bool *cernehexy[1000];
bool *novecernehexy[1000];

int main(){
	for(int i=0;i<1000;i++){
		cernehexy [i] = new bool[1000];
		novecernehexy [i] = new bool[1000];
		for(int j=0;j<1000;j++){
			novecernehexy[i][j] = false;
			cernehexy[i][j] = false;
		}
	}
	ifstream infile("input24.txt");
	while(getline(infile,temp)){
		int pocetSmeru=0;
		int znak=0;
		int hexi=500;
		int hexj=500;
		while(temp[znak]){
			switch(temp[znak]){
				case 'n': hexi--; if(temp[znak+1]=='e')	hexj--; else hexj++;znak+=2;pocetSmeru++;break;
				case 's': hexi++; if(temp[znak+1]=='e')hexj--; else hexj++;znak+=2;pocetSmeru++;break;
				case 'e': hexj-=2;pocetSmeru++;znak++;break;
				case 'w': hexj+=2;pocetSmeru++;znak++;break;
				default : pocetSmeru++;
			}
		}
		//cout << hexi << " " << hexj <<endl;
		if(cernehexy[hexi][hexj]==false){novecernehexy[hexi][hexj]=true;cernehexy[hexi][hexj]=true;continue;}
		cernehexy[hexi][hexj]=false;
	}
	int dayResult = 0;
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			if(cernehexy[i][j])dayResult++;
		}
	}
	cout <<dayResult <<endl;
	int odebrane;
	int pridane;
	for(int i=0;i<100;i++){
		cout << "Den " << i <<": " << odebrane << " " << pridane<<endl;
		odebrane=0;
		pridane=0;
		for(int j=0;j<1000;j++){
			for(int k=0;k<1000;k++){
				int adjacent=0;
				if((j>1)&&(k>1))if(cernehexy[j-1][k-1])adjacent++;
				if((j>1)&&(k<998))if(cernehexy[j-1][k+1])adjacent++;
				if((j<998)&&(k>1))if(cernehexy[j+1][k-1])adjacent++;
				if((j<998)&&(k<998))if(cernehexy[j+1][k+1])adjacent++;
				if(k>1)if(cernehexy[j][k-2])adjacent++;
				if(k<998)if(cernehexy[j][k+2])adjacent++;
				if((adjacent==0)&&(cernehexy[j][k])){novecernehexy[j][k]=false;dayResult--;odebrane++;}
				if((adjacent>0)&&(adjacent<3)&&(cernehexy[j][k])){novecernehexy[j][k]=true;}
				if((adjacent==2)&&(!cernehexy[j][k])){novecernehexy[j][k]=true;dayResult++;pridane++;}
				if((adjacent!=2)&&(!cernehexy[j][k])){novecernehexy[j][k]=false;}
				if((adjacent>2)&&(cernehexy[j][k])){novecernehexy[j][k]=false;dayResult--;odebrane++;}
			}
		}
		for(int j=0;j<1000;j++){
			for(int k=0;k<1000;k++){
				cernehexy[j][k]=novecernehexy[j][k];
			}
		}
		/*int dayResult=0;
		int ripResult=0;
		for(int i=0;i<1000;i++){
			for(int j=0;j<1000;j++){
				if(novecernehexy[i][j])ripResult++;
				if(cernehexy[i][j])dayResult++;
			}
		}*/
		cout << dayResult <<endl;
	}
	
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			if(cernehexy[i][j])result++;
		}
	}
	cout << "Part1: "<< result << endl;
	return 0;
}