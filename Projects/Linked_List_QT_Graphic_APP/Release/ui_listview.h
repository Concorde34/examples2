/********************************************************************************
** Form generated from reading UI file 'listview.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTVIEW_H
#define UI_LISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ListView
{
public:
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *ListView)
    {
        if (ListView->objectName().isEmpty())
            ListView->setObjectName("ListView");
        ListView->resize(575, 380);
        listWidget = new QListWidget(ListView);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(70, 70, 401, 241));
        label = new QLabel(ListView);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 20, 101, 31));
        pushButton = new QPushButton(ListView);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 330, 401, 31));

        retranslateUi(ListView);

        QMetaObject::connectSlotsByName(ListView);
    } // setupUi

    void retranslateUi(QDialog *ListView)
    {
        ListView->setWindowTitle(QCoreApplication::translate("ListView", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ListView", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; text-decoration: underline;\">Your List: </span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("ListView", "back to main menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListView: public Ui_ListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTVIEW_H
