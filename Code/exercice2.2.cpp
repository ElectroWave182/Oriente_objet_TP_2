# include <cmath>
# include <iostream>
# include <vector>
// # include <opencv2/opencv.hpp> 

using namespace std;


void afficher
(vector <auto> & vecteur)
{
	for (auto element: vecteur)
	{
		cout
			<< to_string (element)
			<< "\n"
		;
	}
}


void modifier
(
	vector <auto> & vecteur,
	uint index,
	auto affecte
)
{
	uint taille = vecteur.size ();
	
	if (index >= taille)
	{
		afficher (vecteur);
		cout
			<< "\nSortie des limites du vecteur."
			<< "\nLimite : "
			<< taille
			<< "\nIndex : "
			<< index
		;
		exit (0);
	}
	
	else
	{
		vecteur [index] = affecte;
	}
}


void peindre
(
	vector <auto> & image,
	uint hauteur,
	uint largeur
)
{
	uint
		taille = image.size (),
		nbCanaux = taille / (hauteur * largeur),
		index
	;
	
	for (uint ligne = 0; ligne < hauteur; ligne ++)
	{
		for (uint colonne = 0; colonne < largeur; colonne ++)
		{
			index = (ligne * largeur + colonne) * nbCanaux;
			cout
				<< "["
				<< image [index]
			;
			
			for (uint canal = 1; canal < nbCanaux; canal ++)
			{
				index = (ligne * largeur + colonne) * nbCanaux + canal;
				cout
					<< "|"
					<< image [index]
				;
			}
			
			cout << "] ";
		}
		cout << "\n";
	}
}


int main ()
{
	
	
	// 1)
	
	int
		height = 25,
		width = 25,
		nbChannels = 1,
		index,
		color
	;
	vector <int> image (height * width * nbChannels);

	for (int line = 0; line < height; line ++)
	{
		for (int column = 0; column < width; column ++)
		{
			color = 255 - column * 255 / (width - 1);
			
			for (int channel = 0; channel < nbChannels; channel ++)
			{
				index = (line * width + column) * nbChannels + channel;
				modifier (image, index, color);
			}
		}
	}
	
	peindre (image, height, width);
	// cv:: imshow ("Window Name", image);
	
	
	// 2)
	
	height = 25;
	width = 25;
	nbChannels = 1;
	image.resize (height * width * nbChannels);
	
	for (int line = 0; line < height; line ++)
	{
		for (int column = 0; column < width; column ++)
		{
			color =
    			pow ((
    				pow (line * 510 / (height - 1) - 255, 2) +
    				pow (column * 510 / (width - 1) - 255, 2)
    			) / 2, 0.5)
			;
			
			for (int channel = 0; channel < nbChannels; channel ++)
			{
				index = (line * width + column) * nbChannels + channel;
				modifier (image, index, color);
			}
		}
	}
	
	peindre (image, height, width);
	// cv:: imshow ("Window Name", image);
	
	
	// 3)
	
	height = 25;
	width = 25;
	nbChannels = 3;
	image.resize (height * width * nbChannels);
	
	for (int line = 0; line < height; line ++)
	{
		for (int column = 0; column < width; column ++)
		{
			for (int channel = 0; channel < nbChannels; channel ++)
			{
				switch (channel)
				{
					
					// Rouge
					case 0:
						color = 255 - line * 255 / (height - 1);
						break;
					
					// Vert
					case 1:
						color = 255 - column * 255 / (width - 1);
						break;
					
					// Bleu
					case 2:
						color =
							pow ((
								pow (line * 510 / (height - 1) - 255, 2) +
								pow (column * 510 / (width - 1) - 255, 2)
							) / 2, 0.5)
						;
						break;
							
					// Chelou
					default:
						cout << "Chelou bro\n";
						color = 255;
						break;
						
				}
				
				index = (line * width + column) * nbChannels + channel;
				modifier (image, index, color);
			}
		}
	}
	
	peindre (image, height, width);
	// cv:: imshow ("Window Name", image);
	
	
	// 4)
	
	height = 25;
	width = 50;
	nbChannels = 3;
	image.resize (height * width * nbChannels);
	
	for (int line = 0; line < height; line ++)
	{
		for (int column = 0; column < width; column ++)
		{
			for (int channel = 0; channel < nbChannels; channel ++)
			{
				switch (channel)
				{
					
					// Rouge
					case 0:
						color = 255 - line * 255 / (height - 1);
						break;
					
					// Vert
					case 1:
						color = 255 - column * 255 / (width - 1);
						break;
					
					// Bleu
					case 2:
						color =
							pow ((
								pow (line * 510 / (height - 1) - 255, 2) +
								pow (column * 510 / (width - 1) - 255, 2)
							) / 2, 0.5)
						;
						break;
							
					// Chelou
					default:
						cout << "Chelou bro\n";
						color = 255;
						break;
						
				}
				
				index = (line * width + column) * nbChannels + channel;
				modifier (image, index, color);
			}
		}
	}
	
	peindre (image, height, width);
	// cv:: imshow ("Window Name", image);
	
	
	return 0;
	
}

