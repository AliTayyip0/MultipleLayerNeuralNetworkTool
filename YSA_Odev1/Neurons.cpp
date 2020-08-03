#include "Neurons.h"

#define GIRDISAYISI 3


Neurons::Neurons()
{

}


float girdi[GIRDISAYISI];

float agirlik[GIRDISAYISI] = { 0.9f,0.0f,-0.5f };

float beklenendeger = 0;

float ogrenmekatsayisi = 0.2f;



#pragma region Perseptron






bool Neurons::PerseptronEgitim(float girdiler[], float lbeklenendeger)
{
	for (int i = 0; i < GIRDISAYISI; i++)
	{
		girdi[i] = girdiler[i];
	}
	beklenendeger = lbeklenendeger;

	float cikandeger = Toplam(girdi, agirlik);


	if (beklenendeger == SigmoidFonk(cikandeger))
	{
		return true;
	}
	else
	{
		float gonderilecek = ogrenmekatsayisi * (beklenendeger - SigmoidFonk(cikandeger));
		PerseptronAgirliklariyenidenata(gonderilecek);
		return false;// aðýrlýklar deðiþtiyse yani sistem hatalýysa false döndürüo
	}
}



void Neurons::PerseptronAgirliklariyenidenata(float gelen)
{
	for (int i = 0; i < GIRDISAYISI; i++)
	{
		agirlik[i] = agirlik[i] + (gelen*girdi[i]);
	}
}



#pragma endregion



