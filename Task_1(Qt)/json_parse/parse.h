#ifndef PARSE_H
#define PARSE_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

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
