#include <iostream>
#include<mysql.h>
//#include<mysqld_error.h>
#include<typeinfo>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
char HOST[]="localhost";
char PASS[]="A@62sql#";
char USER[]="root";
MYSQL* obj;
void regi(){
	char username[20];
	char password[20];
	rewind(stdin);
	cout<<"username: ";
	cin.getline(username,20,'\n');
	
	
	cout<<"password: ";
	cin.getline(password,20,'\n');
	
	string sentence="INSERT INTO login (username,password) VALUES ('%s','%s')";
	char *sen=new char[sentence.length()+1];
	strcpy(sen,sentence.c_str());
	char *consult=new char[strlen(sen)+strlen(username)+strlen(password)];
	sprintf(consult,sen,username,password);
	
	if(mysql_ping(obj)){
		cout<<"Error: connection is not sync";
		cout<<mysql_error(obj);
	};
	if(mysql_query(obj,consult)){
		string err=mysql_error(obj);
		if(err.substr(0,15)=="Duplicate entry"){
			cout<<"you are already loged in"<<endl;
		}else{
			cout<<"Error: "<<err<<endl;
		};
		rewind(stdin);
		getchar();
	}else{
		cout<<"registration successful"<<endl;
	};
	mysql_store_result(obj);
	
};
void log(){
	char username[20];
	char password[20];
	rewind(stdin);
	cout<<"username: ";
	cin.getline(username,20,'\n');
	
	cout<<"password: ";
	cin.getline(password,20,'\n');
	
	string sentence="SELECT password FROM login WHERE username='%s'";
	char *sen=new char[sentence.length()+1];
	strcpy(sen,sentence.c_str());
	char *consult=new char[strlen(sen)+strlen(username)];
	sprintf(consult,sen,username);
	
	if(mysql_ping(obj)){
		cout<<"Error: connection is not sync";
		cout<<mysql_error(obj);
	};
	if(mysql_query(obj,consult)){
		cout<<"Error: "<<mysql_error(obj)<<endl;
		rewind(stdin);
		getchar();
	};
	MYSQL_RES *result=mysql_store_result(obj);
	MYSQL_ROW row=mysql_fetch_row(result);
//	MYSQL_FIELD *field=mysql_fetch_field(result);
	if(row==NULL){
		string e=mysql_error(obj);
		if(e!=""){
			cout<<"Error: "<<e<<endl;
		}else{
			cout<<"you don't have an account"<<endl;
		}
	}else{
		if(password==string(row[0])){
			cout<<"you are loged in"<<endl;
		}else{
			cout<<"wrong password"<<endl;
		}
	}
}
int main() {
	
	string username;
	string password;
	
	
	bool isprogramopen=true;
	
	//-----------------------------------
	if(!(obj=mysql_init(0))){
		cout<<"Error: mysql object can't initilize"<<endl;
		cout<<mysql_error(obj)<<endl;
	}else{
		if(!mysql_real_connect(obj,HOST,USER,PASS,"school",3306,NULL,0)){
			cout<<"Error: can't coonnect and sync"<<endl;
			cout<<mysql_error(obj)<<endl;
		}else{
			cout<<"log in"<<endl<<endl;
			while(isprogramopen){
				cout<<" [1]: register \n [2]: log in \n [3]: exit"<<endl;
				char ch;
				ch=getchar();
				rewind(stdin);
				switch(ch){
					case '1':
						regi();
						break;
					case '2':
						log();
						break;
					case '3':
						isprogramopen=false;
						break;
					default:
						cout<<"choose correct options"<<endl;
				};
			}
		}
	};
	cout<<"bye";
	return 0;
}
