#pragma once
ref class Neurons
{

public:
	Neurons();

#pragma region Perseptron

	bool PerseptronEgitim(float girdiler[], float lbeklenendeger);

#pragma endregion

	





#pragma region Public_Global
	
	
	float* AgirlikDondur();



#pragma endregion

	

private:

#pragma region Perseptron

	void PerseptronAgirliklariyenidenata(float gelen);

#pragma endregion

	

#pragma region Private_Global


	float Toplam(float girdiler[], float agirliklar[]);


#pragma endregion

	

#pragma region Aktivation_Function


	int SigmoidFonk(int deger);
	int ReluFonk(int deger);

#pragma endregion

	
};

