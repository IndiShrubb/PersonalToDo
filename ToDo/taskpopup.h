#ifndef TASKPOPUP_H
#define TASKPOPUP_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class TaskPopup;
}

class TaskPopup : public QDialog
{
    Q_OBJECT

public:
    explicit TaskPopup(QWidget *parent = nullptr);
    ~TaskPopup();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::TaskPopup *ui;
};

#endif // TASKPOPUP_H
