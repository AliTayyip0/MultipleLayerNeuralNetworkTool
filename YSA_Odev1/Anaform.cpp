#include "Anaform.h"
#include "Ornekler.h"
#include "Neuron.h"
#include "LayerControl.h"
#include <stdio.h>
#include <string>



#pragma region Kütüphane ve Tanýmlamalar





using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace YSAOdev1;
using namespace System::Collections::Generic;


#define GIRDISAYISI 3

#define BUYUKSAYILARIKUCULTME 300



[STAThread]


#pragma endregion



void main(/*std::array<String^>^ args*/)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	YSAOdev1::Anaform form;
	Application::Run(% form);

	
	
}



















void Anaform::OrnekleriEgitDelta()
{
	//LayerControl^ KatmanKontrol = gcnew LayerControl(4,cmbNoronSayisi->SelectedIndex+1);
	if(KatmanKontrol==nullptr)
		KatmanKontrol = gcnew LayerControl(cmbAraKatmanNoronSayisi->SelectedIndex+1, cmbSinifSayisi->SelectedIndex + 1);
	float girdi[GIRDISAYISI];
	bool TekrarEdilecekMi = false;
	int dogruorneksayisi = 0;
	
	do
	{

		dogruorneksayisi = 0;
		cyclesayisi++;
		TekrarEdilecekMi = false;


		

		for (int OrnekNumarasý = 0; OrnekNumarasý < ornekler->Count; OrnekNumarasý++)
		{
			girdi[0] = ornekler[OrnekNumarasý]->x / 300.0f;
			girdi[1] = ornekler[OrnekNumarasý]->y / 300.0f;
			girdi[2] = 1.0f;


			if (KatmanKontrol->IleriGit(girdi, ornekler[OrnekNumarasý]->beklenen))
			{
				//Hata Oluþtu Demek
				TekrarEdilecekMi = true;
			}
			else
			{
				dogruorneksayisi++;
				//int a = 5;
				// Hata Oluþmadý
			}

		}

		if (dogruorneksayisi / ornekler->Count > 0.7) 
			TekrarEdilecekMi = false;


		lblCycle->Text = "Cycle: " + cyclesayisi.ToString();
		lblStep->Text = "Step: " + KatmanKontrol->stepsayisi.ToString();
		lblCycle->Refresh();
		lblStep->Refresh();



	} while (TekrarEdilecekMi);



	EkraniBolgelereAyir();
	

	
	//#pragma region Aðýrlýklarýn ve sistemin yeniden çizimi

	//if (Katman1->stepsayisi % 1 == 0)
	//{
	//	this->asd = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	//	KordinatSisteminiCiz();
	//	TumOrnekleriCiz();
	//	AgirliklariCiz();
	//	/*for (int i = 0; i < katmandakiNoronSayisi; i++)
	//	{
	//		CizgiCiz(Katman1->GetAgirlikDondur()[i][0], Katman1->GetAgirlikDondur()[i][2] * 300.0f, Katman1->GetAgirlikDondur()[i][1], NumarayaGoreRenkDondurucu(i + 1));
	//	}*/
	//	pictureBox1->Refresh();
	//}

	//#pragma endregion

}






void Anaform::EkraniBolgelereAyir()
{
	
	Point nokta;

	for (int i = 0; i < pictureBox1->Width; i++)
	{
		for (int j = 0; j < pictureBox1->Height; j++)
		{
			asd->SetPixel(i, j, BackColor.Black);
		}
	}
	pictureBox1->Image = asd;
	pictureBox1->Refresh();

	for (int i = 0; i < pictureBox1->Width; i += 3)
	{
		for (int j = 0; j < pictureBox1->Height; j += 3)
		{
			float girdi1[GIRDISAYISI];
			nokta = NormalKordinattanÝstenilenKordinataCevirme(i, j);
			girdi1[0] = nokta.X / 300.0f;
			girdi1[1] = nokta.Y / 300.0f;
			girdi1[2] = 1.0f;
			int sayi = KatmanKontrol->TestEt(girdi1);
			asd->SetPixel(i, j, NumarayaGoreRenkDondurucu(sayi + 1));

		}



		pictureBox1->Image = asd;
		pictureBox1->Refresh();
	}

	KordinatSisteminiCiz();
	TumOrnekleriCiz();
	pictureBox1->Image = asd;
	pictureBox1->Refresh();
}










#pragma region Eventler




void Anaform::pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{


	//if (Katman1 == nullptr) return; // Katman oluþturulmadýysa örnekleme iþleminin yapýlmasýný önler



	if (this->asd == nullptr)
		this->asd = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);







	int NoktaX = e->Location.X;
	int NoktaY = e->Location.Y;


	Color renk;
	Ornekler^ yeniornek;
	Point^ donusturulmus = gcnew Point(NoktaX, NoktaY);




#pragma region NORON SAYISINA VE SEÇÝLÝ ÖRNEÐE BAÐLI OLARAK BEKLENEN DEÐER ATAMASINI GERÇEKLEÞTÝRÝYOR



	// BURADA ÝÞLEM NUMARALARININ 1 DEN BAÞLADIÐI VARSAYILIYOR
	float* beklenendegerlermatrisi;
	beklenendegerlermatrisi = new float[katmandakiNoronSayisi];
	for (int i = 0; i < katmandakiNoronSayisi; i++)
	{
		if (katmandakiNoronSayisi != 1)
		{
			// NORON SAYISINA VE SEÇÝLÝ ÖRNEÐE BAÐLI OLARAK BEKLENEN DEÐER ATAMASINI GERÇEKLEÞTÝRÝYOR
			if (i == islem_number - 1)
				beklenendegerlermatrisi[i] = +1.0f;
			else
				beklenendegerlermatrisi[i] = -1.0f;
		}
		else
		{
			// BU KISIM TEK NORONLU 2 ÖRNEKLÝ YAPILAR ÝÇÝN
			if(islem_number==1)beklenendegerlermatrisi[0] = +1.0f;
			else beklenendegerlermatrisi[0] = -1.0f;
		}
	}



#pragma endregion
	



#pragma region Örneðin türüne göre renginin ve seçili konumun atanmasý iþlemleri

	donusturulmus = NormalKordinattanÝstenilenKordinataCevirme(donusturulmus->X, donusturulmus->Y);
	renk = NumarayaGoreRenkDondurucu(islem_number);
	yeniornek = gcnew Ornekler(donusturulmus->X, donusturulmus->Y, beklenendegerlermatrisi);
	yeniornek->SetColor(renk);



#pragma endregion


	ArtiCiz(NoktaX,NoktaY,renk);  // Picture Box Üzerinde Örneðin Gösterilmesini Saðlýyor
	

	
	
	

	this->ornekler->Add(yeniornek); // Örneði Örnek Listesine Ekliyor
	

	pictureBox1->Image = this->asd;

	pictureBox1->Refresh();
	
}


void Anaform::Anaform_Load(System::Object^  sender, System::EventArgs^  e)
{
	
	KordinatSisteminiCiz();

	cmbSinifSayisi->SelectedIndex = 0;
	cmbAraKatmanNoronSayisi->SelectedIndex = 0;
}


void Anaform::pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	Point gecici = NormalKordinattanÝstenilenKordinataCevirme(e->Location.X,e->Location.Y);
	lblKonum->Text = gecici.ToString();
}


void Anaform::btnKatmanOlustur_Click(System::Object^  sender, System::EventArgs^  e)
{

	//if(cmbSinifSayisi->SelectedIndex!=0)
	//	ButtonOlusturucu(cmbSinifSayisi->SelectedIndex + 1);
	//else
	//	ButtonOlusturucu(2); // TEK NORON KULLANILDIÐINDA 2 ÖRNEK ALINABÝLMESÝ ÝÇÝN
	
	ButtonOlusturucu(cmbSinifSayisi->SelectedIndex + 1);


	if (KatmanKontrol==nullptr)
	{
		KatmanKontrol = gcnew LayerControl(cmbAraKatmanNoronSayisi->SelectedIndex + 1, cmbSinifSayisi->SelectedIndex + 1);
	}


	


	if(asd==nullptr)
		this->asd = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);

	for (int i = 0; i < pictureBox1->Width; i++)
	{
		for (int j = 0; j < pictureBox1->Height; j++)
		{
			asd->SetPixel(i,j,BackColor.Black);
		}
	}

	KordinatSisteminiCiz();

	pictureBox1->Refresh();
	
}


void Anaform::btnTiklamalar(System::Object^  sender, System::EventArgs^  e)
{
	Button^ btngonderen = (Button^)sender;
	islem_number = btngonderen->TabIndex;
	//std::string ss = btngonderen->Text;
	//islem_number = atoi(ss); // stoi(btngonderen->Text);
}


void Anaform::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (KatmanKontrol == nullptr && checkBox1->Checked==true)
	{
		checkBox1->Checked = false;
		return;
	}
	if (KatmanKontrol != nullptr)
	{


		if (checkBox1->Checked == true)
		{
			KatmanKontrol->SetMoment(0.3f);
		}
		else
		{
			KatmanKontrol->SetMoment(0.0f);
		}
	}
}



#pragma region Silme Ýþlemleri


void Anaform::btnTumOrnekSil_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->asd = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);

	for (int i = 0; i < ornekler->Count; i++)
	{
		ornekler->RemoveAt(0);
	}
	
	KordinatSisteminiCiz();
	AgirliklariCiz();
}


void Anaform::btnSonOrnekSil_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->asd = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);

	if (ornekler->Count == 0) return;
	ornekler->RemoveAt(ornekler->Count-1);

	KordinatSisteminiCiz();
	TumOrnekleriCiz();
	AgirliklariCiz();
}





#pragma endregion




#pragma endregion



void Anaform::ButtonOlusturucu(int adet)
{
	for (int i = 0; i < adet; i++)
	{
		Button^ yenibuton = gcnew Button();
		yenibuton->Text = (i + 1).ToString();
		yenibuton->TabIndex = i + 1;
		yenibuton->Location =  Point((10 * i) + 10 + (i * 20),6);
		yenibuton->Size = System::Drawing::Size(20,20);
		yenibuton->UseVisualStyleBackColor = true;
		yenibuton->Click += gcnew System::EventHandler(this, &Anaform::btnTiklamalar);
		//if (i == 0) yenibuton->Visible = false;
		pnlSiniflar->Controls->Add(yenibuton);
		pnlSiniflar->Refresh();
		
		
	}
}

















Color Anaform::NumarayaGoreRenkDondurucu(int numara)
{
	//if (numara == 1) return Color::Black; 
	//else if (numara == 2) return Color::Red;
	//else if (numara == 3) return Color::Green;
	//else if (numara == 4) return Color::DarkBlue;
	//else if (numara == 5) return Color::Chocolate;
	//else if (numara == 6) return Color::Black;
	//else return Color::Black;


	//if (numara == 1) return Color::FromArgb(200, 0, 0);
	//else if (numara == 6) return Color::FromArgb(200, 200, 0);
	//else if (numara == 7) return Color::FromArgb(0, 255, 0);
	//else if (numara == 9) return Color::FromArgb(0, 255, 255);
	//else if (numara == 2) return Color::FromArgb(0, 0, 255);
	//else if (numara == 6) return Color::FromArgb(255, 0, 255);
	//else if (numara == 3) return Color::FromArgb(255, 255, 255);
	//else if (numara == 5) return Color::FromArgb(64 ,224, 208);
	//else if (numara == 4) return Color::FromArgb(205 ,170, 125);
	//else if (numara == 10) return Color::FromArgb(238, 121, 66);
	//else return Color::White;
	//









	/*if (numara == 1) return Color::FromArgb(64 ,224 ,208);
	else if (numara == 2) return Color::FromArgb(74 ,128, 77);
	else if (numara == 3) return Color::FromArgb(139, 101, 139);
	else if (numara == 4) return Color::FromArgb(139 ,69, 19);
	else if (numara == 5) return Color::FromArgb(238 ,232, 170);
	else if (numara == 6) return Color::FromArgb(244, 164 ,96);
	else if (numara == 7) return Color::FromArgb(65, 105, 225);
	else if (numara == 8) return Color::FromArgb(46, 139, 87);
	else if (numara == 9) return Color::FromArgb(0 ,255, 255);
	else if (numara == 10) return Color::FromArgb(0, 255, 0);
	else if (numara == 11) return Color::FromArgb(255, 255, 0);
	else if (numara == 12) return Color::FromArgb(46, 139, 87);
	else if (numara == 13) return Color::FromArgb(46, 139, 87);
	else return Color::Black;*/



	if (numara == 1) return Color::FromArgb(252, 248, 10);
	else if (numara == 2) return Color::FromArgb(127, 255, 0);
	else if (numara == 3) return Color::FromArgb(0, 255, 255);
	else if (numara == 4) return Color::FromArgb(255, 0, 0);
	else if (numara == 5) return Color::FromArgb(255, 255, 255);

	else if (numara == 6) return Color::FromArgb(255, 127, 0);
	else if (numara == 7) return Color::FromArgb(97, 135, 90);
	else if (numara == 8) return Color::FromArgb(255, 0, 124);
	else if (numara == 9) return Color::FromArgb(170, 170, 255);
	else if (numara == 10) return Color::FromArgb(255, 124, 124);
	else return Color::White;


}






Color Anaform::NumarayaGoreKoyuRenkDondurucu(int numara)
{


	if (numara == 1) return Color::FromArgb(127, 127,0);
	else if (numara == 2) return Color::FromArgb(63, 127, 0);
	else if (numara == 3) return Color::FromArgb(0, 127, 127);
	else if (numara == 4) return Color::FromArgb(127 ,0, 0);
	else if (numara == 5) return Color::FromArgb(127 ,127, 127);

	else if (numara == 6) return Color::FromArgb(191, 95 ,0);
	else if (numara == 7) return Color::FromArgb(0, 132, 0);
	else if (numara == 8) return Color::FromArgb(46, 139, 87);
	else if (numara == 9) return Color::FromArgb(255, 255, 0);
	else if (numara == 10) return Color::FromArgb(0, 255, 0);
	else return Color::Black;
}








#pragma region Kordinat Sistemi Ayarlarý



Point Anaform::NormalKordinattanÝstenilenKordinataCevirme(int x, int y)
{
	Point donecek = MousePosition;

	donecek.X = x;
	donecek.Y = y;
	donecek.X = donecek.X - pictureBox1->Width / 2;
	donecek.Y = pictureBox1->Height / 2 - donecek.Y;
	return donecek;
}



Point Anaform::IstenilenKordinattanNormaleCevirme(int x,int y)
{
	Point donecek = MousePosition;
	donecek.X = x;
	donecek.Y = y;


	donecek.X = donecek.X + pictureBox1->Width / 2;
	donecek.Y = pictureBox1->Height / 2 - donecek.Y;

	/*list<Point> pointlist;
	pointlist.push_back(donecek);*/

	return donecek;
}





#pragma endregion





























#pragma region Çizim Ýþlemleri





void Anaform::ArtiCiz(int NoktaX, int NoktaY, Color renk)
{

	

	//if (renk == nullptr) return;

	//TODO: en sondaki piksellere basýnca patlýo kod


	this->asd->SetPixel(NoktaX, NoktaY, renk);

	for (int i = 1; i < arti_boyutu + 1; i++)
	{
		this->asd->SetPixel(NoktaX - i, NoktaY, renk);
		this->asd->SetPixel(NoktaX + i, NoktaY, renk);
		this->asd->SetPixel(NoktaX, NoktaY - i, renk);
		this->asd->SetPixel(NoktaX, NoktaY + i, renk);
	}



}


void Anaform::CizgiCiz(float a, float b, float c)
{
	// cy = ax + b


	if (c == 0)return;

	a = a / c;
	b = b / c;

	Pen^ myPen = gcnew Pen(Color::Black, 2);
	grfx = pictureBox1->CreateGraphics()->FromImage(this->asd);
	grfx->DrawLine(myPen, IstenilenKordinattanNormaleCevirme(XiBul(-280, a, b), 280), IstenilenKordinattanNormaleCevirme(XiBul(280, a, b), -280));
	pictureBox1->Image = this->asd;
}
void Anaform::CizgiCiz(float a, float b, float c,Color renk)
{
	// cy = ax + b


	if (c == 0)return;

	a = a / c;
	b = b / c;

	Pen^ myPen = gcnew Pen(renk, 2);
	grfx = pictureBox1->CreateGraphics()->FromImage(this->asd);
	grfx->DrawLine(myPen, IstenilenKordinattanNormaleCevirme(XiBul(-280, a, b), 280), IstenilenKordinattanNormaleCevirme(XiBul(280, a, b), -280));
	pictureBox1->Image = this->asd;
}
int Anaform::XiBul(int y, float a, float b)
{
	if (a == 0)return 1;
	return ((y - b) / a);
}



void Anaform::KordinatSisteminiCiz()
{
	if (this->asd == nullptr)
		this->asd = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	if (grfx == nullptr)
		grfx = pictureBox1->CreateGraphics()->FromImage(this->asd);


	Color renk = Color::Gray;
	for (int i = 0; i < pictureBox1->Height; i++)
	{
		this->asd->SetPixel(pictureBox1->Width / 2, i, renk);
	}
	for (int i = 0; i < pictureBox1->Width; i++)
	{
		this->asd->SetPixel(i, pictureBox1->Height / 2, renk);
	}

	pictureBox1->Image = this->asd;
}


void Anaform::TumOrnekleriCiz()
{
	Point nokta;
	for (int i = 0; i < this->ornekler->Count; i++)
	{
		nokta = IstenilenKordinattanNormaleCevirme(ornekler[i]->x, ornekler[i]->y);
		ArtiCiz(nokta.X,nokta.Y,ornekler[i]->renk);
	}
}


void Anaform::AgirliklariCiz()
{
	//if (sonyapilanislemdeltami==true)
	//{
	//	for (int i = 0; i < katmandakiNoronSayisi; i++)
	//	{
	//		CizgiCiz(Katman1->GetAgirlikDondur()[i][0], Katman1->GetAgirlikDondur()[i][2] * 300.0f, Katman1->GetAgirlikDondur()[i][1], NumarayaGoreRenkDondurucu(i + 1));
	//	}
	//}
	//else
	//{
	//	for (int i = 0; i < katmandakiNoronSayisi; i++)
	//	{
	//		CizgiCiz(Katman1->GetAgirlikDondur()[i][0], Katman1->GetAgirlikDondur()[i][2] , Katman1->GetAgirlikDondur()[i][1], NumarayaGoreRenkDondurucu(i + 1));
	//	}
	//}

}


#pragma endregion



























/*
bool Anaform::OrnekleriHepsiniTestEt()
{
	// buna gerek yok galiba
	float girdi[GIRDISAYISI];
	for (int i = 0; i < ornekler->Count; i++)
	{
		girdi[0] = ornekler[i]->x;
		girdi[1] = ornekler[i]->y;
		girdi[2] = 1.0f;


		if (first->Perseptronegitim(girdi, ornekler[i]->beklenen) == true)
		{

		}
		else
		{
			return false;
		}
	}
	return true;
}

*/