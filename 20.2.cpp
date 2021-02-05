#include "bits/stdc++.h"
using namespace std;
string temp;
long long result = 0;
int pos=0;
int pocetIteraci=0;
const int N = 144;
const int sqrN = 12;
bool * celkovyObrazek[sqrN*8];
bool * vyuziteNaPriseru[sqrN*8];
bool zarazene[N];
bool hotovo;
struct tile{
bool *krizky[8];
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
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            bool pom=hranice[r].krizky[i][j];
            hranice[r].krizky[i][j]=hranice[r].krizky[7-j][i];
            hranice[r].krizky[7-j][i]=hranice[r].krizky[7-i][7-j];
            hranice[r].krizky[7-i][7-j]=hranice[r].krizky[j][7-i];
            hranice[r].krizky[j][7-i]=pom;
        }
    }
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
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            bool pom=hranice[r].krizky[i][j];
            hranice[r].krizky[i][j]=hranice[r].krizky[7-i][j];
            hranice[r].krizky[7-i][j]=pom;
        }
    }
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
                    //if(zarazene[j])cout << "zarazene: " << j <<" ke " << i << ": x " << hranice[j].x << " y " << hranice[j].y <<endl;
                }
            }
        }   else hotovo=false;
    }
    pocetIteraci++;
    iterace();
}
int spocitejVolne(){
    int volne=0;
    for(int i=0;i<sqrN*8;i++){
        for(int j=0;j<sqrN*8;j++){
            if(!vyuziteNaPriseru[i][j])volne++;
        }
    }
    return volne;
}
void otocObrazek(){
    cout << "otáčim" <<endl;
    for(int i=0;i<sqrN*4;i++){
        for(int j=0;j<sqrN*4;j++){
            bool pom=celkovyObrazek[i][j];
            celkovyObrazek[i][j]=celkovyObrazek[j][sqrN*8-1-i];
            celkovyObrazek[j][sqrN*8-1-i]=celkovyObrazek[sqrN*8-1-i][sqrN*8-1-j];
            celkovyObrazek[sqrN*8-1-i][sqrN*8-1-j]=celkovyObrazek[sqrN*8-1-j][i];
            celkovyObrazek[sqrN*8-1-j][i]=pom;
            pom=vyuziteNaPriseru[i][j];
            vyuziteNaPriseru[i][j]=vyuziteNaPriseru[j][sqrN*8-1-i];
            vyuziteNaPriseru[j][sqrN*8-1-i]=vyuziteNaPriseru[sqrN*8-1-i][sqrN*8-1-j];
            vyuziteNaPriseru[sqrN*8-1-i][sqrN*8-1-j]=vyuziteNaPriseru[sqrN*8-1-j][i];
            vyuziteNaPriseru[sqrN*8-1-j][i]=pom;
        }
    }
    cout << "už neotáčim" <<endl;
    return;
}
void flipniObrazek(){
    cout << "flipuju..." <<endl;
    for(int i=0;i<sqrN*8;i++){
        for(int j=0;j<sqrN*4;j++){
            bool pom=celkovyObrazek[i][j];
            celkovyObrazek[i][j]=celkovyObrazek[i][sqrN*8-1-j];
            celkovyObrazek[i][sqrN*8-1-j]=pom;
            pom=vyuziteNaPriseru[i][j];
            vyuziteNaPriseru[i][j]=vyuziteNaPriseru[i][sqrN*8-1-j];
            vyuziteNaPriseru[i][sqrN*8-1-j]=pom;
        }
    }
    cout << "doflipováno..." <<endl;
}
void najdiPrisery(){
    cout << "hledam..." <<endl;
    for(int i=0;i<sqrN*8;i++)
        cout << celkovyObrazek[0][i];
    cout <<endl; 
    int pocetpriser=0;
    for(int i=0;i<sqrN*8;i++){
        for(int j=0;j<sqrN*8;j++){
            if((i<1)||(i>sqrN*8-2)||(j>sqrN*8-20))continue;
            if(!celkovyObrazek[i][j])continue;
            if(!celkovyObrazek[i][j+5])continue;
            if(!celkovyObrazek[i][j+6])continue;
            if(!celkovyObrazek[i][j+11])continue;
            if(!celkovyObrazek[i][j+12])continue;
            if(!celkovyObrazek[i][j+17])continue;
            if(!celkovyObrazek[i][j+18])continue;
            if(!celkovyObrazek[i][j+19])continue;
            if(!celkovyObrazek[i-1][j+18])continue;
            if(!celkovyObrazek[i+1][j+1])continue;
            cout << 10 <<endl;
            if(!celkovyObrazek[i+1][j+4])continue;
            if(!celkovyObrazek[i+1][j+7])continue;
            if(!celkovyObrazek[i+1][j+10])continue;
            if(!celkovyObrazek[i+1][j+13])continue;
            if(!celkovyObrazek[i+1][j+16])continue;
            pocetpriser++;
            vyuziteNaPriseru[i][j]=true;
            vyuziteNaPriseru[i][j+5]=true;
            vyuziteNaPriseru[i][j+6]=true;
            vyuziteNaPriseru[i][j+11]=true;
            vyuziteNaPriseru[i][j+12]=true;
            vyuziteNaPriseru[i][j+17]=true;
            vyuziteNaPriseru[i][j+18]=true;
            vyuziteNaPriseru[i][j+19]=true;
            vyuziteNaPriseru[i-1][j+18]=true;
            vyuziteNaPriseru[i+1][j+1]=true;
            vyuziteNaPriseru[i+1][j+4]=true;
            vyuziteNaPriseru[i+1][j+7]=true;
            vyuziteNaPriseru[i+1][j+10]=true;
            vyuziteNaPriseru[i+1][j+13]=true;
            vyuziteNaPriseru[i+1][j+16]=true;
        }
    }
    cout << pocetpriser<<endl;
    cout << "nehledam..." << endl;
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
void hledej(){
    cout << spocitejVolne()<<endl;
    najdiPrisery();
    cout << spocitejVolne()<<endl;
    otocObrazek();
    cout << spocitejVolne() <<endl;
    najdiPrisery();
    cout << spocitejVolne()<<endl;
    otocObrazek();
    cout << spocitejVolne()<<endl;
    najdiPrisery();
    cout << spocitejVolne()<<endl;
    otocObrazek();
    cout << spocitejVolne()<<endl;
    najdiPrisery();
    cout << spocitejVolne()<<endl;
    flipniObrazek();
    cout << spocitejVolne()<<endl;
    najdiPrisery();
    cout << spocitejVolne()<<endl;
    otocObrazek();
    cout << spocitejVolne()<<endl;
    najdiPrisery();
    cout << spocitejVolne()<<endl;
    otocObrazek();
    cout << spocitejVolne()<<endl;
    najdiPrisery();
    cout << spocitejVolne()<<endl;
    otocObrazek();
    cout << spocitejVolne()<<endl;
    najdiPrisery();
    cout << spocitejVolne()<<endl;
}
int main(){
    int line=0;
    for(int i=0;i<N;i++){
        zarazene[i]=false;
        hranice[i].x=0;
        hranice[i].y=0;
        for(int j=0;j<8;j++){
            hranice[i].krizky[j]=new bool[8];
            for(int l=0;l<8;l++){
                hranice[i].krizky[j][l]=false;
            }
        }
    }
    zarazene[0]=true;
    hranice[0].x = 10;
    hranice[0].y = 10;
    for(int i=0;i<sqrN*8;i++){
        celkovyObrazek[i]=new bool[sqrN*8];
        vyuziteNaPriseru[i]=new bool[sqrN*8];
        for(int j=0;j<sqrN*8;j++){
            celkovyObrazek[i][j]=false;
            vyuziteNaPriseru[i][j]=true;

        }
    }
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
        if((line%12>1)&&(line%12<10)){
            for(int k=1;k<9;k++){
                //cout << line/12 <<" " << line%12-2 << " " << k-1 << " " << temp[k] << endl ;
                if(temp[k]=='#'){hranice[line/12].krizky[line%12-2][k-1]=true;result++;}
                if(temp[k]=='.')hranice[line/12].krizky[line%12-2][k-1]=false;
            }
        }
        if(temp[0]=='#')hranice[line/12].W+=minn;
        if(temp[9]=='#')hranice[line/12].E+=maxx;
        //cout << "halo 4" << endl;
        line++;
    }
    cout << "halo1" <<endl;
    cout << result <<endl;
    result=1;
    flipniTileX(0);
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
    result=0;
    for(int x=minx;x<=maxx;x++){
        for(int y=miny;y<=maxy;y++){
            for(int i=0;i<N;i++){
                if((hranice[i].x==x)&&(hranice[i].y==y)){
                    for(int j=0;j<8;j++){
                        for(int k=0;k<8;k++){
                            //cout << 8*(x-minx)+j << " " << 8*(y-miny)+k << " " << hranice[i].krizky[j][k] <<endl;
                            if(hranice[i].krizky[j][k]){
                                celkovyObrazek[8*(y-miny)+j][8*(x-minx)+k]=true;
                                vyuziteNaPriseru[8*(y-miny)+j][8*(x-minx)+k]=false;
                            } else {
                                celkovyObrazek[8*(y-miny)+j][8*(x-minx)+k]=false;
                                vyuziteNaPriseru[8*(y-miny)+j][8*(x-minx)+k]=true;
                            }
                        }
                    }
                }
            }

        }
    }
    /*for(int i=0;i<sqrN*8;i++){
        for(int j=0;j<sqrN*8;j++){
            if(j%8==0)cout <<" ";
            if(celkovyObrazek[i][j])cout << "#";else cout << ".";
        }
        if(i%8==7)cout <<endl;
        cout <<endl;
    }*/
    for(int i=0;i<sqrN*8;i++)
        cout << celkovyObrazek[0][i];
    cout <<endl; 
    hledej();
    result=spocitejVolne();
    cout << "Part 2: " <<result <<endl;
	return 0;
}