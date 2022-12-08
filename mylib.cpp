#include "mylib.h"

zmogus::zmogus() {}
zmogus::zmogus(const zmogus& kint) {
    *this = kint;
}
zmogus& zmogus::operator=(const zmogus& kint) {

    st_Vardas = kint.st_Vardas;
    st_Pavarde = kint.st_Pavarde;

    return *this; }

zmogus::Zmogus(string vardas, string pavarde) {
    this->st_Vardas = vardas;
    this->st_Pavarde = pavarde;
}

string zmogus:: getVardas() { return st_Vardas; }
string zmogus::getPavarde() { return st_Pavarde; }

void zmogus::setVardas(string nvardas) { st_Vardas = nvardas; }
void zmogus::setPavarde(string npavarde) { st_Pavarde = npavarde; }
zmogus::~zmogus() {}

Studentas::Studentas() {}
Studentas::Studentas(int egzas, double rezul, int nd_k, vector<int> nd) {
    this->egz_rez = egzas;
    this->rez = rezul;
    this->nd_kiekis = nd_k;
    this->nd_balai = nd;
}

Studentas::Studentas(const Studentas& kint) :zmogus(kint){ *this = kint; }
Studentas& Studentas::operator=(const Studentas& kint)  {
    zmogus::operator=(kint);
    paz = kint.paz;
    egz = kint.egz;
    gal = kint.gal;
    return *this;
}

const vector<int>& Studentas::getPaz() const { return paz; }
double Studentas::getRez() const { return gal; }
double Studentas::getEgz() const { return egz; }

void Studentas::setPaz(vector<int> npaz) { paz = npaz; }
void Studentas::setGal(double ngal) { gal = ngal; }
void Studentas::setEgz(double negz) { egz = negz; }

void Studentas::failo_nuskaitymas(std::ifstream& skaitymas) {
    for (auto& p : paz) { skaitymas >> p; }
    skaitymas >> egz;
}
Studentas::~Studentas() {}
void Studentas::abstr() {}

double mediOrAvg (string vid_or_med, vector<int> &arr, int n, int egz_rez)
{
  double mediOrAvg;
  if (vid_or_med == "vid") {
    if (n == 0) mediOrAvg = 0;
    else mediOrAvg = std::accumulate(arr.begin(), arr.end(),0.0)/(double)n;
  }
  else
  {
    if (n == 0)
    {
      mediOrAvg = 0;
    }
    else{
      std::sort(arr.begin(),arr.end());
      if (n % 2 == 0)
      {
          mediOrAvg = (double)arr[n/2];;
      }
      else
      {
          mediOrAvg = (double)(arr[(n-1)/2]+arr[n/2])/2.0;
      }
    }

  }
  return mediOrAvg * 0.4 + (double)egz_rez * 0.6;
}


void generateFile(int fileSize, string name)
{
    stringstream buffer;
    std::ofstream out(name);
    int temp = (rand()% 10 + 1);
    buffer << "Vardas" << setw(15) << "Pavarde";
    for(int i = 0; i < temp; i++){
        buffer << setw(15) << "ND" << i+1;
    }
    buffer << setw(15) << "Egz.\n";
    for(int i = 0; i < fileSize; i++){
        buffer << "Vardas" << i+1 << setw(15) << "Pavarde" << i+1;
        for(int j = 0; j < temp; j++){
            buffer << setw(15) << (rand()% 10 + 1);
        }
        buffer << setw(15) << (rand()% 10 + 1) << "\n";
    }
    out << buffer.str();
    buffer.clear();
    out.close();
}

void failo_skaitymasvec(vector<Studentas> &sar, string filename, string vid_or_med, int &studentu_skaicius)
{
   try{
        std::ifstream fr(filename);
        if(!fr.fail()){
        int sk;
        string line;
        string temp,pirmaEil;
        int kiekNd = -3;
        std::getline(fr >> std::ws,pirmaEil);
       stringstream iss(pirmaEil);
        while(iss >> temp)
        {
            kiekNd++;
        }
        while(std::getline(fr >> std::ws,line)){
            string vardas;
            string pavarde;
            int egzas;
            double rezul;
            vector<int> nd;
            stringstream iss(line);
            iss>> vardas;
            iss >> pavarde;
            for(int i = 0; i < kiekNd; i++){
                iss>> sk;
                nd.push_back(sk);
            }
            iss >> sk;
            egzas=sk;


            rezul = mediOrAvg(vid_or_med,nd,kiekNd, egzas);

            Studentas s(egzas, rezul, kiekNd, nd);
            s(vardas, pavarde);
            cout << s.getVardas() << " " << s.getPavarde() << " " << s.getRez() << " " << s.getEgz() << endl;
            sar.push_back(s);
        }
        }
        else{
            throw std::runtime_error(filename);
        }
        studentu_skaicius=sar.size();
    }
    catch(std::exception &e){
     cout << "Ivyko problema nuskaitant faila: " << e.what() << "\n";
     std::exit(0);
  }
}

bool cmp(const Studentas &stud_1,const  Studentas &stud_2) {
    if (stud_1.getRez() < stud_2.getRez()){return true;}
    else {return false;}
}

