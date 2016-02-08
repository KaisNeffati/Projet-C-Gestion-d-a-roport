#include "passager.h"

passager::passager(int g,int h,int i,string a,string b,string c,string d,long e,long f,string j,string k):personne(g,h,i,a,b,c,d,e,f)
{
	login=j;
	mots_d_pass=k;
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
void passager::afficher()
{personne::afficher();
for(unsigned int i=0;i<31;i++)
			{for(unsigned int j=0;j<13;j++)
				cout<<etat[i][j]<<" ";
				cout<<endl;}
}
void passager::modifier_passager(vector<passager*> t)
{
	int y=1;
	while(y!=0)
	{cout<<" 1 => modifier nom"<<endl<<" 2 => modifier prenom"<<endl<<" 3 => modifier adress"<<endl<<" 4 => modifier email"<<endl<<" 5 => modifier carte d'identitee"<<endl<<" 6 => modifier  carte bancaire"<<endl<<" 7 => modifier date de naissance"<<endl<<" 8 => modifier login"<<endl<<" 9 => modifier mots de passe"<<endl<<" 0 => Quitter"<<endl;
	cout<<"donner votre choix svp : ";cin>>y;	
	switch(y)
		{
		case 1: {cout<<"donner nom : ";cin>>nom;break;}
		case 2:{cout<<"donner prenom : ";cin>>prenom;break;}
		case 3:{cout<<"donner adress : ";cin>>adress;break;}
		case 4:{cout<<"donner email : ";cin>>email;break;}
		case 5:{
			long a;cout<<"donner carte d'identitee : ";cin>>a;
			while(exist_carte_identitee(t,a)!=-1)
			   {cout<<"donner carte d'identitee : ";cin>>a;}
			carte_d_identitee=a;break;
			   }
		case 6:{cout<<"donner carte bancaire : ";cin>>carte_bancaire;break;}
		case 7:{cout<<"donner date de naissance : "<<endl;date_de_naissance.remplir_date();break;}
		case 8:{cout<<"donner login : ";cin>>login;break;}
		case 9:{cout<<"donner mots de passe : ";cin>>mots_d_pass;break;}

		};
};
	

}
int passager::exist_carte_identitee(vector<passager*> t,long a)
{
	for(unsigned int i=0;i<t.size();i++)
		if(t[i]->get_carte_id()==a)
			return(i);
	return(-1);
}
void passager::remplir_passager(vector<passager*> tpassager)
{
	cout<<"donner nom : ";cin>>nom;
	cout<<"donner prenom : ";cin>>prenom;
	cout<<"donner adress : ";cin>>adress;
	cout<<"donner email : ";cin>>email;
	cout<<"donner carte d'identitee : ";cin>>carte_d_identitee;
	while(exist_carte_identitee(tpassager,carte_d_identitee)!=-1)
	{
	cout<<"donner carte d'identitee : ";cin>>carte_d_identitee;
	}
	cout<<"donner carte bancaire : ";cin>>carte_bancaire;
	cout<<"donner date de naissance : "<<endl;date_de_naissance.remplir_date();
	cout<<"donner login : ";cin>>login;
	cout<<"donner mots de passe : ";cin>>mots_d_pass;
};
ostream& operator<< (ostream & o, passager & p)
	{
		o<<p.nom<<endl; o<<p.prenom<<endl;
		o<<p.email<<endl;o<<p.adress<<endl;
	o<<p.carte_d_identitee<<endl;o<<p.carte_bancaire<<endl;
	o<<p.date_de_naissance<<endl;
	o<<p.login<<endl;o<<p.mots_d_pass;
	for(unsigned int i=0;i<31;i++)
		for(unsigned int j=0;j<13;j++)
			o<<p.etat[i][j]<<endl;
	return(o);
	}
istream& operator>> (istream & in, passager & p)
	{
	getline(in,p.nom,'\n'); getline(in,p.prenom,'\n');
	getline(in,p.email,'\n');getline(in,p.adress,'\n');
	in>>p.carte_d_identitee;in.ignore();in>>p.carte_bancaire;in.ignore();
	in>>p.date_de_naissance;
	getline(in,p.login,'\n');getline(in,p.mots_d_pass,'\n');
	for(unsigned int i=0;i<31;i++)
		for(unsigned int j=0;j<13;j++)
			getline(in,p.etat[i][j],'\n');
	return(in);

	}
passager::~passager(void)
{
}