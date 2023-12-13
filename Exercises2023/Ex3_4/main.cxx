#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "FiniteFunctions.h"
using namespace std;
vector<float> readforx(const string&filenme){ //Reads the x value from the text files and saves as vector floats
    ifstream coeff(filenme);
    vector<float> x1;
    vector<string> d;
    int i =0;
    string a;
    if (coeff.is_open())
    {
        string line;
        getline(coeff,line);
        while(!coeff.eof())
        {
            getline(coeff,a);
            d.push_back(a);
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
    int x = 9;
    cout<<x<<endl;

}