#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include"vols.h"
#include"passager.h"
#include"employer.h"
class compagnie
{	
	protected:
	string nom;
	string adress;
	string email;
	string site_web;
	double numero_d_telephone;
	vector<employer*> liste_des_employer;
	vector<vols *> liste_d_vols;
	vector<avion*> liste_d_avion;
public:
	
	compagnie(string a="",string b="",string c="",string d="",double e=0);
	int existe_employer(vector<employer*>,long);
	friend ostream& operator<< (ostream & o,compagnie & c);
	friend istream& operator>> (istream & in,compagnie & c);
	void set_avion(avion* a){liste_d_avion.push_back(a);}
	int exist_avion(vector<avion*> t,string x);
	void supprission_compagnie(vector<compagnie *>);
	void afficher_compagnie();
	int	existe_avion(vector<avion*> t,string);
	int disponible_employer(vols v)
	{int s=0;
	for(unsigned int i=0 ;i<v.get_liste_d_employer().size();i++)
		if(v.get_liste_d_employer()[i]->get_etat(v.get_date().get_jour(),v.get_date().get_mois())=="disp")
			s++;
	return(s);

	}
	string get_nom_compagnie()
	{return(nom);}
	void set_nom_compagnie(string a)
	{nom=a;}
	void supprimer_passager(passager* p)
	{
		for(unsigned int i=0;i<liste_d_vols.size();i++)
			liste_d_vols[i]->supprimer_passager(p);
	}
	void supprimer_employer(employer *e)
	{
	for(unsigned int i=0;i<liste_d_vols.size();i++)
			liste_d_vols[i]->supprimer_employer(e);
	}
	void erase(passager* p,int i){liste_d_vols[i]->erase(p);}
	bool exist_employer_disponible(vector<employer*>);
	bool exist_avion_disponible(vector<avion*>);
	int rechercher_unicite_nom(vector<compagnie *> C,string n);
	void remplissage_compagnie(vector<compagnie*>,vector<employer*>,vector<avion*>,vector<passager*>);
	void modifier_compagnie(vector<compagnie *>,vector<employer *>,vector<avion*>,vector<passager*>);
	bool disponible_passager(passager*,int);
	int rechercher_exist(int);
	vector<vols*> get_liste_vole(){return(liste_d_vols);}
	vector<avion*> get_liste_avion()
	{return(liste_d_avion);}

	~compagnie(void);
};
