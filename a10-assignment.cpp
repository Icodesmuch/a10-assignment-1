#include <iostream>
using namespace std;

// function prototypes
float subtraction(float, float);
float addition(float, float);
float addition(float, float, float);
float mulitiply(float, float);
float divide(float, float);
float factorial(float);
void promptNumbers(char, float &, float &, float &);
void printResult(float);
void menu(char &optionReference);

int main()
{
    char option;                    // automatic variable
    char &optionReference = option; // reference variable
    float num1;
    float num2;
    float num3;
    float result;
    do
    {
        static int calculationsCount = 0; // static variable
        num1 = 0.0f;
        num2 = 0.0f;
        num3 = 0.0f;
        result = 0.0f;

        // print menu
        menu(optionReference);

        if (option != '6')
        {
            promptNumbers(optionReference, num1, num2, num3); // nesting function
        }

        switch (option)
        {
        case '1':
            if (num3 > 0)
            {
                result = addition(num1, num2, num3);
            }
            else
            {
                result = addition(num1, num2);
            }
            printResult(result);
            calculationsCount++;

            break;
        case '2':
            result = subtraction(num1, num2);
            printResult(result);
            calculationsCount++;
            break;

        case '3':
            result = mulitiply(num1, num2);
            printResult(result);
            calculationsCount++;
            break;

        case '4':
            result = divide(num1, num2);
            printResult(result);
            calculationsCount++;
            break;

        case '5':
            result = factorial(num1);
            printResult(result);
            calculationsCount++;
            break;
        case '6':
            cout << "You did " << calculationsCount << " calculations today";
            break;

        default:
            cout << "Invalid input.";
            break;
        }

    } while (option != '6');

    return 0;
}

void menu(char &optionReference)
{
    cout << "\n\nSelect an option below\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "5. Factorial\n";
    cout << "6. Quit\n";
    cin >> optionReference;
}

float subtraction(float num1, float num2 = 0) // default argument
{
    return num1 - num2;
}

float addition(float num1, float num2)
{
    return num1 + num2;
}

float addition(float num1, float num2, float num3) // function overloading
{
    return num1 + num2 + num3;
}

float mulitiply(float num1, float num2)
{
    return num1 * num2;
}

float divide(float num1, float num2)
{
    return num1 / num2;
}

float factorial(float num) // recursive function
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}

void promptNumbers(char option, float &num1, float &num2, float &num3) // reference parameter
{
    char choice;

    if (option == '1')
    {
        cout << "\nDo you want to add 2 or 3 numbers: ";
        cin >> choice;
        if (choice == '2')
        {
            cout << "\nEnter num1: ";
            cin >> num1;

            cout << "Enter num2: ";
            cin >> num2;
        }
        else if (choice == '3')
        {
            cout << "\nEnter num1: ";
            cin >> num1;

            cout << "Enter num2: ";
            cin >> num2;

            cout << "Enter num3: ";
            cin >> num3;
        }
    }
    else if (option == '5')
    {
        cout << "\nEnter num1: ";
        cin >> num1;
    }
    else
    {
        cout << "\nEnter num1: ";
        cin >> num1;

        cout << "Enter num2: ";
        cin >> num2;
    }
}

void printResult(float result)
{
    cout << "\nThe answer is: " << result;
}
