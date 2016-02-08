#pragma once
#include<fstream>
#include<iostream>
using namespace std;
class date
{
	protected:
	int jour;
	int mois;
	int annee;
public:
	date(int a=0 ,int b=0 ,int c=0){jour=a;mois=b;annee=c;};
	void remplir_date();
	void afficher();
friend ostream& operator<< (ostream & o,date & d);
friend istream& operator>> (istream & in,date & d);

	int get_jour(){return(jour);};
	void set_jour(int a){jour=a;};
	int get_mois(){return(jour);};
	void set_mois(int a){jour=a;};
	int get_annee(){return(jour);};
	void set_annee(int a){jour=a;};
	~date(void);
};

