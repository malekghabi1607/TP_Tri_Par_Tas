#ifndef TP2_H
#define TP2_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class tableau {
    int* T; // Tableau d'entiers
    int n;  // Taille du tableau

public:
    tableau(int n);     // Constructeur pour initialiser un tableau de taille n
    ~tableau();        // Destructeur pour libérer la mémoire
    void affiche();   // Affichage du contenu du tableau
    int triTas();         // Tri par tas
    int triBulle();   // tri par bulle 
    int triInsertion();   // Tri par insertion    
    int  test(int n); /// Test les tris sur des tableaux aléatoires

    // Méthodes supplémentaires pour le tri par tas
    void reorganiser(int j); // Réorganisation du tas à partir de l'indice j
    int suppression();       // Suppression et réorganisation pour maintenir le tas

};

#endif // TP2_H
