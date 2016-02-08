#include "date.h"




void date::remplir_date()
{
	cout<<"donner jour"<<endl;
	cin>>jour;
	while(jour<1||jour>>30)
	{
		cout<<"donner jour"<<endl;
	cin>>jour;
	}
	cout<<"donner mois"<<endl;
	cin>>mois;
	while(mois<1||mois>>12)
	{
		cout<<"donner mois"<<endl;
	cin>>mois;
	}
cout<<"donner annee"<<endl;
	cin>>annee;

}
void date::afficher()
{cout<<jour<<"/"<<mois<<"/"<<annee<<endl;}
istream& operator>> (istream & in,date & d)
{
		in>>d.annee;in.ignore();
		in>>d.mois;in.ignore();
		in>>d.jour;in.ignore();
		return(in);
	}
ostream& operator<< (ostream & o,date & d)
{
		o<<d.annee;
		o<<d.mois;
		o<<d.jour;
		return(o);
	}
date::~date(void)
{
}
