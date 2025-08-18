#include"combination.hpp"


Combination::Combination(): n(0), values(){};

Combination::Combination(const Combination& a):n(a.n),values(a.values){};

Combination::Combination(std::vector<int> v): n(v.size()), values(v){};

int Combination::size() const {
    int m = n;
    return m;
}

int Combination::operator[](int i) const {
    return values[i];
};

std::istream& operator>>(std::istream& is, Combination& combination){
int num;
    std::vector<int> inter;

    for (int i = 0; i < NUMBER_COMBI ; ++i) {
        if (is >> num) {
            inter.push_back(num);
        } else {
            break;
        }
    }
    combination.values = inter;
    combination.n = combination.values.size();
    return is;
};

std::ostream& operator<<(std::ostream& os, const Combination& combination){
for (int i = 0; i<combination.n; i++){
os << combination.values[i] << " ";
}
return os;
};

int Combination::count_rr(const Combination& a) const {
if (n != a.size()){
std::cout<< "erreur de taille" << std::endl;
return 0;
};

int count =0;
for (int i=0; i<n;i++){
if(values[i]==a.values[i]){
    count++;
};
}
return count;
};

std::set<int> Combination::unique_values() const {
    std::set<int> unique_vals;
    for (int i=0; i<n; ++i){
		unique_vals.insert(values[i]);
};
	return unique_vals;
};


int Combination::count_right_place(const int a, const Combination& b) const {
    int count =0;
    for (int i= 0; i< b.size();i++){
        if (a==values[i] && a==b.values[i])
        {
            count++;
        }
        
    }
 return count;
};

int Combination::count_rw(const Combination& a) const {
    if (a.size()!= n)
    {
        std::cout << "erreur de taille pour la proposition"<< std::endl;
        return 0;
    }
    int rw = 0;
    std::set<int> listNum = a.unique_values();
    for (auto it = listNum.begin(); it != listNum.end(); ++it){
        int count_this = std::count(values.begin(), values.end(), *it);
        int count_a = std::count(a.values.begin(), a.values.end(), *it);
        int minus = count_right_place(*it,a);
        rw += std::min(count_this ,count_a) - minus;
    };
    return rw;
};
 
Response Combination::one_try(const Combination& a) const{
    Response final; 
    final.rr = count_rr(a);
    final.rw = count_rw(a);
  return final;
};

bool Combination::won(const Combination& a) const{
    Response r = one_try(a);
    return (r.rr == n);
};

Combination Mastermind::user_guess() const{
Combination F;
Combination vide;
std::cout << "entre ton essai: ";
std::cin >> F;
return F;
};

bool Mastermind::play() const{
    bool win = false;
    int n_guess_count = 0;
    while(n_guess_count < n_guess_max && !win){
        Combination C = user_guess();
        Response r = hidden.one_try(C);
        std::cout << " il y a "<< r.rr << " bonne(s) reponse(s) et " << r.rw << " deplacement(s)" << std::endl;
        win = hidden.won(C); 
        n_guess_count++;
    };
     if (win) {
        std::cout << "Et hop t'as gagne en " << n_guess_count << " essais sur "<< n_guess_max << std::endl;
        }
    else {
        std::cout << "perdu :( " << std::endl;
        };
return win;
};