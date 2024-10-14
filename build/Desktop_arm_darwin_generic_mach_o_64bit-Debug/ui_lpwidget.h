/********************************************************************************
** Form generated from reading UI file 'lpwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LPWIDGET_H
#define UI_LPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LpWidget
{
public:
    QLabel *funcLabel;
    QLineEdit *funcEditX1;
    QLabel *c1Label;
    QLineEdit *funcEditX2;
    QComboBox *funcPurposeBox;
    QLabel *x1;
    QLabel *x2;
    QLineEdit *constraint1EditX1;
    QLineEdit *constraint1EditValue;
    QLabel *x2_2;
    QLineEdit *constraint1EditX2;
    QComboBox *constraint1SignBox;
    QLabel *x1_2;
    QLineEdit *constraint2EditX2;
    QLineEdit *constraint2EditX1;
    QLineEdit *constraint2EditValue;
    QComboBox *constraint2SignBox;
    QLabel *c1Label_2;
    QLabel *x1_3;
    QLabel *x2_3;
    QLineEdit *constraint3EditX2;
    QLineEdit *constraint3EditX1;
    QLineEdit *constraint3EditValue;
    QComboBox *constraint3SignBox;
    QLabel *c1Label_3;
    QLabel *x1_4;
    QLabel *x2_4;
    QPushButton *solveButton;
    QSlider *targetSlider;
    QSlider *scaleSlider;
    QLabel *ansLabel;
    QLabel *funcLabel_2;
    QLabel *funcLabel_3;
    QLabel *funcLabel_4;
    QLabel *minTargetLabel;
    QLabel *minScaleLabel;
    QLabel *maxTargetLabel;
    QLabel *maxScaleLabel;
    QLabel *curTargetLabel;
    QLabel *curScaleLabel;

    void setupUi(QWidget *LpWidget)
    {
        if (LpWidget->objectName().isEmpty())
            LpWidget->setObjectName("LpWidget");
        LpWidget->resize(1034, 600);
        funcLabel = new QLabel(LpWidget);
        funcLabel->setObjectName("funcLabel");
        funcLabel->setGeometry(QRect(690, 20, 231, 16));
        funcEditX1 = new QLineEdit(LpWidget);
        funcEditX1->setObjectName("funcEditX1");
        funcEditX1->setGeometry(QRect(690, 50, 41, 21));
        c1Label = new QLabel(LpWidget);
        c1Label->setObjectName("c1Label");
        c1Label->setGeometry(QRect(690, 90, 101, 16));
        funcEditX2 = new QLineEdit(LpWidget);
        funcEditX2->setObjectName("funcEditX2");
        funcEditX2->setGeometry(QRect(770, 50, 41, 21));
        funcPurposeBox = new QComboBox(LpWidget);
        funcPurposeBox->addItem(QString());
        funcPurposeBox->addItem(QString());
        funcPurposeBox->setObjectName("funcPurposeBox");
        funcPurposeBox->setGeometry(QRect(840, 45, 71, 32));
        funcPurposeBox->setAcceptDrops(true);
        funcPurposeBox->setEditable(false);
        funcPurposeBox->setMaxVisibleItems(3);
        x1 = new QLabel(LpWidget);
        x1->setObjectName("x1");
        x1->setGeometry(QRect(740, 50, 31, 16));
        x2 = new QLabel(LpWidget);
        x2->setObjectName("x2");
        x2->setGeometry(QRect(820, 50, 31, 16));
        constraint1EditX1 = new QLineEdit(LpWidget);
        constraint1EditX1->setObjectName("constraint1EditX1");
        constraint1EditX1->setGeometry(QRect(690, 120, 41, 21));
        constraint1EditValue = new QLineEdit(LpWidget);
        constraint1EditValue->setObjectName("constraint1EditValue");
        constraint1EditValue->setGeometry(QRect(920, 120, 41, 21));
        x2_2 = new QLabel(LpWidget);
        x2_2->setObjectName("x2_2");
        x2_2->setGeometry(QRect(820, 120, 21, 16));
        constraint1EditX2 = new QLineEdit(LpWidget);
        constraint1EditX2->setObjectName("constraint1EditX2");
        constraint1EditX2->setGeometry(QRect(770, 120, 41, 21));
        constraint1SignBox = new QComboBox(LpWidget);
        constraint1SignBox->addItem(QString());
        constraint1SignBox->addItem(QString());
        constraint1SignBox->addItem(QString());
        constraint1SignBox->setObjectName("constraint1SignBox");
        constraint1SignBox->setGeometry(QRect(850, 115, 61, 32));
        constraint1SignBox->setAcceptDrops(true);
        constraint1SignBox->setEditable(false);
        x1_2 = new QLabel(LpWidget);
        x1_2->setObjectName("x1_2");
        x1_2->setGeometry(QRect(740, 120, 31, 16));
        constraint2EditX2 = new QLineEdit(LpWidget);
        constraint2EditX2->setObjectName("constraint2EditX2");
        constraint2EditX2->setGeometry(QRect(770, 190, 41, 21));
        constraint2EditX1 = new QLineEdit(LpWidget);
        constraint2EditX1->setObjectName("constraint2EditX1");
        constraint2EditX1->setGeometry(QRect(690, 190, 41, 21));
        constraint2EditValue = new QLineEdit(LpWidget);
        constraint2EditValue->setObjectName("constraint2EditValue");
        constraint2EditValue->setGeometry(QRect(920, 190, 41, 21));
        constraint2SignBox = new QComboBox(LpWidget);
        constraint2SignBox->addItem(QString());
        constraint2SignBox->addItem(QString());
        constraint2SignBox->addItem(QString());
        constraint2SignBox->setObjectName("constraint2SignBox");
        constraint2SignBox->setGeometry(QRect(850, 185, 61, 32));
        constraint2SignBox->setAcceptDrops(true);
        c1Label_2 = new QLabel(LpWidget);
        c1Label_2->setObjectName("c1Label_2");
        c1Label_2->setGeometry(QRect(690, 160, 101, 16));
        x1_3 = new QLabel(LpWidget);
        x1_3->setObjectName("x1_3");
        x1_3->setGeometry(QRect(740, 190, 31, 16));
        x2_3 = new QLabel(LpWidget);
        x2_3->setObjectName("x2_3");
        x2_3->setGeometry(QRect(820, 190, 21, 16));
        constraint3EditX2 = new QLineEdit(LpWidget);
        constraint3EditX2->setObjectName("constraint3EditX2");
        constraint3EditX2->setGeometry(QRect(770, 260, 41, 21));
        constraint3EditX1 = new QLineEdit(LpWidget);
        constraint3EditX1->setObjectName("constraint3EditX1");
        constraint3EditX1->setGeometry(QRect(690, 260, 41, 21));
        constraint3EditValue = new QLineEdit(LpWidget);
        constraint3EditValue->setObjectName("constraint3EditValue");
        constraint3EditValue->setGeometry(QRect(920, 260, 41, 21));
        constraint3SignBox = new QComboBox(LpWidget);
        constraint3SignBox->addItem(QString());
        constraint3SignBox->addItem(QString());
        constraint3SignBox->addItem(QString());
        constraint3SignBox->setObjectName("constraint3SignBox");
        constraint3SignBox->setGeometry(QRect(850, 255, 61, 32));
        constraint3SignBox->setAcceptDrops(true);
        constraint3SignBox->setAutoFillBackground(false);
        c1Label_3 = new QLabel(LpWidget);
        c1Label_3->setObjectName("c1Label_3");
        c1Label_3->setGeometry(QRect(690, 230, 101, 16));
        x1_4 = new QLabel(LpWidget);
        x1_4->setObjectName("x1_4");
        x1_4->setGeometry(QRect(740, 260, 31, 16));
        x2_4 = new QLabel(LpWidget);
        x2_4->setObjectName("x2_4");
        x2_4->setGeometry(QRect(820, 260, 21, 16));
        solveButton = new QPushButton(LpWidget);
        solveButton->setObjectName("solveButton");
        solveButton->setGeometry(QRect(690, 310, 271, 32));
        targetSlider = new QSlider(LpWidget);
        targetSlider->setObjectName("targetSlider");
        targetSlider->setGeometry(QRect(710, 410, 231, 25));
        targetSlider->setAutoFillBackground(false);
        targetSlider->setMaximum(10);
        targetSlider->setValue(2);
        targetSlider->setOrientation(Qt::Orientation::Horizontal);
        scaleSlider = new QSlider(LpWidget);
        scaleSlider->setObjectName("scaleSlider");
        scaleSlider->setGeometry(QRect(710, 488, 231, 25));
        scaleSlider->setMinimum(1);
        scaleSlider->setMaximum(3);
        scaleSlider->setValue(1);
        scaleSlider->setOrientation(Qt::Orientation::Horizontal);
        scaleSlider->setInvertedAppearance(false);
        scaleSlider->setInvertedControls(false);
        ansLabel = new QLabel(LpWidget);
        ansLabel->setObjectName("ansLabel");
        ansLabel->setGeometry(QRect(690, 560, 251, 16));
        funcLabel_2 = new QLabel(LpWidget);
        funcLabel_2->setObjectName("funcLabel_2");
        funcLabel_2->setGeometry(QRect(690, 380, 231, 16));
        QFont font;
        font.setPointSize(18);
        funcLabel_2->setFont(font);
        funcLabel_3 = new QLabel(LpWidget);
        funcLabel_3->setObjectName("funcLabel_3");
        funcLabel_3->setGeometry(QRect(690, 458, 231, 16));
        funcLabel_3->setFont(font);
        funcLabel_4 = new QLabel(LpWidget);
        funcLabel_4->setObjectName("funcLabel_4");
        funcLabel_4->setGeometry(QRect(690, 530, 231, 16));
        funcLabel_4->setFont(font);
        minTargetLabel = new QLabel(LpWidget);
        minTargetLabel->setObjectName("minTargetLabel");
        minTargetLabel->setGeometry(QRect(690, 412, 20, 16));
        QFont font1;
        font1.setPointSize(12);
        minTargetLabel->setFont(font1);
        minScaleLabel = new QLabel(LpWidget);
        minScaleLabel->setObjectName("minScaleLabel");
        minScaleLabel->setGeometry(QRect(690, 490, 20, 16));
        minScaleLabel->setFont(font1);
        maxTargetLabel = new QLabel(LpWidget);
        maxTargetLabel->setObjectName("maxTargetLabel");
        maxTargetLabel->setGeometry(QRect(943, 412, 20, 16));
        maxTargetLabel->setFont(font1);
        maxScaleLabel = new QLabel(LpWidget);
        maxScaleLabel->setObjectName("maxScaleLabel");
        maxScaleLabel->setGeometry(QRect(943, 490, 20, 16));
        maxScaleLabel->setFont(font1);
        curTargetLabel = new QLabel(LpWidget);
        curTargetLabel->setObjectName("curTargetLabel");
        curTargetLabel->setGeometry(QRect(820, 435, 20, 16));
        curTargetLabel->setFont(font1);
        curScaleLabel = new QLabel(LpWidget);
        curScaleLabel->setObjectName("curScaleLabel");
        curScaleLabel->setGeometry(QRect(820, 510, 20, 16));
        curScaleLabel->setFont(font1);
        QWidget::setTabOrder(funcEditX1, funcEditX2);
        QWidget::setTabOrder(funcEditX2, funcPurposeBox);
        QWidget::setTabOrder(funcPurposeBox, constraint1EditX1);
        QWidget::setTabOrder(constraint1EditX1, constraint1EditX2);
        QWidget::setTabOrder(constraint1EditX2, constraint1SignBox);
        QWidget::setTabOrder(constraint1SignBox, constraint1EditValue);
        QWidget::setTabOrder(constraint1EditValue, constraint2EditX1);
        QWidget::setTabOrder(constraint2EditX1, constraint2EditX2);
        QWidget::setTabOrder(constraint2EditX2, constraint2SignBox);
        QWidget::setTabOrder(constraint2SignBox, constraint2EditValue);
        QWidget::setTabOrder(constraint2EditValue, constraint3EditX1);
        QWidget::setTabOrder(constraint3EditX1, constraint3EditX2);
        QWidget::setTabOrder(constraint3EditX2, constraint3EditValue);
        QWidget::setTabOrder(constraint3EditValue, solveButton);
        QWidget::setTabOrder(solveButton, constraint3SignBox);

        retranslateUi(LpWidget);

        QMetaObject::connectSlotsByName(LpWidget);
    } // setupUi

    void retranslateUi(QWidget *LpWidget)
    {
        LpWidget->setWindowTitle(QCoreApplication::translate("LpWidget", "\320\223\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\274\320\265\321\202\320\276\320\264 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 \320\267\320\260\320\264\320\260\321\207\320\270 \320\273\320\270\320\275\320\265\320\271\320\275\320\276\320\263\320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        funcLabel->setText(QCoreApplication::translate("LpWidget", "\320\246\320\265\320\273\320\265\320\262\320\260\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 (F = ax1 + bx2):", nullptr));
        funcEditX1->setText(QCoreApplication::translate("LpWidget", "2", nullptr));
        funcEditX1->setPlaceholderText(QCoreApplication::translate("LpWidget", "a", nullptr));
        c1Label->setText(QCoreApplication::translate("LpWidget", "\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265 1", nullptr));
        funcEditX2->setText(QCoreApplication::translate("LpWidget", "6", nullptr));
        funcEditX2->setPlaceholderText(QCoreApplication::translate("LpWidget", "b", nullptr));
        funcPurposeBox->setItemText(0, QCoreApplication::translate("LpWidget", "max", nullptr));
        funcPurposeBox->setItemText(1, QCoreApplication::translate("LpWidget", "min", nullptr));

        x1->setText(QCoreApplication::translate("LpWidget", "x1 +", nullptr));
        x2->setText(QCoreApplication::translate("LpWidget", "x2", nullptr));
        constraint1EditX1->setText(QCoreApplication::translate("LpWidget", "1", nullptr));
        constraint1EditX1->setPlaceholderText(QCoreApplication::translate("LpWidget", "a", nullptr));
        constraint1EditValue->setText(QCoreApplication::translate("LpWidget", "10", nullptr));
        constraint1EditValue->setPlaceholderText(QCoreApplication::translate("LpWidget", "c", nullptr));
        x2_2->setText(QCoreApplication::translate("LpWidget", "x2", nullptr));
        constraint1EditX2->setText(QCoreApplication::translate("LpWidget", "2", nullptr));
        constraint1EditX2->setPlaceholderText(QCoreApplication::translate("LpWidget", "b", nullptr));
        constraint1SignBox->setItemText(0, QCoreApplication::translate("LpWidget", "<=", nullptr));
        constraint1SignBox->setItemText(1, QCoreApplication::translate("LpWidget", ">=", nullptr));
        constraint1SignBox->setItemText(2, QCoreApplication::translate("LpWidget", "=", nullptr));

        x1_2->setText(QCoreApplication::translate("LpWidget", "x1 +", nullptr));
        constraint2EditX2->setText(QCoreApplication::translate("LpWidget", "1", nullptr));
        constraint2EditX2->setPlaceholderText(QCoreApplication::translate("LpWidget", "b", nullptr));
        constraint2EditX1->setText(QCoreApplication::translate("LpWidget", "3", nullptr));
        constraint2EditX1->setPlaceholderText(QCoreApplication::translate("LpWidget", "a", nullptr));
        constraint2EditValue->setText(QCoreApplication::translate("LpWidget", "6", nullptr));
        constraint2EditValue->setPlaceholderText(QCoreApplication::translate("LpWidget", "c", nullptr));
        constraint2SignBox->setItemText(0, QCoreApplication::translate("LpWidget", "<=", nullptr));
        constraint2SignBox->setItemText(1, QCoreApplication::translate("LpWidget", ">=", nullptr));
        constraint2SignBox->setItemText(2, QCoreApplication::translate("LpWidget", "=", nullptr));

        c1Label_2->setText(QCoreApplication::translate("LpWidget", "\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265 2", nullptr));
        x1_3->setText(QCoreApplication::translate("LpWidget", "x1 +", nullptr));
        x2_3->setText(QCoreApplication::translate("LpWidget", "x2", nullptr));
        constraint3EditX2->setText(QCoreApplication::translate("LpWidget", "3", nullptr));
        constraint3EditX2->setPlaceholderText(QCoreApplication::translate("LpWidget", "b", nullptr));
        constraint3EditX1->setText(QCoreApplication::translate("LpWidget", "1", nullptr));
        constraint3EditX1->setPlaceholderText(QCoreApplication::translate("LpWidget", "a", nullptr));
        constraint3EditValue->setText(QCoreApplication::translate("LpWidget", "7", nullptr));
        constraint3EditValue->setPlaceholderText(QCoreApplication::translate("LpWidget", "c", nullptr));
        constraint3SignBox->setItemText(0, QCoreApplication::translate("LpWidget", ">=", nullptr));
        constraint3SignBox->setItemText(1, QCoreApplication::translate("LpWidget", "<=", nullptr));
        constraint3SignBox->setItemText(2, QCoreApplication::translate("LpWidget", "=", nullptr));

        c1Label_3->setText(QCoreApplication::translate("LpWidget", "\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265 3", nullptr));
        x1_4->setText(QCoreApplication::translate("LpWidget", "x1 +", nullptr));
        x2_4->setText(QCoreApplication::translate("LpWidget", "x2", nullptr));
        solveButton->setText(QCoreApplication::translate("LpWidget", "\320\240\320\265\321\210\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203 \320\270 \320\277\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        ansLabel->setText(QCoreApplication::translate("LpWidget", "\320\267\320\264\320\265\321\201\321\214 \320\261\321\203\320\264\320\265\321\202 \320\276\321\202\320\262\320\265\321\202", nullptr));
        funcLabel_2->setText(QCoreApplication::translate("LpWidget", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\206\320\265\320\273\320\265\320\262\320\276\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
        funcLabel_3->setText(QCoreApplication::translate("LpWidget", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        funcLabel_4->setText(QCoreApplication::translate("LpWidget", "\320\236\321\202\320\262\320\265\321\202", nullptr));
        minTargetLabel->setText(QCoreApplication::translate("LpWidget", "0", nullptr));
        minScaleLabel->setText(QCoreApplication::translate("LpWidget", "1", nullptr));
        maxTargetLabel->setText(QCoreApplication::translate("LpWidget", "10", nullptr));
        maxScaleLabel->setText(QCoreApplication::translate("LpWidget", "3", nullptr));
        curTargetLabel->setText(QCoreApplication::translate("LpWidget", "2", nullptr));
        curScaleLabel->setText(QCoreApplication::translate("LpWidget", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LpWidget: public Ui_LpWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LPWIDGET_H
