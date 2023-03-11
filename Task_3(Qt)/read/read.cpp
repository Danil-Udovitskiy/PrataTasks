#include <QtGui>
#include <QString>
#include "read.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>



Read::Read(QWidget* parent) : QDialog(parent)
{
    //Name
    label1 = new QLabel(tr("First name:"));
    label1->setFixedWidth(100);
    lineEdit1 = new QLineEdit;
    lineEdit1->setFixedWidth(300);
    lineEdit1->setReadOnly(true);


    //Second name
    label2 = new QLabel(tr("Second name:"));
    label2->setFixedWidth(100);
    lineEdit2 = new QLineEdit;
    lineEdit2->setFixedWidth(300);
    lineEdit2->setReadOnly(true);

    //Age
    label3 = new QLabel(tr("Age:"));
    label3->setFixedWidth(100);
    lineEdit3 = new QLineEdit;
    lineEdit3->setFixedWidth(300);
    lineEdit3->setReadOnly(true);

    //Hobbies
    label4 = new QLabel(tr("Hobbies:"));
    label4->setFixedWidth(100);
    //textEdit = new MyTextEdit;
    textEdit = new QTextEdit;
    textEdit->setFixedWidth(300);
    textEdit->setReadOnly(true);

    //button
    readButton = new QPushButton(tr("Read"));
    connect(readButton, SIGNAL(clicked()), this, SLOT(readClicked()));

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
    Layout4->addWidget(textEdit);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(Layout1);
    mainLayout->addLayout(Layout2);
    mainLayout->addLayout(Layout3);
    mainLayout->addLayout(Layout4);
    mainLayout->addWidget(readButton);
    setLayout(mainLayout);

    //Window name + size
    setWindowTitle(tr("User profile"));

    setFixedHeight(sizeHint().height());
}


void Read::readClicked()
{
    readFromFile();
}


void Read::readFromFile()
{    
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), " ", tr("Text Files (*.txt);"));
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
       qWarning("Cannot open file for reading");
    }

    QTextStream in(&file);

    while (!in.atEnd())
    {
       QString word;
       QString line;

       //1 block
       line = in.readLine();

       if (line.startsWith("First name:"))
       {
           word = line.section(':', 1);
           //label1->setText(word);
       }
       else
       {
           Clear();
           QMessageBox::warning(this,"Error","Incorrect file! (label1)");
           break;
       }

       QRegExp regExp1("[A-Za-z]+");
       if (regExp1.exactMatch(word))
       {
          lineEdit1->setText(word);
       }
       else
       {
           Clear();
           QMessageBox::warning(this,"Error","Incorrect file! (lineEdit1)");
           break;
       }



       //2 block
       line = in.readLine();

       if (line.startsWith("Second name:"))
       {
           word = line.section(':', 1);
           //label2->setText(word);
       }
       else
       {
           Clear();
           QMessageBox::warning(this,"Error","Incorrect file! (label2)");
           break;
       }

       word = line.section(':', 1);
       if (regExp1.exactMatch(word))
       {
          lineEdit2->setText(word);
       }
       else
       {
           Clear();
           QMessageBox::warning(this,"Error","Incorrect file! (lineEdit2)");
           break;
       }



       //3 block
       line = in.readLine();

       if (line.startsWith("Age:"))
       {
           word = line.section(':', 1);
           //label3->setText(word);
       }

       else
       {
           Clear();
           QMessageBox::warning(this,"Error","Incorrect file! (label3)");
           break;
       }

       word = line.section(':', 1);
       QRegExp regExp2( "[0-9]{1,2}" );
       if (regExp2.exactMatch(word))
       {
          lineEdit3->setText(word);
       }
       else
       {
           Clear();
           QMessageBox::warning(this,"Error","Incorrect file! (lineEdit3)");
           break;
       }



       //4 block
       line = in.readLine();

       if (line.startsWith("Hobbies:"))
       {
           word = line.section(':', 1);
           //label4->setText(word);
       }

       else
       {
           Clear();
           QMessageBox::warning(this,"Error","Incorrect file! (label4)");
           break;
       }

       word = line.section(':', 1);
       QRegExp regExp3( "[A-Za-z, ]+" );
       if (regExp3.exactMatch(word))
       {
           textEdit->setText(word);
       }
       else
       {
           Clear();
           QMessageBox::warning(this,"Error","Incorrect file! (textEdit)");
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
    textEdit->clear();
}
