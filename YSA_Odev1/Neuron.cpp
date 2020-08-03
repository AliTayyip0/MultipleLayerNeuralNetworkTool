#include "Neuron.h"
#include <math.h>
#include <ctime>
#include <stdio.h>
#include <cstdlib>






Neuron::Neuron(int girdisayisi)
{
	moment = 0.0f;
	GIRDISAYISI = girdisayisi;
	agirlik = new float[GIRDISAYISI];
	bironcekiagirlikdegisimi = new float[GIRDISAYISI];
	girdi = new float[GIRDISAYISI];


	for (int i = 0; i < GIRDISAYISI; i++)
	{
		bironcekiagirlikdegisimi[i] = 0.0f;
		agirlik[i] = (float)(0.1f*i);
		girdi[i] = 0;
	}
	HATADEGERI = 0;
	//agirlik[GIRDISAYISI] = new float();
	/*agirlik[0] = 1.0f;
	agirlik[1] = 0.0f;
	agirlik[2] = -1.0f;*/
	// oto aðýrlýk atamasý yapýlacak
}


Neuron::Neuron(float agirlik1, float agirlik2, float agirlik3, int girdisayisi)
{
	moment = 0.0f;
	GIRDISAYISI = girdisayisi;
	agirlik = new float[GIRDISAYISI];
	girdi = new float[GIRDISAYISI];

	srand(time(0));

	for (int i = 0; i < GIRDISAYISI; i++)
	{
		agirlik[i] = ((rand() & 89 )+10)/100;
		girdi[i] = i;

	}

	/*agirlik[0] = agirlik1;
	agirlik[1] = agirlik2;
	agirlik[2] = agirlik3;*/

	HATADEGERI = 0;
}



 // Girdi matrisinin oluþturulmasý

//float agirlik[GIRDISAYISI] = {0.5f,0.4f,0.9f};  // Aðýrlýk matrisinin oluþturulmasý ve ilk aðýrlýk atamasý

float beklenendeger = 0; // iþlem yapýlan örnek için beklenen deger

float ogrenmekatsayisi = 0.3f; // Nöronun öðrenme katsayýsý






#pragma region Delta





void Neuron::DeltaAgirliklariyenidenata(float gelen)
{
	/*float dene1 = agirlik[0];
	float dene2 = agirlik[1];
	float dene3 = agirlik[2];*/
	for (int i = 0; i < GIRDISAYISI; i++)
	{

		agirlik[i] = agirlik[i] + (gelen*girdi[i]) + bironcekiagirlikdegisimi[i] * moment;
		bironcekiagirlikdegisimi[i] = (gelen*girdi[i]);

	}
	/*float dene4 = agirlik[0];
	float dene5 = agirlik[1];
	float dene6 = agirlik[2];*/
}



void Neuron::DeltaEgitim(float girdiler[])
{
	//ogrenmekatsayisi = 0.6f;
	for (int i = 0; i < GIRDISAYISI; i++)
	{
			girdi[i] = girdiler[i];
	}

	float cikandeger = Toplam(girdi, agirlik);

	OutPutNormal = cikandeger;
	OutPutSigmoidli = TanjanthFonksiyonu(cikandeger);
	OutPutSigmoidTurevli = TanjanthFonksiyonuTersi(OutPutSigmoidli);
}




void Neuron::AgirliklariDegis(float hatadegeri)
{
	DeltaAgirliklariyenidenata(ogrenmekatsayisi * (OutPutSigmoidTurevli * hatadegeri) );
}



#pragma endregion









#pragma region ORTAK


float Neuron::Toplam(float girdiler[], float agirliklar[])
{
	float toplam = 0;
	for (int i = 0; i < GIRDISAYISI; i++)
	{
		toplam += girdiler[i] * agirliklar[i];
	}
	return toplam;
}



float* Neuron::GetAgirlikDondur()
{
	return this->agirlik;
}


void Neuron::SetMoment(float deger)
{
	moment = deger;
}


#pragma endregion







#pragma region Akitivasyon Fonksiyonlarý

int Neuron::SignFonk(int deger)
{
	if (deger < 0) return -1;
	else return 1;
}

int Relu(int deger)
{
	if (deger < 0) return 0;
	else return deger;
}

float Neuron::TanjanthFonksiyonu(float deger)
{
	float girecek = deger * -1;

	float sayi = expf(girecek);
	sayi = sayi + 1;
	sayi = 2 / sayi;
	sayi = sayi - 1;
	return sayi;
}

float Neuron::TanjanthFonksiyonuTersi(float deger)
{
	/*deger = deger ;*/
	deger = (1 - powf((deger), 2));
	deger = deger / 2;
	return deger;
}

#pragma endregion


