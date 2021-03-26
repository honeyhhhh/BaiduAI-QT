#ifndef WIDGET_H
#define WIDGET_H
#include <string>
#include <QWidget>
#include <QPushButton>
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QTableWidget>
#include <QStatusBar>
#include <QTabWidget>

//#include "facecmp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:

    Widget(QWidget *parent = nullptr);
    ~Widget();

    QString readjson(QString str);
    QString readjson2(QString str);

    void open1();
    void open2();

public slots:
    //void deal(QString *p1,QString *p2,QString *re);

protected:
    void timerEvent(QTimerEvent *e) override;

private:
    Ui::Widget *ui;

    QCamera *camera;
    QCameraViewfinder *camerafind;
    QCameraImageCapture *imagecapture;
    QPushButton *st;
    QPushButton *en;
    QHBoxLayout *qlayout;
    QVBoxLayout *qrlayout;
    QVBoxLayout *qllayout;
    QLabel *qlabel;
    QLabel *qface;
    int timerId;
    QTableWidget *table;

    QTabWidget *page;

    //facecmp *w;
    QPushButton *a;
    QPushButton *b;
    QLabel *aa;
    QLabel *bb;
    QHBoxLayout *layout2;
    QHBoxLayout *layout3;
    QLabel *resul;
    QPushButton *cmp;
    QVBoxLayout *qlayout4;
    QString *pathr;
    QString *pathl;
    QStatusBar *status;

};
#endif // WIDGET_H
