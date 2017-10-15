/********************************************************************************
** Form generated from reading UI file 'surfacewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURFACEWIDGET_H
#define UI_SURFACEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SurfaceWidget
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *var1Min;
    QLabel *label_3;
    QSpinBox *uStepsSpinbox;
    QDoubleSpinBox *var1Max;
    QLabel *label_4;
    QSpinBox *vStepsSpinbox;
    QDoubleSpinBox *var2Min;
    QDoubleSpinBox *var2Max;
    QWidget *tab_2;
    QLabel *label;
    QPushButton *colorButton;
    QLineEdit *equationLine;

    void setupUi(QWidget *SurfaceWidget)
    {
        if (SurfaceWidget->objectName().isEmpty())
            SurfaceWidget->setObjectName(QStringLiteral("SurfaceWidget"));
        SurfaceWidget->resize(312, 161);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SurfaceWidget->sizePolicy().hasHeightForWidth());
        SurfaceWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(SurfaceWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(SurfaceWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        var1Min = new QDoubleSpinBox(tab);
        var1Min->setObjectName(QStringLiteral("var1Min"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(var1Min->sizePolicy().hasHeightForWidth());
        var1Min->setSizePolicy(sizePolicy2);
        var1Min->setMinimum(-1000);
        var1Min->setMaximum(1000);
        var1Min->setValue(-3);

        gridLayout_2->addWidget(var1Min, 0, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        uStepsSpinbox = new QSpinBox(tab);
        uStepsSpinbox->setObjectName(QStringLiteral("uStepsSpinbox"));
        sizePolicy2.setHeightForWidth(uStepsSpinbox->sizePolicy().hasHeightForWidth());
        uStepsSpinbox->setSizePolicy(sizePolicy2);
        uStepsSpinbox->setMinimum(2);
        uStepsSpinbox->setMaximum(1000);
        uStepsSpinbox->setValue(100);

        gridLayout_2->addWidget(uStepsSpinbox, 0, 3, 1, 1);

        var1Max = new QDoubleSpinBox(tab);
        var1Max->setObjectName(QStringLiteral("var1Max"));
        sizePolicy2.setHeightForWidth(var1Max->sizePolicy().hasHeightForWidth());
        var1Max->setSizePolicy(sizePolicy2);
        var1Max->setMinimum(-1000);
        var1Max->setMaximum(1000);
        var1Max->setValue(3);

        gridLayout_2->addWidget(var1Max, 0, 2, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        vStepsSpinbox = new QSpinBox(tab);
        vStepsSpinbox->setObjectName(QStringLiteral("vStepsSpinbox"));
        sizePolicy2.setHeightForWidth(vStepsSpinbox->sizePolicy().hasHeightForWidth());
        vStepsSpinbox->setSizePolicy(sizePolicy2);
        vStepsSpinbox->setMinimum(2);
        vStepsSpinbox->setMaximum(1000);
        vStepsSpinbox->setValue(100);

        gridLayout_2->addWidget(vStepsSpinbox, 1, 3, 1, 1);

        var2Min = new QDoubleSpinBox(tab);
        var2Min->setObjectName(QStringLiteral("var2Min"));
        var2Min->setMinimum(-1000);
        var2Min->setMaximum(1000);
        var2Min->setValue(-3);

        gridLayout_2->addWidget(var2Min, 1, 1, 1, 1);

        var2Max = new QDoubleSpinBox(tab);
        var2Max->setObjectName(QStringLiteral("var2Max"));
        var2Max->setMinimum(-1000);
        var2Max->setMaximum(1000);
        var2Max->setValue(3);

        gridLayout_2->addWidget(var2Max, 1, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 4, 0, 1, 4);

        label = new QLabel(SurfaceWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        colorButton = new QPushButton(SurfaceWidget);
        colorButton->setObjectName(QStringLiteral("colorButton"));
        sizePolicy2.setHeightForWidth(colorButton->sizePolicy().hasHeightForWidth());
        colorButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(colorButton, 0, 3, 1, 1);

        equationLine = new QLineEdit(SurfaceWidget);
        equationLine->setObjectName(QStringLiteral("equationLine"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(equationLine->sizePolicy().hasHeightForWidth());
        equationLine->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(equationLine, 0, 1, 1, 2);


        retranslateUi(SurfaceWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SurfaceWidget);
    } // setupUi

    void retranslateUi(QWidget *SurfaceWidget)
    {
        SurfaceWidget->setWindowTitle(QApplication::translate("SurfaceWidget", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("SurfaceWidget", "u", Q_NULLPTR));
        label_4->setText(QApplication::translate("SurfaceWidget", "v", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SurfaceWidget", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SurfaceWidget", "Tab 2", Q_NULLPTR));
        label->setText(QApplication::translate("SurfaceWidget", "f(u,v) =", Q_NULLPTR));
        colorButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SurfaceWidget: public Ui_SurfaceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACEWIDGET_H
