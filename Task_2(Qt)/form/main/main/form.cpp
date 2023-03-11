#include <QtGui>
#include <QString>
#include "form.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>


Form::Form(QWidget* parent) : QDialog(parent)
{
    //Name
    label1 = new QLabel(tr("First name:"));
    label1->setFixedWidth(100);
    lineEdit1 = new QLineEdit;
    lineEdit1->setFixedWidth(300);
    QRegExp regExp1( "[A-Za-z]+" );
    lineEdit1->setValidator(new QRegExpValidator(regExp1, this ));
    label1->setBuddy(lineEdit1);

    //Second name
    label2 = new QLabel(tr("Second name:"));
    label2->setFixedWidth(100);
    lineEdit2 = new QLineEdit;
    lineEdit2->setFixedWidth(300);
    lineEdit2->setValidator(new QRegExpValidator(regExp1, this ));
    label2->setBuddy(lineEdit2);

    //Age
    label3 = new QLabel(tr("Age:"));
    label1->setFixedWidth(100);
    lineEdit3 = new QLineEdit;
    lineEdit3->setFixedWidth(300);
    QRegExp regExp2("[0-9]{1,2}");
    lineEdit3->setValidator(new QRegExpValidator(regExp2, this ));
    label3->setBuddy(lineEdit3);

    //Hobbies
    label4 = new QLabel(tr("Hobbies:"));
    label4->setFixedWidth(100);
    textEdit = new MyTextEdit;
    textEdit->setFixedWidth(300);
    textEdit->setWordWrapMode(QTextOption::WrapAnywhere);
    textEdit->setAlignment(Qt::AlignLeft);

    //button
    saveButton = new QPushButton(tr("Save"));
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
    Layout4->addWidget(textEdit);

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


void Form::saveClicked()
{
    Write();
}


void Form::Write()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), " ", tr("Text Files (*.txt);"));
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);
        out<<label1->text()<<lineEdit1->text()<<"\n";
        out<<label2->text()<<lineEdit2->text()<<"\n";
        out<<label3->text()<<lineEdit3->text()<<"\n";
        out<<label4->text()<<textEdit->toPlainText()<<"\n";
    }
    else
    {
        qWarning("Could not open file");
    }

    file.close();

    lineEdit1->clear();
    lineEdit2->clear();
    lineEdit3->clear();
    textEdit->clear();
}
