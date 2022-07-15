#include "reservasion_edit.h"
#include "ui_reservasion_edit.h"

reservasion_edit::reservasion_edit(QString logid, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservasion_edit)
{
    ui->setupUi(this);
    log_id=logid;

    reserList();
    carList();
}

reservasion_edit::~reservasion_edit()
{
    delete ui;
}

void reservasion_edit::reserList() //  예약확인2
{
    query="SELECT * FROM reservation where id='" + log_id.toStdString() + "'";

    qDebug() << QString::fromStdString(query); //내용확인

    sql.exec(QString::fromStdString(query));
    sql.first();
    ui-> reser_num-> setText(sql.value(0).toString());
    ui-> car_name-> setText(sql.value(2).toString());
    ui-> car_type-> setText(sql.value(3).toString());
    ui-> car_fuel-> setText(sql.value(4).toString());
    ui-> car_pay -> setText(sql.value(5).toString());
    ui-> car_total-> setText(sql.value(6).toString());
    QString rser_date= sql.value(7).toString()+".0";
    QString rturn_date= sql.value(8).toString()+".0";
    QString form = "yyyy-MM-dd HH:mm:ss.z";
    QDateTime dt = QDateTime::fromString(rser_date, form);
    QDateTime dt2 = QDateTime::fromString(rturn_date, form);
    ui ->reser_date ->setDateTime(dt);
    ui ->return_date ->setDateTime(dt2);

}

void reservasion_edit::carList() //차량 내역
{
    ui->car_list->clear();
    query="SELECT carname, type, fuel, charge FROM rentacar";

    sql.exec(QString::fromStdString(query));
    record = sql.record();

    ui->car_list->setRowCount(sql.size());
    ui->car_list->setHorizontalHeaderItem(0, new QTableWidgetItem("차명"));
    ui->car_list->setHorizontalHeaderItem(1, new QTableWidgetItem("차종"));
    ui->car_list->setHorizontalHeaderItem(2, new QTableWidgetItem("연료"));
    ui->car_list->setHorizontalHeaderItem(3, new QTableWidgetItem("요금"));

       int i=0;
       while(sql.next())
       {
           ui->car_list->setItem(i,0,new QTableWidgetItem(sql.value("carname").toString()));
           ui->car_list->setItem(i,1,new QTableWidgetItem(sql.value("type").toString()));
           ui->car_list->setItem(i,2,new QTableWidgetItem(sql.value("fuel").toString()));
           ui->car_list->setItem(i++,3,new QTableWidgetItem(sql.value("charge").toString()));
       }
}

void reservasion_edit::on_reser_clicked() //예약버튼
{

}

void reservasion_edit::on_back_clicked() //뒤로
{    this ->close();}
