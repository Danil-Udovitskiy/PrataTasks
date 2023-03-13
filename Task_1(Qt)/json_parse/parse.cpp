#include <QtGui>
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QMessageBox>
#include <QStringList>
#include "parse.h"


ResultWindow::ResultWindow(QWidget *parent,QString str): QDialog(parent)
{
    firstName = new QLabel(tr("First users name:"));
    secondName = new QLabel(tr("Second users name:"));
    age = new QLabel(tr("Users age:"));
    fathersName = new QLabel(tr("Fathers name:"));
    fathersAge = new QLabel(tr("Fathers age:"));
    fathersWeight = new QLabel(tr("Fathers weight:"));
    mothersName = new QLabel(tr("Mothers name:"));
    mothersAge = new QLabel(tr("Mothers age:"));
    mothersWeight = new QLabel(tr("Mothers weight:"));

    firstNamea = new QLabel;
    secondNamea = new QLabel;
    agea = new QLabel;
    fathersNamea = new QLabel;
    fathersAgea = new QLabel;
    fathersWeighta = new QLabel;
    mothersNamea = new QLabel;
    mothersAgea = new QLabel;
    mothersWeighta = new QLabel;



    QHBoxLayout* Layout1 = new QHBoxLayout;
    Layout1->addWidget(firstName);
    Layout1->addWidget(firstNamea);

    QHBoxLayout* Layout2 = new QHBoxLayout;
    Layout2->addWidget(secondName);
    Layout2->addWidget(secondNamea);

    QHBoxLayout* Layout3 = new QHBoxLayout;
    Layout3->addWidget(age);
    Layout3->addWidget(agea);

    QHBoxLayout* Layout4 = new QHBoxLayout;
    Layout4->addWidget(fathersName);
    Layout4->addWidget(fathersNamea);

    QHBoxLayout* Layout5 = new QHBoxLayout;
    Layout5->addWidget(fathersAge);
    Layout5->addWidget(fathersAgea);

    QHBoxLayout* Layout6 = new QHBoxLayout;
    Layout6->addWidget(fathersWeight);
    Layout6->addWidget(fathersWeighta);

    QHBoxLayout* Layout7 = new QHBoxLayout;
    Layout7->addWidget(mothersName);
    Layout7->addWidget(mothersNamea);

    QHBoxLayout* Layout8 = new QHBoxLayout;
    Layout8->addWidget(mothersAge);
    Layout8->addWidget(mothersAgea);

    QHBoxLayout* Layout9 = new QHBoxLayout;
    Layout9->addWidget(mothersWeight);
    Layout9->addWidget(mothersWeighta);




    QVBoxLayout* LayoutVert = new QVBoxLayout;
    LayoutVert->addLayout(Layout1);
    LayoutVert->addLayout(Layout2);
    LayoutVert->addLayout(Layout3);
    LayoutVert->addLayout(Layout4);
    LayoutVert->addLayout(Layout5);
    LayoutVert->addLayout(Layout6);
    LayoutVert->addLayout(Layout7);
    LayoutVert->addLayout(Layout8);
    LayoutVert->addLayout(Layout9);
    LayoutVert->setAlignment(Qt::AlignLeft);


    Parse(str);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(LayoutVert);

    setLayout(mainLayout);
    setWindowTitle("Parsed data");
    resize(600, 400);
}


void ResultWindow::Parse(QString str)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());

        // Check if there was an error while parsing
        if (jsonDoc.isNull())
        {
            QMessageBox::warning(nullptr, "Error", "Incorrect JSON string");
            return;
        }

        QJsonObject jsonObj = jsonDoc.object();
        //check the correctness of the content for the keys

        if (!jsonObj.contains("First name") || !jsonObj.contains("Second name") || !jsonObj.contains("Age") || !jsonObj.contains("Family"))
        {
            QMessageBox::warning(nullptr, "Error", "First name or Second name or Age or Family - JSON string does not contain all required keys");
            return;
        }

        QJsonObject familyObj = jsonObj.value("Family").toObject();

        if (!familyObj.contains("Father") || !familyObj.contains("Mother"))
        {
            QMessageBox::warning(nullptr, "Error", "Family - JSON string does not contain all required keys");
            return;
        }

        QJsonObject fatherObj = familyObj.value("Father").toObject();

        if (!fatherObj.contains("Name") || !fatherObj.contains("Age") || !fatherObj.contains("Weight"))
        {
            QMessageBox::warning(nullptr, "Error", "Father - JSON string does not contain all required keys");
            return;
        }

        QJsonObject motherObj = familyObj.value("Mother").toObject();

        if (!motherObj.contains("Name") || !motherObj.contains("Age") || !motherObj.contains("Weight"))
        {
            QMessageBox::warning(nullptr, "Error", "Mother - JSON string does not contain all required keys");
            return;
        }


        //Get the values of the various keys from the jsonObj JSON object and store them in variables of type QString
        QString firstName = jsonObj["First name"].toString();
        QString secondName = jsonObj["Second name"].toString();
        QString age = jsonObj["Age"].toString();

        QJsonObject father = jsonObj["Family"].toObject()["Father"].toObject();
        QString fathersName = father["Name"].toString();
        QString fathersAge = QString::number(father["Age"].toInt());
        QString fathersWeight = QString::number(father["Weight"].toDouble());

        QJsonObject mother = jsonObj["Family"].toObject()["Mother"].toObject();
        QString mothersName = mother["Name"].toString();
        QString mothersAge = QString::number(mother["Age"].toInt());
        QString mothersWeight = QString::number(mother["Weight"].toDouble());

        firstNamea->setText(firstName);
        secondNamea->setText(secondName);
        agea->setText(age);
        fathersNamea->setText(fathersName);
        fathersAgea->setText(fathersAge);
        fathersWeighta->setText(fathersWeight);
        mothersNamea->setText(mothersName);
        mothersAgea->setText(mothersAge);
        mothersWeighta->setText(mothersWeight);

        QStringList resultList;
        resultList << firstName << firstNamea->text();
        resultList << secondName << secondNamea->text();
        resultList << age << agea->text();
        resultList << fathersName << fathersNamea->text();
        resultList << fathersAge << fathersAgea->text();
        resultList << fathersWeight << fathersWeighta->text();
        resultList << mothersName << mothersNamea->text();
        resultList << mothersAge << mothersAgea->text();
        resultList << mothersWeight << mothersWeighta->text();
}


MainWindow::MainWindow(QWidget* parent):QWidget(parent)
{
    setWindowTitle(tr("JSON Parser"));
    resize(600, 400);

    jsonEdit = new QTextEdit;
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(jsonEdit);

    //button
    parseButton = new QPushButton(tr("Parse"));
    connect(parseButton, QPushButton::clicked, this, MainWindow::parseJson);

    layout->addWidget(parseButton);
}


void MainWindow::parseJson()
{
    ResultWindow* resultWindow = new ResultWindow(this, jsonEdit->toPlainText());

    // Getting the geometry of the main window
    QRect mainRect = this->geometry();

    // Calculate the coordinates for the window resultWindow
    int resultX = mainRect.x() + 10;
    int resultY = mainRect.y()-50;

    // Set new coordinates for resultWindow window
    resultWindow->move(resultX, resultY);

    resultWindow->show();
}
