#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QDialog>

namespace Ui {
class ListView;
}

class ListView : public QDialog
{
    Q_OBJECT

public:
    explicit ListView(QWidget *parent = nullptr);
    ~ListView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ListView *ui;
};

#endif // LISTVIEW_H
