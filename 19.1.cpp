#include "bits/stdc++.h"
using namespace std;
string temp;
long long result = 0;
int * cisla[136];
string rege;
int pos=0;
int pocetPravidel = 0;
void pridej(int pravidlo){
    cout << pravidlo <<endl;
    bool hotovo=false;
    if(pravidlo==56){
        rege+="(a|b)";
        return;
    }
    if(pravidlo==54){
        rege+="a";
        return;
    }
    if(pravidlo==117){
        rege+="b";
        return;
    }
    if(pravidlo==11){
        rege+="11";
        return;
    }
    if(pravidlo==8){
        rege+="8";
        return;
    }
    if(pravidlo==-1)return;
    int j=0;
    while(cisla[j][0]!=pravidlo)j++;
    if(cisla[j][3]!=-1)rege+="(";
    pridej(cisla[j][1]);
    pridej(cisla[j][2]);
    if(cisla[j][3]!=-1){
        rege+="|";
        pridej(cisla[j][3]);
        pridej(cisla[j][4]);
        rege+=")";
    }
    return;
}
void vytvorPravidla(){
    cout << "halo2.1" << endl;
    pridej(0);
    cout << "halo2.2" <<endl;
    return;
}
int nactiint(string str,int pozice){
    if(pozice>str.size())return -1;
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
    pos=str.size();
    if(zacatek)return res;
    return -1;
}
int main(){
    for(int i=0;i<136;i++){
        cisla[i]=new int[5];
        for(int j=0;j<5;j++){
            cisla[i][j]=0;
        }
    }   
    cout << "halo1" << endl;
	ifstream infile("input19.txt");
    int line=0;
	while(getline(infile,temp)){
        if(temp == "")break;
        pos = 0;
        for(int i=0;i<5;i++){
            cisla[line][i]=nactiint(temp,pos);
        }
        line++;
	}
    cout <<"halo2" <<endl;
    vytvorPravidla();
    cout <<"halo3" <<endl;
    regex jn(rege);
    cout << rege <<endl;
    while(getline(infile,temp)){
        if(regex_match(temp,jn))result++;
    }
	cout << "Part 1: " <<result << endl;
	return 0;
}