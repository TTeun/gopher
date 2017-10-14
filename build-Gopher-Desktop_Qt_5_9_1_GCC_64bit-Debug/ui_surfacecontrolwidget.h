/********************************************************************************
** Form generated from reading UI file 'surfacecontrolwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURFACECONTROLWIDGET_H
#define UI_SURFACECONTROLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SurfaceControlWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;

    void setupUi(QWidget *SurfaceControlWidget)
    {
        if (SurfaceControlWidget->objectName().isEmpty())
            SurfaceControlWidget->setObjectName(QStringLiteral("SurfaceControlWidget"));
        SurfaceControlWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(SurfaceControlWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(SurfaceControlWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(SurfaceControlWidget);

        QMetaObject::connectSlotsByName(SurfaceControlWidget);
    } // setupUi

    void retranslateUi(QWidget *SurfaceControlWidget)
    {
        SurfaceControlWidget->setWindowTitle(QApplication::translate("SurfaceControlWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SurfaceControlWidget: public Ui_SurfaceControlWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACECONTROLWIDGET_H
