#include "codedialog.h"
#include "ui_codedialog.h"

CodeDialog::CodeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CodeDialog)
{
    ui->setupUi(this);
}

CodeDialog::~CodeDialog()
{
    delete ui;
}

void CodeDialog::setText(QString text)
{
    ui->plainTextEdit->setPlainText(text);
}
