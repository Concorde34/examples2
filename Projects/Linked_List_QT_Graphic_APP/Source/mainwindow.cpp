#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "add_items.h"
#include "listview.h"
#include <QDebug>
#include "LListVar.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Header", "Do you want to close the programm?",
                                  QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}


void MainWindow::on_actionQuit_Program_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quit", "Do you want to close the programm?",
                                  QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "The program demonstrates "
                                      "working with singly linked lists. "
                                      "Data storage and all operations on "
                                      "them are implemented using singly linked lists.");
}


void MainWindow::on_pushButton_5_clicked()
{
    add_items add_window;
    add_window.setModal(true);
    add_window.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    if(list.getSize() > 0)
    {
        ListView view_window;
        view_window.setModal(false);
        view_window.exec();
    }
    else
    {
        QMessageBox::warning(this, "Warning!", "The list cannot be displayed. "
                                       "It's empty. To get started, "
                                       "enter at least one element.");
    }

}


void MainWindow::on_pushButton_6_clicked()
{
    list.remove();

    QMessageBox::warning(this, "Remove the List", "The Linked List is succesfully removed");
}


void MainWindow::on_actionProblem_triggered()
{
    QMessageBox::information(this, "Problem", "Create a singly "
                                              "linked list of real "
                                              "numbers by inserting "
                                              "a new element at the "
                                              "beginning of the list. "
                                              "Find and output the"
                                              " maximum and minimum "
                                              "list elements and their "
                                              "sum. Remove all minimum "
                                              "items from the list.");
}


void MainWindow::on_pushButton_clicked()
{
    QString string;


    if(list.getSize() == 0)
    {
        string = "Calculation error, list is empty.";
    }
    else if(list.getSize() == 1)
    {
        string = "The specified value could not be found. "
                 "There is only one element in the list.";
    }
    else if(list.getSize() > 1)
    {
        if(list.allIsIdent())
        {
            string = "All elements of the list are the same, "
                     "so it is not possible to find the minimum "
                     "and maximum elements.";
        }
        else
        {
            int sum = list.getMax() + list.getMin();
            string = "Minimum element: " + QString::number(list.getMin()) + "\n" +
                    "Maximum element: " + QString::number(list.getMax()) + "\n" +
                    "Sum of minimum and maximum elements: " + QString::number(sum);
            if(list.getIsProcessed())
            {
                string += "\n(All minimal elements have been removed. When listing elements, "
                        "you will no longer be able to see them.)";
            }

        }
    }

    QMessageBox::information(this, "Max, Min and Sum", string);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString string;
    if(!list.getIsProcessed())
    {
        if(list.getSize() == 0)
        {
            string = "Processing error, list is empty.";
        }
        else if(list.getSize() == 1)
        {
            string = "The list cannot be processed because "
                     "it has only one element.";
        }
        else if(list.getSize() > 1)
        {
            if(list.allIsIdent())
            {
                string = "All elements of the list are the same, "
                         "so it is not possible to processed the list ";
            }
            else
            {
                list.remAllMin();
                string = "The singly linked list has been processed. "
                         "All minimal elements have been removed from the list.";
            }
        }
    }
    else
    {
        string = "The list has already been processed. You cannot process the list a second time.";
    }

    QMessageBox::information(this, "Remove all minimum", string);
}

