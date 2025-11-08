#pragma once
#include "MundoHampService.h"

namespace Semana10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FrmMundoHamp : public System::Windows::Forms::Form
	{
	public:
		FrmMundoHamp(void)
		{
			InitializeComponent();

			service = new MundoHampService(panelDibujo->Width, panelDibujo->Height);

			char rutaMario[] = "mario.png";
			service->cargarSpriteMario(rutaMario, 4, 4);

			char rutaHamp[] = "hamp.png";
			service->cargarSpriteHamp(rutaHamp, 4, 4);



			generarPikachusAleatorios(6);

			//teclaPresionada = Direccion::Ninguno;
			teclaPresionadaHamp = Direccion::Ninguno;
		}

	protected:
		~FrmMundoHamp()
		{
			if (components) delete components;
			if (service) delete service;
		}

	private:
		MundoHampService* service;
		Direccion teclaPresionada;
		Direccion teclaPresionadaHamp;

		

		System::Windows::Forms::Panel^ panelDibujo;
		System::Windows::Forms::Label^ lblInstrucciones;
		System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
		   System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMundoHamp::typeid));
			this->panelDibujo = (gcnew System::Windows::Forms::Panel());
			this->lblInstrucciones = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panelDibujo
			// 
			this->panelDibujo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelDibujo->BackColor = System::Drawing::Color::SkyBlue;
			this->panelDibujo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelDibujo.BackgroundImage")));
			this->panelDibujo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelDibujo->Location = System::Drawing::Point(-3, 0);
			this->panelDibujo->Name = L"panelDibujo";
			this->panelDibujo->Size = System::Drawing::Size(1225, 644);
			this->panelDibujo->TabIndex = 0;
			this->panelDibujo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMundoHamp::panelDibujo_Paint);
			// 
			// lblInstrucciones
			// 
			this->lblInstrucciones->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->lblInstrucciones->AutoSize = true;
			this->lblInstrucciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->lblInstrucciones->Location = System::Drawing::Point(12, 658);
			this->lblInstrucciones->Name = L"lblInstrucciones";
			this->lblInstrucciones->Size = System::Drawing::Size(507, 20);
			this->lblInstrucciones->TabIndex = 1;
			this->lblInstrucciones->Text = L"Flechas: Mario | WASD: Hamp | Pikachus se mueven solos";
			// 
			// timer
			// 
			this->timer->Interval = 50;
			this->timer->Tick += gcnew System::EventHandler(this, &FrmMundoHamp::timer_Tick);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(12, 687);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1183, 56);
			this->label1->TabIndex = 2;
			this->label1->Text = L"MundoHamp es un universo donde buscamos la felicidad a trav�s del conocimiento y "
				L"abrazamos la inteligencia artificial como aliada para crear, aprender y comparti"
				L"r";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(12, 743);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(1183, 56);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Si utilizas fragmentos de c�digo, materiales o ideas derivados de este proyecto, "
				L"por favor da los cr�ditos correspondientes al autor.";
			// 
			// FrmMundoHamp
			// 
			this->ClientSize = System::Drawing::Size(1218, 815);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblInstrucciones);
			this->Controls->Add(this->panelDibujo);
			this->KeyPreview = true;
			this->Name = L"FrmMundoHamp";
			this->Text = L"Mundo HAMP:Programa, practica, enseña y usa la IA con responsabilidad.";
			this->Load += gcnew System::EventHandler(this, &FrmMundoHamp::FrmMundoHamp_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoHamp::FrmMundoHamp_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoHamp::FrmMundoHamp_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void FrmMundoHamp_Load(System::Object^ sender, System::EventArgs^ e) {
		timer->Start();
	}

	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		/*if (teclaPresionada != Direccion::Ninguno) {
			service->moverMario(teclaPresionada);
		}*/
		if (teclaPresionadaHamp != Direccion::Ninguno) {
			service->moverHamp(teclaPresionadaHamp);
		}
		service->moverPikachus();

		Graphics^ canvas = panelDibujo->CreateGraphics();
		BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, panelDibujo->ClientRectangle);

		if (panelDibujo->BackgroundImage != nullptr) {
			buffer->Graphics->DrawImage(panelDibujo->BackgroundImage, 0, 0, panelDibujo->Width, panelDibujo->Height);
		} else {
			buffer->Graphics->Clear(Color::SkyBlue);
		}

		service->dibujarTodo(buffer->Graphics);
		buffer->Render(canvas);

		delete buffer;
		delete canvas;
	}

	private: System::Void panelDibujo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void FrmMundoHamp_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		/*if (e->KeyCode == Keys::Up)    teclaPresionada = Direccion::Arriba;
		if (e->KeyCode == Keys::Down)  teclaPresionada = Direccion::Abajo;
		if (e->KeyCode == Keys::Left)  teclaPresionada = Direccion::Izquierda;
		if (e->KeyCode == Keys::Right) teclaPresionada = Direccion::Derecha;*/

		if (e->KeyCode == Keys::W) teclaPresionadaHamp = Direccion::Arriba;
		if (e->KeyCode == Keys::S) teclaPresionadaHamp = Direccion::Abajo;
		if (e->KeyCode == Keys::A) teclaPresionadaHamp = Direccion::Izquierda;
		if (e->KeyCode == Keys::D) teclaPresionadaHamp = Direccion::Derecha;
	}

	private: System::Void FrmMundoHamp_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		/*if (e->KeyCode == Keys::Up || e->KeyCode == Keys::Down ||
			e->KeyCode == Keys::Left || e->KeyCode == Keys::Right) {
			teclaPresionada = Direccion::Ninguno;
		}*/

		if (e->KeyCode == Keys::W || e->KeyCode == Keys::S ||
			e->KeyCode == Keys::A || e->KeyCode == Keys::D) {
			teclaPresionadaHamp = Direccion::Ninguno;
		}
	}

	private: void generarPikachusAleatorios(int cantidad) {
		Random^ random = gcnew Random();
		char rutaPikachu[] = "pikachu.png";

		for (int i = 0; i < cantidad; i++) {
			int x = random->Next(50, panelDibujo->Width - 100);
			int y = random->Next(50, panelDibujo->Height - 100);
			int tipo = i % 2;
			service->agregarPikachu(x, y, rutaPikachu, 4, 4, tipo);
		}
	}

	};
}
