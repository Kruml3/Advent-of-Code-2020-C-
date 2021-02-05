#include "bits/stdc++.h"
using namespace std;
string temp;
int result = 0;
const int N = 5;
int hrac1[2*N];
int karty1=N;
int hrac2[2*N];
int karty2=N;
bool vyhral_1=false;
bool vyhral_2=false;
void souboj(){
    cout << hrac1[0] << " " << hrac2[0] <<endl;
    if(hrac1[0]>hrac2[0]){
        hrac1[karty1]=hrac1[0];
        karty1++;
        karty2--;
        hrac1[karty1]=hrac2[0];
    }
    if(hrac2[0]>hrac1[0]){
        hrac2[karty2]=hrac2[0];
        karty2++;
        karty1--;
        hrac2[karty2]=hrac1[0];
    }
    for(int i=0;i<karty1;i++){
        hrac1[i]=hrac1[i+1];
    }
    for(int i=0;i<karty2;i++){
        hrac2[i]=hrac2[i+1];
    }
}
void boj(){
    cout <<endl;
    while(true){
        int j=0;
        souboj();
        //cout << j << " "<< karty1 << " " <<karty2 <<endl;
        if(karty1==2*N){
            cout << "vyhral1" <<endl;
            vyhral_1=true;
            vyhral_2=false;
            break;
        }
        if(karty2==2*N){
            cout <<"vyhral2" <<endl;
            vyhral_2=true;
            vyhral_1=false;
            break;
        }
        j++;
    }
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
            pozice=i;
            return res;
        }
    }
    pozice=str.size();
    if(zacatek)return res;
    return -1;
}
int main(){
    ifstream infile("input22.txt");
    int line=0;
    getline(infile,temp);
    while(getline(infile,temp)){
        if(temp=="")break;
        hrac1[line]=nactiint(temp,0);
        line++;
    }
    line=0;
    getline(infile,temp);
    while(getline(infile,temp)){
        hrac2[line]=nactiint(temp,0);
        line++;
    }
    for(int i=0;i<N;i++){
        cout << hrac1[i] <<" " << hrac2[i] <<endl;
    }
    vyhral_1=false;
    vyhral_2=false;
    boj();
    cout << endl;
    for(int i=0;i<2*N;i++){
        if(vyhral_1==true){
            cout << 2*N-i << " " << hrac1[i] << " " << result << endl;
            result+=(2*N-i)*hrac1[i];
        }
        if(vyhral_2==true){
            cout << 2*N-i << " " << hrac2[i] << " " << result << endl;
            result+=(2*N-i)*hrac2[i];
        }
    }
	cout << "Part 1: " <<result << endl;
	return 0;
}