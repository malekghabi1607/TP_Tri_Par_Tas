# TP2 - Algorithmique Avancée : Tri par Tas

## 🎯 Objectif
L'objectif de ce TP est de comparer les performances de trois algorithmes de tri sur des tableaux d'entiers générés aléatoirement :

- Tri par Tas (Heap Sort)
- Tri par Insertion
- Tri à Bulles (Bubble Sort)

Ces opérations sont regroupées dans une classe nommée `tableau`.

---

## 🧱 Fichiers du projet

| Fichier        | Description |
|----------------|-------------|
| `tp2.h`        | Déclaration de la classe `tableau` et de ses méthodes |
| `tp2.cpp`      | Implémentation des tris et des fonctions associées |
| `main.cpp`     | Programme principal qui crée des objets `tableau` et appelle la méthode `test()` |
| `sujet.pdf`    | Sujet du TP fourni par l’enseignant |
| `algo.pdf`     | Document de rappel sur les structures et algorithmes |
| `programme`    | Fichier exécutable généré (à ignorer dans Git) |
| `tasks.json`   | Fichier de configuration des tâches pour l'IDE (Visual Studio Code)

---

## ⚙️ Compilation

### Avec g++ en ligne de commande :

```bash
g++ main.cpp tp2.cpp -o programme
./programme

