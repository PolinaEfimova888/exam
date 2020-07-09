#include <iostream>

using namespace std;

class PSystem {
public:
    int p;
    int x;


    PSystem(int P, int X) {
        p = P;
        x = X;
    }


    void Check() {
        int x1 = x;
        bool f = true;
        while (x1 != 0) {
            int xi = x % 10;
            if (xi >= p) {
                f = false;
                break;
            }

            x1 /= 10;
        }
        if (f)
            cout << "число " << x << " верно  записано в " << p << "-ичной системе счисления" << endl;
        else
            cout << "число " << x << " неверно  записано в " << p << "-ичной системе счисления" << endl;
    }


    PSystem Add(PSystem a) {
        int x1 = x, resx = 0, i = 0;

        while (x1 > 0) {
            if (x1 % 10 + a.x % 10 + resx / pow(10, i) >= p) {
                resx += (x1 % 10 + a.x % 10) % p * pow(10, i) + (x1 % 10 + a.x % 10) / p * pow(10, i + 1);
            }
            else {
                resx += (x1 % 10 + a.x % 10) * pow(10, i);
            }

            i++;
            x1 /= 10;
            a.x /= 10;
        }

        PSystem res(p, resx);
        return res;
    }


    PSystem Subtraction(PSystem a) {

        int x1 = x, resx = 0, i = 0;

        while (x1 > 0) {

            if (x1 % 10 - a.x % 10 < 0) {
                resx += (x1 % 10 + p - a.x % 10) * pow(10, i);
                x1 -= pow(10, i + 1);
            }
            else {
                resx += (x1 % 10 - a.x % 10) * pow(10, i);
            }

            i++;
            a.x /= 10;
            x1 /= 10;
        }

        PSystem res(p, resx);
        return res;
    }


    PSystem Multiplication(PSystem a) {
        /*int x1, resx1 = 0, resx = 0, i = 0, j = 0;


        while (a.x > 0) {
        x1 = x;
        i = j;
        while (x1 > 0) {
        if (x1 % 10 * a.x % 10 >= p) {
        resx1 += (x1 % 10 * a.x % 10) % p * pow(10, i) + (x1 % 10 * a.x % 10) / p * pow(10, i + 1);
        }
        else {
        resx1 += x1 % 10 * a.x % 10 * pow(10, i);
        }
        i++;
        x1 /= 10;
        }
        resx += resx1;
        a.x /= 10;
        resx1 = 0;
        j++;
        }

        resx1 = resx;
        i = 0;
        while (resx1 > 0) {
        if (resx1 % 10 >= p) {
        resx -= ((resx1 % 10) / p) * p * pow(10, i);
        resx += ((resx1 % 10) / p) * pow(10, i + 1);
        resx1 -= (resx1 % 10) / p;
        resx1 += (resx1 % 10) / p * 10;
        }
        i++;
        resx1 /= 10;
        }


        PSystem res(p, resx);
        return res;*/

        int x1, i = 0, res1 = 0, res2 = 0, resItog = 0, xItog = 0;

        x1 = a.x;

        while (x1 != 0)
        {
            i++;
            x1 /= 10;
        }

        x1 = a.x;

        for (int j = 1; j < i + 1; j++)
        {
            res1 += pow(a.p, j - 1) * (x1 % 10);
            x1 /= 10;
        }

        i = 0;
        x1 = x;

        while (x1 != 0)
        {
            i++;
            x1 /= 10;
        }

        x1 = x;

        for (int j = 1; j < i + 1; j++)
        {
            res2 += pow(a.p, j - 1) * (x1 % 10);
            x1 /= 10;
        }

        resItog = res1 * res2;

        i = 0;

        while (resItog != 0)
        {
            xItog += (resItog % p) * pow(10, i);
            i++;
            resItog /= p;
        }
        PSystem rs(p, xItog);
        return rs;

    }

    static PSystem TenToP(int a, int ps) {
        int resx = 0, i = 0;
        while (a > 0) {
            resx += a % ps * pow(10, i);
            a /= ps;
            i++;
        }

        PSystem res(ps, resx);
        return res;
    }

    static int PToTen(int a, int ps) {
        int resx = 0, i = 0;
        while (a > 0) {
            resx += a % 10 * pow(ps, i);
            a /= 10;
            i++;
        }

        return resx;
    }

    PSystem division(PSystem a) {
        int a1 = PToTen(a.x, p);
        int x1 = PToTen(x, p);

        int res = x1 / a1;

        return TenToP(res, p);
    }



    PSystem Degree(int a) {

        int x1, i = 0, res1 = 0, resItog = 0, xItog = 0;

        x1 = x;

        while (x1 != 0)
        {
            i++;
            x1 /= 10;
        }

        x1 = x;

        for (int j = 1; j < i + 1; j++)
        {
            res1 += pow(p, j - 1) * (x1 % 10);
            x1 /= 10;
        }

        resItog = pow(res1, a);
        i = 0;

        while (resItog != 0)
        {
            xItog += (resItog % p) * pow(10, i);
            i++;

            resItog /= p;
        }

        PSystem rs(p, xItog);
        return rs;
    }
};