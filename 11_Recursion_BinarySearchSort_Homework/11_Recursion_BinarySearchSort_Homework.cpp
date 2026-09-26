
#include <iostream>

using namespace std;

//1
int Power(int base, int exponent)      // int - повертає число
{
    if (exponent == 0) {
        return 1;

        return base * Power(base, exponent - 1);
    }

}

//2
void PrintStars(int n)
{
    if (n == 0) {
        return; 
    }
    cout << "*";
    PrintStars(n - 1); 
}
    int main()
    {
        Power(2, 5);
        Power(3, 4);

        PrintStars(4);
        PrintStars(7);
        PrintStars(6);
    }

