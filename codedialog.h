#ifndef CODEDIALOG_H
#define CODEDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class CodeDialog;
}

class CodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CodeDialog(QWidget *parent = 0);
    ~CodeDialog();
    void setText(QString text);

private:
    Ui::CodeDialog *ui;
};

#endif // CODEDIALOG_H
