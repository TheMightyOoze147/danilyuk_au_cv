#ifndef MYLIB_H
#define MYLIB_H
#include <iostream>
#include <math.h>
#include <string>

using namespace std;
typedef struct point {
    string name;
    int x;
    int y;
    int way;
}Pt;

Pt* make_point (string id);
Pt* random_walk (Pt *obj);
void point_show (Pt *obj);
void menu_func ();
void distance (Pt* obj1, Pt* obj2);
#endif // MYLIB_H