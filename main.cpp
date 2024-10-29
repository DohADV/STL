#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct problema {
    string idProblema;
    string specializare;
};

struct doctor {
    string idDoctor;
    string specializareDr;
};

int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;

    inFile >> no_problems;
    vector<problema> probleme(no_problems);
    vector<bool> rezolvat(no_problems);
    for (int i = 0; i < no_problems; i++)
        rezolvat[i] = 0;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> probleme[i].idProblema;
        inFile >> probleme[i].specializare;
        //cout << name << ' ' << speciality << '\n';
    }

    inFile >> no_doctors;
    vector<doctor> doctori(no_doctors);

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> doctori[i].idDoctor;
        inFile >> doctori[i].specializareDr;
        //cout << name << ' ' << speciality << '\n';
    }

    for (int i = 0; i < no_problems; i++) {
        for (int j = 0; j < no_doctors; j++)
            if (probleme[i].specializare == doctori[j].specializareDr && rezolvat[i] == 0) {
                rezolvat[i] = 1;
                cout << probleme[i].idProblema << " Acceptat\n";
                break;
            }
        if (rezolvat[i] == 0) cout << probleme[i].idProblema << " Respins\n";
    }

    return 0;
}