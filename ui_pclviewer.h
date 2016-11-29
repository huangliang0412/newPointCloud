/********************************************************************************
** Form generated from reading UI file 'pclviewer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLVIEWER_H
#define UI_PCLVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PCLViewer
{
public:
    QAction *OpenAction;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QMdiArea *mdiArea;
    QWidget *subwindow;
    QHBoxLayout *horizontalLayout_2;
    QVTKWidget *qvtkWidget;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *ShowDockWidget;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QDockWidget *OperateDockWidget;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer_5;
    QSlider *KtreeSlider;
    QSpacerItem *verticalSpacer_4;
    QPushButton *ReconstructButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *BuildButton;
    QSpacerItem *verticalSpacer;
    QPushButton *FilterButton;
    QSpacerItem *verticalSpacer_6;
    QPushButton *ResetButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *ClearButton;

    void setupUi(QMainWindow *PCLViewer)
    {
        if (PCLViewer->objectName().isEmpty())
            PCLViewer->setObjectName(QString::fromUtf8("PCLViewer"));
        PCLViewer->resize(1373, 899);
        OpenAction = new QAction(PCLViewer);
        OpenAction->setObjectName(QString::fromUtf8("OpenAction"));
        centralWidget = new QWidget(PCLViewer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        subwindow = new QWidget();
        subwindow->setObjectName(QString::fromUtf8("subwindow"));
        horizontalLayout_2 = new QHBoxLayout(subwindow);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        qvtkWidget = new QVTKWidget(subwindow);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));

        horizontalLayout_2->addWidget(qvtkWidget);

        mdiArea->addSubWindow(subwindow);

        horizontalLayout->addWidget(mdiArea);

        PCLViewer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PCLViewer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1373, 28));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        PCLViewer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PCLViewer);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PCLViewer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PCLViewer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PCLViewer->setStatusBar(statusBar);
        ShowDockWidget = new QDockWidget(PCLViewer);
        ShowDockWidget->setObjectName(QString::fromUtf8("ShowDockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        horizontalLayout_3 = new QHBoxLayout(dockWidgetContents);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame = new QFrame(dockWidgetContents);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(frame);

        ShowDockWidget->setWidget(dockWidgetContents);
        PCLViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(1), ShowDockWidget);
        OperateDockWidget = new QDockWidget(PCLViewer);
        OperateDockWidget->setObjectName(QString::fromUtf8("OperateDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        horizontalLayout_4 = new QHBoxLayout(dockWidgetContents_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frame_2 = new QFrame(dockWidgetContents_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lcdNumber = new QLCDNumber(frame_2);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        verticalLayout->addWidget(lcdNumber);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        KtreeSlider = new QSlider(frame_2);
        KtreeSlider->setObjectName(QString::fromUtf8("KtreeSlider"));
        KtreeSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(KtreeSlider);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        ReconstructButton = new QPushButton(frame_2);
        ReconstructButton->setObjectName(QString::fromUtf8("ReconstructButton"));

        verticalLayout->addWidget(ReconstructButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        BuildButton = new QPushButton(frame_2);
        BuildButton->setObjectName(QString::fromUtf8("BuildButton"));

        verticalLayout->addWidget(BuildButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        FilterButton = new QPushButton(frame_2);
        FilterButton->setObjectName(QString::fromUtf8("FilterButton"));

        verticalLayout->addWidget(FilterButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        ResetButton = new QPushButton(frame_2);
        ResetButton->setObjectName(QString::fromUtf8("ResetButton"));

        verticalLayout->addWidget(ResetButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        ClearButton = new QPushButton(frame_2);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));

        verticalLayout->addWidget(ClearButton);


        horizontalLayout_4->addWidget(frame_2);

        OperateDockWidget->setWidget(dockWidgetContents_2);
        PCLViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(1), OperateDockWidget);

        menuBar->addAction(menu_F->menuAction());
        menu_F->addAction(OpenAction);

        retranslateUi(PCLViewer);

        QMetaObject::connectSlotsByName(PCLViewer);
    } // setupUi

    void retranslateUi(QMainWindow *PCLViewer)
    {
        PCLViewer->setWindowTitle(QApplication::translate("PCLViewer", "PCLViewer", 0, QApplication::UnicodeUTF8));
        OpenAction->setText(QApplication::translate("PCLViewer", "\346\211\223\345\274\200(&N)", 0, QApplication::UnicodeUTF8));
        subwindow->setWindowTitle(QApplication::translate("PCLViewer", "\345\255\220\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
        menu_F->setTitle(QApplication::translate("PCLViewer", "\346\226\207\344\273\266(&F)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PCLViewer", "                \347\202\271\344\272\221\347\262\276\347\256\200", 0, QApplication::UnicodeUTF8));
        ReconstructButton->setText(QApplication::translate("PCLViewer", "\347\202\271\344\272\221\351\207\215\346\236\204", 0, QApplication::UnicodeUTF8));
        BuildButton->setText(QApplication::translate("PCLViewer", "\346\233\262\351\235\242\351\207\215\345\273\272", 0, QApplication::UnicodeUTF8));
        FilterButton->setText(QApplication::translate("PCLViewer", "\346\233\262\351\235\242\345\205\211\346\273\221", 0, QApplication::UnicodeUTF8));
        ResetButton->setText(QApplication::translate("PCLViewer", "\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
        ClearButton->setText(QApplication::translate("PCLViewer", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PCLViewer: public Ui_PCLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLVIEWER_H
