#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class Customer
{
	private:
   		 char id[10],numOfDays[10],name[15],extra[100],typeOfRoom[6];
	public:
		void readCustomer()
		{
			fstream rfile;
			rfile.open("customer.txt",ios::in);
			cout << "\n_________________\n\n";
        		cout << "Read Customer Bookings:";
			cout << "\n_________________\n\n";
			cout<<"******-------Name\tId\tType Of Room\tNum Of Room-------*******\n\n";
			while(!rfile.eof())
			{
				rfile.getline(name,30,'|');
				rfile.getline(id,30,'|');
				rfile.getline(typeOfRoom,10,'|');
				rfile.getline(numOfDays,10,'|');
				rfile.getline(extra,100,'\n');
				cout<<name<<"\t";
    				cout<<id<<"\t";
    				cout<<typeOfRoom<<"\t";
    				cout<<numOfDays<<"\n\n";
			}
		}

		void writeCustomer()
		{
			fstream ifile;
			char buf[100],check;
			ifile.open("customer.txt",ios::out|ios::app);
    			char ch; 
    			do
    			{
    				Customer c;
    				cout << "\n_________________\n\n";
        			cout << "Add a New Booking: ";
				cout << "\n_________________\n\n";
        			cout << "Enter Your Name: ";
        			cin >>name;
        			bool valid = true;
        			for(int i = 0; i < strlen(c.name); i++)
        			{
        				if(isspace(name[i]) || !isalpha(name[i])){
        				valid = false;
        				break;
				}	 
			}
			if(strlen(name) < 3)
				valid = false;
			while(!valid)
			{
				valid = true;
        			cout << "Enter a valid name: "; 
        			cin >>name;
				for(int i = 0; i < strlen(name); i++)
				{
        				if(isspace(name[i]) || !isalpha(name[i]))
        				{
        					valid = false;
        					break;
					}	 
	    			 } 	
	     			if(strlen(name) < 3) 
	     				valid = false;
			}		
      			cout << "Enter your Id: "; 
        		cin >>id;
        		cout << "Do you want single room or double ? (Single/Double): "; 
        		cin >>typeOfRoom;	
        		cout << "Enter the number of days you will book: "; 
        		cin >>numOfDays;
        		cout << "**************************************************\nAdd Another Booking ? (y/press any character such (n)): ";
        		cin >> ch;
        		strcpy(buf,name);
        		strcat(buf,"|");
        		strcat(buf,id);
        		strcat(buf,"|");
        		strcat(buf,typeOfRoom);
        		strcat(buf,"|");
        		strcat(buf,numOfDays);
        		strcat(buf,"|");
        		strcat(buf,"\n");
        		ifile.write(buf,strlen(buf));
        		cout<<"***********************Customer added Successfuly**********************\n";
    		}while(ch == 'y' || ch == 'Y');
   		ifile.close();
	}
	void searchCustomer()
		{
   			int flag=0;
    			fstream sfile;
    			char x[10];
    			cout << "\n_________________\n\n";
        		cout << "Search Customer Bookings:";
			cout << "\n_________________\n\n";
   			sfile.open("customer.txt",ios::in);
    			cout<<"Enter the Id to be searched\n";
    			cin>>x;
    			
    			while(!sfile.eof())
    			{
    				sfile.getline(name,20,'|');
    				sfile.getline(id,20,'|');
    				sfile.getline(typeOfRoom,20,'|');
    				sfile.getline(numOfDays,20,'|');
    				sfile.getline(extra,100,'\n');
    				if(strcmp(x,id)==0)
    				{
    					cout<<"\t______________Customer Id Found_______________\n";
    					cout<<"\tName\t\t\tId\tType Of Room\tNum Of Room\n";
    					cout<<name<<"\t";
    					cout<<id<<"\t";
    					cout<<typeOfRoom<<"\t";
    					cout<<numOfDays<<"\t";
    					cout<<"\n";
    					flag=1;
    					break;
    				}

    			}
    			if(flag==0)
    				cout<<"__________________Customer Id not Found______________\n";
    			
		}
		void updateCustomer()
		{
    			Customer c;
    			int flag=0;
    			fstream ufile,unfile,udfile;
   			ufile.open("customer.txt" , ios::in | ios::out|ios::app);
    			cout << "\n_________________\n\n";
        		cout << "Update Customer Bookings:";
			cout << "\n_________________\n\n";
   			bool found = false;
    			char x[10];
    			cout<<"Enter Id to be updated\n";
    			cin>>x;
    			char buf[100];
    			Customer a[100];
    			int i=0,j=0,k=0;
    			while(!ufile.eof())
   			{
    				ufile.getline(a[i].name,30,'|');
    				ufile.getline(a[i].id,30,'|');
    				ufile.getline(a[i].typeOfRoom,30,'|');
    				ufile.getline(a[i].numOfDays,30,'|');
    				ufile.getline(extra,100,'\n');
    				i++;
    			}
   			for(k=0;k<i;k++)
    			{
    				if(strcmp(a[k].id,x)==0)
    				{
    					cout<<"Enter new number of days you want to stay\n";
    					cin>>a[k].numOfDays;
    					cout<<"___________________New Upadated details are__________________\n";
    					cout<<"Name\tId\tType of Room\tNum of Days\n";
    					cout<<a[k].name<<"\t";
    					cout<<a[k].id<<"\t";
    					cout<<a[k].typeOfRoom<<"\t";
    					cout<<a[k].numOfDays<<"\t";
    					flag=1;
    			 		cout<<"_______________________Customer Updated Successfuly____________________________\n";
    					break;
    				}
    			}
    			ufile.close();
    			if(flag==0)
    				cout<<"__________________Customer Id not Found______________\n";
    				
    			//udfile.open("customer.txt",ios::trunc);
    			//udfile.close();
    			remove("customer.txt");
    			unfile.open("customer.txt",ios::app|ios::out);
    			for(j=0;j<i;j++)
    			{
    				strcpy(buf,a[j].name);
        			strcat(buf,"|");
        			strcat(buf,a[j].id);
        			strcat(buf,"|");
        			strcat(buf,a[j].typeOfRoom);
        			strcat(buf,"|");
        			strcat(buf,a[j].numOfDays);
        			strcat(buf,"|");
        			strcat(buf,"\n");
        			unfile.write(buf,strlen(buf));
    	
    			}
    			unfile.close();  
    			//remove("customer.txt");
    			//rename("customer2.txt","customer.txt");
		}
		void deleteRecordCustomer()
		{
    			Customer a[100];
    			int i=0,j=0,k=0,flag=1;
    			char buf[100];
    			fstream dfile,nfile,afile;
    			cout << "\n_________________\n\n";
        		cout << "Delete Customer Bookings:";
			cout << "\n_________________\n\n";
    			dfile.open("customer.txt",ios::out|ios::in);
    			cout << "Delete Booking:- ";
    			cout << "\n______________\n\n";
    			char x[10];
    			cout << "Enter Id Of Customer To Delete: "; 
    			cin >> x;
    			while(!dfile.eof())
    			{
    				dfile.getline(a[i].name,20,'|');
    				dfile.getline(a[i].id,20,'|');
    				dfile.getline(a[i].typeOfRoom,20,'|');
    				dfile.getline(a[i].numOfDays,20,'|');
    				dfile.getline(extra,100,'\n');
    				i++;
   			 }
   			 dfile.close();
   			// nfile.open("customer.txt",ios::trunc);
   			// nfile.close();
   			remove("customer.txt");
   			afile.open("customer.txt",ios::out|ios::app);
    			for(j=0;j<i;j++)
   			{
    				if((strcmp(x,a[j].id))!=0)
    				{
    					strcpy(buf,a[j].name);
       					strcat(buf,"|");
        				strcat(buf,a[j].id);
       	 				strcat(buf,"|");
        				strcat(buf,a[j].typeOfRoom);
        				strcat(buf,"|");
        				strcat(buf,a[j].numOfDays);
       					strcat(buf,"|");
       					strcat(buf,"\n");
       					afile.write(buf,strlen(buf));
       				}
       				if(strcmp(x,a[j].id)==0)
       					flag=0;
    			 
    			}
    			if(flag==0)
    				cout<<"__________________Customer Deleted Successfuly_____________\n";
    			else
    				cout<<"__________________Customer Id not Found______________\n";	
    			afile.close();	
    			//remove("customer.txt");
    			//rename("customer1.txt","customer.txt");
    		}
	
};
class room
{
	private:
		char room_no[10],room_price[10],room_type[10],room_view[10],buf[100],extra[100];
	public:
		void writeRoom()
		{
			fstream out;
			out.open("rooms.txt",ios::out|ios::app);
			char ch;
			do
			{
				cout << "\n_________________________\n";
				cout << "Add a New Room: ";
				cout << "\n__________________________\n";
				cout << "\nRoom Number: "; 
				cin >> room_no;
				cout << "Room Type Single or Double (Single/Double): "; 
				cin >>room_type;
				cout << "Room View 'Sea' for Sea view\n and 'Pool' for Pool view\n and 'Garden'for Garden view:\n"; 
				cin >>room_view;	
				cout << "Room Price in one day: ";
				cin >>room_price;
				cout << "**********************************************\nDo you want add more rooms (y/press any character such (n))? ";
				cin >> ch;
				strcpy(buf,room_no);
				strcat(buf,"|");
				strcat(buf,room_type);
				strcat(buf,"|");
				strcat(buf,room_view);
				strcat(buf,"|");
				strcat(buf,room_price);
				strcat(buf,"|");
				strcat(buf,"\n");
				out.write(buf,strlen(buf));
				cout<<"***********************Room added Successfuly**********************\n";
			}while(ch == 'y' || ch == 'Y'); 
			out.close();
		}

		void readRoom()
		{	
			fstream in;
			in.open("rooms.txt",ios::in);
			cout << "\n_________________________\n";
			cout << "Read Room Details: ";
			cout << "\n__________________________\n";
			cout<<"Room No\tRoom Type\tRoom View\tRoom Price\n";
			while(!in.eof())
			{
				in.getline(room_no,10,'|');
				in.getline(room_type,10,'|');
				in.getline(room_view,10,'|');
				in.getline(room_price,10,'|');
				in.getline(extra,100,'\n');
				cout<<room_no<<"\t";
				cout<<room_type<<"\t";
				cout<<room_view<<"\t";
				cout<<room_price<<"\n";
			}
			in.close();

	 
		}
		void searchRoom()
		{
	 		fstream sin;
	 		char rn[10];
	 		int flag=0;
	 		sin.open("rooms.txt",ios::in);
	 		cout << "\n_________________________\n";
			cout << "Search Room Details: ";
			cout << "\n__________________________\n";
	 		cout<<"Enter the Room number to be searched\n";
	 		cin>>rn;
	 		while(!sin.eof())
	 		{
	 			sin.getline(room_no,10,'|');
				sin.getline(room_type,10,'|');
				sin.getline(room_view,10,'|');
				sin.getline(room_price,10,'|');
				sin.getline(extra,100,'\n');
				if(strcmp(room_no,rn)==0)
				{
					cout<<"\t______________ Room Number Found_______________\n";
					cout<<"Room No\tRoom Type\tRoom View\tRoom Price\n";
    					cout<<room_no<<"\t";
    					cout<<room_type<<"\t";
    					cout<<room_view<<"\t";
    					cout<<room_price<<"\n";
    					flag=1;
    					break;
					
				}
	 		}
	 		if(flag==0)
	 			cout<<"_____________________Room Number Not Found_____________________\n";
	 		sin.close();
		}
		void updateRoom()
		{
	 		fstream uinout,f1,f2;
	 		uinout.open("rooms.txt",ios::in|ios::out);
	 		char rn[10];
	 		room a[100];
	 		int i=0,j=0,k=0,flag=0;
	 		cout << "\n_________________________\n";
			cout << "Update Room Details: ";
			cout << "\n__________________________\n";
	 		cout<<"Enter the Room Number to be updated\n";
	 		cin>>rn;
	 		while(!uinout.eof())
	 		{
	 			uinout.getline(a[i].room_no,10,'|');
				uinout.getline(a[i].room_type,10,'|');
				uinout.getline(a[i].room_view,10,'|');
				uinout.getline(a[i].room_price,10,'|');
				uinout.getline(extra,100,'\n');
				i++;
			}
			for(k=0;k<i;k++)
			{
				if(strcmp(rn,a[k].room_no)==0)
				{
					cout<<"Enter new Price for "<<rn<<"\n";
					cin>>a[k].room_price;
					cout<<"_______________Room Updated Successfuly\n";
					cout<<"Room NO\tRoom Type\tRoom View\tRoom Price\n";
					cout<<a[k].room_no<<"\t";
    					cout<<a[k].room_type<<"\t";
    					cout<<a[k].room_view<<"\t";
    					cout<<a[k].room_price<<"\n";
    					flag=1;
					cout<<"_______________________Room Updated Successfuly____________________________\n";
    					break;
				}
			}
			uinout.close();
			//f2.open("rooms.txt",ios::trunc);
			//f2.close();
			remove("rooms.txt");
			f1.open("rooms.txt",ios::out|ios::app);
			for(j=0;j<i;j++)
			{
				strcpy(buf,a[j].room_no);
        			strcat(buf,"|");
        			strcat(buf,a[j].room_type);
        			strcat(buf,"|");
        			strcat(buf,a[j].room_view);
        			strcat(buf,"|");
        			strcat(buf,a[j].room_price);
        			strcat(buf,"|");
        			strcat(buf,"\n");
        			f1.write(buf,strlen(buf));
			}
			f1.close();
			if(flag==0)
				cout<<"_______________________Room Number Not Found____________________________\n";
			//remove("rooms.txt");
			//rename("rooms1.txt","rooms.txt");
	 		
		}
		void deleteRoom()
		{
	 		room a[100];
    			int i=0,j=0,k=0,flag=0;
    			char buf[100];
    			fstream delf,newf;
    			delf.open("rooms.txt",ios::in);
    			cout << "\n_________________________\n";
			cout << "Delete Room: ";
			cout << "\n__________________________\n";
    			char x[10];
    			cout << "Enter Room Number to be deleted: "; 
    			cin >> x;
    			while(!delf.eof())
    			{
    				delf.getline(a[i].room_no,20,'|');
    				delf.getline(a[i].room_type,20,'|');
    				delf.getline(a[i].room_view,20,'|');
    				delf.getline(a[i].room_price,20,'|');
    				delf.getline(extra,100,'\n');
    				i++;
   			 }
   			 delf.close();
   			// delf1.open("rooms.txt",ios::trunc);
   			// delf1.close();
   			remove("rooms.txt");
   			newf.open("rooms.txt",ios::out|ios::app);
    			for(j=0;j<i;j++)
   			{
    				if(strcmp(x,a[j].room_no)!=0)
    				{
    					strcpy(buf,a[j].room_no);
       					strcat(buf,"|");
        				strcat(buf,a[j].room_type);
       	 				strcat(buf,"|");
        				strcat(buf,a[j].room_view);
        				strcat(buf,"|");
        				strcat(buf,a[j].room_price);
        				strcat(buf,"|");
        				strcat(buf,"\n");
        				newf.write(buf,strlen(buf));
    				}
    				if(strcmp(x,a[j].room_no)==0)
    					flag==1;
   			}	
   			if(flag==1)
				cout<<"_______________________Room Deleted Successfuly____________________________\n";
			else
				cout<<"_______________________Room Number Not Found____________________________\n";	
			newf.close();
    			//remove("rooms.txt");
    			//rename("rooms2.txt","rooms.txt");
    		}

};
void manageHotel()
{
	room r;
	Customer c;
	cout << "\t\t\t\t\t__________________________________\n\n";
	cout << "\t\t\t\t\tRESERVATION MANAGEMENT SYSTEM\n";
	cout << "\t\t\t\t\t___________________________________\n\n";
	cout << "************\nRESERVARION MANAGEMENT\n************\n";
	cout << "1. Customer Class\n2. Room Class\n3. Exit\n";
	char ch;
	cout << "*****************\nYour Choice: ";
	cin >> ch;
	if(ch == '1')
	{
		while(true)
		{
			int x;
    			cout << "******************************\nMANAGE CUSTOMER BOOKING\n******************************";
			cout << "\n1. Add a New Booking \n2. Search about Booking by Id \n3. Update Booking \n4. Delete Booking \n5. Show all Hotel Booking \n6. Back to Main Menu\n";
    			cout << "*****************************";
    			cout << "\nYour choise: "; cin >> x;
   			if(x == 1)
   				 c.writeCustomer();
    			else if(x == 2) 
    				c.searchCustomer();
    			else if(x == 3)
    				c.updateCustomer();
    			else if(x == 4) 
    				c.deleteRecordCustomer();
    			else if(x == 5) 
    				c.readCustomer();
    			else if(x == 6) 
    				manageHotel();
			else
			{
				cout << "Please, Enter a Correct Number.";
				cout << "\n\nPress any key to continue....!! ";
			}
    		}
	}
	else if(ch == '2')
	{
		while(true)
		{
			cout << "***********\nMANAGE ROOMS\n***********\n1. Write Room\n2. Search Room\n3. Update Room\n4. Delete Room\n5. Show all Rooms\n6. Back to Main Menu\n********************\n";
			char x;
			cout << "Your Choice: "; 
			cin >> x;
			cout << "*************\n";
			if(x == '1') 
				r.writeRoom();
			else if(x == '2') 
				r.searchRoom();
			else if(x == '3') 
				r.updateRoom();
			else if(x == '4') 
				r.deleteRoom();
			else if(x == '5') 
				r.readRoom();
			else if(x == '6') 
				manageHotel();
			else
			{
				cout << "Please, Enter a Correct Number.";
				cout << "\n\nPress any key to continue....!! ";
			}
		}			
	}
	else if(ch == '3')
	{
		cout << "\n\n\t\t\t***************THAKNK YOU FOR YOUR RESERVATION**************\n\n";
		exit(0);
	}
	else
	{
		cout << "Please, Enter a Correct Number.";
		cout << "\n\nPress any key to continue....!! ";
		manageHotel();
	}
}
int main()
{
	manageHotel();
	return 0;
}

