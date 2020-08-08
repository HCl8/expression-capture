/********************************************************************************
** Form generated from reading UI file 'develop10.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVELOP10_H
#define UI_DEVELOP10_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <Screen.h>
#include <myslider.h>
#include <paintMap.h>

QT_BEGIN_NAMESPACE

class Ui_develop10Class
{
public:
    QAction *File_camera;
    QAction *File_Video;
    QAction *File_Image;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_2;
    Screen *SCREEN;
    MySlider *Slider;
    QListWidget *SnapList;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QProgressBar *progressBar0;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QProgressBar *progressBar1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QProgressBar *progressBar2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QProgressBar *progressBar3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QProgressBar *progressBar4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QProgressBar *progressBar5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QProgressBar *progressBar6;
    QSpacerItem *horizontalSpacer;
    paintMap *HotMap;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *develop10Class)
    {
        if (develop10Class->objectName().isEmpty())
            develop10Class->setObjectName(QStringLiteral("develop10Class"));
        develop10Class->resize(1009, 563);
        File_camera = new QAction(develop10Class);
        File_camera->setObjectName(QStringLiteral("File_camera"));
        File_Video = new QAction(develop10Class);
        File_Video->setObjectName(QStringLiteral("File_Video"));
        File_Image = new QAction(develop10Class);
        File_Image->setObjectName(QStringLiteral("File_Image"));
        centralWidget = new QWidget(develop10Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_8 = new QHBoxLayout(centralWidget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        SCREEN = new Screen(centralWidget);
        SCREEN->setObjectName(QStringLiteral("SCREEN"));

        verticalLayout_2->addWidget(SCREEN);

        Slider = new MySlider(centralWidget);
        Slider->setObjectName(QStringLiteral("Slider"));
        Slider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(Slider);


        horizontalLayout_8->addLayout(verticalLayout_2);

        SnapList = new QListWidget(centralWidget);
        SnapList->setObjectName(QStringLiteral("SnapList"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SnapList->sizePolicy().hasHeightForWidth());
        SnapList->setSizePolicy(sizePolicy);
        SnapList->setMaximumSize(QSize(165, 16777215));

        horizontalLayout_8->addWidget(SnapList);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMaximumSize(QSize(354, 16777215));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout->setContentsMargins(-1, -1, 1, -1);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(54, 0));
        label->setSizeIncrement(QSize(0, 0));
        label->setBaseSize(QSize(0, 0));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        label->setFont(font);

        horizontalLayout_7->addWidget(label);

        progressBar0 = new QProgressBar(widget);
        progressBar0->setObjectName(QStringLiteral("progressBar0"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(progressBar0->sizePolicy().hasHeightForWidth());
        progressBar0->setSizePolicy(sizePolicy3);
        progressBar0->setMaximumSize(QSize(300, 16777215));
        progressBar0->setFont(font);
        progressBar0->setValue(24);

        horizontalLayout_7->addWidget(progressBar0);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(54, 0));
        label_2->setFont(font);

        horizontalLayout_6->addWidget(label_2);

        progressBar1 = new QProgressBar(widget);
        progressBar1->setObjectName(QStringLiteral("progressBar1"));
        progressBar1->setMaximumSize(QSize(300, 16777215));
        progressBar1->setFont(font);
        progressBar1->setValue(24);

        horizontalLayout_6->addWidget(progressBar1);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(54, 0));
        label_3->setFont(font);

        horizontalLayout_5->addWidget(label_3);

        progressBar2 = new QProgressBar(widget);
        progressBar2->setObjectName(QStringLiteral("progressBar2"));
        progressBar2->setMaximumSize(QSize(300, 16777215));
        progressBar2->setFont(font);
        progressBar2->setValue(24);

        horizontalLayout_5->addWidget(progressBar2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(54, 0));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        progressBar3 = new QProgressBar(widget);
        progressBar3->setObjectName(QStringLiteral("progressBar3"));
        progressBar3->setMaximumSize(QSize(300, 16777215));
        progressBar3->setFont(font);
        progressBar3->setValue(24);

        horizontalLayout_4->addWidget(progressBar3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(54, 0));
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);

        progressBar4 = new QProgressBar(widget);
        progressBar4->setObjectName(QStringLiteral("progressBar4"));
        progressBar4->setMaximumSize(QSize(300, 16777215));
        progressBar4->setFont(font);
        progressBar4->setValue(24);

        horizontalLayout_3->addWidget(progressBar4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(true);
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setMinimumSize(QSize(54, 0));
        label_6->setFont(font);

        horizontalLayout_2->addWidget(label_6);

        progressBar5 = new QProgressBar(widget);
        progressBar5->setObjectName(QStringLiteral("progressBar5"));
        progressBar5->setMaximumSize(QSize(300, 16777215));
        progressBar5->setFont(font);
        progressBar5->setValue(24);

        horizontalLayout_2->addWidget(progressBar5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(54, 0));
        label_7->setFont(font);

        horizontalLayout->addWidget(label_7);

        progressBar6 = new QProgressBar(widget);
        progressBar6->setObjectName(QStringLiteral("progressBar6"));
        progressBar6->setMaximumSize(QSize(300, 16777215));
        progressBar6->setFont(font);
        progressBar6->setValue(24);

        horizontalLayout->addWidget(progressBar6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(354, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        HotMap = new paintMap(widget);
        HotMap->setObjectName(QStringLiteral("HotMap"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(HotMap->sizePolicy().hasHeightForWidth());
        HotMap->setSizePolicy(sizePolicy4);
        HotMap->setMinimumSize(QSize(344, 200));

        verticalLayout->addWidget(HotMap);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_8->addWidget(widget);

        develop10Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(develop10Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1009, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        develop10Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(develop10Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        develop10Class->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(File_camera);
        menu->addAction(File_Video);
        menu->addAction(File_Image);

        retranslateUi(develop10Class);

        QMetaObject::connectSlotsByName(develop10Class);
    } // setupUi

    void retranslateUi(QMainWindow *develop10Class)
    {
        develop10Class->setWindowTitle(QApplication::translate("develop10Class", "develop10", nullptr));
        File_camera->setText(QApplication::translate("develop10Class", "\346\221\204\345\203\217\345\244\264", nullptr));
        File_Video->setText(QApplication::translate("develop10Class", "\350\247\206\351\242\221", nullptr));
        File_Image->setText(QApplication::translate("develop10Class", "\345\233\276\347\211\207", nullptr));
        label->setText(QApplication::translate("develop10Class", "Angry", nullptr));
        progressBar0->setFormat(QApplication::translate("develop10Class", "%v", nullptr));
        label_2->setText(QApplication::translate("develop10Class", "DISgust", nullptr));
        progressBar1->setFormat(QApplication::translate("develop10Class", "%v", nullptr));
        label_3->setText(QApplication::translate("develop10Class", "Fear", nullptr));
        progressBar2->setFormat(QApplication::translate("develop10Class", "%v", nullptr));
        label_4->setText(QApplication::translate("develop10Class", "Happy", nullptr));
        progressBar3->setFormat(QApplication::translate("develop10Class", "%v", nullptr));
        label_5->setText(QApplication::translate("develop10Class", "Sad", nullptr));
        progressBar4->setFormat(QApplication::translate("develop10Class", "%v", nullptr));
        label_6->setText(QApplication::translate("develop10Class", "Surprise", nullptr));
        progressBar5->setFormat(QApplication::translate("develop10Class", "%v", nullptr));
        label_7->setText(QApplication::translate("develop10Class", "Neutral", nullptr));
        progressBar6->setFormat(QApplication::translate("develop10Class", "%v", nullptr));
        menu->setTitle(QApplication::translate("develop10Class", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class develop10Class: public Ui_develop10Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVELOP10_H
