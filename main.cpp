#include<conio.h>	//Sleep,gotoxy coordinate functions
#include<bits/stdc++.h>
#include<fstream>
#include<dos.h>
#include<windows.h>
using namespace std;
char loc[20];			//holds time ad date
void delr1();			//delete file
void delr2();			//rename file
void gotoxy (int x, int y);	//handle output on screen
void frame ();			//frame for every dialog box
void frame_fix();
char *date_time ();
void scroll_note();
void flow(char *ch);
void main_menu();
void sub_menu();
COORD coord = {0, 0};
fstream ff,fs,fp,fg;
class date;
class atm{	//class for entire program;
	private:
	int mbno,pcode,amt,prev,pin,acc;
	int adl;
	int day,month,year,hour,min,sec;
	char fname[10],sname[10],p_name[20],city[15],email[20],dob[15],type;

	public:

	void create_account();
	void help();
	void main_menu();
	void sub_menu();

	void cash_deposit(atm);
	void fund_transfer(atm);
	void change_pin(atm);
	void other_services(atm);

	void fast_cash(atm);
	void cash_withdraw(atm);
	void balance_enquiry(atm);
	void mini_statement(atm);

	void admin();

	void note();
	atm login_check();

};
class date{
	public:
		int aday,amonth,ayear,ahour,amin,asec;
        void date_times(){
            SYSTEMTIME t;		//pre defined in time.h header
            GetLocalTime(&t);
            aday=t.wDay,amonth=t.wMonth,ayear=t.wYear,ahour=t.wHour,amin=t.wMinute,asec=t.wSecond;

        }
};
void gotoxy (int x, int y){
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void frame(){
	int i,j=79;
	for(i = 0;i<80,j>=0;i++,j--){
		gotoxy(i,3);
		Sleep(10);
		cout<<"_";
		gotoxy(j,20);
		Sleep(10);
		cout<<"_";
	}
	gotoxy(56,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;		//every frame has date on the right top
}
void frame_fix(){	//instead of flow line fixing the frame
	int i,j=79;
	for(i = 0;i<80,j>=0;i++,j--){
		gotoxy(i,3);
		cout<<"_";
		gotoxy(j,20);
		cout<<"_";
	}
	gotoxy(56,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;
}
char *date_time(){
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;	//returns local time and date
}
void flow(char *ch){	//flow of instructions
	char *str=ch;
	for(int i=0;i<strlen(str);i++){
		Sleep(20);
		cout<<str[i];
	}
}
void scroll_note(){
	system("color FC");
	int j,i,x,y;
	for(i=0;i<27;i++){
		gotoxy(i,13);cout<<" ";
		cout<<"ATM SYSTEM - ";
		Sleep(40);
	}
	for(j=67;j>40;j--){
		gotoxy(j,13);
		cout<<"PSUP MINI PROJECT";cout<<" ";
		Sleep(40);
	}
	gotoxy(27,13);cout<<"ATM SYSTEM - ";
	gotoxy(41,13);cout<<"PSUP MINI PROJECT";
	for(int j=78;j>=0;j--){
		gotoxy(j,20);cout<<"|";
		gotoxy(j,4);cout<<"|";
		Sleep(30);
	}
	gotoxy(56,23);cout<<"Jhanvee Khola 03001172020";
	gotoxy(56,24);cout<<"Khushi Punia 05201172020";
	Sleep(2000);
}
void atm:: main_menu(){
	system("cls");
	system("COLOR 3F");
	frame();

	gotoxy(33,10);
	cout<<"ATM SYSTEM";
	gotoxy(30,14);
	cout<<"ENTER YOUR CHOICE : ";
	gotoxy(1,19);
	cout<<"HELP";
	char op;
	gotoxy(1,21);
	cout<<"C :Create account \n H :Help \n P :Proceed to account(if already have account)\n E : Exit  ";
	gotoxy(1,2);
	cout<<"ADMIN ";
	gotoxy(54,14);cout<<"";
	op=getch();

	if(op=='c'||op=='C'){
		create_account();
	}
	else if(op=='h'||op=='H')
	{
		cout<<"h";
		help();
	}
	else if(op=='p'||op=='P')
	{
		sub_menu();
	}
	else if(op=='a'||op=='A')
	{
		admin();
	}
	else if(op=='e'||op=='E')
	{
		system("cls");
		note();
	}
	else
	{
		cout<<" \a\a\aINVALID OPTION ";
		Sleep(1000);
		main_menu();
	}

}
void atm::sub_menu(){	//after user login the following fuctions are displayed
	system("cls");
	int cpin;

	atm r;
	r=login_check();
	fg.close();
		while(1){

			int i;
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(1,6);
			cout<<"1. CASH DEPOSIT";
			gotoxy(1,10);
			cout<<"2. FUND TRANSFER";
			gotoxy(1,14);
			cout<<"3. PIN CHANGE";
			gotoxy(1,18);
			cout<<"4. OTHER SERVICES";
			gotoxy(64,6);
			cout<<"5. FAST CASH";
			gotoxy(64,10);
			cout<<"6. CASH WITHDRAWL";
			gotoxy(64,14);
			cout<<"7. BALANCE ENQUIRY";
			gotoxy(64,18);
			cout<<"8. MINI STATEMENT";
			gotoxy(28,4);
			const char *s= "Select your transaction";
			for(int i=0;i<24;i++){
				cout<<s[i];
				Sleep(100);
			}
			int op;
			gotoxy(38,24);
			cout<<" ";
			cin>>op;
			switch(op){
				case 1:{
						cash_deposit(r);
						break;
					}
				case 2:{
						fund_transfer(r);
						break;
					}
				case 3:{
						change_pin(r);
						break;
					}
				case 4:{
						other_services(r);
						break;
					}
				case 5:{
						fast_cash(r);
						break;
					}
				case 6:{
						cash_withdraw(r);
						break;
					}
				case 7:{
						balance_enquiry(r);
						break;
					}
				case 8:{
						mini_statement(r);
						break;
					}
				default:{
						gotoxy(64,24);
						cout<<"Invalid Input ";
						cout<<"\a\a\a";		//terminating to mainmenu
						Sleep(1000);
						main_menu();
					}

			}
		}

}
void atm::help(){
	system("cls");
	system("COLOR AF");
	for(int i=0;i<25;i++){
		gotoxy(2,i);
		cout<<"|";
		gotoxy(77,i);
		cout<<"|";
	}
	gotoxy(3,0);
	cout<<"Inorder to use our ATM services be sure that,";
	gotoxy(3,1);
	cout<<"you might have already opened an account previously. ";
	gotoxy(3,22);
	cout<<"For more information, contact:";
	gotoxy(3,23);
	cout<<"Call our 24x7 helpline through toll free 98XXXXXXX.";
	gotoxy(3,24);
	cout<<"Contact at psup_project.in";
	gotoxy(3,5);
	cout<<"ATM Services";
	gotoxy(3,8);
	cout<<"Cash Withdrawal : Use this service to withdraw amount (40,000/-per day).";
	gotoxy(3,10);
	cout<<"Fast Cash : This enables to withdraw your preferred amounts with a touch.";
	gotoxy(3,12);
	cout<<"Pin Change : Use this service to change your ATM password.";
	gotoxy(3,14);
	cout<<"Balance Enquiry : To check the current balance in your account.";
	gotoxy(3,16);
	cout<<"Ministatement : Keep track of the transactions in your account.";
	gotoxy(3,18);
	cout<<"Fund Transfer : Transfers amount instantly to your loved ones.";

	getch();
	main_menu();
}
void atm::create_account(){
	atm a;
	system("cls");
	system("COLOR E0");
	for(int i=0;i<25;i++){
		gotoxy(5,i);
		cout<<"|";
		gotoxy(75,i);
		cout<<"|";
	}
	gotoxy(34,2);
	cout<<"APPLICATION FORM";
	gotoxy(10,5);
	cout<<"Enter Full Name : ";
	cin>>a.fname>>a.sname;
	gotoxy(10,7);
	cout<<"Father/Guardian Name : ";
	cin>>a.p_name;
	gotoxy(10,9);
	cout<<"Date Of Birth (dd/mm/yyyy) : ";
	cin>>a.dob;
	gotoxy(10,11);
	cout<<"Account Type (S/C) : ";
	cin>>a.type;
	gotoxy(10,13);
	cout<<"City : ";
	cin>>a.city;
	gotoxy(10,15);
	cout<<"PINCODE : ";
	cin>>a.pcode;
	gotoxy(10,17);
	cout<<"Email Id : ";
	cin>>a.email;
	gotoxy(10,19);
	cout<<"Enter initial amount( >= 500) : ";
	cin>>a.amt;
	a.pin=rand();
	string fn,sn,f,birth,typ,citi,pc,emel,gn;
	int as,p,ac;
	fstream f1;
	f1.open("atm_users.txt",ios::in);
	if(f1){
		f1.seekg(0);
		while(f1>>ac>>p>>fn>>sn>>gn>>birth>>typ>>citi>>pc>>emel>>as){}
		a.acc=ac+1;
	}
	f1.close();
	fstream file;
	file.open("atm_users.txt",ios::in|ios::app);
	if(!file){
		acc=1000;
		file.open("atm_users.txt",ios::out);
		file<<a.acc<<" "<<a.pin<<" "<<a.fname<<" "<<a.sname<<" "<<a.p_name<<" "<<a.dob<<" "<<a.type<<" "<<a.city<<" "<<a.pcode<<" "<<a.email<<" "<<a.amt<<"\n";
		file.close();
	}
	else{
		file.seekg(0);
		while(file>>ac>>p>>fn>>sn>>gn>>birth>>typ>>citi>>pc>>emel>>as){
			if(emel==a.email){
				cout<<"Account already exists with this e-mail"<<endl;
				file.close();
				a.main_menu();
			}
			else{
			file<<a.acc<<" "<<a.pin<<" "<<a.fname<<" "<<a.sname<<" "<<a.p_name<<" "<<a.dob<<" "<<a.type<<" "<<a.city<<" "<<a.pcode<<" "<<a.email<<" "<<a.amt<<"\n";
			file.close();
			}
		}
	}
	//inital account details posting to atm_users file
	//initialize amount,time & date of account opened and APPENDING to transactions file
	a.adl=a.amt;	//adl = additional amount either deposit/credit
	a.prev=0;		//prev = available balance before transaction
	date d;
	d.date_times();
	a.day=d.aday;a.month=d.amonth;a.year=d.ayear;
	a.hour=d.ahour;a.min=d.amin;a.sec=d.asec;
	//to transactions file
	fp.open("transactions.txt",ios::app|ios::out);
	fp<<a.acc<<" "<<a.fname<<" "<<a.prev<<" "<<a.adl<<" "<<a.amt<<" "<<a.day<<" "<<a.month<<" "<<a.year<<" "<<a.hour<<" "<<a.min<<" "<<a.sec<<"\n";
	fp.close();
	fstream fp1;
	fp1.open("accounts.txt",ios::app|ios::out);
	fp1<<a.acc<<" "<<a.pin<<" "<<a.fname<<" "<<a.sname<<"\n";
	gotoxy(35,21);
	cout<<" SUBMIT";
	char c;
	//c=getche();
	c=getchar();
	gotoxy(10,23);
	cout<<"Loading";
	Sleep(400);
	cout<<".";
	Sleep(400);
	cout<<".";
	Sleep(400);
	cout<<".";
	Sleep(400);
	system("cls");
	system("COLOR B0");
	frame_fix();
	gotoxy(22,5);
	cout<<"YOUR ACCOUNT HAS SUCCESSFULLY CREATED ";
	gotoxy(29,8);
	cout<<"ACCOUNT NUMBER  : "<<a.acc;
	gotoxy(29,12);
	cout<<"ATM PIN	      : "<<a.pin;
	gotoxy(8,19);
	cout<<"NOTE : THESE ARE THE ACCOUNT CREDENTIALS FOR USING ATM SERVICES.";
	gotoxy(28,23);
	cout<<"MAIN MENU : PRESS ENTER";
	char op;
	//op=getche();
	op=getchar();
	main_menu();
}
void atm:: balance_enquiry(atm r){
	system("cls");
	frame_fix();
	gotoxy(22,10);
	cout<<"ACCOUNT HOLDER NAME  : "<<r.fname;
	gotoxy(22,13);
	cout<<"CURRENT BALANCE      : "<<r.amt;
	Sleep(3000);
    system("cls");
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
	main_menu();
}
void atm:: cash_deposit(atm r){
	fstream f1,f2,f3;
	system("cls");
	int cash;
	frame_fix();
	gotoxy(22,6);
	cout<<"PLEASE ENTER AMOUNT : ";
	cin>>cash;
	r.amt+=cash;
	r.adl=cash;
	date d;
	d.date_times();
	r.day=d.aday;r.month=d.amonth;r.year=d.ayear;
	r.hour=d.ahour;r.min=d.amin;r.sec=d.asec;
    atm a;
    f1.open("transactions.txt",ios::app|ios::out);
    f1<<r.acc<<" "<<r.fname<<" "<<r.prev<<" "<<r.adl<<" "<<r.amt<<" "<<r.day<<" "<<r.month<<" "<<r.year<<" "<<r.hour<<" "<<r.min<<" "<<r.sec<<"\n";
    f1.close();
    //finding current account details to accounts file for changing amount
    // f2.open("accounts.txt",ios::in);
    // f3.open("temp.txt",ios::out);
    // while(f2>>a.acc>>a.pin>>a.fname>>a.sname>>a.amt){
    // 	if(g.acc==a.acc){
    // 		a.amt=g.amt;
    // 		f3<<a.acc<<" "<<a.pin<<" "<<a.fname<<" "<<a.sname<<" "<<a.amt<<"\n";
    // 	}
    // }
    // f3.close();
	// f2.close();
    system("cls");
    frame_fix();
    gotoxy(18,12);
	cout<<"AMOUNT DEPOSITED  : "<<r.adl<<" FINAL BALANCE : "<<r.amt;
	Sleep(3000);
    system("cls");
	gotoxy(18,13);
	cout<<"	      PLEASE WAIT VALIDATING THE CASH		";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
    main_menu();
}
void atm:: cash_withdraw(atm r){
	fstream f1;
	system("cls");
	int cash;
	frame_fix();
	gotoxy(22,6);
	cout<<"PLEASE ENTER AMOUNT : ";
	cin>>cash;
	if(cash>r.amt){
		gotoxy(15,13);
		cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
		Sleep(1000);
		main_menu();
	}
	r.amt-=cash;
	r.adl=cash;
	date d;
	d.date_times();
	r.day=d.aday;r.month=d.amonth;r.year=d.ayear;
	r.hour=d.ahour;r.min=d.amin;r.sec=d.asec;
	// atm a;
	f1.open("transactions.txt",ios::app|ios::out);
	f1<<r.acc<<" "<<" "<<r.fname<<" "<<r.prev<<" "<<r.adl<<" "<<r.amt<<" "<<r.day<<" "<<r.month<<" "<<r.year<<" "<<r.hour<<" "<<r.min<<" "<<r.sec<<"\n";
	f1.close();
	// f2.open("accounts.txt",ios::in);	//finding current account details to accounts file for changing amount
    // f3.open("temp.txt",ios::out);
    // while(f2>>a.acc>>a.pin>>a.fname>>a.sname>>a.amt)
    // {
    // 	if(g.acc==a.acc){
    // 	a.amt=g.amt;
    // 	f3<<a.acc<<" "<<a.pin<<" "<<a.fname<<" "<<a.sname<<" "<<a.amt<<"\n";
    // }
    // }
	// f3.close();
	// f2.close();
    system("cls");
    frame_fix();
    gotoxy(18,12);
	cout<<"AMOUNT WITHDRAWN  : "<<r.adl<<" FINAL BALANCE : "<<r.amt;
	Sleep(3000);
    system("cls");
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       ";
	Sleep(100);
	gotoxy(30,16);
	cout<<"PLEASE COLLECT CASH \a\a";
	Sleep(1000);
    main_menu();getch();
}
void atm:: mini_statement(atm r){
	system("cls");
	fstream fm;
	int l;
	system("COLOR E0");
	for(int i=0;i<24;i++){
		gotoxy(2,i);
		cout<<"|";
		gotoxy(77,i);
		cout<<"|";
	}
	gotoxy(6,1);
	cout<<"DATE";
	gotoxy(17,1);
	cout<<"TIME";
	gotoxy(27,1);
	cout<<"TRANSACTION  TYPE";
	gotoxy(51,1);
	cout<<"AMOUNT";
	gotoxy(62,1);
	cout<<"FINAL BALANCE";
	atm n;			//checking account numer of current and to trasactions file
						//whenever it returns true it prints the transaction
	fm.open("transactions.txt",ios::in);
	l=3;
	while(fm>>n.acc>>n.fname>>n.prev>>n.adl>>n.amt>>n.day>>n.month>>n.year>>n.hour>>n.min>>n.sec){
		if(r.acc==n.acc){
			gotoxy(3,l);
			if(n.amt>n.prev && n.prev!=0){
                cout<<setw(2)<<n.day<<"/"<<setw(2)<<n.month<<"/"<<n.year<<"   "<<setw(2)<<n.hour<<":"<<setw(2)<<n.min<<":"<<setw(2)<<n.sec;
                cout<<setw(18)<<"CASH DEPOSITED"<<setw(15)<<n.adl<<setw(18)<<n.amt;
			}
			else if(n.amt<n.prev){
                cout<<setw(2)<<n.day<<"/"<<setw(2)<<n.month<<"/"<<n.year<<"   "<<setw(2)<<n.hour<<":"<<setw(2)<<n.min<<":"<<setw(2)<<n.sec;
                cout<<setw(19)<<"CASH WITHDRAWAL"<<setw(14)<<n.adl<<setw(18)<<n.amt;
			}
			else if(n.amt>n.prev&&n.prev==0){
                cout<<setw(2)<<n.day<<"/"<<setw(2)<<n.month<<"/"<<n.year<<"   "<<setw(2)<<n.hour<<":"<<setw(2)<<n.min<<":"<<setw(2)<<n.sec;
                cout<<setw(18)<<"ACCOUNT OPENED"<<setw(15)<<n.adl<<setw(18)<<n.amt;
			}
			l=l+2;
		}
	}
	fm.close();
	getch();
	system("cls");
	frame_fix();
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"      TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
	main_menu();
}
void atm::fast_cash(atm r){
	fstream fr,fs,ft;
	system("cls");
	frame_fix();
	int choice;
	atm g;
	g.prev=r.amt;
	g.acc=r.acc;
	strcpy(g.fname,r.fname);
	strcpy(g.sname,r.sname);
	g.pin=r.pin;
	gotoxy(26,5);
	flow("SELECT YOUR TRANSACTION AMOUNT");
	gotoxy(11,7);
	cout<<"100";
	gotoxy(11,12);
	cout<<"500";
	gotoxy(10,17);
	cout<<"1000";
	gotoxy(64,7);
	cout<<"1500";
	gotoxy(64,12);
	cout<<"2500";
	gotoxy(64,17);
	cout<<"5000 ";
	gotoxy(38,24);
	cout<<"";
	cin>>choice;
	switch(choice){
		case 1:
			g.adl=100;
			if(g.adl>r.amt)
			{
				system("cls");
				gotoxy(15,13);
				cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
				Sleep(1000);main_menu();
			}
			g.amt=r.amt-100;
			break;
		case 2:
			g.adl=500;
			if(g.adl>r.amt)
			{
				system("cls");
				gotoxy(15,13);
				cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
				Sleep(1000);main_menu();
			}
			g.amt=r.amt-500;
			break;
		case 3:
			g.adl=1000;
			if(g.adl>r.amt)
			{
				system("cls");
				gotoxy(15,13);
				cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
				Sleep(1000);main_menu();
			}
			g.amt=r.amt-1000;
			break;
		case 4:
			g.adl=1500;
			if(g.adl>r.amt)
			{
				system("cls");
				gotoxy(15,13);
				cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
				Sleep(1000);main_menu();
			}
			g.amt=r.amt-1500;
			break;
		case 5:
			g.adl=2500;
			if(g.adl>r.amt)
			{
				system("cls");
				gotoxy(15,13);
				cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
				Sleep(1000);main_menu();
			}
			g.amt=r.amt-2500;
			break;
		case 6:
			g.adl=5000;
			if(g.adl>r.amt)
			{
				system("cls");
				gotoxy(15,13);
				cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
				Sleep(1000);main_menu();
			}
			g.amt=r.amt-5000;
			break;
		default:
			cout<<"INVALID OPTION \a\a\a";
			Sleep(1000);
			main_menu();
	}
	date d;
	d.date_times();
	g.day=d.aday;g.month=d.amonth;g.year=d.ayear;
	g.hour=d.ahour;g.min=d.amin;g.sec=d.asec;
	//transacton APPENDING to transactions file
	// atm a;
	fr.open("transactions.txt",ios::app|ios::out);
	fr<<g.acc<<" "<<g.fname<<" "<<g.prev<<" "<<g.adl<<" "<<g.amt<<" "<<g.day<<" "<<g.month<<" "<<g.year<<" "<<g.hour<<" "<<g.min<<" "<<g.sec<<"\n";
	fr.close();
	// fs.open("accounts.txt",ios::in);
    // ft.open("temp.txt",ios::out);	//finding current account details to accounts file for changing amount
    // while(fs>>a.acc>>a.pin>>a.fname>>a.sname>>a.amt)
    // {
    // 	if(g.acc==a.acc)
    // 	a.amt=g.amt;
    // 	ft<<a.acc<<" "<<a.pin<<" "<<a.fname<<" "<<a.sname<<" "<<a.amt;
    // }
	// ft.close();
	// fs.close();
    system("cls");
    frame_fix();
    gotoxy(20,13);
	cout<<"AMOUNT WITHDRAWN : "<<g.adl<<" FINAL BALANCE : "<<g.amt;
	Sleep(3000);
    system("cls");
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       ";
	Sleep(100);
    gotoxy(32,16);
	cout<<"PLEASE COLLECT CASH \a\a";
	Sleep(1000);
	//delr1();	//calling file delete function bottom section of the code
    main_menu();
    getch();
}
void atm::fund_transfer(atm r){
	system("cls");
	frame_fix();

	fstream fk,fl,fm,fn;
	char racno[7],rracno[7];
	int famt;
	gotoxy(22,6);
	cout<<"ENTER RECEPIENT'S ACCOUNT NUMBER : ";
	cin>>racno;
	gotoxy(22,8);
	cout<<"CONFIRM ACCOUNT NUMBER           : ";
	cin>>rracno;
	if(strcmp(racno,rracno)==0){}
	else{
		system("cls");
		gotoxy(24,14);
		cout<<"GIVEN ACCOUNT NUMBER DOES NOT MATCH \a\a\a";
		Sleep(1000);
		main_menu();
	}
	gotoxy(22,11);
	cout<<"PLEASE ENTER AMOUNT              : ";
	cin>>famt;
	if(famt>r.amt){
		gotoxy(15,13);
		cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
		Sleep(1000);
		main_menu();
	}
	atm g;
	g.prev=r.amt;
	g.amt=r.amt-famt;
	g.adl=famt;
	g.acc=r.acc;
	strcpy(g.fname,r.fname);
	g.pin=r.pin;
	date d;
	d.date_times();
	g.day=d.aday;g.month=d.amonth;g.year=d.ayear;
	g.hour=d.ahour;g.min=d.amin;g.sec=d.asec;
			//transacton APPENDING to transactions file
	atm a,b;
	fstream f1;
	fl.open("transactions.txt",ios::app);
	fl<<g.acc<<" "<<g.fname<<" "<<g.prev<<" "<<g.adl<<" "<<g.amt<<" "<<g.day<<" "<<g.month<<" "<<g.year<<" "<<g.hour<<" "<<g.min<<" "<<g.sec<<"\n";
	f1.close();
			//finding current account details to accounts file for changing amount and also transfer account
	fm.open("accounts.txt",ios::in);
    fn.open("temp.txt",ios::out);
    while(fm>>a.acc>>a.pin>>a.fname>>a.sname>>a.amt){
    	if(g.acc==a.acc)		//transfer account
    	a.amt=g.amt;

    	else if(r.acc==a.acc){

    		b=a;
    		b.prev=a.amt;b.amt=a.amt+famt;b.adl=famt;	//transacton APPENDING to transactions file
    			fk.open("transactions.txt",ios::app);
				fk<<b.acc<<" "<<b.fname<<" "<<b.prev<<" "<<b.adl<<" "<<b.amt<<" "<<g.day<<" "<<g.month<<" "<<g.year<<" "<<g.hour<<" "<<g.min<<" "<<g.sec<<"\n";
				fk.close();

			a.amt=a.amt+famt;

    	}

    	fn<<a.acc<<" "<<a.pin<<" "<<a.fname<<" "<<a.sname<<" "<<a.amt<<"\n";
    }
	fn.close();
	fm.close();
	system("cls");
	frame_fix();
	gotoxy(18,13);
	cout<<"AMOUNT TRANSFERRED : "<<famt<<" FINAL BALANCE : "<<g.amt;
    Sleep(3000);
	system("cls");
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
    delr1();	//calling file delete function bottom section of the code
    main_menu();getch();
}
void atm::change_pin(atm g){
	system("cls");
	frame_fix();
	fstream fk,fl;
	int npin1,npin2;
	gotoxy(2,11);
	cout<<"YOUR PIN IS CONFIDENTIAL";
	gotoxy(2,13);
	cout<<"NOBODY SHOULD SEE THE PIN";
	gotoxy(2,15);
	cout<<"WHILE YOU ARE ENTERING IT.";
	gotoxy(2,17);
	cout<<"MAKE YOUR PIN MORE SECURE BY";
	gotoxy(2,19);
	cout<<"CHANGING IT FREQUENTLY.";
	gotoxy(30,6);
	cout<<"ENTER NEW PIN : ";
	cin>>npin1;
	gotoxy(30,8);
	cout<<"CONFIRM PIN   : ";
	cin>>npin2;
	atm a;
	if(npin1==npin2){
		fk.open("accounts.txt",ios::in);
    	fl.open("temp.txt",ios::out);	//finding current account details to accounts file for changing pin
  		while(fk>>a.acc>>a.pin>>a.fname>>a.sname>>a.amt){
  	  		if(g.acc==a.acc)
    		a.pin=npin1;
    		fl<<a.acc<<" "<<a.pin<<" "<<a.fname<<" "<<a.sname<<" "<<a.amt<<"\n";
  	  	}
		fl.close();
		fk.close();
	}
	else{
		gotoxy(40,16);
		cout<<"Password do not match try after some time \a\a\a";
		Sleep(1000);
		main_menu();
	}
	system("cls");
	frame_fix();
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"      TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
	delr1();	//calling file delete function bottom section of the code
	main_menu();
}
void atm::other_services(atm r){
	system("cls");
	system("COLOR 70");
	for(int i=0;i<25;i++){
		gotoxy(2,i);
		cout<<"|";
		gotoxy(77,i);
		cout<<"|";
	}
	gotoxy(3,0);
	cout<<"Good to see here ";
	gotoxy(59,0);
	cout<<"Mr./Ms."<<r.fname<<"_"<<r.sname;//name of user on top right
	gotoxy(32,1);
	gotoxy(32,1);
	cout<<"POINTS TO NOTE";gotoxy(3,3);
	flow("Ensure that you change the PIN number after first using your card also");gotoxy(3,4);
	flow("frequently change PIN number");
	gotoxy(3,6);
	flow("Ensure that nobody else can see you entering your PIN number at the ATM.");
	gotoxy(3,8);
	flow("Do not use the ATM machine when strangers are inside the ATM counter.");
	gotoxy(3,10);
	flow("Do not seek the assistance of strangers while operating the ATM machine.");
	gotoxy(3,12);
	flow("Should you notice anything strange or suspicious at the ATM counter please");
	gotoxy(3,13);
	flow("refrain from using  the same.");
	gotoxy(3,15);
	flow("Ensure that you check your account statement from time to time.");
	gotoxy(3,17);
	flow("In case you lose your ATM card call 1800-425-3800 to block your card and ");
	gotoxy(3,18);
	flow("this avoid misuse of the card.");
	gotoxy(3,20);
	flow("Do not disclose your PIN number to others IBO/RBI or any other Government,");
	gotoxy(3,21);
	flow("Banking institutions will never require you to disclose your PIN number.");
	gotoxy(3,23);
	flow("-------------------------------");
	gotoxy(45,23);
	flow("--------------------------------");
	gotoxy(35,23);
	cout<<" THANK YOU ";Sleep(1000);
	gotoxy(78,24);cout<<"";
	system("cls");
	system("color 2F");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
	main_menu();
}

//different function than all functions till
//access of all details of every user account
void atm :: admin(){
	char addname[15],pass[8];
	char adname[]="jhanveekhola";
	char password[]="pass_jhanvee";
	system("cls");
	gotoxy(25,13);
	cout<<"Enter name of the admin : ";
	cin>>addname;
	if(strcmp(adname,addname)==0){
		gotoxy(25,15);
		cout<<"Enter password : ";
		cin>>pass;
		if(strcmp(password,pass)==0){
			while(1){
				system("cls");
				int op;gotoxy(10,9);
				cout<<"1.ACCOUNT MEMBERS ";gotoxy(10,11);
				cout<<"2.ACCOUNT TRANSACTIONS ";gotoxy(10,13);
				cout<<"3.MAIN MENU ";gotoxy(10,16);
				cout<<"Select : ";
				cin>>op;
				if(op==1){
					system("cls");
					fstream fy;atm b;int i=3;
					fy.open("accounts.txt",ios::in);//all information from accounts file
					gotoxy(0,1);
					cout<<"ACCOUNT NUMBER		PIN NUMBER	FULL NAME	AVAILABLE BALANCE";
			  		while(fy>>b.acc>>b.pin>>b.fname>>b.sname>>b.amt){
 		  				gotoxy(2,i);
    					cout<<b.acc<<"		"<<b.pin<<"		"<<b.fname<<" "<<b.sname<<" "<<b.amt;
    					i=i+2;
  	  				}
  	  				fy.close();
  	  				getch();
				}
				else if(op==2){
					system("cls");
					fstream fz;atm z;int l;
					gotoxy(6,1);
					cout<<"DATE";
					gotoxy(17,1);
					cout<<"TIME";
					gotoxy(27,1);
					cout<<"TRANSACTION  TYPE";
					gotoxy(51,1);
					cout<<"AMOUNT";
					gotoxy(62,1);
					cout<<"FINAL BALANCE";
					fz.open("transactions.txt",ios::in);	//all information from transactions file
					l=3;
					while(fz>>z.acc>>z.fname>>z.prev>>z.adl>>z.amt>>z.day>>z.month>>z.year>>z.hour>>z.min>>z.sec){
							gotoxy(3,l);
							if(z.amt>z.prev&&z.prev!=0){
								cout<<setw(2)<<z.day<<"/"<<setw(2)<<z.month<<"/"<<z.year<<"   "<<setw(2)<<z.hour<<":"<<setw(2)<<z.min<<":"<<setw(2)<<z.sec;
								cout<<setw(18)<<"CASH DEPOSITED"<<setw(15)<<z.adl<<setw(18)<<z.amt;
							}
							else if(z.amt<z.prev){
								cout<<setw(2)<<z.day<<"/"<<setw(2)<<z.month<<"/"<<z.year<<"   "<<setw(2)<<z.hour<<":"<<setw(2)<<z.min<<":"<<setw(2)<<z.sec;
								cout<<setw(19)<<"CASH WITHDRAWAL"<<setw(14)<<z.adl<<setw(18)<<z.amt;
							}
							else if(z.amt>z.prev&&z.prev==0){
								cout<<setw(2)<<z.day<<"/"<<setw(2)<<z.month<<"/"<<z.year<<"   "<<setw(2)<<z.hour<<":"<<setw(2)<<z.min<<":"<<setw(2)<<z.sec;
								cout<<setw(18)<<"ACCOUNT OPENED"<<setw(15)<<z.adl<<setw(18)<<z.amt;
							}
							l=l+2;
					}

					fz.close();
					getch();
				}
				else{
					system("cls");gotoxy(35,13);
					cout<<"INVALID OPTION \a\a\a";
					main_menu();
				}
			}
		}
		else{
			system("cls");
			gotoxy(25,17);
			cout<<"INVALID USERNAME OR PASSWORD \a\a\a";
			getch();main_menu();
		}
	}
}
void atm::note(){
	system("color F0");
	gotoxy(10,3);
	cout<<"THANK YOU FOR USING OUR ATM SERVICE";gotoxy(10,7);
	cout<<"THIS IS THE PROJECT DONE FOR 1ST YEAR 2ND SEM SUBMISSION.";gotoxy(10,8);
	cout<<"THE PROJECT HAVE BEEN CODED IN C++.";gotoxy(10,10);
	cout<<"THANKS AGAIN!!!!!";gotoxy(10,17);
	cout<<"CONTACT US AT : XXXXX@GMAIL.COM";gotoxy(24,18);
	gotoxy(58,22);
	cout<<"IGDTUW, DELHI";
	getch();
	exit(0);
}
atm atm::login_check(){
	system("cls");
	system("COLOR 1F");
	frame();
	int apin=0,aacno=0;
	int cnt,e=0;
	char x,y;char p1,p2,p3,p4;p1=p2=p3=p4=0;
	char ans;
	gotoxy(3,5);
	cout<<"enter any number";
	gotoxy(3,7);
	cout<<"between 10 and 99";
	gotoxy(3,9);
	cout<<"for eg. 25 ";
	gotoxy(3,12);
	cout<<"Press y if the";
	gotoxy(3,14);
	cout<<"number is displayed";
	gotoxy(3,17);
	cout<<"Press n if the";
	gotoxy(3,19);
	cout<<"number is not displayed";
	gotoxy(77,23);
	x=getche();
	gotoxy(76,23);
	cout<<"   ";
	gotoxy(38,23);
	cout<<x;
	gotoxy(77,23);
	y=getche();
	gotoxy(76,23);
	cout<<"   ";
	gotoxy(39,23);
	cout<<y;
	gotoxy(65,14);
	cout<<" ";
	ans=getche();
	if(ans=='y'||ans=='Y'){}
	else
	main_menu();
	system("cls");
	gotoxy(24,12);
	cout<<" PLEASE ENTER YOUR ACCOUNT NUMBER ";
	gotoxy(37,16);
	cin>>aacno;
	system("cls");
	frame();
	gotoxy(34,2);
	cout<<"PSUP ATM SYSTEM";
	gotoxy(56,2);
	cout<<"                        ";
	gotoxy(32,5);
	cout<<"PLEASE ENTER YOUR PIN : ";
	cin>>apin;
	gotoxy(2,12);
	cout<<"YOUR PIN IS CONFIDENTIAL";
	gotoxy(2,13);
	cout<<"NOBODY SHOULD SEE THE PIN";
	gotoxy(2,15);
	cout<<"WHILE YOU ARE ENTERING IT.";
	gotoxy(2,17);
	cout<<"MAKE YOUR PIN MORE SECURE BY";
	gotoxy(2,19);
	cout<<"CHANGING IT FREQUENTLY.";
	gotoxy(38,22);
	/*apin=getche();
	gotoxy(36,22);
	cout<<"        ";
	gotoxy(39,9);
	cout<<"X"<<"\a";
	gotoxy(38,22);
	apin=getche();
	gotoxy(36,22);
	cout<<"       ";
	gotoxy(40,9);
	cout<<"X"<<"\a";
	gotoxy(38,22);
	apin=getche();
	gotoxy(36,22);
	cout<<"        ";
	gotoxy(41,9);
	cout<<"X"<<"\a";
	gotoxy(38,22);
	apin=getche();
	gotoxy(36,22);
	cout<<"        ";
	gotoxy(42,9);
	cout<<"X"<<"\a";*/
	fstream fg;
	atm b,q;
	fg.seekg(0);
	fg.open("accounts.txt",ios::in);
	while(fg>>b.acc>>b.pin>>b.fname>>b.sname>>b.amt){
		if(aacno==b.acc){
			q=b;
			if(apin==b.pin){
				gotoxy(2,8);
				cout<<"HELLO "<<b.fname<<" "<<b.sname;
				Sleep(1000);
				return q;
				cnt++;
			}
			else{
				Sleep(1000);
				cout<<"\a\a\aINCORRECT PIN";
				login_check();
				e++;
			}
        }
	}
	if(cnt==0&&e<3){
		gotoxy(30,24);
		cout<<"No account exits of given data. ";
		sub_menu();
	}
    else if(cnt==0&&e==3){
        gotoxy(30,24);
        cout<<"\nThe service for respective account is temporarily stopped. Please try again later.";
        main_menu();
    }
	fg.close();
}
void delr1(){
	char ac[]="accounts.txt";
	int aaa;
		//system function (remove) in stdio.h header
	aaa=remove(ac);
	cout<<"\n\ndel "<<aaa;
	delr2();
}
void delr2(){
	char acc[]="accounts.txt";
	char tmp[]="temp.txt";
	int bbc;
		//system function (rename) in stdio.h header
	bbc=rename(tmp,acc);
	cout<<" ren"<<bbc;
}

int main(){
	scroll_note();
	atm m;
	m.main_menu();
	return 0;
}
