#include "LayerControl.h"
#include "Layer.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>

int sonkatmannoronsayisi = 0;



LayerControl::LayerControl(int arakatmannoronsayisi,int cikabilecektursayisi)
{
		sonkatmannoronsayisi = cikabilecektursayisi;

		 KatmanOlustur(arakatmannoronsayisi,3);
		 KatmanOlustur(cikabilecektursayisi,arakatmannoronsayisi);
}


void LayerControl::KatmanOlustur(int NoronSayisi, int girdisayisi)
{
	Layer^ eklenecekkatman = gcnew Layer(NoronSayisi,girdisayisi);
	Katmanlar->Add(eklenecekkatman);
}



int cycle = 0;

float* HataMatrisi = new float[sonkatmannoronsayisi];



bool LayerControl::IleriGit(float* girdi,float* beklenen)
{
	cycle++;
	bool donecek = false;
	float* outputgirdi;
	/*ofstream myfile;
	myfile.open("ara katman noron ciktilar.txt", std::ios_base::app);
	ofstream myfile2;
	myfile2.open("Çýktý katmaný noron ciktilar.txt", std::ios_base::app);*/
	for (int i = 0; i < Katmanlar->Count; i++)
	{
		if (i == 0)
		{
			Katmanlar[i]->SurekliEgitimDelta(girdi);
			outputgirdi = Katmanlar[i]->OutputMatrisiAFli;
			/*myfile << "Tur: "<<cycle << "  Noron:0"<< "    Çýktý:"<< Katmanlar[i]->OutputMatrisiAFli[0]<<"\n";
			myfile << "Tur: " << cycle << "  Noron:1" << "    Çýktý:" << Katmanlar[i]->OutputMatrisiAFli[1]<<"\n";
			myfile << "Tur: " << cycle << "  Noron:2" << "    Çýktý:" << Katmanlar[i]->OutputMatrisiAFli[2]<<"\n";
			myfile << "-------------------------\n";*/
		}
		else
		{
			Katmanlar[i]->SurekliEgitimDelta(outputgirdi);
			
			outputgirdi = Katmanlar[i]->OutputMatrisiAFli;
			/*myfile2 << "Tur: " << cycle << "  Noron:0" << "    Çýktý:" << outputgirdi[0] << "\n";
			myfile2 << "Tur: " << cycle << "  Noron:1" << "    Çýktý:" << outputgirdi[1] << "\n";
			myfile2 << "Tur: " << cycle << "  Noron:2" << "    Çýktý:" << outputgirdi[2] << "\n";
			myfile2 << "-------------------------\n";*/
		}
	}


	 
	


	//ofstream myfile3;
	//myfile3.open("son katman çýkýþý hata degerleri.txt", std::ios_base::app);
	float toplamhataE = 0;

	for (int i = 0; i < sonkatmannoronsayisi; i++)
	{
		float atanacak = TanjanthFonksiyonu(beklenen[i]) - outputgirdi[i];
		
		
		HataMatrisi[i] = atanacak;

		toplamhataE += powf(atanacak,2.0f);
		//if (fabs(HataMatrisi[i]) > 0.1f) donecek = true;
		
	}
	//myfile3 << "TOPLAM HATA DEÐERÝ       " << toplamhataE << "\n";
	if (toplamhataE > 0.1f) donecek = true;


	//if (donecek == false) return false;
	GeriGit(HataMatrisi);
	/*myfile.close();
	myfile2.close();*/
	//myfile3.close();
	return donecek;
}



void LayerControl::GeriGit(float* hataMatrisi)
{
	for (int i = Katmanlar->Count-1; -1 < i; i--)   
	{
		Katmanlar[i]->NoronlarinAgirliklariniDegis(hataMatrisi);
		hataMatrisi = Katmanlar[i]->SonrakiKatmanaGonderilecekHataDegerleri(hataMatrisi);
	}
	stepsayisi = Katmanlar[0]->stepsayisi;
	// burada agirliklari ekrana yazdýr kýsmý olmalý
}





float LayerControl::TanjanthFonksiyonu(float deger)
{
	float girecek = deger * -1;

	float sayi = expf(girecek);
	sayi = sayi + 1;
	sayi = 2 / sayi;
	sayi = sayi - 1;
	return sayi;
}





int LayerControl::TestEt(float* girdi)
{
	float* outputgirdi;
	

	for (int i = 0; i < Katmanlar->Count; i++)
	{
		if (i == 0)
		{
			Katmanlar[i]->SurekliEgitimDelta(girdi);
			outputgirdi = Katmanlar[i]->OutputMatrisiAFli;

		}
		else
		{
			Katmanlar[i]->SurekliEgitimDelta(outputgirdi);

			outputgirdi = Katmanlar[i]->OutputMatrisiAFli;

		}
	}

	int  enbuyuk = 0;
	int enbuyukindex = 0;

	for (int i = 0; i < sonkatmannoronsayisi; i++)
	{
		if (outputgirdi[i] > enbuyuk)
		{
			enbuyuk = outputgirdi[i];
			enbuyukindex = i;
		}
	}

	return enbuyukindex;
}





void LayerControl::SetMoment(float deger)
{
	
	for (int i = 0; i < Katmanlar->Count; i++)
	{
		Katmanlar[i]->SetMoment(deger);
	}
}







void LayerControl::AgirlikKaydet()
{
	ofstream myfile;
	myfile.open("agirlik.txt", std::ios_base::app);
	myfile << Katmanlar->Count <<"\n";
	for (int i = 0; i < Katmanlar->Count; i++)
	{
		myfile << i<<"\n";
		float** agirliklar = Katmanlar[i]->GetAgirlikDondur();
		for (int j = 0; j <4 ; j++)
		{

		}
	}
}




















//int LayerControl::TestEt(float* girdi)
//{/*
//	ofstream myfile;
//	myfile.open("Test Arakatman çýktýsý.txt", std::ios_base::app);
//	ofstream myfile2;
//	myfile2.open("Test çýkýþ katman çýktýsý.txt", std::ios_base::app);*/
//	float* outputgirdi;
//
//	for (int i = 0; i < Katmanlar->Count; i++)
//	{
//		if (i == 0)
//		{
//			Katmanlar[i]->SurekliEgitimDelta(girdi);
//			outputgirdi = Katmanlar[i]->OutputMatrisiAFli;
//
//			/*myfile << "Tur: " << cycle8 << "  Noron:0" << "    Çýktý:" << outputgirdi[0] << "\n";
//			myfile << "Tur: " << cycle8 << "  Noron:1" << "    Çýktý:" << outputgirdi[1] << "\n";
//			myfile << "Tur: " << cycle8 << "  Noron:2" << "    Çýktý:" << outputgirdi[2] << "\n";
//			myfile << "-------------------------\n";*/
//		}
//		else
//		{
//			Katmanlar[i]->SurekliEgitimDelta(outputgirdi);
//
//			outputgirdi = Katmanlar[i]->OutputMatrisiNormal;
//
//			/*myfile2 << "Tur: " << cycle8 << "  Noron:0" << "    Çýktý:" << outputgirdi[0] << "\n";
//			myfile2 << "Tur: " << cycle8 << "  Noron:1" << "    Çýktý:" << outputgirdi[1] << "\n";
//			myfile2 << "Tur: " << cycle8 << "  Noron:2" << "    Çýktý:" << outputgirdi[2] << "\n";
//			myfile2 << "-------------------------\n";*/
//		}
//	}
//
//	int  enbuyuk = 0;
//	int enbuyukindex = 0;
//	for (int i = 0; i < sonkatmannoronsayisi; i++)
//	{
//		if (outputgirdi[i] > enbuyuk)
//		{
//			enbuyuk = outputgirdi[i];
//			enbuyukindex = i;
//		}
//	}
//
//	/*
//		myfile.close();
//		myfile2.close();*/
//	return enbuyukindex;
//}