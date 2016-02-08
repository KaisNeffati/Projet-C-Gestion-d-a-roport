#pragma once
#include"personne.h"
#include<iostream>
using namespace std;
#include<vector>
#include<string>
class employer:public personne
{		
	protected:
		string grade;
		float salaire;
		bool embauche;
		string etat[31][13];
public:
	employer(int g=0,int h=0,int i=0,string a="",string b="",string c="",string d="",long e=0,long f=0,string j="",float k=0,bool w=false);
	string get_etat(int i,int j){return(etat[i][j]);}
	void set_embauche(bool t){embauche=t;}
	bool get_embauche(){return(embauche);}
friend ostream& operator<< (ostream & o,employer & p);
friend istream& operator>> (istream & i,employer & p);
	int	exist_carte_identitee(vector<employer*>,long);
	void set_etat(int i,int j,string a){etat[i][j]=a;}
	void remplir_employer(vector<employer*>);
	void modifier_employer(vector<employer*>);
	void afficher();
	~employer(void);
};

