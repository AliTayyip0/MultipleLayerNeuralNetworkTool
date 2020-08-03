#pragma once
using namespace System::Drawing;

ref class Ornekler
{


public:
	Ornekler(int x, int y, float lbeklenen[]);

	int x;
	int y;
	float* beklenen;
	Color renk;

	void SetColor(Color lrenk);
};

