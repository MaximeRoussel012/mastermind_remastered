#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <set>
#include<vector>
#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>


const int NUMBER_OF_TRY = 10;
const int MIN_NUMBER = 0;
const int MAX_NUMBER= 5;
const int NUMBER_COMBI = 4;


struct Response{
 int rr;
 int rw;
 };

class Combination{
 private:
 int n; 
 std::vector<int> values; 
 public:
 Combination();
 Combination(const std::vector<int> v);
 Combination(const Combination& a);
 std::set<int> unique_values() const;
 int count_value(int) const;
 int count_right_place(const int a, const Combination& b) const;
 int count_rr(const Combination& a) const;
 int count_rw(const Combination& a) const;
 int size() const;
 int operator[](int i) const;
 friend std::istream& operator>>(std::istream& is, Combination& combination);
 friend std::ostream& operator<<(std::ostream& os, const Combination& combination); 
 Response one_try(const Combination& a) const;
 bool won(const Combination& a) const;
 };

  class Mastermind{
 private:
 int n_guess_max; 
 int n_guess_count; 
 Combination hidden; 
 public:
  Mastermind(int M, Combination C): n_guess_max(M), n_guess_count(0), hidden(C){};
  Combination user_guess() const;
  bool play() const;
 }; 

#endif