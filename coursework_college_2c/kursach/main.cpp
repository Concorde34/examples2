#include <iostream>
#include <fstream>
#include <cstring>
#include "Patient.h"
#include "main.h"

// Доделать методы addPatient(), choseDiagn(), choseLastDoc();

using namespace std;

ofstream writeFile;
ifstream readFile;

const string path("data.txt");

int main()
{
    setlocale(LC_ALL, "rus");

    readFile.exceptions(ifstream::badbit | ifstream::failbit);
    writeFile.exceptions(ofstream::badbit | ofstream::failbit);

    int getInp;
    do
    {
        system("clear");
        cout << '\t' << "Главное меню:" << endl
             << endl;
        cout << "1. Просмотр существующего файла пациентов" << endl;
        cout << "2. Добавление информации про пациентов" << endl;
        cout << "3. Редактирование записей" << endl;
        cout << "4. Удаление записей" << endl;
        cout << "5. Сортирование информации" << endl;
        cout << "6. Выполнение запросов" << endl;
        cout << "7. Выход из программы" << endl;

        cout << "Введите номер пункта меню:\t";

        cin >> getInp;

        switch (getInp)
        {
        case 1:
            displayFile();
            break;
        case 2:
            addPatient();
            break;
        case 3:
            editFile();
            break;
        case 4:
            removePatient();
            break;
        case 5:
            sortInfo();
            break;
        case 6:
            queryExec();
        default:
            break;
        }

    } while (getInp != 7);

    return 0;
}

void displayFile()
{
    try
    {
        readFile.open(path);
    }
    catch(const ifstream::failure & e)
    {
        system("clear");
        cout << "Ошибка чтения файла" << endl << "Внесите записи прежде чем открывать файл";
        getchar();
        getchar();
        return;
    }

    readFile.close();
}

void addPatient ()
{

    try
    {
        writeFile.open(path, ofstream::app);
    }
    catch(const std::exception& e)
    {
        system("clear");
        cout << "Ошибка записи файла!" << endl;  
        getchar();
        getchar();
        return;      
    }

    system("clear");    // Я работаю на линуксе поэтому я использую system("clear") вместо system("cls");
    Patient patient;

    cout << "Добавление пацента: " << endl;
    cout << "Введите ФИО пациента: " << endl;
    while(true)
    {
        cout << "Введите Фамилию : ";
        cin >> patient.pLastname;
        if(Patient::isLastname(patient.pLastname))
        {
            break;
        }
        else
        {
            cout << endl << "Неверный формат фамилии. Повторите попытку ввода" << endl;
        }
    }
    patient.pLastname = Patient::doLastname(patient.pLastname);
    while(true)
    {
        cout << endl << "Введите Инициалы: (Имя, первая буква):\t";
        cin >> patient.Pf;
        if(Patient::isInit(&patient.Pf))
        {
            break;
        }
        else
        {
            cout << endl << "Неверный формат инициалов. Повторите попытку ввода" << endl;
        }
    }
    while (true)
    {
        cout << endl << "Введите Инициалы: (Отчество, первая буква):\t";
        cin >> patient.Pp;
        if(Patient::isInit(&patient.Pp))
        {
            break;
        }
        else 
        {
            cout << endl << "Неверный формат инициалов. Повторите пожалуйста попытку ввода" << endl;
        }
    }
    
    system("clear");    // Я работаю на линуксе поэтому я использую system("clear") вместо system("cls");

    while(true)
    {
        cout << endl << "Введите дату рождения пациента: " << endl << "День: ";
        cin >> patient.day;
        if(Patient::isDay(patient.day))
        {
            break;
        }
        else
        {
            cout << endl << "Неверный ввод! Повторите попытку" << endl;
        }
    }

    while(true)
    {
        cout << endl << "Введите дату рождения пациента: " << endl << "Месяц: ";
        cin >> patient.month;
        if(Patient::isMonth(patient.month))
        {
            break;
        }
        else
        {
            cout << endl << "Неверный ввод! Повторите попытку" << endl;
        }
    }

    while(true)
    {
        cout << endl << "Введите дату рождения пациента: " << endl << "Год: ";
        cin >> patient.year;
        if(Patient::isYear(patient.year))
        {
            break;
        }
        else
        {
            cout << endl << "Неверный ввод! Повторите попытку" << endl;
        }
    }

    patient.setDep();  // Выбор отделения пользователем

    getchar();
    getchar(); // в моем компиляторе нету system("pause"), а getchar() работает только если его прописать два раза
    


    system("clear");
    
    patient.setDoc();       // Выбор доктора пользователем
    cout << "Введите диагноз пациента:\t";
    patient.setDiagn();     // Выбор диагноза пользователем

    getchar();
    getchar();

    // Выбор даты поступления пациента на учет и его выписки.

    while(true)
    {
        cout << "Введите дату поступления пациента на учет: " << endl;
        cout << "Введите день: ";
        cin >> patient.day1;
        if(patient.isDay)
        {
            break;
        }
        else
        {
            cout << endl << "Неверный формат даты. Повторите ввод" << endl;
        }
    }
    while(true)
    {
        cout << "Введите дату поступления пациента на учет: " << endl;
        cout << "Введите месяц: ";
        cin >> patient.month1;
        if(patient.month1)
        {
            break;
        }
        else
        {
            cout << endl << "Неверный формат даты. Повторите ввод" << endl;
        }
    }
    while(true)
    {
        cout << "Введите дату поступления пациента на учет: " << endl;
        cout << "Введите год: ";
        cin >> patient.month1;
        if(patient.year1)
        {
            break;
        }
        else
        {
            cout << endl << "Неверный формат даты. Повторите ввод" << endl;
        }
    }
    while(true)
    {
        cout << "Введите дату выписки пациента с учета: " << endl;
        cout << "Введите день: ";
        cin >> patient.day2;
        if(patient.isDay)
        {
            break;
        }
        else
        {
            cout << endl << "Неверный формат даты. Повторите ввод" << endl;
        }
    }
    while(true)
    {
        cout << "Введите дату поступления пациента на учет: " << endl;
        cout << "Введите месяц: ";
        cin >> patient.month2;
        if(patient.isMonth)
        {
            break;
        }
        else
        {
            cout << endl << "Неверный формат даты. Повторите ввод" << endl;
        }
    }
    while(true)
    {
        cout << "Введите дату поступления пациента на учет: " << endl;
        cout << "Введите год: ";
        cin >> patient.year1;
        if(patient.isYear)
        {
            break;
        }
        else
        {
            cout << endl << "Неверный формат даты. Повторите ввод" << endl;
        }
    }

    system("clear");
    cout << "Попытка сохранения данных в файл...." << endl;
       
}

void editFile()         // Изменить информацию о пациентах
{}

void removePatient()    // Удалить пацента
{}

void sortInfo() // Сортировка информации о пациентах
{}

void queryExec()    // Обработка запросов
{
    int getInp;
    do
    {
        system("clear");    // Я работаю на линуксе поэтому я использую system("clear") вместо system("cls");
        cout << '\t' << "Выберите запрос:" << endl
            << endl;
        cout << "1. Общее количество пациентов (по дате вхождения в стационар)" << endl;
        cout << "2. Самый распространенный диагноз (по отделению) " << endl;
        cout << "3. Самые загруженные врачи" << endl;
        cout << "4. процентное соотношение (по отделению) количества \n \t пациентов, которые сейчас находятся на стационарном лечении" << endl;
        cout << "5. список и средний возраст пациентов, которых курирует выбранный врач" << endl;
        cout << "6. Выполнение запросов" << endl;
        cout << "7. Перейти в главное меню" << endl;

        cout << "Введите номер пункта меню:\t";

        cin >> getInp;

        switch (getInp)
        {
        case 1:
            foo1();
        case 2:
            foo2();
        case 3:
            foo3();
        case 4:
            foo4();
        case 5:
            foo5();
        case 6:
            foo6();
        case 7:
            return;
        default:
            break;
        }

    } while (getInp != 7);
}

void foo1()
{

}

void foo2()
{

}

void foo3()
{

}

void foo4()
{

}

void foo5()
{}

void foo6()
{}
