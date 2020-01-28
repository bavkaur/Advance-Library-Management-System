#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<windows.h>
#include <stdlib.h>
#include<time.h>
#include <unistd.h>
#include<limits>
using namespace std;
void cover();
void  showotp();

//**************************** Generate CAPTCHA  *********************
string generatecaptcha()
{
    srand(time(NULL));
    // All possible characters of my OTP
    string str = "abcdefghijklmnopqrstuvwxyzABCD"
               "EFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int n = str.length();

    // String to hold my OTP
    string OTP;

    for (int i=1; i<=6; i++)
        OTP.push_back(str[rand() % n]);

    return(OTP);
}
//*******************************************************************************

//****************************Generate Random Password ****************
int selectArray()
{
	int *j=(int*)malloc(sizeof(int));

	int i=int(j);
	i=i%5;
	if(i==0)
		i++;
	return i;
}
int getKey()
{
	int *i=(int *)malloc(sizeof(int));
	int key=int(i);
	key=key%26;
	return key;
}
string generateRandomPassword()
{
	string password="";
	string alphabet="abcdefghijklmnopqrstuvwxyz";
	string ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string s_symbol="!@#$%&";
	string number="0123456789";

	int key,count_alphabet=0,count_ALPHABET=0,count_number=0,count_s_symbol=0;
	int count=0;
	while(count<10)
	{
		int k=selectArray();
		if(count==0)
		{
			k=k%3;
			if(k==0)
				k++;
		}
		switch(k)
		{
			case 1:
        if((count_alphabet==2)&&(count_number==0||count_ALPHABET==0||count_ALPHABET==1||count_s_symbol==0))
				break;
			key=getKey();
			password=password+alphabet[key];
			count_alphabet++;
			count++;
			break;

			case 2:
			if((count_ALPHABET==2)&&(count_number==0||count_alphabet==0||count_alphabet==1||count_s_symbol==0))
				break;
			key=getKey();
			password=password+ALPHABET[key];
			count_ALPHABET++;
			count++;
			break;

			case 3:
			if((count_number==1)&&(count_alphabet==0||count_alphabet==1||count_ALPHABET==1||count_ALPHABET==0||count_s_symbol==0))
				break;

			key=getKey();
			key=key%10;
			password=password+number[key];
			count_number++;
			count++;
			break;

			case 4:
			if((count_s_symbol==1)&&(count_alphabet==0||count_alphabet==1||count_ALPHABET==0||count_ALPHABET==1||count_number==0))
				break;
			key=getKey();
			key=key%6;
			password=password+s_symbol[key];
			count_s_symbol++;
			count++;
			break;
		}
	}
	return password;
}


//**********************************************************************
char temp[25];
COORD coord = {0, 0};

void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//********************** OTP Generator ***********************************

int selArr()
{
	int *j=(int*)malloc(sizeof(int));

	int i=int(j);
	i=i%5;
	if(i==0)
		i++;
	return i;
}

int GKey()
{
	int *i=(int *)malloc(sizeof(int));

	int key=int(i);
	key=key%10;
	return key;
}
string generateOTP()
{
	string otp="";
	string number="0123456789";
	int key ;
	int count=0;
	while(count<6)
	{
      int k=selArr();
		if(count==0)
		{
			k=k%3;
			if(k==0)
				k++;
		}
		switch(k)
		{
			case 1:
			key=GKey();
			otp=otp+number[key];
			count++;
			break;

			case 2:
			key=GKey();
			otp=otp+number[key];
			count++;
			break;

			case 3:
			key=GKey();
			key=key%10;
			otp=otp+number[key];
			count++;
			break;

			case 4:
			key=GKey();
			key=key%10;
			otp=otp+number[key];
			count++;
			break;
		}
	}

return otp;
}

//**********************************************************************

//****************** Password validity **************************************
int checkvalidity( char* pass)
{
	int length = strlen(pass);

	if(length<8 || length>25)
    {
        cout<<"Password Length Must be Between 8 and 25. "<<endl;
        return 0;

    }
    else
    {

	int i=0;
	int isup =0 , islow=0 , isdig=0 , isspce=0;

	while(i<length)
	{
	    if (isupper( pass[i]))
      	    { isup++; }
       	else if(islower(pass[i]))
		    { islow++; }
		else if(isdigit(pass[i]))
			{ isdig++; }
		else if(isspace(pass[i]))
			{ isspce++; }
		i++;
	}
		if(isup==0 || islow==0 || isdig==0 )
		{
			{ cout<<"\t\n Your password misses: "; }
		}
		if(isup==0)
	    	{ cout<<"\t\n                       an upper case alphabet. "; }
		if(islow==0)
		    { cout<<"\t\n                       a lower case alphabet. "; }
		if(isdig==0)
			{ cout<<"\t\n                       a digit. "; }
		if(isspce!=0)
    		{ cout<<"\t\n Your password cannot have anything other than uppercase alphabets, lowercase alphabets and digits. "; }

		if(isup==0 || islow==0 || isdig==0 || isspce!=0 )
			{
				return 0;
			}
		else{
				return 1;
			}
    }
}
//*****************************************************************
//************************************************

//***************Class User***********************
class user{
public:
char full_name[20];
char name[10];
char password[25];
char issued_book_no[3];
char email[25];
long mobile;


void create_user()
{
  cout<<"\n\n\tEnter Full Name:";
  gets(full_name);
     cin.sync();
  cout<<"\n\tEnter User Name:";
  gets(name);
     cin.sync();
  cout<<"\n\n\tEnter your email ID: ";
  gets(email);
     cin.sync();
  cout<<"\n\n\tEnter your Mobile Number: ";
  cin>>mobile;
   cin.sync();
  cout<<" \t\n Password : ";
  cout<<" \t\n (Suggestion: Use the randomly generated password : " << generateRandomPassword() << " ) ";

cout<<"\t\n\n Note: Your password must contain an upper case alphabet,\n       a lower case alphabet and a digit. ";
   cout<<"\t\n       And your password should not have space in between. ";
   cout<<"\t\n       And your password size must be between 8 and 25. ";
cout<<"\t\n\n : ";
   cin.ignore();
    gets(password);
    cin.sync();
	while( checkvalidity(password ) == 0)
	{
		cout<<"\t\n\n Please Enter a password satisfying the above conditions: ";
		gets(password);
		   cin.sync();
	}

	cin.sync();
    cout<<"\t\n\n Re Enter Password: ";
    gets(temp);
    cin.sync();
    while(strcmp(password,temp)!=0){

        cout<<"\t\n\n Password did not matched! Enter again";
        cout<<"\t\n\n Enter password: ";
        gets(password);

        while( checkvalidity(password ) == 0)
		{
		cout<<"\t\n\n Please Enter a password satisfying the above conditions : ";
		gets(password);
		}
        cin.sync();
        cout<<"\t\n\n Re Enter Password: ";
        gets(temp);
         cin.ignore();
    }

     cin.ignore();
    string captcha;
    a:
    cout<<"\n Please type the words that appear below to Register Your Account: ";
    string check;
    check = generatecaptcha().c_str() ;
     cin.ignore();
    cout<<"\n\n\t\t "<< check<<"  ";
    cout<<"\n\n :  ";
      cin>>captcha;
     if (cin.fail())
        {
         cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    while( check != captcha)
    {
        if (cin.fail())
        {
         cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cout<<"\n\n\t INCORRECT CAPTCHA!, Please try again ";
          check = generatecaptcha().c_str() ;
    cout<<"\n\n\t\t "<< check;
    cout<<endl;
        cin>>captcha;
    }

    string OTPgenerated = generateOTP();

    //////////////////////////////////////////////////////////////////////////////////////////
    	ofstream out("otpforteacher.DAT");
	if(out)
        {
        out<<full_name<<"\t\t\t"<<OTPgenerated;
        out.close();
        }
	else
	cout<<"cannot open the OtpForTeacher.dat file. \n";



string EnterOtp;
    cin.sync();
    cout<<"\n\n The OTP has been sent to the Admin , Kindly Ask for it and Enter the OTP to Register your Account : ";
    cout<<" \n\n OTP : ";
    getline(cin,EnterOtp);
    cin.sync();
    if( EnterOtp != OTPgenerated )
    {
        cout<<"\n\n Wrong OTP !!";
        cout<<"\n Press Enter ";
        _getch();
        cover();
    }


}
 void add_user();
 void user_login();
 void show_allu();
 void admin_menu();
 void user_menu();
 void issue_book();
 void show_account();
};

//***********************************************
//*************Class Book************************
class book{
public:
 char book_no[3];
 char book_name[50];
 char author[20];
 int no_of_book;

	void create_book()
	{
	 cout<<"\n\n\tEnter The Serial No. :";
	 cin>>book_no;
	 cin.sync();
	 cout<<"\n\tEnter Tha Name of The Book :";
	 gets(book_name);
	 cin.sync();
	 cout<<"\n\tEnter The Author Name :";
	 gets(author);
	 cin.sync();
	 cout<<"\n\tEnter No of Books :";
	 cin>>no_of_book;
	 cin.sync();
	}

	void show_book()
	{
	  cout<<setw(4)<<book_no<<"."<<setw(35)<<book_name<<setw(20)<<author<<setw(12)<<no_of_book<<"\n";
	}



	void modify_book()
	{
		cout<<"\n\tBook no. : "<<book_no;
		cout<<"\n\tModify Book Name : ";
		gets(book_name);
		cin.sync();
		cout<<"\n\tModify Author's Name of Book : ";
		gets(author);
		cin.sync();
		cout<<"\n\tModify Book Count : ";
		cin>>no_of_book;
		cin.sync();
	}
void add_book();
 void show_allb1();
  void show_allb2();
  void book_bno();
  void book_bna();
  void book_bar();
  void delete_book();
  void mod_book();
  void issue_book();
  void deposite_book();
  //void show_account();
};

//***************************************************
//*****************class Admin***********************
class admin{

public:
  char pass_admin[4];
  void create_admin()
 {
  cout<<"Enter the password:\n";
  cin>>pass_admin;
  }



  void admin_login();
  void add_admin();
};

//***************************************************
//****************global obj*************************
user u;
book b;
admin a;
//*************************************************************************
//****************global variable for current user*************************
char current_user[10];
char book_serial_no[3];
char current_book_name[50];

void showotp()
 {
     string line;
  ifstream myfile ("OtpForTeacher.dat");
  if (myfile.is_open())
  {
      cin.sync();
    while ( getline (myfile,line) )
    {
      cout << line << endl;
      cin.sync();
    }
    myfile.close();
    _getch();
    u.admin_menu();
  }
  else
  {cout << "Unable to open file";
    _getch();
    u.admin_menu();
   }
 }
//***************************************************
//********************add user***********************

void user::add_user () /////////////////////////////////////////////////
 {


	u.create_user();
	ofstream out("user.DAT",ios::app);
	if(!out){
	cout<<"cannot open the user.dat file. \n";
	}
	strcpy(u.issued_book_no,"0");
	out.write((char*) &u,sizeof(user));
    out.close();
	cout<<"\tYour Account Has Been Created";
     _getch();
    system("WelcomeEmailGenerator.exe"); //**************************************************************************************
    cover();

	}
//***************************************************
//********************add admin***********************
void admin::add_admin()
 {
	a.create_admin();
	ofstream out("admin.dat",ios::app);
	if(!out){
	cout<<"cannot open the user.dat file. \n";
	}
	out.write((char*) &a,sizeof(admin));
	cout<<"Your Account Has Been Created";
	system("AdminNewAccountEmailGenerator.exe"); //**************************************************************************************
	cover();

 }

//****************************************************
//*********************log in for user****************
  void user:: user_login()
 {
  char n[25],p[25];
  int flag=0;
  ifstream in("user.dat");

  cout<<"\n\n\tEnter The User Name: ";
  gets(n);
  cin.sync();
  cout<<"\n\n\tEnter The Password: ";
  cin>>p;
  cin.sync();

  if(!in)
  {
	 cout<<"File Not Found";
  }

  while(in.read((char *)&u,sizeof(user)))
  {
	  if(strcmp(u.name,n)==0 && strcmp(u.password,p)==0)
	  {
		 strcpy(current_user,u.name);
		 strcpy(book_serial_no,u.issued_book_no);
		 flag=1;
		 cout<<"\n\tWELCOME  "<<u.full_name<<"\n";
		 _getch();
		 system("WelcomeBackEmailGenerator.exe"); //**************************************************************************************
        u.user_menu();
		 }
	 }
	 if(flag==0)
	 {
	  cout<<"\tWrong User Name or Password";
	  user_login();
	 }
	 in.close();


 }
 //****************************************************
//*********************log in for Admin****************
  void admin::admin_login()
 {
  char x[4];
  ifstream in("admin.dat",ios::in|ios::out);
  cout<<"\n\n\tEnter The Password: ";
  cin>>x;
  if(!in)
  {
	 cout<<"File Not Found";
  }


  while(in.read((char *)&a,sizeof(admin)))
  {
	  if(strcmp(a.pass_admin,x)==0)
	  {
	      string otp = generateOTP();
     	ofstream out("AdminLoginOTPEmail.txt"); //************************************************************************
        if(out)
        {
        out<<"From: library Management System";
        out<<"<library.project.prabsimar.bavleen@gmail.com>"<<endl;
        out<<"To: Prabsimar Singh<simarsingh1112@gmail.com>"<<endl;
        out<<"Subject: OTP for Admin log In  "<<endl;
        out<<"Date: Mon, 7 Nov 2016 08:45:16"<<endl;
        out<<endl;
        out<<"Hello!, Prabsimar Singh."<<endl;
        out<<"OTP: "<<otp;
        out.close();
        }
        else
           cout<<"cannot open the AdminLoginOTPEmail.dat file. \n";

        system("AdminLoginOTPEmailGenerator.exe");  //**************************************************************************************

        cout<<"\n An OTP has been sent on your Email ID, Please Enter the OTP below.";
        string otpEntered;
         cin>>otpEntered;

        if( otpEntered != otp)
        {   int count=0;
            while( count<1 )
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                cin>>otpEntered;
                count++;
            }
            if(otpEntered!=otp)
            {
            cout<<"\n Wrong OTP! ";
            cout<<"\n Press Enter";
            _getch();
            cover();
            }
            cout<<"logged In"; //************************************************
            _getch();
            u.admin_menu();

        }
        else
        {
            cout<<"\n\tLOGGED IN" ;
            _getch();
            u.admin_menu();
        }
	  }
	  else
	  {
		  cout<<"\twrong password";
		  a.admin_login();
	  }
	 }
	 in.close();
 }
//**********************************************
//****************search book by book no********
 void book :: book_bno()
 {
	ifstream in;
	char n[3],x;
	int flag=0;
	do{
	cout<<"\n\n\tEnter The Serial No of The Book: ";
	cin>>n;
	cin.sync();
	in.open("book.dat");
	while(in.read((char*)&b,sizeof(book)))
	{
		if(strcmpi(b.book_no,n)==0)
		{  cout<<"\t\t\t     *Book List*\n\n";
		cout<<"|Book No.|"<<setw(20)<<"|Book Name|"<<setw(25)<<"|Author|"<<setw(20)<<"|Book Count|\n";
		cout<<"***************************************************************************\n";
			b.show_book();
			flag=1;
			break;
		}
	}
		if(flag==0)
		{
		cout<<"Book Not Found";
		}
		flag=0;
		cout<<"\n\n\tDo you want to search again..(y/n?)";
		cin>>x;
		in.close();
		}while(x=='y'||x=='Y');
		_getch();
		u.user_menu();
 }
//*************************************************
//*******************search book by name***********

  void book:: book_bna()
 {
	ifstream in;
	char n[50],x;
	int flag=0;
	do{
	cout<<"\n\n\tEnter The Name of The Book:";
	gets(n);
	cin.sync();
	in.open("book.dat");
	while(in.read((char*)&b,sizeof(book)))
	{
		if(strcmpi(b.book_name,n)==0)
		{  cout<<"\t\t\t     *Book List*\n\n";
		cout<<"|Book No.|"<<setw(20)<<"|Book Name|"<<setw(25)<<"|Author|"<<setw(20)<<"|Book Count|\n";
		cout<<"***************************************************************************\n";
			b.show_book();
			flag=1;
			break;
		}

	}
		if(flag==0)
		{
		cout<<"Book Not Found";

		}
		flag=0;
		cout<<"\n\nDo you want to search again..(y/n?)";
		cin>>x;
		in.close();
		}while(x=='y'||x=='Y');
		_getch();
		u.user_menu();

 }

 //*************************************************
//*******************search book by author**********

  void book::book_bar()
 {
	ifstream in;
	char n[20],x;
	int flag=0;
	cout<<"\n\n\tEnter The Name of The Author:";
	gets(n);
	cout<<"\t\t\t     *Book List*\n\n";
		cout<<"|Book No.|"<<setw(20)<<"|Book Name|"<<setw(25)<<"|Author|"<<setw(20)<<"|Book Count|\n";
		cout<<"***************************************************************************\n";
	do{

	in.open("book.dat");
	while(in.read((char*)&b,sizeof(book)))
	{
		if(strcmpi(b.author,n)==0)
		{

			b.show_book();
			flag=1;
		}



	}

	  if(flag==0)
		{
		cout<<"Book Not Found";
		}


		cout<<"\n\n\tDo You Want To Search Again..(y/n?)";
		cin>>x;
		in.close();
		}while(x=='y'||x=='Y');
		_getch();
		u.user_menu();

 }


//***********************************************
//*******************add_book********************
 void book:: add_book()
 {
  char c;
  do{
  b.create_book();
  ofstream out("book.dat",ios::app);
  if(!out){
  cout<<"cannot open the user.dat file. \n";
  }
  out.write((char*) &b,sizeof(book));
  cout<<"\n\n\tDo You Want To Add More Book To The Record(y/n?)";
  cin>>c;
  out.close();
  } while(c=='y'||c=='Y');
  _getch();
  u.admin_menu();


  }

//***********************************************
//*******************show_allb for admin*******************


 void book:: show_allb1()
 {

  ifstream in("book.dat");
  if(!in)
  {
  cout<<"File not Found";
  }
		cout<<"\t\t\t     *Book List*\n\n";
		cout<<"|Book No.|"<<setw(20)<<"|Book Name|"<<setw(25)<<"|Author|"<<setw(20)<<"|Book Count|\n";
		cout<<"***************************************************************************\n";
  while(in.read((char*)&b,sizeof(book)))
  {
	b.show_book();

  }
  in.close();
    _getch();
   u.admin_menu();
 }
//***********************************************
//*******************show_allb for user*******************
  void book::show_allb2()
 {

  ifstream in("book.dat");
  if(!in)
  {
  cout<<"File not Found";
  }
  cout<<"\t\t\t     *Book List*\n\n";
  cout<<"|Book No.|"<<setw(20)<<"|Book Name|"<<setw(25)<<"|Author|"<<setw(20)<<"|Book Count|\n";
  cout<<"***************************************************************************\n";
  while(in.read((char*)&b,sizeof(book)))
  {
	b.show_book();

  }
  in.close();
  _getch();
  u.user_menu();

 }



 //***********************************************
//*******************show_allu*******************


 void user::show_allu()
 {

  ifstream in("user.dat");
  if(!in)
  {
  cout<<"File not Found";
  }
	 cout<<"\n\t|Name|"<<setw(33)<<"|User Name|"<<setw(33)<<"|Email-ID|"<<setw(33)<<"|Mobile|"<<"\n" ;
	 cout<<"\t***************************************\n";
  while(in.read((char*)&u,sizeof(user)))
  {

		  cout<<"\t"<<u.full_name<<"\t\t\t"<<u.name<<"\t\t\t"<<u.email<<"\t\t\t"<<u.mobile<<"\n";

  }
  in.close();
	_getch();
	u.admin_menu();
 }


//***********************************************
//********************Delete Book****************


void book::delete_book()
{

		char n[3];
		char c2;
		int flag=0;
		fstream f1;
		fstream f2;

		cout<<"\n\n\n\tDELETE Specific Book...";
		do{
		cout<<"\n\nEnter The Serial no. of the Book To Delete : ";
		cin>>n;
		f1.open("book.dat",ios::in|ios::out);
		f2.open("temp.dat",ios::out);
		f1.seekg(0,ios::beg);
		while(f1.read((char*)&b,sizeof(book)))
	{
		if(strcmpi(b.book_no,n)!=0)
				f2.write((char*)&b,sizeof(book));
		else
				flag=1;
	}

	f2.close();
		f1.close();
		remove("book.dat");
		rename("temp.dat","book.dat");
		cout<<b.book_no;
		if(flag==1)
			{
			cout<<"\n\n\tRecord Deleted ..";
			cout<<"\n\nDo you want to add more record..(y/n?)";
			cin>>c2;
			}

		else
		  {	cout<<"\n\nRecord not found";
			cout<<"\n\nDo you want to add more record..(y/n?)";
			cin>>c2;
			}
			}while(c2=='y'||c2=='Y');
			_getch();
			u.admin_menu();


}

//***************************************************
//*********************modify book*******************
void book:: mod_book()
{ 	char n[6],ch;
	fstream fp;
	int found=0;
	system("cls");
	cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
	cout<<"\n\n\tEnter The book no. of The book :";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&b,sizeof(book)) && found==0)
	{
		if(strcmpi(b.book_no,n)==0)
		{
		  do{
			system("cls");
			cout<<"\n\t\t\t     *Book List*\n\n";
			cout<<"|Book No.|"<<setw(20)<<"|Book Name|"<<setw(25)<<"|Author|"<<setw(20)<<"|Book Count|\n";
			cout<<"***************************************************************************\n";
			b.show_book();

			cout<<"\n\n\t**********************";
			cout<<"\n\tBook Modification Menu";
			cout<<"\n\t**********************";
			cout<<"\n\t1.Modify Book Serial No";
			cout<<"\n\t2.Modify Book Name";
			cout<<"\n\t3.Modify Book Author";
			cout<<"\n\t4.Modify Book Count";
			cout<<"\n\t5.Go To Admin Menu\n";
			cout<<"\n\tEnter Your Choice: ";
			ch=getche();

			switch(ch)
		{
			 case '1':
			 {
                system("cls");
			 cout<<"\n\tModify Book Serial No : ";
			 cin>>b.book_no;
			 int pos=-1*sizeof(b);
			 fp.seekp(pos,ios::cur);
			 fp.write((char*)&b,sizeof(book));

			 found=1;
			 fp.close();
			 break;
			 }

			  case '2':
			  {
			      system("cls");
			 cout<<"\n\tModify Book Name : ";
			 gets(b.book_name);
			 int pos=-1*sizeof(b);
			 fp.seekp(pos,ios::cur);
			 fp.write((char*)&b,sizeof(book));
			 cout<<"\n\n\t Record Updated";
			 found=1;
				 fp.close();
			 break;
			 }
			  case '3':
			 {
			     system("cls");
			 cout<<"\n\tModify Book Author Name : ";
			 gets(b.author);
			 int pos=-1*sizeof(b);
			 fp.seekp(pos,ios::cur);
			 fp.write((char*)&b,sizeof(book));
			 cout<<"\n\n\t Record Updated";
			 found=1;
				 fp.close();
			 break;
			 }
			  case '4':
			 {
			     system("cls");
			 cout<<"\n\tModify Book count : ";
			 cin>>b.no_of_book;
			 int pos=-1*sizeof(b);
			 fp.seekp(pos,ios::cur);
			 fp.write((char*)&b,sizeof(book));
			 cout<<"\n\n\t Record Updated";
			 found=1;
				 fp.close();
			 break;
			 }
			 case '5':
			 {
			 system("cls");
			 u.admin_menu();
			 break;
			 }
	  }
	  }while(ch!='5');

		}
	}

		fp.close();
		if(found==0)
			cout<<"\n\n Record Not Found ";
			getch();
			u.admin_menu();


	}




//********************************************
//*****************issue Book*****************
void book::issue_book()
{
	char n[3];
	fstream fp,f;
	int found=0;
	system("cls");
	cout<<"\n\n\tEnter The serial no. of The book:";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&b,sizeof(book)) && found==0)
	{
		if(strcmpi(b.book_no,n)==0)
		{  found=1;

		cout<<"|Book No.|"<<setw(20)<<"|Book Name|"<<setw(25)<<"|Author|"<<setw(20)<<"|Book Count|\n";
		cout<<"***************************************************************************\n";
			b.show_book();
			if(b.no_of_book==0)
			{
			 cout<<"\n\n\t   ********This Book Is Not Available For Issuing.********\n";
			 break;
			}
			else
			{
			b.no_of_book=b.no_of_book-1;
			strcpy(current_book_name,b.book_name);
				int pos=-1*sizeof(b);
				fp.seekp(pos,ios::cur);
				fp.write((char*)&b,sizeof(book));
				cout<<"\n\n\tBook Has Been Issued For 10 Days.Late Fee 1 Rs Per Day\n";

			}

		}
	}


		fp.close();
		if(found==0)
			cout<<"\n\n Record Not Found ";

		f.open("user.dat",ios::in|ios::out);
		while(f.read((char*)&u,sizeof(user)))
	{
		if(strcmpi(u.name,current_user)==0)
		{
				strcpy(u.issued_book_no,n);
				strcpy(book_serial_no,u.issued_book_no);
				int pos=-1*sizeof(u);
				f.seekp(pos,ios::cur);
				f.write((char*)&u,sizeof(user));
		 }
	}
		_getch();
		u.user_menu();

}

//*************************************
//***************book_deposite*********6
void book::deposite_book()
{
	char n[6];
	fstream fp,f;
	int found=0;
	system("cls");
		f.open("user.dat",ios::in|ios::out);
		while(f.read((char*)&u,sizeof(user)))
	{
		if(strcmpi(u.name,current_user)==0)
		{
			  strcpy(n,u.issued_book_no);
			  strcpy(u.issued_book_no,"0");

			int pos=-1*sizeof(u);
				f.seekp(pos,ios::cur);
				f.write((char*)&u,sizeof(user));


		}
		}
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&b,sizeof(book)) && found==0)
	{
		if(strcmpi(b.book_no,n)==0)
		{  cout<<"\t\t\t     *Book List*\n\n";
		cout<<"|Book No.|"<<setw(20)<<"|Book Name|"<<setw(25)<<"|Author|"<<setw(20)<<"|Book Count|\n";
		cout<<"***************************************************************************\n";
			b.show_book();
			b.no_of_book=b.no_of_book+1;

			int pos=-1*sizeof(b);
				fp.seekp(pos,ios::cur);
				fp.write((char*)&b,sizeof(book));
				cout<<"\n\n\tBook Has Been Deposited\n";

				found=1;
		}
	}

		fp.close();
		if(found==0)
			cout<<"\n\n\t No Book To Deposite ";
	 _getch();
	 u.user_menu();

	}




//****************************************************
//***************Show Account Detail************************

void user:: show_account()
{
	ifstream in,i;
	i.open("book.dat");
	while(i.read((char*)&b,sizeof(book)))
	{
	  if(strcmpi(b.book_no,book_serial_no)==0)
	  {
		 strcpy(current_book_name,b.book_name);

	  }
	  }


	in.open("user.dat");
	while(in.read((char*)&u,sizeof(user)))
	{
	if(strcmpi(u.name,current_user)==0)
		{

		 cout<<"\n\t|Name|"<<setw(25)<<"|Password|"<<setw(30)<<"|Issued Book|"<<"\n";
		 cout<<"\t**********************************************************\n";
		  cout<<"\t"<<u.full_name<<setw(20)<<u.password<<setw(30)<<current_book_name<<"\n\n";



		}
	 }
	 in.close();
      _getch();
      u.user_menu() ;

	}


//*********************************************
//**************admin_menu*********************
void user::admin_menu()
{
    admenu:
    system("cls") ;
char c1;
cout<<"\n\n\t*****************";
cout<<"\n\t    Admin Menu";
cout<<"\n\t*****************";
cout<<"\n\t1.Show All Book";
cout<<"\n\t2.Add Book";
cout<<"\n\t3.Modify Book";
cout<<"\n\t4.Delete Book";
cout<<"\n\t5.Show All User";
cout<<"\n\t6.Open OTP File";
cout<<"\n\t7.LogOut\n";
cout<<"\n\tEnter Your Choice: ";
c1=getche();
switch(c1)
{
 case '1':system("cls");
			 b.show_allb1();
			 break;
 case '2':system("cls");
			 b.add_book();
			 break;
 case '3':system("cls");
			 b.mod_book();
			 break;
 case '4':system("cls");
			 b.delete_book();
			 break;
 case '5':system("cls");
			 u.show_allu();
			 break;
 case '6':system("cls");
			 showotp();
			 break;
case '7':system("cls");
			 cover();
			 break;
default : system("cls");
			u.admin_menu();
			break;
}

}

//************************************
//****************user_menu***********
void user:: user_menu()
{
  char c1;
system("cls") ;
cout<<"\n\t*****************";
cout<<"\n\t    User Menu";
cout<<"\n\t*****************";
cout<<"\n\n\t1.Show Account Detail";
cout<<"\n\t2.Show All Book";
cout<<"\n\t3.Search Book By No";
cout<<"\n\t4.Search Book By Name";
cout<<"\n\t5.Search Book By Author";
cout<<"\n\t6.Issue Book";
cout<<"\n\t7.Deposite Book";
cout<<"\n\t8.LogOut\n";
cout<<"\n\tEnter Your Choice: ";


c1=getche();
switch(c1)
{
 case '1':system("cls");
			 u.show_account();
			 break;
 case '2':system("cls");
			 b.show_allb2();
			 break;
 case '3':system("cls");
			 b.book_bno();
			 break;
 case '4':system("cls");
			 b.book_bna();
			 break;
 case '5':system("cls");
			 b.book_bar();
			 break;
 case '6':system("cls");
			 b.issue_book();
			 break;
 case '7':system("cls");
			 b.deposite_book();
			 break;
 case '8':system("cls");
			 strcpy(current_user,"");
			 cover();
			 break;
 default:
            system("cls");
            _getch();
            system("cls");
            u.user_menu();
            break;



}


}
void cover()
{
    system("cls") ;
char ch;
  cout<<"\n\n\t\t\t  ***************************\n";
  cout<<"\t\t\t  [LIBRARY MANAGEMENT SYSTEM]";
  cout<<"\n\t\t\t  ***************************";
  gotoxy(10,15);
  cout<<"\n\t1.User Login";
  cout<<"\n\t2.Admin Login";
  cout<<"\n\t3.Create An User Account\n\t";
  ch=getche();
  switch(ch)
  {
	case '1':system("cls");
				u.user_login();
				break;
	case '2': system("cls");
				a.admin_login();
				break;
	case '3': system("cls") ;
				u.add_user();
				break;
    default:
            cout<<"\n\t Wrong Option,Please try again. ";
            _getch();
            cover();
  }
}
int main()
{
 cover();
return 0;
}
