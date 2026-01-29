#include <iostream>
#include <fstream>
using namespace std;
    char name[50];
    char phone[15];
    char email[50];
 int directory[100]; 
int contact_count = 0;
void addContact(){
	ofstream myfile("number.txt", ios::app);
	cout<<"\nEnterName: ";
	cin>>name;
	cout<<"\nEnter phone Number: ";
	cin>>phone;
	cout<<"\nEnter email: ";
	cin>>email;
	myfile << name << endl; << phone << endl; << email << endl;
    myfile.close();
    cout << "Contact saved successfully!\n";
}
void displayContacts(){
    ifstream myfile("number.txt");
    cout << "\n--- Contact List ---\n";
    int count = 1;
    while (myfile >> name >> phone>>email) {
        cout << count++ << ". Name: " << name << " | Phone: " << phone << endl;}
	myfile.close();}
void searchContact(){
	ifstream myfile("number.txt");
	bool found = false;
	string s;
	cout<<"\nEnter Name To Search: ";
	cin>>s;
	while(myfile >> name>> phone>>email)
	{
		if(s == name)
		{
			cout<<"\nContact Found!";
			cout<<"\nName: "<<name;
			cout<<"\nPhone Number: "<<phone;
			cout<<"\nEmail: "<<email;
			found = true;
			break;
		}
	}
	if(!found){
		cout<<"\nOOPS! No Contact Found!";
	}
	myfile.close();
}
int main() {
    int choice;
    while (true) {
        cout << "\n1. Add Contact\n2. Display All\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) addContact();
        else if (choice == 2) displayContacts();
        else if (choice == 3) break;
        else cout << "Invalid choice.\n";
    }
    return 0;
}
