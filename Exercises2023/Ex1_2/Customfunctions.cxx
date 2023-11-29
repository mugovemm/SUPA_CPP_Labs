#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
// #include "CustomFunctions.h"
using namespace std;

// float squrfunc(double num, double num1){
//   return std::sqrt(std::pow(num,2)+std::pow(num1,2));
// }
// vector<float> squrfunc(vector<float> num, vector<float> num1){
//   return sqrt(pow(num,2)+pow(num1,2));
// }



vector<float> readforx(const string&filenme){
    ifstream coeff(filenme);
    vector<float> x1;
    vector<float> y1;
    vector<string> d;
    vector<string> e;
    int i =0;
    string a,b;
    if (coeff.is_open())
    {
        string line;
        getline(coeff,line);
        while(!coeff.eof())
        {
            getline(coeff,a,',');
            d.push_back(a);
            getline(coeff,b);
            e.push_back(b);
            i++;
        } 
        for (int j = 0; j < i-1; j++){
            x1.push_back(stof(d[j]));
            y1.push_back(stof(e[j]));
        }
        coeff.close();
    }
    else{
        cout << "error"<<endl;
    }
    return x1;
}

vector<float> readfory(const string&filenme){
    ifstream coeff(filenme);
    vector<float> x1;
    vector<float> y1;
    vector<string> d;
    vector<string> e;
    int i =0;
    string a,b;
    if (coeff.is_open())
    {
        string line;
        getline(coeff,line);
        while(!coeff.eof())
        {
            getline(coeff,a,',');
            d.push_back(a);
            getline(coeff,b);
            e.push_back(b);
            i++;
        } 
        for (int j = 0; j < i-1; j++){
            x1.push_back(stof(d[j]));
            y1.push_back(stof(e[j]));
        }
        coeff.close();
    }
    else{
        cout << "error"<<endl;
    }
    return y1;
}

void prnt2(vector<float>numb1,vector<float>numb2){
    int i = numb1.size();
    for (int j = 0; j< i-1;j++){
        cout << numb1[j]  << ','<< numb2[j] <<endl;

    }

}

vector <float> magn(vector<float>numb1,vector<float>numb2){
    int i = numb1.size();
    float g;
    vector<float> z;
    for (int j = 0; j< i-1;j++){
        g=sqrt(pow(numb1[j],2)+ pow(numb2[j],2));
        z.push_back(g);
    
    }
    return z;
}
void prnt1(vector<float> vec) {
    for (float element : vec) {
        cout << element << endl;
    }
}
