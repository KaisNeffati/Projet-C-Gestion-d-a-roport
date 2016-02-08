#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
using namespace std;

class avion
{protected:
	int nb_place_maxi;
	string nom;
	string marque;
	string modele;
	bool vendus;
	string etat[31][13];

	
public:
	avion(int a=0,string b="",string c="",string d="",bool e=false);
	int	get_nb_plase_maxi(){return(nb_place_maxi);}
	friend ostream& operator<< (ostream & o,avion & a);
	friend istream& operator>> (istream & in,avion & a);
	void remplir_avion(int i,int j);
	void afficher();
	void remplir_avion_compagnie();
	bool operator==(avion& a)
	{
		for(unsigned int i=0;i<31;i++)
			for(unsigned int j=0;j<31;j++)
				if(etat[i][j]!=a.etat[i][j])
					return(false);
		if((nb_place_maxi==a.nb_place_maxi)&&(nom==a.nom)&&(marque==a.marque)&&(modele==a.modele)&&(vendus==a.vendus))
			return(true);
		return(false);
	}
	string get_marque(){return(marque);}
	string get_modele(){return(modele);}
	void get_avion(vector<avion*> a,int i)
	{
	nb_place_maxi=a[i]->get_nb_plase_maxi();
	nom=a[i]->get_nom();
	marque=a[i]->get_marque();
	modele=a[i]->get_modele();
	vendus=a[i]->get_vendus();
	for(unsigned int r=0;r<31;r++)
		for(unsigned int j=0;j<13;j++)
			etat[r][j]=a[i]->get_etat(r,j);
	
	}
	int existe_avion(vector<avion*>t,string a);
	bool get_vendus(){return(vendus);}
	void set_vendus(bool e){vendus=e;}
	void modifier(vector<avion*>);
	string get_nom(){return(nom);}
	string get_etat(int i,int j){return(etat[i][j]);}
	void set_etat(int i,int j ,string a){etat[i][j]=a;}
	void set_nb_place_maxi();
	void modifier_avion();
	~avion(void);
};

