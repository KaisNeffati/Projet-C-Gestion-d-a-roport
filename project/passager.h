#pragma once
#include"personne.h"
#include<iostream>
#include<fstream>

using namespace std;
#include<vector>
#include<string>
class passager:public personne
{
	protected:
	string login;
	string mots_d_pass;
	string etat[31][13];

public:
	passager(int g=0,int h=0,int i=0,string a="",string b="",string c="",string d="",long e=0,long f=0,string j="",string k="");
	void modifier_passager(vector<passager*>);
	void afficher();
	friend ostream& operator<< (ostream & o,passager & p);
	friend istream& operator>> (istream & in,passager & p);
	void remplir_passager(vector<passager*>);
	string	get_login(){return(login);};
	int exist_carte_identitee(vector<passager*> t,long a);
	string set_login(string c){login=c;};
	string	get_mots_d_pass(){return(mots_d_pass);};
	string set_mots_d_pass(string c){mots_d_pass=c;};
	string get_etat(int i,int j){return(etat[i][j]);};
	void set_etat(int i,int j,string a){etat[i][j]=a;};
	~passager(void);
};

