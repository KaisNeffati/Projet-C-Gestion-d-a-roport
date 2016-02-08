#include<iostream>
#include<fstream>
using namespace std;
#include<string>
#include<vector>
#include"passager.h"
#include"compagnie.h"
#include"employer.h"

int connexion_exist(vector<passager*> t,string l,string v)
{
	for(unsigned int i=0;i<t.size();i++)
		if ((t[i]->get_login()==l)&&(t[i]->get_mots_d_pass()==v))
			return(i);
	return(-1);
}
void affiche_vols_place_existant(vector<compagnie *> t)
{int s=1;
for(unsigned int i=0;i<t.size();i++)
	for(unsigned int j=0;j<t[i]->get_liste_vole().size();j++)
		if (t[i]->get_liste_vole()[j]->existe_place()>0)
		{cout<<"vols numero "<<s<<" :"<<endl;
			cout<<"**********************************************************"<<endl;
			t[i]->get_liste_vole()[j]->afficher_vols_client();
			cout<<"**********************************************************"<<endl;
			s++;}
	
}
int trouver_vols_place(vector<compagnie *> t,int e)
{
for(unsigned int i=0;i<t.size();i++)
	for(unsigned int j=0;j<t[i]->get_liste_vole().size();j++)
		if (t[i]->get_liste_vole()[j]->existe_place()>0)
			if (e==t[i]->get_liste_vole()[j]->get_num_vols())
				return(j);
	return(-1);
	

}
int trouver_comp(vector<compagnie *> t,int e)
{for(unsigned int i=0;i<t.size();i++)
	for(unsigned int j=0;j<t[i]->get_liste_vole().size();j++)
		if (t[i]->get_liste_vole()[j]->existe_place()>0)
			if (e==t[i]->get_liste_vole()[j]->get_num_vols())
				return(i);
	return(-1);
	
}
int rechercher_nom(vector<compagnie*>t,string m)
{
	for(unsigned int i=0;i<t.size();i++)
		if(t[i]->get_nom_compagnie()==m)
			return(i);
	return(-1);
}
int rechercher_cin(vector<passager*> t,long m)
{
		for(unsigned int i=0;i<t.size();i++)
		if(t[i]->get_carte_id()==m)
			return(i);
	return(-1);
}
void main()
{	
	vector<passager*> liste_des_passager;
	vector<compagnie *> liste_des_compagnie;
	vector<employer *> liste_des_employer;
	vector<avion*> liste_des_avion;
	
	while(!liste_des_passager.empty())
	{
		liste_des_passager.pop_back();
	}
	passager* p;
	ifstream fi1("D:\\passager.txt");
	if(!fi1){cout<<"";};
	if (fi1)
	{
	while(!fi1.eof())
	{
		p=new passager();
		fi1>> *p;
		liste_des_passager.push_back(p);
	}
	
	fi1.close();

	liste_des_passager.pop_back();
	}
	while(!liste_des_compagnie.empty())
	{
		liste_des_compagnie.pop_back();
	}
	compagnie* c;
	ifstream fi2("D:\\compagnie.txt");
	if(!fi2){cout<<"";};
	if (fi2)
	{
	while(!fi2.eof())
	{
		c=new compagnie();
		fi2>> *c;
		liste_des_compagnie.push_back(c);
	}
	
	fi2.close();
	liste_des_compagnie.pop_back();
	}
		while(!liste_des_employer.empty())
	{
		liste_des_employer.pop_back();
	}
	employer* e;
	ifstream fi3("D:\\employer.txt");
	if(!fi3){cout<<"";};
	if (fi3)
	{
	while(!fi3.eof())
	{
		e=new employer();
		fi3>> *e;
		liste_des_employer.push_back(e);

	}
	
	fi3.close();
	liste_des_employer.pop_back();
	}
	while(!liste_des_avion.empty())
	{
		liste_des_avion.pop_back();
	}
	avion* a;
	ifstream fi4("D:\\joueurs.txt");
	if(!fi4){cout<<"";};
	if (fi4)
	{
	while(!fi4.eof())
	{
		a=new avion();
		fi4>> *a;
		liste_des_avion.push_back(a);
	}
	
	fi4.close();
	liste_des_avion.pop_back();
	}
	cout<<"*********************************************************************"<<endl;
	cout<<"****************Bienvenus chez gestion d'aereport********************"<<endl;

	cout<<"*********************************************************************"<<endl;
	int x=1;
	
	while(x!=0)
	{cout<<" 1 => gestion de point de vue administrative"<<endl<<" 2 => gestion de point de vue client"<<endl<<" 0 => Quitter"<<endl;
	cout<<"donner votre choix svp : ";cin>>x;
		switch(x)
		{
		case 1:{cout<<"**********************Bienvenus admin**************************"<<endl;
				int y=1;
				while(y!=0)
				{cout<<" 1 => Gestion des compagnie"<<endl<<" 2 => Gestion des passager"<<endl<<" 0 => Quitter "<<endl;
				cout<<"donner votre choix svp : ";cin>>y;
					switch(y)
					{
					case 1:
						{int q=1;
						while(q!=0)
						{	cout<<"*********************************************************************"<<endl;
							cout<<" 1 => ajouter compagnie"<<endl<<" 2 => modifier compagnie"<<endl<<" 3 => supprimer compagnie"<<endl<<" 4 => afficher compagnie "<<endl<<" 5 => afficher liste des compagnie"<<endl<<" 0 => Quitter"<<endl;
							cout<<"donner votre choix svp : ";cin>>q;
							switch(q)
							{
							case 1:
								{	cout<<"*********************************************************************"<<endl;
								compagnie *c=new compagnie();
								c->remplissage_compagnie(liste_des_compagnie,liste_des_employer,liste_des_avion,liste_des_passager);
								liste_des_compagnie.push_back(c);
								cout<<"fin d'ajoue de compagnie"<<endl;
									cout<<"*********************************************************************"<<endl;
								   break;}
							case 2:
								{	cout<<"*********************************************************************"<<endl;
									string m;
								cout<<"donner nom de compagnie a modifier"<<endl;
								cin>>m;
									if(rechercher_nom(liste_des_compagnie,m)!=-1)
									{
										liste_des_compagnie[rechercher_nom(liste_des_compagnie,m)]->modifier_compagnie(liste_des_compagnie,liste_des_employer,liste_des_avion,liste_des_passager);	
											cout<<"fin de modification"<<endl;
									}
									else cout<<"compagnie inexistant"<<endl;

								cout<<"*********************************************************************"<<endl;
								   break;}
							case 3:
								{	cout<<"*********************************************************************"<<endl;
									string m;
								cout<<"donner nom de compagnie a supprimer"<<endl;
								cin>>m;
									if(rechercher_nom(liste_des_compagnie,m)!=-1)
									{	
										liste_des_compagnie[rechercher_nom(liste_des_compagnie,m)]->supprission_compagnie(liste_des_compagnie);
										liste_des_compagnie.erase(liste_des_compagnie.begin()+rechercher_nom(liste_des_compagnie,m));
										cout<<"fin de supprission"<<endl;
									}
									else cout<<"compagnie inexistant"<<endl;
								  	cout<<"*********************************************************************"<<endl;
								break;}
							case 4:
								{	cout<<"*********************************************************************"<<endl;
								string m;
								cout<<"donner nom de compagnie a afficher"<<endl;
								cin>>m;
								if(rechercher_nom(liste_des_compagnie,m)!=-1)
									{
										liste_des_compagnie[rechercher_nom(liste_des_compagnie,m)]->afficher_compagnie();
										cout<<"fin de affichage"<<endl;
									}
									else cout<<"compagnie inexistant"<<endl;
									cout<<"*********************************************************************"<<endl;
								   break;}
							case 5:{
										cout<<"*********************************************************************"<<endl;
									for(unsigned int i=0;i<liste_des_compagnie.size();i++)
										liste_des_compagnie[i]->afficher_compagnie();
									cout<<"fin de affichage liste"<<endl;
								   	cout<<"*********************************************************************"<<endl;
								   break;}
							
							
							}

							cout<<"*********************************************************************"<<endl;
						
						}
							
						   break;}
					case 2:
						{int q=1;
						while(q!=0)
						{	cout<<"*********************************************************************"<<endl;
						cout<<" 1 => modifier passager"<<endl<<" 2 => supprimer passager"<<endl<<" 3 => afficher passager"<<endl<<" 4 => afficher liste des passager"<<endl<<" 0 => Quitter"<<endl;
						cout<<"donner votre choix svp : ";cin>>q;
						switch(q)
						{
						case 1:
							{	cout<<"*********************************************************************"<<endl;
								int m;
								cout<<"donner carte d'identitée de passager a modifer"<<endl;
								cin>>m;
								if(rechercher_cin(liste_des_passager,m)!=-1)
									{
										liste_des_passager[rechercher_cin(liste_des_passager,m)]->modifier_passager(liste_des_passager);
										cout<<"fin de modification"<<endl;
									}
									else cout<<"passager inexistant"<<endl;
								cout<<"*********************************************************************"<<endl;						   
							   break;}
						case 2:
							{	cout<<"*********************************************************************"<<endl;
								int m;
								cout<<"donner carte d'identitée de passager a supprimer"<<endl;
								cin>>m;
								if(rechercher_cin(liste_des_passager,m)!=-1)
									{
										for(unsigned int i=0;i<liste_des_compagnie.size();i++)
										liste_des_compagnie[i]->supprimer_passager(liste_des_passager[rechercher_cin(liste_des_passager,m)]);
										liste_des_passager.erase(liste_des_passager.begin()+rechercher_cin(liste_des_passager,m));
										cout<<"fin de supprission"<<endl;
									}
									else cout<<"passager inexistant"<<endl;
									cout<<"*********************************************************************"<<endl;
							   break;}
						case 3:
							{	cout<<"*********************************************************************"<<endl;
								int m;
								cout<<"donner carte d'identitée de passager a afficher"<<endl;
								cin>>m;
								if(rechercher_cin(liste_des_passager,m)!=-1)
									{
										liste_des_passager[rechercher_cin(liste_des_passager,m)]->afficher();
										cout<<"fin de affichage"<<endl;
									}
									else cout<<"passager inexistant"<<endl;
									cout<<"*********************************************************************"<<endl;
							   break;}
						case 4:
							{
									cout<<"*********************************************************************"<<endl;
									for(unsigned int i=0;i<liste_des_passager.size();i++)
										liste_des_passager[i]->afficher();
									cout<<"fin de affichage liste"<<endl;
								  	cout<<"*********************************************************************"<<endl;
							   break;}
						}

						
						
						}





						   }
					}
				}
			 break;}
		case 2:
			{cout<<"***********************Bienvenus cher client **********************"<<endl;
			int y=1;
			
			while(y!=0)
			{	cout<<"*********************************************************************"<<endl;
			cout<<" 1 => connexion "<<endl<<" 2 => s'inscrire"<<endl<<" 0 => Quitter"<<endl;
			cout<<"donner votre choix svp : ";cin>>y;
				switch(y)
				{
				case 1:
					{	string l,m;
						cout<<" LOGIN : ";cin>>l;
						cout<<" MOTS DE PASSE : ";cin>>m;
						if (connexion_exist(liste_des_passager,l,m)!=-1)
						{
							int p=connexion_exist(liste_des_passager,l,m);
							cout<<"********Bienvenus Chez Nous ********"<<endl;

							int z=1;
							while(z!=0)
							{cout<<" 1 => profile"<<endl<<" 2 => Consulter la liste des vols "<<endl<<" 0 => Quitter"<<endl;
							 cout<<"donner votre choix svp : ";cin>>z;
								switch(z)
								{
								case 1:{liste_des_passager[p]->afficher();	cout<<"*********************************************************************"<<endl;
										int b=1;
										while(b!=0)
										{cout<<" 1 => modifier profile"<<endl<<" 2 => liste de Reservation"<<endl<<" 0 => Quitter"<<endl;
										cout<<"donner votre choix svp : ";cin>>b;
										switch(b)
										{
										case 1:
												{liste_des_passager[p]->modifier_passager(liste_des_passager);
												cout<<"************fin de modification****************"<<endl;break;}
										case 2:{for(unsigned int i=0;i<liste_des_compagnie.size();i++)
												for(unsigned int j=0;j<liste_des_compagnie[i]->get_liste_vole().size();j++)
													for(unsigned int r=0;r<liste_des_compagnie[i]->get_liste_vole()[j]->get_liste_d_passager().size();r++)
														if(liste_des_compagnie[i]->get_liste_vole()[j]->get_liste_d_passager()[r]->get_carte_id()==liste_des_passager[p]->get_carte_id())
															{	cout<<"*********************************************************************"<<endl;
															liste_des_compagnie[i]->get_liste_vole()[j]->afficher_vols_client();
																cout<<"*********************************************************************"<<endl;}
											break;}
										}
										}
									   break;}
								case 2:{affiche_vols_place_existant(liste_des_compagnie);break;}
								}
							}
							
						  }
						cout<<"Compte introuvable.. vous devez s'inscrire "<<endl;
						
					   break;}
				case 2:
					{passager *C = new passager();
					C->remplir_passager(liste_des_passager);
					liste_des_passager.push_back(C);
					
					cout<<"*******************inscription terminer******************"<<endl;
					   break;}
			     }
			    }
			   }
		}
	}
	ofstream fo1("D:\\compagnie.txt",ios::trunc);
	if(!fo1){cout<<"\n error";};
	for (unsigned int i=0;i<liste_des_compagnie.size();i++)
	{
		fo1<<*(liste_des_compagnie[i]);
	}
	fo1.close();
		ofstream fo2("D:\\passager.txt",ios::trunc);
	if(!fo2){cout<<"\n error";};
	for (unsigned int i=0;i<liste_des_passager.size();i++)
	{
		fo2<<*(liste_des_passager[i]);
	}
	fo2.close();
		ofstream fo3("D:\\employer.txt",ios::trunc);
	if(!fo3){cout<<"\n error";};
	for (unsigned int i=0;i<liste_des_employer.size();i++)
	{
		fo3<<(*liste_des_employer[i]);
	}
	fo3.close();
		ofstream fo4("D:\\avion.txt",ios::trunc);
	if(!fo4){cout<<"\n error";};
	for (unsigned int i=0;i<liste_des_avion.size();i++)
	{
		fo4<<*(liste_des_avion[i]);
	}
	fo4.close();



system("pause");
}