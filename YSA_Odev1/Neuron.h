#pragma once




ref class Neuron
{


public:
	Neuron(int girdisayisi);
	Neuron(float agirlik1, float agirlik2, float agirlik3, int girdisayisi);

	
	void DeltaEgitim(float girdiler[]);
	float* GetAgirlikDondur();

	void SetMoment(float deger);



	float OutPutNormal=0;
	float OutPutSigmoidTurevli=0;
	float OutPutSigmoidli=0;

	float* agirlik;
	float* bironcekiagirlikdegisimi;

	float moment;

	float Epsilon = 0.1f; // Delta
	int GIRDISAYISI = 3;
	float* girdi;
	






	void AgirliklariDegis(float hatadegeri);





private:
	void DeltaAgirliklariyenidenata(float gelen); // Delta
	float HATADEGERI; // Delta


	float Toplam(float girdiler[], float agirliklar[]); // Global












	// Aktivasyon fonksiyonlarý

	int SignFonk(int deger);
	float TanjanthFonksiyonu(float deger);
	float TanjanthFonksiyonuTersi(float deger);
};

