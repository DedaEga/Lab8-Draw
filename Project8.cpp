#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <chrono>


using namespace std;
void GetInput(int& x) {
    fstream out;
    string path = "logs.txt";
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);
    out.open(path, fstream::in | fstream::out | fstream::app);
#pragma warning(suppress : 4996)
    out << std::ctime(&end_time) << "Pol'zovatel' vvel: " << x << endl;
}
void GetOutput(string& outp) {
    fstream out;
    string path = "logs.txt";
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);
    out.open(path, fstream::in | fstream::out | fstream::app);
#pragma warning(suppress : 4996)
    out << std::ctime(&end_time) << outp << endl;
}

int main()
{
    // Объявляем переменную N и считываем ее значение с клавиатуры
    int N;
    string outp;
    outp = "Enter N: ";
    GetOutput(outp);
    cout << outp;
    cin >> N;
    GetInput(N);
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
        outp = "Drawn: "+ to_string(r + 1);
        cout << outp << endl;
        GetOutput(outp);

        // Отмечаем бочонок как вытянутый
        drawn[r] = true;
        cin.get();
    }
    return 0;
}