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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SurfaceWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *equationLine;
    QDoubleSpinBox *var2Min;
    QDoubleSpinBox *var1Min;
    QDoubleSpinBox *var2Max;
    QDoubleSpinBox *var1Max;
    QPushButton *colorButton;
    QSpinBox *uStepsSpinbox;
    QSpinBox *vStepsSpinbox;

    void setupUi(QWidget *SurfaceWidget)
    {
        if (SurfaceWidget->objectName().isEmpty())
            SurfaceWidget->setObjectName(QStringLiteral("SurfaceWidget"));
        SurfaceWidget->resize(306, 107);
        gridLayout = new QGridLayout(SurfaceWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(SurfaceWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(SurfaceWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label = new QLabel(SurfaceWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 0, 1, 2);

        equationLine = new QLineEdit(SurfaceWidget);
        equationLine->setObjectName(QStringLiteral("equationLine"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(equationLine->sizePolicy().hasHeightForWidth());
        equationLine->setSizePolicy(sizePolicy);

        gridLayout->addWidget(equationLine, 4, 3, 1, 2);

        var2Min = new QDoubleSpinBox(SurfaceWidget);
        var2Min->setObjectName(QStringLiteral("var2Min"));
        var2Min->setMinimum(-1000);
        var2Min->setMaximum(1000);
        var2Min->setValue(-3);

        gridLayout->addWidget(var2Min, 1, 1, 1, 3);

        var1Min = new QDoubleSpinBox(SurfaceWidget);
        var1Min->setObjectName(QStringLiteral("var1Min"));
        var1Min->setMinimum(-1000);
        var1Min->setMaximum(1000);
        var1Min->setValue(-3);

        gridLayout->addWidget(var1Min, 0, 1, 1, 3);

        var2Max = new QDoubleSpinBox(SurfaceWidget);
        var2Max->setObjectName(QStringLiteral("var2Max"));
        var2Max->setMinimum(-1000);
        var2Max->setMaximum(1000);
        var2Max->setValue(3);

        gridLayout->addWidget(var2Max, 1, 4, 1, 1);

        var1Max = new QDoubleSpinBox(SurfaceWidget);
        var1Max->setObjectName(QStringLiteral("var1Max"));
        var1Max->setMinimum(-1000);
        var1Max->setMaximum(1000);
        var1Max->setValue(3);

        gridLayout->addWidget(var1Max, 0, 4, 1, 1);

        colorButton = new QPushButton(SurfaceWidget);
        colorButton->setObjectName(QStringLiteral("colorButton"));

        gridLayout->addWidget(colorButton, 4, 5, 1, 1);

        uStepsSpinbox = new QSpinBox(SurfaceWidget);
        uStepsSpinbox->setObjectName(QStringLiteral("uStepsSpinbox"));
        uStepsSpinbox->setMinimum(2);
        uStepsSpinbox->setMaximum(1000);
        uStepsSpinbox->setValue(100);

        gridLayout->addWidget(uStepsSpinbox, 0, 5, 1, 1);

        vStepsSpinbox = new QSpinBox(SurfaceWidget);
        vStepsSpinbox->setObjectName(QStringLiteral("vStepsSpinbox"));
        vStepsSpinbox->setMinimum(2);
        vStepsSpinbox->setMaximum(1000);
        vStepsSpinbox->setValue(100);

        gridLayout->addWidget(vStepsSpinbox, 1, 5, 1, 1);


        retranslateUi(SurfaceWidget);

        QMetaObject::connectSlotsByName(SurfaceWidget);
    } // setupUi

    void retranslateUi(QWidget *SurfaceWidget)
    {
        SurfaceWidget->setWindowTitle(QApplication::translate("SurfaceWidget", "Form", Q_NULLPTR));
        label_4->setText(QApplication::translate("SurfaceWidget", "v", Q_NULLPTR));
        label_3->setText(QApplication::translate("SurfaceWidget", "u", Q_NULLPTR));
        label->setText(QApplication::translate("SurfaceWidget", "f(u,v) =", Q_NULLPTR));
        colorButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SurfaceWidget: public Ui_SurfaceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACEWIDGET_H
