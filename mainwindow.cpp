#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <Qcursor>
#include <QInputDialog>
#include <QMessageBox>
#include <QThread>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "utiles.h"

MainWindow::MainWindow(QGraphicsView *pres) :
    QMainWindow(0),
    ui(new Ui::MainWindow)
{
    qDebug() << "Cargado!";

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


    // Dados:
    this->img_dados = new QImage("dados.png");
    for ( int i = 0 ; i < 6 ; i++ ) {
        QPixmap *tmp_img = new QPixmap();
        tmp_img->convertFromImage(this->img_dados->copy(i*42,0,42,42));
        this->arr_dados[i] = tmp_img;
    }
    ui->dados1->setScene(new QGraphicsScene());
    ui->dados1->show();
    ui->dados2->setScene(new QGraphicsScene());
    ui->dados2->show();
    ui->dadosProgress->setVisible(false);

    this->animacion.timer = new QTimer(this);
    this->animacion.loops = 5;

    setUpConnections();

    this->img_pc = new QIcon("pc.png");

    this->game = new TEG::Game(this);

    this->allEnabled(false);

    // Para que se note el cartel! se hace sleep 3
    QThread::sleep(1);
    pres->close();
    this->show();
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
        if ( !enabled ) color = "grey";
        else color = "white";
    QString owner = "";
        if ( this->game->hasStarted() ) owner = "background-color:"+this->game->getPaisColor(this->paises->id(btn))+";";

    btn->setStyleSheet("color:"+color+";"+owner);
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

void MainWindow::setDados(QList<int> atac, QList<int> def , bool animacion){
    if ( animacion ) {
        this->animacion.loop = this->animacion.loops;
        this->animacion.atac = atac;
        this->animacion.def = def;
        this->ui->dadosProgress->setVisible(true);
        this->ui->dadosProgress->setValue(0);

        this->dadosUpdate();
        this->animacion.timer->start(350);
    } else {
        this->drawDados(atac,def);
    }

    if ( this->animacion.loop > 0 ){
        float op = this->animacion.loops - this->animacion.loop;
        op = ( op / this->animacion.loops) * 100;
        this->ui->dadosProgress->setValue(op);
        this->animacion.loop--;
    } else {
        this->animacion.timer->stop();
        this->ui->dadosProgress->setValue(100);
        this->drawDados(this->animacion.atac,this->animacion.def);
        this->ui->dadosProgress->setVisible(false);
        this->ui->dadosProgress->setValue(0);

        // Animacion finalizada! Activar lo que sea necesario!
        this->game->ronda->turno->endDadosAnimacion();
    }
}

void MainWindow::drawDados(QList<int> atac, QList<int> def){

    //qDebug() << "Digujar dados! " << atac << " - " << def;

    QGraphicsScene *scene = ui->dados1->scene();
    QList<int>::iterator i;
    int it = 0;

    this->vaciarDados(scene);
    for (i = atac.begin(); i != atac.end(); i++){
        this->agregarDado(scene,(*i),it);
        it++;
    }

    scene = ui->dados2->scene();
    it = 0;

    this->vaciarDados(scene);
    for (i = def.begin(); i != def.end(); i++){
        this->agregarDado(scene,(*i),it);
        it++;
    }
}


void MainWindow::agregarDado( QGraphicsScene * widget, int dado , int pos ){
    QGraphicsPixmapItem *itm = new QGraphicsPixmapItem(*this->arr_dados[dado-1]);
    itm->setX(pos * 42);
    widget->addItem(itm);
}

void MainWindow::vaciarDados(){
    this->vaciarDados(ui->dados1->scene());
    this->vaciarDados(ui->dados2->scene());
}
void MainWindow::vaciarDados( QGraphicsScene * widget ){ // private
    widget->clear();
}

void MainWindow::consoleLog(QString msj){
    ui->consoleOut->setText( ui->consoleOut->text() + msj + "\n" );
    qDebug() << "MSJ: " <<  msj;
}

void MainWindow::setRoundType(int type){
    QString msj;
    switch(type){
        case 0: msj = "Ronda de Fichas"; break;
        case 1: msj = "Ronda de Ataques"; break;
        default: msj = "Esperando partida"; break;
    }
    ui->stageLabel->setText(msj);
}

void MainWindow::addPlayer(QString nom, QString color, int IA, int id){
    this->consoleLog("Jugador creado: " + nom + ". Color: "+color +". IA:"+QString::number(IA));

    QTableWidgetItem *colColor = new QTableWidgetItem();
    colColor->setBackgroundColor(QColor(color));

    ui->playersTable->setItem(id,0,colColor);
    ui->playersTable->setItem(id,1,new QTableWidgetItem(nom));
    if ( IA > 0 ) ui->playersTable->setItem(id,2,new QTableWidgetItem(*this->img_pc,QString::number(IA)));
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

void MainWindow::nextButton(QString txt){
    if ( txt == "")
        ui->nextButton->setEnabled(false);
    else {
        ui->nextButton->setEnabled(true);
        ui->nextButton->setText(txt);
    }
}

void MainWindow::setAttackButton(bool enabled,bool attack){
    if ( attack ) ui->btnAttack->setText("Atacar!");
    else ui->btnAttack->setText("Reagrupar");
    this->setAttackButton(enabled);
}

void MainWindow::setAttackButton(bool enabled){
    ui->btnAttack->setEnabled(enabled);
}


void MainWindow::setAtaque(QString atac, QString def){
    ui->atackFrame->setTitle(atac + " vs " + def);
}
void MainWindow::clearAtaque(){
    ui->atackFrame->setTitle("");
}

void MainWindow::setPlayerInfo(QString nom, int paises, int ej, int ej_rest){
    if ( nom != "" ) this->ui->playerCurrent->setText(nom);
    if ( paises > -1 ) this->ui->playerInfo->setItem(0,1,new QTableWidgetItem(QString::number(paises)));
    if ( ej > -1 ) this->ui->playerInfo->setItem(1,1,new QTableWidgetItem(QString::number(ej)));
    if ( ej_rest > -1 ) this->ui->playerInfo->setItem(2,1,new QTableWidgetItem(QString::number(ej_rest)));
    this->ui->playerInfo->setEnabled(true);
}

QStringList MainWindow::getColores(){
    QStringList colores;
    colores << tr("red") << tr("black") << tr("blue") << tr("green") << tr("yellow") << tr("purple");
    return this->game->getColores(colores);
}

int MainWindow::popUpFichas(int type, int min, int max){
    int val;
    bool ok;
    QString tipo; if ( type == 1 ) tipo = "Pais conquistado!"; else tipo = "Reagrupar";

    val = QInputDialog::getInt(this,tipo,"Fichas a pasar:",max,min,max,1,&ok);

    if ( !ok && type == 1 ) val = min; // Paso el mínimo posible
    else if ( !ok && type == 2 ) val = 0; // No paso ninguna ficha.

    return val;
}

void MainWindow::setWinner(QString nom, QString color, QString obj){
    QMessageBox::information(this, tr("Fin del Juego!"),"El jugador " + nom + " ganó la partida! \n Objetivo: "+obj);
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
   connect(ui->nextButton, SIGNAL(clicked()),this,SLOT(buttonNext()));
   connect(ui->btnAttack, SIGNAL(clicked()),this,SLOT(btnAttack()));

   // Animacion Timer
   connect(this->animacion.timer, SIGNAL(timeout()), this, SLOT(dadosUpdate()));

   // Paises
   connect(this->paises, SIGNAL(buttonClicked(int)), this, SLOT(buttonSelect(int)));
}

void MainWindow::buttonSelect(int id){
    //this->consoleLog("Presionaste el boton ID: " + QString::number(id));
    this->game->pressed(id);
}

void MainWindow::buttonNext(){
    this->game->ronda->btnNext();
}

void MainWindow::btnAttack(){
    this->game->ronda->turno->btnAttack();
}

void MainWindow::verObjetivo(){
    QMessageBox::information(this, tr("Objetivo"),game->ronda->showObjetivo());
}

void MainWindow::dadosUpdate(){
    this->setDados(TEG::Utiles::getRandomList(this->animacion.atac.size(),6),TEG::Utiles::getRandomList(this->animacion.def.size(),6),false);
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
    IA = QInputDialog::getInt(this,tr("Nuevo Jugador"),tr("Inteligencia Artificial. (cancelar si no se desea)"),1,1,1,1,&ok);
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
