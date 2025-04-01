#include "tp2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


// Constructeur qui génère un tableau aléatoire de taille n
tableau::tableau(int n) : n(n) {
    T = new int[n];
    srand(time(0)); // Initialisation de la génération aléatoire
    for (int i = 0; i < n; i++) {
        T[i] = rand() % 1901 + 100; // Génère des nombres entre 100 et 2000
    }
}

// Destructeur pour libérer la mémoire allouée au tableau
tableau::~tableau() {
    delete[] T;
}

// Affichage du contenu du tableau
void tableau::affiche() {
    for (int i = 0; i < n; i++) {
        cout << T[i] << " ";
    }
    cout << endl;
}

// Tri par tas   

// Tri par tas
int tableau::triTas() {
    int echanges = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        reorganiser(i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(T[0], T[i]);
        echanges++;
        n--;
        reorganiser(0);
    }
    return echanges;
}


// Tri par bulle
int tableau::triBulle() {
    int echanges = 0;
   for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (T[j] > T[j + 1]) {
                // Utilisation d'une variable temporaire pour échanger
                int temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
                echanges++;
            }
        }
    }
    return echanges;
}




// Tri par insertion
int tableau::triInsertion() {
    int echanges = 0;
    for (int i = 1; i < n; i++) {
        int cle = T[i];
        int j = i - 1;
        while (j >= 0 && T[j] > cle) {
            T[j + 1] = T[j];
            j--;
            echanges++;
        }
        T[j + 1] = cle;
    }
    return echanges;
}


// Réorganisation en tas pour maintenir la propriété de tas à partir de l'indice 
void tableau::reorganiser(int j) {
    int gauche = 2 * j + 1;
    int droite = 2 * j + 2;
    int plus_grand = j;

    // Comparaison avec l'enfant gauche
    if (gauche < n && T[gauche] > T[plus_grand]) {
        plus_grand = gauche;
    }

    // Comparaison avec l'enfant droit
    if (droite < n && T[droite] > T[plus_grand]) {
        plus_grand = droite;
    }

    // Si le plus grand élément n'est pas le parent
    if (plus_grand != j) {
        // Échange manuel des éléments T[j] et T[plus_grand] 
        int temp = T[j];
        T[j] = T[plus_grand];
        T[plus_grand] = temp;

        // Appel récursif pour vérifier le sous-arbre
        reorganiser(plus_grand);
    }
}
// Suppression de l'élément minimum (ou maximum selon le type de tas) et réorganisation du tas
int tableau::suppression() {
    if (n == 0) {
        return -1; // Cas où le tableau est vide
    }

    int min = T[0];
    T[0] = T[n - 1];
    n--;
    reorganiser(0);
    return min;
}

// Méthode pour tester les tris

int tableau::test(int n) {
    // Affichage d'un tableau des résultats pour chaque n
    string separator = "------------------------------------------------------------------------";

    // Initialisation des variables pour stocker les échanges et les temps
    int exchangesBulle = 0, exchangesInsertion = 0, exchangesTas = 0;
    double timeBulle = 0.0, timeInsertion = 0.0, timeTas = 0.0;

    // Exécution des tris et collecte des résultats
    for (int iteration = 0; iteration < 10; iteration++) {
        tableau tableauTemp(n);
        int* copy = new int[n];

        // Copie des valeurs pour les tests
        for (int i = 0; i < n; i++) {
            copy[i] = tableauTemp.T[i]; // Copie des valeurs
        }

        // Tri Bulle
        time_t start = time(nullptr); // Temps de départ
        exchangesBulle += tableauTemp.triBulle();
        time_t end = time(nullptr); // Temps de fin
        timeBulle += difftime(end, start); // Calculer la différence

        // Réinitialiser le tableau
        for (int i = 0; i < n; i++) {
            tableauTemp.T[i] = copy[i];
        }

        // Tri par Insertion
        start = time(nullptr); // Temps de départ
        exchangesInsertion += tableauTemp.triInsertion();
        end = time(nullptr); // Temps de fin
        timeInsertion += difftime(end, start); // Calculer la différence

        // Réinitialiser le tableau
        for (int i = 0; i < n; i++) {
            tableauTemp.T[i] = copy[i];
        }

        // Tri par Tas
        start = time(nullptr); // Temps de départ
        exchangesTas += tableauTemp.triTas();
        end = time(nullptr); // Temps de fin
        timeTas += difftime(end, start); // Calculer la différence

        delete[] copy;
    }


    // Affichage des résultats pour n

    cout << "                        " << endl;
    cout << "n        Nom du Tri          Nb d'Echanges               Temps(s)          " << endl;
    cout << separator << endl;
 


    // Affichage des résultats pour chaque tri 
    cout << n << "      " << "Bulle                " << exchangesBulle  << "                           " << timeBulle << endl;
    cout << n << "      " << "Insertion            " << exchangesInsertion << "                          " << timeInsertion << endl;
    cout << n << "      " << "Tas                  " << exchangesTas  << "                            " << timeTas<< endl;

    return 0;
}
