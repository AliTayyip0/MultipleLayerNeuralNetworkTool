#include "Ornekler.h"


using namespace System::Drawing;


Ornekler::Ornekler(int x, int y, float lbeklenen[])
{
	this->x = x;
	this->y = y;
	this->beklenen = lbeklenen;
	
}


void Ornekler::SetColor(Color lrenk)
{
	this->renk = lrenk;
}