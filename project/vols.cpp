#include "vols.h"

vols::vols(int d,int e,int f,int g,int h,int i,int j,int k,string l,string m,string n,string a,string b,int c):temp_d_depart(d,e),temp_d_arrivee(f,g),date_d_vols(h,i,j),av(k,l,m,n)
{
	lieu_depart=a;
	lieu_d_arrivee=b;
	num_d_vols=c;
}
int vols::existance_num(vector<vols*> tvols,int num)
{
	for(unsigned int i=0 ;i<tvols.size();i++)
		if (tvols[i]->get_num_vols()==num)
			return(i);
	return(-1);


}
int vols::existe_place()
{return(av.get_nb_plase_maxi()-liste_d_passager.size());};
ostream& operator<< (ostream & o,vols & v)
	{
	o<<v.temp_d_arrivee<<endl;o<<v.lieu_depart<<endl;
	o<<v.lieu_d_arrivee<<endl;o<<v.num_d_vols<<endl;
	o<<v.temp_d_depart<<endl;o<<v.date_d_vols<<endl;
	o<<v.av<<endl;
	for(unsigned int i=0;i<v.liste_d_employer.size();i++)
		o<<v.liste_d_employer[i]<<endl;
    for(unsigned int i=0;i<v.liste_d_passager.size();i++)
		o<<v.liste_d_passager[i]<<endl;
    for(unsigned int i=0;i<v.liste_des_escales.size();i++)
		o<<v.liste_des_escales[i]<<endl;
	return(o);
	}
istream& operator>> (istream & in,vols & v)
	{
	in>>v.temp_d_arrivee;getline(in,v.lieu_depart,'\n');
	getline(in,v.lieu_d_arrivee,'\n');in>>v.num_d_vols;in.ignore();
	in>>v.temp_d_depart;in>>v.date_d_vols;
	in>>v.av;
	for(unsigned int i=0;i<v.liste_d_employer.size();i++)
		in>>*(v.liste_d_employer[i]);
    for(unsigned int i=0;i<v.liste_d_passager.size();i++)
		in>>*(v.liste_d_passager[i]);
    for(unsigned int i=0;i<v.liste_des_escales.size();i++)
		in>>v.liste_des_escales[i];
	return(in);
	}
int vols::exist_avion(vector<avion*> t,string nom)
{	for(unsigned int i=0 ;i<t.size();i++)
		if (t[i]->get_nom()==nom)
			return(i);
	return(-1);}
void vols::modifer_vols(vector<vols*> tvols,vector<employer*> temployer,vector<passager*> tpassager)
{int x=1;
while(x!=0)
{	cout<<"*********************************************************************"<<endl;
cout<<" 1 => modifier le plan de vols "<<endl<<" 2 => modifier avion "<<endl<<" 3 => modifier liste des employer"<<endl<<" 4 => modifier liste des passager"<<endl<<" 5 => modifier numero de vols"<<endl<<" 0 => Quitter"<<endl;
cout<<"donner votre choix svp : ";cin>>x;
switch(x)
{
case 1:
	{
		int y=1;
		while(y!=0)
		{	cout<<"*********************************************************************"<<endl;
			cout<<" 1 => modifier lieu de depart"<<endl<<" 2 => modifier lieu d'arriver"<<endl<<" 3 => modifier temp de depart"<<endl<<" 4 => modifier temps d'arriver"<<endl<<" 5 => modifier date de vols"<<endl<<" 0 => Quitter "<<endl;
		cin>>y;
			switch(y)
			{
			case 1:{cout<<"donner lieu de depart"<<endl;
				cin>>lieu_depart;break;}
			case 2:{cout<<"donner lieu de depart"<<endl;
				cin>>lieu_d_arrivee;break;}
			case 3:{temp_d_depart.remplir_temp();break;}
			case 4:{temp_d_arrivee.remplir_temp();break;}
			case 5:{date_d_vols.remplir_date();break;}
							
			}
		
			cout<<"*********************************************************************"<<endl;
		}
	   break;}
case 2:{	cout<<"*********************************************************************"<<endl;av.modifier_avion();	cout<<"*********************************************************************"<<endl;break;}
case 3:
	{	int y=1;
	while(y!=0)
	{	cout<<"*********************************************************************"<<endl;
		cout<<"gestion d'equipe de vols :"<<endl<<" 1 => ajouter un employer"<<endl<<" 2 => supprimer un employer"<<endl<<" 3 => afficher liste des employer"<<endl<<" 0 => Quitter"<<endl;
		cout<<"donner votre choix svp : ";cin>>x;
		switch(y)
		{
		case 1:
			{
				if(disponible_employer(temployer)>0)
						{int n,s=0;
						for(unsigned int i=0 ;i<temployer.size();i++)							
							if(temployer[i]->get_etat(date_d_vols.get_jour(),date_d_vols.get_mois())=="disp")
							{cout<<"employer numero "<<s<<" :"<<endl;temployer[i]->afficher();s++;}

							cout<<"donner numero d'employer : "<<endl;
							cin>>n;
							while(n<0||n>=s)
							{cout<<"donner numero d'employer : "<<endl;
							cin>>n;}
							if (temployer[n]->get_etat(date_d_vols.get_jour(),date_d_vols.get_mois())=="disp")
							{
								liste_d_employer.push_back(temployer[n]);
								temployer[n]->set_etat(date_d_vols.get_jour(),date_d_vols.get_mois(),"0000");
								cout<<"fin de supprission"<<endl;
							}
							else cout<<"employer en vols"<<endl;
							}
				else cout<<"desole il n'y a pas des employer disponible a cette date "<<endl;
				
			   break;}
		case 2:
			{	
				for(unsigned int i=0 ;i<liste_d_employer.size();i++)
					liste_d_employer[i]->afficher();
				int n;
				cout<<"donner numero d'employer : "<<endl;
				cin>>n;
				int w=liste_d_employer.size();
				if(0<=n&&n<w)
				{
				liste_d_employer[n]->set_etat(date_d_vols.get_jour(),date_d_vols.get_mois(),"disp");
				liste_d_employer.erase(liste_d_employer.begin()+n);}
				else cout<<"employer inexistant"<<endl;
				cout<<"fin de supprission"<<endl;
				
			   break;}
		case 3:
			{	
				for(unsigned int i=0 ;i<liste_d_employer.size();i++)
					liste_d_employer[i]->afficher();
				cout<<"***********fin d'affichage**************"<<endl;
				
				   break;}
				}
	
	
	
	
			cout<<"*********************************************************************"<<endl;}
	break;}
case 4:
	{int a=1;
	while(a!=0)
	{	cout<<" 1 => ajouter un passager"<<endl<<" 2 =>gestion des passager sur le vols"<<endl<<" 0 => Quitter "<<endl;
		cout<<"donner votre choix svp : ";cin>>a;
	switch(a)
	{
case 1:
	{	cout<<"*********************************************************************"<<endl;
				if(disponible_passager(tpassager)>0)
						{int n,s=0;
						for(unsigned int i=0 ;i<tpassager.size();i++)							
							if(tpassager[i]->get_etat(date_d_vols.get_jour(),date_d_vols.get_mois())=="disp")
							{cout<<"passager numero "<<s<<" :"<<endl;tpassager[i]->afficher();s++;}

							cout<<"donner numero d'passager : "<<endl;
							cin>>n;
							while(n<0||n>=s)
							{cout<<"donner numero d'passager : "<<endl;
							cin>>n;}
							if (tpassager[n]->get_etat(date_d_vols.get_jour(),date_d_vols.get_mois())=="disp")
							{
								liste_d_passager.push_back(tpassager[n]);
								tpassager[n]->set_etat(date_d_vols.get_jour(),date_d_vols.get_mois(),"0000");
								cout<<"fin de supprission"<<endl;
							}
							else cout<<"passager en vols"<<endl;
							}
				else cout<<"desole il n'y a pas des passager disponible a cette date "<<endl;
					cout<<"*********************************************************************"<<endl;
			   break;}
case 2:{	
	for(unsigned int i=0 ;i<liste_d_passager.size();i++)
		{cout<<"passager numero "<<i<<" :"<<endl;liste_d_passager[i]->afficher();}
		cout<<"donner le numero de passager"<<endl;int y;
		cin>>y;int i=liste_d_passager.size();
		if((0<=y)&&(y<i))
		{
			int a=1;
			while(a!=0)
			{	cout<<"*********************************************************************"<<endl;
			cout<<" 1 => modifier passager"<<endl<<" 2 => supprimer passager"<<endl<<" 0 => Quitter "<<endl;
			cin>>a;
			if (a==1)
			liste_d_passager[y]->modifier_passager(tpassager);
			else if (a==2)	{liste_d_passager[y]->set_etat(date_d_vols.get_jour(),date_d_vols.get_mois(),"disp");
								liste_d_passager.erase(liste_d_passager.begin()+y);}
				cout<<"*********************************************************************"<<endl;
			}
		}
		else cout<<"passager inexistant"<<endl;
	   break;}
	}
	}
	   break;
	}
case 5:{
			cout<<"donner numero de vols"<<endl;int a;
			cin>>a;
			while(existance_num(tvols,a)!=-1)
			{	cout<<"*********************************************************************"<<endl;
			cout<<"donner numero de vols"<<endl;
			cin>>a;
				cout<<"*********************************************************************"<<endl;}
			num_d_vols=a;
	   break;}
}

	cout<<"*********************************************************************"<<endl;
	
}	
}
int vols::disponible_employer(vector<employer *> t)
{int s=0;
	for(unsigned int i=0 ;i<t.size();i++)
		if(t[i]->get_etat(date_d_vols.get_jour(),date_d_vols.get_mois())=="disp")
			s++;
	return(s);

}
int vols::disponible_passager(vector<passager*> t)
{int s=0;
	for(unsigned int i=0 ;i<t.size();i++)
		if(t[i]->get_etat(date_d_vols.get_jour(),date_d_vols.get_mois())=="disp")
			s++;
	return(s);
}
void vols::remplir_vols(vector<employer*> temployer,vector<vols*> tvols,vector<avion*> tavion,vector<passager*> tpassager)
{

	
	
	cout<<"donner le lieu de depart "<<endl;
	cin>>lieu_depart;
	cout<<"donner le lieu d'arriver "<<endl;
	cin>>lieu_d_arrivee;
	cout<<"donner numero de vols"<<endl;
	cin>>num_d_vols;
	while(existance_num(tvols,num_d_vols)!=-1)
	{
	cout<<"donner numero de vols"<<endl;
	cin>>num_d_vols;
	}
	cout<<"donner date de vols"<<endl;
	date_d_vols.remplir_date();
	cout<<"donner temps de depart de vols"<<endl;
	temp_d_depart.remplir_temp();
	cout<<"donner temps d'arriver de vols"<<endl;
	temp_d_arrivee.remplir_temp();
	for(unsigned int i=0 ;i<tavion.size();i++)
		if(tavion[i]->get_etat(date_d_vols.get_jour(),date_d_vols.get_mois())=="disp")
		{cout<<"avion numero "<<i<<":"<<endl;
			tavion[i]->afficher();}
	cout<<"donner nom d'avion"<<endl;string y;
	cin>>y;
	while(exist_avion(tavion,y)==-1)
	{cout<<"donner nom d'avion"<<endl;
	cin>>y;}
	av.get_avion(tavion,exist_avion(tavion,y));
	av.set_etat(date_d_vols.get_jour(),date_d_vols.get_mois(),"0000");
	int x=1;
	while(x!=0)
	{
		cout<<"gestion des escales :"<<endl<<" 1 => insert un escale"<<endl<<" 2 => supprimer un escale"<<endl<<" 0 => Quitter"<<endl;
		cout<<"donner votre choix svp : ";cin>>x;
		switch(x)
		{
		case 1:
			{	cout<<"*********************************************************************"<<endl;
				for(unsigned int i=0 ;i<liste_des_escales.size();i++)
				cout<<"escale numero "<<i<<" : "<<liste_des_escales[i]<<endl;
				cout<<"*********************************************************************"<<endl;
			string e;
			cout<<"donner escale"<<endl;
			cin>>e;
			int n;
			cout<<"donner numero d'escale"<<endl;
			cin>>n;
			int u=liste_des_escales.size();
			if (n>=u)
				liste_des_escales.push_back(e);
			else
			{
			while(n<0||n>=u)
			{
			cout<<"donner numero d'escale"<<endl;
			cin>>n;
			}
			liste_des_escales.insert(liste_des_escales.begin()+n,e);}
			cout<<"fin d'insertion escalier"<<endl;	cout<<"*********************************************************************"<<endl;
			   break;}
		case 2:
			{	cout<<"*********************************************************************"<<endl;
			for(unsigned int i=0 ;i<liste_des_escales.size();i++)
					cout<<"escale numero "<<i+1<<" : "<<liste_des_escales[i]<<endl;
				cout<<"*********************************************************************"<<endl;
			if(liste_des_escales.size()!=0)
			{
			int n;
			cout<<"donner numero d'escale"<<endl;
			cin>>n;int u=liste_des_escales.size();
			if(0<=n&&n<u)
			{
			liste_des_escales.erase(liste_des_escales.begin()+n);
			cout<<"fin de suppression"<<endl;
			}else
				cout<<"aucun escalier"<<endl;
			}
			else cout<<"aucun escale existant"<<endl;	cout<<"*********************************************************************"<<endl;
			   break;}
		}
	
	
	
	}
	x=1;
	while(x!=0)
	{	cout<<"*********************************************************************"<<endl;
		cout<<"gestion d'equipe de vols :"<<endl<<" 1 => ajouter un employer"<<endl<<" 2 => supprimer un employer"<<endl<<" 3 => afficher liste des employer"<<endl<<" 0 => Quitter"<<endl;
		cout<<"donner votre choix svp : ";cin>>x;
		switch(x)
		{
		case 1:
			{	cout<<"*********************************************************************"<<endl;
				if(disponible_employer(temployer)>0)
						{int n,s=0;
						for(unsigned int i=0 ;i<temployer.size();i++)							
							if(temployer[i]->get_etat(date_d_vols.get_jour(),date_d_vols.get_mois())=="disp")
							{cout<<"employer numero "<<s<<" :"<<endl;temployer[i]->afficher();s++;}

							cout<<"donner numero d'employer : "<<endl;
							cin>>n;
							while(n<0||n>=s)
							{cout<<"donner numero d'employer : "<<endl;
							cin>>n;}
							if (temployer[n]->get_etat(date_d_vols.get_jour(),date_d_vols.get_mois())=="disp")
							{
								liste_d_employer.push_back(temployer[n]);
								temployer[n]->set_etat(date_d_vols.get_jour(),date_d_vols.get_mois(),"0000");
								cout<<"fin de supprission"<<endl;
							}
							else cout<<"employer en vols"<<endl;
							}
				else cout<<"desole il n'y a pas des employer disponible a cette date "<<endl;
					cout<<"*********************************************************************"<<endl;
			   break;}
		case 2:
			{		cout<<"*********************************************************************"<<endl;
				for(unsigned int i=0 ;i<liste_d_employer.size();i++)
					liste_d_employer[i]->afficher();
				int n;
				cout<<"donner numero d'employer : "<<endl;
				cin>>n;
				int w=liste_d_employer.size();
				if(0<=n&&n<w)
				{
				liste_d_employer[n]->set_etat(date_d_vols.get_jour(),date_d_vols.get_mois(),"disp");
				liste_d_employer.erase(liste_d_employer.begin()+n);}
				else cout<<"employer inexistant"<<endl;
				cout<<"fin de supprission"<<endl;
					cout<<"*********************************************************************"<<endl;
			   break;}
		case 3:
			{		cout<<"*********************************************************************"<<endl;
				for(unsigned int i=0 ;i<liste_d_employer.size();i++)
					liste_d_employer[i]->afficher();
				cout<<"****************************fin d'affichage*************************"<<endl;
					cout<<"*********************************************************************"<<endl;
				   break;}
				}
	
	
	
			}
	x=1;
	while(x!=0)
	{	cout<<"*********************************************************************"<<endl;
		cout<<"gestion de la liste des passager de vols :"<<endl<<" 1 => ajouter un passager"<<endl<<" 2 => supprimer un passager"<<endl<<" 3 => afficher liste des passager"<<endl<<" 0 => Quitter"<<endl;
		cout<<"donner votre choix svp : ";cin>>x;
		switch(x)
		{
		case 1:
			{	cout<<"*********************************************************************"<<endl;
				if(disponible_passager(tpassager)>0)
						{int n,s=0;
						for(unsigned int i=0 ;i<tpassager.size();i++)							
							if(tpassager[i]->get_etat(date_d_vols.get_jour(),date_d_vols.get_mois())=="disp")
							{cout<<"passager numero "<<s<<" :"<<endl;tpassager[i]->afficher();s++;}

							cout<<"donner numero d'passager : "<<endl;
							cin>>n;
							while(n<0||n>=s)
							{cout<<"donner numero d'passager : "<<endl;
							cin>>n;}
							if (tpassager[n]->get_etat(date_d_vols.get_jour(),date_d_vols.get_mois())=="disp")
							{
								liste_d_passager.push_back(tpassager[n]);
								tpassager[n]->set_etat(date_d_vols.get_jour(),date_d_vols.get_mois(),"0000");
								cout<<"fin de ajout"<<endl;
							}
							else cout<<"passager en vols"<<endl;
							}
				else cout<<"desole il n'y a pas des passager disponible a cette date "<<endl;
					cout<<"*********************************************************************"<<endl;
			   break;}
		case 2:
			{		cout<<"*********************************************************************"<<endl;
				for(unsigned int i=0 ;i<liste_d_passager.size();i++)
					liste_d_passager[i]->afficher();
				int n;
				cout<<"donner numero d'passager : "<<endl;
				cin>>n;
				int w=liste_d_passager.size();
				if(0<=n&&n<w)
				{
				liste_d_passager[n]->set_etat(date_d_vols.get_jour(),date_d_vols.get_mois(),"disp");
				liste_d_passager.erase(liste_d_passager.begin()+n);}
				else cout<<"passager inexistant"<<endl;
				cout<<"fin de supprission"<<endl;
					cout<<"*********************************************************************"<<endl;
			   break;}
		case 3:
			{		cout<<"*********************************************************************"<<endl;
				for(unsigned int i=0 ;i<liste_d_passager.size();i++)
					liste_d_passager[i]->afficher();
				cout<<"*************************fin d'affichage******************************"<<endl;
					cout<<"*********************************************************************"<<endl;
				   break;}
				}
	
	
	
			}
		
		
	
};
void vols::supprimer_vols()
{
	av.set_etat(date_d_vols.get_jour(),date_d_vols.get_mois(),"disp");
	for(unsigned int i=0 ;i<liste_d_employer.size();i++)
		liste_d_employer[i]->set_etat(date_d_vols.get_jour(),date_d_vols.get_mois(),"disp");
	for(unsigned int i=0 ;i<liste_d_passager.size();i++)
		liste_d_passager[i]->set_etat(date_d_vols.get_jour(),date_d_vols.get_mois(),"disp");
}
void vols::afficher_vols()
{
		cout<<"*********************************************************************"<<endl;
	cout<<"temps de depart : ";temp_d_depart.afficher();
	cout<<"temps d'arriver : ";temp_d_arrivee.afficher();
	cout<<"lieu de depart : "<<lieu_depart<<endl;
	cout<<"lieu d'arrivee : "<<lieu_d_arrivee<<endl;
	cout<<"numeor de vols : "<<num_d_vols<<endl;
	cout<<"date de vols :";
	date_d_vols.afficher();
		cout<<"*********************************************************************"<<endl;
	cout<<"avion utiliser :"<<endl;
	av.afficher();cout<<endl;
		cout<<"*********************************************************************"<<endl;
	cout<<"equipe de vols "<<endl;
	for(unsigned int i=0 ;i<liste_d_employer.size();i++)
		liste_d_employer[i]->afficher();
		cout<<"*********************************************************************"<<endl;
	cout<<"liste des passager "<<endl;
	for(unsigned int i=0 ;i<liste_d_passager.size();i++)
		liste_d_passager[i]->afficher();
	cout<<"*********************************************************************"<<endl;
	cout<<"liste des escales "<<endl;
	for(unsigned int i=0 ;i<liste_des_escales.size();i++)
		cout<<"escale numero "<<i+1<<" : "<<liste_des_escales[i]<<endl;
	cout<<"*********************************************************************"<<endl;
};
void vols::afficher_vols_client()
{

	cout<<"lieu d'arriver : "<<lieu_d_arrivee<<endl;
	cout<<"temp d'arriver"<<endl;
	temp_d_arrivee.afficher();
	cout<<"lieu de depart : "<<lieu_depart<<endl;
	cout<<"temp de depart"<<endl;
	temp_d_depart.afficher();
	cout<<"date de vols"<<endl;
	date_d_vols.afficher();

}
vols::~vols(void)
{
	for(unsigned int i=0 ;i<liste_d_passager.size();i++)
		delete liste_d_passager[i];
	liste_d_passager.clear();

	for(unsigned int i=0 ;i<liste_d_employer.size();i++)
		delete liste_d_employer[i];
	liste_d_employer.clear();


	liste_des_escales.clear();

}
