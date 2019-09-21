#include "red.h"
#define INF 1215752192
#define vacio 4294967295
red::red()
{
    fstream archin;
    string line;
    archin.open("router.txt");
    while(!archin.eof()){
        getline(archin,line);
        if(routers.find(line[0])==vacio){
            routers+=line[0];
            }
        if(routers.find(line[1])==vacio){
            routers+=line[1];
            }
    }
    cn=int(routers.size());
    archin.close();
}

void red::crearAdyacente()
{
    vector<unsigned int> a;
    vector<char> b;
    for(int i=0;i<cn;i++){
        adyacente.push_back(a);
        adyacenteChar.push_back(b);
        for(int j=0;j<cn;j++){
           if(j==i){
               adyacente[i].push_back(0);
               adyacenteChar[i].push_back('0');
           }
           else {
               adyacente[i].push_back(INF);
               adyacenteChar[i].push_back('1');
           }
        }
    }
    fstream archin;
    string line;
    archin.open("router.txt");
    while(!archin.eof()){
        getline(archin,line);
        if(line[3]>47 && line [3]<58){
            adyacente[nodoNum(line[0])][nodoNum(line[1])]=((line[2]-48)*10)+(line[3]-48);
            adyacenteChar[nodoNum(line[0])][nodoNum(line[1])]=line[1];
            adyacente[nodoNum(line[1])][nodoNum(line[0])]=((line[2]-48)*10)+(line[3]-48);
            adyacenteChar[nodoNum(line[1])][nodoNum(line[0])]=line[0];

        }
        else{
            adyacente[line[0]-65][line[1]-65]=line[2]-48;
            adyacenteChar[line[0]-65][line[1]-65]=line[1];
            adyacente[line[1]-65][line[0]-65]=line[2]-48;
            adyacenteChar[line[1]-65][line[0]-65]=line[0];
        }

    }
    archin.close();
    for(int i=0;i<cn;i++){
        for(int j=0;j<cn;j++){
            cout<< adyacente[i][j];

        }
        cout<<endl;
    }


}

void red::crearMinimo()
{
    minimos = this->adyacente;
    minimosChar=this->adyacenteChar;
        for(int k = 0; k < cn; k++)
            for(int i = 0; i < cn; i++)
                for(int j = 0; j < cn; j++){
                    unsigned int dt =  minimos[i][k] +  minimos[k][j];
                    if( minimos[i][j] > dt){
                        minimos[i][j] = dt;
                        minimosChar[i][j]=char(k+65);

                    }
                }
        cout<<endl;
        for(int i=0;i<cn;i++){
            for(int j=0;j<cn;j++){
                cout<< minimos[i][j];

            }
            cout<<endl;
        }
}

int red::nodoNum(char a)
{
    int num;
    for(int i=0;i<cn;i++){
        if(routers[i]==a) num=i;
    }
    return num;
}
