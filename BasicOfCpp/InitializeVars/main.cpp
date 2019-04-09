#include <iostream>
using namespace std;

int gb_int {50};

int main()
{

    double room_width{ 0.0 };
    double room_length{ 0.0 };

    cout << "Enter your root width: ";
    cin >> room_width;

    cout << "Enter your root length: ";
    cin >> room_length;

    cout << "Your roo area is : " << (room_width * room_length) << endl;

    return 0;
}