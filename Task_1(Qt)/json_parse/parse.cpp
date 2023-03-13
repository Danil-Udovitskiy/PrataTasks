#include <QtGui>
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QMessageBox>
#include <QStringList>
#include "parse.h"

ResultWindow::ResultWindow(QWidget *parent,QString str): QWidget(parent)
{

    firstName = new QLabel(tr("First users name:"));
    firstName->setFixedWidth(100);

    secondName = new QLabel(tr("Second users name:"));
    secondName->setFixedWidth(100);

    age = new QLabel(tr("Users age:"));
    age->setFixedWidth(100);

    fathersName = new QLabel(tr("Fathers name:"));
    fathersName->setFixedWidth(100);

    fathersAge = new QLabel(tr("Fathers age:"));
    fathersAge->setFixedWidth(100);

    fathersWeight = new QLabel(tr("Fathers weight:"));
    fathersWeight->setFixedWidth(100);

    mothersName = new QLabel(tr("Mothers name:"));
    mothersName->setFixedWidth(100);

    mothersAge = new QLabel(tr("Mothers age:"));
    mothersAge->setFixedWidth(100);

    mothersWeight = new QLabel(tr("Mothers weight:"));
    mothersWeight->setFixedWidth(100);


    QVBoxLayout* Layout1 = new QVBoxLayout;
    Layout1->addWidget(firstName);
    Layout1->addWidget(secondName);
    Layout1->addWidget(age);
    Layout1->addWidget(fathersName);
    Layout1->addWidget(fathersAge);
    Layout1->addWidget(fathersWeight);
    Layout1->addWidget(mothersName);
    Layout1->addWidget(mothersAge);
    Layout1->addWidget(mothersWeight);



    Parse(str);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(Layout1);
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
    ResultWindow* resultWindow = new ResultWindow;
    //ResultWindow* resultWindow = new ResultWindow(this, jsonEdit->toPlainText());

    // Getting the geometry of the main window
    QRect mainRect = this->geometry();

    // Calculate the coordinates for the window resultWindow
    int resultX = mainRect.x() + 10;
    int resultY = mainRect.y()-50;

    // Set new coordinates for resultWindow window
    resultWindow->move(resultX, resultY);

    //resultWindow->show();
}
