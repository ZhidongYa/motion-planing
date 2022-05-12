/********************************************************************************
** Form generated from reading UI file 'PathPlanning.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHPLANNING_H
#define UI_PATHPLANNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PathPlanning
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frameViewer;
    QGroupBox *groupBox;
    QPushButton *pushButtonReset;
    QGroupBox *groupBox_2;
    QCheckBox *checkBoxColModel;
    QCheckBox *checkBoxRobot;
    QCheckBox *checkBoxObstacles;
    QCheckBox *checkBoxFloor;
    QCheckBox *checkBoxOption1;
    QGroupBox *groupBox_3;
    QLabel *label_2;
    QLCDNumber *lcdNumberTrajectory;
    QSlider *horizontalSliderTrajectory;
    QLabel *labelMinPos;
    QLabel *labelMaxPos;
    QPushButton *visualizeGridButton;
    QPushButton *pushButtonStep2;
    QPushButton *pushButtonStep3;
    QPushButton *pushButtonRunPlanner;
    QGroupBox *groupBox_5;
    QLabel *labelInfo1;
    QLabel *labelInfo2;
    QLabel *labelInfo3;
    QLabel *label_3;
    QComboBox *comboBoxScene;
    QLabel *label_4;
    QComboBox *comboBoxAlgo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PathPlanning)
    {
        if (PathPlanning->objectName().isEmpty())
            PathPlanning->setObjectName(QStringLiteral("PathPlanning"));
        PathPlanning->resize(1103, 840);
        centralwidget = new QWidget(PathPlanning);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frameViewer = new QFrame(centralwidget);
        frameViewer->setObjectName(QStringLiteral("frameViewer"));
        frameViewer->setFrameShape(QFrame::StyledPanel);
        frameViewer->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frameViewer, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(200, 16777215));
        pushButtonReset = new QPushButton(groupBox);
        pushButtonReset->setObjectName(QStringLiteral("pushButtonReset"));
        pushButtonReset->setGeometry(QRect(20, 10, 171, 28));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 480, 201, 201));
        checkBoxColModel = new QCheckBox(groupBox_2);
        checkBoxColModel->setObjectName(QStringLiteral("checkBoxColModel"));
        checkBoxColModel->setGeometry(QRect(10, 30, 131, 20));
        checkBoxRobot = new QCheckBox(groupBox_2);
        checkBoxRobot->setObjectName(QStringLiteral("checkBoxRobot"));
        checkBoxRobot->setGeometry(QRect(10, 60, 131, 20));
        checkBoxRobot->setChecked(true);
        checkBoxObstacles = new QCheckBox(groupBox_2);
        checkBoxObstacles->setObjectName(QStringLiteral("checkBoxObstacles"));
        checkBoxObstacles->setGeometry(QRect(10, 90, 131, 20));
        checkBoxObstacles->setChecked(true);
        checkBoxFloor = new QCheckBox(groupBox_2);
        checkBoxFloor->setObjectName(QStringLiteral("checkBoxFloor"));
        checkBoxFloor->setGeometry(QRect(10, 120, 131, 20));
        checkBoxFloor->setChecked(true);
        checkBoxOption1 = new QCheckBox(groupBox_2);
        checkBoxOption1->setObjectName(QStringLiteral("checkBoxOption1"));
        checkBoxOption1->setGeometry(QRect(10, 150, 131, 20));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 170, 201, 301));
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 71, 16));
        lcdNumberTrajectory = new QLCDNumber(groupBox_3);
        lcdNumberTrajectory->setObjectName(QStringLiteral("lcdNumberTrajectory"));
        lcdNumberTrajectory->setGeometry(QRect(110, 30, 81, 31));
        lcdNumberTrajectory->setSmallDecimalPoint(true);
        lcdNumberTrajectory->setDigitCount(5);
        lcdNumberTrajectory->setProperty("value", QVariant(0));
        horizontalSliderTrajectory = new QSlider(groupBox_3);
        horizontalSliderTrajectory->setObjectName(QStringLiteral("horizontalSliderTrajectory"));
        horizontalSliderTrajectory->setGeometry(QRect(10, 70, 181, 20));
        horizontalSliderTrajectory->setMaximum(1000);
        horizontalSliderTrajectory->setPageStep(50);
        horizontalSliderTrajectory->setOrientation(Qt::Horizontal);
        labelMinPos = new QLabel(groupBox_3);
        labelMinPos->setObjectName(QStringLiteral("labelMinPos"));
        labelMinPos->setGeometry(QRect(10, 90, 91, 21));
        labelMaxPos = new QLabel(groupBox_3);
        labelMaxPos->setObjectName(QStringLiteral("labelMaxPos"));
        labelMaxPos->setGeometry(QRect(160, 90, 41, 20));
        labelMaxPos->setLayoutDirection(Qt::RightToLeft);
        visualizeGridButton = new QPushButton(groupBox_3);
        visualizeGridButton->setObjectName(QStringLiteral("visualizeGridButton"));
        visualizeGridButton->setGeometry(QRect(10, 170, 171, 28));
        pushButtonStep2 = new QPushButton(groupBox_3);
        pushButtonStep2->setObjectName(QStringLiteral("pushButtonStep2"));
        pushButtonStep2->setGeometry(QRect(10, 210, 171, 28));
        pushButtonStep3 = new QPushButton(groupBox_3);
        pushButtonStep3->setObjectName(QStringLiteral("pushButtonStep3"));
        pushButtonStep3->setGeometry(QRect(10, 250, 171, 28));
        pushButtonRunPlanner = new QPushButton(groupBox_3);
        pushButtonRunPlanner->setObjectName(QStringLiteral("pushButtonRunPlanner"));
        pushButtonRunPlanner->setGeometry(QRect(10, 130, 171, 27));
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(0, 680, 201, 91));
        labelInfo1 = new QLabel(groupBox_5);
        labelInfo1->setObjectName(QStringLiteral("labelInfo1"));
        labelInfo1->setGeometry(QRect(10, 20, 181, 16));
        labelInfo2 = new QLabel(groupBox_5);
        labelInfo2->setObjectName(QStringLiteral("labelInfo2"));
        labelInfo2->setGeometry(QRect(10, 40, 191, 16));
        labelInfo3 = new QLabel(groupBox_5);
        labelInfo3->setObjectName(QStringLiteral("labelInfo3"));
        labelInfo3->setGeometry(QRect(10, 60, 191, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 50, 131, 16));
        comboBoxScene = new QComboBox(groupBox);
        comboBoxScene->setObjectName(QStringLiteral("comboBoxScene"));
        comboBoxScene->setGeometry(QRect(10, 70, 181, 31));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 110, 131, 16));
        comboBoxAlgo = new QComboBox(groupBox);
        comboBoxAlgo->setObjectName(QStringLiteral("comboBoxAlgo"));
        comboBoxAlgo->setGeometry(QRect(10, 130, 181, 31));

        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        PathPlanning->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PathPlanning);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1103, 22));
        PathPlanning->setMenuBar(menubar);
        statusbar = new QStatusBar(PathPlanning);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PathPlanning->setStatusBar(statusbar);

        retranslateUi(PathPlanning);

        QMetaObject::connectSlotsByName(PathPlanning);
    } // setupUi

    void retranslateUi(QMainWindow *PathPlanning)
    {
        PathPlanning->setWindowTitle(QApplication::translate("PathPlanning", "PathPlanning", Q_NULLPTR));
        groupBox->setTitle(QString());
        pushButtonReset->setText(QApplication::translate("PathPlanning", "Reset", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("PathPlanning", "Display options", Q_NULLPTR));
        checkBoxColModel->setText(QApplication::translate("PathPlanning", "Collision model", Q_NULLPTR));
        checkBoxRobot->setText(QApplication::translate("PathPlanning", "robot", Q_NULLPTR));
        checkBoxObstacles->setText(QApplication::translate("PathPlanning", "obstacles", Q_NULLPTR));
        checkBoxFloor->setText(QApplication::translate("PathPlanning", "floor", Q_NULLPTR));
        checkBoxOption1->setText(QApplication::translate("PathPlanning", "option 1", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("PathPlanning", "Control", Q_NULLPTR));
        label_2->setText(QApplication::translate("PathPlanning", "Trajectory", Q_NULLPTR));
        labelMinPos->setText(QApplication::translate("PathPlanning", "0", Q_NULLPTR));
        labelMaxPos->setText(QApplication::translate("PathPlanning", "100", Q_NULLPTR));
        visualizeGridButton->setText(QApplication::translate("PathPlanning", "Visualize Grid (PF only)", Q_NULLPTR));
        pushButtonStep2->setText(QApplication::translate("PathPlanning", "Step 2", Q_NULLPTR));
        pushButtonStep3->setText(QApplication::translate("PathPlanning", "Step 3", Q_NULLPTR));
        pushButtonRunPlanner->setText(QApplication::translate("PathPlanning", "Run Planner", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("PathPlanning", "Info", Q_NULLPTR));
        labelInfo1->setText(QApplication::translate("PathPlanning", "TextLabel", Q_NULLPTR));
        labelInfo2->setText(QApplication::translate("PathPlanning", "TextLabel", Q_NULLPTR));
        labelInfo3->setText(QApplication::translate("PathPlanning", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("PathPlanning", "Select Scene", Q_NULLPTR));
        label_4->setText(QApplication::translate("PathPlanning", "Select Algorithm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PathPlanning: public Ui_PathPlanning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHPLANNING_H
