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


/*
Complex Matrix Calculator:
	Add
	Sub
	Multiply
	
	
	//Please follow the input format
	ex: [0+1i 2+3i;4+5i 6+7i]
*/


class Complex
{
	public:
	float real;
	float imag;
	Complex() {real=imag=0;}
};

int main()
{
    Complex A[100] , B[100] ,res[100];

	int x; char temp,op;
	string m;
	getline(cin , m);
	int cnt =0,semi_colons=0;
	for(int i=0;i<m.length();i++)
	{
	    if(m[i]==';') break;
        if(isspace(m[i])) cnt++;
	}
	for(int i=0;i<m.length();i++)
	{
	    if(m[i]==';') semi_colons++;
	}

	semi_colons++;
	cnt++;
    stringstream fin(m);

	fin>>temp;
	for(int i=0;i<cnt*semi_colons;i++)
    {
        if(i!=0 and i%cnt==0) fin>>temp;
        fin>>A[i].real>>A[i].imag>>temp;
    }
	fin>>temp>>temp;

	cin>>op;















    cin.ignore();
    string k;
    getline(cin , k);
    int cnt2 =0,semi_colons2=0;


    for(int i=0;i<k.length();i++)
	{
	    if(k[i]==';') break;
        if(isspace(k[i])) cnt2++;
	}
	for(int i=0;i<k.length();i++)
	{
	    if(k[i]==';') semi_colons2++;
	}

	semi_colons2++; cnt2++;
    if((semi_colons2!=semi_colons and op!='*') or (cnt!=cnt2 and op!='*')) return cout<<"ERROR" ,0;



    stringstream fun(k);
    fun>>temp;
    for(int i=0;i<cnt2*semi_colons2;i++)
    {
        if(i!=0 and i%cnt2==0) fun>>temp;
        fun>>B[i].real>>B[i].imag>>temp;
    }
    fun>>temp;


    if(op=='+' or op=='-')
    {
        for(int i=0;i<cnt*semi_colons;i++)
        {
            if(op=='+')
            {
                res[i].real = A[i].real + B[i].real;
                res[i].imag = A[i].imag + B[i].imag;
            }
            else if(op=='-')
            {
                res[i].real = A[i].real - B[i].real;
                res[i].imag = A[i].imag - B[i].imag;
            }

        }


         cout<<"[";
        for(int i=0;i<cnt*semi_colons;i++)
        {
            if(i!=0 and i%cnt==0) cout<<";";
            else if(i%cnt!=0)
                cout<<" ";
            cout<<res[i].real;
            if(res[i].imag >0) cout<<"+";
           else if(res[i].imag== 0) cout<<"+";
            cout<<res[i].imag<<"i";
        }
        cout<<"]";
        return 0;
    }

    if(cnt!=semi_colons2) return cout<<"ERROR" , 0;
    float real_1[100][100] , img_1[100][100] , real_2[100][100] , img_2[100][100];
    for(int i=0;i<semi_colons;i++)
        for(int j=0;j<cnt;j++)
            real_1[i][j]=A[i*cnt+j].real;

    for(int i=0;i<semi_colons;i++)
        for(int j=0;j<cnt;j++)
            img_1[i][j]=A[i*cnt+j].imag;


     for(int i=0;i<semi_colons2;i++)
        {
            for(int j=0;j<cnt2;j++)
            {
                real_2[i][j]=B[i*cnt2+j].real;
            }
        }

     for(int i=0;i<semi_colons2;i++)
        for(int j=0;j<cnt2;j++)
            img_2[i][j]=B[i*cnt2+j].imag;

    //r1 = semi_colons      //c1 = cnt
    //r2 = semi_colons2     //c2 = cnt2





    //Getting the results
    float res_real[100][100] , res_img[100][100];
    for(int i = 0; i < semi_colons; ++i)
        for(int j = 0; j < cnt2; ++j)
            for(int k = 0; k < cnt; ++k)
             {
                 res_real[i][j] += real_1[i][k] * real_2[k][j];
                 res_real[i][j] -= img_1[i][k] * img_2[k][j];
                 //cout<<  real_1[i][k]<<" "<<real_2[k][j]<<" "<<   img_1[i][k]<<" "<<    img_2[k][j]<<" "<<   res_real[i][j]<<endl;
             }
    for(int i = 0; i < semi_colons; ++i)
        for(int j = 0; j < cnt2; ++j)
            for(int k = 0; k < cnt; ++k)
             {
                 res_img[i][j] += real_1[i][k] * img_2[k][j];
                 res_img[i][j] += img_1[i][k] * real_2[k][j];
             }
    //convert to RES
     for(int i = 0; i < semi_colons; ++i)
        for(int j = 0; j < cnt2; ++j)
            res[i*cnt2+j].real = res_real[i][j];

      for(int i = 0; i < semi_colons; ++i)
        for(int j = 0; j < cnt2; ++j)
            res[i*cnt2+j].imag = res_img[i][j];





    cout<<"[";
    for(int i=0;i<cnt2*semi_colons;i++)
    {
        if(i!=0 and i%cnt2==0) cout<<";";
        else if(i%cnt2!=0)
            cout<<" ";
        cout<<res[i].real;
        if(res[i].imag >0) cout<<"+";
       else if(res[i].imag== 0) cout<<"+";
        cout<<res[i].imag<<"i";
    }
    cout<<"]";

    return 0;
}


