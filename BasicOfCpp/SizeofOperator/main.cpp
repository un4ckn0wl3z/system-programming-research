#include <climits>
#include <iostream>
using namespace std;
int main()
{

    cout << "Hello World... " << std::endl;

    cout << "=========================" << endl;
    cout << "sizeof information" << endl;
    cout << "=========================" << endl;
    cout << "sizeof char " << sizeof(char) << " bytes" << endl;
    cout << "sizeof int " << sizeof(int) << " bytes" << endl;
    cout << "sizeof unsigned int " << sizeof(unsigned int) << " bytes" << endl;
    cout << "sizeof signed int " << sizeof(signed int) << " bytes" << endl;
    cout << "sizeof short " << sizeof(short) << " bytes" << endl;
    cout << "sizeof long " << sizeof(long) << " bytes" << endl;
    cout << "sizeof long long " << sizeof(long long) << " bytes" << endl;
    cout << "sizeof float " << sizeof(float) << " bytes" << endl;
    cout << "sizeof double " << sizeof(double) << " bytes" << endl;
    cout << "sizeof long double " << sizeof(long double) << " bytes" << endl;
    cout << "=========================" << endl;
    cout << "Minimal values" << endl;
    cout << "=========================" << endl;
    cout << "char " << CHAR_MIN << " bytes" << endl;
    cout << "int " << INT_MIN << " bytes" << endl;
    cout << "short " << SHRT_MIN << " bytes" << endl;
    cout << "long " << LONG_MIN << " bytes" << endl;
    cout << "long long " << LLONG_MIN << " bytes" << endl;
    cout << "=========================" << endl;
    cout << "Maximum values" << endl;
    cout << "=========================" << endl;
    cout << "char " << CHAR_MAX << " bytes" << endl;
    cout << "int " << INT_MAX << " bytes" << endl;
    cout << "short " << SHRT_MAX << " bytes" << endl;
    cout << "long " << LONG_MAX << " bytes" << endl;
    cout << "long long " << LLONG_MAX << " bytes" << endl;
    cout << "=========================" << endl;
    cout << "sizeof vars" << endl;

    double room_width{ 5.6 };
    int room_length{ 7 };
    cout << "=========================" << endl;
    cout << "double " << sizeof(room_width) << " bytes" << endl;
    cout << "int " << sizeof(room_length) << " bytes" << endl;

    return 0;
}