#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<sstream>
#include<ctime>
#include<stdlib.h>

using namespace std;

//Assign class

class assign{
	public:
		void all_students();
		void sing_student();
};

//Task class

class atask:public assign
{
	protected:
	char task[100];
	public:
		void create_task();
		void assign_task();
		void update_task();
		void delete_task();
		void view_sol();
};

//Admin Class
class admin:public atask
{
	protected:
	char fpass[10];
		int UID;
		//string fpassword;
	public:
		void ainput();
		void forgot();
		void display_submission();//create a file with task submissions of students.
};


int regno;
class stask{
	char ques[100];
	public:
		
		void view_task();
		void submit_task();
		//svoid check_date();	
				
};

class student:public stask
{
	//string spassword;
	char s[10];
	string name;
	public:
		void sinput();
		void forgot();//To be added inside input.
};

//Class Person
class person:public admin,public student
{
	int n;
	public:
		void select()
		{
			cout<<"--------------------------------------------------------------------------------\n"<<endl;
			cout<<"\n\n\t\tSelect\n\t\t1.Faculty\n\t\t2.Student\n\n\t\t";
			cin>>n;
			if(n==1)
			{
				admin::ainput();
			}
			else if(n==2)
			{
				student::sinput();
			}
			else
			{
				cout<<"\n\n\t\tPlease Choose Correct Option.";
				select();
			}
			
		}
};

void admin::ainput()
{
	system("cls");
cout<<"\n\n\t\tWelcome Dear Faculty"<<endl;
	cout<<"\n\t\tEnter the UID\n\n\t\t->";
	cin>>UID;
	cout<<"\n\t\tEnter the password\n\n\t\t->";
	char s[10];
	int i;
	for(i=0;i<10;i++)
	{
		s[i]=_getch();
		if (s[i] == 13)
		{
			s[i]='\0';
			break;
		} 
		 _putch('*');
		 
        
	}
	
	string Fpass(s);
	
	//cin>>fpassword;
	fstream file;
	file.open("faculty.txt");
	if(!file)
	{
		cout<<"\n\t\t!Error Occurred"<<endl;
	}
	int id;
	string pass;
	string name;
	file>>id;
	file>>pass;
	file>>name;
	if( Fpass == pass && UID == id)
	{
		
		
		cout<<"\n\t\t---------------Successfully LoggedIn---------------";
		
		cout<<"\n\t\tWelcome "<<name<<endl<<"\n\n\n";
		system("pause");
		
		cout<<"\n\t\t1.Create Task\n\t\t2.Assign Task\n\t\t3.Update Task\n\t\t4.Delete Task\n\t\t5.View Solutions\n\n\t\t";
		int z;
		cin>>z;
		switch(z)
		{
			
		case 1: atask::create_task();break;
		case 2: atask::assign_task();break;
		case 3: atask::update_task();break;
		case 4: atask::delete_task();break;
		case 5: atask::view_sol();break;
		default:{
		cout<<"\n\t\tNo such Option"<<endl;
		}
}
}
	else
	{
		cout<<"\n\n\t\txx-!Wrong details-xx."<<endl;
		cout<<"\n\t\tForgot Password?(Y/N)\n\t\t->";
		char ch;
		cin>>ch;
		if(ch=='Y'||ch=='y')
		{
			admin::forgot();
		}
		else if(ch=='N'||ch=='n')
		{
			admin::ainput();
		}
	}

}
void admin::forgot()
{
	system("cls");
	string apass;
	string cpass;
	cout<<"\n\t\tChanging Your Password\n";
	cout<<"\n\t\tEnter your ID"<<endl;
	cin>>UID;
	cout<<"\n\t\tEnter your new password"<<endl;
	cin>>apass;
	cout<<"\n\t\tEnter your Password Again"<<endl;
	cin>>cpass;
	ofstream fout;
	fout.open("faculty.txt",ios::out);
	if(apass.compare(cpass)==0)
	{
	fout<<UID<<endl;
	fout<<apass;
	cout<<"\n\t\tYour Details are succesfully Updated";
	}
	else
	{
		cout<<"\n\t\tPasswords donot Match please enter again."<<endl;
		forgot();
	}
}

void atask::create_task()
{
	system("cls");
	static int m=0;
	m++;
	cout<<"\n\n\t\t\t\tCreating TASK\n\n";
	
	cout<<"\n\t\t\t--------Enter the task "<<m<<"--------\n\n\t\t\t->";
	cin.ignore(); 
	string task;
	getline(cin,task);
	fstream fout;
	ofstream fdate;
	fout.open("Task.txt",ios::out|ios::app);
	fdate.open("Date.txt",ios::out);
	if(!fout)
	{
		cout<<"\n\t\t\tError Opening File Task";
		exit(1);
	}
	fout<<m<<" ";
	fout<<task<<endl;
	
	int dd,mm,yyyy;
	cout<<"\n\t\tEnter the Date of submission(dd/mm/yyyy)\n\t\t\t->";
	cin>>dd>>mm>>yyyy;
	
	fdate<<dd<<"/"<<mm<<"/"<<yyyy<<endl;
	
	cout<<"\n\n\n\t\t\tTask "<<m<<" Created Successfully."<<endl;
	cout<<"\n\n\t\t\tDo you want to create Another task?(Y/N)\n\n\t\t\t";
	char ch;
	cin>>ch;
	if(ch=='Y'||ch=='y')
	{
		create_task();
	}
	else
	{	
	fout.close();
	fdate.close();
		cout<<"\n-------------------------------------------------------------------------";
		cout<<"\n\t\t\t1.Assign Task\n\t\t\t2.Update Task\n\t\t\t3.Delete Task\n\n\t\t";
		int z;
		cin>>z;
		switch(z)
		{
			
		case 1: atask::assign_task();break;
		case 2: atask::update_task();break;
		case 3: atask::delete_task();break;
		default:{
		cout<<"\n\t\tNo such Option"<<endl;
		}
		
    }
}
}
void atask::assign_task()
{
	system("cls");
	cout<<"\n\n\t\t   --------------------Assigning Tasks-----------------------   "<<endl;
	y:cout<<"\n\t\t1.Assign Task To All Students.\n\t\t2.Assign Task to a single student.\n\n\t\t->";
	int n;
	cin>>n;
	switch(n)
	{
		case 1: assign::all_students();cin.ignore();break;
		case 2: assign::sing_student();break;
		default: 
		{
			cout<<"\n\t\tNo such Option.";
			goto y;
		}
	}	
	
};


void atask::update_task()
{
	system("cls");
	string uques;
	cout<<"\n\n\t\t-----------UPDATE TASK-------------\n";
	fstream rfile;
	rfile.open("Task.txt",ios::in|ios::out);
	ofstream ufile;
	ufile.open("Utask.txt",ios::out);
	int len=0;
	rfile.seekg(0,ios::end);
	len=rfile.tellg();
	rfile.seekg(0,ios::beg);
	int n;
	cout<<"\n\t\tEnter the task which you want to UPDATE\n\t\t"<<endl;
	cin>>n;
	cin.ignore();
	int num;
	while(len>0)
	{
		len=len-sizeof(class admin);
		rfile>>num;
		if(num==n)
		{
			cout<<"\n\t\tEnter the task\n\t\t";
			getline(cin,uques);
			ufile<<uques;
			cout<<"\n\t\tUpdating Task"<<n<<endl;
		}
	}
	rfile.close();
	ufile.close();
	remove("Task.txt");
	rename("Utask.txt","Task.txt");
	cout<<"\n\t\tAssigning the Updated Task\n"<<endl;
	system("pause");
	
	assign_task();
	
}


void atask::delete_task()
{
	system("cls");
	cout<<"\n\t\t----------------Deleting Tasks-------------"<<endl;
	fstream ftask;
	fstream ftaskall;
	fstream fstud;
	cout<<"\n\t\tDo You want to delete All the tasks or Task for a Single Student\n\t\t";
	cout<<"\n\t\t1)All Students\n\t\t2)Single Student\n\t\t";
	int n;
	cin>>n;
	int regno;
	switch(n)
	{
	case 1:
	{
	ftask.open("Task.txt",ios::out);
	ftaskall.open("TaskAll.txt",ios::out);
	ftaskall.close();
	ftask.close();
	cout<<"\n\t\tTasks Successfully Deleted"<<endl;
	break;
	}
	case 2:
	{
		cout<<"\n\tEnter the Regestration Number of the student Which You want to delete"<<endl;
		cin>>regno;
		
		
		int oreg;
	oreg=regno;
	ostringstream str;
	str<<oreg;
	string oreg1 = str.str();
	
	oreg1.append(".txt");
	
	const char* filename = oreg1.c_str();
		
		fstud.open(filename,ios::out);
		fstud.close();
		
		cout<<"\n\t\tTasks Successfully Deleted"<<endl;
		break;
	}
	default:
		{
			cout<<"\n\t\tNo such Option.";
			atask::delete_task();
		}

}
}

void atask::view_sol()
{
	system("cls");
	string ans;
	fstream fview;
	fview.open("Answers.txt");
	if(fview.good())
	{
		cout<<"n\t\t--------Viewing Solutions Submitted by Students--------"<<endl;
		while(fview.good())
		{
			getline(fview,ans);
			cout<<ans<<endl;
		}	
	}
	else
	{
		cout<<"\n\t\t---------No solutions Are submitted By the student"<<endl;
	}
}

void assign::all_students()
{
	system("cls");
	cout<<"\n\t\t-------Assign Task to All students-------\n\n";
	
	int regno;
	int i=70;
	char ch;
	string ques;
	ifstream fin;
	ofstream fnew;
	fin.open("Task.txt");
	fnew.open("TaskAll.txt",ios::out|ios::app);
	while(fin.eof()==0)
	{
	getline(fin,ques);
	fnew<<ques<<endl;
	}
	fnew.close();
	fin.close();
	
	cout<<"\n\t\t\tTask Assigned To All Students"<<endl;
	system("pause");
}
void assign::sing_student()
{
	system("cls");
	string reg;
	cout<<"\n\t\tEnter the Regestration number of the student.\n\t\t->"<<endl;
	cin>>reg;
	
	ifstream fin;
	fin.open("Regno.txt");
	
	ofstream fout;
	
	ifstream file;
	file.open("Task.txt");
	char ques[80];
	file.read((char *)&ques,80);
	file.close();
	
	int oreg;
	while(fin.eof()==0)
	{
		fin>>oreg;
		ostringstream str;
		str<<oreg;
		string regno1 = str.str();
		
		if(regno1==reg)
		{
			regno1.append(".txt");
			const char* filename = regno1.c_str();
			cout<<"\n\t\t\t<--Regno. Matched-->\n\t\t\t";
			fout.open(filename,ios::out);
			fout.write((char *)&ques,sizeof(ques));
			fout.close();
		}
	}
	fin.close();
	
	cout<<"\n\t\tTask Assigned To student With RegNo."<<reg<<endl;
	system("pause");
}


void student::sinput()
{
	system("cls");
	cout<<"\n\t\t\t----------Welcome student---------"<<endl;
	cout<<"\n\t\tEnter the REGESTRATION ID\n\n\t\t->";
	cin>>regno;
	cout<<"\n\t\tEnter the password\n\n\t\t->";
	
	char s[10];
	int i;
	for(i=0;i<10;i++)
	{
		s[i]=_getch();
		if (s[i] == 13)
		{
			s[i]='\0';
			break;
		} 
		 _putch('*');
		 
        
	}
	
	string Spass(s);
	
	//cin>>spassword;
	fstream fin;
	fin.open("students.txt");
	int reg;
	string pass;
	string name;
	
	fin>>reg;
	fin>>pass;
	fin>>name;
	if(regno==reg && pass==Spass)
	{
		cout<<"\n\t\t----------You Are successfully LoggedIn-----------\n\t\t"<<endl;
		cout<"\n\t\tYour Details:-\n";
		cout<<"\n\t\tName"<<"                             "<<"Regno."<<endl;
		cout<<"\t-----------------------------------------------------------------";
		cout<<"\n\t\t"<<name<<"                 "<<reg<<endl;
		cout<<"\t-----------------------------------------------------------------";
		cout<<"\n\t\t1)View Task\n\n\t\t2)Submit Task";
		int n;
		cout<<"\n\t\t";
		cin>>n;
		switch(n)
		{
			case 1: stask::view_task();break;
			case 2:stask::submit_task();break;
			default:{
				cout<<"\n\t\tNo such options";
				break;
			}
		}
		
		
	}
	else
	{
		cout<<"\n\n\t\txx-!Wrong details-xx."<<endl;
		cout<<"\n\t\tForgot Password?(Y/N)\n\t\t->";
		char ch;
		cin>>ch;
		if(ch=='Y'||ch=='y')
		{
			student::forgot();
		}
		else if(ch=='N'||ch=='n')
		{
			student::sinput();
		}
	}
}


void student::forgot()
{
	system("cls");
	string spass;
	string cpass;
	cout<<"\n\t\tChanging Your Password\n";
	cout<<"\n\t\tEnter your ID\n\n\t\t";
	cin>>regno;
	cout<<"\n\t\tEnter your name\n\n\t\t";
	cin>>name;
	cout<<"\n\t\tEnter your new password\n\n\t\t";
	cin>>spass;
	cout<<"\n\t\tEnter your Password Again\n\n\t\t";
	cin>>cpass;
	
	ofstream fout;
	fout.open("students.txt",ios::out);
	if(spass.compare(cpass)==0)
	{
	fout<<regno<<endl;
	fout<<spass<<endl;
	fout<<name<<endl;
	cout<<"\n\t\tYour Details are succesfully Updated";
	}
	else
	{
		cout<<"\n\t\tPasswords donot Match please enter again."<<endl;
		student::forgot();
	}
}


void stask::view_task()
{
	system("cls");
	cout<<"\n\t\t---------------Viewing Task------------";
	cout<<"\n\n\t\tYour regestration number is:"<<regno<<endl;
	
	fstream fall;
	fstream fsin;
	fstream fdate;
	string ques;
	//int dd,mm,yyyy;
	string date;
	char ch;
	
	fall.open("TaskAll.txt",ios::in);
	fdate.open("Date.txt",ios::in);
	if(fall.good())
	{
		cout<<"\n\t\tThe Task Assigned to you is:-"<<endl;
		while(fall.good())
		{
			getline(fall,ques);
			cout<<"\n\t\t"<<ques<<endl;
		}
		getline(fdate,date);
		cout<<"\n\t\tThe last date of submission is:-"<<date<<endl;
	}
	else
	{
	int oreg;
	oreg=regno;
	ostringstream str;
	str<<oreg;
	string oreg1 = str.str();
	
	oreg1.append(".txt");
	
	const char* filename = oreg1.c_str();
	fsin.open(filename,ios::in);
	if(fsin.good())
{
	cout<<"\n\tThe task Assigned to you is:-\n\t";
	while(fsin.good())
	{
		getline(fsin,ques);
		cout<<"\n\t\t"<<ques<<endl;
		getline(fdate,date);
		cout<<"\n\t\tLast Date is:-"<<date<<endl;	
	}
	
}
else
{
	cout<<"\n\t\tNo Task is Assigned To You."<<endl;
}
	
	
	}
	fall.close();
	fsin.close();
	exit(1);
}


void stask::submit_task()
{
	system("cls");
	static int m=0;
	cout<<"\n\t\t----------Submitting Task----------\n\t\t";
	cout<<"\n\t\tEnter the answers"<<endl;
	cout<<"\n\t\tEnter the number of questions you want to answer"<<endl;
	string  ans;
	int n;
	
	ofstream fout;
	fout.open("Answers.txt",ios::out);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		m++;
		cout<<"\n\t\tAnswering Question Number "<<m;
		getline(cin,ans);
		fout<<m<<"->"<<" "<<ans<<endl;
	}
	cout<<"\n\t\tYour Answers are successfully Submitted"<<endl;
}

int main()
{
	system("color F1");
	
	cout<<endl;
	time_t tt;
	struct tm *ti;
	time(&tt);
	ti=localtime(&tt);
	cout<<asctime(ti);
	
	cout<<"--------------------------------------------------------------------------------"<<endl;
	
	admin a;
	student s;
	person p;
	cout<<"\t\t\t-------------------------";
	cout<<"\n\t\t\t|     Class Calendar    |";
	cout<<"\n\t\t\t-------------------------\n\n";
		
	p.select();	
}
