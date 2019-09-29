#include "red.h"
#define INF 1215752192
#define vacio 4294967295
void red::minimo(char *a, char *b)
{
    int c=nodoNum(*a),d=nodoNum(*b);
    char e;
    if(d<c){
        e=*a;
        *a=*b;
        *b=e;
    }
}

void red::obtenerRouters()
{
    ifstream archin;
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
    ifstream archin;
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
           if(adyacente[i][j]!=INF) cout<< adyacenteChar[j][i]<<" ";
            else cout<<adyacenteChar[j][i]<<" ";
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
                cout<< minimosChar[j][i]<<" ";

            }
            cout<<endl;
        }
}

int red::nodoNum(char a)
{
    int num=-1;
    for(int i=0;i<cn;i++){
        if(routers[i]==a) num=i;
    }
    return num;
}

void red::agregarNodo(char a,char b, int num)
{
    fstream archof;
    archof.open("router.txt",std::fstream::app);
    string line;
    line+=a;
    line+=b;
    line+=char(num+48);
    archof<<line;
}

void red::eliminarNodo(char a)
{
    ifstream archin;
    string line,arch;
    archin.open("router.txt");
    while(!archin.eof()){
        getline(archin,line);
        if(line.find(a)==vacio){
            arch+=line;
        }
    }
    archin.close();
    ofstream archof;
    archof.open("router.txt");
    archof<<arch;
}

void red::menu()
{
    int flag_=0;
    while (flag_==0) {
        int opcion;
        string ingresado;
        cout<<"Seleccione una opcion \n";
        cout<<"\n 1. Ir de un router a otro \n";
        cout<<"\n 2. Agregar un enrutador \n";
        cout<<"\n 3. Eliminar un enrutador \n";
        cout<<"\n 4. Agregar una conexion \n";
        cout<<"\n 5. Eliminar una conexion \n";
        cin>>opcion;

        if(opcion==1){
        cout<<"Ingrese que routers (ej. AB: camino de A hacia B): "; cin>>ingresado;
        cout<<"El camino de menor costo es: ";
        imprimirCamino(ingresado[0],ingresado[1]);
        cout<<" y cuesta "<<minimos[nodoNum(ingresado[0])][nodoNum(ingresado[1])]<<endl;
        }
        else if(opcion==2){
            fstream archin;
            archin.open("router.txt",fstream::out|fstream::app);
            string a="   ",b;
            int s=0;
            cout<<"Ingrese el nombre del Router: ";cin>>a[0];
            while(s!=1){
                cout<<"Ingrese la conexion: ";cin>>a[1];
                cout<<" y su valor de conexion: ";cin>>a[2];
                archin<<'\n'<<a;
                cout<<"Ingrese 1 si desea agregar conexion a otro router";cin>>s;
            }

        }
        else if(opcion==3){
            ifstream archin;
            archin.open("router.txt");
            string a,b,c;
            cout<<"Ingrese el nombre del Router: ";cin>>a;
            while(!archin.eof()){
                getline(archin,c);
                if(c.find(a)==vacio) b+=c;
            }
            archin.close();

            ofstream archof;
            archof.open("router.txt");
            archof<<b;
        }
        else if(opcion==4){

        }
        else if(opcion==5){

        }
        else flag_=1;


    }



    }

void red::imprimirCamino(char a, char b)
{
    minimo(&a,&b);
    string camino;
    camino+=b;
     for(char i=b;i!='0';){
         i=minimosChar[nodoNum(b)][nodoNum(a)];
         if(i!='0'){
             camino+=i;
             b=i;
         }
     }
    cout<<camino.at(camino.size()-1);
    for(int j=camino.size()-2;j>-1;j--){
        cout<<"->"<<camino.at(j)<<" ";

    }
}

