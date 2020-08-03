#pragma once
#include <stdio.h>
#include "Ornekler.h"
#include "Neuron.h"
#include "Layer.h"
#include "LayerControl.h"

namespace YSAOdev1 {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for Anaform
	/// </summary>
	public ref class Anaform : public System::Windows::Forms::Form
	{
	public:
		Anaform(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Anaform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  btngrup4;
	private: System::Windows::Forms::Button^  btngrup3;
	private: System::Windows::Forms::Button^  btngrup2;
	private: System::Windows::Forms::Button^  btngrup1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DomainUpDown^  domainUpDown1;
	private: System::Windows::Forms::Button^  btnExit;
	private: System::Windows::Forms::Label^  lblKonum;

	private: System::Windows::Forms::Panel^  panel2;

	private: System::Windows::Forms::ListBox^  listBox1;

	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  btnKatmanOlustur;
	private: System::Windows::Forms::ComboBox^  cmbSinifSayisi;


	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Panel^  pnlSiniflar;
	private: System::Windows::Forms::Label^  lblCycle;

	private: System::Windows::Forms::Label^  lblStep;
	private: System::Windows::Forms::Button^  btnKatmanSil;
	private: System::Windows::Forms::Button^  btnSonOrnekSil;
	private: System::Windows::Forms::Button^  btnTumOrnekSil;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  cmbAraKatmanNoronSayisi;
	private: System::Windows::Forms::Button^  btnAgirlikKaydet;
	private: System::Windows::Forms::Button^  btnOrnekKaydet;
	private: System::Windows::Forms::Button^  button2;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pnlSiniflar = (gcnew System::Windows::Forms::Panel());
			this->btngrup1 = (gcnew System::Windows::Forms::Button());
			this->btngrup2 = (gcnew System::Windows::Forms::Button());
			this->btngrup4 = (gcnew System::Windows::Forms::Button());
			this->btngrup3 = (gcnew System::Windows::Forms::Button());
			this->lblKonum = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->domainUpDown1 = (gcnew System::Windows::Forms::DomainUpDown());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->lblStep = (gcnew System::Windows::Forms::Label());
			this->lblCycle = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->btnAgirlikKaydet = (gcnew System::Windows::Forms::Button());
			this->btnOrnekKaydet = (gcnew System::Windows::Forms::Button());
			this->btnKatmanSil = (gcnew System::Windows::Forms::Button());
			this->btnSonOrnekSil = (gcnew System::Windows::Forms::Button());
			this->btnTumOrnekSil = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cmbAraKatmanNoronSayisi = (gcnew System::Windows::Forms::ComboBox());
			this->btnKatmanOlustur = (gcnew System::Windows::Forms::Button());
			this->cmbSinifSayisi = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->pnlSiniflar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel4->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->pnlSiniflar);
			this->panel1->Controls->Add(this->lblKonum);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->btnExit);
			this->panel1->Controls->Add(this->domainUpDown1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(986, 40);
			this->panel1->TabIndex = 0;
			// 
			// pnlSiniflar
			// 
			this->pnlSiniflar->Controls->Add(this->btngrup1);
			this->pnlSiniflar->Controls->Add(this->btngrup2);
			this->pnlSiniflar->Controls->Add(this->btngrup4);
			this->pnlSiniflar->Controls->Add(this->btngrup3);
			this->pnlSiniflar->Location = System::Drawing::Point(3, 5);
			this->pnlSiniflar->Name = L"pnlSiniflar";
			this->pnlSiniflar->Size = System::Drawing::Size(496, 30);
			this->pnlSiniflar->TabIndex = 13;
			// 
			// btngrup1
			// 
			this->btngrup1->Location = System::Drawing::Point(10, 6);
			this->btngrup1->Name = L"btngrup1";
			this->btngrup1->Size = System::Drawing::Size(20, 20);
			this->btngrup1->TabIndex = 0;
			this->btngrup1->Text = L"1";
			this->btngrup1->UseVisualStyleBackColor = true;
			this->btngrup1->Visible = false;
			this->btngrup1->Click += gcnew System::EventHandler(this, &Anaform::btngrup1_Click);
			// 
			// btngrup2
			// 
			this->btngrup2->Location = System::Drawing::Point(34, 6);
			this->btngrup2->Name = L"btngrup2";
			this->btngrup2->Size = System::Drawing::Size(20, 20);
			this->btngrup2->TabIndex = 2;
			this->btngrup2->Text = L"2";
			this->btngrup2->UseVisualStyleBackColor = true;
			this->btngrup2->Visible = false;
			this->btngrup2->Click += gcnew System::EventHandler(this, &Anaform::btngrup2_Click);
			// 
			// btngrup4
			// 
			this->btngrup4->Location = System::Drawing::Point(86, 6);
			this->btngrup4->Name = L"btngrup4";
			this->btngrup4->Size = System::Drawing::Size(20, 20);
			this->btngrup4->TabIndex = 4;
			this->btngrup4->Text = L"4";
			this->btngrup4->UseVisualStyleBackColor = true;
			this->btngrup4->Visible = false;
			this->btngrup4->Click += gcnew System::EventHandler(this, &Anaform::btngrup4_Click);
			// 
			// btngrup3
			// 
			this->btngrup3->Location = System::Drawing::Point(60, 6);
			this->btngrup3->Name = L"btngrup3";
			this->btngrup3->Size = System::Drawing::Size(20, 20);
			this->btngrup3->TabIndex = 3;
			this->btngrup3->Text = L"3";
			this->btngrup3->UseVisualStyleBackColor = true;
			this->btngrup3->Visible = false;
			this->btngrup3->Click += gcnew System::EventHandler(this, &Anaform::btngrup3_Click);
			// 
			// lblKonum
			// 
			this->lblKonum->AutoSize = true;
			this->lblKonum->Location = System::Drawing::Point(363, 10);
			this->lblKonum->Name = L"lblKonum";
			this->lblKonum->Size = System::Drawing::Size(0, 13);
			this->lblKonum->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(512, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Art˝n˝n Boyutu:";
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(949, 8);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(25, 23);
			this->btnExit->TabIndex = 7;
			this->btnExit->Text = L"X";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &Anaform::btnExit_Click);
			// 
			// domainUpDown1
			// 
			this->domainUpDown1->BackColor = System::Drawing::SystemColors::Control;
			this->domainUpDown1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->domainUpDown1->InterceptArrowKeys = false;
			this->domainUpDown1->Items->Add(L"2");
			this->domainUpDown1->Items->Add(L"3");
			this->domainUpDown1->Items->Add(L"4");
			this->domainUpDown1->Items->Add(L"5");
			this->domainUpDown1->Items->Add(L"6");
			this->domainUpDown1->Items->Add(L"7");
			this->domainUpDown1->Items->Add(L"8");
			this->domainUpDown1->Items->Add(L"9");
			this->domainUpDown1->Items->Add(L"10");
			this->domainUpDown1->Location = System::Drawing::Point(593, 11);
			this->domainUpDown1->Name = L"domainUpDown1";
			this->domainUpDown1->ReadOnly = true;
			this->domainUpDown1->Size = System::Drawing::Size(32, 20);
			this->domainUpDown1->TabIndex = 5;
			this->domainUpDown1->Text = L"2";
			this->domainUpDown1->SelectedItemChanged += gcnew System::EventHandler(this, &Anaform::domainUpDown1_SelectedItemChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Left;
			this->pictureBox1->Location = System::Drawing::Point(0, 40);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 502);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Anaform::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Anaform::pictureBox1_MouseMove);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->lblStep);
			this->panel2->Controls->Add(this->lblCycle);
			this->panel2->Location = System::Drawing::Point(506, 231);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(302, 382);
			this->panel2->TabIndex = 8;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(9, 87);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(96, 17);
			this->checkBox1->TabIndex = 3;
			this->checkBox1->Text = L"Moment Kullan";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Anaform::checkBox1_CheckedChanged);
			// 
			// lblStep
			// 
			this->lblStep->AutoSize = true;
			this->lblStep->Location = System::Drawing::Point(7, 41);
			this->lblStep->Name = L"lblStep";
			this->lblStep->Size = System::Drawing::Size(32, 13);
			this->lblStep->TabIndex = 2;
			this->lblStep->Text = L"Step:";
			// 
			// lblCycle
			// 
			this->lblCycle->AutoSize = true;
			this->lblCycle->Location = System::Drawing::Point(7, 19);
			this->lblCycle->Name = L"lblCycle";
			this->lblCycle->Size = System::Drawing::Size(36, 13);
			this->lblCycle->TabIndex = 1;
			this->lblCycle->Text = L"Cycle:";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(1207, 60);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(146, 563);
			this->listBox1->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->button2);
			this->panel4->Controls->Add(this->btnAgirlikKaydet);
			this->panel4->Controls->Add(this->btnOrnekKaydet);
			this->panel4->Controls->Add(this->btnKatmanSil);
			this->panel4->Controls->Add(this->btnSonOrnekSil);
			this->panel4->Controls->Add(this->btnTumOrnekSil);
			this->panel4->Controls->Add(this->button1);
			this->panel4->Controls->Add(this->label3);
			this->panel4->Location = System::Drawing::Point(814, 49);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(167, 560);
			this->panel4->TabIndex = 11;
			// 
			// btnAgirlikKaydet
			// 
			this->btnAgirlikKaydet->Location = System::Drawing::Point(6, 314);
			this->btnAgirlikKaydet->Name = L"btnAgirlikKaydet";
			this->btnAgirlikKaydet->Size = System::Drawing::Size(154, 30);
			this->btnAgirlikKaydet->TabIndex = 15;
			this->btnAgirlikKaydet->Text = L"A˝rliklari Kaydet";
			this->btnAgirlikKaydet->UseVisualStyleBackColor = true;
			// 
			// btnOrnekKaydet
			// 
			this->btnOrnekKaydet->Location = System::Drawing::Point(6, 278);
			this->btnOrnekKaydet->Name = L"btnOrnekKaydet";
			this->btnOrnekKaydet->Size = System::Drawing::Size(154, 30);
			this->btnOrnekKaydet->TabIndex = 14;
			this->btnOrnekKaydet->Text = L"÷rnekleri Kaydet";
			this->btnOrnekKaydet->UseVisualStyleBackColor = true;
			// 
			// btnKatmanSil
			// 
			this->btnKatmanSil->Location = System::Drawing::Point(6, 451);
			this->btnKatmanSil->Name = L"btnKatmanSil";
			this->btnKatmanSil->Size = System::Drawing::Size(154, 30);
			this->btnKatmanSil->TabIndex = 13;
			this->btnKatmanSil->Text = L"Katman˝ Sil";
			this->btnKatmanSil->UseVisualStyleBackColor = true;
			this->btnKatmanSil->Visible = false;
			this->btnKatmanSil->Click += gcnew System::EventHandler(this, &Anaform::btnKatmanSil_Click);
			// 
			// btnSonOrnekSil
			// 
			this->btnSonOrnekSil->Location = System::Drawing::Point(6, 415);
			this->btnSonOrnekSil->Name = L"btnSonOrnekSil";
			this->btnSonOrnekSil->Size = System::Drawing::Size(154, 30);
			this->btnSonOrnekSil->TabIndex = 12;
			this->btnSonOrnekSil->Text = L"Son koyulan ÷rnei Sil";
			this->btnSonOrnekSil->UseVisualStyleBackColor = true;
			this->btnSonOrnekSil->Click += gcnew System::EventHandler(this, &Anaform::btnSonOrnekSil_Click);
			// 
			// btnTumOrnekSil
			// 
			this->btnTumOrnekSil->Location = System::Drawing::Point(6, 383);
			this->btnTumOrnekSil->Name = L"btnTumOrnekSil";
			this->btnTumOrnekSil->Size = System::Drawing::Size(154, 30);
			this->btnTumOrnekSil->TabIndex = 11;
			this->btnTumOrnekSil->Text = L"T¸m ÷rnekleri Sil";
			this->btnTumOrnekSil->UseVisualStyleBackColor = true;
			this->btnTumOrnekSil->Click += gcnew System::EventHandler(this, &Anaform::btnTumOrnekSil_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 30);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Eit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Anaform::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"÷renme ›˛lemleri:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->cmbAraKatmanNoronSayisi);
			this->groupBox1->Controls->Add(this->btnKatmanOlustur);
			this->groupBox1->Controls->Add(this->cmbSinifSayisi);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(506, 49);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(302, 176);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Katman Olu˛tur";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"S˝n˝f say˝s˝:";
			// 
			// cmbAraKatmanNoronSayisi
			// 
			this->cmbAraKatmanNoronSayisi->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbAraKatmanNoronSayisi->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->cmbAraKatmanNoronSayisi->FormattingEnabled = true;
			this->cmbAraKatmanNoronSayisi->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10"
			});
			this->cmbAraKatmanNoronSayisi->Location = System::Drawing::Point(206, 73);
			this->cmbAraKatmanNoronSayisi->Name = L"cmbAraKatmanNoronSayisi";
			this->cmbAraKatmanNoronSayisi->Size = System::Drawing::Size(84, 21);
			this->cmbAraKatmanNoronSayisi->TabIndex = 3;
			// 
			// btnKatmanOlustur
			// 
			this->btnKatmanOlustur->Location = System::Drawing::Point(206, 110);
			this->btnKatmanOlustur->Name = L"btnKatmanOlustur";
			this->btnKatmanOlustur->Size = System::Drawing::Size(90, 60);
			this->btnKatmanOlustur->TabIndex = 2;
			this->btnKatmanOlustur->Text = L"Katman˝ Olu˛tur";
			this->btnKatmanOlustur->UseVisualStyleBackColor = true;
			this->btnKatmanOlustur->Click += gcnew System::EventHandler(this, &Anaform::btnKatmanOlustur_Click);
			// 
			// cmbSinifSayisi
			// 
			this->cmbSinifSayisi->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbSinifSayisi->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->cmbSinifSayisi->FormattingEnabled = true;
			this->cmbSinifSayisi->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9", L"10"
			});
			this->cmbSinifSayisi->Location = System::Drawing::Point(206, 24);
			this->cmbSinifSayisi->Name = L"cmbSinifSayisi";
			this->cmbSinifSayisi->Size = System::Drawing::Size(84, 21);
			this->cmbSinifSayisi->TabIndex = 1;
			this->cmbSinifSayisi->SelectedIndexChanged += gcnew System::EventHandler(this, &Anaform::cmbNoronSayisi_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 81);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(175, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Ara katmanda Olacak Nˆron Say˝s˝:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 146);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(154, 30);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Bˆlgeleri Ay˝r";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Anaform::button2_Click);
			// 
			// Anaform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(986, 542);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Anaform";
			this->Text = L"Anaform";
			this->Load += gcnew System::EventHandler(this, &Anaform::Anaform_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->pnlSiniflar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion












		




	private:
		void ArtiCiz(int NoktaX, int NoktaY, Color renk);
		Void CizgiCiz(float a, float b, float c);
		Void CizgiCiz(float a, float b, float c, Color renk);
		Color NumarayaGoreRenkDondurucu(int numara);

		
		int XiBul(int y, float a, float b);
		Point NormalKordinattan›stenilenKordinataCevirme(int x, int y);
		Point IstenilenKordinattanNormaleCevirme(int x, int y);
		Bitmap^ asd;
		Graphics^ grfx;
		int islem_number = 1;
		int arti_boyutu = 5;

		int katmandakiNoronSayisi = 1;


		LayerControl^ KatmanKontrol;


		List<Ornekler^>^ ornekler = gcnew List<Ornekler^>();
		void EkraniBolgelereAyir();



		



		void KordinatSisteminiCiz();
		void TumOrnekleriCiz();
		void AgirliklariCiz();
		bool sonyapilanislemdeltami = false;


		int cyclesayisi = 0;


		//void OrneklerinKatmanlaraGonderilmesi();


		void OrnekleriEgitDelta();








		Color NumarayaGoreKoyuRenkDondurucu(int numara);



		void btnTiklamalar(System::Object^  sender, System::EventArgs^  e);
		void ButtonOlusturucu(int adet);






#pragma region Test Butonlar˝


		System::Void btngrup1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			islem_number = 1;
		}
		System::Void btngrup2_Click(System::Object^  sender, System::EventArgs^  e)
		{
			islem_number = 2;

		}
		System::Void btngrup3_Click(System::Object^  sender, System::EventArgs^  e)
		{
			islem_number = 3;
		}
		System::Void btngrup4_Click(System::Object^  sender, System::EventArgs^  e)
		{
			islem_number = 4;
		}



#pragma endregion





		System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);



		System::Void domainUpDown1_SelectedItemChanged(System::Object^  sender, System::EventArgs^  e)
		{
			arti_boyutu = domainUpDown1->SelectedIndex + 2;
		}












		System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->Close();
		}
		System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);


		System::Void Anaform_Load(System::Object^  sender, System::EventArgs^  e);



		System::Void btnegit_Click(System::Object^  sender, System::EventArgs^  e)
		{
			//egitim();
			//OrneklerinKatmanlaraGonderilmesi();
			//OrnekleriEgitPerseptron();
		}



		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			//egitim2();
			OrnekleriEgitDelta();

		}
		System::Void cmbNoronSayisi_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		{
			katmandakiNoronSayisi = cmbSinifSayisi->SelectedIndex + 1;

		}



		System::Void btnKatmanOlustur_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnTumOrnekSil_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnSonOrnekSil_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnKatmanSil_Click(System::Object^  sender, System::EventArgs^  e)
		{
			
		}
		System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);










	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		EkraniBolgelereAyir();
	}
};
}