#include <iostream>

using namespace std;

int main()
{
    char middle_init{ 'j' };
    cout << middle_init << endl;

    unsigned short int exam_score{ 55 };
    cout << "My score is :" << (exam_score) << endl;

    int money{ 100 };
    cout << "I have money for  :" << (money) << " baht " << endl;

    long people_in_thailand{ 70'000'000 };
    cout << "Thailand population is :" << (people_in_thailand) << endl;

    long long people_on_earth{ 7'600'000'000 };
    cout << "people_on_earth :" << (people_on_earth) << endl;

    float my_electric_bill{ 250.60 };
    cout << "my_electric_bill :" << (my_electric_bill) << endl;

    double pi{ 3.14159 };
    cout << "PI is :" << (pi) << endl;

    long double big_long{ 2.7e120 };
    cout << "big_long :" << (big_long) << endl;

    bool game_over { false };
    cout << "gameOver :" << (game_over) << endl;

    return 0;
}