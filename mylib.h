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

class Studentas{
private:
    string st_Vardas, st_Pavarde;
    int nd_kiekis = 0;
    vector <int> nd_balai;
    int egz_rez;
    double rez;
public:
    Studentas(string vardas, string pavarde, int egzas, double rezul, int nd_k, vector<int> nd);
    double getRez() const;
};

double mediOrAvg (string vid_or_med, vector <Studentas> first_st, int temp, int student_kiekis);
void generateFile(int fileSize, string name);
void failo_skaitymasvec(vector<Studentas> &kint, string file_name, string vid_or_med, int &studentu_skaicius);
bool cmp(const Studentas &stud_1,const  Studentas &stud_2);

#endif // STUDENTAS_H_INCLUDED


#endif // MYLIB_H_INCLUDED
