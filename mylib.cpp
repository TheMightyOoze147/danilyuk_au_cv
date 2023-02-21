#include "mylib.h"

point* random_walk (point *obj) {
    int t_x = rand()%1000 - 500; 
    int t_y = rand()%1000 - 500;
    int S_x = fabs(obj->x) + fabs(t_x);
    int S_y = fabs(obj->y) + fabs(t_y);

    obj->x = t_x;
    obj->y = t_y;
    obj->way = obj->way + S_x + S_y;
    //Функция должна менять way
    return obj;
}

void point_show (point *obj) {
    cout 
    << "\nВ настоящее время точка имеет такие данные: "
    << "\nИмя: " << obj->name
    << "\nКоордината x: " << obj->x
    << "\nКоордината y: " << obj->y
    << "\nПройденный путь: " << obj->way
    << endl;
}

//a
void distance (point* obj1, point* obj2) {
    float dist; int diff_x, diff_y;
    if (obj1->x == obj2->x || obj1->y == obj2->y) {
        dist = fabs (obj1->x - obj2->x) + fabs (obj1->y - obj2->y);
    }
    else {
        diff_x = fabs (obj1->x - obj2->x);
        diff_y = fabs (obj1->y - obj2->y);
        dist = sqrt (pow(diff_x, 2) + pow(diff_y, 2));
    }
    cout << "\nРасстояние между " << obj1->name << " и " << obj2->name << " составляет " << dist << endl;
}

void menu_func () {
    int ch, struct_ch, wh = 1;
    string new_name;
    point* prev, *curr, *temp;
    cout 
    << "\n(Всего можно создать две структуры (для тестирования дистанции))"
    << "\nМеню: "
    << "\n1. Создать новый объект."
    << "\n2. Переключиться на второй объект (если есть)" 
    << "\n3. Случайно переместить объект." 
    << "\n4. Узнать расстояние между двумя объектами" 
    << "\n5. Выйти из программы." 
    << endl;
    while (wh == 1) {
        cin >> ch;
        switch (ch) {
        case 1:
            prev = curr;
            cout << "\nВведите название объекта: ";
            cin >> new_name;
            curr = new point(new_name, 0, 0);
            //curr = make_point(new_name);
            point_show (curr);
            break;
        case 2:
            cout << "\nВы сейчас на структуре " << curr->name << "\nПереключиться на " << prev->name << "?";
            cout 
            << "\n1. Да"
            << "\n2. Нет" << endl;
            cin >> struct_ch;
            switch (struct_ch) {
                case 1:
                    temp = curr;
                    curr = prev;
                    prev = temp;
                    point_show (curr);
                    break;
                case 2:
                    point_show (curr);
                    break;
                default:
                    cout << "\nНеправильный выбор!";
                    break;
            }
            break;
        case 3:
            random_walk(curr);
            point_show(curr);
            break;
        case 4:
            distance (curr, prev);
            break;
        case 5:
        wh = 0;
            break;
        }
    }
}