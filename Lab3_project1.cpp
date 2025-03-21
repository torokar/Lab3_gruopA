//Группа А
#include <iostream>
#include <vector>
#include <ctime>


int main()
{
    setlocale(LC_ALL, "ru");
    int size_vec = 12; 
    double tmp;
    std::vector<double> Xn; 
    std::vector<double> Xi; 
    std::vector<double> B;  

    std::cout << "Каким способом заполнить вектор:\n";
    std::cout << "1 - Ручной ввод\n";
    std::cout << "2 - Автоматический ввод\n";
    std::cout << "--> ";

    int choice;
    
    do
    {

        std::cin >> choice;
        system("cls");
        if (choice == 0)
        {
            std::cout << "Выход из программы\n";
            return 0;
        }
        if (std::cin.fail() || choice > 2 || choice < 1)
        {
            std::cout << "Некорректный ввод! Попробуйте еще!\n--> ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    } while (choice > 2 || choice < 1);

    switch (choice)
    {
    case 1:
    {
        std::cout << "Ручной ввод элементов вектора\n";
        std::cout << "Введите значения для вектора\n";
        for (int i = 0; i < size_vec; i++)
        {
            std::cout << "--> ";
            std::cin >> tmp;
            Xn.push_back(tmp);
        }
        break;
    }
    case 2:
    {
        std::cout << "Автоматический ввод элементов вектора\n\n";
        srand(time(NULL));
        for (int i = 0; i < size_vec; i++)
        {
            int num = rand();
            num = num - (RAND_MAX / 2);
            Xn.push_back(num);
        }
        break;
    }

    default:
    {
        std::cout << "Некорректный ввод!\n";
        break;
    }
    }

    std::cout << "Полученный вектор Xn:\n\n";
    
    std::string str(230, '--' );
    std::cout << str << std::endl << std::endl;
    for (int i = 0; i < size_vec; i++)
    {
        std::cout << Xn[i] << " ";
    }
    std::cout << std::endl << std::endl << str << std::endl << std::endl;


    double max = *std::max_element(Xn.begin(), Xn.end());
    double min = *std::min_element(Xn.begin(), Xn.end());
    std::cout << "Максимальный элемент: " << max << std::endl;
    std::cout << "Минимальный элемент: " << min << std::endl << std::endl;


    double M = (min + max) / 2;
    std::cout << "Значение M = " << M << std::endl << std::endl;


    for (int i = 0; i < size_vec; i++)
    {
        if (Xn[i] > M)
        {
            Xi.push_back(Xn[i]);
        }
    }

    std::cout << "Вектор Xi (элементы, превышающие M):\n";
    for (int i = 0; i < Xi.size(); i++)
    {
        std::cout << Xi[i] << " ";
    }
    std::cout << std::endl << std::endl;


    for (int i = 0; i < Xi.size(); i++)
    {
        if (Xi[i] > M)
        {
            B.push_back(Xi[i]);
        }
    }

    std::cout << "Вектор B (элементы из Xi, превышающие M):\n";
    for (int i = 0; i < B.size(); i++)
    {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl << std::endl;
    return 0;
}
