#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    string surname;
    int* grades;      // Dinaminis masyvas
    int examGrade;
    int hwCount = 0;  // Kiek buvo ivesta namu darbu

    Student() {
        grades = new int[100]; // Dinaminis masyvas su pradine talpa (100)
    }

    ~Student() {
        delete[] grades; // Isvalome atminti sunaikinant objektą
    }

    void inputStudentData() {
        cout << "Vardas: ";
        cin >> name;
        cout << "Pavarde: ";
        cin >> surname;
    
        // Dinaminis namu darbu ivedimas
        cout << "Iveskite namu darbu balus (1-10). Iveskite -1, jei norite baigti: ";
        while (hwCount < 100) {
            int grade;
            cin >> grade;
        
            if (cin.fail()) {  // Tikrina, ar buvo ivesta ne skaicius (Nusprendzia pagal kintamojo tipa)
                cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: ";
                cin.clear();  // Isvalo klaidos busena
                cin.ignore(1000, '\n');  // Pasalina netinkama ivesti is buferio
                continue;  // Kartojame cikla
            }
        
            if (grade == -1) 
                break;
        
            if (grade >= 1 && grade <= 10) {
                grades[hwCount++] = grade;  // Irašome i masyva
            }
            else {
                cout << "Neteisingas balas! Kartokite (1-10): ";
                cin.clear();  // Isvalo klaidos busena
                cin.ignore(1000, '\n');  // Pasalina netinkama ivesti is buferio
            }
        }
        cout << "Iveskite egzamino bala (1-10): ";
        while (true) {
            cin >> examGrade;
            if (examGrade >= 1 && examGrade <= 10) {
                break;
            }
            else {
                cout << "Neteisingas skaicius! Kartokite (1-10): ";
                cin.clear();
                cin.ignore(100, '\n');
            }
        }
    }

    // Skaiciuojam vidurki
    double calculateAverage() {
        if (hwCount == 0) 
            return 0;
        int sum = 0;
        for (int i = 0; i < hwCount; i++) {
            sum += grades[i];
        }
        return static_cast<double>(sum) / hwCount; // Pavercia sum i double, kad dalyba (double / int) gautume atsakyma double
    }

    // Skaiciuojam mediana
    double calculateMedian() {
        if (hwCount == 0)
            return 0.0;
        sort(grades, grades + hwCount);
        if (hwCount % 2 == 0)
            return (grades[hwCount / 2 - 1] + grades[hwCount / 2]) / 2.0; // Dalinam is 2.0 kad rezultatas butu double
        return grades[hwCount / 2];
    }

    //Apskaiciuojamas galutinis vertinimas (Kuris skaiciuojamas nuo vartotojo pasirinkimo (ar medianu, ar vidurkiu))
    double calculateFinalGrade(bool useMedian) {
        return 0.4 * (useMedian ? calculateMedian() : calculateAverage()) + 0.6 * examGrade;
        // Jei vartotojas pasirinko mediana tuomet True yra skaiciuojamas, jei vidurki tada False skaiciuojamas
    }
    
};

    int main() {
        Student* students = new Student[100];
        int studentCount = 0;  // Skaiciuojamas studentu skaicius
        char choice;

    // Studentu duomenu ivedimas
    while (true) {
        students[studentCount].inputStudentData();
        studentCount++;
        cout << "Ivesti kita studenta? (t/n): ";
        cin >> choice;
        if (choice != 't' && choice != 'T')
            break;
    }

    char method;
    while (true) {
    cout << "Pasirinkite metoda skaciavimui (v - vidurkis, m - mediana): ";
    cin >> method;
    if (method == 'v' || method == 'V' || method == 'm' || method == 'M'){
        break;
        }
    else{
        cout << "Neteisinga reiksme. Prasome ivesti 'v' arba 'm'." << endl;
        }
    }

    bool useMedian = (method == 'm' || method == 'M');

    // Reaultatu isvedimas
    cout << "\nPavarde    Vardas    Galutinis (" << (useMedian ? "Med." : "Vid.") << ")\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < studentCount; i++) {
    cout << left << setw(12) << students[i].surname << setw(12) << students[i].name<< "  " << fixed << setprecision(2) << students[i].calculateFinalGrade(useMedian) << endl;
    }
    
    delete[] students; //Atlaisvinam dinamine atminti

    return 0;
}