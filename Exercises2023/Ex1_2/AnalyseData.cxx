#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

float squrfunc(double num, double num1){
  return std::sqrt(std::pow(num,2)+std::pow(num1,2));
}

vector<float> readfile(const string&filenme){
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
        cout<< "yourvalues"<<endl; 
        for (int j = 0; j < i-1; j++){
            x1.push_back(stof(d[j]));
            y1.push_back(stof(e[j]));
            cout << x1[j] <<endl;
            cout << y1[j] <<endl;
        }
        cout << i <<endl;
        coeff.close();
    }
    else{
        cout << "error"<<endl;
    }
    return x1,y1;
}



int main(){
    // vector<string>d;
    // vector<string>e;
    // vector<float>x;
    // vector<float>y;
    // string a,b;
    // float w;
    // int i=0;
    // ifstream coeff("input2D_float.txt");
    // if (coeff.is_open())
    // {
    //     string line;
    //     getline(coeff,line);
    //     while(!coeff.eof())
    //     {
    //         getline(coeff,a,',');
    //         d.push_back(a);
    //         getline(coeff,b);
    //         e.push_back(b);
    //         i++;
    //     }
    //     cout<< "yourvalues"<<endl; 
    //     for (int j = 0; j < i-1; j++){
    //         x.push_back(stof(d[j]));
    //         y.push_back(stof(e[j]));
    //         cout << x[j] <<endl;
    //         cout << y[j] <<endl;
    //     }
    //     cout << i <<endl;
    //     coeff.close();
    // }
    // else{
    //     cout << "error"<<endl;
    // }
    // return 0;
    vector<float> data1;
    vector<float> data2;
    data1,data2 = readfile("input2D_float.txt");



}