#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <Qcursor>
#include <QInputDialog>
#include <QMessageBox>

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

    // SetUp Board
    this->board = new QGraphicsScene();
    this->board->addItem(new QGraphicsPixmapItem(QPixmap("mapa.jpg")));
    ui->graphicsView->setScene(this->board);
    ui->graphicsView->show();

    this->paises = new QButtonGroup();


    // SetUp Tables
        // Players
    ui->playersTable->setColumnWidth(0,20);
    ui->playersTable->setColumnWidth(1,126);
    ui->playersTable->setColumnWidth(2,35);
    ui->playersTable->setColumnWidth(3,5);

        // PlayerInfo
    ui->playerInfo->setColumnWidth(0,140);
    ui->playerInfo->setColumnWidth(1,50);

    QPushButton * btn = new QPushButton("Ver");
    btn->setMaximumWidth(45);
    ui->playerInfo->setCellWidget(3,1,btn);

    ui->playerInfo->setDisabled(true);






    setUpConnections();

    this->pcIco = new QIcon("pc.png");

    this->game = new TEG::Game(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPais(int id, QString nom, int x, int y){
    QPushButton* btn = new QPushButton;
    btn->setGeometry(QRect(x, y, 25, 25));
    btn->setText("0");
    btn->setToolTip(nom);
    btn->setCursor(Qt::PointingHandCursor);
    btn->setProperty("clase","pais");
    paises->addButton(btn,id);
    board->addWidget(btn);
}

void MainWindow::setPaisColor(int id, QString color){
    paises->button(id)->setStyleSheet("background-color:"+color+";");
}

void MainWindow::setPaisFichas(int id, int cant){
    paises->button(id)->setText(QString::number(cant));
}

void MainWindow::setPaisesFichas(QList<int> *paises, int cant){
    for ( QList<int>::iterator i = paises->begin() ; i != paises->end() ; i++ )
        this->setPaisFichas((*i),cant);
}
void MainWindow::setPaisEnabled(QAbstractButton * btn, bool enabled){
    btn->setEnabled(enabled);
    QString color;
    if ( !enabled )
        color = "grey";
    else
        color = "white";
    btn->setStyleSheet("color:"+color+";background-color:"+this->game->getPaisColor(this->paises->id(btn))+";");
        // Hay que volver a setear el color, porque lo pierde
}

void MainWindow::setPaisEnabled(int id, bool enabled){
    this->setPaisEnabled(paises->button(id),enabled);
}

void MainWindow::setPaisesEnabled(QList<int> *paises, bool enabled){
    for ( QList<int>::iterator i = paises->begin() ; i != paises->end() ; i++ )
        this->setPaisEnabled((*i),enabled);
}

void MainWindow::allEnabled(bool enabled){
    int cont = 0;
    QList<QAbstractButton*> lista = paises->buttons();
    QList<QAbstractButton*>::iterator i;
    for (i = lista.begin(); i != lista.end(); i++){
        cont++;
        this->setPaisEnabled((*i),enabled);
    }
}

void MainWindow::setPaisSelected(int id, bool selected){
    QAbstractButton * btn = paises->button(id);
    QString border = "";
    if ( selected )
        border = "yellow";
    else
        border = "black";
    btn->setStyleSheet("border-color:"+border+";color:white;background-color:"+this->game->getPaisColor(id)+";");
    btn->setEnabled(true);
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

void MainWindow::addPlayer(QString nom, QString color, int IA, int id){
    this->consoleLog("Jugador creado: " + nom + ". Color: "+color +". IA:"+QString::number(IA));

    QTableWidgetItem *colColor = new QTableWidgetItem();
    colColor->setBackgroundColor(QColor(color));

    ui->playersTable->setItem(id,0,colColor);
    ui->playersTable->setItem(id,1,new QTableWidgetItem(nom));
    if ( IA > 0 ) ui->playersTable->setItem(id,2,new QTableWidgetItem(*this->pcIco,QString::number(IA)));
    ui->playersTable->setItem(id,3,new QTableWidgetItem());
}

void MainWindow::setTurno(int id, int cant){
    QString color;
    for ( int i = 0 ; i < cant ; i++  ) {
        if ( i == id ) color = "green";
        else color = "white";
        ui->playersTable->item(i,3)->setBackgroundColor(QColor(color));
    }
}

void MainWindow::setPlayerInfo(QString nom, int paises, int ej, int ej_rest){
    this->ui->playerCurrent->setText(nom);
    this->ui->playerInfo->setItem(0,1,new QTableWidgetItem(QString::number(paises)));
    this->ui->playerInfo->setItem(1,1,new QTableWidgetItem(QString::number(ej)));
    this->ui->playerInfo->setItem(2,1,new QTableWidgetItem(QString::number(ej_rest)));
    this->ui->playerInfo->setEnabled(true);
}

QStringList MainWindow::getColores(){
    QStringList colores;
    colores << tr("red") << tr("black") << tr("blue") << tr("green") << tr("yellow") << tr("purple");
    return this->game->getColores(colores);
}

// --------------------------------------
//          Slots:
// --------------------------------------

void MainWindow::setUpConnections(){
   // Menu connect
   connect(ui->btnNewPlayer,SIGNAL(triggered()),this,SLOT(popupCreatePlayer()));
   connect(ui->btnIniciarPartida,SIGNAL(triggered()),this,SLOT(start()));

   // Botones
   connect(ui->playerInfo->cellWidget(3,1), SIGNAL(clicked()),this,SLOT(verObjetivo()));

   // Paises
   connect(this->paises, SIGNAL(buttonClicked(int)), this, SLOT(buttonSelect(int)));
}

void MainWindow::buttonSelect(int id){
    this->consoleLog("Presionaste el boton ID: " + QString::number(id));
    this->game->pressed(id);
}

void MainWindow::verObjetivo(){
    QMessageBox::information(this, tr("Objetivo"),tr("Conquistar bla bla bla"));
}

void MainWindow::popupCreatePlayer(){

    if ( this->game->getCantPlayers() >= 6 ){
        QMessageBox::information(this, tr("Error!"),tr("El máximo de 6 jugadores ya fue alcanzado"));
        return;
    }

    bool ok; int IA;
    QString nom,color;

    // Crear Jugador: Nombre
    nom = QInputDialog::getText(this, tr("Nuevo Jugador"), tr("Nombre:"), QLineEdit::Normal,
                        "Jugador" + QString::number(this->game->getCantPlayers()), &ok);

    // Errores
    if (!ok) return;
    if ( nom.isEmpty() ) {
        QMessageBox::information(this, tr("Error!"),tr("El nombre esta vacio"));
        return;
    }
    if ( this->game->existsPlayerName(nom) ){
        QMessageBox::information(this, tr("Error!"),tr("Ese nombre ya esta en uso"));
        return;
    }

    // Crear Jugador: Color
    color = QInputDialog::getItem(this, tr("Nuevo Jugador"), tr("Color:"), this->getColores(), 0, false, &ok);

    // Errores
    if (!ok || color.isEmpty())
        return;

    // Crear Jugador: IA
    IA = QInputDialog::getInt(this,tr("Nuevo Jugador"),tr("Inteligencia Artificial. (cancelar si no se desea)"),1,1,5,1,&ok);
    if ( !ok ) IA = 0;

    this->game->addPlayer(nom,color,IA);
}

void MainWindow::start(){
    if ( this->game->getCantPlayers() < 2 ){
        QMessageBox::information(this, tr("Error!"),tr("Se necesita un mínimo de 3 jugadores"));
        return;
    }

    this->game->start();
}
