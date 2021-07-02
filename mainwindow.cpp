#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // タイトルバーを消す
    this->setWindowFlags(Qt::CustomizeWindowHint);
    // closeButtonに閉じる機能を実装
    QObject::connect(ui->closeButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    // QTableWidgetの設定
    ui->tableWidget->setColumnWidth(0, 110);
    ui->tableWidget->setColumnWidth(1,  40);
    ui->tableWidget->setColumnWidth(2,  90);
    ui->tableWidget->setColumnWidth(3,  70);
    ui->tableWidget->setColumnWidth(4,  70);
    ui->tableWidget->setColumnWidth(5,  70);
    ui->tableWidget->setColumnWidth(6,  40);
    ui->tableWidget->setColumnWidth(7,  90);
    ui->tableWidget->setColumnWidth(8,  90);
    ui->tableWidget->setColumnWidth(9,  90);
    ui->tableWidget->setColumnWidth(10, 90);
    // QTableWidgetへのItem登録サンプル
    int count = 0;
    QTableWidgetItem *item[10];
    item[0] = new QTableWidgetItem(QString("Cell0").arg(0.1));
    item[1] = new QTableWidgetItem(QString("Cell1").arg(count));
    item[2] = new QTableWidgetItem(QString("Cell2").arg(count));
    item[3] = new QTableWidgetItem(QString("Cell3").arg(count));
    item[4] = new QTableWidgetItem(QString("Cell4").arg(count));
    item[5] = new QTableWidgetItem(QString("Cell5").arg(count));
    item[6] = new QTableWidgetItem(QString("Cell6").arg(count));
    item[7] = new QTableWidgetItem(QString("Cell7").arg(count));
    item[8] = new QTableWidgetItem(QString("Cell8").arg(count));
    item[9] = new QTableWidgetItem(QString("Cell9").arg(count));
    for(int ncol=0;ncol<10;ncol++){ ui->tableWidget->setItem(0, ncol, item[ncol]);}

    // ステータスバー
    QLabel *initStsLabel = new QLabel;
    QLabel *unitNameLabel = new QLabel;
    QLabel *unitStsLabel = new QLabel;
    initStsLabel->setText("初期化：未完了");
    unitNameLabel->setText("ELA05(EAM01)");
    unitStsLabel->setText("装置停止中");
    ui->statusBar->addWidget(initStsLabel);
    ui->statusBar->addWidget(unitNameLabel);
    ui->statusBar->addWidget(unitStsLabel);
    initStsLabel->setGeometry(0, 0, 500, this->height());
    unitNameLabel->setGeometry(500, 0, 300, this->height());
    unitStsLabel->setGeometry(800, 0, 500, this->height());
 //   initStsLabel->setSizePolicy();
}

MainWindow::~MainWindow()
{
    delete ui;
}
