#include <QtGui>
#include <QString>
#include "read.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


Read::Read(QWidget* parent) : QDialog(parent)
{
    //Name
    label1 = new QLabel(tr("First name:"));
    lineEdit1 = new QLineEdit;
    //QRegExp regExp1( "[A-Za-z]+" );
    //QRegExp regExp1("");
    //lineEdit1->setValidator(new QRegExpValidator(regExp1, this ));
    lineEdit1->setReadOnly(true);
    label1->setBuddy(lineEdit1);

    //Second name
    label2 = new QLabel(tr("Second name:"));
    lineEdit2 = new QLineEdit;
    //lineEdit2->setValidator(new QRegExpValidator(regExp1, this ));
    lineEdit2->setReadOnly(true);
    label2->setBuddy(lineEdit2);

    //Age
    label3 = new QLabel(tr("Age:"));
    lineEdit3 = new QLineEdit;
    //QRegExp regExp2( "[0-9]{2}" );
    //lineEdit3->setValidator(new QRegExpValidator(regExp2, this ));
    lineEdit3->setReadOnly(true);
    label3->setBuddy(lineEdit3);

    //Hobbies
    label4 = new QLabel(tr("Hobbies:"));
    lineEdit4 = new QLineEdit;
    //QRegExp regExp3( "[A-Za-z, ]+" );
    //lineEdit4->setValidator(new QRegExpValidator(regExp3, this ));
    lineEdit4->setReadOnly(true);
    label4->setBuddy(lineEdit4);

    //button
    saveButton = new QPushButton(tr("Read"));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveClicked()));

    //Layouts
    QHBoxLayout* Layout1 = new QHBoxLayout;
    Layout1->addWidget(label1);
    Layout1->addWidget(lineEdit1);

    QHBoxLayout* Layout2 = new QHBoxLayout;
    Layout2->addWidget(label2);
    Layout2->addWidget(lineEdit2);

    QHBoxLayout* Layout3 = new QHBoxLayout;
    Layout3->addWidget(label3);
    Layout3->addWidget(lineEdit3);

    QHBoxLayout* Layout4 = new QHBoxLayout;
    Layout4->addWidget(label4);
    Layout4->addWidget(lineEdit4);


    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(Layout1);
    mainLayout->addLayout(Layout2);
    mainLayout->addLayout(Layout3);
    mainLayout->addLayout(Layout4);
    mainLayout->addWidget(saveButton);
    setLayout(mainLayout);

    //Window name + size
    setWindowTitle(tr("User profile"));

    setFixedHeight(sizeHint().height());
}


void Read::saveClicked()
{
    Write();
}


void Read::Write()
{
    QTextStream out(stdout);

    QString filename =QFileDialog::getOpenFileName(this, tr("Open File"), " ", tr("Text Files (*.txt);"));
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
       qWarning("Cannot open file for reading");
    }

    QTextStream in(&file);

    while (!in.atEnd())
    {
       QString line = in.readLine();
       QString word;

       word = line.section(':', 1);
       QRegExp regExp1("[A-Za-z]+");
       if (regExp1.exactMatch(word))
       {
          lineEdit1->setText(word);
       }
       else
       {
           Clear();
           QMessageBox::warning(this,"Error","Incorrect file!");
           break;
       }

       line = in.readLine();
       word = line.section(':', 1);
       if (regExp1.exactMatch(word))
       {
          lineEdit2->setText(word);
       }
       else
       {
           Clear();
           QMessageBox::warning(this,"Error","Incorrect file!");
           break;
       }

       line = in.readLine();
       word = line.section(':', 1);
       QRegExp regExp2( "[0-9]{2}" );
       if (regExp2.exactMatch(word))
       {
          lineEdit3->setText(word);
       }
       else
       {
           Clear();
           QMessageBox::warning(this,"Error","Incorrect file!");
           break;
       }

       line = in.readLine();
       word = line.section(':', 1);
       QRegExp regExp3( "[A-Za-z, ]+" );
       if (regExp3.exactMatch(word))
       {
          lineEdit4->setText(word);
       }
       else
       {
           Clear();
           QMessageBox::warning(this,"Error","Incorrect file!");
           break;

       }
    }

    file.close();
}


void Read::Clear()
{
    lineEdit1->clear();
    lineEdit2->clear();
    lineEdit3->clear();
    lineEdit4->clear();
}
