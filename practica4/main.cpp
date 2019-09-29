#include <fstream>
#include <iostream>
#include <vector>
#include "red.h"
using namespace std;
int main()
{
    red a;
    a.obtenerRouters();
    a.crearAdyacente();
    a.crearMinimo();
    cout<<endl;
    a.menu();

}
