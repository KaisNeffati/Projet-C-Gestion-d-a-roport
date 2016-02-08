#pragma once
#include"temp.h"
#include"date.h"
#include"employer.h"
#include"avion.h"
#include"passager.h"
#include<vector>
#include<string>
class vols
{

protected:
	temp temp_d_arrivee;
	string lieu_depart;
	string lieu_d_arrivee;
	int num_d_vols;
	temp temp_d_depart;
	date date_d_vols;
	avion av;
	vector<employer*> liste_d_employer;
    vector<passager*> liste_d_passager;
	vector<string> liste_des_escales;
	

public:
		
	vols(int d=0,int e=0,int f=0,int g=0,int h=0,int i=0,int j=0,int k=0,string l="",string m="",string n="",string a="",string b="",int c=0);
	int existe_place();
	void afficher_vols_client();
	friend ostream& operator<< (ostream & o,vols & v);
	friend istream& operator>> (istream & in,vols & v);	
	vector<passager*> get_liste_d_passager(){return(liste_d_passager);}
	void set_lieu_d(string a){lieu_depart=a;}
	void set_lieu_a(string a){lieu_d_arrivee=a;}
	void set_num_d_vols(int a){num_d_vols=a;}
	int disponible_passager(vector<passager*> t);
	void set_avion(avion a){av=a;}
	temp get_temp_d(){return(temp_d_depart);}
	temp get_temp_a(){return(temp_d_arrivee);}
	date get_date(){return(date_d_vols);}
	avion get_avion(){return(av);}
	int exist_avion(vector<avion*> t,string nom);
	int get_num_vols(){return(num_d_vols);}
	int existance_num(vector<vols*>,int);
	void supprimer_vols();
	void erase(passager *p)
	{for(unsigned int i=0;i<liste_d_passager.size();i++)
									if(liste_d_passager[i]->get_carte_id()==p->get_carte_id())
											liste_d_passager.erase(liste_d_passager.begin()+i);}
	void supprimer_passager(passager* p)
	{
		for(unsigned int i=0;i<liste_d_passager.size();i++)
			if(liste_d_passager[i]->get_carte_id()==p->get_carte_id())
			liste_d_passager.erase(liste_d_passager.begin()+i);

	}
	void supprimer_employer(employer* e)
	{
		for(unsigned int i=0;i<liste_d_employer.size();i++)
			if(liste_d_employer[i]->get_carte_id()==e->get_carte_id())
			liste_d_employer.erase(liste_d_employer.begin()+i);
	}
	int disponible_employer(vector<employer *> t);
	void modifer_vols(vector<vols*>,vector<employer*>,vector<passager*>);
	vector<string> get_ls_escal(){return(liste_des_escales);}
	vector<employer*> get_liste_d_employer(){return(liste_d_employer);};
	void remplir_vols(vector<employer*>,vector<vols*>,vector<avion*>,vector<passager*>);
	void afficher_vols();
	~vols(void);
};