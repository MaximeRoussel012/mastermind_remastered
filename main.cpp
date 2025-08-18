#include"combination.hpp"
#include<random>


int NUMBER_OF_TRY = 10;
int MIN_NUMBER = 0;
int MAX_NUMBER= 5;
int NUMBER_COMBI = 4;

int main(){
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(MIN_NUMBER, MAX_NUMBER);
    std::vector<int> v;
 
    for (int n = 0; n < NUMBER_COMBI; ++n){
        v.push_back(distrib(gen));
    }
    Combination goal(v);

   /* std::fstream fichier("combinaison_4.dat");
     if (!fichier) {
        std::cout << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }
    Combination a_deviner;
    fichier >> a_deviner;*/

    Mastermind game(NUMBER_OF_TRY, goal);
    std::cout<< "Bienvenue dans mon MasterMind, tu as " << NUMBER_OF_TRY << " chances pour trouver la combinaison de " << NUMBER_COMBI << " chiffres compris entre " << MIN_NUMBER << " et " << MAX_NUMBER << ". Bonne chance ;)" << std::endl;
    bool win = game.play();
    if (!win) {
        std::cout << "la reponse etait " << goal << std::endl; 
        };

    //fichier.close(); 
    return 0;
}