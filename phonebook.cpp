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

        cout << "Enter Name: "; cin >> name;
        cout << "Enter Phone Number: "; cin>> phone;
        while(phone.length() != 10) {cout << "Enter Valid Phone Number: "; cin>> phone;}
        cout << "Enter Email: "; cin>> email;

        cout << endl;

        Node* temp = new Node;
        temp->name = name;
        temp->phone = phone;
        temp->email = email;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL){
            head = temp;
        }

        else {
            x = head;

            while (x->next != NULL){
                x = x->next;
            }
            x->next = temp;
            temp->prev = x;
        }

    }

    void displayAll(){
        Node* x = head;

        if (head == NULL){
            cout << "Phone Book is Empty" << endl << endl;
        }

        else{

            while(x != NULL){
                cout << endl;
                cout << "Name: " << x->name << endl;
                cout << "Phone: +91-" << x->phone << endl;
                cout << "Email: "<< x->email << endl << endl;
                x = x->next;
            }
        }


    }

    void display(Node* x){
            cout << endl;
            cout << "Name: " << x->name << endl;
            cout << "Phone: +91-" << x->phone << endl;
            cout << "Email: "<< x->email << endl << endl;
    }

    void insert(){
        getDetails();
    }

    void deleteContact(string name){
        int check = 0;
        Node* ptr = head;

        while(ptr!=NULL){   // traversing and checking if name exist
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
            cout << "Contact Deleted Successfully!" << endl << endl;
        }

        else if (check == 1 && ptr == head){
            head = head->next;
            head->prev = NULL;

            delete ptr;
            cout << "Contact Deleted Successfully!" << endl << endl;
        }

        else if (check == 1 && ptr->next == NULL){
            ptr->prev->next = NULL;
            ptr->prev = NULL;

            delete ptr;
            cout << "Contact Deleted Successfully!" << endl << endl;
        }

        else {
            cout << "Contact is not in the Phone Book" << endl << endl;
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
            cout << "Contact not Found!" << endl << endl;
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
            cout << "Contact not Found!" << endl << endl;
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
            cout << "Contact not Found!" << endl << endl;
        }
    }


};


int main(){
    phonebook ph;

    ph.insert();

    ph.displayAll();

    ph.deleteContact("x-men");

    ph.displayAll();

    //ph.displayAll();

    //ph.searchByName("");

    //ph.searchByEmail("");

    //ph.searchByPhone("");


    return 0;
}
