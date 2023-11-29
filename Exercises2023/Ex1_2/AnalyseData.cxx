#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "CustomFunctions.h"
using namespace std;

float squrfunc(double num, double num1){
  return std::sqrt(std::pow(num,2)+std::pow(num1,2));
}


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
    for (int j = 0; j< i;j++){
        cout << numb1[j]  << ','<< numb2[j] <<endl;

    }

}

vector <float> magn(vector<float>numb1,vector<float>numb2){
    int i = numb1.size();
    float g;
    vector<float> z;
    for (int j = 0; j< i;j++){
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

float fitp (vector<float>x,vector<float>y){
    int i = x.size();
    float xy=0;
    float a=0;
    float b=0;
    float x2=0;
    float all = 0;
    float all2 = 0;
    for(int j=0; j<i ; j++){
        xy = xy+x[j]*y[j];
        a = a+x[j];
        b = b+y[j];
        x2 = x2+(x[j]*x[j]);
    }
    all = ((i*xy)-(a*b))/(x2-(a*b));
    all2 = ((x2*b)-(xy*a))/((i*x2)-(a*a));
    float r[2] = {all,all2};


    return all;

}

float fitq (vector<float>x,vector<float>y){
    int i = x.size();
    float xy=0;
    float a=0;
    float b=0;
    float x2=0;
    float all = 0;
    float all2 = 0;
    for(int j=0; j<i ; j++){
        xy = xy+x[j]*y[j];
        a = a+x[j];
        b = b+y[j];
        x2 = x2+(x[j]*x[j]);
    }
    all = ((i*xy)-(a*b))/(x2-(a*b));
    all2 = ((x2*b)-(xy*a))/((i*x2)-(a*a));
    float r[2] = {all,all2};


    return all2;

}
// float fitq(vector<float>x,vector<float>y){


// }


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
    vector<float> dataz;
    datax = readforx("input2D_float.txt");
    datay = readfory("input2D_float.txt");
    // prnt2(datax,datay);
    // dataz = magn(datax,datay);
    // prnt1(dataz);
    cout<< fitp(datax,datay)<<endl;
    return 0;


}