#define P_OK 0
#define P_ERR_RANGE -5
#define P_ERR_VAL -10


#include <iostream>
#include <cctype>
#include <locale>
#include <string>


using namespace std;


std::string segment[13]
{
    " _ | ||_|",
    "     |  |",
    " _  _||_ ",    
    " _  _| _|",
    "   |_|  |",
    " _ |_  _|",
    "   |_ |_|",
    " _   |  |",
    " _ |_||_|",
    " _ |_|  |",
    " *  *  * ",
    "   ***   ",
    "  * * *  "
};

int display(std::string str)
{

    int res;
    int tcount;

    int i;
    int j;
    int k;

    int x;

    std::string ln01="";
    std::string ln02="";
    std::string ln03="";

    if(str.length()>1 && str.length()<15)
    {
        tcount=0;



        for(i=0; i<str.length(); i++)
        {
            if( std::isdigit(str[i])==true || str[i]==':' || str[i]=='-' || str[i]=='/' )
            {

                if(isdigit(str[i])==true)
                {
                    x=str[i]-'0';

                }else if(str[i]==':')
                {
                    x=10;
                }else if(str[i]=='-')
                {
                    x=11;

                }else if(str[i]=='/')
                {
                    x=12;

                };


                k=0;
                while(k<3)
                {
                    ln01+=segment[ x ][k];
                    ln02+=segment[ x ][k+3];
                    ln03+=segment[ x ][k+6];

                    k++;
                };


            }else
            {
                tcount++;

            };

            ln01+=" ";
            ln02+=" ";
            ln03+=" ";



        };



        if(tcount==0)
        {
            cout<<ln01<<std::endl;
            cout<<ln02<<std::endl;
            cout<<ln03<<std::endl;

            res=P_OK;

        }else
        {
            res=P_ERR_VAL;

        };



        

    }else
    {
        res=P_ERR_RANGE;
    };






    res=P_OK;

    return res;

};


int main(int argc, char* argv[])
{

    string str;

    int result;

    cout<<"Enter a string of digits (max 14 characters): ";
    cin>>str;

    result=display(str);

    if(result!=P_OK)
    {
        if(result==P_ERR_RANGE)
        {
            cout<<"Error: Input string length must be between 1 and 14 characters."<<endl;
        }else if(result==P_ERR_VAL)
        {
            cout<<"Error: Input string contains invalid characters. Only digits, ':', '-', and '/' are allowed."<<endl;
        }else
        {
            cout<<"An unknown error occurred."<<endl;
        };

    };


    return 0;

};




