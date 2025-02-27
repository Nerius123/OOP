#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>  
#include <algorithm> 

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::fixed;
using std::setprecision;
using std::left;

struct Student {
    string name;
    string surname;
    vector<int> grades;
    int examGrade;


void inputStudentData() {
    cout << "Vardas: "; 
    cin >> name;
    cout << "Pavarde: "; 
    cin >> surname;

    // Namu darbu balu ivedimas
    cout << "Iveskite namu darbu balus (1-10). Iveskite -1, jei norite baigti.\n";
    int grade;
    while (cin >> grade && grade != -1) grades.push_back(grade);
    
    //Egzamino balu ivedimas ir ju tikrinimas
    cout << "Iveskite egzamino bala (1-10): ";
    while(true) {
        cin >> examGrade;
        if (examGrade >= 1 && examGrade <= 10) {
            break;
        }
        else {
            cout << "Neteisingas skaicius! Kartokite (1-10): ";
            cin.clear(); // Isvalo cin klaidos busena 
            cin.ignore(100, '\n'); // Pasalina visus likusius simbolius iki naujos eilutes, kad cin veiktu normaliai
        }
    }
}

    //Apskaiciuojamas vidurkis 
    double calculateAverage() {
        if (grades.empty())
            return 0;
    return accumulate(grades.begin(), grades.end(), 0.0) / grades.size(); // Susumuoja visus skaicius
    }

    //Apskaiciuojamas medianas
    double calculateMedian() {
        if (grades.empty()) 
            return 0;
        sort(grades.begin(), grades.end()); // Surusiuoja vektoriu didejancia tvarka
        int n = grades.size();
        return (n % 2 == 0) ? (grades[n / 2 - 1] + grades[n / 2]) / 2.0 : grades[n / 2];
    }

    //Apskaiciuojamas galutinis vertinimas (Kuris skaiciuojamas nuo vartotojo pasirinkimo (ar medianu, ar vidurkiu))
    double calculateFinalGrade(bool useMedian) {
        return 0.4 * (useMedian ? calculateMedian() : calculateAverage()) + 0.6 * examGrade;
    }
         // Jei vartotojas pasirinko mediana tuomet True yra skaiciuojamas, jei vidurki tada False skaiciuojamas 
};