#include "widget.h"
#include "ui_widget.h"
#include <string>
#include <QTimerEvent>

#include <QJsonObject>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonArray>
#include <QStringList>
#include <QHeaderView>
#include <QDebug>
#include <QFileDialog>
#include <QImage>




#include "face.h"
aip::Face *cli;

Json::Value result;
const std::string app_id = "";
const std::string api_key = "";
const std::string secret_key = "";


std::string file_content;


Json::Value face_data;
Json::Value image_desp_1;
Json::Value image_desp_2;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    cli = new aip::Face(app_id,api_key,secret_key);

    //this->setMaximumSize(1400,600);
    this->setMinimumSize(1400,600);

    camera = new QCamera();
    camerafind = new QCameraViewfinder();
    imagecapture = new QCameraImageCapture(camera);

    qlabel = new QLabel();
    qlabel->setScaledContents(true);
    qlabel->setMinimumSize(500,300);
    //qlabel->setMaximumSize(500,300);


    qface = new QLabel();
    qface->setScaledContents(true);
    qface->setMinimumSize(500,100);
    //qface->setMaximumSize(500,100);


    table = new QTableWidget();
    table->setMinimumSize(500,200);
    //table->setMaximumSize(500,200);
    table->setColumnCount(4);
    table->setRowCount(0);
    QStringList header;
    header << "性别" << "年龄" << "颜值" << "情绪";
    table->setHorizontalHeaderLabels(header);
    table->horizontalHeader()->setFixedHeight(25); //设置表头的高度为25
    table->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
    table->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    table->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头的背景色
    table->setStyleSheet("selection-background-color:rgb(34, 170, 75);"); //设置选中行的背景色
    table->setFrameShape(QFrame::NoFrame);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    st = new QPushButton();
    st->setText("start");
    connect(st,&QPushButton::clicked,
            [=]()
    {
        timerId = this->startTimer(3000);//毫秒为单位,每隔一秒触发一次定时器
        setWindowTitle("start capture ");
    });

    en = new QPushButton();
    en->setText("stop");
    connect(en,&QPushButton::clicked,
            [=]()
    {
        killTimer(timerId);
        setWindowTitle("stop capture ");
    });

    qlayout = new QHBoxLayout();
    qllayout = new QVBoxLayout();
    qrlayout = new QVBoxLayout();

    qllayout->addWidget(camerafind);
    qllayout->addWidget(st);
    qllayout->addWidget(en);


    qrlayout->addWidget(qlabel);
    qrlayout->addWidget(qface);
    qrlayout->addWidget(table);

    qlayout->addLayout(qllayout);
    qlayout->addLayout(qrlayout);
    qlayout->setStretchFactor(qllayout,2);
    qlayout->setStretchFactor(qrlayout,1);

    imagecapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    camera->setViewfinder(camerafind);
    camera->start();

    ui->tab->setLayout(qlayout);
    //this->setGeometry(100,100,1500,1000);

    /*
    qDebug() << "8";
    w = new facecmp();
    //void (facecmp:: *funsignal)(QString *,QString *,QString *) = &facecmp::mysignal;
    connect(w,SIGNAL(mysignal(QString *,QString *,QString *)),this,SLOT(deal(QString *,QString *,QString *)));
    */

    a = new QPushButton("select1");
    b = new QPushButton("select2");
    layout2 = new QHBoxLayout();
    layout3 = new QHBoxLayout();
    aa = new QLabel("please select");
    aa->setFrameShape(QFrame::Box);
    aa->resize(75,50);
    aa->setStyleSheet("border-width:1px;border-style:solid;border-color:rgb(255,170,0);");
    bb = new QLabel("please select");
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

    resul = new QLabel();
    resul->setText("result display");
    resul->setAlignment(Qt::AlignCenter);

    cmp = new QPushButton("compare");
    cmp->setStyleSheet("margin: 0 400 0 400");

    status = new QStatusBar();

    connect(a,&QPushButton::clicked,this,&Widget::open1);
    connect(b,&QPushButton::clicked,this,&Widget::open2);
    connect(cmp,&QPushButton::clicked,
            [=]()
    {
        if(pathl == nullptr || pathl->isEmpty() || pathr->isEmpty())
            resul->setText("请填充要对比的两张图片!");
        else
        {
            aip::get_file_content(pathl->toStdString().c_str(), &file_content);
            image_desp_1["image"] = aip::base64_encode(file_content.c_str(), (int) file_content.size());
            image_desp_1["image_type"] = "BASE64";

            aip::get_file_content(pathr->toStdString().c_str(), &file_content);
            image_desp_2["image"] = aip::base64_encode(file_content.c_str(), (int) file_content.size());
            image_desp_2["image_type"] = "BASE64";

            face_data[0] = image_desp_1;
            face_data[1] = image_desp_2;

            result = cli->match(face_data);
            std::string str = result.toStyledString();
            QString qstr = QString::fromStdString(str);
            QString r = readjson2(qstr);
            resul->setText(r);
        }
    });    
    qlayout4 = new QVBoxLayout(ui->tab_2);
    qlayout4->addLayout(layout2,4);
    qlayout4->addLayout(layout3,1);
    qlayout4->addWidget(cmp,1);
    qlayout4->addWidget(resul,1);
    qlayout4->addWidget(status,1);


}

Widget::~Widget()
{
    delete ui;
}
void Widget::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == this->timerId)
    {
        imagecapture->capture();
        connect(imagecapture,&QCameraImageCapture::imageCaptured,
                [=](int id,QImage ima)
        {
            //std::to_string(id)
            std::string path = "../buf.jpg";
            ima.save(path.c_str(),"JPG",100);
            qlabel->setPixmap(QPixmap::fromImage(ima));

            aip::get_file_content(path.c_str(), &file_content);

            std::string image = aip::base64_encode(file_content.c_str(),(int)file_content.size());
            std::string image_type = "BASE64";

            // 如果有可选参数
            std::map<std::string, std::string> options;
            options["face_field"] = "face_probability,age,beauty,expression,gender,emotion,race";
            options["max_face_num"] = "2";
            options["face_type"] = "LIVE";
            options["liveness_control"] = "LOW";

            // 带参数调用人脸检测
            result = cli->detect(image, image_type, options);
            std::string str = result.toStyledString();
            QString qstr = QString::fromStdString(str);
            QString rel = readjson(qstr);
            qface->setText(rel);
        });
    }

}

QString Widget::readjson(QString qjson)
{
    QString re;
    QJsonObject ob;
    QJsonParseError json_error;
    QJsonDocument doc = QJsonDocument::fromJson(qjson.toUtf8(),&json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        //have obj
        if(doc.isObject())
        {
            ob = doc.object();
            if(ob.contains("result"))
            {
                QJsonObject ob2 = ob.value("result").toObject();
                if(ob2.isEmpty())
                {
                    re += "未检测到人脸!"; return re;
                }
                if(ob2.contains("face_num"))
                {

                    int facenum = ob2.value("face_num").toInt();
                    table->setRowCount(facenum);
                }
                if(ob2.contains("face_list"))
                {
                    QJsonArray infolist = ob2.value("face_list").toArray();
                    for(int i = 0; i < infolist.size(); i++)
                    {
                        QJsonObject ob3 = infolist.at(i).toObject();
                        if(ob3.contains("age"))
                        {
                            int age = ob3.value("age").toInt();
                            table->setItem(i,1,new QTableWidgetItem(QString::number(age)));
                        }
                        if(ob3.contains("gender"))
                        {
                            QJsonObject ob3_gender = ob3.value("gender").toObject();
                            if(ob3_gender.contains("type"))
                            {
                                if(ob3_gender.value("type").toString() == "male")
                                {
                                    table->setItem(i,0,new QTableWidgetItem("男"));
                                }
                                else
                                {                     
                                    table->setItem(i,0,new QTableWidgetItem("女"));
                                }
                            }
                        }
                        if(ob3.contains("beauty"))
                        {
                            double beauty = ob3.value("beauty").toDouble();
                            table->setItem(i,2,new QTableWidgetItem(QString::number(beauty)));
                        }
                        if(ob3.contains("emotion"))
                        {
                            QJsonObject ob3_emotion = ob3.value("emotion").toObject();
                            if(ob3_emotion.contains("type"))
                            {
                                //if(ob3_emotion.value("type").toString() == "sad");
                                table->setItem(i,3,new QTableWidgetItem(ob3_emotion.value("type").toString()));
                            }
                        }
                    }
                }

            }
        }
    }
    return re;
}
/*
void Widget::deal(QString *p1, QString *p2, QString *r)
{
    qDebug() << "????????";
    r = new QString("1");
}
*/

void Widget::open1()
{
    QImage image;
    QString path1 = QFileDialog::getOpenFileName(this,"open","../","all(*.*);;source(*.cpp *.h);;Text(*.txt);;all(*.*);;pic(*.jpg *.png)");
    pathl = new QString(path1);
    //aa->setText(path1);
    if(path1 != "")
    {
        if(image.load(path1))
        {
            aa->setScaledContents(true);
            aa->setPixmap(QPixmap::fromImage(image).scaled(bb->size(),Qt::KeepAspectRatio));//
        }
    }
}

void Widget::open2()
{
    QImage image2;
    QString path2 = QFileDialog::getOpenFileName(this,"open","../","all(*.*);;source(*.cpp *.h);;Text(*.txt);;all(*.*);;pic(*.jpg *.png)");
    pathr = new QString(path2);
    bb->setText(path2);
    if(path2 != "")
    {
        if(image2.load(path2))
        {
            bb->setScaledContents(true);
            bb->setPixmap(QPixmap::fromImage(image2).scaled(bb->size(),Qt::KeepAspectRatio));//
        }
    }
}

QString Widget::readjson2(QString qjson)
{
    status->showMessage("compare completely",5000);
    QString re;
    QJsonObject ob;
    QJsonParseError json_error;
    QJsonDocument doc = QJsonDocument::fromJson(qjson.toUtf8(),&json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        //have obj
        if(doc.isObject())
        {
            ob = doc.object();
            if(ob.contains("result"))
            {
                QJsonObject ob2 = ob.value("result").toObject();
                if(ob2.isEmpty())
                {
                    re += "未检测到人脸!"; return re;
                }
                if(ob2.contains("score"))
                {
                    double score = ob2.value("score").toDouble();
                    re += "相似度" + QString::number(score,'f',2) + "%";
                }
            }
        }
    }
    return re;
}
