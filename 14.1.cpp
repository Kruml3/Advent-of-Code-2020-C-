#include "bits/stdc++.h"
using namespace std;
string temp;
long long result;
int maska[36];
bool cislo[100000][36];
long long max36 = 2;
int main(){
	for(int i=0;i<34;i++)max36*=2;
	for(int k=0;k<1000;k++){
		for(int i=0;i<36;i++)cislo[k][i]=false;
	}
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
			long long hodnota=0;
			while(temp[i]!='=')i++;
			i+=2;
			while(temp[i]){
				hodnota*=10;
				hodnota+=temp[i]-48;
				i++;
			}
			long long maxx=max36;
			for(int j=0;j<36;j++){
				if(hodnota>=maxx){
					cislo[adresa][j]=true;hodnota-=maxx;
				}
				else cislo[adresa][j]=false;
				maxx/=2;
			}
			for(int j=0;j<36;j++){
				if(maska[j]==1)cislo[adresa][j]=true;
				if(maska[j]==0)cislo[adresa][j]=false;
			}
		}
		
		
	}
	for(int k=0;k<100000;k++){
		long long maxx=max36;
		for(int j=0;j<36;j++){
			if(maska[j]=='1')cislo[k][j]=true;
			if(maska[j]=='0')cislo[k][j]=false;
			if(cislo[k][j]){
				result+=maxx;
			}
			maxx/=2;
		}
	}
	cout << "Part 1: " <<result << endl;
	return 0;
}