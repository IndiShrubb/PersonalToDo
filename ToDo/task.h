#ifndef TASK_H
#define TASK_H

#include "ui_mainwindow.h"
#include "mainwindow.h"

class Task
{
public:
    Task();

    bool MakeTask(QLineEdit *line_edit, QTableWidget *table);

    bool UpdateTaskText(QString new_string); //TODO: implement this in the popup menu so you can change the task text

    bool UpdateTaskRow(int new_row); //TODO: make it so you can drag tasks to a different order

    bool MakeChecklist(); //TODO: make it so you can have a list of sub-items when you double click a task
private:
    QString task_text{};
    int row{};
    QVarLengthArray<QString> checklist_text;
};

#endif // TASK_H
