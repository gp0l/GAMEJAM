#pragma once
#include "CompetenciaService.h"

namespace Semana10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FrmCompetencia : public System::Windows::Forms::Form
	{
	public:
		FrmCompetencia(void)
		{
			InitializeComponent();
			competenciaService = new CompetenciaService(panelDibujo->Width, panelDibujo->Height);
			//graphics = panelDibujo->CreateGraphics();
		}

	protected:
		~FrmCompetencia()
		{
			if (components)
			{
				delete components;
			}
			if (competenciaService != nullptr) {
				delete competenciaService;
			}
		}

	private:
		System::Windows::Forms::Timer^ timer;
		System::Windows::Forms::Panel^ panelDibujo;
		System::Windows::Forms::Button^ btnIniciar;
		System::Windows::Forms::Label^ lblResultado;
	private: System::ComponentModel::IContainer^ components;


		CompetenciaService* competenciaService;
	private: System::Windows::Forms::Label^ label1;
		   //Graphics^ graphics;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelDibujo = (gcnew System::Windows::Forms::Panel());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->lblResultado = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer->Interval = 50;
			this->timer->Tick += gcnew System::EventHandler(this, &FrmCompetencia::timer_Tick);
			// 
			// panelDibujo
			// 
			this->panelDibujo->BackColor = System::Drawing::Color::White;
			this->panelDibujo->Location = System::Drawing::Point(12, 60);
			this->panelDibujo->Name = L"panelDibujo";
			this->panelDibujo->Size = System::Drawing::Size(1020, 500);
			this->panelDibujo->TabIndex = 0;
			this->panelDibujo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmCompetencia::panelDibujo_Paint);
			// 
			// btnIniciar
			// 
			this->btnIniciar->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->btnIniciar->Location = System::Drawing::Point(12, 12);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(150, 40);
			this->btnIniciar->TabIndex = 1;
			this->btnIniciar->Text = L"Iniciar Competencia";
			this->btnIniciar->UseVisualStyleBackColor = true;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &FrmCompetencia::btnIniciar_Click);
			// 
			// lblResultado
			// 
			this->lblResultado->AutoSize = true;
			this->lblResultado->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->lblResultado->Location = System::Drawing::Point(400, 20);
			this->lblResultado->Name = L"lblResultado";
			this->lblResultado->Size = System::Drawing::Size(0, 22);
			this->lblResultado->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 585);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(374, 18);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Desarrollado por Henry Antonio Mendoza Puerta";
			// 
			// FrmCompetencia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1051, 610);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblResultado);
			this->Controls->Add(this->btnIniciar);
			this->Controls->Add(this->panelDibujo);
			this->Name = L"FrmCompetencia";
			this->Text = L"Competencia de Figuras";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	

	private: System::Void btnIniciar_Click(System::Object^ sender, System::EventArgs^ e) {
		competenciaService->iniciarPartida();
		timer->Start();
		btnIniciar->Enabled = false;
		lblResultado->Text = "";
	}

	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		competenciaService->moverFiguras();
		competenciaService->verificarMeta();

		Graphics^ canvas = panelDibujo->CreateGraphics();
		BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, panelDibujo->ClientRectangle);

		buffer->Graphics->Clear(Color::White);
		competenciaService->dibujar(buffer->Graphics);
		buffer->Render(canvas);

		delete buffer;
		delete canvas;

		if (competenciaService->juegoTerminado()) {
			timer->Stop();
			int ganador = competenciaService->getGanador();

			if (ganador == -2) {
				lblResultado->Text = "EMPATE!";
			}
			else {
				String^ nombreGanador = "";
				if (ganador == 0) nombreGanador = "Triangulo";
				else if (ganador == 1) nombreGanador = "Rectangulo";
				else if (ganador == 2) nombreGanador = "Rombo";
				lblResultado->Text = "GANADOR: " + nombreGanador;
			}

			btnIniciar->Enabled = true;
		}
	}

	private: System::Void panelDibujo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		//competenciaService->dibujar(graphics);
	}
	};
}
