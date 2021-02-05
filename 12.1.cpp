#include "bits/stdc++.h"
using namespace std;
string temp;
int smer = 90;
int otoceni = 90;
int x = 0;
int y = 0;
void pohyb(int mod, int instrukce){
	int ins=instrukce;
	switch(mod){
		case 0:smer=90;break;
		case 1:smer=270;break;
		case 2:smer=0;break;
		case 3:smer=180;break;
		case 4:otoceni-=ins;smer=otoceni;ins=0;break;
		case 5:otoceni+=ins;smer=otoceni;ins=0;break;
		case 6:smer=otoceni;break;
	}
	while(smer>359)smer-=360;
	while(smer<0)smer+=360;
	switch(smer){
		case 0:y-=ins;break;
		case 90:x+=ins;break;
		case 180:y+=ins;break;
		case 270:x-=ins;break;
	}
	cout << x << " " << y << endl;
}
int main(){
	ifstream infile("input12.txt");
	while(getline(infile,temp)){
		int mod = 0;
		switch(temp[0]){
			case 'E':mod=0;break;
			case 'W':mod=1;break;
			case 'N':mod=2;break;
			case 'S':mod=3;break;
			case 'L':mod=4;break;
			case 'R':mod=5;break;
			case 'F':mod=6;break;
		}
		int instrukce=0;
		int i=1;
		while(temp[i]){
			instrukce*=10;
			instrukce+=temp[i]-48;
			i++;
		}
		pohyb(mod,instrukce);
	}
	int pomoc = x;
	if(x<0)x-=2*pomoc;pomoc=y;if(y<0)y-=2*pomoc;
	cout << endl << "Part 1: " << x+y <<endl;
	return 0;
}