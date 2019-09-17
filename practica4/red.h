#ifndef RED_H
#define RED_H
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class red
{
private:
    int cn; //cantidad de nodos
    string routers;//string con el nombre de los routers en la red
    vector< vector<int> > adyacente, minimos; //matriz con valor entre nodos que tengan conexion directa
public:
    red();
};

#endif // RED_H
