#include <iostream>
#include <cstring>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include<dos.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include <iomanip>

#define MAX_NAME_LEN 25
#define MAX_NAME_airline 100
using namespace std;


	class node{
		public:
			string data;
			string dest; 	string dept;	string airline;		string fdate; 		string ftype;	int price;	string btime;
			node* next;
			node* down;
			node(string data){
				this->data = data;
				this->next = NULL;
				this->down = NULL;
			}	
	};

	void delay(){
	for(int i = 3; i > 0; i--){
				system("CLS");
				cout<<"\n\t\tNet starting in "<<i+1<<" seconds";
				Sleep(1000);	
			}
}
	string date() {
    time_t now = time(0);
	string date;
	tm *ltm = localtime(&now);

   date= to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
   return date;
}	
	string time() {
   time_t now = time(0);
   tm *ltm = localtime(&now);
   string time;
   time=to_string(ltm->tm_hour)+":"+to_string(ltm->tm_min)+":"+to_string(ltm->tm_sec);
   return time;
}
	string date_generator(string date_string){
	time_t now = time(0);
	string date,year = "2022";
	tm *ltm = localtime(&now);
	//date = ltm->tm_mday + rand()%14+7;
	if(ltm->tm_mday + rand()%14+7 > 30){
		ltm->tm_mday -= 30;
		ltm->tm_mon += 1;
	}
	date_string = to_string(ltm->tm_mday + rand()%14+7) + " - ";	
	//date = ltm->tm_mon + 1;
	if(ltm->tm_mon + 1 > 12){
		ltm->tm_mon -= 12;
		year = "2023";
	}
	date_string = date_string + to_string(ltm->tm_mon + 1) + " - ";
	date_string = date_string + year + 	"\tat ";	//	17 - 09 - 2022
	date_string = date_string + to_string(rand()%11+1);
	if(rand()%2 == 0)
	date_string = date_string + " pm ";
	else
	date_string = date_string + " am ";
	return date_string;
}
	string date_select(){
		system("cls");
		srand(time(0));
		int size = rand()%5+4 ,number;
		string array[size],datee,date_current,time_current;	 
		
		cout<<"\n\tAvailable flights  ||  ";
		cout<<"Date:\t"<<date();cout<<" | time: "<<time();cout<<"\n\n";
		for(int i = 0 ; i < size ; i++)
		array[i] = date_generator(array[i]);
		for(int i = 0 ; i < size ; i++)
		cout<<"\t\t"<<i+1<<" :\t"<<array[i]<<endl;
		
	    do{
	    	cout<<"\n\n\tWhich date would you prefer for your flight  \n";
	    	cout<<"\n\tpress serial number:  ";
			cin>>number;	cin.ignore();
		}while(number < 1 || number > size);
		datee = array[number-1];
		return datee;
	}

	string inputstring(){
		string z;
		getline(cin,z);
		return z;
	}
	string convertToString(char* a, int size){
	    int i;
	    string s = "";
	    for (i = 0; i < size; i++) {
	        s = s + a[i];
	    }
	    return s;
	}
	string string_to_char_array_modified(string s){
    int n = s.length();
    
    char array[n + 1];
    
    strcpy(array, s.c_str());	// copying the contents of the string to char array
 	
 	if(int(array[0]) >= 97 )
	array[0] -= 32; 			//A65 a97
	for(int i = 1; i < n; i++){
		if(array[i] < 97 && array[i] != ' ' )
		array[i] += 32; 
		if(array[i] == ' '){
			if(array[i+1] >= 97)
			array[i + 1] -= 32;
			i++;
		}
	}
	
    string str = convertToString(array,n);   		
    return str;  	
}	
	void string_to_char_array(string s){	//for cnic
    int n = s.length();
    
    char char_array[n + 1];
    
    strcpy(char_array, s.c_str());	// copying the contents of the string to char array
 		for(int i = 0; i < 5; i++)
       	cout<<char_array[i];	cout<<"-";
       	for(int i = 5; i < 12; i++)
       	cout<<char_array[i];	cout<<"-";
       	cout<<char_array[12];
}
	
	string add_underscore(string s){
	int n = s.length();
    
    char array[n + 1];
    
    strcpy(array, s.c_str());
    
    for (int i = 0 ; i < n ; i++){
    	if(array[i] == ' ')
    		array[i] = '_';
	}
	
	string str = convertToString(array,n);   		
    return str; 
}
	string remove_underscore(string s){
	int n = s.length();
    
    char array[n + 1];
    
    strcpy(array, s.c_str());
    
    for (int i = 0 ; i < n ; i++){
    	if(array[i] == '_')
    		array[i] = ' ';
	}
	
	string str = convertToString(array,n);   		
    return str; 
}


	int roundUp(int value){			//rounds up the prices to correct thousand 
	       int roundDown = ((int) (value) / 1000) * 1000;
	       int roundUp = roundDown + 1000; 
	       int roundCalc = roundUp;;
	       return (roundCalc); 
	}
	int roundup100(int value){		//rounds up the prices to correct hundred 
	       int roundDown = ((int) (value) / 100) * 100;
	       int roundUp = roundDown + 100; 
	       int roundCalc = roundUp;;
	       return (roundCalc); 
	}
	int roundup10(int value){		//rounds up the prices to correct tenth 
	       int roundDown = ((int) (value) / 10) * 10;
	       int roundUp = roundDown + 10; 
	       int roundCalc = roundUp;;
	       return (roundCalc); 
	}
	int roundup50(int value){		//rounds up the prices to correct 50th 
	       int roundDown = ((int) (value) / 50) * 50;
	       int roundUp = roundDown + 50; 
	       int roundCalc = roundUp;;
	       return (roundCalc); 
	}

	int netprob = 0;					//when this variable becomes 3. net gets disconnected
	void main_game();
	void popu_airlines(string *air,int siz,string,string);
	void popu_flights(string *arr,int size,string,string);
	string generatekey(char* name,string key);
	void insert_airline(string* flights,int size,int);
	void print_airlinedata();
	void specific_alphabet_names();
	void signup(string *airline,int size_airlines);
	void adminOptions(string *airline,int size_airlines);
	void printtable(string *airlines,int size);
	node* binarysearch_horizontal(node *head, string value);
	node* middle_horizontal(node* start, node* last);
	node* binarysearch_vertical(node *head, string value);
	node* middle_vertical(node* start, node* last);

	// Enumerator
	enum IN {
	// 13 is ASCII for carriage return
	IN_BACK = 8,
	IN_RET = 13

};
	class Game{
	public:

void fill_abcd_stacks(stack<int> &s,stack<int> &a,stack<int> &b,stack<int> &c,stack<int> &d,int size,string *name){
	system("cls");
	for(int i = 0,j=0 ; i < size ; i++,j++){
		cout<<"\t\tIteration count -> "<<j+1<<" || New cards alloted" <<endl;
		a.push(s.top());	s.pop();
			b.push(s.top());	s.pop();
				c.push(s.top());	s.pop();
					d.push(s.top());	s.pop();
		cout<<"\nStack of "<<name[0]<<": " ;displayStack(a);	cout<<endl;	cout<<"\nStack of "<<name[01]<<": " ;displayStack(b);	cout<<endl;	
		cout<<"\nStack of "<<name[02]<<": " ;displayStack(c);	cout<<endl;	cout<<"\nStack of "<<name[03]<<": " ;displayStack(d);				
		maxcard(a,b,c,d);			
	}
	//cout<<"Stack of A: ";displaytop(a);		cout<<"Stack of B: ";displaytop(b);			cout<<"Stack of C: ";displaytop(c);		cout<<"Stack of D: ";displaytop(d);
	cout<<"\n\t\tUltimate result of all iterations\n";
	cout<<"\nStack of "<<name[0]<<": " ;displayStack(a);		cout<<endl<<endl;	cout<<"\nStack of "<<name[01]<<": " ;displayStack(b);	cout<<endl<<endl;	
	cout<<"\nStack of "<<name[02]<<": " ;displayStack(c);	    cout<<endl<<endl;	cout<<"\nStack of "<<name[03]<<": " ;displayStack(d);	cout<<endl<<endl;
	
}
void swap(int* x,int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void shuffle(int *array){
	srand(time(0));
	for(int i = 0 ; i < 100; i++){
		swap(&array[rand()%50],&array[rand()%50+50]);
		swap(&array[rand()%50],&array[rand()%50+50]);
		swap(&array[rand()%50],&array[rand()%50+50]);
	}
}
void fill_array(int* array){
	for(int i = 0 ; i < 100 ; i++)
	array[i] = i+1;
}
void displayStack(stack<int> &s){	//utility func to view the stack of cards
	// If stack is empty
    if (s.empty())
        return;
  
// Extract top of the stack
    int x = s.top();
  
    // Pop the top element
    s.pop();
  
    // Print the current top
    // of the stack i.e., x
    cout << endl <<"\t\t" <<  x << ' ' ;
  
    // Proceed to print
// remaining stack
    displayStack(s);
  
    // Push the element back
    s.push(x);
}
void fillstack(stack<int> &s){	//utility func to fill stack of cards with 1-100
	int array[100];
	fill_array(array);
	shuffle(array);
	for (int i = 0 ; i < 100 ; i++)
	s.push(array[i]);	
}
void maxcard(stack<int> &a,stack<int> &b,stack<int> &c,stack<int> &d){
	int max;
	max = a.top();	int flag = 0;
	if(b.top() > max){
		max = b.top();	flag = 1;
	}
	if(c.top() > max){
		max = c.top();	flag = 2;
	}
	if(d.top() > max){
		max = d.top();	flag = 3;
	}
	
	if(flag == 0){	//A had the highest card
		cout<<endl<<"\n\tA has the highest card -> gets all cards of this turn\n";
		a.push(b.top());	b.pop();
			a.push(c.top());	c.pop();
				a.push(d.top());	d.pop();
	//	cout<<"Stack of A: ";displayStack(a);		
	}
	else if(flag == 1){	//B had the highest card
		cout<<endl<<"\n\tB has the highest card -> gets all cards of this turn\n";
		b.push(a.top());	a.pop();
			b.push(c.top());	c.pop();
				b.push(d.top());	d.pop();
	//	cout<<"Stack of B: ";displayStack(b);		
	}
	else if(flag == 2){	//C had the highest card
		cout<<endl<<"\n\tC has the highest card -> gets all cards of this turn\n";
		c.push(b.top());	b.pop();
			c.push(a.top());	a.pop();
				c.push(d.top());	d.pop();
	//	cout<<"Stack of C: ";displayStack(c);		
	}
	else if(flag == 3){	//D had the highest card
		cout<<endl<<"\n\tD has the highest card -> gets all cards of this turn\n";
		d.push(b.top());	b.pop();
			d.push(c.top());	c.pop();
				d.push(a.top());	a.pop();
	//	cout<<"Stack of D: ";displayStack(d);		
	}
}
void results(stack<int> &a,stack<int> &b,stack<int> &c,stack<int> &d,string *name){
	if(a.size() > b.size() && a.size() > c.size() && a.size() > d.size() )
	cout<<"\n\tPlayer 1 wins the game with most cards in pile";
	else if(b.size() > a.size() && b.size() > c.size() && b.size() > d.size())
	cout<<"\n\tPlayer 2 wins the game with most cards in pile";
	else if(c.size() > b.size() && c.size() > a.size() && c.size() > d.size())	
	cout<<"\n\tPlayer 3 wins the game with most cards in pile";
	else if(d.size() > b.size() && d.size() > c.size() && d.size() > a.size())	
	cout<<"\n\tPlayer 4 wins the game with most cards in pile";	
	else {
	
	if(a.size() == b.size() && b.size() == c.size() && c.size() == d.size()){
		cout<<"\n\tEveryone won equals rounds -> equal cards. "; 	goto end;
	}
	else{
			if(a.size() == b.size() && b.size() == c.size()){
			cout<<"\n\tTie between Player 1,Player 2 and Player 3";	goto end;
			}			
			else if(a.size() == b.size() && b.size() == d.size()){
			cout<<"\n\tTie between Player 1,Player 2 and Player 4";	goto end;
			}				
			else if(a.size() == c.size() && c.size() == d.size()){
			cout<<"\n\tTie between Player 1,Player 3 and Player 4";	goto end;
			}		
			else if(b.size() == c.size() && b.size() == d.size()){
			cout<<"\n\tTie between Player 2,Player 3 and Player 4";	goto end;
			}
			else{
				if(a.size() != 0){
				if(a.size() == b.size() )
				cout<<"\n\tTie between Player 1 and Player 2";	
				else if(a.size() == c.size() )
				cout<<"\n\tTie between Player 1 and Player 3";	
				else if(a.size() == d.size() )
				cout<<"\n\tTie between Player 1 and Player 4";
		}
				if(b.size() != 0){
			 	if(b.size() == c.size() )
				cout<<"\n\tTie between Player 2 and Player 3";	
				else if(b.size() == d.size() )
				cout<<"\n\tTie between Player 2 and Player 4";
		}
				if(c.size() != 0  ){
				if(c.size() == d.size() )
				cout<<"\n\tTie between Player 3 and Player 4";
									}			
				end:	return;
				}		
}
}		
}
int ask_iterations(){
	int iterations;
		here:	cout<<"How Many iterations:  ";cin>>iterations;
	if(iterations < 0 || iterations > 25)	//at most 25 iterations allowed
	goto here;
	return iterations;
}
void asknames(string *name){
	cin.ignore();
	system("cls");
	for(int i = 0 ; i < 4 ; i++){
		cout<<"\n\tEnter Player "<<i+1<<"'s Name:  ";	
		getline(cin,name[i]);
	
	}
	system("cls");
}
void main_game(){
	stack<int> s;	
	stack<int> a,b,c,d;
	
	string name[4];
	asknames(name);
	fillstack(s);	

	int choice;
L1:	cout<<"\n\tPress 1 to Start/continue Game | 0 to End game.\n\tEnter:  ";	cin>>choice;
	if(choice == 1)
		fill_abcd_stacks(s,a,b,c,d,choice,name);
	else if(choice == 0){
		results(a,b,c,d,name);
		cout<<endl<<endl<<endl;
		return;
	}
	else{
		cout<<"\nEnter Valid Instruction\n";	goto L1;
	}	goto L1;
	// ---> old logic. no user interaction. 
	//iterations = ask_iterations();	//asks the user how many times he wants to execute the play.
	//fill_abcd_stacks(s,a,b,c,d,choice);
	
}

};
	class hashmap:protected Game{
	
	public:
		node* head = NULL;				
	void insert(string data){
			node *newnode = new node(data);
			if(head == NULL)
			head = newnode;
			else{
				node *temp = head;
				while (temp->next != NULL)
				temp = temp->next;	
				temp->next = newnode;
			}
			
		}
	void fill_mainLL_alphabets(string *array){
	for (int i = 0 , j = 97; i < 26 ; i++,j++ ){
		array[i] = j;			
		insert(array[i]);
	}
}	
	void searchkey_main_chain(string key,string name,string *airline,string *flights,int size,int size_flights){			//searches the alphabet under which name has to fall
		node* temp;

		temp = binarysearch_horizontal(head,key); // finds the key
		// puts the name in sorted position
		
		node* current = temp->down;
		
		node *newnode = new node(name);
		
		if(current == NULL || current->data >= newnode->data)
		{
			newnode->down = temp->down;
			temp->down = newnode;
		}
		else
		{
			current = temp->down;
        while (current->down != NULL && current->down->data < newnode->data) {
            current = current->down;
        }
        newnode->down = current->down;
        current->down = newnode;
		}
//		while(temp->down != NULL)
//		temp = temp->down;
//		
//		temp->down = newnode;
		
		popu_flights(flights,size_flights,key,name);
		popu_airlines(airline,size,key,name);
		insert_dest_dept(dest,departure,key,name);
	}
	void specific_alphabet_names(){								//prints all names under a specific alphabet such as k
		string key;
	cout<<"\nEnter your name's initial alphabet :  ";
  	cin>>key;
	print_specific_alphabets_names(key);	cout<<endl;
	}
	void print_specific_alphabets_names(string key){			//util function to print all the names of specific alphabets => called in upper func
		node* temp;
		string airline;									//shows all names, that the user has entered, in a table format
		cout<<"\nWhich Airline did you select before:  ";	cin.ignore();
		getline(cin,airline);
		airline = string_to_char_array_modified(airline);
//		while(temp->data != key)
//		temp = temp->next;

		temp = binarysearch_horizontal(head,key);
		
		if(temp->down == NULL){
			cout<<"No names starting with '"<<key<<"' \n\n";
			return;
		}else{
			cout<<"\n\nPassengers of initial alphabet -> "<<key<<":\n\n"  ;
			int i = 1;
			while (temp->down != NULL){
				if(temp->down->airline == airline){
					if(temp->down->data.size() < 15){
						if(temp->down->data.size() < 7)
						cout<<"\t"<<temp->down->data<<" \t\t\t"<<temp->down->dept<<" to "<<temp->down->dest<<" in "<<temp->down->ftype<<" class"<<"\n\t\t\t\tTotal: "<<temp->down->price<<"/- pkr\n\t\t\t\ton "<<temp->down->fdate<<"\n\t\t\t\tBooking Time: " << temp->down->btime<<endl<<endl;
						else 
						cout<<"\t"<<temp->down->data<<" \t\t"<<temp->down->dept<<" to "<<temp->down->dest<<" in "<<temp->down->ftype<<" class"<<"\n\t\t\t\tTotal: "<<temp->down->price<<"/- pkr\n\t\t\t\ton "<<"\n\t\t\t\tBooking Time: " << temp->down->btime<<endl<<endl;
					}	
					else
						cout<<"\t"<<temp->down->data<<" \t"<<temp->down->dept<<" to "<<temp->down->dest<<" in "<<temp->down->ftype<<" class"<<"\n\t\t\t\tTotal: "<<temp->down->price<<"/- pkr\n\t\t\t\ton "<<temp->down->fdate<<"\n\t\t\t\tBooking Time: " << temp->down->btime<<endl<<endl;
						i++;					
			temp = temp->down;	
			}
		}	
	}
}
	string* askdetails(string *array){	
		
		cout<<"\nPlease enter your selected Airline:  ";
		getline(cin,array[0]);	
		array[0] = string_to_char_array_modified(array[0]);
		
		cout<<"Please enter your destination area:    ";	
		getline(cin,array[1]);	
		array[1] = string_to_char_array_modified(array[1]);
		
		cout<<"Please enter your departure location:  ";	
		getline(cin,array[2]);	
		array[2] = string_to_char_array_modified(array[2]);	
		
		return array;
	}
	void searchname_util(string name,string key){				//util function to search if a name exists
		string array[3];					//array[0] = airline, +1 = dest, +2 = dept
		string *airline,*dest,*dept;
		airline = askdetails(array);		//airline recieves the value at base index of array
		dest = (airline+1);					//dest = array[1]
		dept = (dest+1);
		
	    node* temp;
		bool check1 = true; 	bool check2 = true;		bool check3 = true;		bool check4 = true;	
//		while(temp->data != key)
//			temp = temp->next;

		temp = binarysearch_horizontal(head, key);
		
//			while (temp->data != name){
//			temp = temp->down;
//					
//			}
		temp = binarysearch_vertical(temp->down, name);
		
		if(temp == NULL)
		{
			check1 = false;
			goto here;
		}
			if(temp->airline != *airline){
				check2 = false;		//cout<<endl<<temp->airline;
			}
			if(temp->dest != *dest){
				check3 = false;		//cout<<endl<<temp->dest;
			}
			if(temp->dept != *dept){
				check4 = false;		//cout<<endl<<temp->dept;
			}
			
		here:	
		if(check1 == false ||check2 == false ||check3 == false ||check4 == false ){
//				cout<<temp->data<<" "<<temp->airline<<" "<<temp->dest<<" "<<temp->dept<<endl;
//				cout<<*airline<<" "<<*dest<<" "<<*dest<<endl;
				cout<<"\nName Not Found in directory -> Ticket not booked\n\n";
				return;
		}
		else
		cout<<endl<<endl<<"\t Your ticket has been booked at " << temp->btime << " for "<<temp->ftype<<" class"<<endl;
		cout<<"\t Details: " << temp->fdate<<" | "<<"Total: "<<temp->price<<"/- pkr"<<endl;			
	}
	
	void name_search(char* name, string key){					//tells if a name exists or not
		string localname;	
	
		cout<<"\nEnter name to be searched:  ";		//cin.ignore();	--> has a significant impact. 
			getline(cin,localname);

		localname = string_to_char_array_modified(localname);	
		int n = localname.length();

    	strcpy(name, localname.c_str());
		
		key = generatekey(name, key);	
		searchname_util(name, key);
}
	void filldata_util(char* name,string key,int iterationskey,string* airline,string* flights,int size,int size_flights){	//fill the names as per user defined iterations
		string localname;
	
	for(int i = 0 ; i < iterationskey ; i++){
		system("CLS");
		cout<<"Enter passenger "<<i+1<<"'s name:  " ;			
		if(i == 0)	
		cin.ignore();					
		//cin.getline (name, MAX_NAME_LEN);
		getline(cin,localname);
		//strcpy(name_local,name);
		//string localname = convertToString(name_local,sizeof(name_local)/sizeof(name_local[0]));
		localname = string_to_char_array_modified(localname);	cout<<endl;
		int n = localname.length();
    
   	 	//char char_array[n + 1];
    
    	strcpy(name, localname.c_str());
		system("cls");
		
		key = generatekey(name, key);
		searchkey_main_chain(key,name,airline,flights,size,size_flights);
	}

}	
	void filldata(string key,char *name,string* airline,string* flights,int size,int size_flights){
	int iterationskey;
	system("CLS");
	do{
		cout<<"Enter how many tickets do you want to buy:  ";		
		cin>>iterationskey;
	}while(iterationskey <= 0);

	cout<<endl;
	filldata_util(name,key,iterationskey,airline,flights,size,size_flights);						//fills the hashtable with names
}		
	void printtable(string *airlines,int size){					//shows all names, that the user has entered, in a table format
	static int global_i = 0;	//for below func for loop
	int counter=0;	
	string airline;				
			
	here:	cout<<"\nWhich Airline did you select before:  ";	
			if( global_i > 0 ){
					cin.ignore();
					global_i++;
			}
			getline(cin,airline);
			airline = string_to_char_array_modified(airline);
			
		//check for airline validity
		for(int i = 0 ; i < size ; i++){
			if(airlines[i] == airline){
				break;
			}			
			if(i == size - 1)
			goto here;
		}
		
		cout<<endl<<endl<<"Passenger Data of all flights of "<<airline<<": \n\n";
		node *temp = head;
		node *ptr = temp;							//to save the link of the main branch
		for(int i = 0 ;i < 26 ; i++){				//loop accesses each alphabet
			int flag = 0;
			int printalpha = 0;
			if(ptr->down != NULL){
				string savekey = ptr->data;
				
				while(ptr->down != NULL){
					ptr = ptr->down;
					counter++;
					if(ptr->airline == airline){
					flag = 1;							//check for cout<<endl<<endl
					if(printalpha == 0){
						cout<<savekey<<":   ";			//alphabet
						printalpha++;
					}
					if(ptr->data.size() < 15){
						if(ptr->data.size() < 7)
						cout<<"\t"<<ptr->data<<" \t\t\t"<<ptr->dept<<" to "<<ptr->dest<<" in "<<ptr->ftype<<" class"<<"\n\t\t\t\tTotal: "<<ptr->price<<"/- pkr\n\t\t\t\ton "<<ptr->fdate<<"\n\t\t\t\tBooking Time: " << ptr->btime<<endl<<endl;
						else 
						cout<<"\t"<<ptr->data<<" \t\t"<<ptr->dept<<" to "<<ptr->dest<<" in "<<ptr->ftype<<" class"<<"\n\t\t\t\tTotal: "<<ptr->price<<"/- pkr\n\t\t\t\ton "<<ptr->fdate<<"\n\t\t\t\tBooking Time: " << ptr->btime<<endl<<endl;
					}	
					else
					cout<<"\t"<<ptr->data<<" \t"<<ptr->dept<<" to "<<ptr->dest<<" in "<<ptr->ftype<<" class"<<"\n\t\t\t\tTotal: "<<ptr->price<<"/- pkr\n\t\t\t\ton "<<ptr->fdate<<"\n\t\t\t\tBooking Time: " << ptr->btime<<endl<<endl;
					}
				}
			}	
		temp = temp->next;	
		ptr  = temp;
		if (flag == 1)
		cout<<endl<<endl;
		}
		return;
	}

	// Function that accepts the password string takePasswdFromUser(
	string take_pwd(char sp = '*'){
	// Stores the password
	string passwd = "";
	char ch_ipt;

	// Until condition is true
	while (true) {

		ch_ipt = getch();

		// if the ch_ipt
		if (ch_ipt == IN::IN_RET) {
			cout << endl;
			return passwd;
		}
		else if (ch_ipt == IN::IN_BACK
				&& passwd.length() != 0) {
			passwd.pop_back();

			// Cout statement is very important as it will erase previously printed character
			cout << "\b \b";
			continue;
		}

		// Without using this, program will crash as \b can't be print in beginning of line
		else if (ch_ipt == IN::IN_BACK
				&& passwd.length() == 0) {
			continue;
		}

		passwd.push_back(ch_ipt);
		cout << sp;
	}
}
	void login_check(string key,char *name,string* flights,string *airline,int size_airlines,int size_flights,string username,string pwd,string CNIC){
		string user,password,cnic;
		system("cls");
	ifstream login("Admininfo.txt",ios::in);
		cout<<"\n\tEnter your premium details\n\n";	cin.ignore();
	
	l1:	cout<<"\tEnter your CNIC:  "; 
		getline(cin,cnic);
		
				while(login >> username >> password >> CNIC){
					cout << cnic << " " << CNIC << endl;
					if(cnic == CNIC)	goto l2;
				}
					if( login.eof() && cnic != CNIC){
						cout<<endl;	goto l1;
					}
			

	l2:	login.close();	
		ifstream login2("Admininfo.txt",ios::in);		
		cout<<"\tEnter your Username:  "; //cin.ignore();	
		getline(cin,user);
				while(login2 >> username >> password >> CNIC){
					if(user == remove_underscore(username))	goto l3;		
				}
					if( login2.eof() &&  username != user){
						cout<<endl;	goto l2;
					}
					
		
	l3:	login2.close();	
		ifstream login3("Admininfo.txt",ios::in);	
		cout<<"\tEnter your Password:  "; //cin.ignore();	
		pwd = take_pwd();
				while(login3 >> username >> password >> CNIC){
						if(pwd == password)		goto l4;
				}
						if( login3.eof() &&  pwd != password){
							cout<<endl;	goto l3;
						}
						
		
		
	l4:	login3.close();
		session_summary(key,name,flights,airline,size_airlines,size_flights,username,pwd,CNIC);
					
		cout<<"\n\n\tDetails valid --> press any key to view features : ";	getchar();
		Login(key,name,flights,airline,size_airlines,size_flights);	//proceed to login
			
			
//		cout<<"\n\tEnter your premium details\n\n\tEnter your CNIC:  "; cin.ignore();	getline(cin,cnic);
//		cout<<"\tEnter your Username:  "; //cin.ignore();	
//		getline(cin,user);
//		cout<<"\tEnter your Password:  "; //cin.ignore();	
//		getline(cin,pwd);
//			
//			ifstream login("Admininfo.txt",ios::in);
//				while(login >> username >> password >> CNIC){
//					//	cout<<cnic<<" |1 "<<CNIC<<" |  "<<user<<" |  "<<username<<" |  "<<pwd<<" |  "<<password<<endl;
//					if(cnic == CNIC && username == user && pwd == password){
//						session_summary(key,name,flights,airline,size_airlines,size_flights,username,pwd,CNIC);
//						cout<<"\n\n\tDetails valid --> press any key to view features : ";	getchar();
//						Login(key,name,flights,airline,size_airlines,size_flights);	//proceed to login
//				}
//			}
//					if(login.eof() && (cnic != CNIC || username != user || pwd != password )){
//						cout << "\n\t-->  Details are  invalid --> Proceeding to Menu\n\t"  ;		system("pause");
//						premium_features(key,name,flights,airline,size_airlines,size_flights,username,pwd,CNIC);
//					//	viewmenu(key,name,flights,airline,size_airlines,size_flights);	//if CNIC not found
//					}		
//	login.close();
}
	void premium_features(string key,char *name,string* flights,string *airline,int size_airlines,int size_flights,string username,string pwd,string cnic){
	system("cls");
		int choose,c2;
		cout<<"\tPremium features cost pkr 100000/- BUT ONCE ONLY\n\n\tpress:\n\n\t1. to buy access to the features\n\t2. Access the features (already have an account)\n\t3. any other number to return to menu\n\n\tEnter:  ";
		cin>>choose;
		
		if(choose == 1){
			string destin,depart,name1,key1,cnic,CNIC,username,password,airline1;	
			
			system("cls");
			cout<<"\n\tYou can only buy the premium features if you a flight already booked\n";
			cout<<"\n\tPlease Enter Flight details\n\n";
			cin.ignore();
		L1:	cout<<"\n\tEnter Name(with which you have booked your flight): ";	
			getline(cin , name1);	
			name1 = string_to_char_array_modified(name1);
			
			
			key1 = name1.front();	
			int n = key1.length();
    
   			char char_array[n + 1];
    
   			strcpy(char_array, key1.c_str());	
			char_array[0] += 32 ;
			key1 = convertToString(char_array,n);
			node *temp;
//			while(temp->data != key1){
//					temp = temp->next;	//key at initial alpha
//			}

		temp = binarysearch_horizontal(head,key1);
		temp = binarysearch_horizontal(temp->down,name1);
		
//			while(temp->data != name1){
////				cout<<temp->data<<" "<<name1<<endl;	
//				temp = temp->down;	

//			}

				if(temp == NULL){
					cout<<"\n\tYou havent booked a flight --> Enter Correct name " << endl;	
					goto L1;
				}
		
	L2:		cout<<"\tEnter your Airline:  ";
			getline(cin,airline1);
			airline1 = string_to_char_array_modified(airline1);
			if(temp->airline != airline1){
				cout<<endl;		goto L2;
				cout<<temp->airline<<" "<<airline1<<endl;
			}
		
	L3:		cout<<"\tEnter your Destination:  ";
			getline(cin,destin);
			destin = string_to_char_array_modified(destin);
			if(temp->dest != destin){
				cout<<endl;		goto L3;
			}
			
	L4:		cout<<"\tEnter your Departure:  ";
			getline(cin,depart);
			depart = string_to_char_array_modified(depart);
			if(temp->dept != depart){
				cout<<endl;		goto L4;
			}

			cout<<"\n\n\tDetails valid --> press any key to proceed to Sign-up : ";	getchar();	//all conditions met
					temp->price = temp->price + 100000;	//charges added
					signup(key,name,flights,airline,size_airlines,size_flights,username,pwd,cnic);			
				
	}
		else if(choose == 2){
			login_check(key,name,flights,airline,size_airlines,size_flights,username,pwd,cnic);
		}
		else
		viewmenu(key,name,flights,airline,size_airlines,size_flights,username,pwd,cnic);		
}
	void session_summary(string key,char *name,string* flights,string *airline,int size_airlines,int size_flights,string username,string pwd,string CNIC){
		int choice;
//		linkedlist obj;	//inserts current time
//		obj.insert(username,cnic,date()+"   "+time());
		ofstream outfile;						//used for file
		outfile.open("session.txt", ios::app);	
		
		outfile << username << "\t"; 	
		outfile << CNIC << "\t";
		outfile << date()+"   "+time() << "\t\n";
		outfile.close();
		
		cout<<"\n\tDo you want to see the session summary?\n\n\t1. press one for yes\n\t2. any other key to return\n\n\tEnter:  ";
		cin>>choice;
		if(choice == 1)
		show_summary(key,name,flights,airline,size_airlines,size_flights,username,pwd,CNIC);
		else
		return;
	}
	bool is_empty(ifstream& pFile){
    return pFile.peek() == ifstream::traits_type::eof();
}

	void print_session_summary(string key,char *name,string* flights,string *airline,int size_airlines,int size_flights,string username,string pwd,string CNIC){
		int i = 1;
		ifstream login("session.txt",ios::in);
		if(is_empty(login)){
			cout<<"\n\tNo Data\n\t";	system("pause");
			return;
		}
		else{
			string user,cnic,date,time;
				
				while(login >> user  >> cnic >> date >> time){
					
						if(user.size() > 5){
							cout<<i<<":\tUsername: "<<user<<"\t\tCNIC: ";	string_to_char_array(cnic);
							cout<<"\n\t\t\t\t\ton "<<date<<"   "<<time<<endl<<endl;
						}
						else{
							cout<<i<<":\tUsername: "<<user<<"\t\t\tCNIC: ";	string_to_char_array(cnic);
							cout<<"\n\t\t\t\t\ton "<<date<<"   "<<time<<endl<<endl;
						}
						i++;	
					if(login.eof()){
						cout << "\n\t-->To Proceed to premium features\n\t";		system("pause");
						premium_features(key,name,flights,airline,size_airlines,size_flights,username,pwd,CNIC);
					//	viewmenu(key,name,flights,airline,size_airlines,size_flights);	//if CNIC not found
					}	
			}
	login.close();
	}
	return;
}	
	void show_summary(string key,char *name,string* flights,string *airline,int size_airlines,int size_flights,string username,string pwd,string CNIC){
		system("cls");
		cout<<"\n\tSession summary is as follows\n\n";
		print_session_summary(key,name,flights,airline,size_airlines,size_flights,username,pwd,CNIC);
		cout<<"\tTo proceed to Login page\n\t";
		system("pause");	
		return;
}

	void viewmenu(string key,char *name,string* flights,string *airline,int size_airlines,int size_flights,string username,string pwd,string cnic){				//menu func which asks the user what he wants to do. keeps the program running until user exits
	int choice,choicegame;		
	here:	
	if(netprob == 3){
			system("CLS");
			cout<<"\t\t\tYour Internet has disconnected\n\n";		Sleep(500);
			cout<<"Press 1 to play game OR any other to wait for internet to connect back:  ";
			cin>>choicegame;
			if(choicegame == 1){
				system("CLS");
				main_game();			//net problems -> game
				system("pause");
			}
			else{
				delay();
			}
			
		}
	
	system("CLS");
	cout<<"\npress   (1) to search if ticket is booked (enter your name)\n";
    cout<<"\t(2) to book more tickets\n";

	cout<<"\t(3) To buy Premium features | Access Admin Options\n";
	cout<<"\t --> session summary available (developer only feature)\n";   
   	cout<<"\t(0) to exit the program\n";
	cout<<"\nEnter choice: ";	
   	cin>>choice;	cin.ignore();
    
    if(choice == 0 ){
    	cout<<"\n\nThankyou for visiting :)";	
    	exit(0);
	}
	else if(choice == 1){
		name_search(name, key);
	}
	else if(choice == 2){
		char name[MAX_NAME_LEN];
		string key ;
		filldata(key,name,airline,flights,size_airlines,size_flights);
	}
	else if(choice == 3){
		premium_features(key,name,flights,airline,size_airlines,size_flights,username,pwd,cnic);
	}
	else{                                                            
		cout<<"Invalid option - Press any key ";
		getchar();		goto here;
	}

	netprob++;
	cout<<endl<<"\t\t";	system("pause");
	goto here;
	}

	//	Below are airline and flights func
	void insert_dest_dept(string dest,string dept,string key,string name){		//fills user data with dest and dept
	node* temp;
//		while(temp->data != key)
//		temp = temp->next;
		temp = binarysearch_horizontal(head,key);
//		while(temp->data != name)
//		temp = temp->down;			
		temp = binarysearch_vertical(temp->down,name);	//has reached the name
		
		temp->dept = dept;
		temp->dest = dest;
}
	void insert_airline(string key,string name,string airline,int price){										//fills user data with dest and dept
		node* temp;
	
//		while(temp->data != key)
//		temp = temp->next;
		temp = binarysearch_horizontal(head,key);
//		while(temp->data != name)
//		temp = temp->down;		
		temp = binarysearch_vertical(temp->down,name);		//has reached the name
		
		temp->airline = airline;
	
		int type;
		system("cls");
		cout<<"\n\n\tEnter flight class \n\n1.\t Luxury (pkr 25000/-)\n2.\t Business(pkr 20000/-) \n3.\t Standard\n4.\t Economy\n";
here:	cout<<"\nEnter Choice (Serial number) : ";		
		cin>>type;
		if(type == 1)
		price += 25000;
		else if(type == 2)
		price+= 20000;
		if(type < 1 || type > 4)
		goto here;
		
		string array[4] = {"Luxury","Business","Standard","Economy"};
		temp->ftype = array[type - 1];
		string date = date_select();
		insert_flight_date_price( key, name, date , price);	
}
	void insert_flight_date_price(string key,string name,string date,int price){										//fills user data with dest and dept
	node* temp;
		temp = binarysearch_horizontal(head,key);
		temp = binarysearch_vertical(temp->down,name);			//has reached the name
		
		temp->fdate = date;
		temp->btime = time();
		temp->price = price;
}

	string dest,departure;	
	
	string generatekey(char* name,string key){						//generates key under which the name is placed in the main LL. key is the first alphabet
		int size = sizeof(name) / sizeof(char);
			key = convertToString(name, size);						//converts char array of name to string of name
			char front = key.front();
			if(front <= 90){
				front += 32;
			} 
			key = front;
			return key;	
	}
	void show_flights(string *flights,int size){
		for (int i = 0 , j = 1 ; i < size ; i++,j++){
			cout<<flights[i];
			if(j % 3 != 0  ){
				cout<<"\t\t\t||";
			}
			else cout << endl;			
		}
	}
	void show_airlines(string *airlines,int size){
		for (int i = 0 , j = 1 ; i < size ; i++,j++){
			cout<<airlines[i];
			if(j % 3 != 0  ){
				cout<<"\t\t||";
			}
			else cout << endl;			
		}
	}

	void check(string *flights,string key,string name,int size){
	bool boolf = false, boold = false;
	do{
		cout<<"\nEnter destination: ";	
		getline(cin,dest); 
		dest = string_to_char_array_modified(dest);
		
			for(int i = 0 ; i < size ; i++){
				if(flights[i] == dest)
				boolf = true;
			}
		}while(boolf != true);
	
	do{
		cout<<"Enter departure:   ";	
		getline(cin,departure);
		departure = string_to_char_array_modified(departure);
		
		for(int i = 0 ; i < size ; i++){
			if(flights[i] == departure)
			boold = true;
		}
			if(dest == departure)
			boold = false;	
		cout<<endl;	
	}while(boold != true);
	
	insert_dest_dept(dest,departure,key,name);
}
	void check101(string *flights,string key,string name,int size){
		bool boolf = false, boold = false;
	
		here:	cout<<"\nEnter destination: ";	getline(cin,dest); 
				cout<<"Enter departure:   ";	getline(cin,departure);	
				
		for(int i = 0 ; i < size ; i++){
			if(flights[i] == dest)
			boolf = true;
			if(flights[i] == departure)
			boold = true;
			
			if(dest == departure)
			boolf = false;
			if(boold == true && boolf == true){
				insert_dest_dept(dest,departure,key,name);
					break;
			}
			else {
				if(i == size - 1){
					cout<<"\n\t\tPlease enter Correct Data\n";
					goto here;
				}
				
			}
		}
	}

	void select_airline(string *airlines,int size,string key,string name,int *prices){
		string airline_name ;
here:	static int j = 0;
		int save_price;
		bool boolair = false;
				cout<<"\nSelect Airline for "<<departure<<" to "<<dest<<": "; 
		    	if(j > 0)
				cin.ignore();		        		
				getline(cin, airline_name);	//cout<<airline_name<<endl;
				airline_name = string_to_char_array_modified(airline_name);
				
		for(int i = 0 ; i < size ; i++){
			if(airlines[i] == airline_name){
				boolair = true;
				save_price = i;
			}
			
			
			if(boolair == true ){
				save_price = prices[i];	//gets the value of flight
				insert_airline(key,name,airline_name,save_price);
				break;
			}
			else {
				if(i == size - 1){
					cout<<"\t\tPlease enter Correct Data\n";
					goto here;
				}
			}
		}
	}

	void details(string *airlines,int size,int *prices){
		srand(time(0)); 
		cout<<endl<<"Current Details for "<<departure<<" to "<<dest<<endl<<endl;
		
		
		for(int i = 0 ; i < size ; i++){
			int value = rand()%100000+50000;
			prices[i] = roundUp(value);	//fills array of all prices of flights
			cout<<i+1<<":\tPrice = "<<roundUp(value)<<"/- pkr via "<<airlines[i]<<endl;
			value = rand()%50+50;
			cout<<"\tLuggage allowed = \t"<<roundup10(value)<<"kg  \n";
			float comfort = rand()%7+3;
			cout<<"\tComfort ratings = \t"<<comfort<<"."<<rand()%89+10<<endl;
			int time = rand()%6+6;
			cout<<"\tAprox Time of Journey: \t"<<time<<" hours | "<<roundup10(rand()%58+1)<<" minutes \n";
			int seats = rand()%300+200;
			cout<<"\tSeating Capacity: \t"<<roundup50(seats)<<" seats\n\n";
		}
	}
	void popu_flights(string *arr,int size,string key,string name){
		string flights[size] = {  "Germany",        "Maldives",     "Paris",       "Kashmir",    "Peshawar",
							  	  "Thailand",    	"Turkey",   	"Islamabad",   		"A",  		 "Brazil",
								  "Kuala Lumpur",    		 "Chicago",	    "B",  			"Bangkok", 	 "China",
								  "Italy" , 		"Hong Kong" ,	"Singapore", 	
								  "Rome" , 	 		"Istanbul",  	"Pakistan",
								  "Macau",			"Karachi", 		"Antalya" , 
								  "Mexico",  		"San Francisco","Lisbon",
								  "Moscow" ,        "Beijing"   , 	"Los Angeles",
								  "Texas"  , 		"Abu Dhabi"	,	"Barcelona",
								  "Porto"  , 		"Amsterdam" , 	"Netherlands"
								};
		cout<<"\t\tAvailable flights:  \n\n";
		for(int i = 0 ; i < size ; i++)
		arr[i] = flights[i];
		
		show_flights(flights,size);
		check(flights,key,name,size);
		return;
	}
	void popu_airlines(string *air,int siz,string key,string name){
		system("CLS");
		string airlines[siz] = {"Emirates", 		"Qatar Airways",     "A",       
							    "Fast ITN",      	"American air", 	 "Turk Airways",
							    "Air China", 		"AirAsia", 		 	 "Asiana",
								"Jet Airways"  ,	"Qantas",	 		 "Korean Air",
								"Cathay Pacific",	"Thai Airways"	,	 "Malaysian Airlines"
							 };
		cout<<"\t\tAvailable Airlines:  \n\n";
		
		for(int i = 0 ; i < siz ; i++)								//fills the array created in main func
		air[i] = airlines[i];
		show_airlines(airlines,siz);								//prints the above array of airlines
		
		int prices[15];	//gets filled by being passed into func
		details(airlines,siz,prices);
		select_airline(airlines,siz,key,name,prices);
		return;
	}
	
	//below are admin options
	void adminOptions(string *airline,int size_airlines){
	cout << "-->\tLogged in as Administrator" << endl;

	int choice;
	
    cout<<"\n\tPress Serial Number\n\n\t(1) to view all passengers which are associated with an Airline\n";
    cout<<"\t(2) to see all passengers starting with your name's initial alphabet\n";
 here:  cout<<"\nEnter choice: ";	
  	 	cin>>choice;	cin.ignore();
   
   	if(choice == 1){
		printtable(airline,size_airlines);	
	}	
	else if(choice == 2){
		specific_alphabet_names();
	}	
	else{
		cout<<"Invalid option - Press any key: ";
		getchar();		goto here;
	}
}
	bool check_username_exists(string username){
		string Username;
		string Password;
		
		ifstream infile("Admininfo.txt",ios::in);
			 
		while(infile >> Username >> Password){
			if(Username == username){
			//cout<<"Already exits!\n";	Sleep(500);
			return true;
		}
			
		}	 return false;
	}
	void Login(string key,char* name,string *flights,string *airline,int size_airlines,int size_flights){
		//Admin a;
		system("cls");
		cout << "\tWelcome to your Premium features | Search " << endl<<endl; 
		adminOptions(airline, size_airlines);
		
	}

	void signup(string key,char* name,string *flights,string *airline,int size_airlines,int size_flights,string username,string pwd,string cnic){
		string Username,CNIC;
		string Password;
		
		system("cls");	
		cout << "\tCongratulations on being an Admin. Welcome to your Premium features: " << endl<<endl;
	
		ofstream outfile;//used for file
		outfile.open("Admininfo.txt", ios::app);//will store evetry data we want after it
		
		cout<<"\n\tSign-up -> Fill in your credentials";
here:	cout << "\n\n\tEnter your Username: ";
		Username = inputstring();
	
		
		if(check_username_exists(Username) == true){	// will check if username exist or not
			cout<<"\n\n\tUsername already exists --> try again .";			
			goto here; 
		} 
		Username = add_underscore(Username);
		outfile << Username << "\t"; //will store data and leave 
		
		cout << "\tEnter your Password: ";
		Password = inputstring();
		outfile << Password << "\t";
		
		do{
			cout << "\n\tEnter your CNIC number: ";
			CNIC = inputstring();
		}while(CNIC.size() != 13);
		outfile << CNIC << "\t\n";
		
		cout<<"\n\n\tYou have succesfully created an account\n";	Sleep(1000);
		
		outfile.close();
		
		viewmenu(key,name,flights,airline,size_airlines,size_flights,username,pwd,cnic);
		
	} 

	};

	void loading(){
		system("Color F0");
		cout<<"\n\n\n\n\t     Loading  ";
		char x = 219;
		for(int i = 0 ; i < 45 ; i++){
			cout<<x;
			if(i<10)
			Sleep(300);
			if(i>=10 && i<30)
			Sleep(150);
			if(i >= 30)
			Sleep(50);
		}
		system("cls");
	}
	void homepage(){	
				system("Color F0");
				cout<<"\n\n\n\t\tWelcome to Collective Airline Index by Acubed ";
				Sleep(1000);	
				
				loading();
				system("CLS");
	}

	node* middle_horizontal(node* start, node* last){
		if (start == NULL)
			return NULL;
	
		node* slow = start;
		node* fast = start -> next;
	
		while (fast != last)
		{
			fast = fast -> next;
			if (fast != last)
			{
				slow = slow -> next;
				fast = fast -> next;
			}
		}
	
		return slow;
	}
	node* binarysearch_horizontal(node *head, string value){
		node* start = head;
		node* last = NULL;
	
		do
		{
			node* mid = middle_horizontal(start, last);
	
			if (mid == NULL)
				return NULL;
	
			if (mid -> data == value)
			{
			//	cout << mid->data;
				return mid;
			}
	
			else if (mid -> data < value)
				start = mid -> next;
	
			else
				last = mid;
	
		} while (last == NULL ||
				last != start);
	
		return NULL;
	}	
	node* middle_vertical(node* start, node* last){
		if (start == NULL)
			return NULL;
	
		node* slow = start;
		node* fast = start -> down;
	
		while (fast != last)
		{
			fast = fast -> next;
			if (fast != last)
			{
				slow = slow -> down;
				fast = fast -> down;
			}
		}
	
		return slow;
	}	
	node* binarysearch_vertical(node *head, string value){
	node* start = head;
	node* last = NULL;

	do
	{
		node* mid = middle_vertical(start, last);

		if (mid == NULL)
			return NULL;

		if (mid -> data == value)
		{
			//cout << mid->data;
			return mid;
		}

		else if (mid -> data < value)
			start = mid -> down;

		else
			last = mid;

	} while (last == NULL ||
			last != start);

	return NULL;
}
	
	
int main(){
	
	hashmap userdata;
	char name[MAX_NAME_LEN];
	string key,username,pwd,cnic;
	string array[26];
	string airline[15];
	string flights[36];
	
	homepage();
	system("Color F1");


	int size_of_airline_array = sizeof(airline)/sizeof(airline[0]);
	int size_of_flights_array = sizeof(flights)/sizeof(flights[0]);
	
	userdata.fill_mainLL_alphabets(array);			//array WITH MAIN BRANCH OF 26 CHARACTERS
	userdata.filldata(key,name,airline,flights,size_of_airline_array,size_of_flights_array);	
	

	userdata.viewmenu(key,name,flights,airline,size_of_airline_array,size_of_flights_array,username,pwd,cnic);
	
	
}

