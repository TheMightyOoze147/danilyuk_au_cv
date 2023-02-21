#ifndef MYLIB_H
#define MYLIB_H
#include <iostream>
#include <math.h>
#include <string>

using namespace std;
class point {
public:
    string name;
    int x;
    int y;
    int way = 0;
    point(string d_name, int d_x, int d_y){
    name = d_name;
    x = d_x;
    y = d_y;;
    }
};

point* random_walk (point *obj);
void point_show (point *obj);
void distance (point* obj1, point* obj2);
void menu_func ();
#endif // MYLIB_H