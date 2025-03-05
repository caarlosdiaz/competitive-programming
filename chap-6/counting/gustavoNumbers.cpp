#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class BigNumber
{
private:
    string value;

public:
    BigNumber() : value("0") {}
    BigNumber(string newValue) : value(newValue) {}

    inline string getValue() const
    {
        return value;
    }

    BigNumber operator*(int num) const
    {
        string result = "";
        int carry = 0;
        for (int i = value.length() - 1; i >= 0; i--)
        {
            int res = (value[i] - '0') * num + carry;
            carry = res / 10;
            res = res % 10;
            result = char(res + '0') + result;
        }

        while (carry)
        {
            result = to_string(carry % 10) + result;
            carry /= 10;
        }

        return BigNumber(result);
    }

    BigNumber operator+(const BigNumber &num) const
    {
        string result = "";
        int carry = 0;
        const string &numValue = num.getValue();
        int i = value.size() - 1, j = numValue.size() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += value[i--] - '0';
            if (j >= 0)
                sum += numValue[j--] - '0';

            result = char(sum % 10 + '0') + result;
            carry = sum / 10;
        }

        return BigNumber(result);
    }
};

int main(int argc, char * argv[])
{
    const int N = 1000;
    vector<BigNumber> a(N);

    a[0] = BigNumber("2");
    a[1] = BigNumber("5");
    a[2] = BigNumber("13");

    for (int i = 3; i < N; i++)
    {
        a[i] = ((a[i - 1] * 2) + a[i - 2]) + a[i - 3];
    }

    cout << "{" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "\"" << a[i].getValue() << "\"" << "," << endl;
    }
    cout << "}" << endl;

    return 0;
}
