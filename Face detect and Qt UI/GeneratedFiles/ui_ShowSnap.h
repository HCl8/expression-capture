/********************************************************************************
** Form generated from reading UI file 'ShowSnap.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWSNAP_H
#define UI_SHOWSNAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MySlider.h"
#include "Screen.h"

QT_BEGIN_NAMESPACE

class Ui_ShowSnap
{
public:
    QVBoxLayout *verticalLayout;
    Screen *screen;
    MySlider *slider;

    void setupUi(QWidget *ShowSnap)
    {
        if (ShowSnap->objectName().isEmpty())
            ShowSnap->setObjectName(QStringLiteral("ShowSnap"));
        ShowSnap->resize(576, 406);
        verticalLayout = new QVBoxLayout(ShowSnap);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        screen = new Screen(ShowSnap);
        screen->setObjectName(QStringLiteral("screen"));

        verticalLayout->addWidget(screen);

        slider = new MySlider(ShowSnap);
        slider->setObjectName(QStringLiteral("slider"));
        slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider);


        retranslateUi(ShowSnap);

        QMetaObject::connectSlotsByName(ShowSnap);
    } // setupUi

    void retranslateUi(QWidget *ShowSnap)
    {
        ShowSnap->setWindowTitle(QApplication::translate("ShowSnap", "ShowSnap", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowSnap: public Ui_ShowSnap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWSNAP_H
