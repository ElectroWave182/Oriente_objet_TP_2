# include <iostream>
# define STB_IMAGE_IMPLEMENTATION
# define STB_IMAGE_WRITE_IMPLEMENTATION
# include "stb_image.h"
# include "stb_image_write.h"

using namespace std;


int main ()
{
    
	int width, height, channels;
	unsigned char *data = stbi_load ("lena.png", &width, &height, &channels, 0);
	
	
	// 1)
	
	cout << "Largeur : " << width << '\n';
	cout << "Hauteur : " << height << '\n';
	cout << "Nombre de canaux : " << channels << '\n';
	
	
	// 2)
	
	stbi_write_png ("copie", width, height, channels, *data, 0);
	
	
	// 3)
	
	int numCanal;
	for (int ligne = 0; ligne < height; ligne ++)
	{
		for (int colonne = 0; colonne < width; colonne ++)
		{
			for (int canal = 0; canal < channels; canal ++)
			{
				numCanal = (ligne * width + colonne) * channels + canal;
				data[numCanal] =
			}
		}
	}
	
	
	return 0;
	
}
