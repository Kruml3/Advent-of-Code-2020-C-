#include "bits/stdc++.h"
using namespace std;
string temp;
long long result = 1;
int pos=0;
int pocetIteraci=0;
const int N = 144;
const int sqrN = 12;
bool zarazene[N];
bool hotovo;
struct tile{
int x;
int y;
int N;
int E;
int S;
int W;
int ID;
};
tile hranice[N];
void otocTile(int r){
    int pom=hranice[r].N;
    hranice[r].N=hranice[r].W;
    hranice[r].W=hranice[r].S;
    hranice[r].S=hranice[r].E;
    hranice[r].E=pom;
}
int opak(int o){
    int res=0;
    int ok=o;
    int maxx=512;
    int minn=1;
    while(maxx>=1){
        if(ok>=maxx){
            res+=minn;
            ok-=maxx;
        }
        maxx/=2;minn*=2;
    }
    return res;
}
void flipniTileX(int r){
    int pom1=opak(hranice[r].S);
    hranice[r].E=opak(hranice[r].E);
    hranice[r].S=opak(hranice[r].N);
    hranice[r].W=opak(hranice[r].W);
    hranice[r].N=pom1;
}
int sedistrany(int i, int j){
    for(int k=0;k<4;k++){
        otocTile(j);
        if(hranice[i].N==opak(hranice[j].S))return 1;
        if(hranice[i].E==opak(hranice[j].W))return 2;
        if(hranice[i].S==opak(hranice[j].N))return 3;
        if(hranice[i].W==opak(hranice[j].E))return 4;
    }
    flipniTileX(j);
    for(int k=0;k<4;k++){
        otocTile(j);
        if(hranice[i].N==opak(hranice[j].S))return 1;
        if(hranice[i].E==opak(hranice[j].W))return 2;
        if(hranice[i].S==opak(hranice[j].N))return 3;
        if(hranice[i].W==opak(hranice[j].E))return 4;
    }
    flipniTileX(j);
    return 0;
}
void iterace(){
    cout << pocetIteraci << endl;
    if(pocetIteraci>N)return;
    if(hotovo)return;
    hotovo = true;
    for(int i=0;i<N;i++){
        if(zarazene[i]){
            //cout << "uz mame: " << i <<endl;
            for(int j=0;j<N;j++){
                if((i!=j)&&(!zarazene[j])){
                    int z =sedistrany(i,j);
                    if(z>0){zarazene[j]=true;}
                    if(z==1){hranice[j].y=hranice[i].y-1;hranice[j].x=hranice[i].x;}
                    if(z==2){hranice[j].x=hranice[i].x+1;hranice[j].y=hranice[i].y;}
                    if(z==3){hranice[j].y=hranice[i].y+1;hranice[j].x=hranice[i].x;}
                    if(z==4){hranice[j].x=hranice[i].x-1;hranice[j].y=hranice[i].y;}
                    if(zarazene[j])cout << "zarazene: " << j <<" ke " << i << ": x " << hranice[j].x << " y " << hranice[j].y <<endl;
                }
            }
        }   else hotovo=false;
    }
    pocetIteraci++;
    iterace();
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
    int line=0;
    for(int i=1;i<N;i++){
        zarazene[i]=false;
        hranice[i].x=0;
        hranice[i].y=0;
    }
    zarazene[0]=true;
    hranice[0].x = 10;
    hranice[0].y = 10;
    ifstream infile("input20.txt");
    while(getline(infile,temp)){
        //cout << "halo 1" << endl;
        int maxx=512;
        if(line%12==0){
            hranice[line/12].ID=nactiint(temp,0);
        }
        if(line%12==1){
            hranice[line/12].N=0;
            for(int i=0;i<10;i++){
                if(temp[i]=='#')hranice[line/12].N+=maxx;
                maxx/=2;
            }
        }
        //cout << "halo 2" << endl;
        maxx=512;
        if(line%12==10){
            hranice[line/12].S=0;
            for(int i=9;i>=0;i--){
                if(temp[i]=='#')hranice[line/12].S+=maxx;
                maxx/=2;
            }
        }
        //cout << "halo 3" << endl;
        maxx=512;
        int minn=1;
        for(int i=1;i<line%12;i++){
            maxx/=2;
            minn*=2;
        }
        if(temp[0]=='#')hranice[line/12].W+=minn;
        if(temp[9]=='#')hranice[line/12].E+=maxx;
        //cout << "halo 4" << endl;
        line++;
    }
    for(int i=0;i<5;i++){
        cout << hranice[i].ID << " " << hranice[i].N << " " << hranice[i].E << " "<< hranice[i].S << " "<< hranice[i].W <<endl;
    }
    for(int i=0;i<N;i++){
        if((hranice[i].N==810)||(hranice[i].N==339))cout << hranice[i].ID <<endl;
        if((hranice[i].E==810)||(hranice[i].E==339))cout << hranice[i].ID<<endl;
        if((hranice[i].S==810)||(hranice[i].S==339))cout << hranice[i].ID<<endl;
        if((hranice[i].W==810)||(hranice[i].W==339))cout << hranice[i].ID<<endl;
    }
    iterace();
    int maxx=10;
    int maxy=10;
    int minx=10;
    int miny=10;
    for(int i=0;i<N;i++){
        if(hranice[i].x<minx)minx=hranice[i].x;
        if(hranice[i].y<miny)miny=hranice[i].y;
        if(hranice[i].x>maxx)maxx=hranice[i].x;
        if(hranice[i].y>maxy)maxy=hranice[i].y;
    }
    cout << "minx "<< minx << " miny " << miny << " maxx " << maxx << " maxy " <<maxy <<endl;
    for(int i=0;i<N;i++){
        if((hranice[i].x==minx)&&(hranice[i].y==miny)){result*=hranice[i].ID;cout << hranice[i].ID<<endl;}
        if((hranice[i].x==minx+sqrN-1)&&(hranice[i].y==miny)){result*=hranice[i].ID;cout << hranice[i].ID<<endl;}
        if((hranice[i].x==minx)&&(hranice[i].y==miny+sqrN-1)){result*=hranice[i].ID;cout << hranice[i].ID<<endl;}
        if((hranice[i].x==minx+sqrN-1)&&(hranice[i].y==miny+sqrN-1)){result*=hranice[i].ID; cout << hranice[i].ID<<endl;}
    }
	cout << "Part 1: " <<result << endl;
	return 0;
}