#include "bits/stdc++.h"
using namespace std;
string temp;
string garbage;
long long result = 0;
int ingredientCount;
int allergenCount=0;
struct allergen{
	string name;
	string possible[100];
	int possibleCount = 0;
	int appearance = 0;
};/*
struct ingredient{
	string name;
	bool allergens[100];
	int possibleAllergens=0;
};*/
allergen allergens[100];

string nactistr(string str,int &pozice){
    if(pozice>str.size())return "";
    bool zacatek = false;
    string res = "";
    for(int i=pozice;str[i];i++){
        if((str[i]>=97)&&(str[i]<=122)){
            zacatek=true;
            res+=str[i];
            continue;
        }
        if(zacatek){
            pozice=i;
            return res;
        }
    }
    pozice=str.size();
    if(zacatek)return res;
    return "";
}
void reduce(int ikr, string jn,int &curr){
	cout << "halo 6: reduced boogaloo" <<endl;
	cout << allergens[ikr].name << endl;
	for(int i=0;i<allergens[ikr].possibleCount;i++){
		cout << allergens[ikr].possible[i] << " ";
	}
	cout << endl << jn <<endl;
	int pos3=0;
	int newCount=0;
	string newList[100];
	while(jn[pos3+1]!='('){
		string help=nactistr(jn,pos3);
		//cout << "help: " << help <<endl;
		for(int i=0;i<allergens[ikr].possibleCount;i++){
			//cout << allergens[ikr].possible[i] << " " <<help<<endl;
			if(allergens[ikr].possible[i]==help){
				//cout << "halo 9" <<endl;
				newList[newCount]=help;
				newCount++;
				break;
			} 
		}
	}
		allergens[ikr].possibleCount=newCount;
		for(int i=0;i<100;i++){
			//cout << "new: " << newList[i] << endl;
			allergens[ikr].possible[i]=newList[i];
		}
	curr++;
	cout << "new list: " << endl;
	for(int i=0;i<allergens[ikr].possibleCount;i++){
		cout << allergens[ikr].possible[i] << " ";
	}
	cout <<endl;
	return;
}
int main(){
	ifstream infile("input21.txt");
	while(getline(infile,temp)){
		int pos1=0;
		//cout << "halo 1" <<endl;
		while(temp[pos1]!='(')pos1++;
		garbage = nactistr(temp,pos1);
		//cout << "halo 2" <<endl;
			int currAllergens = 0;
		while(pos1<temp.size()-1){
			//cout << "halo 3" <<endl;
			string currName=nactistr(temp,pos1);
			//cout << currName <<endl;
			allergens[allergenCount].name=currName;
			allergens[allergenCount].appearance=1;
			allergenCount++;
			//cout << "halo 4" <<endl;
			bool done=false;
			for(int i=0;i<allergenCount-1;i++){
				//cout << i << "/"<<allergenCount-1 <<endl;
				if(allergenCount-i>1)
				if(currName==allergens[i].name){
					reduce(i,temp,currAllergens);
					allergenCount--;
					allergens[i].appearance++;
					done=true;
					break;
				}
			}
			int position=0;
			if(done)continue;
			while(temp[position+1]!='('){
				allergens[allergenCount-1].possible[allergens[allergenCount-1].possibleCount] =nactistr(temp,position);
				//cout << allergens[allergenCount-1].possible[allergens[allergenCount-1].possibleCount] <<endl;
				allergens[allergenCount-1].possibleCount++;
			}
			currAllergens++;
			//cout << endl << "halo 8" <<endl;
		
		

		}
	}
	ifstream infile2("input21.txt");
	for(int i=0;i<allergenCount;i++){
		cout << allergens[i].name << " ";
		for(int j=0;j<allergens[i].possibleCount;j++){
			cout << allergens[i].possible[j] <<" ";
		}
		cout << endl;
	}
	while(getline(infile2,temp)){
		int posi=0;
		while(temp[posi+1]!='('){
			bool pricti=true;
			string jj=nactistr(temp,posi);
			for(int i=0;i<allergenCount;i++){
				for(int j=0;j<allergens[i].possibleCount;j++){
					if(allergens[i].possible[j]==jj)pricti=false;
				}
			}
			if(pricti)result++;
		}
	}
	cout << "Part 1: " <<result << endl;
	return 0;
}