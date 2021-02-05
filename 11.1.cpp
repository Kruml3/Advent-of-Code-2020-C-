#include "bits/stdc++.h"
using namespace std;
string temp;
long long result = 10;
long long newResult = 0;
const int N = 98;
int sedadla[N][N];
int novaSedadla[N][N];
int adjacent =0;
void iterace(int sedadla[N][N],int nova[N][N]){
	result = newResult;
	newResult=0;
	for(int j=0;j<N;j++){
		for(int k=0;k<N;k++){
			nova[j][k]=sedadla[j][k];
			adjacent = 0;
			if((j!=0)&&(k!=0))if(sedadla[j-1][k-1]==1)adjacent++;
			if(j!=0)if(sedadla[j-1][k]==1)adjacent++;
			if((j!=0)&&(k!=N-1))if(sedadla[j-1][k+1]==1)adjacent++;
			if(k!=0)if(sedadla[j][k-1]==1)adjacent++;
			if(k!=N-1)if(sedadla[j][k+1]==1)adjacent++;
			if((j!=N-1)&&(k!=0))if(sedadla[j+1][k-1]==1)adjacent++;
			if(j!=N-1)if(sedadla[j+1][k]==1)adjacent++;
			if((j!=N-1)&&(k!=N-1))if(sedadla[j+1][k+1]==1)adjacent++;
			if((sedadla[j][k]==1)&&(adjacent>=4)){nova[j][k]=0;}
			if((sedadla[j][k]==0)&&(adjacent==0)){nova[j][k]=1;}
			if(sedadla[j][k]==2)nova[j][k]=2;
		}
	}
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				sedadla[j][k]=nova[j][k];
				if(nova[j][k]==1)newResult++;
			}
		}

}
int main(){
	ifstream infile("input11.txt");
	int s=0;
	while(getline(infile,temp)){
		for(int i=0;i<N;i++){
			switch(temp[i]){
				case '.':sedadla[s][i]=2;break;
				case '#':sedadla[s][i]=1;break;
				case 'L':sedadla[s][i]=0;break;
			}
		}
		s++;
	}
	while(result!=newResult){
		iterace(sedadla,novaSedadla);
	}

	cout << endl << "Part 1: " << result <<endl;
	return 0;
}