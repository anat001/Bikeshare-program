#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAX_YEARS = 5;
const int MAX_CAPACITY = 500;

void printfiveyearsold1(double aeven[], double aodd[], int n);
void printfiveyearsold2(double beven[], double bodd[], int n);
void findbicycle1(double aeven[], double aodd[], int target, int n);
void findbicycle2(double beven[], double bodd[], int target, int n);

int main () {

int count = 0;
int i = 0;
int mnum;
int target;
const int m1 = 1,
          m2 = 2,
          m3 = 3,
          m4 = 4;
string buf;
string txtchoice;
string userchoice;
string a = "a2.txt";
string b = "b2.txt";

double *aarray = new double[MAX_CAPACITY];
double *aeven = new double[MAX_CAPACITY];
double *aodd = new double[MAX_CAPACITY];

double *barray = new double[MAX_CAPACITY];
double *beven = new double[MAX_CAPACITY];
double *bodd = new double[MAX_CAPACITY];

ifstream fA;
fA.open("a2.txt");

while (!fA.eof()) {
fA >> aarray[count];
count++;
}
for (count = 1; count < 201; count++) {
    if (count % 2 == 0) {
    aeven[count] = aarray[count];
    } else {
     aodd[count] = aarray[count];
    }
    } 

fA.close();
ifstream fB;
fB.open("b2.txt");

while(!fB.eof()) {
fB >> barray[i];
i++;
}

for(int i = 1; i < 401; i++) {
    if(i % 2 == 0) {
    beven[i] = barray[i];
    } else {
    bodd[i] = barray[i];
    }
}

fB.close();

while(true) {
    cout << "\nMenu\n";
    cout << "----\n";
    cout << "1) Read bicycle entries from a file.\n";
    cout << "2) Print a report of bicycles older than 5 years.\n";
    cout << "3) Print how long ago a bicycle was purchased.\n";
    cout << "4) Exit the program.\n";
    cout << "Your choice? ";
    getline(cin, userchoice);
    mnum = atoi(userchoice.c_str());

   

switch (mnum) {
    case m1: {
        cout << "Filename? ";
        getline(cin, txtchoice);
        cout << "\n";
        if(txtchoice == a) {
         cout << aarray[0] << " entries read from a2.txt\n"; 
        } else if (txtchoice == b) {
         cout << barray[0] << " entries read from b2.txt\n";
        }
    } break;
    case m2: {
        if(txtchoice == a) {
            cout << "\n";
            printfiveyearsold1(aeven, aodd, 100);
            
        } else if(txtchoice == b) {
            cout << "\n";
            printfiveyearsold2(beven, bodd, 200);
            
        }
    }
    break;
    case m3: {
        if(txtchoice == a) {
            cout << "Enter the serial number to find: ";
            cin >> buf; target = atoi(buf.c_str());
            cout << "\n"; 
            findbicycle1(aeven, aodd, target, 100);
            cin.ignore(1000, 10);
        } else if (txtchoice == b) {
        cout << "Enter the serial number to find: ";
        cin >> buf; target = atoi(buf.c_str());
        cout << "\n";
        findbicycle2(beven, bodd, target, 200);
        cin.ignore(1000, 10);
    }
    }
    break;
    case m4: 
    cout << "\nExiting...\n";
    exit(0);
    break;
    
}
}
}

void printfiveyearsold1(double aeven[], double aodd[], int n) {
    int i;
    for(int count = 2; count < 201; count++) {
        if(aeven[count] > MAX_YEARS) {
            i = count - 1;
            cout << "Serial number: " << aodd[i] << ", acquired " << aeven[count] << " years ago.\n";
        }

    }
}

void printfiveyearsold2(double beven[], double bodd[], int n) {
    int i;
    for(int count = 2; count < 401; count++) {
        if(beven[count] > MAX_YEARS) {
            i = count - 1;
            cout << "Serial number: " << bodd[i] << ", acquired " << beven[count] << " years ago.\n";
        }
    }
}
void findbicycle1(double aeven[], double aodd[], int target, int n) { 
    int i;
    for(int count = 1; count < 201; count++) {
        if(aodd[count] == target) {
            i = count + 1;
            cout << "Serial number: " << aodd[count] << " was acquired " << aeven[i] << " years ago.\n";
        }
    }

}

void findbicycle2(double beven[], double bodd[], int target, int n) {
    int i;
    for (int count = 1; count < 401; count++) {
        if(bodd[count] == target) {
            i = count + 1;
            cout << "Serial number: " << bodd[count] << " was acquired " << beven[i] << " years ago.\n";
        }
    }
}

