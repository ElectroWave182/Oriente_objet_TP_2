# include <iostream>
# include <bits/stdc++.h>

using namespace std;


int main ()
{


    string nom, nomPersonne, prenomPersonne, contenu;
    int agePersonne;


    // Entrees
	
    cout << "Donnez le nom du fichier : ";
    cin >> nom;

    cout << "Donnez votre nom : ";
    cin >> nomPersonne;
    contenu = "Nom : " + nomPersonne + '\n';

    cout << "Donnez votre prénom : ";
    cin >> prenomPersonne;
    contenu = contenu + "Prénom : " + prenomPersonne + '\n';

    cout << "Donnez votre age : ";
    cin >> agePersonne;
    contenu = contenu + "Age : " + to_string (agePersonne) + '\n';
	
	
	// Initialisation
	
	ifstream entree (nom); 
	ofstream sortie (nom); 


    // Ecriture
	
    sortie << contenu << '\n';
    cout << "Enregistrement terminé" << "\n\n";
	sortie.close ();
	
	
	// Lecture
	
	string ligne;
	
	while (! entree.eof ())
	{
		getline (entree, ligne);
		cout << ligne << '\n';
	}
	entree.close ();
	
	
	return 0;


}