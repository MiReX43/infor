#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double x, y;
    char �hoice = 'y';
    while (�hoice == 'y' || �hoice == 'Y') {

        cout << "\n������� ���������� �����: ";
        cin >> x >> y;
        double r2 = x * x + y * y;
        if (r2 < 1 && y > 0 && y < 0.2) {
            cout << "����� ����������� �������" << endl;
        }
        else if (r2 > 1 || y < 0 || y > 0.2) {
            cout << "����� �� ����������� �������" << endl;
        }
        else {
            cout << "����� ����� �� ������� �������" << endl;
        }

        cout << "������ ������ ��� ���� �����? (y/n): ";
        cin >> �hoice;
    }
    
}

	
