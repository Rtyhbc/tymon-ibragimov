#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
public:
    string name;
    int age;
    string email;
    string date;

    friend ostream& operator<<(ostream& out, const User& user) {
        out << user.name << "\n" << user.age << "\n" << user.email << "\n" << user.date << "\n";
        return out;
    }


    friend istream& operator>>(istream& in, User& user) {
        getline(in, user.name);
        in >> user.age;
        in.ignore(); 
        getline(in, user.email);
        getline(in, user.date);
        return in;
    }
};

int main() {
    User user1;
    user1.name = "Myknailo";
    user1.age = 15;
    user1.email = "tymonmykhailo@gmail.com";
    user1.date = "2023-10-07";


    ofstream outFile("user.txt");
    if (outFile.is_open()) {
        outFile << user1;
        outFile.close();
    }
    else {
        cout << "Не вдалося відкрити файл для запису." << endl;
        return 1;
    }


    ifstream inFile("user.txt");
    if (inFile.is_open()) {
        User user2;
        inFile >> user2;
        inFile.close();


        cout << "Name: " << user2.name << endl;
        cout << "Age: " << user2.age << endl;
        cout << "Email: " << user2.email << endl;
        cout << "Date: " << user2.date << endl;
    }
    else {
        cout << "Не вдалося відкрити файл для читання." << endl;
        return 1;
    }

    return 0;
}
