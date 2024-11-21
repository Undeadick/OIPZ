#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("resultsForY.txt");

// Функція перевірки вхідних даних
void checkData(int n, double x, double b, double h)
{
    if (n < 3 || x > b || h <= 0)
    {
        throw "incorrect";
    }
}

// Функція для отримання даних від користувача
void getData(int& n, double& a, double& b, double& h, double& yesNO) {
    cout << "Enter n: "; // Введіть n
    cin >> n;
    cout << "Enter a: "; // Введіть a
    cin >> a;
    cout << "Enter b: "; // Введіть b
    cin >> b;
    cout << "Enter h: "; // Введіть h
    cin >> h;
    cout << "Enter 0 to save answers to a file: "; // Введіть 0, щоб записати відповіді у файл
    cin >> yesNO;
}

// Функція для підрахунку значень функції та їх виведення
double y(int n, double x)
{
    double y = 0;
    if (x > 0)
    {
        for (int i = 0; i <= n - 1; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                y += (i + 1) / (j + x);
            }
        }
    }
    else
    {
        for (int i = 2; i <= n - 1; i++)
        {
            y += (x - 1) / i;
        }
    }
    return y;
}

// Функція для друку результатів
void Print(double a, double b, double h, double yesNO, int n)
{
    double total = 0;
    for (double x = a; x <= b; x += h)
    {
        total += y(n, x);
        cout << " (x=" << x << ")" << ", y = " << y(n, x) << endl;
        if (yesNO == 0)
        {
            fout << " (x=" << x << ")" << ", y = " << y(n, x) << endl;
        }
    }
    cout << "\nTotal sum = " << total; // новий елемент програми
}

int main() {
    setlocale(LC_ALL, "UKRAINIAN"); // встановлення української локалізації
    int n;
    double a, b, h, yesNO;
    getData(n, a, b, h, yesNO);
    try // перевірка
    {
        checkData(n, a, b, h);
    }
    catch (const char* exit) // відома помилка
    {
        cout << exit;
        return -1;
    }
    catch (...) // невідома помилка 
    {
        cout << "Enter different values "; // Введіть інші значення
        return -2;
    }
    Print(a, b, h, yesNO, n);
    return 0;
}
