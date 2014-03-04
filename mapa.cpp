#include "mapa.h"

TEG::Mapa::Mapa(TEG::Game *game){
    this->game = game;

    this->continentes[0] = new TEG::Continente("America del Norte",0);
    this->continentes[1] = new TEG::Continente("America del Sur",1);
    this->continentes[2] = new TEG::Continente("Europa",2);
    this->continentes[3] = new TEG::Continente("Asia",3);
    this->continentes[4] = new TEG::Continente("Africa",4);
    this->continentes[5] = new TEG::Continente("Oceania",5);

    this->paises[0] = new TEG::Pais(0,"Alaska",0);				this->game->gui->addPais(0,"Alaska",8,209);
    this->paises[1] = new TEG::Pais(1,"Yukon",0);				this->game->gui->addPais(1,"Yukon",58,178);
    this->paises[2] = new TEG::Pais(2,"Canada",0);				this->game->gui->addPais(2,"Canada",109,108);
    this->paises[3] = new TEG::Pais(3,"Oregon",0);				this->game->gui->addPais(3,"Oregon",42,256);
    this->paises[4] = new TEG::Pais(4,"California",0);			this->game->gui->addPais(4,"California",90,272);
    this->paises[5] = new TEG::Pais(5,"Mexico",0);				this->game->gui->addPais(5,"Mexico",142,278);
    this->paises[6] = new TEG::Pais(6,"Nueva York",0);			this->game->gui->addPais(6,"Nueva York",180,220);
    this->paises[7] = new TEG::Pais(7,"Terranova",0);			this->game->gui->addPais(7,"Terranova",205,198);
    this->paises[8] = new TEG::Pais(8,"Labrador",0);			this->game->gui->addPais(8,"Labrador",195,145);
    this->paises[9] = new TEG::Pais(9,"Groenlandia",0);			this->game->gui->addPais(9,"Groenlandia",259,139);

    this->paises[10] = new TEG::Pais(10,"Colombia",1);			this->game->gui->addPais(10,"Colombia",232,310);
    this->paises[11] = new TEG::Pais(11,"Peru",1);				this->game->gui->addPais(11,"Peru",236,348);
    this->paises[12] = new TEG::Pais(12,"Brasil",1);			this->game->gui->addPais(12,"Brasil",312,361);
    this->paises[13] = new TEG::Pais(13,"Chile",1);				this->game->gui->addPais(13,"Chile",225,427);
    this->paises[14] = new TEG::Pais(14,"Argentina",1);			this->game->gui->addPais(14,"Argentina",257,436);
    this->paises[15] = new TEG::Pais(15,"Uruguay",1);			this->game->gui->addPais(15,"Uruguay",303,411);

    this->paises[16] = new TEG::Pais(16,"Islandia",2);			this->game->gui->addPais(16,"Islandia",341,229);
    this->paises[17] = new TEG::Pais(17,"Suecia",2);			this->game->gui->addPais(17,"Suecia",469,132);
    this->paises[18] = new TEG::Pais(18,"Rusia",2);				this->game->gui->addPais(18,"Rusia",543,161);
    this->paises[19] = new TEG::Pais(19,"Gran Bretaña",2);		this->game->gui->addPais(19,"Gran Bretaña",427,201);
    this->paises[20] = new TEG::Pais(20,"Polonia",2);			this->game->gui->addPais(20,"Polonia",550,259);
    this->paises[21] = new TEG::Pais(21,"Alemania",2);			this->game->gui->addPais(21,"Alemania",502,241);
    this->paises[22] = new TEG::Pais(22,"Francia",2);			this->game->gui->addPais(22,"Francia",458,263);
    this->paises[23] = new TEG::Pais(23,"España",2);			this->game->gui->addPais(23,"España",403,302);
    this->paises[24] = new TEG::Pais(24,"Italia",2);			this->game->gui->addPais(24,"Italia",500,300);

    this->paises[25] = new TEG::Pais(25,"Sahara",3);			this->game->gui->addPais(25,"Sahara",468,375);
    this->paises[26] = new TEG::Pais(26,"Zaire",3);				this->game->gui->addPais(26,"Zaire",516,434);
    this->paises[27] = new TEG::Pais(27,"Etiopia",3);			this->game->gui->addPais(27,"Etiopia",586,408);
    this->paises[28] = new TEG::Pais(28,"Egipto",3);			this->game->gui->addPais(28,"Egipto",606,380);
    this->paises[29] = new TEG::Pais(29,"Sudafrica",3);			this->game->gui->addPais(29,"Sudafrica",566,461);
    this->paises[30] = new TEG::Pais(30,"Madagascar",3);		this->game->gui->addPais(30,"Madagascar",645,442);

    this->paises[31] = new TEG::Pais(31,"Aral",4);				this->game->gui->addPais(31,"Aral",575,122);
    this->paises[32] = new TEG::Pais(32,"Tartaria",4);			this->game->gui->addPais(32,"Tartaria",596,89);
    this->paises[33] = new TEG::Pais(33,"Taimir",4);			this->game->gui->addPais(33,"Taimir",636,97);
    this->paises[34] = new TEG::Pais(34,"Siberia",4);			this->game->gui->addPais(34,"Siberia",656,126);
    this->paises[35] = new TEG::Pais(35,"Kamchatka",4);			this->game->gui->addPais(35,"Kamchatka",688,97);
    this->paises[36] = new TEG::Pais(36,"Japon",4);				this->game->gui->addPais(36,"Japon",756,150);
    this->paises[37] = new TEG::Pais(37,"Iran",4);				this->game->gui->addPais(37,"Iran",609,196);
    this->paises[38] = new TEG::Pais(38,"Mongolia",4);			this->game->gui->addPais(38,"Mongolia",631,165);
    this->paises[39] = new TEG::Pais(39,"Gobi",4);				this->game->gui->addPais(39,"Gobi",658,228);
    this->paises[40] = new TEG::Pais(40,"China",4);				this->game->gui->addPais(40,"China",713,228);
    this->paises[41] = new TEG::Pais(41,"Turquia",4);			this->game->gui->addPais(41,"Turquia",607,256);
    this->paises[42] = new TEG::Pais(42,"India",4);				this->game->gui->addPais(42,"India",685,314);
    this->paises[43] = new TEG::Pais(43,"Malasia",4);			this->game->gui->addPais(43,"Malasia",752,273);
    this->paises[44] = new TEG::Pais(44,"Israel",4);			this->game->gui->addPais(44,"Israel",591,318);
    this->paises[45] = new TEG::Pais(45,"Arabia",4);			this->game->gui->addPais(45,"Arabia",632,334);

    this->paises[46] = new TEG::Pais(46,"Sumatra",5);			this->game->gui->addPais(46,"Sumatra",665,374);
    this->paises[47] = new TEG::Pais(47,"Borneo",5);			this->game->gui->addPais(47,"Borneo",722,335);
    this->paises[48] = new TEG::Pais(48,"Java",5);				this->game->gui->addPais(48,"Java",769,309);
    this->paises[49] = new TEG::Pais(49,"Australia",5);			this->game->gui->addPais(49,"Australia",750,397);

    this->relaciones[0] = this->getPaisesList(1,3,35);
    this->relaciones[1] = this->getPaisesList(0,2,3);
    this->relaciones[2] = this->getPaisesList(1,3,6,7);
    this->relaciones[3] = this->getPaisesList(0,1,2,6,4);
    this->relaciones[4] = this->getPaisesList(3,6,5);
    this->relaciones[5] = this->getPaisesList(4,10);
    this->relaciones[6] = this->getPaisesList(2,3,4,7,9);
    this->relaciones[7] = this->getPaisesList(2,6,8,9);
    this->relaciones[8] = this->getPaisesList(7,9);
    this->relaciones[9] = this->getPaisesList(8,6,16);

    this->relaciones[10] = this->getPaisesList(11,12,5);
    this->relaciones[11] = this->getPaisesList(13,14,12,10);
    this->relaciones[12] = this->getPaisesList(10,11,14,15,25);
    this->relaciones[13] = this->getPaisesList(11,14,49);
    this->relaciones[14] = this->getPaisesList(13,11,12,15);
    this->relaciones[15] = this->getPaisesList(14,12);

    this->relaciones[16] = this->getPaisesList(9,19,17);
    this->relaciones[17] = this->getPaisesList(16,18);
    this->relaciones[18] = this->getPaisesList(17,20,31,37,41);
    this->relaciones[19] = this->getPaisesList(16,23,21);
    this->relaciones[20] = this->getPaisesList(21,18,41,28);
    this->relaciones[21] = this->getPaisesList(19,22,24,20);
    this->relaciones[22] = this->getPaisesList(21,24,23);
    this->relaciones[23] = this->getPaisesList(19,25,22);
    this->relaciones[24] = this->getPaisesList(22,21);

    this->relaciones[25] = this->getPaisesList(26,28,27,12,23);
    this->relaciones[26] = this->getPaisesList(25,27,29,30);
    this->relaciones[27] = this->getPaisesList(28,25,26,29);
    this->relaciones[28] = this->getPaisesList(25,27,30,20,41,44);
    this->relaciones[29] = this->getPaisesList(26,27);
    this->relaciones[30] = this->getPaisesList(26,28);

    this->relaciones[31] = this->getPaisesList(32,34,38,37,18);
    this->relaciones[32] = this->getPaisesList(31,34,33);
    this->relaciones[33] = this->getPaisesList(32,34);
    this->relaciones[34] = this->getPaisesList(31,32,33,35,40,38);
    this->relaciones[35] = this->getPaisesList(34,40,36,0);
    this->relaciones[36] = this->getPaisesList(35,40);
    this->relaciones[37] = this->getPaisesList(31,38,39,40,41,42,18); // Hago la suposicion de que Iran(37) y Siberia(34) NO son limitrofes
    this->relaciones[38] = this->getPaisesList(31,34,40,39,37);
    this->relaciones[39] = this->getPaisesList(37,38,40);
    this->relaciones[40] = this->getPaisesList(36,35,34,38,39,37,42,43);
    this->relaciones[41] = this->getPaisesList(37,44,45,28,20,18);
    this->relaciones[42] = this->getPaisesList(37,40,43,46);
    this->relaciones[43] = this->getPaisesList(42,40,47);
    this->relaciones[44] = this->getPaisesList(41,45,28);
    this->relaciones[45] = this->getPaisesList(41,44);

    this->relaciones[46] = this->getPaisesList(49,42);
    this->relaciones[47] = this->getPaisesList(49,43);
    this->relaciones[48] = this->getPaisesList(49);
    this->relaciones[49] = this->getPaisesList(46,47,48,13);
}

TEG::Mapa::~Mapa(){
}

QList<TEG::Pais*> * TEG::Mapa::getLimitrofes(int id){
    return this->relaciones[id];
}

QList<TEG::Pais*>* TEG::Mapa::getPaisesList(int a,int b,int c,int d,int e,int f,int g,int h){
    QList<TEG::Pais*> * li;
    li = new QList<TEG::Pais*>();
    if(a > -1)
        li->append(this->paises[a]);
    if(b > -1)
        li->append(this->paises[b]);
    if(c > -1)
        li->append(this->paises[c]);
    if(d > -1)
        li->append(this->paises[d]);
    if(e > -1)
        li->append(this->paises[e]);
    if(f > -1)
        li->append(this->paises[f]);
    if(g > -1)
        li->append(this->paises[g]);
    if(h > -1)
        li->append(this->paises[h]);

return li;
}
