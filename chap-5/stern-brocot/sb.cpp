#include <iostream>

using namespace std;

class Fraction {
    private:
        int num;
        int den;

        int gcd() {
            int a = num;
            int b = den;

            while (b != 0)
            {
                int temp = b;
                b = a % b;
                a = temp;
            }

            return a;
        }
    public:
        Fraction(int n, int d) 
            : num(n), den(d) {}

        int getNum() {
            return num;
        }

        int getDen() {
            return den;
        }

        Fraction sum(Fraction f) {
            int n = num + f.getNum();
            int d = den + f.getDen();

            return Fraction(n, d);
        }

        bool isBiggerThan(Fraction f) {
            int c1 = num * f.getDen();
            int c2 = den * f.getNum();

            return c1 > c2;
        }

        bool isEqualTo(Fraction f) {
            return num == f.getNum() 
                    && den == f.getDen();
        }

        int reduce() {
            int d = gcd();

            num /= d;
            den /= d;

            return 0;
        }
};

Fraction parallelSum(Fraction &a, Fraction &b){
    int nom = a.getNum() + b.getNum();
    int den = a.getDen() + b.getDen();

    Fraction f(nom, den);
    f.reduce();

    return f;
}

int main(int argc, char *argv[])
{
    int nom, den;

    while (true)
    {
        cin >> nom;
        cin >> den;

        if (nom == 1 && den == 1) break;

        Fraction s(nom, den);

        Fraction l(0, 1);
        Fraction c(1, 1);
        Fraction r(1, 0);        
        
        while (!c.isEqualTo(s))
        {
            if (s.isBiggerThan(c)) {
                cout << "R";

                l = c;
                c = parallelSum(c, r);

                continue;
            }

            cout << "L";
            r = c;
            c = parallelSum(l, c);
        }

        cout << endl;
    }

    return 0;
}