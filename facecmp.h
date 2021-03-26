#ifndef FACECMP_H
#define FACECMP_H

#include <QWidget>
#include <QString>
class facecmp : public QWidget
{
    Q_OBJECT
public:
    explicit facecmp(QWidget *parent = nullptr);

    //void open1();
    //void open2();

signals:
    //void mysignal(QString *path1,QString *path2,QString *result);


public slots:
    //void sendsignal();

private:
    //QString *pathl;
    //QString *pathr;
    //QString *res;

};

#endif // FACECMP_H
