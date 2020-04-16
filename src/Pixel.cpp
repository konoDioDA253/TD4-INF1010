#include "Pixel.h"

/**
 * @brief constructeur par défaut de la classe
 */
Pixel::Pixel() : rouge_(0), vert_(0), bleu_(0) {}
/**
 * @brief constructeur par paramètres de la classe
 * @param rouge, l'élément R du pixel, entre 0 -> 255
 * @param vert, l'élément G du pixel, entre 0 -> 255
 * @param bleu, l'élément B du pixel, entre 0 -> 255
 */
Pixel::Pixel(uint8_t rouge, uint8_t vert, uint8_t bleu)
    : rouge_(rouge), vert_(vert), bleu_(bleu) {}

void Pixel::operator=(const Pixel &pixel) 
{
	// TO DO
	rouge_ = pixel.rouge_;
	vert_ = pixel.vert_;
	bleu_ = pixel.bleu_;
}


void Pixel::setRouge(int rouge)
{
	// TO DO
	bool surcharge = (rouge >= 255 || rouge <= 0);
	bool over255;
	switch (surcharge) 
	{
		case 1:
			over255 = (rouge >= 255);
			switch (over255)
			{
				case 0:
					rouge_ = 0;
					break;
				case 1:
					rouge_ = 255;
					break;
			}
			break;
		default:
			rouge_ = rouge;
	}
}

void Pixel::setVert(int vert)
{
	// TO DO
	bool surcharge = (vert >= 255 || vert <= 0);
	bool over255;
	switch (surcharge)
	{
	case 1:
		over255 = (vert >= 255);
		switch (over255)
		{
		case 0:
			vert_ = 0;
			break;
		case 1:
			vert_ = 255;
			break;
		}
		break;
	default:
		vert_ = vert;
	}
}

void Pixel::setBleu(int bleu)
{
	bool surcharge = (bleu >= 255 || bleu <= 0);
	bool over255;
	switch (surcharge)
	{
	case 1:
		over255 = (bleu >= 255);
		switch (over255)
		{
		case 0:
			bleu_ = 0;
			break;
		case 1:
			bleu_ = 255;
			break;
		}
		break;
	default:
		bleu_ = bleu;
	}
}
/**
 * @brief retourn l'attribut rouge_ du pixel
 * @return rouge_ du type uint8_t
 */
uint8_t Pixel::getRouge() const { return rouge_; }
/**
 * @brief retourn l'attribut vert_ du pixel
 * @return vert_ du type uint8_t
 */
uint8_t Pixel::getVert() const { return vert_; }
/**
 * @brief retourn l'attribut bleu_ du pixel
 * @return bleu_ du type uint8_t
 */
uint8_t Pixel::getBleu() const { return bleu_; }

std::ostream& operator<<(std::ostream& os, Pixel pixel)
{
  // TO DO
	os << setbase(16);
	os << '#' << setfill('0') << setw(2) << uppercase << unsigned(pixel.getRouge()) << " " << unsigned(pixel.getVert()) << " " << unsigned(pixel.getBleu());
	return os;
}

std::istream& operator>>(std::istream& is, Pixel& pixel)
{
	// TO DO

	/*int rouge;
	int vert;
	int bleu;*/
	//is >> pixel.setRouge(pixel.getRouge()) >> pixel.setVert(pixel.getVert()) >> pixel.setBleu(pixel.getBleu());
	int rouge, vert, bleu;
	is >> rouge >> vert >> bleu;
	pixel.setRouge(rouge);
	pixel.setVert(vert);
	pixel.setBleu(bleu);
	return is;
}