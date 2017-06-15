#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int flag=0;
int x=0;
int k=1;
int global=0;
void psarray(string r,int m,int *ps);
void KMPsearch(string s,vector<string> Pagestring )
{
	vector<string>::iterator i;
    x=1;
	for(i=Pagestring.begin();i<Pagestring.end();i++,++x)
	{	  
         int m=s.length();
		int n=(*i).length();
		int ps[m];
		psarray(s,m,ps);
		int p=0;
		int q=0;
		while(p<n)
		{
			if(s[q]==(*i)[p])
			{
				q++;
				p++;
				
			}
			if(q==m)
			{
				cout<<"page:"<<global<<','<<"line:"<<x<<endl;
				flag=1;
				q=ps[q-1];
			}
			else if((p<n)&&(s[q]!=(*i)[p]))
			{
				if(q!=0)
				q=ps[q-1];
				else
				p=p+1;
				
			}
		}
	}
	
}
void psarray(string r,int m,int *ps)
{
	int len=0;
	ps[0]=0;
	int i=1;
	while(i<m)
	{
		if(r[i]==r[len])
		{
			len++;
			ps[i]=len;
			i++;
			
		}
		else
		{
			if(len!=0)
			len=ps[len-1];
			else
			{
				ps[i]=0;
				i++;
			}
		}
		
	}
}

void occurence(string search,vector<string> datastring)
{
	
	KMPsearch(search,datastring);	
}
int main()
{   
    string line;
    string page="page_";
	ifstream ifile("queries.txt",ios::in);
 	vector<string> queryfile;
    vector<string> Dataoffile;
    vector<string>::iterator t;
    if(!ifile)
    cout<<"Error....query file not found"<<endl;
    while (std::getline(ifile, line))
    {
        queryfile.push_back(line);
    }
    for(t=queryfile.begin();t!=queryfile.end();t++)
    {   k=1;
    	cout<<"WORD:"<<*t<<endl;
    	cout<<"Occurences:"<<endl;
     for(int l=1;l<5;l++)
     {
    global=l;
	ifstream infile("page_"+to_string(l)+".txt",ios::in);
    if(!infile)
	cout<<"error..file not found"<<endl;
    
    while (std::getline(infile, line))
    {
        Dataoffile.push_back(line);
    }
   	occurence(*t,Dataoffile);	
	infile.close();
	Dataoffile.clear();
	++k;
      }
     if((flag==0)&&(k==5))
	 cout<<"none"<<endl;
	 if(flag==1)
	 flag=0;
   }
}
