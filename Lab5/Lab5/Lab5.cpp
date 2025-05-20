#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double x, y;
    char сhoice = 'y';
    while (сhoice == 'y' || сhoice == 'Y') {

        cout << "\nВведите координаты точки: ";
        cin >> x >> y;
        double r2 = x * x + y * y;
        if (r2 < 1 && y > 0 && y < 0.2) {
            cout << "Точка принадлежит области" << endl;
        }
        else if (r2 > 1 || y < 0 || y > 0.2) {
            cout << "Точка не принадлежит области" << endl;
        }
        else {
            cout << "Точка лежит на границе области" << endl;
        }

        cout << "Хотите ввести еще одну точку? (y/n): ";
        cin >> сhoice;
    }
    
}

	
