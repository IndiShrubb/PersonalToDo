#include "task.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVarLengthArray>
#include <QtWidgets>

namespace Ui {
class Task;
}

Task::Task()
{

}

 bool Task::MakeTask(QLineEdit *line_edit, QTableWidget *table)
{
    QTableWidgetItem *box = new QTableWidgetItem;
    box->setCheckState(Qt::Unchecked); // Create checkbox for daily
    QTableWidgetItem *text = new QTableWidgetItem;
    text->setText(line_edit->text()); // Add text to daily

    int num_rows = table->rowCount(); // Get amount of rows
    table->insertRow(num_rows); // Add row to bottom of list
    table->setItem(num_rows,0, box); // Add in checkbox
    table->setItem(num_rows,1, text); // Add in text from line edit

    table->setColumnWidth(0,20);
    table->setColumnWidth(1,table->maximumWidth());
    table->resizeRowToContents(num_rows);

    if(text->text() == line_edit->text())
    {
        line_edit->clear(); // clear line edit
        return true;
    }
    else return false;
}
