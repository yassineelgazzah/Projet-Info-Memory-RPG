# Projet-Info-Memory-RPG

Bienvenue dans le CY-Memory-RPG. Dans ce jeu, entre 2 et 4 aventuriers se lancent dans la découverte d'un labyrinthe à la recherche d'un coffre au trésor et d'une arme antique, tout en affrontant les monstres qui s'y trouvent. 

Objectif du jeu :

L'objectif pour chaque aventurier est de :
 - Parcourir le labyrinthe sans être vaincu par les monstres.
 - Trouver au moins un coffre au trésor.
 - Trouver son arme antique spécifique.

Aventuriers et armes antiques :

Le jeu propose 4 types d'aventuriers, chacun à la recherche d’un trésor et de son arme antique : 
 - Le guerrier est à la recherche de l'épée de feu. 
 - Le ranger est à la recherche du bâton de contrôle des familiers. 
 - Le magicien est à la recherche du grimoire interdit. 
 - Le voleur est à la recherche de la dague de sommeil.

Plateau de jeu (Labyrinthe) :

Le plateau de jeu est un labyrinthe composé de 25 cases face retournées. Elles cachent plusieurs éléments, distribués aléatoirement dans le labyrinthe, bénéfiques ou défavorables pour la partie de l’aventurier. Voici ce que les cases du labyrinthe peuvent contenir :
 - 4 armes antiques (1 de chaque type mentionné précédemment). 
 - 2 coffres au trésor. 
 - 16 monstres répartis en différentes catégories : 
       - Basilics : seul le bouclier peut les vaincre. 
       - Zombies : seule la torche peut les éliminer. 
       - Trolls : seule la hache peut les vaincre. 
       - Harpies : seul un arc peut les vaincre. 
 - 1 portail qui permet de se téléporter. 
 - 2 totems de transmutation.

Instructions pour jouer :

1. Avant de commencer la partie, choisissez le nombre d'aventuriers qui participeront à la partie (entre 2 et 4) et leurs noms.
2. Les aventuriers sont positionnés à l’extérieur du labyrinthe.
3. La partie démarre avec le ranger, s’ensuit le guerrier, le voleur et le magicien. Chaque joueur effectue un trajet dans le labyrinthe à tour de rôle.
4. Avant de se déplacer d'une case dans le labyrinthe, chaque aventurier doit choisir une arme parmi les quatre disponibles : bouclier, torche, arc ou hache. Chaque arme permet de vaincre un type de monstre spécifique en fonction des descriptions précédentes.
5. L'aventurier peut avancer d'une case dans n'importe quelle direction (haut, bas, gauche, droite) à condition qu'il n'y ait pas d'obstacles lui bloquant le passage.
6. Lorsqu'un aventurier rencontre un monstre, il doit utiliser l'arme appropriée pour le vaincre. Si l'aventurier n'a pas la bonne arme, il est vaincu et le tour passe au joueur suivant.
7. Si l'aventurier parvient à vaincre un monstre, il peut continuer à avancer dans le labyrinthe.
8. L'objectif de chaque aventurier est de trouver un coffre au trésor et son arme antique. Une fois ces objectifs atteints, il sera considéré comme vainqueur.
9. Le jeu se poursuit jusqu'à ce qu’un aventurier soit déclaré vainqueur.
10. Le vainqueur est l’aventurier qui a trouvé un coffre au trésor et une arme antique.
11. À la fin de la partie, les joueurs peuvent décider de relancer une partie pour tenter de nouvelles stratégies ou explorer davantage le labyrinthe.

Amusez-vous bien dans le CY-Memory-RPG, combattant les dangers du labyrinthe à la recherche de votre arme antique afin de remporter la partie.

MakeFile :

Voici une explication simplifiée de la façon dont le Makefile fonctionne :

1. Tout d'abord, le Makefile définit deux cibles principales : main et main-debug.
2. La variable CC est définie avec la valeur clang, ce qui spécifie que le compilateur C utilisé sera Clang.
3. La variable CFLAGS est définie avec l'option -g -Wno-everything -pthread -lm. Ces options sont passées au compilateur pour définir les indicateurs de compilation.
  -g inclut les informations de débogage dans le binaire généré. 
  -Wno-everything désactive tous les avertissements du compilateur. 
  -pthread active le support des threads POSIX. 
  -lm lie la bibliothèque mathématique lors de la compilation.
4. Les variables SRCS et HEADERS sont définies à l'aide de la commande find. Elles récupèrent respectivement les chemins de tous les fichiers source (.c) et les fichiers d'en-tête (.h) présents dans le répertoire courant et ses sous-répertoires, à l'exception du répertoire .ccls-cache.
5. La cible main dépend des fichiers source ($(SRCS)) et des fichiers d'en-tête ($(HEADERS)). Si l'un de ces fichiers est modifié, la cible doit être reconstruite.
6. La recette de la cible main utilise la variable CC pour appeler le compilateur C avec les indicateurs de compilation CFLAGS, les fichiers source $(SRCS) et crée l'exécutable "main" en sortie.
7. La cible main-debug fonctionne de manière similaire à main, mais avec l'ajout de l'indicateur d'optimisation -O0 pour désactiver l'optimisation du code. Cela facilite le débogage.
8. La cible clean est fournie pour supprimer les fichiers exécutables générés main et main-debug à l'aide de la commande rm.

En résumé, ce Makefile permet de construire les exécutables main et main-debug en compilant les fichiers source C avec les indicateurs de compilation spécifiés. La cible clean permet de supprimer les exécutables générés.

