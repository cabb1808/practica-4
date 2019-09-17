#include "red.h"

red::red()
{
    fstream archin;
    int a=0,cNum;
    string line;
    char c,primer,segun;
    archin.open("router.txt");
    for(int i = 0; i < cn; i++)
           adyacente[i][i] = 0;
    while(!archin.eof()){
        archin.get(c);
        if(a==0){
            if(routers.find(c)!=string::npos){
                routers+=c;
            }
            a++;
            primer=c;
        }
        else if (a==1){
            if(routers.find(c)!=string::npos){
                routers+=c;
            }
            a++;
            segun=c;
        }
        else if (a==2){
            cNum=c-48;
            adyacente[primer-65][segun-65]=cNum;
        }
        else a=0;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; i < 3; i++) cout<<adyacente[i][j]<< " ";
        cout<<endl;
    }
}
