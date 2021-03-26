#include "facecmp.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPushButton>
#include <QDebug>

facecmp::facecmp(QWidget *parent) : QWidget(parent)
{
    /*
    QPushButton *a = new QPushButton("select1");
    QPushButton *b = new QPushButton("select2");
    QHBoxLayout *layout2 = new QHBoxLayout();
    QHBoxLayout *layout3 = new QHBoxLayout();
    QLabel *aa = new QLabel("please select");
    aa->setFrameShape(QFrame::Box);
    aa->resize(75,50);
    aa->setStyleSheet("border-width:1px;border-style:solid;border-color:rgb(255,170,0);");
    QLabel *bb = new QLabel("please select");
    bb->setFrameShape(QFrame::Box);
    bb->setStyleSheet("border-width:1px;border-style:solid;border-color:rgb(255,170,0);");
    bb->resize(75,50);
    layout2->addWidget(aa);
    layout2->addWidget(bb);
    layout2->setContentsMargins(200,0,200,0);
    layout2->setSpacing(50);
    layout3->addWidget(a);
    layout3->addWidget(b);
    layout3->setContentsMargins(300,50,300,50);
    layout3->setSpacing(300);

    QLabel *result = new QLabel();
    result->setText("result display");
    result->setAlignment(Qt::AlignCenter);

    QPushButton *cmp = new QPushButton("compare");
    cmp->setStyleSheet("margin: 0 400 0 400");


    pathl = nullptr;
    pathr = nullptr;
    res = nullptr;

    connect(a,&QPushButton::clicked,this,&facecmp::open1);
    connect(b,&QPushButton::clicked,this,&facecmp::open2);
    connect(cmp,SIGNAL(clicked(bool)),this,SLOT(sendsignal()));




    QVBoxLayout *qlayout4 = new QVBoxLayout(this);
    qlayout4->addLayout(layout2,3);
    qlayout4->addLayout(layout3,1);
    qlayout4->addWidget(cmp,1);
    qlayout4->addWidget(result,1);
    */

}
/*
void facecmp::sendsignal()
{
    qDebug() << "send";
    emit mysignal(pathl,pathr,res);
    qDebug() << res;
}

void facecmp::open1()
{
    qDebug() << "open1";
    QString path1 = QFileDialog::getOpenFileName(this,"open","../","all(*.*);;source(*.cpp *.h);;Text(*.txt);;all(*.*);;pic(*.jpg *.png)");
}

void facecmp::open2()
{

    qDebug() << "open2";
    QString path2 = QFileDialog::getOpenFileName(this,"open","../","all(*.*);;source(*.cpp *.h);;Text(*.txt);;all(*.*);;pic(*.jpg *.png)");
}
*/
