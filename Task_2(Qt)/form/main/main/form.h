#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

#include <QKeyEvent>

class MyTextEdit : public QTextEdit
{
public:
    MyTextEdit(QWidget *parent = 0) : QTextEdit(parent) {};

protected:
    void keyPressEvent(QKeyEvent *event) override
    {
        if (event->key() == Qt::Key_Comma || event->key() == Qt::Key_Space ||(event->key() >= Qt::Key_A && event->key() <= Qt::Key_Z))
        {
            QTextEdit::keyPressEvent(event);
        }
        else
        {
            event->ignore();
        }
    }
};




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
    MyTextEdit * textEdit;

    QPushButton* saveButton;
};

#endif

