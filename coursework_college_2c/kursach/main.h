#pragma once

#include <iostream>

void displayFile();     // Отобразить на экран информацию о пациентах
void addPatient();      // Добавить пациента
void editFile();        // Изменить информацию о пациентах
void removePatient();   // Удалить информацию о пациентах
void sortInfo();        // Сортировка информации о пациентах
void queryExec();       // Обработка запросов

// Вспомогательные функции выполняющие запросы.(вызываются только из функции queryExec())
void foo1();
void foo2();
void foo3(); 
void foo4();
void foo5();
void foo6();



