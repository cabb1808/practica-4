#include "red.h"
#define INF 10000000*10000
red::red()
{
    fstream archin;
    string line;
    archin.open("router.txt");
    while(!archin.eof()){
        getline(archin,line);
        if(routers.find(line[0])==4294967295){
            routers+=line[0];
            }
        if(routers.find(line[1])==4294967295){
            routers+=line[1];
            }
    }
    cn=int(routers.size());
    archin.close();
}

void red::crearAdyacente()
{
    vector<int> a;
    for(int i=0;i<cn;i++){
        adyacente.push_back(a);
        for(int j=0;j<cn;j++){
           if(j==i)adyacente[i].push_back(0);
           else adyacente[i].push_back(0);
        }
    }
    fstream archin;
    string line;
    archin.open("router.txt");
    while(!archin.eof()){
        getline(archin,line);
        adyacente[line[0]-65][line[1]-65]=line[2]-48;
        adyacente[line[1]-65][line[0]-65]=line[2]-48;
    }
    archin.close();
    for(int i=0;i<cn;i++){
        for(int j=0;j<cn;j++){
            cout<<adyacente[i][j];

        }
        cout<<endl;
    }

}
