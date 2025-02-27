#include "my_library.h"

int main() {

    vector<Student> students;

    char choice;
    while (true){
        Student s;
        s.inputStudentData();
        students.push_back(s);
        cout << "Ivesti kita studenta? (t/n): ";
        cin >> choice;
        if (choice != 't' && choice != 'T') 
            break;
    }
    
    char method;
    while (true) {
        cout << "Pasirinkite metoda skaciavimui (v - vidurkis, m - mediana): ";
        cin >> method;
        if (method == 'v' || method == 'V' || method == 'm' || method == 'M') {
            break;
        } 
        else {
            cout << "Neteisinga reiksme. Prasome ivesti 'v' arba 'm'." << endl;
        }
    }

    bool useMedian = (method == 'm' || method == 'M');

    cout << "\nPavarde    Vardas    Galutinis (" << (useMedian ? "Med." : "Vid.") << ")\n";
    cout << "----------------------------------------\n";
    for (auto &s : students) {
        cout << left << setw(12) << s.name << setw(12)  << s.surname << "  " << fixed << setprecision(2) << s.calculateFinalGrade(useMedian) << endl;
    }
}