#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// �������� ��������
const double EPS = 1e-6;

// ������� f(x) = arctg(x) - (1 / (3 * x^3))
double f(double x) {
    return atan(x) - (1.0 / (3 * pow(x, 3)));
}

// ����� ���������� �������� ������ �� �������� ������� [a, b] � ����� step
vector<pair<double, double>> find_isolation_intervals(double a, double b, double step) {
    vector<pair<double, double>> intervals;
    double x1 = a, x2 = a + step;
    while (x2 <= b) {
        if (f(x1) * f(x2) < 0) {  // ���� ����� ������, ������, ���� ������
            intervals.push_back({ x1, x2 });
        }
        x1 = x2;
        x2 += step;
    }
    return intervals;
}

// ����� �������� ��� ���������� ����� ��������� f(x) = 0 �� ������� [a, b]
pair<double, int> bisection(double a, double b) {
    int iterations = 0;
    double mid;
    while ((b - a) / 2 > EPS) {
        mid = (a + b) / 2;
        if (f(mid) == 0) break;
        if (f(a) * f(mid) < 0) {
            b = mid;
        }
        else {
            a = mid;
        }
        iterations++;
    }
    return { mid, iterations };
}

int main() {
    double a = -5.0, b = 5.0;  // ������� ������ ������
    double step = 0.1;         // ��� ��� ������ ���������� ��������

    // ����� ���������� ��������
    vector<pair<double, double>> intervals = find_isolation_intervals(a, b, step);

    cout << "��������� ��������� �������� ������:" << endl;
    for (const auto& interval : intervals) {
        cout << "[" << interval.first << ", " << interval.second << "]" << endl;
    }

    cout << "\n����� ������ ������� ��������:" << endl;
    for (const auto& interval : intervals) {
        auto [root, iterations] = bisection(interval.first, interval.second);
        cout << "������: " << root << " f(������) = " << f(root) << " ��������: " << iterations << endl;
    }

    return 0;
}
