#include "bits/stdc++.h"
using namespace std;
string temp;
long long result = 0;
bool *** conway4[22];
bool *** novyconway4[22];
int zkontrolujSousedy(int x,int y,int z,int w){
	int soucet=0;
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			for(int k=-1;k<2;k++){
				for(int l=-1;l<2;l++){
					if((i==0)&&(j==0)&&(k==0)&&(l==0))continue;
					if(conway4[x+i][y+j][z+k][w+l])soucet++;
				}
			}
		}
	}
	return soucet;
}
int main(){
	for(int i=0;i<22;i++){
		novyconway4[i]= new bool**[22];
		conway4[i]= new bool**[22];
		for(int j=0;j<22;j++){
			conway4[i][j]= new bool*[22];
			novyconway4[i][j]= new bool*[22];
			for(int k=0;k<22;k++){
				conway4[i][j][k]=new bool[22];
				novyconway4[i][j][k]=new bool[22];
				for(int l=0;l<22;l++){
					conway4[i][j][k][l]=false;
					novyconway4[i][j][k][l]=false;
				}
			}
		}
	}
	ifstream infile("input17.txt");
	int line=7;
	while(getline(infile,temp)){
		for(int i=0;i<8;i++){
			if(temp[i]=='#')conway4[i+7][line][11][11]=true;
		}
		line++;
	}
	for(int i=0;i<6;i++){
		for(int j=1;j<21;j++){
			for(int k=1;k<21;k++){
				for(int l=1;l<21;l++){
					for(int m=1;m<21;m++){
						if((conway4[j][k][l][m])&&((zkontrolujSousedy(j,k,l,m)<2)||(zkontrolujSousedy(j,k,l,m)>3)))novyconway4[j][k][l][m]=false;
						if((conway4[j][k][l][m])&&((zkontrolujSousedy(j,k,l,m)==2)||(zkontrolujSousedy(j,k,l,m)==3)))novyconway4[j][k][l][m]=true;
						if((!conway4[j][k][l][m])&&(zkontrolujSousedy(j,k,l,m)==3))novyconway4[j][k][l][m]=true;
						if((!conway4[j][k][l][m])&&(zkontrolujSousedy(j,k,l,m)!=3))novyconway4[j][k][l][m]=false;
					}
				}
			}
		}
		for(int j=1;j<21;j++){
			for(int k=1;k<21;k++){
				for(int l=1;l<21;l++){
					for(int m=1;m<21;m++){
					conway4[j][k][l][m]=novyconway4[j][k][l][m];
					}
				}
			}
		}
	}
	for(int j=0;j<22;j++){
		for(int k=0;k<22;k++){
			for(int l=0;l<22;l++){
				for(int m=0;m<22;m++){
					if(conway4[j][k][l][m])result++;
				}
			}
		}
	}
	cout << "Part 1: " <<result << endl;
	return 0;
}