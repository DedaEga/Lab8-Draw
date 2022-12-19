#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
    // Объявляем переменную N и считываем ее значение с клавиатуры
    int N;
    cout << "Enter N: ";
    cin >> N;
    // Инициализируем вектор, который будет хранить вытянутые бочонки
    vector <bool> drawn;;
    for (int i = 0; i < N; i++)
        drawn.push_back(false);
    cin.get();
    // В цикле вытаскиваем бочонки из мешка
    for (int i = 0; i < N; i++)
    {
        // Генерируем случайное число от 0 до N-1
        int r = rand() % N;

        // Если бочонок уже был вытянут, генерируем новое случайное число
        while (drawn[r])
            r = rand() % N;

        // Вытаскиваем бочонок с номером r
        cout << "Drawn: " << r + 1 << endl;

        // Отмечаем бочонок как вытянутый
        drawn[r] = true;
        cin.get();
    }
    return 0;
}