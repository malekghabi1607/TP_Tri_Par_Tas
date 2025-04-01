#include "tp2.h"
#include <iostream>

using namespace std;

int main() {

    for (int n = 10; n <= 1000000; n *= 10) { // Pour n = 10, 100, 1000, ..., 1,000,000
        tableau tableauObj(n); // Créer un objet de type tableau
        tableauObj.test(n); // Lancer le test
    }

    return 0;
}
