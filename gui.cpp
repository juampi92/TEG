#include "gui.h"
#include <QPushButton>

TEG::GUI::GUI(QGraphicsScene *tablero){
    this->board = tablero;
    this->paises = new TEG::GUIFichas(this);
}

TEG::GUI::~GUI(){

}

void TEG::GUI::callback(){
    qDebug() << "Apretaste el menu";
}

void TEG::GUI::addPais(int id, int x, int y){
    QPushButton* pLabel = new QPushButton;
    pLabel->setGeometry(QRect(x, y, 25, 25));
    //pLabel->setObjectName("red");
    pLabel->setText("0");
    pLabel->setCursor(Qt::PointingHandCursor);
    paises->addButton(pLabel,id);
    board->addWidget(pLabel);
}

void TEG::GUI::setPaisColor(int id, QString color){
    paises->button(id)->setStyleSheet("background-color:"+color+";");
}

void TEG::GUI::setPaisFichas(int id, int cant){
    paises->button(id)->setText(QString::number(cant));
}

void TEG::GUI::setPaisEnabled(int id, bool enabled){
    paises->button(id)->setEnabled(enabled);
}

void TEG::GUI::buttonSelect(int id){
    qDebug() << "Presionaste el boton ID: " << id ;
}

void TEG::GUI::setDados(QList<int> atac, QList<int> def){
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

void TEG::GUI::consoleLog(QString msj){
    qDebug() << msj;
}


