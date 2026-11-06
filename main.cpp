#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
using namespace std;

class CompteSecure {
private:
    string titulaire;
    double solde;

public:
    CompteSecure(string nom, double montant)
        : titulaire(nom), solde(montant) {

        if (montant < 0) {
            throw invalid_argument("Solde invalide !");
        }
    }

    void deposer(double montant) {
        if (montant <= 0) {
            throw invalid_argument("Montant de depot invalide !");
        }

        solde += montant;
        cout << "Depot effectue." << endl;
    }

    void retirer(double montant) {
        if (montant <= 0) {
            throw invalid_argument("Montant invalide !");
        }

        if (montant > solde) {
            throw runtime_error("Solde insuffisant !");
        }

        solde -= montant;
        cout << "Retrait effectue." << endl;
    }

    void afficher() const {
        cout << "Titulaire: " << titulaire << endl;
        cout << "Solde: " << solde << endl;
    }
};

int main() {
    try {
        unique_ptr<CompteSecure> compte(
            new CompteSecure("Hiba", 1000)
        );

        compte->afficher();

        compte->deposer(500);
        compte->retirer(200);

        cout << "\nApres operations:" << endl;
        compte->afficher();

        compte->retirer(2000);
    }
    catch (const exception& e) {
        cout << "Erreur: " << e.what() << endl;
    }

    return 0;
}