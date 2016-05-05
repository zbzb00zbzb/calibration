#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QStyledItemDelegate>
#include <QItemDelegate>
#include <QPainter>
#include <QSignalMapper>
#include <QList>
#include <QProcess>

#include "ui_mainwindow.h"
#include "calibration_gui/gui_calibration_node.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void AddRoot (int rowNUmber);
    void AddChildIP (QTreeWidgetItem *parent, int rowNUmber);
    void setQStrings();
    //void AddChildTopic (QTreeWidgetItem *parent);


public:
    MainWindow(QNode *node, QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_bt_add_clicked();

    void on_bt_remove_clicked();

    void on_treeWidget_itemChanged(QTreeWidgetItem *item, int column);

    void on_bt_start_nodes_clicked();

    void NodeFinished(int exit_code, QProcess::ExitStatus exit_status);

    void on_bt_stop_nodes_clicked();

private:
    Ui::MainWindow *ui;
    QNode *qnode;
    QProcess *process;

    // Parameter Strings
    QString parameterBallDiameter;
    QString parameterNumPoints;
    QList<QString> supportedSensors;
};


// Source: http://www.qtcentre.org/archive/index.php/t-7031.html
// Only column 1 has editable cells
class MyItemDelegate : public QItemDelegate
{
public:
MyItemDelegate(QObject* parent = 0) : QItemDelegate(parent) {}

QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
// allow only specific column to be edited, second column in this example
if (index.column() == 1)
return QItemDelegate::createEditor(parent, option, index);
return 0;
}
};

#endif // MAINWINDOW_H
