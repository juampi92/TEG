#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <Qcursor>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile styleSheet("styles.qss");  //path where the file is stored
    if ( !styleSheet.open(QIODevice::ReadOnly) ) {
        qWarning("Unable to load the Styles");
        return;
    }
    qApp->setStyleSheet(styleSheet.readAll());

    this->board = new QGraphicsScene();
    ui->graphicsView->setScene(this->board);
    ui->graphicsView->show();

    this->paises = new QButtonGroup();

    this->board->addItem(new QGraphicsPixmapItem(QPixmap("mapa.jpg")));

    setUpConnections();

    ui->playersTable->setColumnWidth(0,20);
    ui->playersTable->setColumnWidth(1,126);
    ui->playersTable->setColumnWidth(2,20);
    ui->playersTable->setColumnWidth(3,20);

    // MAX: ui->playersTable->setRowCount(6);

    this->game = new TEG::Game(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpConnections(){
   connect(ui->btnPartidaNueva,SIGNAL(triggered()),this,SLOT(callback()));
   connect(this->paises, SIGNAL(buttonClicked(int)), this, SLOT(buttonSelect(int)));
}

void MainWindow::callback(){
    qDebug() << "Apretaste el menu";
}

void MainWindow::addPais(int id, QString nom, int x, int y){
    QPushButton* btn = new QPushButton;
    btn->setGeometry(QRect(x, y, 25, 25));
    btn->setText("0");
    btn->setToolTip(nom);
    btn->setCursor(Qt::PointingHandCursor);
    paises->addButton(btn,id);
    board->addWidget(btn);
}

void MainWindow::setPaisColor(int id, QString color){
    paises->button(id)->setStyleSheet("background-color:"+color+";");
}

void MainWindow::setPaisFichas(int id, int cant){
    paises->button(id)->setText(QString::number(cant));
}

void MainWindow::setPaisEnabled(int id, bool enabled){
    paises->button(id)->setEnabled(enabled);
}

void MainWindow::allEnabled(bool enabled){
    QList<QAbstractButton*> lista = paises->buttons();
    QList<QAbstractButton*>::iterator i;
    for (i = lista.begin(); i != lista.end(); ++i)
        (*i)->setEnabled(enabled);
}

void MainWindow::buttonSelect(int id){
    this->consoleLog("Presionaste el boton ID: " + QString::number(id));
}

void MainWindow::setDados(QList<int> atac, QList<int> def){
    QString out = "Ataque: ";

    QList<int>::iterator i;
    for (i = atac.begin(); i != atac.end(); ++i){
        out.append(QString::number(*i));
        out.append(", ");
    }
    out.append(" Defensa: ");
    for (i = def.begin(); i != def.end(); ++i){
        out.append(QString::number(*i));
        out.append(", ");
    }
    this->consoleLog(out);
}

void MainWindow::consoleLog(QString msj){
    ui->consoleOut->setText( ui->consoleOut->text() + msj + "\n" );
    qDebug() << "MSJ: " <<  msj;
}


