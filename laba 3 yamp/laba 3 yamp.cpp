// laba 3 yamp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    setlocale(0, "rus");
   // char s[50];
    int a[12] = { 5, 12,  34, 2123, 4, 123, 54, 3121, 34, 52, 12, 96 }; //Делаем изначальный файл
    ofstream start;
    start.open("C:\\Users\\IDler\\Desktop\\merge.txt");
    for (int i = 0; i < 12; i++) {
        start << a[i]<< " ";
    }
    start.close();



    int counter=0;
    while (true) {                              //Первый этам сортировки
        ofstream help1;
        ofstream help2;
        ifstream merge;
        help1.open("C:\\Users\\IDler\\Desktop\\help1.txt");
        help2.open("C:\\Users\\IDler\\Desktop\\help2.txt");
        merge.open("C:\\Users\\IDler\\Desktop\\merge.txt");
        // fout2.get(s, 50);
        int d;
        int count;
        bool checkHelp = true;    // true - записываем в первый файл false записываем во второй файл
        merge >> count;
        help1 << count << " ";
        while (true) {
            
            merge >> d;
            if (merge.eof()) break;
            if (d >= count && checkHelp) {                // если последовательость соблюдается и записывали в первый - опять запишем в первый 
                help1 << d << " ";
            }
            if (d >= count && !checkHelp) {               // если последовательость соблюдается и записывали во второй  - опять запишем во второй  
                help2 << d << " ";
            }
            if (d < count && checkHelp) {
                help2 << d << " ";
                checkHelp = !checkHelp;
                count = d;
                counter++;
                //cout << d << " ";
                continue;
               
            }
            if (d < count && !checkHelp) {
                help1 << d << " ";
                checkHelp = !checkHelp;
                count = d;
                counter++;
               // cout << d << " ";
                continue;
            }
            count = d;

          //  cout << d << " ";
        }
        merge.close();
        help1.close();
        help2.close();
        cout << endl;
        if (counter == 0) break;              //проверка если на предыдущем этапе не было ни одного перехода в другой файл, то сортировка окончена 
        counter = 0;
        ifstream help11;
        ifstream help22;
        ofstream merge1;
        help11.open("C:\\Users\\IDler\\Desktop\\help1.txt");
        help22.open("C:\\Users\\IDler\\Desktop\\help2.txt");
        merge1.open("C:\\Users\\IDler\\Desktop\\merge.txt");
        help11 >> count;
        help22 >> d;
        while (!help11.eof() || !help22.eof()) {                          //Второй этап сортировки т.е слияние 
            if (help22.eof()) {
                while (true) {
                    if (help11.eof()) break;
                    merge1 << count << " ";
                    help11 >> count;
                }
                break;
            }
            if (help11.eof()) {
                while (true) {
                    if (help22.eof()) break;
                    merge1 << d << " ";
                    help22 >> d;
                }
                break;
            }
            if (count >= d) {
                merge1 << d << " ";
                help22 >> d;
            }
            else {
                merge1 << count << " ";
                help11 >> count;
            }
        }
        help11.close();
        help22.close();
        merge1.close();
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
