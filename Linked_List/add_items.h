#ifndef ADD_ITEMS_H
#define ADD_ITEMS_H

#include <QDialog>
#include <QValidator>

namespace Ui {
class add_items;
}

class add_items : public QDialog
{
    Q_OBJECT

public:
    explicit add_items(QWidget *parent = nullptr);
    ~add_items();

private slots:
    void on_save_button_clicked();

    void on_finish_button_clicked();

private:
    Ui::add_items *ui;
    QValidator* validator;
};

#endif // ADD_ITEMS_H
