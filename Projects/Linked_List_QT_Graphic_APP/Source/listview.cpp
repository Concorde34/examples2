#include "listview.h"
#include "ui_listview.h"
#include "LListVar.h"

ListView::ListView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);
    list.DebugPrint();
    for(int i = 0; i < list.getSize(); i++)
    {
        ui->listWidget->addItem(QString::number(list.getElement(i)));
    }
}

ListView::~ListView()
{
    delete ui;
}

void ListView::on_pushButton_clicked()
{
    ListView::close();
}

