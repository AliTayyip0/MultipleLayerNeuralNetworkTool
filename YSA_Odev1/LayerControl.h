#pragma once

#include "Layer.h"


ref class LayerControl
{
public:
	LayerControl(int arakatmannoronsayisi, int cikabilecektursayisi);
	void KatmanOlustur(int NoronSayisi , int girdisayisi);

	bool IleriGit(float* girdi, float* beklenen);
	void GeriGit(float* hataMatrisi);
	void AgirlikKaydet();


	int TestEt(float* girdi);
	int stepsayisi = 0;
	void SetMoment(float deger);
private:
	List<Layer^>^ Katmanlar = gcnew List<Layer^>();
	float TanjanthFonksiyonu(float deger);



};

