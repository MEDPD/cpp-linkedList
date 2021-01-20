#include <iostream>

//!  code challenge URL https://www.hackerrank.com/challenges/virtual-functions/problem
using namespace std;

class Person{
protected:
    string name;
    int age;

public: 
    Person(string name, int age){
        this->name = name; this->age = age;
    }

};

class Professor: Person{
private: 
    string publications;
    static int id_inc; // unique ID, this prop is a class prop and not an object prop
    const int cur_id;
public:
    Professor(string name, int age, string pub): Person(name, age), cur_id(++id_inc){
        this->publications = pub; 
    }
    Professor getdata(){
        string name, pub; int age;
        cin >> name >> pub >> age;
        return Professor(name, age, pub);
    }
    void putData(){

    }
};

class Student: Person{

};



int main(int argc, char const *argv[])
{
   
    cout << "GoodBye World !" << endl;
    return 0; 
}
