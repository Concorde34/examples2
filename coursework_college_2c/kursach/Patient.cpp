#include "Patient.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Patient::Patient() : pLastname(""),
                     Pf(""),
                     Pp(""),
                     day(0),
                     month(0),
                     year(0),
                     department(""),
                     dName(""),
                     diagnosis(""),
                     day1(0),
                     month1(0),
                     year1(0),
                     day2(0),
                     month2(0),
                     year2(0)
{
}

bool Patient::isDay(int d)
{
    if (d >= 1 && d <= 31)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Patient::isMonth(int m)
{
    if (m >= 1 && m <= 12)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Patient::isYear(int y)
{
    if (y >= 1900 && y <= 2022)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Patient::isLastname(string lastname)
{
    if (lastname.size() > 1 && lastname.size() <= 20)
    {
        for (size_t i = 0; i < lastname.size(); i++)
        {
            if (!(isalpha(lastname[i])))
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

string Patient::doLastname(string lastname)
{
    lastname[0] = toupper(lastname[0]);
    for (size_t i = 0; i < lastname.size(); i++)
    {
        lastname[i] = tolower(lastname[i]);
    }
    return lastname;
}

bool Patient::isInit(string *init)
{
    if (init->size() == 1)
    {
        string tmp = *init;
        if (isalpha(tmp[0]))
        {
            return true;
        }
    }
    return false;
}

void Patient::setDoc()
{
    int getInp;
    system("clear");
    if (department == "Кардиологическое")
    {
        bool quit = false;
        while (!quit)
        {
            cout << "Выберите врача: ";
            cout << endl
                 << "1. Мороженец В.А.";
            cout << endl
                 << "2. Должикова П.Ю.";
            cout << endl
                 << "3. Карин Т.С.";
            cout << endl
                 << "4. Войцеховский Т.А.";
            cout << endl
                 << "5. Дипченко А.Д.";
            cout << endl
                 << "Ваш выбор: ";
            cin >> getInp;
            switch (getInp)
            {
            case 1:
                dName = "Мороженец В.А.";
                break;
            case 2:
                dName = "Должикова П.Ю.";
                break;
            case 3:
                dName = "Карин Т.С.";
                break;
            case 4:
                dName = "Войцеховский Т.А.";
                break;
            case 5:
                dName = "Дипченко А.Д.";
                break;
            case 6:
                dName = "Дипченко А.Д.";
                break;
            default:
                cout << endl
                     << "Неверный ввод, повторите попытку" << endl;
            }
        }
    }
    else if (department == "Урологическое")
    {
        bool quit = false;
        while (!quit)
        {
            cout << "Выберите врача: ";
            cout << endl
                 << "1. Сухов А.И.";
            cout << endl
                 << "2. Крусько Т.С.";
            cout << endl
                 << "3. Чулов Б.И.";
            cout << endl
                 << "Ваш выбор: ";
            cin >> getInp;
            switch (getInp)
            {
            case 1:
                dName = "Сухов А.И.";
                quit = true;
                break;
            case 2:
                dName = "Крусько Т.С.";
                quit = true;
                break;
            case 3:
                dName = "Чулов Б.И.";
                quit = true;
                break;
            default:
                cout << endl
                     << "Неверный ввод, повторите попытку" << endl;
            }
        }
    }
    else if (department == "Хирургическое")
    {
        bool quit = false;
        while (!quit)
        {
            cout << "Выберите врача: ";
            cout << endl
                 << "1. Наумов О.В.";
            cout << endl
                 << "2. Петренко Д.В.";
            cout << endl
                 << "3. Вентиль Ш.С.";
            cout << endl
                 << "Ваш выбор: ";
            cin >> getInp;
            switch (getInp)
            {
            case 1:
                dName = "Наумов О.В.";
                quit = true;
                break;
            case 2:
                dName = "Петренко Д.В.";
                quit = true;
                break;
            case 3:
                dName = "Вентиль Ш.С.";
                quit = true;
                break;
            default:
                cout << endl
                     << "Неверный ввод, повторите попытку" << endl;
            }
        }
    }
    else if (department == "Инфекционное")
    {
        bool quit = false;
        while (!quit)
        {
            cout << "Выберите врача: ";
            cout << endl
                 << "1. Манченко А.В.";
            cout << endl
                 << "2. Мандрыкин С.У.";
            cout << endl
                 << "3. Инаненко Б.В.";
            cout << endl
                 << "Ваш выбор: ";
            cin >> getInp;
            switch (getInp)
            {
            case 1:
                dName = "Манченко А.В.";
                quit = true;
                break;
            case 2:
                dName = "Мандрыкин С.У.";
                quit = true;
                break;
            case 3:
                dName = "Инаненко Б.В.";
                quit = true;
                break;
            default:
                cout << endl
                     << "Неверный ввод, повторите попытку" << endl;
            }
        }
    }
    else if (department == "Терапевтическое")
    {
        bool quit = false;
        while (!quit)
        {
            cout << "Выберите врача: ";
            cout << endl
                 << "1. Петреева Ю.В.";
            cout << endl
                 << "2. Соколова Ж.А.";
            cout << endl
                 << "3. Пицік М.В.";
            cout << endl
                 << "4. Ищик А.Д.";
            cout << endl
                 << "5. Соловьев А.К.";
            cout << endl
                 << "Ваш выбор: ";
            cin >> getInp;
            switch (getInp)
            {
            case 1:
                dName = "Петреева Ю.В.";
                quit = true;
                break;
            case 2:
                dName = "Соколова Ж.А.";
                quit = true;
                break;
            case 3:
                dName = "Пицік М.В.";
                quit = true;
                break;
            case 4:
                dName = "Ищик А.Д.";
                quit = true;
                break;
            case 5:
                dName = "Соловьев А.К.";
                quit = true;
                break;
            default:
                cout << endl
                     << "Неверный ввод, повторите попытку" << endl;
            }
        }
    }
    else if (department == "Гастроентерологическое")
    {
        bool quit = false;
        while (!quit)
        {
            cout << "Выберите врача: ";
            cout << endl
                 << "1. Моренко Ж.Ю.";
            cout << endl
                 << "2. Федоренко Ш.С.";
            cout << endl
                 << "3. Антонов П.С.";
            cout << endl
                 << "4. Малышко В.Д.";
            cout << endl
                 << "Ваш выбор: ";
            cin >> getInp;
            switch (getInp)
            {
            case 1:
                dName = "Моренко Ж.Ю.";
                quit = true;
                break;
            case 2:
                dName = "Федоренко Ш.С.";
                quit = true;
                break;
            case 3:
                dName = "Антонов П.С.";
                quit = true;
                break;
            case 4:
                dName = "Малышко В.Д.";
                quit = true;
                break;
            default:
                cout << endl
                     << "Неверный ввод, повторите попытку" << endl;
            }
        }
    }
}

void Patient::setDiagn()
{
    int getInp;
    system("clear");
    if (department == "Кардиологическое")
    {
        bool quit = false;
        while (!quit)
        {
            cout << "1. Выберите диагноз: " << endl;
            cout << "2. Ишемичная болезнь сердца" << endl;
            cout << "3. Перикардит" << endl;
            cout << "4. Ендокардит" << endl;
            cout << "5. Инфаркт миокарда" << endl;
            cout << "6. Миокардит" << endl;
            cout << "Ваш выбор: ";
            cin >> getInp;
            switch (getInp)
            {
            case 1:
                diagnosis = "Ишемичная болезнь сердца";
                quit = true;
                break;
            case 2:
                diagnosis = "Перикардит";
                quit = true;
                break;
            case 3:
                diagnosis = "Ендокардит";
                quit = true;
                break;
            case 4:
                diagnosis = "Инфаркт миокарда";
                quit = true;
                break;
            case 5:
                diagnosis = "Миокардит";
                quit = true;
                break;
            default:
                cout << "Неверный ввод. Повторите попытку ввода" << endl;

            }
        }
    }
    else if (department == "Урологическое")
    {
        bool quit = false;
        while (!quit)
        {
            cout << "1. Выберите диагноз: " << endl;
            cout << "2. Поликистоз почек" << endl;
            cout << "3. Аденокарцинома почки" << endl;
            cout << "4. Цистит" << endl;
            cout << "Ваш выбор: ";
            cin >> getInp;
            switch(getInp)
            {
            case 1:
                diagnosis = "Поликистоз почек";
                quit = true;
                break;
            case 2:
                diagnosis = "Аденокарцинома почки";
                quit = true;
                break;
            case 3:
                diagnosis = "Цистит";
                quit = true;
                break;
            default:
                cout << endl << "Неверный ввод. Повторите попытку!" << endl;
            }
        }
    }
    else if (department == "Хирургическое")
    {
        bool quit = false;
        while (!quit)
        {
            cout << "Выберите диагноз: ";
            cout << "1. Воспаление апендицита"  << endl;
            cout << "2. Травма конечностей" << endl;
            cout << "3. Гангрена" << endl;
            cout << "Ваш выбор: ";
            cin >> getInp;
            switch(getInp)
            {
            case 1:
                diagnosis = "Воспаление апендицита";
                quit = true;
                break;
            case 2:
                diagnosis = "Травма конечностей";
                quit = true;
                break;
            case 3:
                diagnosis = "Гангрена";
                quit = true;
                break;
            default:
                cout << endl << "Неверный ввод. Повторите попытку!" << endl;
            }
        }
    }
    else if (department == "Инфекционное")
    {
        bool quit = false;
        while (!quit)
        {
            cout << "Выберите диагноз: " << endl;
            cout << "1. ГРВИ" << endl;
            cout << "2. Грипп" << endl;
            cout << "3. Бутулизм" << endl;
            cout << "Ваш выбор: ";
            cin >> getInp;
            switch(getInp)
            {
            case 1:
                diagnosis = "ГРВИ";
                quit = true;
                break;
            case 2:
                diagnosis = "Грипп";
                quit = true;
                break;
            case 3:
                diagnosis = "Бутулизм";
                quit = true;
                break;
            default:
                cout << endl << "Неверный ввод. Повторите попытку!" << endl;
            }
        }
    }
    else if (department == "Терапевтическое")
    {
        bool quit = false;
        while (!quit)
        {
            cout << "Выберите врача: ";
            cout << endl;
            cout << "1. Бронхиальная астма";
            cout << endl;
            cout << "2. Анемия";
            cout << endl;
            cout << "3. Диабет";
            cout << endl;
            cout << "4. Вегето-сосудистая дистония";
            cout << endl;
            cout << "5. Остеоартроз";
            cout << endl;
            cout << "Ваш выбор: ";
            cin >> getInp;
            switch (getInp)
            {
            case 1:
                diagnosis = "Бронхиальная астма";
                quit = true;
                break;
            case 2:
                diagnosis = "Анемия";
                quit = true;
                break;
            case 3:
                diagnosis = "Диабет";
                quit = true;
                break;
            case 4:
                diagnosis = "Вегето-сосудистая дистония";
                quit = true;
                break;
            case 5:
                diagnosis = "Остеоартроз";
                quit = true;
                break;
            default:
                cout << endl
                     << "Неверный ввод, повторите попытку" << endl;
            }
        }
    }
    else if (department == "Гастроентерологическое")
    {
        bool quit = false;
        while (!quit)
        {
            cout << "Выберите врача: ";
            cout << endl << "1. Гастрит";
            cout << endl << "2. Язва желудка";
            cout << endl << "3. Холецистит";
            cout << endl << "4. Дисбактериоз";
            cout << endl << "Ваш выбор: ";
            cin >> getInp;
            switch (getInp)
            {
            case 1:
                dName = "Гастрит";
                quit = true;
                break;
            case 2:
                dName = "Язва желудка";
                quit = true;
                break;
            case 3:
                dName = "Холецистит";
                quit = true;
                break;
            case 4:
                dName = "Дисбактериоз";
                quit = true;
                break;
            default:
                cout << endl
                     << "Неверный ввод, повторите попытку" << endl;
            }
        }
    }
}

void Patient::setDep()
{
    int getInp;
    system("clear");
    bool dowhile = true;
    while (dowhile) // Зацикленный ввод отделения, дабы избежать ошибок, если пользователь что-то введет не правильно.
    {
        cout << endl
             << "Выберите отделение в котором состоит пациент: " << endl;
        cout << "1. Кардиологическое" << endl;
        cout << "2. Урологическое" << endl;
        cout << "3. Хирургическое" << endl;
        cout << "4. Инфекционное" << endl;
        cout << "5. Терапевтическое" << endl;
        cout << "6. Гастроентерологическое" << endl;
        cout << endl
             << "Введите ваш выбор: ";

        cin >> getInp;

        switch (getInp)
        {
        case 1:
            department = "Кардиологическое";
            dowhile = false;
            break;
        case 2:
            department = "Урологическое";
            dowhile = false;
            break;
        case 3:
            department = "Хирургическое";
            dowhile = false;
            break;
        case 4:
            department = "Инфекционное";
            dowhile = false;
            break;
        case 5:
            department = "Терапевтическое";
            dowhile = false;
            break;
        case 6:
            department = "Гастроентерологическое";
            dowhile = false;
            break;
        default:
            system("clear");
            cout << endl
                 << "Неверный ввод. Повторите попытку ввода." << endl;
            getchar();
            getchar();
        }
    }
}