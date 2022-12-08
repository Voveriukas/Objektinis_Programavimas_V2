#include "mylib.h"

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
        ifstream fr(filename);
        if(!fr.fail()){
        int sk;
        double temp2;
        string line;
        string temp,pirmaEil;
        int kiekNd = -3;
        getline(fr >> ws,pirmaEil);
       stringstream iss(pirmaEil);
        while(iss >> temp)
        {
            kiekNd++;
        }
        while(getline(fr >> ws,line)){
            Studentas s;
            stringstream iss(line);
            iss>> temp;
            s.setVardas(temp);
            iss >> temp;
            s.setPavarde(temp);
            vector<int> nd;
            for(int i = 0; i < kiekNd; i++){
                iss>> sk;
                nd.push_back(sk);
            }
            s.setNd(nd);
            s.setNdK(kiekNd);
            iss >> sk;
            int rezul;
            s.setEgz(sk);
            rezul = mediOrAvg(vid_or_med,nd,kiekNd, sk);
            s.setRez(rezul);
            sar.push_back(s);
        }
        }
        else{
            throw std::runtime_error(filename);
        }
        studentu_skaicius=sar.size();
    }
    catch(exception &e){
     cout << "Ivyko problema nuskaitant faila: " << e.what() << "\n";
     system("pause");
     exit(0);
  }

}

bool cmp(const Studentas &stud_1,const  Studentas &stud_2) {
    if (stud_1.getRez() < stud_2.getRez()){return true;}
    else {return false;}
}

