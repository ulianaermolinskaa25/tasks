#include <iostream>

using namespace std;

class Money {
private:
    long rubles;
    unsigned char kopeсks;

public:

    Money() : rubles(0), kopeсks(0)
    {}
    Money(long rub, unsigned char kop) : rubles(rub), kopeсks(kop)
    {}

    void get_money()
    {
        cout << "Enter rubles: "; cin >> rubles;
        cout << "Enter kopeyks: "; cin >> kopeсks;
    }

    void show_money()
    {
        printf("%ld rub., %02d kop.\n", rubles, kopeсks);
    }

    friend istream& operator>>(istream& in, Money& m)
    {
        in >> m.rubles >> m.kopeсks;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Money& m)
    {
        out << m.rubles << " rub., " << (int)m.kopeсks << " kop.";
        return out;
    }

    Money operator+(Money) const;
    Money operator-(Money) const;
    Money operator*(double) const;
    Money operator/(double) const;
    bool operator<(Money) const;
};

Money Money::operator+ (Money m) const
{
    long r = rubles + m.rubles;
    int8_t k = kopeсks + m.kopeсks;
    r += k / 100;
    k %= 100;
    return Money(r, k);
}

Money Money::operator- (Money m) const
{
    long r = rubles - m.rubles;
    int8_t k = kopeсks - m.kopeсks;
    while (k < 0)
    {
        k += 100;
        r--;
    }
    return Money(r, k);
}

Money Money::operator* (double s) const
{
    double total_cents = (rubles * 100 + kopeсks) * s;
    long r = total_cents / 100;
    int8_t k = total_cents - r * 100;
    return Money(r, k);
}

Money Money::operator/ (double t) const
{
    double total_cents = (rubles * 100 + kopeсks) / t;
    long r = total_cents / 100;
    int8_t k = total_cents - r * 100;
    return Money(r, k);
}

bool Money::operator< (Money m) const
{
    long b1 = rubles + kopeсks / 100;
    unsigned char b2 = m.rubles + m.kopeсks / 100;
    return (b1 < b2) ? true : false;
}

int main()
{
    Money money1, sum, substr, multipl, div;
    money1.get_money();

    Money money2(5, 60);

    sum = money1 + money2;

    if (money1 < money2)
    {
        cout << "\nMoney1 less than Money2." << endl;
        div = money1 / 2.4;
        substr = money2 - money1;
    }
    else
    {
        cout << "\nMoney2 less than Money1." << endl;
        div = money1 / 2.4;
        substr = money1 - money2;
    }

    multipl = money1 * 5.0;

    cout << "Money1 = "; money1.show_money(); cout << endl;
    cout << "Money2 = "; money2.show_money(); cout << endl;
    cout << "Sum = "; sum.show_money(); cout << endl;
    cout << "Substraction = "; substr.show_money(); cout << endl;
    cout << "Multiplication = "; multipl.show_money(); cout << endl;
    cout << "Division = "; div.show_money(); cout << endl;

    return 0;
}