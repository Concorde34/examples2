#include "add_items.h"
#include "ui_add_items.h"
#include <QValidator>
#include "LListVar.h"

add_items::add_items(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_items)
{
    ui->setupUi(this);
    validator = new QIntValidator(-2147483648, 2147483647, this);
    ui->numbers->setValidator(validator);
    ui->finish_button->setDefault(false);
    ui->save_button->setDefault(true);
}

add_items::~add_items()
{
    delete ui;
    delete validator;
}

void add_items::on_save_button_clicked()
{

    if(ui->numbers->text() != "")
    {
        int data = ui->numbers->text().toInt();
        list.push_back(data);
        ui->numbers->clear();
    }
}


void add_items::on_finish_button_clicked()
{
    add_items::close();
}

