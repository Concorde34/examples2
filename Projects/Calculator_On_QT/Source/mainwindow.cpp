#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->pushButton_plusminus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton* button = (QPushButton*) sender();
    QString new_label;
    double all_numbers;

    if (ui->label_result->text().contains(".") && button->text() == "0")
    {
        new_label = ui->label_result->text() + button->text();
    }
    else
    {
        all_numbers = (ui->label_result->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 11);
    }

    ui->label_result->setText(new_label);
}


void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->label_result->text().contains('.')))
    {
        ui->label_result->setText(ui->label_result->text() + '.');
    }

}

void MainWindow::operations()
{
    QPushButton* button = (QPushButton*) sender();
    QString new_label;
    double all_numbers;

    if(button->text() == "+/-")
    {
        all_numbers = (ui->label_result->text()).toDouble();
        all_numbers *= -1;
        new_label = QString::number(all_numbers, 'g', 11);
        ui->label_result->setText(new_label);
    }
    else if(button->text() == '%')
    {
        all_numbers = (ui->label_result->text()).toDouble();
        all_numbers *= 0.01;
        new_label = QString::number(all_numbers, 'g', 11);
        ui->label_result->setText(new_label);
    }
}

void MainWindow::math_operations()
{
    QPushButton* button = (QPushButton*) sender();

    num_first = ui->label_result->text().toDouble();
    ui->label_result->setText("");
    button->setChecked(true);
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_divide->setChecked(false);

    ui->label_result->setText("0");
}


void MainWindow::on_pushButton_equals_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->label_result->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label_result->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked())
    {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label_result->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_mult->isChecked())
    {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label_result->setText(new_label);
        ui->pushButton_mult->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked())
    {
        if(num_second == 0)
        {
            QMessageBox::warning(this, "Division by zero", "Division by zero is meaningless");
            ui->label_result->setText("0");
        }
        else
        {
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber, 'g', 15);
            ui->label_result->setText(new_label);
        }
        ui->pushButton_divide->setChecked(false);
    }
}












