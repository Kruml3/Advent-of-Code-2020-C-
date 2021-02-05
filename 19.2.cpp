#include "bits/stdc++.h"
using namespace std;
string temp;
long long result = 0;
int * cisla[136];
string rege="";
int pos=0;
int pocetPravidel = 0;
string *pokusy[10];
void pridej(int pravidlo){
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
        if(pravidlo==11)pridej(cisla[j][5]);
        rege+=")";
    }
    return;
}
void vytvorPravidla(int l){
    pridej(l);
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
    for(int i=0;i<10;i++){
        pokusy[i]=new string[10];
    }
    for(int i=0;i<136;i++){
        cisla[i]=new int[6];
        for(int j=0;j<6;j++){
            cisla[i][j]=0;
        }
    }   
    cout << "halo1" << endl;
	ifstream infile("input19.txt");
    int line=0;
	while(getline(infile,temp)){
        if(temp == "")break;
        pos = 0;
        for(int i=0;i<6;i++){
            cisla[line][i]=nactiint(temp,pos);
        }
        line++;
	}
    cout <<"halo2" <<endl;
    for(int i=2;i<20;i++){
        for(int j=1;j<i;j++){
            rege="";
            for(int k=0;k<i;k++){
                pridej(42);
            }
            for(int k=0;k<j;k++){
                pridej(31);
            }
            regex jnn(rege);
            ifstream infile("input19.txt");
            while(getline(infile,temp)){
                if(regex_match(temp,jnn))result++;
            }
        }
    }

	cout << "Part 2: " <<result << endl;
	return 0;
}