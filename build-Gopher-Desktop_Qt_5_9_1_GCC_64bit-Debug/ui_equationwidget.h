/********************************************************************************
** Form generated from reading UI file 'equationwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUATIONWIDGET_H
#define UI_EQUATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EquationWidget
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *m_uMax;
    QDoubleSpinBox *m_vMin;
    QDoubleSpinBox *m_uMin;
    QLabel *label;
    QDoubleSpinBox *m_vMax;
    QSpinBox *m_uSteps;
    QSpinBox *m_vSteps;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox;
    QLineEdit *m_equationLine;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *m_showSurface;
    QCheckBox *m_showGrid;

    void setupUi(QWidget *EquationWidget)
    {
        if (EquationWidget->objectName().isEmpty())
            EquationWidget->setObjectName(QStringLiteral("EquationWidget"));
        EquationWidget->resize(424, 458);
        gridLayout = new QGridLayout(EquationWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(EquationWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        m_uMax = new QDoubleSpinBox(groupBox);
        m_uMax->setObjectName(QStringLiteral("m_uMax"));
        m_uMax->setMinimum(-10000);
        m_uMax->setSingleStep(0.1);
        m_uMax->setValue(1);

        gridLayout_2->addWidget(m_uMax, 0, 2, 1, 1);

        m_vMin = new QDoubleSpinBox(groupBox);
        m_vMin->setObjectName(QStringLiteral("m_vMin"));
        m_vMin->setMinimum(-10000);
        m_vMin->setSingleStep(0.1);
        m_vMin->setValue(-1);

        gridLayout_2->addWidget(m_vMin, 2, 1, 1, 1);

        m_uMin = new QDoubleSpinBox(groupBox);
        m_uMin->setObjectName(QStringLiteral("m_uMin"));
        m_uMin->setMinimum(-10000);
        m_uMin->setSingleStep(0.1);
        m_uMin->setValue(-1);

        gridLayout_2->addWidget(m_uMin, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        m_vMax = new QDoubleSpinBox(groupBox);
        m_vMax->setObjectName(QStringLiteral("m_vMax"));
        m_vMax->setMinimum(-10000);
        m_vMax->setSingleStep(0.1);
        m_vMax->setValue(1);

        gridLayout_2->addWidget(m_vMax, 2, 2, 1, 1);

        m_uSteps = new QSpinBox(groupBox);
        m_uSteps->setObjectName(QStringLiteral("m_uSteps"));
        m_uSteps->setMinimum(1);
        m_uSteps->setMaximum(1000);
        m_uSteps->setValue(50);

        gridLayout_2->addWidget(m_uSteps, 0, 3, 1, 1);

        m_vSteps = new QSpinBox(groupBox);
        m_vSteps->setObjectName(QStringLiteral("m_vSteps"));
        m_vSteps->setMinimum(1);
        m_vSteps->setMaximum(1000);
        m_vSteps->setValue(50);

        gridLayout_2->addWidget(m_vSteps, 2, 3, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(EquationWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(true);

        horizontalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setChecked(true);

        horizontalLayout->addWidget(checkBox_3);

        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        m_equationLine = new QLineEdit(EquationWidget);
        m_equationLine->setObjectName(QStringLiteral("m_equationLine"));

        gridLayout->addWidget(m_equationLine, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(EquationWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));

        gridLayout->addWidget(groupBox_2, 4, 0, 1, 1);

        groupBox_4 = new QGroupBox(EquationWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_showSurface = new QCheckBox(groupBox_4);
        m_showSurface->setObjectName(QStringLiteral("m_showSurface"));
        m_showSurface->setChecked(true);

        horizontalLayout_2->addWidget(m_showSurface);

        m_showGrid = new QCheckBox(groupBox_4);
        m_showGrid->setObjectName(QStringLiteral("m_showGrid"));
        m_showGrid->setChecked(true);

        horizontalLayout_2->addWidget(m_showGrid);


        gridLayout->addWidget(groupBox_4, 3, 0, 1, 1);


        retranslateUi(EquationWidget);
        QObject::connect(checkBox_2, SIGNAL(toggled(bool)), groupBox, SLOT(setVisible(bool)));
        QObject::connect(checkBox, SIGNAL(toggled(bool)), groupBox_2, SLOT(setVisible(bool)));
        QObject::connect(checkBox_3, SIGNAL(toggled(bool)), groupBox_4, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(EquationWidget);
    } // setupUi

    void retranslateUi(QWidget *EquationWidget)
    {
        EquationWidget->setWindowTitle(QApplication::translate("EquationWidget", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("EquationWidget", "Domain", Q_NULLPTR));
        label_2->setText(QApplication::translate("EquationWidget", "u", Q_NULLPTR));
        label->setText(QApplication::translate("EquationWidget", "v", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("EquationWidget", "Controls", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("EquationWidget", "Domain", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("EquationWidget", "View", Q_NULLPTR));
        checkBox->setText(QApplication::translate("EquationWidget", "Parameters", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("EquationWidget", "Parameter", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("EquationWidget", "View", Q_NULLPTR));
        m_showSurface->setText(QApplication::translate("EquationWidget", "Surface", Q_NULLPTR));
        m_showGrid->setText(QApplication::translate("EquationWidget", "Grid", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EquationWidget: public Ui_EquationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUATIONWIDGET_H
