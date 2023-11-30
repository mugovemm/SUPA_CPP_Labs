#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "CustomFunctions.h"
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
            y1.push_back(stof(e[j]));
        }
        coeff.close();
    }
    else{
        cout << "error"<<endl;
    }
    return x1;
}

vector<float> readfory(const string&filenme){//Reads the y value from the text files and saves as vector floats
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

void prnt2(vector<float>numb1,vector<float>numb2){//able to print two vector floats side by side
    int i = numb1.size();
    for (int j = 0; j< i;j++){
        cout << numb1[j]  << ','<< numb2[j] <<endl;

    }

}

vector <float> magn(vector<float>numb1,vector<float>numb2){//calculates the magnitude
    int i = numb1.size();
    float g;
    vector<float> z;
    for (int j = 0; j< i;j++){
        g=sqrt(pow(numb1[j],2)+ pow(numb2[j],2));
        z.push_back(g);
    
    }
    return z;
}
void prnt1(vector<float> vec) {//only prints a single vector float
    for (float element : vec) {
        cout << element << endl;
    }
}

float fitp (vector<float>x,vector<float>y){//calculadtes the value of p from the fitting equation
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

float fitq (vector<float>x,vector<float>y){//calculates the value of q from the fitting equation
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
float sqrefunc(vector<float>x,vector<float>y,vector<float>ex,vector<float>ey){//calculates the goodness of the fits
    float q = fitq(x,y);
    float p = fitp(x,y);
    int i = x.size();
    float E=0;
    for (int j=0; j<i-1;j++){
        float mm = y[j]-(p*x[j] + q);
        float m = mm*mm;
        float n = ey[j]*ey[j];
        E = E + (m/n);

    }
    return E;
    


}



int main(){
    vector<string>d;//string and vector float declarations necessary for importing data from text file
    vector<string>e;
    vector<float>x;
    vector<float>y;
    string a,b;
    float w;
    int i=0;
    ifstream coeff("input2D_float.txt");//opening the input file
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
            x.push_back(stof(d[j]));//convert the string into a vector float
            y.push_back(stof(e[j]));
            // cout << x[j] <<endl;
            // cout << y[j] <<endl;
        }
        cout << i <<endl;
        coeff.close();
    }
    else{
        cout << "error"<<endl;
    }
    vector<float> datax;//using functions instead of loops so these are vector float declarations
    vector<float> datay;
    vector<float> dataz;
    vector<float> errorx;
    vector<float> errory;
    datax = readforx("input2D_float.txt");
    datay = readfory("input2D_float.txt");
    errorx = readforx("erro2D_float.txt");
    errory = readfory("error2D_float.txt");
    prnt2(datax,datay);//from function that prints two vectors side by side
    dataz = magn(datax,datay);
    prnt1(dataz);

    float p = fitp(datax,datay);//fits for the line
    float q = fitq(datax,datay);
    float t = sqrefunc(datax,datay,errorx,errory);//calculates the goodness of the plot
    cout <<"the value"<< t<<endl;
    int n = datax.size();

    ofstream outfile("magnitude.txt");
    

    for (int i = 0; i < n; i++) {
        outfile << dataz[i] << "\n";
    }

    outfile.close();
    

    ofstream ofile("equation_of_line.txt");
    ofile<<p<<"x +"<<q<<" ";

    ofile.close();
    ofstream newfile("xsquare_value.txt");
    newfile<<"The goodness came out as "<<t<<" ";

    newfile.close();



    return 0;
}