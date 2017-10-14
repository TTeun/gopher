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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SurfaceWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;

    void setupUi(QWidget *SurfaceWidget)
    {
        if (SurfaceWidget->objectName().isEmpty())
            SurfaceWidget->setObjectName(QStringLiteral("SurfaceWidget"));
        SurfaceWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(SurfaceWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(SurfaceWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(SurfaceWidget);

        QMetaObject::connectSlotsByName(SurfaceWidget);
    } // setupUi

    void retranslateUi(QWidget *SurfaceWidget)
    {
        SurfaceWidget->setWindowTitle(QApplication::translate("SurfaceWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SurfaceWidget: public Ui_SurfaceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACEWIDGET_H
