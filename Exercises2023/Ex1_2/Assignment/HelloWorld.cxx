#include <iostream>
#include <cmath>

float squrfunc(double num, double num1){
  return std::sqrt(std::pow(num,2)+std::pow(num1,2));
}
int main(){

  std::cout << "Hello World!"<<std::endl;
  float x,y,z;
  x=3;
  y=4.5;
  z= squrfunc(x,y);
  std::cout << "z="<<z<<std::endl;


  return 0;

}

