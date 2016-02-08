#include "avion.h"
avion::avion(int a,string b,string c,string d,bool e)
{
	nb_place_maxi=a;
	nom=b;
	marque=c;
	modele=d;
	vendus=e;
etat[0][1]="Janv";etat[0][2]="Fivr";etat[0][3]="Mars";etat[0][4]="Avrl";
etat[0][5]="Mai ";etat[0][6]="Juan";etat[0][7]="Jult";etat[0][8]="Ouet";
etat[0][9]="Stmr";etat[0][10]="oct ";etat[0][11]="nvmr";etat[0][12]="dcmb";

etat[1][0]="1 ";etat[2][0]="2 ";etat[3][0]="3 ";etat[4][0]="4 ";etat[5][0]="5 ";etat[6][0]="6 ";
etat[7][0]="7 ";etat[8][0]="8 ";etat[9][0]="9 ";etat[10][0]="10";etat[11][0]="11";etat[12][0]="12";
etat[13][0]="13";etat[14][0]="14";etat[15][0]="15";etat[16][0]="16";etat[17][0]="17";etat[18][0]="18";
etat[19][0]="19";etat[20][0]="20";etat[21][0]="21";etat[22][0]="22";etat[23][0]="23";etat[24][0]="24";
etat[25][0]="25";etat[26][0]="26";etat[27][0]="27";etat[28][0]="28";etat[29][0]="29";etat[30][0]="30";
etat[0][0]="T ";
		for(unsigned int i=1;i<31;i++)
			for(unsigned int j=1;j<13;j++)
				etat[i][j]="disp";                             
}
int avion::existe_avion(vector<avion*>t,string a)
{
for(unsigned int i=0;i<t.size();i++)
		if(t[i]->get_nom()==a)
			return(i);
	return(-1);	
}
void avion::modifier(vector<avion*> t)
{
	int y=1;
	while(y!=0)
	{cout<<" 1 => modifier nom"<<endl<<" 2 => modifier marque"<<endl<<" 3 => modifier modele"<<endl<<" 4 => modifier nombre maximal de passager"<<endl<<" 0 => Quitter"<<endl;
		cout<<"donner votre choix svp : ";cin>>y;
		switch(y)
		{
		case 1:{cout<<"donner nom : ";cin>>nom;
			while(existe_avion(t,nom)!=-1)
				{cout<<"donner nom : ";cin>>nom;
				}
			   break;}
		case 2:{cout<<"donner marque : ";cin>>marque;break;}
		case 3:{cout<<"donner modele : ";cin>>modele;break;}
		case 4:{cout<<"donner carte d'identitee : ";cin>>nb_place_maxi;
				
				break;}
			}
	}
};
void avion::modifier_avion()
{
	int y=1;
	while(y!=0)
	{cout<<" 1 => modifier nom"<<endl<<" 2 => modifier marque"<<endl<<" 3 => modifier modele"<<endl<<" 4 => modifier nombre de place maximal"<<endl<<" 0 => Quitter"<<endl;
	cout<<"donner votre choix svp : ";cin>>y;
	switch(y)
		{
		case 1:{cout<<"donner nom :";cin>>nom;break;}
		case 2:{cout<<"donner marque :";cin>>marque;break;}
		case 3:{cout<<"donner modele :";cin>>modele;break;}
		case 4:{cout<<"donner nombre des places maximal :";cin>>nb_place_maxi;break;}
		
		}
	}
	
}
ostream& operator<< (ostream & o,avion & a)
{o<<a.nb_place_maxi<<endl;o<<a.nom<<endl;o<<a.marque<<endl;o<<a.modele<<endl;o<<a.vendus<<endl;
for(unsigned int i=0;i<31;i++)
		for(unsigned int j=0;j<13;j++)
			o<<a.etat[i][j]<<endl;
return(o);
	}
istream& operator>> (istream & in,avion & a)
{in>>a.nb_place_maxi;in.ignore();getline(in,a.nom,'\n');getline(in,a.marque,'\n');getline(in,a.modele,'\n');in>>a.vendus;in.ignore();
for(unsigned int i=0;i<31;i++)
		for(unsigned int j=0;j<13;j++)
			getline(in,a.etat[i][j],'\n');;
return(in);
	}
void avion::remplir_avion_compagnie()
{	
	cout<<"donner nom : ";cin>>nom;
	cout<<"donner marque : ";cin>>marque;
	cout<<"donner modéle : ";cin>>modele;
	cout<<"donner nombre de place maximal : ";cin>>nb_place_maxi;
}
void avion::remplir_avion(int i,int j)
{
	cout<<"donner nom : ";cin>>nom;
	cout<<"donner marque : ";cin>>marque;
	cout<<"donner modéle : ";cin>>modele;
	cout<<"donner nombre de place maximal : ";cin>>nb_place_maxi;
	etat[i][j]="0000";
}
void avion::afficher()
{	cout<<"donner nom : "<<nom<<endl;
	cout<<"donner marque : "<<marque<<endl;
	cout<<"donner modéle : "<<modele<<endl;
	cout<<"donner nombre de place maximal : "<<nb_place_maxi<<endl;
	cout<<"Calendrier annuel :"<<endl;
	for(unsigned int i=0;i<31;i++)
			{for(unsigned int j=0;j<13;j++)
				cout<<etat[i][j]<<" ";
			cout<<endl;}

}
avion::~avion(void)
{}
