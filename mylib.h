#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::sort;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::ws;
using std::istream_iterator;
using std::distance;
using std::stringstream;
using std::exception;
using std::setw;
using std::left;
using std::to_string;
using std::list;

/*struct Studentas {
  string st_Vardas;
  string st_Pavarde;
  int nd_kiekis = 0;
  vector <int> nd_balai;
  int egz_rez;
  double rez;
};*/
class Zmogus
{
    protected:
        string st_Vardas;
        string st_Pavarde;
    public:
        virtual void setVardas(string vardas) { st_Vardas = vardas; }
        virtual void setPavarde(string pavarde) { st_Pavarde = pavarde; }
        inline string getVardas() const { return st_Vardas; }
        inline string getPavarde() const { return st_Pavarde; }

        Zmogus()
        {
            st_Vardas = "";
            st_Pavarde = "";
        }
};

class Studentas : public Zmogus{
private:
    string st_Vardas, st_Pavarde;
    int nd_kiekis = 0;
    vector <int> nd_balai;
    int egz_rez;
    double rez;
public:
    ~Studentas(){ nd_balai.clear(); }
     Studentas() {
        egz_rez = 0;
        rez = 0;
    }
    Studentas(const Studentas &s)
    {
        st_Vardas = s.st_Vardas;
        st_Pavarde = s.st_Pavarde;
        egz_rez = s.egz_rez;
        nd_kiekis = s.nd_kiekis;
        rez=s.rez;
        nd_balai = s.nd_balai;
    }
    Studentas& operator=(const Studentas& s)
    {
        if (this == &s)
        {
            return *this;
        }
        st_Vardas = s.st_Vardas;
        st_Pavarde = s.st_Pavarde;
        std::copy(s.nd_balai.begin(), s.nd_balai.end(), nd_balai.begin());
        egz_rez = s.egz_rez;
        rez = s.rez;
        nd_kiekis = s.nd_kiekis;
        return *this;
    }
    double getRez() const { return rez; }
    void setNd(vector<int> nd) { nd_balai=nd; }
    inline int getEgz() const { return egz_rez; }
    void setEgz(int egz) { egz_rez = egz; }
    void setNdK(int ndKiekis) { nd_kiekis = ndKiekis; }
    void setRez(double rezi) { rez = rezi; }
};

double mediOrAvg (string vid_or_med, vector <Studentas> first_st, int temp, int student_kiekis);
void generateFile(int fileSize, string name);
void failo_skaitymasvec(vector<Studentas> &kint, string file_name, string vid_or_med, int &studentu_skaicius);
bool cmp(const Studentas &stud_1,const  Studentas &stud_2);

#endif // STUDENTAS_H_INCLUDED


#endif // MYLIB_H_INCLUDED
