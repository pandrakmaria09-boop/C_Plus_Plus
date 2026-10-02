#include <iostream>
#include <cctype>
using namespace std;

// 4
int myStrlen(char arr[])
{
    int len = 0;
    while (arr[len] != '\0')
    {
        len++;
    }
    return len;
}

int main()
{
    char arr[255];
    char arr2[255];

    // 1
    cout << "1. Enter  text : ";
    cin.getline(arr, 255);

    int countA = 0, countO = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (tolower(arr[i]) == 'a') countA++;
        if (tolower(arr[i]) == 'o') countO++;
    }
    cout << "a : " << countA << ", o : " << countO << endl;
    if (countA > countO)
        cout << "'a' is more" << endl;
    else if (countO > countA)
        cout << "'o' is more" << endl;
    else
        cout << "Equal" << endl;

    //2
    cout << "\n 2. Enter  text : ";
    cin.getline(arr, 255);

    int letters = 0, digits = 0, spaces = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (isalpha(arr[i])) letters++;
        else if (isdigit(arr[i])) digits++;
        else if (arr[i] == ' ') spaces++;
    }
    cout << "Letters : " << letters << endl;
    cout << "Digits : " << digits << endl;
    cout << "Spaces : " << spaces << endl;

    //3
    cout << "\n 3. Enter  text :  ";
    cin.getline(arr, 255);

    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (isupper(arr[i]))
            arr[i] = tolower(arr[i]);
        else if (islower(arr[i]))
            arr[i] = toupper(arr[i]);
    }
    cout << "Result : " << arr << endl;

    // 4
    cout << "\n 4. Enter  text :  ";
    cin.getline(arr, 255);
    cout << "Length : " << myStrlen(arr) << endl;

    // 5
    cout << "\n 5. Enter  text :  ";
    cin.getline(arr, 255);

    char letter;
    cout << "Which char to remove : ";
    cin >> letter;
    cin.ignore();   

    int k = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] != letter)
        {
            arr2[k] = arr[i];
            k++;
        }
    }
    arr2[k] = '\0';
    cout << "New string : " << arr2 << endl;

    //6
    cout << "\n 6. Enter  text :  ";
    cin.getline(arr, 255);

    int whitespaces = 0, vowels = 0, consonants = 0, punct = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (isspace(arr[i]))
        {
            whitespaces++;
        }
        else if (isalpha(arr[i]))
        {
            char l = tolower(arr[i]);
            if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')
                vowels++;
            else
                consonants++;
        }
        else if (ispunct(arr[i]))
        {
            punct++;
        }
    }
    cout << whitespaces << endl;
    cout << vowels << endl;
    cout << consonants << endl;
    cout << punct << endl;


}