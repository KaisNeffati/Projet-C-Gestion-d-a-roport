#pragma once
#include"date.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class personne
{
protected:
	string nom;
	string prenom;
	string email;
	string adress;
	long carte_d_identitee;
	long carte_bancaire;
	date date_de_naissance;

public:
	personne(int g=0,int h=0,int i=0,string a="",string b="",string c="",string d="",long e=0,long f=0);
	virtual void afficher();

	long get_carte_id(){return(carte_d_identitee);};
	~personne(void);
};


