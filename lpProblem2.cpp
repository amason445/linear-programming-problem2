#include <algorithm>
#include <tuple>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

typedef std::vector< std::tuple<double, double, double> > solutionsVector;

std::tuple<double, double, double> ObjectiveFunction(double x1, double x2) {

  double z;

  z = (0.3 * x1) + (0.9 * x2);

  return {z, x1, x2};


}

//constraint: both variables must be >= 0
solutionsVector solutionsSpace(int n){

  solutionsVector sv;

  for (int i1 = 0; i1 <= n * 10; i1++) {

    for (int i2 = 0; i2 <= n * 10; i2++) {

     const double x1 = i1 / 10.0;
     const double x2 = i2 / 10.0;

      std::tuple<double, double, double> solutionSet = ObjectiveFunction(x1, x2);

      sv.push_back(solutionSet);
    }
  }

  return sv;

}


int main() {

  int n = 1000;

  solutionsVector sv;

  sv = solutionsSpace(n);

  //0.21x1 - 0.30x2 <= 0
  sv.erase(std::remove_if(sv.begin(), sv.end(), [](std::tuple<double, double, double>& x) -> bool { return (std::get<1>(x) * 0.21) - (std::get<2>(x) * 0.3) > 0; }), sv.end());

  //.03x1 - .01x2 >= 0
  sv.erase(std::remove_if(sv.begin(), sv.end(), [](std::tuple<double, double, double>& x) -> bool { return (std::get<1>(x) * 0.03) - (std::get<2>(x) * 0.01) < 0; }), sv.end());

  //x1 + x2 >= 800
  sv.erase(std::remove_if(sv.begin(), sv.end(), [](std::tuple<double, double, double>& x) -> bool { return std::get<1>(x) + std::get<2>(x) < 800; }), sv.end());

  //minimize solutions vector

  auto result = std::min_element(sv.begin(), sv.end(), [](const std::tuple<double, double, double> &x, const std::tuple<double, double, double> &y) {return std::get<0>(x) < std::get<0>(y); });

  //print solution

  std::cout << "The objective equation to be minimized is z = 0.3x1 + 0.9x2. \n";
  std::cout << "The minimized solution is: " << std::get<0>(*result) << "\n";
  std::cout << "Variable x1 = " << std::get<1>(*result) << " and variable x2 = " << std::get<2>(*result) << std::endl;


}
