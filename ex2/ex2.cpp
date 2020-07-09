#include <iostream>
#include <math.h>
#include "Header.h"
using namespace std;


int main() {

    setlocale(LC_ALL, "Russian");


    int x, x1, x2;


    cout << "Введите систему счисления: ";
    cin >> x;
    cout << "Введите первое число в " << x << "-ичной системе счисления: ";
    cin >> x1;
    cout << "Введите второе число в " << x << "-ичной системе счисления: ";
    cin >> x2;

    PSystem p1(x, x1);
    PSystem p(x, x2);


    PSystem p2 = p1.Add(p);
    cout << "Результат сложение " << p1.x << " и " << p.x << " в " << p.p << "-ичной системе счисления: " << p2.x << endl;

    p2 = p1.Subtraction(p);
    cout << "Результат вычетания из " << p1.x << " " << p.x << " в " << p.p << "-ичной системе счисления: " << p2.x << endl;

    p2 = p1.Multiplication(p);
    cout << "Результат умножения " << p1.x << " на " << p.x << " в " << p.p << "-ичной системе счисления: " << p2.x << endl;


    p2 = p1.division(p);
    cout << "Результат деления " << p1.x << " на " << p.x << " в " << p.p << "-ичной системе счисления: " << p2.x << endl;

    p2 = p.Degree(4);
    cout << "Результат возведения " << p.x << " в 4-ю степень в " << p.p << "-ичной системе счисления: " << p2.x << endl;

    p2 = PSystem::TenToP(20, 3);
    cout << "Результат перевода 20 из 10-ичной системы счисления в 3-ичную: " << p2.x << endl;

    int g = PSystem::PToTen(202, 3);
    cout << "Результат перевода 202 из 3-ичной системы счисления в 10-ичную: " << g << endl;


    p2.Check();
    PSystem p3(3, 1234);
    p3.Check();

}

