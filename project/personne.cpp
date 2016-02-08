#include "personne.h"


personne::personne(int g,int h,int i,string a,string b,string c,string d,long e,long f):date_de_naissance(g,h,i)
{
	 nom=a;
	 prenom=b;
	 email=c;
	 adress=d;
	 carte_d_identitee=e;
	 carte_bancaire=f;
}

void personne::afficher()
{
	cout<<"nom: "<<nom<<endl;
	cout<<"prenom: "<<prenom<<endl;
	cout<<"adress: "<<adress<<endl;
	cout<<"email: "<<email<<endl;
	cout<<"carte d'identite : "<<carte_d_identitee<<endl;
	cout<<"catre bancaire : "<<carte_bancaire<<endl;
	cout<<"date de naissance : ";
	date_de_naissance.afficher();
}

personne::~personne(void)
{
}