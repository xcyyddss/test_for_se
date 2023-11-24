#ifndef LOGIC_H
#define LOGIC_H

#include <QWidget>
#include<operationwindow.h>
#include<QStackedWidget>
#include<doctor.h>
#include<manager.h>
#include<patient.h>
#include<pharmacist.h>
#include<QMessageBox>
#include <QDateTime>
#include <QRegExp>

class logic : public QWidget
{
    Q_OBJECT
private:
    QStackedWidget* stackedWidget;
    OperationWindow* opwindow[100];
    Doctor* doctor;
    Patient* patient;
    Manager* manager;
    Pharmacist* pharmacist;
    QString now_date;
public:
    explicit logic(QWidget *parent = nullptr);

signals:

public slots:
    void solve1(int);
    void solvep1(int);
    void solvep2(int);
    void solvep3(int);
    void solvep4(int);
    void solvep5(int);
    void solved1(int);
    void solved2(int);
    void solved3(int);
    void solved4(int);
    void solved5(int);
    void solved6(int);
    void solved7(int);
    void solved8(int);
    void solveph1(int);
    void solveph2(int);
    void solveph3(int);
    void solvem1(int);
    void solvem2(int);
    void solvem3(int);
    void solvem4(int);
    void solvem5(int);
    void solvem6(int);
};
QString list_to_str(QLinkedList<QLinkedList<QString>> list,int index);

#endif // LOGIC_H
