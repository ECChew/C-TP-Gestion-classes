#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct personne {
    int identifiant{};
    std::string nom;
    std::string prenom;
    std::string ddn;
    std::string ville;
    int cp{};

    personne(const personne &);

    personne() {

    }

};

personne::personne(const personne &p) {
    personne p1;
    identifiant = p.identifiant;
    nom = p.nom;
    prenom = p.prenom;
    ddn = p.ddn;
    ville = p.ville;
    cp = p.cp;

}

int main() {
    std::string nf{"o"};
    std::cout << "Nom du fichier?" << std::endl;
    std::string ligne;
    std::cin >> nf;
    std::ifstream fichier{nf};
    std::vector<personne> donnees{};
    int k = 0;
    while (std::getline(fichier, ligne)) {
        if (fichier) {
            personne p;
            fichier >> p.identifiant >> p.nom >> p.prenom >> p.ddn >> p.ville
                    >> p.cp;  // on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée
            donnees.push_back(p);
            k++;
            //std::cout << p.identifiant << std::endl;
        }
    }
    std::cout << donnees[0].identifiant << std::endl;
    std::vector<personne> donneesf{};
    std::cout << "Nombre de personnes :" << k << std::endl;

    for (int i = 0; i < k; i++) {
        if ((donnees[i].identifiant > 500) && (donnees[i].cp / 1000 == 13)) {
            personne df(donnees[i]);
            donneesf.push_back(df);
            std::cout << donneesf[i].identifiant << std::endl;
            std::cout << donneesf[i].cp << std::endl;
        }
    }

    std::cout << "Travail termine" << std::endl;
    return 0;
}