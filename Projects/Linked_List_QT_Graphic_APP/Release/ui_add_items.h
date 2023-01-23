/********************************************************************************
** Form generated from reading UI file 'add_items.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_ITEMS_H
#define UI_ADD_ITEMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_items
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *numbers;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *finish_button;
    QPushButton *save_button;

    void setupUi(QDialog *add_items)
    {
        if (add_items->objectName().isEmpty())
            add_items->setObjectName("add_items");
        add_items->resize(529, 328);
        layoutWidget = new QWidget(add_items);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(130, 50, 248, 121));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(25);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        numbers = new QLineEdit(layoutWidget);
        numbers->setObjectName("numbers");
        numbers->setAcceptDrops(true);
        numbers->setInputMethodHints(Qt::ImhNone);

        horizontalLayout->addWidget(numbers);


        verticalLayout->addLayout(horizontalLayout);

        layoutWidget_2 = new QWidget(add_items);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(120, 190, 271, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setSpacing(23);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        finish_button = new QPushButton(layoutWidget_2);
        finish_button->setObjectName("finish_button");

        horizontalLayout_2->addWidget(finish_button);

        save_button = new QPushButton(layoutWidget_2);
        save_button->setObjectName("save_button");

        horizontalLayout_2->addWidget(save_button);


        retranslateUi(add_items);

        QMetaObject::connectSlotsByName(add_items);
    } // setupUi

    void retranslateUi(QDialog *add_items)
    {
        add_items->setWindowTitle(QCoreApplication::translate("add_items", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("add_items", "Enter a new list item", nullptr));
        label_2->setText(QCoreApplication::translate("add_items", "New Item:", nullptr));
#if QT_CONFIG(statustip)
        numbers->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        finish_button->setText(QCoreApplication::translate("add_items", "Finish adding", nullptr));
        save_button->setText(QCoreApplication::translate("add_items", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_items: public Ui_add_items {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_ITEMS_H
