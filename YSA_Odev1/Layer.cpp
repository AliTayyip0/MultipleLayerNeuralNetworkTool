#include "Layer.h"
#include <memory.h>
#include <iostream>
#include <fstream>

using namespace std;





Layer::Layer(int NoronSayisi,int GirdiSayisi)
{
	noronSayisi = NoronSayisi;
	GIRDISAYISI = GirdiSayisi;

	
#pragma region NORONLARIN OLUÞTURULMASI


	//beklenenDegerlerMatrisi = new float[NoronSayisi];
	OutputMatrisiAFli = new float[NoronSayisi];
	OutputMatrisiNormal = new float[NoronSayisi];
	donecek = new float[GIRDISAYISI];
	for (int i = 0; i < NoronSayisi; i++)
	{
		Noronlar->Add(gcnew Neuron(/*(0.1f)*(i+1),0.4f,0.5f,*/GirdiSayisi)); //TODO: bura randomlaþa bilir
		OutputMatrisiAFli[i] = 0.0f;
		OutputMatrisiNormal[i] = 0.0f;
	}

#pragma endregion


#pragma region AÐIRLIK MATRÝSÝNÝN DÝNAMÝK ATAMASI VE DEÐERLERÝNÝN ALINMASI

	agirlikMatrisleri = new float*[NoronSayisi];   // AÐIRLIK MATRÝSÝNÝN DÝNAMÝK ATAMASI

	for (int i = 0; i < NoronSayisi; i++)
	{
		agirlikMatrisleri[i] = new float[3];
		memset(agirlikMatrisleri[i], false, GIRDISAYISI * sizeof(float));


		agirlikMatrisleri[i] = Noronlar[i]->GetAgirlikDondur();

		//for (int j = 0; j < GIRDISAYISI; j++)
		//{
		//	agirlikMatrisleri[i][j] = Noronlar[i]->GetAgirlikDondur()[j];
		//}
	}


#pragma endregion


	
}


int cycle1 = 0;

void Layer::SurekliEgitimDelta(float* girdiler)
{
	cycle1++;
	/*ofstream myfile;
	myfile.clear();
	myfile.open("Katman içinde çýktý matrisi.txt", std::ios_base::app);*/


	for (int i = 0; i < noronSayisi; i++)
	{
		stepsayisi++;
		Noronlar[i]->DeltaEgitim(girdiler);
	}

	for (int i = 0; i < noronSayisi; i++)
	{
		OutputMatrisiAFli[i] = Noronlar[i]->OutPutSigmoidli;
		OutputMatrisiNormal[i] = Noronlar[i]->OutPutNormal;
	}
/*
	myfile << "Tur: " << cycle1 << "  Noron:0" << "    Çýktý:" << OutputMatrisiAFli[0] << "\n";
	myfile << "Tur: " << cycle1 << "  Noron:1" << "    Çýktý:" << OutputMatrisiAFli[1] << "\n";
	myfile << "Tur: " << cycle1 << "  Noron:2" << "    Çýktý:" << OutputMatrisiAFli[2] << "\n";
	myfile << "-------------------------\n";

	myfile.close();*/
}








void Layer::NoronlarinAgirliklariniDegis(float* HataDegerleri)
{
	for (int i = 0; i < noronSayisi; i++)
	{
		Noronlar[i]->AgirliklariDegis(HataDegerleri[i]);
		
		
		agirlikMatrisleri[i] = Noronlar[i]->GetAgirlikDondur();
	}
}


float* Layer::SonrakiKatmanaGonderilecekHataDegerleri(float* HataDegerleri)
{
	//float* donecek = new float[GIRDISAYISI];
	
	
	for (int i = 0; i < GIRDISAYISI; i++)
	{
		donecek[i] = 0;
	}

 	for (int i = 0; i < noronSayisi; i++)
	{
		for (int j = 0; j < GIRDISAYISI; j++)
		{
			float atanacak = HataDegerleri[i] * Noronlar[i]->OutPutSigmoidTurevli * agirlikMatrisleri[i][j];
			donecek[j] += atanacak;
		}
	}

	// EÐER SIKINTI OLURSA  NoronlarinAgirliklariniDegis bunun içinde yazanlarý buraya koy tekrar dene sistemi

	return donecek;
}






float** Layer::GetAgirlikDondur()
{
	return agirlikMatrisleri;
}





void Layer::SetMoment(float deger)
{
	for (int i = 0; i < noronSayisi; i++)
	{
		Noronlar[i]->SetMoment(deger);
	}
}










