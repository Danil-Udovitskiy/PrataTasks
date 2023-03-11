#ifndef READ_H
#define READ_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>


class Read : public QDialog
{
    Q_OBJECT

public:

    Read(QWidget* parent = 0);
    void readFromFile();
    void Clear();

private slots:

    void readClicked();

private:

    QLabel* label1;
    QLineEdit* lineEdit1;

    QLabel* label2;
    QLineEdit* lineEdit2;

    QLabel* label3;
    QLineEdit* lineEdit3;

    QLabel* label4;
    QTextEdit* textEdit;

    QPushButton* readButton;
};

#endif
