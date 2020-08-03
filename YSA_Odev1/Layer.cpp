#include "Layer.h"
#include <memory.h>
#include <iostream>
#include <fstream>

using namespace std;





Layer::Layer(int NoronSayisi,int GirdiSayisi)
{
	noronSayisi = NoronSayisi;
	GIRDISAYISI = GirdiSayisi;

	
#pragma region NORONLARIN OLU�TURULMASI


	//beklenenDegerlerMatrisi = new float[NoronSayisi];
	OutputMatrisiAFli = new float[NoronSayisi];
	OutputMatrisiNormal = new float[NoronSayisi];
	donecek = new float[GIRDISAYISI];
	for (int i = 0; i < NoronSayisi; i++)
	{
		Noronlar->Add(gcnew Neuron(/*(0.1f)*(i+1),0.4f,0.5f,*/GirdiSayisi)); //TODO: bura randomla�a bilir
		OutputMatrisiAFli[i] = 0.0f;
		OutputMatrisiNormal[i] = 0.0f;
	}

#pragma endregion


#pragma region A�IRLIK MATR�S�N�N D�NAM�K ATAMASI VE DE�ERLER�N�N ALINMASI

	agirlikMatrisleri = new float*[NoronSayisi];   // A�IRLIK MATR�S�N�N D�NAM�K ATAMASI

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
	myfile.open("Katman i�inde ��kt� matrisi.txt", std::ios_base::app);*/


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
	myfile << "Tur: " << cycle1 << "  Noron:0" << "    ��kt�:" << OutputMatrisiAFli[0] << "\n";
	myfile << "Tur: " << cycle1 << "  Noron:1" << "    ��kt�:" << OutputMatrisiAFli[1] << "\n";
	myfile << "Tur: " << cycle1 << "  Noron:2" << "    ��kt�:" << OutputMatrisiAFli[2] << "\n";
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

	// E�ER SIKINTI OLURSA  NoronlarinAgirliklariniDegis bunun i�inde yazanlar� buraya koy tekrar dene sistemi

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










