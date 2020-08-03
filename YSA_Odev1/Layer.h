#pragma once
#include "Neuron.h"



using namespace System::Collections::Generic; 
using namespace std; 



ref class Layer
{


public:

	Layer(int NoronSayisi,  int GirdiSayisi);


	void SurekliEgitimDelta(float* girdiler);

	void SetMoment(float deger);


	float** GetAgirlikDondur();

	int GIRDISAYISI = 3;


	float* OutputMatrisiAFli;
	
	float* OutputMatrisiNormal;



	int stepsayisi = 0;
	int agirlikdegisimsayisi = 0;






	void NoronlarinAgirliklariniDegis(float* HataDegerleri);
	float* SonrakiKatmanaGonderilecekHataDegerleri(float* HataDegerleri);
	




private:
	int noronSayisi = 0;
	

	float* donecek;

	List<Neuron^>^ Noronlar = gcnew List<Neuron^>();
	
	//float* beklenenDegerlerMatrisi;
	float** agirlikMatrisleri;

};

