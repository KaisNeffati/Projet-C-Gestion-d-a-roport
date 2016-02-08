#include "compagnie.h"

compagnie::compagnie(string a,string b,string c,string d,double e)
{
	nom=a;
	adress=b;
	email=c;
	site_web=d;
	numero_d_telephone=e;
}
int compagnie::rechercher_unicite_nom(vector<compagnie *> c,string n)
{
	for(unsigned int i=0;i<c.size();i++)
		if (n==c[i]->get_nom_compagnie())
			return(i);
	return(-1);
}
int compagnie::rechercher_exist(int a)
{
	for(unsigned int i=0;i<liste_d_vols.size();i++)
		if(liste_d_vols[i]->get_num_vols()==a)
			return(i);
	return(-1);
}
void compagnie::remplissage_compagnie(vector<compagnie *> tcompagnie,vector<employer *> temployer,vector<avion*> tavion,vector<passager*> tpassager)
{
	
	cout<<"Donner nom compagnie : " ;
	cin>>nom;
	while(rechercher_unicite_nom(tcompagnie,nom)!=-1)
	{cout<<"Donner nom compagnie : " ;
	cin>>nom;}
	cout<<"Donner nom adress : " ;
	cin>>adress;
	cout<<"Donner nom email : " ;
	cin>>email;
	cout<<"Donner nom site web : " ;
	cin>>site_web;
	cout<<"Donner numero de telephone : " ;
	cin>>numero_d_telephone;
	int y=1;
	while(y!=0)
	{
	cout<<"*********************************************************************"<<endl;
	cout<<" 1 => gestion des vols "<<endl<<" 2 => gestion des employer "<<endl<<" 3 => gestion des avions "<<endl<<" 0 => Quitter"<<endl;
	cout<<"donner votre choix svp : ";cin>>y;
	switch(y)
	{
	case 1:{	cout<<"*********************************************************************"<<endl;
	int x=1;
	if((liste_des_employer.size()>0)&&(liste_d_avion.size()>0))
		{
	while(x!=0)
	{	cout<<"*********************************************************************"<<endl;
cout<<" 1 => ajouter vols "<<endl<<" 2 => modifier vols"<<endl<<" 3 => supprimer vols "<<endl<<" 4 => afficher vols"<<endl<<" 5 => afficher liste des vols"<<endl<<" 0 => Quitter "<<endl;
		cout<<"donner votre choix svp : ";cin>>x;
		switch(x)
		{
		case 1:{	cout<<"*********************************************************************"<<endl;		
				vols *v= new vols();
				v->remplir_vols(liste_des_employer,liste_d_vols,liste_d_avion,tpassager);
				liste_d_vols.push_back(v);	
				cout<<"fin d'ajoue de vols"<<endl;
					cout<<"*********************************************************************"<<endl;
				break;}
		case 2:
			{	cout<<"****************************************"<<endl;
				cout<<"donner numero de vols a modifier"<<endl;
				int a;cin>>a;
				if(rechercher_exist(a)!=-1)
				{
					liste_d_vols[rechercher_exist(a)]->modifer_vols(liste_d_vols,liste_des_employer,tpassager);
					cout<<"fin de modification des vols"<<endl;
				}
				else cout<<"vols inexistant"<<endl;
				cout<<"****************************************"<<endl;
			   break;}
		case 3:
			{	cout<<"****************************************"<<endl;
				cout<<"donner numero de vols a supprimer"<<endl;
				int a;cin>>a;
				if(rechercher_exist(a)!=-1)
				{
					liste_d_vols[rechercher_exist(a)]->supprimer_vols();
					liste_d_vols.erase(liste_d_vols.begin()+rechercher_exist(a));
					cout<<"fin de supprission de vols"<<endl;
				}
				else cout<<"vols inexistant"<<endl;
				cout<<"****************************************"<<endl;
			   break;}
		case 4:
			{	cout<<"****************************************"<<endl;
				cout<<"donner numero de vols a afficher"<<endl;
				int a;cin>>a;
				if(rechercher_exist(a)!=-1)
				{
					liste_d_vols[rechercher_exist(a)]->afficher_vols();
					cout<<"fin de affichage de vols"<<endl;
				}
				else cout<<"vols inexistant"<<endl;
				cout<<"****************************************"<<endl;
			   break;}
		case 5:
			{	cout<<"****************************************"<<endl;
				for(unsigned int i=0;i<liste_d_vols.size();i++)
				{cout<<"vols numero "<<i<<" : "<<endl;liste_d_vols[i]->afficher_vols();}
				cout<<"fin de affichage de liste de vols"<<endl;
				
				cout<<"****************************************"<<endl;
			   break;}
		
		
		}
	}
	}else cout<<"Desole Vous ne pouvez pas annoncer une vols "<<endl;
		   break;}
	case 2:
		{int x=1;
		while(x!=0)
		{cout<<"****************************************"<<endl;
		cout<<" 1 => ajouter employer "<<endl<<" 2 => modifier employer"<<endl<<" 3 => supprimer employer "<<endl<<" 4 => afficher employer"<<endl<<" 5 => afficher liste des employers"<<endl<<" 0 => Quitter "<<endl;
			cout<<"donner votre choix svp : ";cin>>x;
			switch(x)
			{
			case 1:{cout<<"****************************************"<<endl;
				
				int y=1;
				while(y!=0)
				{cout<<" 1 => embaucher employer avec experience "<<endl<<" 2 => embaucher un employeur debutant"<<endl<<" 0 => Quitter"<<endl;
				cin>>y;
				if(y==1)
				{cout<<"****************************************"<<endl;
					if(exist_employer_disponible(temployer)==true)
				{
				for(unsigned int i=0;i<temployer.size();i++)
					if (temployer[i]->get_embauche()==false)
							temployer[i]->afficher();
				cout<<"donner la carte d'identiter de l'employer"<<endl;
				long a;cin>>a;
				if(existe_employer(temployer,a)!=-1 && temployer[existe_employer(temployer,a)]->get_embauche()==false)
				{
									liste_des_employer.push_back(temployer[existe_employer(temployer,a)]);
									temployer[existe_employer(temployer,a)]->set_embauche(true);
				}
				else cout<<"employer indisponible"<<endl;cout<<"****************************************"<<endl;
				}
				else cout<<"aucun employer existant"<<endl;
				cout<<"****************************************"<<endl;}
				else if (y==2)
				{cout<<"****************************************"<<endl;
					employer *S =new employer();
				S->remplir_employer(temployer);
				liste_des_employer.push_back(S);
				temployer.push_back(S);
				temployer[existe_employer(temployer,S->get_carte_id())]->set_embauche(true);
				cout<<"****************************************"<<endl;}
				}cout<<"****************************************"<<endl;
				break;}
			case 2:{cout<<"****************************************"<<endl;
				cout<<"donner carte d'identité d'employer a modifier"<<endl;
				long a;cin>>a;
				if(existe_employer(liste_des_employer,a)!=-1)
				{
					liste_des_employer[existe_employer(liste_des_employer,a)]->modifier_employer(temployer);
					cout<<"fin de modification des vols"<<endl;
				}
				else cout<<"vols inexistant"<<endl;
				cout<<"****************************************"<<endl;	
				break;}
			case 3:{cout<<"****************************************"<<endl;
				cout<<"donner carte d'identité d'employer a supprimer"<<endl;
				long a;cin>>a;
				if(existe_employer(liste_des_employer,a)!=-1)
				{	cout<<"***************************"<<endl;
					for(unsigned int i=0;i<tcompagnie.size();i++)
						tcompagnie[i]->supprimer_employer(liste_des_employer[existe_employer(liste_des_employer,a)]);
					cout<<"***************************"<<endl;
					liste_des_employer[existe_employer(liste_des_employer,a)]->set_embauche(false);
					cout<<"***************************"<<endl;
					liste_des_employer.erase(liste_des_employer.begin()+existe_employer(liste_des_employer,a));
					cout<<"fin de supprission de employer"<<endl;
				}
				else cout<<"vols inexistant"<<endl;
				cout<<"****************************************"<<endl;
				break;}
			case 4:{cout<<"****************************************"<<endl;
				cout<<"donner carte d'identite d'employer a afficher"<<endl;
				long a;cin>>a;
				if(existe_employer(liste_des_employer,a)!=-1)
				{
					liste_des_employer[existe_employer(liste_des_employer,a)]->afficher();
					cout<<"fin de affichage de employer"<<endl;
				}
				else cout<<"vols inexistant"<<endl;
				cout<<"****************************************"<<endl;
				break;}
			case 5:{cout<<"****************************************"<<endl;
				for(unsigned int i=0;i<liste_des_employer.size();i++)
					liste_des_employer[i]->afficher();
				cout<<"fin de affichage de liste de employer"<<endl;
				cout<<"****************************************"<<endl;
				break;}
			
			}
		}
		 break;}
	case 3:
		{int x=1;
		while(x!=0)
		{cout<<"****************************************"<<endl;
		cout<<" 1 => ajouter avion "<<endl<<" 2 => modifier avion"<<endl<<" 3 => supprimer avion "<<endl<<" 4 => afficher avion"<<endl<<" 5 => afficher liste des avions"<<endl<<" 0 => Quitter "<<endl;
		cout<<"donner votre choix svp : ";cin>>x;
		switch(x)
		{
		case 1:{cout<<"****************************************"<<endl;

				int y=1;
				while(y!=0)
				{cout<<" 1 => ajouter avion occasion "<<endl<<" 2 => ajouter avion nouvelle"<<endl<<" 0 => Quitter"<<endl;
				cin>>y;	
				cout<<"****************************************"<<endl;
				if(y==1)
				{
				if(exist_avion_disponible(tavion))
				{	for(unsigned int i=0;i<tavion.size();i++)
					if (tavion[i]->get_vendus()==false)
							tavion[i]->afficher();
				cout<<"donner le nom de l'avion"<<endl;
				string a;cin>>a;
				if(existe_avion(tavion,a)!=-1 && tavion[existe_avion(tavion,a)]->get_vendus()==false)
				{
									liste_d_avion.push_back(tavion[existe_avion(tavion,a)]);
									tavion[existe_avion(tavion,a)]->set_vendus(true);
				}
				else cout<<"avion indisponible"<<endl;
			
				}
				else cout<<"aucune avion existant"<<endl;
				}
				else if (y==2)
				{
				avion *o=new avion();
				o->remplir_avion_compagnie();
				tavion.push_back(o);
				tavion[existe_avion(tavion,o->get_nom())]->set_vendus(true);
				liste_d_avion.push_back(o);
				}cout<<"****************************************"<<endl;
				}
				break;}
		case 2:{cout<<"****************************************"<<endl;
				cout<<"donner le nom de l'avion a modifier"<<endl;
				string a;cin>>a;
				if(existe_avion(liste_d_avion,a)!=-1)
				{
					liste_d_avion[existe_avion(liste_d_avion,a)]->modifier(tavion);
					cout<<"fin de modification des avions"<<endl;
				}
				else cout<<"avion inexistant"<<endl;
				cout<<"****************************************"<<endl;	
			break;}
		case 3:{cout<<"****************************************"<<endl;
				cout<<"donner nom d'avion a supprimer"<<endl;
				string a;cin>>a;
				if(existe_avion(liste_d_avion,a)!=-1)
				{cout<<"****"<<endl;
					for(unsigned int i=0;i<tcompagnie.size();i++)
						for(unsigned int j=0;j<tcompagnie[i]->get_liste_vole().size();j++)
							if(liste_d_avion[existe_avion(liste_d_avion,a)]==&tcompagnie[i]->get_liste_vole()[j]->get_avion())
									tcompagnie[i]->get_liste_vole()[j]->supprimer_vols();
					cout<<"****"<<endl;
					
					tavion[existe_avion(tavion,a)]->set_vendus(false);cout<<"****"<<endl;
					liste_d_avion.erase(liste_d_avion.begin()+existe_avion(tavion,a));
					cout<<"fin de supprission d'avion"<<endl;
				}
				else cout<<"avion inexistant"<<endl;
				cout<<"****************************************"<<endl;
			break;}
		case 4:{cout<<"****************************************"<<endl;
				cout<<"donner nom d'avion a afficher"<<endl;
				string a;cin>>a;
				if(existe_avion(liste_d_avion,a)!=-1)
				{
					liste_d_avion[existe_avion(liste_d_avion,a)]->afficher();
					cout<<"fin de affichage d'avion "<<endl;
				}
				else cout<<"avion inexistant"<<endl;
				cout<<"****************************************"<<endl;
			break;}
		case 5:{cout<<"****************************************"<<endl;
				for(unsigned int i=0;i<liste_d_avion.size();i++)
					liste_d_avion[i]->afficher();
				cout<<"fin de affichage de liste de avion"<<endl;
				cout<<"****************************************"<<endl;
			break;}
		}
		
		}


		   break;}

	}
	}

}
int compagnie::existe_avion(vector<avion*> t,string a)
{for(unsigned int i=0;i<t.size();i++)
	if (t[i]->get_nom()==a)
		return(i);
	return(-1);
}
ostream& operator<< (ostream & o,compagnie & c)
	{o<<c.nom<<endl;o<<c.adress<<endl;o<<c.email<<endl;o<<c.site_web<<endl;
	o<<c.numero_d_telephone<<endl;
		for(unsigned int i=0;i<c.liste_des_employer.size();i++)
			o<<c.liste_des_employer[i];
		for(unsigned int i=0;i<c.liste_d_vols.size();i++)
			o<<c.liste_d_vols[i];
		for(unsigned int i=0;i<c.liste_d_avion.size();i++)
			o<<c.liste_d_avion[i];
	
	return(o);
	}
istream& operator>> (istream & in,compagnie & c)
{	getline(in,c.nom,'\n');getline(in,c.adress,'\n');getline(in,c.email,'\n');getline(in,c.email,'\n');
	in>>c.numero_d_telephone;in.ignore();
	for(unsigned int i=0;i<c.liste_des_employer.size();i++)
		in>>*(c.liste_des_employer[i]);
	for(unsigned int i=0;i<c.liste_d_vols.size();i++)
		in>>*(c.liste_d_vols[i]);
	for(unsigned int i=0;i<c.liste_d_avion.size();i++)
		in>>*(c.liste_d_avion[i]);
	return(in);
	}
bool compagnie::disponible_passager(passager* p,int i)
{
	if(p->get_etat(liste_d_vols[i]->get_date().get_jour(),liste_d_vols[i]->get_date().get_mois())=="disp")
		return(false);
	else return(true);

}
bool compagnie::exist_employer_disponible(vector<employer*> t)
{
	for(unsigned int i=0;i<t.size();i++)
	if(t[i]->get_embauche()==false)
		return(true);
 return(false);

}
bool compagnie::exist_avion_disponible(vector<avion*> t)
{
	for(unsigned int i=0;i<t.size();i++)
	if(t[i]->get_vendus()==false)
		return(true);
	 return(false);

}
int compagnie::existe_employer(vector<employer*> t, long a)
{for(unsigned int i=0;i<t.size();i++)
	if (t[i]->get_carte_id()==a)
		return(i);
	return(-1);
}
int compagnie::exist_avion(vector<avion*> t,string x)
{for(unsigned int i=0;i<t.size();i++)
	if (t[i]->get_nom()==x)
		return(i);
	return(-1);
}
void compagnie::modifier_compagnie(vector<compagnie *> tcompagnie,vector<employer *> temployer,vector<avion*>tavion,vector<passager*> tpassager)
{int y=1;
while(y!=0)
{cout<<" 1 => modifier nom "<<endl<<" 2 => modifier adress "<<endl<<" 3 => modifier email "<<endl<<" 4 => modifier site web"<<endl<<" 5 => modifier numero de telephone "<<endl<<" 6 => modifier liste des employer"<<endl<<" 7 => modifier liste des vols"<<endl<<" 8 => modifier liste des avion"<<endl<<" 0 => Quitter "<<endl;
	cout<<"donner votre choix svp : ";cin>>y;
	switch(y)
	{
	case 1:{cout<<"donner nom : ";cin>>nom;
		   while(rechercher_unicite_nom(tcompagnie,nom)!=-1&&tcompagnie.size()==0)
			{cout<<"Donner nom : " ;
			cin>>nom;}
		   break;}
	case 2: {cout<<"donner adresse : ";cin>>adress;break;}
	case 3: {cout<<"donner email : ";cin>>email;break;}
	case 4: {cout<<"donner site web : ";cin>>site_web;break;}
	case 5:	{cout<<"donner numero de telephone : ";cin>>numero_d_telephone;break;}
	case 6: 
		{int x=1;
		while(x!=0)
		{cout<<"****************************************"<<endl;
		cout<<" 1 => ajouter employer "<<endl<<" 2 => modifier employer"<<endl<<" 3 => supprimer employer "<<endl<<" 4 => afficher employer"<<endl<<" 5 => afficher liste des employers"<<endl<<" 0 => Quitter "<<endl;
			cout<<"donner votre choix svp : ";cin>>x;
			switch(x)
			{
			case 1:{cout<<"****************************************"<<endl;
				
				int y=1;
				while(y!=0)
				{cout<<" 1 => embaucher employer avec experience "<<endl<<" 2 => embaucher un employeur debutant"<<endl<<" 0 => Quitter"<<endl;
				cin>>y;
				if(y==1)
				{cout<<"****************************************"<<endl;
					if(exist_employer_disponible(temployer)==true)
				{
				for(unsigned int i=0;i<temployer.size();i++)
					if (temployer[i]->get_embauche()==false)
							temployer[i]->afficher();
				cout<<"donner la carte d'identiter de l'employer"<<endl;
				long a;cin>>a;
				if(existe_employer(temployer,a)!=-1 && temployer[existe_employer(temployer,a)]->get_embauche()==false)
				{
									liste_des_employer.push_back(temployer[existe_employer(temployer,a)]);
									temployer[existe_employer(temployer,a)]->set_embauche(true);
				}
				else cout<<"employer indisponible"<<endl;cout<<"****************************************"<<endl;
				}
				else cout<<"aucun employer existant"<<endl;
				cout<<"****************************************"<<endl;}
				else if (y==2)
				{cout<<"****************************************"<<endl;
					employer *S =new employer();
				S->remplir_employer(temployer);
				liste_des_employer.push_back(S);
				temployer.push_back(S);
				temployer[existe_employer(temployer,S->get_carte_id())]->set_embauche(true);
				cout<<"****************************************"<<endl;}
				}cout<<"****************************************"<<endl;
				break;}
			case 2:{cout<<"****************************************"<<endl;
				cout<<"donner carte d'identité d'employer a modifier"<<endl;
				long a;cin>>a;
				if(existe_employer(liste_des_employer,a)!=-1)
				{
					liste_des_employer[existe_employer(liste_des_employer,a)]->modifier_employer(temployer);
					cout<<"fin de modification des vols"<<endl;
				}
				else cout<<"vols inexistant"<<endl;
				cout<<"****************************************"<<endl;	
				break;}
			case 3:{cout<<"****************************************"<<endl;
				cout<<"donner carte d'identité d'employer a supprimer"<<endl;
				long a;cin>>a;
				if(existe_employer(liste_des_employer,a)!=-1)
				{	cout<<"***************************"<<endl;
					for(unsigned int i=0;i<tcompagnie.size();i++)
						tcompagnie[i]->supprimer_employer(liste_des_employer[existe_employer(liste_des_employer,a)]);
					cout<<"***************************"<<endl;
					liste_des_employer[existe_employer(liste_des_employer,a)]->set_embauche(false);
					cout<<"***************************"<<endl;
					liste_des_employer.erase(liste_des_employer.begin()+existe_employer(liste_des_employer,a));
					cout<<"fin de supprission de employer"<<endl;
				}
				else cout<<"vols inexistant"<<endl;
				cout<<"****************************************"<<endl;
				break;}
			case 4:{cout<<"****************************************"<<endl;
				cout<<"donner carte d'identite d'employer a afficher"<<endl;
				long a;cin>>a;
				if(existe_employer(liste_des_employer,a)!=-1)
				{
					liste_des_employer[existe_employer(liste_des_employer,a)]->afficher();
					cout<<"fin de affichage de employer"<<endl;
				}
				else cout<<"vols inexistant"<<endl;
				cout<<"****************************************"<<endl;
				break;}
			case 5:{cout<<"****************************************"<<endl;
				for(unsigned int i=0;i<liste_des_employer.size();i++)
					liste_des_employer[i]->afficher();
				cout<<"fin de affichage de liste de employer"<<endl;
				cout<<"****************************************"<<endl;
				break;}
			
			}
		}
		
			break;}
	case 7:{int x=1;
		if(liste_des_employer.size()>0&&liste_d_avion.size()>0)
		{
			while(x!=0)
		{cout<<"****************************************"<<endl;
		
		cout<<" 1 => ajouter vols "<<endl<<" 2 => modifier vols"<<endl<<" 3 => supprimer vols "<<endl<<" 4 => afficher vols"<<endl<<" 5 => afficher liste des vols"<<endl<<" 0 => Quitter "<<endl;
		cout<<"donner votre choix svp : ";cin>>x;
		switch(x)
		{
		case 1:{cout<<"****************************************"<<endl;			
				vols *v= new vols();
				v->remplir_vols(liste_des_employer,liste_d_vols,liste_d_avion,tpassager);
				liste_d_vols.push_back(v);	
				cout<<"fin d'ajoue de vols"<<endl;
				cout<<"****************************************"<<endl;
				break;}
		case 2:
			{	cout<<"****************************************"<<endl;
				cout<<"donner numero de vols a modifier"<<endl;
				int a;cin>>a;
				if(rechercher_exist(a)!=-1)
				{
					liste_d_vols[rechercher_exist(a)]->modifer_vols(liste_d_vols,liste_des_employer,tpassager);
					cout<<"fin de modification des vols"<<endl;
				}
				else cout<<"vols inexistant"<<endl;
				cout<<"****************************************"<<endl;
			   break;}
		case 3:
			{	cout<<"****************************************"<<endl;
				cout<<"donner numero de vols a supprimer"<<endl;
				int a;cin>>a;
				if(rechercher_exist(a)!=-1)
				{
					liste_d_vols[rechercher_exist(a)]->supprimer_vols();
					liste_d_vols.erase(liste_d_vols.begin()+rechercher_exist(a));
					cout<<"fin de supprission de vols"<<endl;
				}
				else cout<<"vols inexistant"<<endl;
				cout<<"****************************************"<<endl;
			   break;}
		case 4:
			{	cout<<"****************************************"<<endl;
				cout<<"donner numero de vols a afficher"<<endl;
				int a;cin>>a;
				if(rechercher_exist(a)!=-1)
				{
					liste_d_vols[rechercher_exist(a)]->afficher_vols();
					cout<<"fin de affichage de vols"<<endl;
				}
				else cout<<"vols inexistant"<<endl;
				cout<<"****************************************"<<endl;
			   break;}
		case 5:
			{	cout<<"****************************************"<<endl;
				for(unsigned int i=0;i<liste_d_vols.size();i++)
				{cout<<"vols numero "<<i<<" : "<<endl;liste_d_vols[i]->afficher_vols();}
				cout<<"fin de affichage de liste de vols"<<endl;
				
				cout<<"****************************************"<<endl;
			   break;}
		
		
				}
			}
		}
		else cout<<"Desole Vous ne pouvez pas annoncer une vols "<<endl;
		   break;}
	case 8:{int x=1;
		while(x!=0)
		{cout<<"****************************************"<<endl;
		cout<<" 1 => ajouter avion "<<endl<<" 2 => modifier avion"<<endl<<" 3 => supprimer avion "<<endl<<" 4 => afficher avion"<<endl<<" 5 => afficher liste des avions"<<endl<<" 0 => Quitter "<<endl;
		cout<<"donner votre choix svp : ";cin>>x;
		switch(x)
		{
		case 1:{cout<<"****************************************"<<endl;

				int y=1;
				while(y!=0)
				{cout<<" 1 => ajouter avion occasion "<<endl<<" 2 => ajouter avion nouvelle"<<endl<<" 0 => Quitter"<<endl;
				cin>>y;	
				cout<<"****************************************"<<endl;
				if(y==1)
				{
				if(exist_avion_disponible(tavion))
				{	for(unsigned int i=0;i<tavion.size();i++)
					if (tavion[i]->get_vendus()==false)
							tavion[i]->afficher();
				cout<<"donner le nom de l'avion"<<endl;
				string a;cin>>a;
				if(existe_avion(tavion,a)!=-1 && tavion[existe_avion(tavion,a)]->get_vendus()==false)
				{
									liste_d_avion.push_back(tavion[existe_avion(tavion,a)]);
									tavion[existe_avion(tavion,a)]->set_vendus(true);
				}
				else cout<<"avion indisponible"<<endl;
			
				}
				else cout<<"aucune avion existant"<<endl;
				}
				else if (y==2)
				{
				avion *o=new avion();
				o->remplir_avion_compagnie();
				tavion.push_back(o);
				tavion[existe_avion(tavion,o->get_nom())]->set_vendus(true);
				liste_d_avion.push_back(o);
				}cout<<"****************************************"<<endl;
				}
				break;}
		case 2:{cout<<"****************************************"<<endl;
				cout<<"donner le nom de l'avion a modifier"<<endl;
				string a;cin>>a;
				if(existe_avion(liste_d_avion,a)!=-1)
				{
					liste_d_avion[existe_avion(liste_d_avion,a)]->modifier(tavion);
					cout<<"fin de modification des avions"<<endl;
				}
				else cout<<"avion inexistant"<<endl;
				cout<<"****************************************"<<endl;	
			break;}
		case 3:{cout<<"****************************************"<<endl;
				cout<<"donner nom d'avion a supprimer"<<endl;
				string a;cin>>a;
				if(existe_avion(liste_d_avion,a)!=-1)
				{cout<<"****"<<endl;
					for(unsigned int i=0;i<tcompagnie.size();i++)
						for(unsigned int j=0;j<tcompagnie[i]->get_liste_vole().size();j++)
							if(liste_d_avion[existe_avion(liste_d_avion,a)]==&tcompagnie[i]->get_liste_vole()[j]->get_avion())
									tcompagnie[i]->get_liste_vole()[j]->supprimer_vols();
					cout<<"****"<<endl;
					
					tavion[existe_avion(tavion,a)]->set_vendus(false);cout<<"****"<<endl;
					liste_d_avion.erase(liste_d_avion.begin()+existe_avion(tavion,a));
					cout<<"fin de supprission d'avion"<<endl;
				}
				else cout<<"avion inexistant"<<endl;
				cout<<"****************************************"<<endl;
			break;}
		case 4:{cout<<"****************************************"<<endl;
				cout<<"donner nom d'avion a afficher"<<endl;
				string a;cin>>a;
				if(existe_avion(liste_d_avion,a)!=-1)
				{
					liste_d_avion[existe_avion(liste_d_avion,a)]->afficher();
					cout<<"fin de affichage d'avion "<<endl;
				}
				else cout<<"avion inexistant"<<endl;
				cout<<"****************************************"<<endl;
			break;}
		case 5:{cout<<"****************************************"<<endl;
				for(unsigned int i=0;i<liste_d_avion.size();i++)
					liste_d_avion[i]->afficher();
				cout<<"fin de affichage de liste de avion"<<endl;
				cout<<"****************************************"<<endl;
			break;}
		}
		
		}


		   break;}
	}
}
}
void compagnie::supprission_compagnie(vector<compagnie*>t)
{
		for(unsigned int i=0;i<liste_d_vols.size();i++)
			liste_d_vols[i]->supprimer_vols();
		for(unsigned int i=0;i<liste_des_employer.size();i++)
			liste_des_employer[i]->set_embauche(false);
		for(unsigned int i=0;i<liste_d_avion.size();i++)
			liste_d_avion[i]->set_vendus(false);

}
void compagnie::afficher_compagnie()
{
	cout<<"nom : "<<nom<<endl;
	cout<<"adress : "<<adress<<endl;
	cout<<"email : "<<email<<endl;
	cout<<"site web : "<<site_web<<endl;
	cout<<"numero de telephone : "<<numero_d_telephone<<endl;
	cout<<"****************************************"<<endl;
	cout<<"la liste des vols est :"<<endl;
		for(unsigned int i=0;i<liste_d_vols.size();i++)
		{cout<<"vols numero "<<i<<" : "<<endl;liste_d_vols[i]->afficher_vols();}
	cout<<"****************************************"<<endl;
	cout<<"la liste des employers est :"<<endl;
		for(unsigned int i=0;i<liste_des_employer.size();i++)
		{cout<<"employer numero "<<i<<" : "<<endl;liste_des_employer[i]->afficher();}

		cout<<"****************************************"<<endl;
	cout<<"la liste des avions est :"<<endl;
		for(unsigned int i=0;i<liste_d_avion.size();i++)
		{cout<<"avion numero "<<i<<" : "<<endl;liste_d_avion[i]->afficher();}
		cout<<"***************fin d'affichge ************"<<endl;
}
compagnie::~compagnie(void)
{
	for(unsigned int i=0 ;i<liste_des_employer.size();i++)
		delete liste_des_employer[i];
	liste_des_employer.clear();

	for(unsigned int i=0 ;i<liste_d_vols.size();i++)
		delete liste_d_vols[i];
	liste_d_vols.clear();

	for(unsigned int i=0 ;i<liste_d_avion.size();i++)
		delete liste_d_avion[i];
	liste_d_avion.clear();
}
