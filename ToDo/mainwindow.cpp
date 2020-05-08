#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"
#include "taskpopup.h"
#include <QTime>
#include <QStyleFactory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowIcon(QIcon("todo.ico")); //This doesn't work

    //Dark mode stylesheet, woul dlike for this to be an option and have other themes
    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(darkPalette);
    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");

    // Custom Slot connectors
    QObject::connect(ui->tableWidget, SIGNAL(cellChanged(int, int)), this, SLOT(task_checked(int, int)));
    QObject::connect(ui->tableWidget_2, SIGNAL(cellChanged(int, int)), this, SLOT(task_checked_2(int, int)));
    QObject::connect(ui->tableWidget_3, SIGNAL(cellChanged(int, int)), this, SLOT(task_checked_3(int, int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


// ENTER TO DO -- BUTTON
void MainWindow::on_pushButton_clicked()
{
    auto obj = ui->lineEdit; // line edit object associated with Dailies PushButton
    if(obj->text().size() == 0) return; // if empty do nothing
    auto table = ui->tableWidget; // table widget object    
    bool result;
    Task t;
    result = t.MakeTask(obj, table);
    if(!result)
    {
        //some error message
    }
}

// ENTER DAILIES -- BUTTON
void MainWindow::on_pushButton_2_clicked()
{
    auto obj = ui->lineEdit_2; // line edit object associated with Dailies PushButton
    if(obj->text().size() == 0) return; // if empty do nothing
    auto table = ui->tableWidget_2; // table widget object
    bool result;
    Task t;
    result = t.MakeTask(obj, table);
}

// ENTER REMINDERS -- BUTTON
void MainWindow::on_pushButton_3_clicked()
{
    auto obj = ui->lineEdit_3; // line edit object associated with Dailies PushButton
    if(obj->text().size() == 0) return; // if empty do nothing
    auto table = ui->tableWidget_3; // table widget object
    bool result;
    Task t;
    result = t.MakeTask(obj, table);
}

// COMPLETE TASK
void MainWindow::task_checked(int row, int col)
{
    QTableWidgetItem *item = ui->tableWidget->item(row, col);
    if(item->checkState() == Qt::Checked)
    {
        ui->tableWidget->removeRow(row);
    }
}

// COMPLETE DAILY
void MainWindow::task_checked_2(int row, int col)
{
    QTableWidgetItem *item = ui->tableWidget_2->item(row, col);
    if(item->checkState() == Qt::Checked)
    {
        ui->tableWidget_2->removeRow(row);
    }
}

// COMPLETE REMINDER
void MainWindow::task_checked_3(int row, int col)
{
    QTableWidgetItem *item = ui->tableWidget_3->item(row, col);
    if(item->checkState() == Qt::Checked)
    {
        ui->tableWidget_3->removeRow(row);
    }
}

// ENTER TO DO -- RETURN
void MainWindow::on_lineEdit_returnPressed()
{
    auto obj = ui->lineEdit; // line edit object associated with Dailies PushButton
    if(obj->text().size() == 0) return; // if empty do nothing
    auto table = ui->tableWidget; // table widget object
    bool result;
    Task t;
    result = t.MakeTask(obj, table);
}

// ENTER DAILY -- RETURN
void MainWindow::on_lineEdit_2_returnPressed()
{
    auto obj = ui->lineEdit_2; // line edit object associated with Dailies PushButton
    if(obj->text().size() == 0) return; // if empty do nothing
    auto table = ui->tableWidget_2; // table widget object
    bool result;
    Task t;
    result = t.MakeTask(obj, table);
}

// ENTER REMINDERS -- RETURN
void MainWindow::on_lineEdit_3_returnPressed()
{
    auto obj = ui->lineEdit_3; // line edit object associated with Dailies PushButton
    if(obj->text().size() == 0) return; // if empty do nothing
    auto table = ui->tableWidget_3; // table widget object
    bool result;
    Task t;
    result = t.MakeTask(obj, table);
}

// EDIT DAILY -- OPEN THE POPUP WINDOW
void MainWindow::on_tableWidget_2_cellDoubleClicked(int row, int column)
{
    qDebug("Doubley Clickerdoo");
    TaskPopup tp;
    tp.exec();
}
