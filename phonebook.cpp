#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Contact {
private:
    string name;
    string number; //As it will be a 10 or 12 digit
public:
    Contact() {}
    Contact(string name, string number) {
        this->name = name;
        this->number = number;
    }

    void setName(string name) {
        this->name = name;
    }
    void setNumber(string number) {
        this->number = number;
    }

    string getName() const {
        return this->name;
    }
    string getNumber() const {
        return this->number;
    }

    void display() const {
        cout << "Name : " << this->name << endl << "Phone No. : " << this->number << endl;
    }

    bool matchesName(string name) const {
        return this->name == name;
    }
    bool matchesNumber(string number) const {
        return this->number == number;
    }

    string toFileString() const {
        return this->name + "," + this->number;
    }
    void fromFileString(string line) {
        size_t comma = line.find(',');
        if(comma != string::npos) {
            this->name = line.substr(0, comma);
            this->number = line.substr(comma+1);
        }
    }
};

class ContactManager {
private:
    vector<Contact> contacts;
    const string fileName = "contacts.txt";
public:
    void loadFromFile() {
        contacts.clear();
        ifstream file(fileName);
        string line;
        while(getline(file, line)) {
            Contact contact;
            contact.fromFileString(line);
            contacts.push_back(contact);
        }
        file.close();
    }

    void saveToFile() {
        ofstream file(fileName);
        for(auto contact : contacts) {
            file << contact.toFileString() << endl;
        }
        file.close();
    }

    void addContact() {
        string name, number;
        cout << "Enter name : ";
        cin.ignore(); //for any leftover newline character
        getline(cin, name);
        cout << "Enter phone number : ";
        getline(cin, number);
        contacts.push_back(Contact(name, number));
        cout << "Contact added successfully!\n";
    }

    void displayAll() {
        if(contacts.empty()) {
            cout << "No contacts available!\n";
            return ;
        }
        for(auto contact : contacts) {
            contact.display();
        }
    }

    void searchByName() {
        string name;
        cout << "Enter name you want to seach : ";
        cin.ignore();
        getline(cin, name);
        bool present = false;
        for(auto contact : contacts) {
            if(contact.matchesName(name)) {
                contact.display();
                present = true;
            }
        }
        if(!present) cout << "Contact not found!\n";
    }

    void searchByNumber() {
        string number;
        cout << "Enter number you want to seach : ";
        cin.ignore();
        getline(cin, number);
        bool present = false;
        for(auto contact : contacts) {
            if(contact.matchesNumber(number)) {
                contact.display();
                present = true;
            }
        }
        if(!present) cout << "Contact not found!\n";
    }

    void updateContact() {
        string name;
        cout << "Enter contact name to update: ";
        cin.ignore();
        getline(cin, name);
        for (auto contact : contacts) {
            if (contact.matchesName(name)) {
                string newName, newNumber;
                cout << "Enter new name: ";
                getline(cin, newName);
                cout << "Enter new number: ";
                getline(cin, newNumber);
                contact.setName(newName);
                contact.setNumber(newNumber);
                cout << "Contact updated successfully.\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void deleteContact() {
        string name;
        cout << "Enter Name to delete: ";
        cin.ignore();
        getline(cin, name);
        auto it = remove_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.getName() == name;
        });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            cout << "Contact deleted successfully.\n";
        } else {
            cout << "Contact not found.\n";
        }
    }

    void deleteAll() {
        contacts.clear();
        cout << "All contacts deleted.\n";
    }

    void countContacts() {
        cout << "Total contacts: " << contacts.size() << endl;
    }
};
// Menu Function
int menu() {
    cout << "\n========= PHONE BOOK MENU =========\n";
    cout << "1. Add Contact\n";
    cout << "2. Display All Contacts\n";
    cout << "3. Search by Name\n";
    cout << "4. Search by Number\n";
    cout << "5. Update Contact\n";
    cout << "6. Delete Contact\n";
    cout << "7. Delete All Contacts\n";
    cout << "8. Count Contacts\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}

// Main Function
int main() {
    ContactManager cm;
    cm.loadFromFile();

    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1: cm.addContact(); break;
            case 2: cm.displayAll(); break;
            case 3: cm.searchByName(); break;
            case 4: cm.searchByNumber(); break;
            case 5: cm.updateContact(); break;
            case 6: cm.deleteContact(); break;
            case 7: cm.deleteAll(); break;
            case 8: cm.countContacts(); break;
            case 9: cm.saveToFile(); cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}