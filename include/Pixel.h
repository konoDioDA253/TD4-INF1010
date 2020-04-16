/*
 * Titre : Pixel.h - Travail Pratique #4 - Programmation Orient�e Objet
 * Date : 27 F�vrier 2020
 * Auteur : Nabil Dabouz
 */

#ifndef PIXEL_H
#define PIXEL_H

#include <iomanip>
#include <iostream>
using namespace std;

class Pixel {
public:
  // Constructeurs
  Pixel();
  Pixel(uint8_t rouge, uint8_t vert, uint8_t bleu);
  // Destructeur
  ~Pixel() = default;
  // Operateurs
  void operator=(const Pixel& pixel);
  /*{
	  rouge_ = pixel.rouge_;
	  vert_ = pixel.vert_;
	  bleu_ = pixel.bleu_;
  }*/
 
  // Setters
  void setRouge(int rouge);
  void setVert(int vert);
  void setBleu(int bleu);
  // Getters
  uint8_t getRouge() const;
  uint8_t getVert() const;
  uint8_t getBleu() const;

private:
  uint8_t rouge_;
  uint8_t vert_;
  uint8_t bleu_;
};

std::ostream &operator<<(std::ostream &os, Pixel pixel);
std::istream &operator>>(std::istream &is, Pixel &pixel);

//std::ostream& operator<<(std::ostream& os, Pixel pixel)
//{
//	os << setbase(16);
//	os << '#' << setfill('0') << setw(2) << uppercase << unsigned(pixel.getRouge()) << " " << unsigned(pixel.getVert()) << " " << unsigned(pixel.getBleu());
//	return os;
//}

//std::istream& operator>>(std::istream& is, Pixel& pixel)
//{
//	/*int rouge;
//	int vert;
//	int bleu;*/
//	//is >> pixel.setRouge(pixel.getRouge()) >> pixel.setVert(pixel.getVert()) >> pixel.setBleu(pixel.getBleu());
//	int rouge, vert, bleu;
//	is >> rouge >> vert >> bleu;
//	pixel.setRouge(rouge);
//	pixel.setVert(vert);
//	pixel.setBleu(bleu);
//	return is;
//}


//void Pixel::setRouge(int rouge)
//{
//	bool surcharge = (rouge >= 255 || rouge <= 0);
//	switch (surcharge) 
//	{
//		case 1:
//			bool over255 = (rouge >= 255);
//			switch (over255)
//			{
//				case 0:
//					rouge_ = 0;
//					break;
//				case 1:
//					rouge_ = 255;
//					break;
//			}
//			break;
//		default:
//			rouge_ = rouge;
//	}
//}

//void Pixel::setVert(int vert)
//{
//	bool surcharge = (vert >= 255 || vert <= 0);
//	switch (surcharge)
//	{
//	case 1:
//		bool over255 = (vert >= 255);
//		switch (over255)
//		{
//		case 0:
//			vert_ = 0;
//			break;
//		case 1:
//			vert_ = 255;
//			break;
//		}
//		break;
//	default:
//		vert_ = vert;
//	}
//}

//void Pixel::setBleu(int bleu)
//{
//	bool surcharge = (bleu >= 255 || bleu <= 0);
//	switch (surcharge)
//	{
//	case 1:
//		bool over255 = (bleu >= 255);
//		switch (over255)
//		{
//		case 0:
//			bleu_ = 0;
//			break;
//		case 1:
//			bleu_ = 255;
//			break;
//		}
//		break;
//	default:
//		bleu_ = bleu;
//	}
//}
#endif