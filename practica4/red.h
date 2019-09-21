#ifndef RED_H
#define RED_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class red
{
private:
    string routers;//string con el nombre de los routers en la red
    vector< vector<unsigned int> > adyacente, minimos; //matriz con valor entre nodos que tengan conexion directa
    vector< vector<char> > adyacenteChar,minimosChar;
    int cn; //cantidad de nodos
public:
    red();
    void crearAdyacente();
    void crearMinimo();
    int nodoNum(char a);
};

#endif // RED_H
