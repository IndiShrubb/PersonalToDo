#include "task.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVarLengthArray>
#include <QtWidgets>
#include <QSqlQuery>
#include <QSqlError>
#include <QRandomGenerator>

namespace Ui {
class Task;
}

Task::Task()
{

}



 bool Task::UpdateTaskUi(QLineEdit *line_edit, QTableWidget *table)
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

 bool Task::UpdateTaskDb() {
     // make new query
     QSqlQuery query;
     // Set the query up
     query.prepare("INSERT INTO TASK "
                "(id, type, row, task_text) "
                "VALUES "
                "(:id,:type,:row,:task_text)");
     // Populate the query values
     //query.bindValue(":id",NULL);
     query.bindValue(":type",TypeToInt(GetType()));
     query.bindValue(":row",GetRow());
     query.bindValue(":task_text",GetText());

     if(query.exec()) {
         return true;
     }
     else {
         qDebug() << "Error updating db:"
                  << query.lastError();
         return false;
     }
 }

int Task::GetId()
{
    return id;
}

void Task::SetId(int new_id)
{
    id = new_id;
}


void Task::SetType(Task::Type new_type) {
    type = new_type;
}
Task::Type Task::GetType() {
    return type;
}
int Task::TypeToInt(Task::Type type) {
    switch (type) {
        case Task::Type::TODO:
            return 1;
            break;
        case Task::Type::DAILY:
            return 2;
            break;
        case Task::Type::REMINDER:
            return 3;
            break;
        default:
            return 0;
    }
}

void Task::SetRow(int new_row) {
    row = new_row;
}
int Task::GetRow() {
    return row;
}

void Task::SetText(QString new_text) {
    task_text = new_text;
}
QString Task::GetText() {
    return task_text;
}
