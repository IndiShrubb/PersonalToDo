#ifndef TASK_H
#define TASK_H

#include "ui_mainwindow.h"
#include "mainwindow.h"

class Task
{
public:
    Task();

    enum Type {
        TODO,
        DAILY,
        REMINDER
    };

    bool UpdateTaskUi(QLineEdit *line_edit, QTableWidget *table);
    bool UpdateTaskDb();

    int GenerateId();
    void SetId(int);
    int GetId();

    void SetType(Task::Type new_type);
    Task::Type GetType();
    int TypeToInt(Task::Type type);


    void SetRow(int new_row);
    int GetRow();

    void SetText(QString new_text);
    QString GetText();

    bool UpdateTaskText(QString *new_string); //TODO: implement this in the popup menu so you can change the task text

    bool UpdateTaskRow(int new_row); //TODO: make it so you can drag tasks to a different order

    bool MakeChecklist(); //TODO: make it so you can have a list of sub-items when you double click a task



private:
    int id{};
    Type type{}; // To Do - 1 ; Daily - 2 ; Reminder - 3 ;
    int row{};
    QString task_text{};
    QVarLengthArray<QString> checklist_text;
};

#endif // TASK_H
