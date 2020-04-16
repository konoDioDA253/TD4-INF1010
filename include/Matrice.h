/*
 * Titre : Matrice.h - Travail Pratique #4 - Programmation Orient�e Objet
 * Date : 27 F�vrier 2020
 * Auteur : Nabil Dabouz
 */

#ifndef MATRICE_H
#define MATRICE_H

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include <string>

template <typename T> class Matrice {

public:
  Matrice();
  // Destructeur
  ~Matrice() = default;
  T operator()(const size_t &posY, const size_t &posX) const;
  // Lecture du fichier
  bool chargerDepuisFichier(const std::string &nomFichier);
  bool lireElement(const std::string &elementFichier, const size_t &posY,
                   const size_t &posX);
  // Remplir un matrice
  bool ajouterElement(T element, const size_t &posY, const size_t &posX);
  // Faire une copie
  std::unique_ptr<Matrice<T>> clone() const;
  // Setters
  void setHeight(size_t height);
  void setWidth(size_t width);
  // Getters
  size_t getHeight() const;
  size_t getWidth() const;

private:
  std::vector<std::vector<T>> elements_;
  size_t height_;
  size_t width_;
};

namespace {
static constexpr int CAPACITE_MATRICE = 100;
}

/**
 * @brief constructeur par défaut de la classe
 */
template <typename T> inline Matrice<T>::Matrice()
	:elements_((CAPACITE_MATRICE), std::vector<T>(CAPACITE_MATRICE))
	,height_(0)
	,width_(0)
{
  // TO DO
	//for (unsigned i = 0; i < CAPACITE_MATRICE; i++) //Pour chaque ligne de ma matrice
	//{
	//	for (unsigned j = 0; j < CAPACITE_MATRICE; j++) //Pour chaque colonne de ma matrice
	//	{
	//		elements_[i][j] = 0; //Initialisons à 0
	//	}
	//}
}
/**
 * @brief retourne le nombre de lignes de la matrice
 * @return l'attribut height_ de l'objet
 */
template <typename T> inline size_t Matrice<T>::getHeight() const {
  return height_;
}
/**
 * @brief retourne le nombre de colonnes de la matrice
 * @return l'attribut width_ de l'objet
 */
template <typename T> inline size_t Matrice<T>::getWidth() const {
  return width_;
}
template <typename T>
T Matrice<T>::operator()(const size_t& posY, const size_t& posX) const
{
	if (posY > height_ || posX > width_)
	{
		return T();
	}
	else 
	{
		return elements_[posY][posX];
	}
}
template <typename T>
bool Matrice<T>::ajouterElement(T element, const size_t& posY, const size_t& posX)
{
	if (posY > height_ || posX > width_)
	{
		return false;
	}
	elements_[posY][posX] = element;
	return true;
}

template <typename T>
bool Matrice<T>::lireElement(const std::string& elementFichier, const size_t& posY, const size_t& posX)
{
	T elementLu;
	std::istringstream stream(elementFichier);
	if (stream >> elementLu)
	{
		return ajouterElement(elementLu, posY, posX);	
	}
	return false;
}

template <typename T>
bool Matrice<T>::chargerDepuisFichier(const std::string& nomFichier)
{
	std::ifstream fichier(nomFichier);
	std::string stream;
	if (fichier)
	{
		
		size_t posX = 0;
		size_t posY = -1;
		
		while (getline(fichier, stream))
		{
			if (stream != "L")
			{
				if (lireElement(stream, posY, posX) == false) // Appel a lireElement
				{
					return false;
				}
				posX = posX + 1;				
				//width_++;
				setWidth(posX /*+ 1*/);
			}
			else
			{				
				//setHeight(posY + 1);
				height_++;
				/*if (posY != 0 && posX != 0)
				{
				}*/
				posY = posY + 1;
				setWidth(0);
				posX = 0;
			}
		}		
		return true;
	}
	std::cerr << "Le fichier " << nomFichier
		<< " n'existe pas. Assurez vous de le mettre au bon endroit.\n";
	return false;

	//std::ifstream fichier(nomFichier);
	//if (fichier) 
	//{
	//	std::string ligne;
	//	int posX = 0, posY = -1;

	//	while (getline(fichier, ligne)) 
	//	{

	//		if (ligne == "L")
	//		{
	//			height_++;
	//			posY++;
	//			width_ = 0;
	//			posX = 0;
	//		}
	//		else 
	//		{
	//			if (!lireElement(ligne, posY, posX))
	//				return false;
	//			posX++;
	//			width_++;
	//		}
	//	}
	//	return true;
	//}
	//std::cerr << "Le fichier " << nomFichier
	//	<< " n'existe pas. Assurez vous de le mettre au bon endroit.\n";
	//return false;
}

template <typename T>
void Matrice<T>::setHeight(size_t height)
{
	bool overCapaciteMatrice = (height >= CAPACITE_MATRICE);
	switch (overCapaciteMatrice)
	{
	case 0 :
		height_ = height;
		break;
	case 1 :
		height_ = CAPACITE_MATRICE;
		break;
	}
	
}

template <typename T>
void Matrice<T>::setWidth(size_t width)
{
	/*width_ = width;*/
	bool overCapaciteMatrice = (width >= CAPACITE_MATRICE);
	switch (overCapaciteMatrice)
	{
	case 0:
		width_ = width;
		break;
	case 1:
		width_ = CAPACITE_MATRICE;
		break;
	}
}

template <typename T>
std::unique_ptr<Matrice<T>> Matrice<T>::clone() const
{
	Matrice<T> matriceClone;
	matriceClone.setHeight(height_);
	matriceClone.setWidth(width_);
	for (unsigned i = 0; i < height_; i++)
	{
		for (unsigned j = 0; j < width_; j++)
		{
			matriceClone.elements_[i][j] = elements_[i][j];
		}
	}
	std::unique_ptr<Matrice<T>> ptrMatrice = std::make_unique<Matrice<T>>(matriceClone);
	return std::move(ptrMatrice);
}

#endif
