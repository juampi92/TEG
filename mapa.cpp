#include "mapa.h"

TEG::Mapa::Mapa(TEG::Game *game){
    this->game = game;
    this->continentes = new TEG::Continente*[6];
    this->paises = new TEG::Pais*[50];
    this->relaciones = new QList<TEG::Pais*>*[50];

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
    this->paises[22] = new TEG::Pais(22,"Francia",2);			this->game->gui->addPais(22,"Francia",258,263);
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
}

TEG::Mapa::~Mapa(){
}
