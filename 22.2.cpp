#include "bits/stdc++.h"
using namespace std;
string temp;
int result = 0;
const int N = 25;
int pocetTahu[N];
int hrac1[2*N];
int *saving1 [N];
int **kontrola1 [N];
int karty1=N;
int savingkarty1[N];
int hrac2[2*N];
int *saving2 [N];
int **kontrola2 [N];
int karty2=N;
int savingkarty2[N];
int hloubka=0;
int pocetLoopu=0;

int boj();
void souboj(){
    /*if(hloubka==3){
    for(int i=0;i<karty1;i++){
        cout << hrac1[i] << " ";
    }
    cout << endl;
    for(int i=0;i<karty2;i++){
        cout << hrac2[i] << " ";
    }
    cout << endl;
    }*/
    
    //cout << hrac1[0] << " " << hrac2[0] << " " << hloubka <<" " <<karty1 << " " << karty2 <<endl;
    for(int i=0;i<2*N;i++){
        if(i<karty1)kontrola1[hloubka][pocetTahu[hloubka]][i]=hrac1[i];
        else kontrola1[hloubka][pocetTahu[hloubka]][i]=0;
    }
    for(int i=0;i<2*N;i++){
        if(i<karty2)kontrola2[hloubka][pocetTahu[hloubka]][i]=hrac2[i];
        else kontrola2[hloubka][pocetTahu[hloubka]][i]=0;
    }
    if((hrac1[0]<karty1)&&(hrac2[0]<karty2)){
        /*for(int i=0;i<karty1;i++){
            cout << hrac1[i] << " "; 
        }
        cout <<endl;
        for(int i=0;i<karty2;i++){
            cout << hrac2[i] << " "; 
        }
        cout <<endl;
        cout << karty1 << " " << karty2 <<endl;*/
        savingkarty1[hloubka]=karty1;
        savingkarty2[hloubka]=karty2;
        for(int i=0;i<karty1;i++){
            saving1[hloubka][i]=hrac1[i];
        }
        for(int i=0;i<karty2;i++){
            saving2[hloubka][i]=hrac2[i];
        }
        karty1 = hrac1[0];
        for(int i=0;i<karty1;i++){
            hrac1[i]=hrac1[i+1];
        }
        karty2 = hrac2[0];
        for(int i=0;i<karty2;i++){
            hrac2[i]=hrac2[i+1];
        }
        //cout << "karty " << karty1 <<" " << karty2<< endl;
        /*cout <<endl << "boj " <<hloubka << ": ";
        for(int i=0;i<karty1;i++){
            cout << hrac1[i] << " "; 
        }
        cout <<endl << "boj " <<hloubka << ": ";
        for(int i=0;i<karty2;i++){
            cout << hrac2[i] << " "; 
        }
        cout <<endl;*/
        hloubka++;
        //cout << "novaHloubka: " << hloubka <<endl;
        int vitez = boj();
        hloubka--;
        //cout << "novaHloubka: " << hloubka <<endl;
        if(vitez==0)pocetLoopu++;
        if((vitez==1)||(vitez==0)){
            saving1[hloubka][savingkarty1[hloubka]]=saving1[hloubka][0];
            saving1[hloubka][savingkarty1[hloubka]+1]=saving2[hloubka][0];
            savingkarty2[hloubka]--;
            savingkarty1[hloubka]++;
        }
        if(vitez==2){
            saving2[hloubka][savingkarty2[hloubka]]=saving2[hloubka][0];
            saving2[hloubka][savingkarty2[hloubka]+1]=saving1[hloubka][0];
            savingkarty2[hloubka]++;
            savingkarty1[hloubka]--;
        }
        for(int i=0;i<savingkarty1[hloubka];i++){
            hrac1[i]=saving1[hloubka][i+1];
        }
        for(int i=0;i<savingkarty2[hloubka];i++){
            //cout << "ripp: " <<saving2[hloubka][i+1] <<endl;
            hrac2[i]=saving2[hloubka][i+1];
        }
        karty1=savingkarty1[hloubka];
        karty2=savingkarty2[hloubka];
        /*cout <<endl << "boj " <<hloubka << ": ";
        for(int i=0;i<karty1;i++){
            cout << hrac1[i] << " "; 
        }
        cout <<endl << "boj " <<hloubka << ": ";
        for(int i=0;i<karty2;i++){
            cout << hrac2[i] << " "; 
        }
        cout <<endl;*/
        return;

    }
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
int boj(){
    pocetTahu[hloubka]=0;
    while(true){
        //cout << "pocet tahu: " << pocetTahu[hloubka] <<endl;
        if(pocetTahu[hloubka]>10000)return 0;
        souboj();
        bool kon1=false;
        bool kon2=false;
        for(int i=0;i<pocetTahu[hloubka];i++){
            bool konp1=true;
            bool konp2=true;
            for(int j=0;j<2*N;j++){
                if(kontrola1[hloubka][i][j]!=kontrola1[hloubka][pocetTahu[hloubka]][j]){
                    konp1=false;
                    break;
                }
            }
            if(konp1){
                kon1=true;
                break;
            }
        }
        for(int i=0;i<pocetTahu[hloubka];i++){
            bool konp2=true;
            for(int j=0;j<2*N;j++){
                if(kontrola2[hloubka][i][j]!=kontrola2[hloubka][pocetTahu[hloubka]][j]){
                    konp2=false;
                    break;
                }
            }
            if(konp2){
                kon2=true;
                break;
            }
        }
        pocetTahu[hloubka]++;
        //if(hloubka==3)cout << "kontrola: " <<kon1 <<" " << kon2 <<endl;
        //cout << "karty: " << karty1 << " " << karty2 <<endl;
        //cout << j << " "<< karty1 << " " <<karty2 <<endl;
        if(karty2==0){
            //cout << "vyhral_1" <<endl;
            return 1;
        }
        if(karty1==0){
            //cout <<"vyhral_2" <<endl;
            return 2;
        }
        if((kon1==true)&&(kon2==true)){
            //cout << "loop" << endl;
            pocetLoopu++;
            return 1;
        }
    }
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
    for(int i=0;i<N;i++){
        saving1[i]=new int[2*N];
        saving2[i]=new int[2*N];
        kontrola1[i]=new int*[50000];
        kontrola2[i]=new int*[50000];
        for(int j=0;j<50000;j++){
            kontrola1[i][j]=new int[2*N];
            kontrola2[i][j]=new int[2*N];
        }
    }
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
    /*for(int i=0;i<N;i++){
        cout << hrac1[i] <<" " << hrac2[i] <<endl;
    }*/
    int konec = boj();
    cout << endl;
    cout << "konec hry" <<endl;
    if((konec==1)||(konec==0))
    for(int i=0;i<karty1;i++){
        //cout << karty1-i << " " << hrac1[i] << " " << result << endl;
        result+=(karty1-i)*hrac1[i];
    
    }
    if(konec==2)
    for(int i=0;i<karty2;i++){
        //cout << karty2-i << " " << hrac2[i] << " " << result << endl;
        result+=(karty2-i)*hrac2[i];
    
    }
    cout << "pocetLoopu: " <<pocetLoopu << endl;
	cout << "Part 2: " <<result << endl;
	return 0;
}