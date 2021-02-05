#include "bits/stdc++.h"
using namespace std;
string temp;
long long result = 0;
bool ** conway3[22];
bool ** novyconway3[22];
int zkontrolujSousedy(int x,int y,int z){
	int soucet=0;
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			for(int k=-1;k<2;k++){
				if((i==0)&&(j==0)&&(k==0))continue;
				if(conway3[x+i][y+j][z+k])soucet++;
			}
		}
	}
	return soucet;
}
int main(){
	for(int i=0;i<22;i++){
		novyconway3[i]= new bool*[22];
		conway3[i]= new bool*[22];
		for(int j=0;j<22;j++){
			conway3[i][j]= new bool[22];
			novyconway3[i][j]= new bool[22];
			for(int k=0;k<22;k++){
				conway3[i][j][k]=false;
				novyconway3[i][j][k]=false;
			}
		}
	}
	ifstream infile("input17.txt");
	int line=7;
	while(getline(infile,temp)){
		for(int i=0;i<8;i++){
			if(temp[i]=='#')conway3[i+7][line][11]=true;
		}
		line++;
	}
	for(int i=0;i<6;i++){
		for(int j=1;j<21;j++){
			for(int k=1;k<21;k++){
				for(int l=1;l<21;l++){
					if((conway3[j][k][l])&&((zkontrolujSousedy(j,k,l)<2)||(zkontrolujSousedy(j,k,l)>3)))novyconway3[j][k][l]=false;
					if((conway3[j][k][l])&&((zkontrolujSousedy(j,k,l)==2)||(zkontrolujSousedy(j,k,l)==3)))novyconway3[j][k][l]=true;
					if((!conway3[j][k][l])&&(zkontrolujSousedy(j,k,l)==3))novyconway3[j][k][l]=true;
					if((!conway3[j][k][l])&&(zkontrolujSousedy(j,k,l)!=3))novyconway3[j][k][l]=false;
				}
			}
		}
		for(int j=1;j<21;j++){
			if(i==0)cout << "z= " << j << endl;
			for(int k=1;k<21;k++){
				for(int l=1;l<21;l++){
					if(i==0)cout << novyconway3[l][k][j];
					conway3[j][k][l]=novyconway3[j][k][l];
				}
				if(i==0)cout <<endl;
			}
			if(i==0)cout <<endl;
		}
	}
	for(int j=0;j<22;j++){
			for(int k=0;k<22;k++){
				for(int l=0;l<22;l++){
					if(conway3[j][k][l])result++;
				}
			}
		}
	cout << "Part 1: " <<result << endl;
	return 0;
}