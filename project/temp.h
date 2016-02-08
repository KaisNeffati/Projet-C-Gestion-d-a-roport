#pragma once
#include<fstream>
#include<iostream>
using namespace std;
class temp
{protected:
	int min;
	int heur;
public:
	temp(int a=0,int b=0){min=a;heur=b;};
friend ostream& operator<< (ostream & o,temp & t);
friend istream& operator>> (istream & in,temp & t);
	void remplir_temp()
	{cout<<"donner min"<<endl;
	cin>>min;
	while(min<0||min>60)
	{
		cout<<"donner min"<<endl;
	cin>>min;
	}
	cout<<"donner heur"<<endl;
	cin>>heur;
	while(heur<1||heur>12)
	{
		cout<<"donner heur"<<endl;
	cin>>heur;
	}
	}
	void afficher(){cout<<"horaire : "<<min<<":"<<heur<<endl;}
	~temp(void){};
};
