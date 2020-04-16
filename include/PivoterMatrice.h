/*
 * Titre : PivoterMatrice.h - Travail Pratique #4 - Programmation Orient�e Objet
 * Date : 27 F�vrier 2020
 * Auteur : Nabil Dabouz
 */

#ifndef PIVOTER_MATRICE_H
#define PIVOTER_MATRICE_H

#include "def.h"
#include <cmath>

template <class M> class PivoterMatrice {
public:
  // Constructeurs
  PivoterMatrice();
  PivoterMatrice(M *matrice);
  // Destructeur
  ~PivoterMatrice() = default;
  void pivoterMatrice(Direction direction);

private:
  Coordonnees changerCoordonneesCentreMatrice(Coordonnees coords) const;
  Coordonnees recupererCoordonnees(Coordonnees coords) const;
  M *matrice_;
};

/**
 * @brief constructeur par défaut de la classe
 */
template <class M> inline PivoterMatrice<M>::PivoterMatrice()
	:matrice_()
{
  // TO DO
	
}
/**
 * @brief constructeur par paramètre de la classe
 */
template <class M>
inline PivoterMatrice<M>::PivoterMatrice(M *matrice) : matrice_(matrice) {}
/**
 * @brief trouver les coordonnées du point par rapport au centre de la matrice
 * @param coords les coordonnées du point originales
 */
template <class M>
inline Coordonnees
PivoterMatrice<M>::changerCoordonneesCentreMatrice(Coordonnees coords) const
{
  // TO DO
	size_t taille = matrice_->getHeight();
	int amplitude = (taille) / 2;
	coords.x = coords.x - amplitude;
	coords.y = coords.y - amplitude;
  return {coords.x,coords.y};
}
/**
 * @brief revenir au système précédent, trouver les coordonnées du point par
 * rapport au premier élément de la matrice
 * @param coords les coordonnées du point originales
 */
template <class M>
inline Coordonnees
PivoterMatrice<M>::recupererCoordonnees(Coordonnees coords) const
{
  // TO DO
	int amplitude = (int)(matrice_->getHeight()) / 2;
	coords.x = coords.x + amplitude;
	coords.y = coords.y + amplitude;
  return {coords.x, coords.y};
}

template <class M>
void PivoterMatrice<M>::pivoterMatrice(Direction direction)
{
	std::unique_ptr<M> matriceBis = matrice_->clone();
	Coordonnees coords;
	for (int i = 0; i < matrice_->getHeight(); i++) // i est la hauteur de la matrice
	{
		for (int j = 0;  j < matrice_->getWidth(); ++j) // j est la largeur de la matrice
		{
			//coords.x = j;	//largeur
			//coords.y = i;	//hauteur
			Coordonnees coordsBis = changerCoordonneesCentreMatrice({ i,j }); //coordBis.x est ma largeur, coordBis.y est ma hauteur
			if (direction == Direction::Left) // Rotation de 90 degrees
			{
				coords.x = coordsBis.x * 0/*cos(1.57079632 ou pi/2)*/ - coordsBis.y * 1/*sin(1.57079632 ou pi/2)*/;		//Nouvelle hauteur
				coords.y = coordsBis.x * 1/*sin(1.57079632 ou pi/2)*/ + coordsBis.y * 0/*cos(1.57079632 ou pi/2)*/;		//Nouvelle largeur
			}
			if (direction == Direction::Right) // Rotation de -90 degrees
			{
				coords.x = coordsBis.x * 0/*cos(-1.57079632 ou -pi/2)*/ - coordsBis.y * (-1)/*sin(-1.57079632 ou -pi/2)*/;		//Nouvelle hauteur
				coords.y = coordsBis.x * (-1)/*sin(-1.57079632 ou -pi/2)*/ + coordsBis.y * 0/*cos(-1.57079632 ou -pi/2)*/;		//Nouvelle largeur
			}
			coords = recupererCoordonnees({coords.x, coords.y}); //Conversion dans le systeme initial de coordonnees		//Correspond aux coordonnees de l'element dans la nouvelle matrice
			matrice_->ajouterElement(matriceBis->operator()(coords.y, coords.x), j, i);

		}
	}
}
#endif
