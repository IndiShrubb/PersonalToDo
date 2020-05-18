#ifndef TASKPOPUP_H
#define TASKPOPUP_H

#include <QWidget>
#include <QDialog>
#include "task.h"

namespace Ui {
class TaskPopup;
}

class TaskPopup : public QDialog
{
    Q_OBJECT

public:
    explicit TaskPopup(QWidget *parent = nullptr);
    ~TaskPopup();
    void Populate();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::TaskPopup *ui;
    Task *task;
};

#endif // TASKPOPUP_H
