#include <iostream>
using namespace std;

char answer='y';
int id;
float saved;
char name[10];
char pass[10];
int choose=1;
int up=0;
int age;
char address[15];
int found=0;
int findnum;
char answer2='y';
FILE *fp1;


class usee
{
    public : void inserting()
    {
        //do
        //{
         cout<<"Enter the ID :  ";
         cin>>id;
         cout<<"Enter the user name :  ";
         cin>>name;
         cout<<"Enter the age :  ";
         cin>>age;
         cout<<"Enter the password :  ";
         cin>>pass;
         cout<<"Enter the saved money amount :  ";
         cin>>saved;
         cout<<"Enter the address :  ";
         cin>>address;
         //cout<<"Do another [y/n]:  ";
         //cin>>answer;
         //fprintf(fp,"%d\t\t%d\t\t%d\t\t%d\t\t",id,name,age,pass,saved,address);

        //}while(answer!='n');
    }
    public : void updating()
    {

         cout<<"Enter the ID :  ";
         cin>>id;
         cout<<"Enter the user name :  ";
         cin>>name;
         cout<<"Enter the age :  ";
         cin>>age;
         cout<<"Enter the password :  ";
         cin>>pass;
         cout<<"Enter the saved money amount :  ";
         cin>>saved;
         cout<<"Enter the address :  ";
         cin>>address;
         //fprintf(fp,"%d\t\t%d\t\t%d\t\t%d\t\t",id,name,pass,saved);

    }
    char goodbye[28]="Thank for using our service ";
};

int main()
{
    fp1=fopen("BankingData1.txt","w+");
    usee obj1;

    do
    {
        cout<<"Press 1 to insert data : \n";
        cout<<"Press 2 to update data : \n";
        cout<<"Press 3 to find data : \n";
        cout<<"Choose action :  ";
        cin>>choose;
        switch(choose)
        {
        case 1:
        {
            do
            {
                obj1.inserting();
                fprintf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%f\t\t%s\n",id,name,age,pass,saved,address);
                cout<<"Do another [y/n]:  ";
                cin>>answer;

            }while(answer!='n');
            usee.goodbye;
        }break;
        case 2:
        {
            {
                if(!feof(fp1))
                    cout<<"There is no data to be updated : ";
                else
                {
                    cout<<"Enter the number of the line you want to update : ";
                    cin>>up;
                    fseek(fp1,up,SEEK_SET);
                    obj1.updating();
                    fprintf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%f\t\t%s\n",id,name,age,pass,saved,address);
                }
            }
            usee.goodbye;
        }break;
        case 3:
        {
            {
                if(!feof(fp1))
                    cout<<"There is no data to find : ";
                else
                {
                    cout<<"Enter the ID you want to search : ";
                    cin>>findnum;
                    fseek(fp1,0,SEEK_SET);
                    while(!(feof(fp1))&&found==0)
                    {
                        fscanf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%f\t\t%s\n",id,name,age,pass,saved,address);
                        if(findnum==id)
                        {
                            cout<<id<<"\t\t"<<name<<"\t\t"<<age<<"\t\t"<<pass<<"\t\t"<<saved<<"\t\t"<<address<<endl;
                            found=1;
                        }
                    }
                    if(found==0)
                    {
                        cout<<"There is no data associated with the ID you entered \n";
                    }
                }
            }
            usee.goodbye;
        }break;
        default:
            cout<<"May be you have entered the wrong commands ";

        }

        cout<<"Do you want to use the service again : ";
        cin>>answer2;
    }while(answer2!='n');
}
