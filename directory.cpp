#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Directory
{
public:
    string name;
    string owner;
    string phone;
    string address;
    string activity;
    Directory(string name, string owner, string phone, string address, string activity)
    {
        this->name = name;
        this->owner = owner;
        this->phone = phone;
        this->address = address;
        this->activity = activity;
    }
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Owner: " << owner << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "Activity: " << activity << endl;
        cout << "----------------------" << endl;
    }
};

class DirectoryManager
{
private:
    vector<Directory> _records;
public:
    void Add()
    {
        string name, owner, phone, address, activity;
        cout << "Enter company name: ";
        getline(cin, name);
        cout << "Enter owner: ";
        getline(cin, owner);
        cout << "Enter phone: ";
        getline(cin, phone);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter activity: ";
        getline(cin, activity);
        _records.push_back(Directory(name, owner, phone, address, activity));
        ofstream file("directory.txt", ios::app);
        file << name << endl;
        file << owner << endl;
        file << phone << endl;
        file << address << endl;
        file << activity << endl;
        file.close();
        cout << "Record added!" << endl;
    }

    void Load()
    {
        ifstream file("directory.txt");
        if (!file.is_open())
            return;
        string name, owner, phone, address, activity;
        while (getline(file, name))
        {
            if (!getline(file, owner)) break;
            if (!getline(file, phone)) break;
            if (!getline(file, address)) break;
            if (!getline(file, activity)) break;
            _records.push_back(Directory(name, owner, phone, address, activity));
        }

        file.close();
    }
    void ShowAll()
    {
        for (int i = 0; i < _records.size(); i++)
        {
            _records[i].Print();
        }
    }
    void Search(int choice)
    {
        string value;
        cout << "Enter search value: ";
        getline(cin, value);
        for (int i = 0; i < _records.size(); i++)
        {
            if ((choice == 1 && _records[i].name == value) ||
                (choice == 2 && _records[i].owner == value) ||
                (choice == 3 && _records[i].phone == value) ||
                (choice == 4 && _records[i].activity == value))
            {
                _records[i].Print();
            }
        }
    }
};

int main()
{
    DirectoryManager manager;
    manager.Load();
    int choice;
    do
    {
        cout << "\n1. Add record" << endl
            << "2. Show all records" << endl
            << "3. Search by name" << endl
            << "4. Search by owner" << endl
            << "5. Search by phone" << endl
            << "6. Search by activity" << endl
            << "0. Exit" << endl
            << "Choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            manager.Add();
            break;
        case 2:
            manager.ShowAll();
            break;
        case 3:
            manager.Search(1);
            break;
        case 4:
            manager.Search(2);
            break;
        case 5:
            manager.Search(3);
            break;
        case 6:
            manager.Search(4);
            break;
        }

    } while (choice != 0);








    return 0;


}
