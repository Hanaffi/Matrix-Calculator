#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#define N 100

using namespace std;

//Matrix Calculator
/*
Operations:
	ADD
	SUB
	Multiply
	Inverse
	Transpose
	determinant
	power
	Division
	
	//Please follow the input format
	ex: [1 2 3;4 5 6;7 8 9]
*/
	

int r1 , c1 , r2 , c2;

float first[100][100];
void input_first(int &row , int &col)
 {
     double numbers=0 , semi_colons=0;
     char c;
     double d;
     cin>>c;
     int rows = 0 , cols = 0;
     while(true){
         string s;
         cin>>s;
        if(s[s.length()-1]==']')
        {
          	s= s.substr(0,s.length()-1);
          	first[rows][cols]=atof(s.c_str());
          	numbers++;
          	break;
        }
        bool check=false;
        for(int k=0;k<s.length();k++)
        {
         	if(s[k]==';')
         	{   semi_colons++;
         		string num1 =  s.substr(0,k); // WHERE TO CUT #1
         		string num2 = s.substr(k+1 , s.length()-k ); // WHERE TO CUT #2
         		first[rows][cols]=atof(num1.c_str()); numbers++;
         		rows++;
         		cols=0;
         		first[rows][cols]=atof(num2.c_str()); numbers++;
         		cols++;
         		check=true;
         		break;
         	}
        }
     	if(!check)
         {first[rows][cols]=atof(s.c_str()); cols++; numbers++;}
     }
     semi_colons++;
     if(ceil(numbers/semi_colons) != floor(numbers/semi_colons))  {cout<<"ERROR" ; exit(0);}
     rows++ , cols++;
 	row=rows , col=cols;
 }

 float second[100][100];
 void input_second(int &row , int &col)
 {
     char c;
    double numbers=0 , semi_colons=0;

     double d;
     cin>>c;
     int rows = 0 , cols = 0;
     while(true){
         string s;
         cin>>s;
          if(s[s.length()-1]==']')
          {
          	s= s.substr(0,s.length()-1);
          	second[rows][cols]=atof(s.c_str());    	numbers++;
          	break;
          }
          bool check=false;
         for(int k=0;k<s.length();k++)
         {
         	if(s[k]==';')
         	{
         	    semi_colons++;
         		string num1 =  s.substr(0,k); // WHERE TO CUT #1
         		string num2 = s.substr(k+1 , s.length()-k ); // WHERE TO CUT #2
         		second[rows][cols]=atof(num1.c_str());    	numbers++;
         		rows++;
         		cols=0;
         		second[rows][cols]=atof(num2.c_str()); 	numbers++;
         		cols++;
         		check=true;
         		break;
         	}
         }
     	if(!check)
         {second[rows][cols]=atof(s.c_str()); cols++; numbers++;}
     }
     rows++ , cols++;
     semi_colons++;
          if(ceil(numbers/semi_colons) != floor(numbers/semi_colons))  {cout<<"ERROR" ; exit(0);}

 	row=rows , col=cols;
 }

 void show_first(int r1 , int c1)
 {
     cout<<'[';
     for(int i=0;i<r1;i++)
     {
         for(int j=0;j<c1;j++)
         {
             cout<<first[i][j];
             if(j!=c1 -1) cout<<" ";
         }
         if(i!=r1-1)
             cout<<";";
     }
     cout<<']';
 }

 void show_second(int r1 , int c1)
 {
     cout<<'[';
     for(int i=0;i<r1;i++)
     {
         for(int j=0;j<c1;j++)
         {
             cout<<second[i][j];
             if(j!=c1 -1) cout<<" ";
         }
         if(i!=r1-1)
             cout<<";";
     }
     cout<<']';
 }

 void ADD(int r1 , int c1 , int r2 , int c2)
 {
     if(r1!=r2 or c1!= c2)
     {
         cout<<"ERROR";
         exit(0);
     }
     for(int i=0;i<r1;i++)
     {
         for(int j=0;j<c1;j++)
         {
             second[i][j]+= first[i][j];
         }
     }
     show_second(r1 , c1);
 }


 void SUB(int r1 , int c1 , int r2 , int c2)
 {
     if(r1!=r2 or c1!= c2)
     {
         cout<<"ERROR";
         exit(0);
     }
     for(int i=0;i<r1;i++)
     {
         for(int j=0;j<c1;j++)
         {
             second[i][j]-= first[i][j];
 			second[i][j]=-1*second[i][j];
         }
     }
     show_second(r1 , c1);
 }
 double third[100][100];
 void MULTIPLY(int r1 , int c1 , int r2 ,int c2)
 {
     if(c1!=r2)
     {
         cout<<"ERROR";
         exit(0);
     }
     for(int i = 0; i < r1; ++i)
         for(int j = 0; j < c2; ++j)
             for(int k = 0; k < c1; ++k)
             {
                 third[i][j] += first[i][k] * second[k][j];
             }

     cout<<'[';
     for(int i=0;i<r1;i++)
     {
         for(int j=0;j<c2;j++)
         {
             cout<<third[i][j];
             if(j!=c2 -1) cout<<" ";
         }
         if(i!=r1-1)
             cout<<";";
     }
     cout<<']';
 }
/*
double det(int n, double mat[100][100])
{
    if(r1!=c1) {cout<<"ERROR";   exit(0);}
    int c, subi , subj , i , j;
    double submat[100][100];
    if(n==2)
        return (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]);
    double d=0;
    for(c = 0; c < n; c++)
        {
            subi = 0;
            for(i = 1; i < n; i++)
            {
                subj = 0;
                for(j = 0; j < n; j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
        d = d + (pow(-1 ,c) * mat[0][c] * det(n - 1 ,submat));
        }

    return d;
}
*/

void POWER(int n)
{
    if(r1!=c1)
    {
        cout<<"ERROR";
        exit(0);
    }
    double two[100][100];
     for(int i=0;i<r1;i++)
            for(int j=0;j<c1;j++)
                two[i][j]=first[i][j];
    for(int i=0;i<n-1;i++)
    {
        double one[100][100];
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c1;j++)
                one[i][j]=first[i][j];
        }


    memset(first , 0 , sizeof first);
     for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c1; ++j)
            for(int k = 0; k < c1; ++k)
            {
                first[i][j] += one[i][k]* two[k][j];
            }



    }
    show_first(r1,c1);
}

void transpose()
{
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            if(first[i][j]==1e9)
            {

                cout<<"ERROR";
                return;
            }
        }

    }
    cout<<"[";
        for(int j=0;j<c1;j++)
        {
            for(int i=0;i<r1;i++)
            {
                cout<<first[i][j];
                if(i!=r1 -1) cout<<" ";
            }
            if(j!=c1-1)
            cout<<";";
        }
        cout<<"]";
}



void XBOX(float b[100][100],float a[100][100],int i,int n){
	int j,l,h=0,k=0;
	for(l=1;l<n;l++)
		for( j=0;j<n;j++){
			if(j == i)
				continue;
			b[h][k] = a[l][j];
			k++;
			if(k == (n-1)){
				h++;
				k=0;
			}
		}
}

float det(float a[100][100],int n){
	int i;
	float b[100][100],sum=0;
	if (n == 1)
return a[0][0];
	else if(n == 2)
return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
	else
		for(i=0;i<n;i++){
			XBOX(b,a,i,n);	// read function
			sum = (float) (sum+a[0][i]*pow(-1,i)*det(b,(n-1)));
		}
return sum;
}

void transpose(float c[100][100],float d[100][100],int n,float det){
	int i,j;
	float b[100][100];
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			b[i][j] = c[j][i];
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			d[i][j] = b[i][j]/det;
}

void cofactor(float a[100][100],float d[100][100],int n,float determinte){
	float b[100][100],c[100][100];
	int l,h,m,k,i,j;
	for (h=0;h<n;h++)
		for (l=0;l<n;l++){
			m=0;
			k=0;
			for (i=0;i<n;i++)
				for (j=0;j<n;j++)
					if (i != h && j != l){
						b[m][k]=a[i][j];
						if (k<(n-2))
							k++;
						else{
							k=0;
							m++;
						}
					}
			c[h][l] = (float) pow(-1,(h+l))*det(b,(n-1));
		}
	transpose(c,d,n,determinte);
}

void inverse(float a[100][100],float d[100][100],int n,float det){
	if(det == 0)
		cout<<"ERROR";
	else if(n == 1)
		d[0][0] = 1;
	else
		cofactor(a,d,n,det);	}








int main()
{

    input_first(r1 , c1);

    char op;
    cin>>op;
    if(op=='+')
    {
        input_second(r2,c2);
        ADD(r1 , c1 , r2 , c2);
    }
    else if(op=='-')
    {
        input_second(r2,c2);
        SUB(r1 , c1 , r2 , c2);
    }
    else if(op=='*')
    {
        input_second(r2,c2);
        MULTIPLY(r1 , c1 , r2 , c2);

    }
    else if(op=='D')
    {
        if(r1!=c1) {cout<<"ERROR"; return 0;}
        return (cout<<(float)det(first,r1) , 0);
    }
    else if(op=='T')
    {
        transpose();
    }
    else if(op=='^')
    {
        int x;
        cin>>x;
        POWER(x);
    }
    else if(op=='I')
    {
        if(r1!=c1) {cout<<"ERROR"; return 0;}
        float d[100][100],deter;
        deter = (float) det(first,r1);
        inverse(first,d,r1,deter);
        for(int i=0;i<r1;i++)
            for(int j=0;j<c1;j++)
                second[i][j]= round( d[i][j] * 10000.0 ) / 10000.0;



        show_second(r1,c1);
    }
    else if(op=='/')
    {
        input_second(r2,c2);
        float d[100][100],deter;
        deter = (float) det(second,r1);
        inverse(second,d,r1,deter);
        for(int i=0;i<r1;i++)
            for(int j=0;j<c1;j++)
                second[i][j]= round( d[i][j] * 10000.0 ) / 10000.0;
        MULTIPLY(r1,c1,r2,c2);

    }
    return 0;
}


