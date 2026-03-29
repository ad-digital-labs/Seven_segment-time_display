#define P_OK 0
#define P_ERR_RANGE -5
#define P_ERR_VAL -10


#include <iostream>
#include <cctype>
#include <locale>
#include <string>
#include <time.h>


using namespace std;


std::string segment[14]
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
    "    *  * ",
    "      ***",
    "     * * ",
    "         "

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

    if(str.length()>1 && str.length()<20)
    {
        tcount=0;



        for(i=0; i<str.length(); i++)
        {
            if( std::isdigit(str[i])==true || str[i]==':' || str[i]=='-' || str[i]=='/' || str[i]==' ')
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

                }else if(str[i]==' ')
                {
                    x=13;

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

    return res;

};



int display_time()
{
    int res;

    int h;
    int u;
    int m;
    int d;
    int y;

    std::string str01="";

    time_t tm01;
    tm *ctm01;

    tm01=time(NULL);
    ctm01=localtime(&tm01);

    h=ctm01->tm_hour;
    u=ctm01->tm_min;
    m=ctm01->tm_mon;
    d=ctm01->tm_mday;
    y=ctm01->tm_year+1900;

    if(m<10)
    {
        str01+="0";
    };

    str01+=to_string(m);
    str01+="/";

    if(d<10)
    {
        str01+="0";
    };

    str01+=to_string(d) + "/" + to_string(y)+" -";

    if(h<10)
    {
        str01+="0";
    };
    str01+=to_string(h)+":";
    
    if(u<10)
    {
        str01+="0";
    };
    str01+=to_string(u);


    res=display(str01);


    return res;


};




int main(int argc, char* argv[])
{

    int result;

    cout<<endl<<endl;

    result=display_time();

    if(result!=P_OK)
    {
        if(result==P_ERR_RANGE)
        {
            cout<<"ERROR: Date values out of range."<<endl;
        }else if(result==P_ERR_VAL)
        {
            cout<<"Error: Time variiables not in digits."<<endl;
        }else
        {
            cout<<"ERROR: Unexpected error occurred."<<endl;
        };

    };

    cout<<endl<<endl;


    return 0;

};




