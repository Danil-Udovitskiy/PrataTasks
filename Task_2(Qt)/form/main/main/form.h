#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include <QFileDialog>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Form : public QDialog
{
    Q_OBJECT

public:

    Form(QWidget* parent = 0);
    void Write();

private slots:

    void saveClicked();

private:

    QLabel* label1;
    QLineEdit* lineEdit1;

    QLabel* label2;
    QLineEdit* lineEdit2;

    QLabel* label3;
    QLineEdit* lineEdit3;

    QLabel* label4;
    QLineEdit* lineEdit4;

    QPushButton* saveButton;
};

#endif

