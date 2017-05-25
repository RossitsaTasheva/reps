//============================================================================
// Name        : ~Vector_sort_DOG.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

struct Dog
{
    string name;
    int age;
    short scaryness;

    Dog()
    {
        this->name="";
        this->age = 0;
        this->scaryness = 0;
    }

    Dog(string name, int age, short scaryness)
    {
        this->name = name;
        this->age = age;
        this->scaryness = scaryness;
    }
};

struct DogComp
{
    bool sortDirection;
    bool operator()(Dog a, Dog b)
    {
        if(sortDirection)
        {
            return a.age < b.age;
        }
        else
        {
            return a.age > b.age;
        }
    }
};

int main()
{
    vector<int> numbers;
    numbers.push_back(42);
    numbers.push_back(9);
    numbers.push_back(24);
    numbers.push_back(13);
    numbers.push_back(57);
    numbers.push_back(1559);
    numbers.push_back(257);

    cout<<"First 3 numbers sorted:"<<endl;
    sort(numbers.begin(), numbers.begin() + 3);
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;

    cout<<"All numbers sorted:"<<endl;
    sort(numbers.begin(), numbers.end());
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;

    Dog dogs[3];
    dogs[0] = Dog("Sharo", 10, 2000);
    dogs[1] = Dog("Mustafa", 1, 3000);
    dogs[2] = Dog("Laika", 57, 0);

    DogComp comparatorObject = DogComp();

    cout<<"Dogs sorted ascending:"<<endl;
    comparatorObject.sortDirection = true;
    sort(dogs, dogs+3, comparatorObject);
    for(int i=0; i<3; i++)
    {
        cout<<dogs[i].name<< " " << dogs[i].age << " " << dogs[i].scaryness << endl;
    }

    cout<<"Dogs sorted descending:"<<endl;
    comparatorObject.sortDirection = false;
    sort(dogs, dogs+3, comparatorObject);
    for(int i=0; i<3; i++)
    {
        cout<<dogs[i].name<< " " << dogs[i].age << " " << dogs[i].scaryness << endl;
    }
}
