#include <QtGui>
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QMessageBox>
#include <QStringList>
#include "parse.h"

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
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonEdit->toPlainText().toUtf8());

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


    //Create second window
    QWidget* resultWindow = new QWidget;
    QVBoxLayout* resultLayout = new QVBoxLayout(resultWindow);
    QTextEdit* resultEdit = new QTextEdit;
    resultEdit->setReadOnly(true);
    resultLayout->addWidget(resultEdit);
    resultWindow->setWindowTitle("Parsed data");
    resultWindow->resize(600, 400);


    // Getting the geometry of the main window
    QRect mainRect = this->geometry();

    // Calculate the coordinates for the window resultWindow
    int resultX = mainRect.x() + 10;
    int resultY = mainRect.y()-50;

    // Set new coordinates for resultWindow window
    resultWindow->move(resultX, resultY);


    QStringList resultList;
    resultList << "First user's name: " + firstName + "\n";
    resultList << "Second user's name: " + secondName + "\n";
    resultList << "User's age: " + age + "\n";
    resultList << "Father's name: " + fathersName;
    resultList << "Father's age: " + fathersAge;
    resultList << "Father's weight: " + fathersWeight + "\n";
    resultList << "Mother's name: " + mothersName;
    resultList << "Mother's age: " + mothersAge;
    resultList << "Mother's weight: " + mothersWeight;

    //Concatenate all elements of resultList into one string
    resultEdit->setText(resultList.join("\n"));
    resultWindow->show();
}
