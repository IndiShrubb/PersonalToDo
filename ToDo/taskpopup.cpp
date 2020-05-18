#include "taskpopup.h"
#include "ui_taskpopup.h"
#include "task.h"

TaskPopup::TaskPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskPopup)
{
    ui->setupUi(this);
}

TaskPopup::~TaskPopup()
{
    delete ui;
}

//void TaskPopup::Populate(Task *t) {
//    ui->lineEdit->setText(t->GetText());
//}

void TaskPopup::on_pushButton_2_clicked()
{
    QDialog *dialog = new QDialog(this);

    close();

    delete dialog;
}
