#ifndef PARSE_H
#define PARSE_H

#include <QTextEdit>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>

class ResultWindow : public QWidget
{
    Q_OBJECT

public:
    ResultWindow(QWidget *parent = nullptr,QString str="");
    void Parse(QString str);

private:
    QLabel* firstName;
    QLabel* secondName;
    QLabel* age;
    QLabel* fathersName;
    QLabel* fathersAge;
    QLabel* fathersWeight;
    QLabel* mothersName;
    QLabel* mothersAge;
    QLabel* mothersWeight;

    QLabel* firstNamea;
    QLabel* secondNamea;
    QLabel* agea;
    QLabel* fathersNamea;
    QLabel* fathersAgea;
    QLabel* fathersWeighta;
    QLabel* mothersNamea;
    QLabel* mothersAgea;
    QLabel* mothersWeighta;
};



class MainWindow : public QWidget
{
    Q_OBJECT
public:

    MainWindow(QWidget* parent = nullptr);

private slots:
    void parseJson();


private:
    QTextEdit* jsonEdit;
    QPushButton* parseButton;
};

#endif




