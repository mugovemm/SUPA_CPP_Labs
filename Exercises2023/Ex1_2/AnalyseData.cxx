#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

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

void prnt(vector<float>numb1,vector<float>numb2){
    int i = numb1.size();
    for (int j = 0; j< i-1;j++){
        cout << numb1[j]  << ','<< numb2[j] <<endl;

    }

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
    //     for (int j = 0; j < i-1; j++){
    //         x.push_back(stof(d[j]));
    //         y.push_back(stof(e[j]));
    //         // cout << x[j] <<endl;
    //         // cout << y[j] <<endl;
    //     }
    //     cout << i <<endl;
    //     coeff.close();
    // }
    // else{
    //     cout << "error"<<endl;
    // }
    vector<float> datax;
    vector<float> datay;
    datax = readfory("input2D_float.txt");
    datay = readfory("input2D_float.txt");
    prnt(datax,datay);
    // printVector(datay);
    return 0;
    // cout << 'hello' <<endl;

    // auto[data]=squrfunc(data1,data2);




}