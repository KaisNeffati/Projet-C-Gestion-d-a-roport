#include"temp.h"
ostream& operator<< (ostream & o,temp & t)
	{o<<t.min;o<<t.heur;return(o);}
istream & operator>> (istream & in,temp & t)
	{in>>t.min;in.ignore();in>>t.heur;in.ignore();return(in);}