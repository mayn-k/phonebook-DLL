#include <iostream>
#include <string>
using namespace std;

struct Node {
    string phone;
    string email;
    string name;
    Node* next;
    Node* prev;
};

class phonebook {
private:
    Node* head;
    Node* tail;

public:
    phonebook(){
        head = NULL;
        tail = NULL;
    }

    void getDetails(){
        string name, phone, email;
        Node* x;

        cout << " Enter Name: "; cin >> name;
        cout << " Enter Phone Number: "; cin>> phone;
        while(phone.length() != 10) {cout << " Enter Valid Phone Number: "; cin>> phone;}
        cout << " Enter Email: "; cin>> email;

        cout << endl;

        Node* temp = new Node;
        temp->name = name;
        temp->phone = phone;
        temp->email = email;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL){
            head = temp;
            tail = temp;
        }

        else {
            x = head;

            while (x->next != NULL){
                x = x->next;
            }
            x->next = temp;
            temp->prev = x;

            tail = temp;
        }

    }

    void displayAll(){
        Node* x = head;

        if (head == NULL){
            cout << " Phone Book is Empty" << endl << endl;
        }

        else{

            while(x != NULL){
                cout << endl;
                cout << " Name: " << x->name << endl;
                cout << " Phone: +91-" << x->phone << endl;
                cout << " Email: "<< x->email << endl << endl;
                x = x->next;
            }
        }


    }

    void displayAllReversed(){
        Node* x = tail;

        if (tail == NULL){
            cout << " Phone Book is Empty" << endl << endl;
        }

        else{

            while(x != NULL){
                cout << endl;
                cout << " Name: " << x->name << endl;
                cout << " Phone: +91-" << x->phone << endl;
                cout << " Email: "<< x->email << endl << endl;
                x = x->prev;
            }
        }


    }

    void display(Node* x){
            cout << endl;
            cout << " Name: " << x->name << endl;
            cout << " Phone: +91-" << x->phone << endl;
            cout << " Email: "<< x->email << endl << endl;
    }

    void insert(){
        getDetails();
    }

    void deleteContact(string name){
        int check = 0;
        Node* ptr = head;

        while(ptr!=NULL){
            if (name == ptr->name){
                check = 1;
                break;
            }
            ptr = ptr->next;
        }

        if (check == 1 && ptr != head && ptr->next != NULL){
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;

            delete ptr;
            cout << " Contact Deleted Successfully!" << endl << endl;
        }

        else if (check == 1 && ptr == head){
            head = head->next;
            head->prev = NULL;

            delete ptr;
            cout << " Contact Deleted Successfully!" << endl << endl;
        }

        else if (check == 1 && ptr->next == NULL){
            tail = ptr->prev;
            ptr->prev->next = NULL;
            ptr->prev = NULL;



            delete ptr;
            cout << " Contact Deleted Successfully!" << endl << endl;
        }

        else {
            cout << " Contact is not in the Phone Book" << endl << endl;
        }



    }

    void searchByName(string name){
        Node* ptr = head;

        while(ptr != NULL){
            if (ptr->name == name){
                display(ptr);
                break;
            }
            ptr = ptr->next;

        }

        if (ptr == NULL){
            cout << " Contact not Found!" << endl << endl;
        }
    }

    void searchByPhone(string phone){
        Node* ptr = head;

        while(ptr != NULL){
            if (ptr->phone == phone){
                display(ptr);
                break;
            }
            ptr = ptr->next;

        }

        if (ptr == NULL){
            cout << " Contact not Found!" << endl << endl;
        }
    }

    void searchByEmail(string email){
        Node* ptr = head;

        while(ptr != NULL){
            if (ptr->email == email){
                display(ptr);
                break;
            }
            ptr = ptr->next;
        }

        if (ptr == NULL){
            cout << " Contact not Found!" << endl << endl;
        }
    }


    void sortContacts(){
       Node *i, *j;

       string tempName, tempPhone, tempEmail;

       for (i=head; i->next != NULL; i=i->next){

        for (j=i->next; j != NULL; j=j->next){

            if (i->name > j->name){

                tempName = i->name;
                tempPhone = i->phone;
                tempEmail = i->email;

                i->name = j->name;
                i->phone = j->phone;
                i->email = j->email;

                j->name = tempName;
                j->phone = tempPhone;
                j->email = tempEmail;
            }
        }
       }
    }


    void updateContact(string name){
        Node* x = head;
        int ch;
        bool i = true;
        string phone;

        while(x != NULL){
            if(x->name == name){
                while(i == true){
                    cout << endl;
                    cout << " UPDATE CONTACT FOR " << x->name << endl;
                    cout << " 1.UPDATE NAME" << endl;
                    cout << " 2.UPDATE PHONE NUMBER" << endl;
                    cout << " 3.UPDATE EMAIL" << endl;
                    cout << " 4.DISPLAY CONTACT" << endl;
                    cout << " 5.EXIT" << endl;
                    cout << " ENTER YOUR CHOICE: "; cin >> ch;
                    cout << endl;

                    switch(ch){
                        case 1:
                            cout << " Enter New Name: ";
                            cin>> x->name;
                            break;
                        case 2:
                            cout << " Enter New Phone: ";
                            cin >> phone;
                            while((x->phone).length() != 10) {cout << " Enter Valid Phone Number: "; cin>> phone;}
                            x->phone = phone;
                            break;
                        case 3:
                            cout << " Enter New Email: ";
                            cin >> x->email;
                            break;
                        case 4:
                            display(x);
                            break;
                        default:
                            i = false;
                            break;

                    }
                }
                break;
            }
            x = x->next;
        }


        if (x == NULL){
            cout << " Contact Not Found" << endl  << endl;
        }

        else {
            cout << " Contact Updated Successfully!" << endl << endl;
        }

    }
    /* destructor to check head & tail
    ~phonebook(){
        cout << "============================" << endl;
        display(head);
        display(tail);
        cout << "============================" << endl;
    }
    */
};


int main(){
    phonebook ph;

    int choice;
    string n;



    while(1){

        cout << endl ;
        cout << "----------------------------" << endl;
        cout << "         PHONE BOOK" << endl;
        cout << "----------------------------" << endl;
        cout << " 1.DISPLAY[A-Z]" << endl;
        cout << " 2.DISPLAY[Z-A]" << endl;
        cout << " 3.ADD NEW CONTACT" << endl;
        cout << " 4.UPDATE EXSITING CONTACT" << endl;
        cout << " 5.SEARCH BY NAME" << endl;
        cout << " 6.SEARCH BY PHONE NUMBER" << endl;
        cout << " 7.SEARCH BY EMAIL" << endl;
        cout << " 8.DELETE CONTACT" << endl;
        cout << " 9.EXIT" << endl;
        cout << "----------------------------" << endl;
        cout << " ENTER YOUR CHOICE: ";
        cin >> choice;
        cout << endl;

        switch(choice){
            case 1:
                ph.sortContacts();
                ph.displayAll();
                break;
            case 2:
                ph.displayAllReversed();
                break;
            case 3:
                ph.insert();
                ph.sortContacts();
                break;
            case 4:
                cout << "Enter Contact Name to Update: "; cin >> n;
                ph.updateContact(n);
                ph.sortContacts();
                break;
            case 5:
                cout << "Enter Name to Search: "; cin >> n;
                ph.searchByName(n);
                break;
            case 6:
                cout << "Enter Phone Number to Search: "; cin >> n;
                ph.searchByPhone(n);
                break;
            case 7:
                cout << "Enter Email to Search: "; cin >> n;
                ph.searchByEmail(n);
                break;
            case 8:
                cout << "Enter Contact Name to Delete: "; cin >> n;
                ph.deleteContact(n);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
