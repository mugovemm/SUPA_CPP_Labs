#include <iostream>
#include <string>
#include <vector>
#include "FiniteFunctions.h"
#include <filesystem>
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

vector<float> readforx(const string&filenme){ //Reads the x value from the text files and saves as vector floats
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
        }
        coeff.close();
    }
    else{
        cout << "error"<<endl;
    }
    return x1;
}
int main(){
    vector<float>x;
    x = readforx("Mysterydata01441.txt");
}