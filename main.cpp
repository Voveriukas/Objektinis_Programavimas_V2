#include "mylib.h"

int main() {
    srand(time(NULL));
    int student_kiekis=0;
    vector <Studentas> first_st;
    string vid_or_med;
    cout << "Ar norite suzinoti studento (-u) rezultata skaiciuota su mediana ar vidurkiu? (med / vid)";cin >> vid_or_med;
    while (vid_or_med != "vid" && vid_or_med != "med") {
        cout << "Ivedama reiksme turi buti arba vid arba med." << endl;
        cout << "Bandykite is naujo: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> vid_or_med;
    }
    int fileSize=1000;
    char yra_st;
    vector <Studentas> nuskriaustieji_scnd;
    string file_name;
    // File create
    cout << "Ar norite sugeneruoti naujus failus? (T / N) "; cin >> yra_st;
    while (yra_st != 'T' && yra_st != 'N' && yra_st !=  't' && yra_st != 'n') {
        cout << "Ivedama reiksme turi buti arba T arba N" << endl;
        cout << "Bandykite is naujo: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> yra_st;
    }
    if(yra_st=='T' || yra_st=='t')
    {
        for (int i=fileSize; i<=10000000; i*=10)
        {
            file_name = "studentai_" + to_string(i) + ".txt";
            generateFile(i, file_name);
        }
        cout << "Failai sugeneruoti" << endl;
    }
    cout << "| " << setw(30) << left << "Dydis" << " | " << setw(45) << left << "Rusiavimas i nuskriaustuosius ir galvocius" << " | " << endl;
    for (int i=fileSize; i<=10000000; i*=10)
    {
        file_name = "studentai_" + to_string(i) + ".txt";
        auto start1 = std::chrono::high_resolution_clock::now();
        failo_skaitymasvec(first_st, file_name, vid_or_med, student_kiekis);
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;

        // Vector operation 2nd

        auto start5 = std::chrono::high_resolution_clock::now();
        sort(first_st.begin(), first_st.end(), cmp);
        first_st.erase(remove_if(first_st.begin(), first_st.end(), [&nuskriaustieji_scnd](Studentas s) {
        if (s.getRez() < 5.00) {
            nuskriaustieji_scnd.push_back(s);
            return true;
        }
        else { return false; }
        }), first_st.end());
        auto end5 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff5 = end5 - start5;
        nuskriaustieji_scnd.clear();
        first_st.clear();
        cout << "| " << setw(30) << left << i << " | " << setw(45) << left << diff5.count() << " | " << endl;
    }
    cout << string(82, '-') << endl;
  return 0;
}
