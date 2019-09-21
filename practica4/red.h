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
    vector< vector<int> > adyacente, minimos; //matriz con valor entre nodos que tengan conexion directa
    int cn; //cantidad de nodos
public:
    red();
    void crearAdyacente();
};

#endif // RED_H
