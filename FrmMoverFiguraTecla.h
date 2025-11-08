#pragma once
#include "JuegoService.h"

namespace Semana10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmMoverFiguraTecla
	/// </summary>
	public ref class FrmMoverFiguraTecla : public System::Windows::Forms::Form
	{
	public:
		FrmMoverFiguraTecla(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
			// El servicio se inicializa después de que el panel esté creado
			// Inicializar el servicio del juego con las dimensiones del panel

			juegoService = new JuegoService(panelDibujo->Width, panelDibujo->Height);
			//graphics = panelDibujo->CreateGraphics();

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~FrmMoverFiguraTecla()
		{
			if (components)
			{
				delete components;
			}
			if (juegoService)
			{
				delete juegoService;
			}
		}

	private:
		// Variables de negocio
		JuegoService* juegoService;
		//Graphics^ graphics;

		// Controles del formulario
		System::Windows::Forms::Panel^ panelDibujo;
		System::Windows::Forms::Label^ lblInstrucciones;
		System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::IContainer^ components;
		   /// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panelDibujo = (gcnew System::Windows::Forms::Panel());
			this->lblInstrucciones = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panelDibujo
			// 
			this->panelDibujo->BackColor = System::Drawing::Color::White;
			this->panelDibujo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelDibujo->Location = System::Drawing::Point(16, 15);
			this->panelDibujo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panelDibujo->Name = L"panelDibujo";
			this->panelDibujo->Size = System::Drawing::Size(1066, 615);
			this->panelDibujo->TabIndex = 0;
			this->panelDibujo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMoverFiguraTecla::panelDibujo_Paint);
			// 
			// lblInstrucciones
			// 
			this->lblInstrucciones->AutoSize = true;
			this->lblInstrucciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInstrucciones->Location = System::Drawing::Point(16, 679);
			this->lblInstrucciones->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblInstrucciones->Name = L"lblInstrucciones";
			this->lblInstrucciones->Size = System::Drawing::Size(593, 24);
			this->lblInstrucciones->TabIndex = 1;
			this->lblInstrucciones->Text = L"Flechas Arriba/Abajo: Mover circulo | D: Lanzar figura aleatoria";
			// 
			// timer
			// 
			this->timer->Interval = 30;
			this->timer->Tick += gcnew System::EventHandler(this, &FrmMoverFiguraTecla::timer_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(16, 645);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(463, 24);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Desarrollado por Henry Antonio Mendoza Puerta";
			// 
			// FrmMoverFiguraTecla
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1107, 715);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblInstrucciones);
			this->Controls->Add(this->panelDibujo);
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"FrmMoverFiguraTecla";
			this->Text = L"Mover Figuras con Teclas";
			this->Load += gcnew System::EventHandler(this, &FrmMoverFiguraTecla::FrmMoverFiguraTecla_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMoverFiguraTecla::FrmMoverFiguraTecla_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// Eventos del formulario
	private: System::Void FrmMoverFiguraTecla_Load(System::Object^ sender, System::EventArgs^ e) {
		// Iniciar el timer
		timer->Start();

		panelDibujo->Invalidate();
	}

	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (juegoService != nullptr) {
			juegoService->moverFiguras();
			juegoService->verificarColisiones();

			Graphics^ canvas = panelDibujo->CreateGraphics();
			BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
			BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, panelDibujo->ClientRectangle);

			buffer->Graphics->Clear(Color::White);
			juegoService->dibujar(buffer->Graphics);
			buffer->Render(canvas);

			delete buffer;
			delete canvas;
		}
	}

	private: System::Void panelDibujo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		//if (juegoService != nullptr) {
		//	juegoService->moverFiguras();
		//	juegoService->verificarColisiones();
		//	juegoService->dibujar(graphics);
		//}
	}

	private: System::Void FrmMoverFiguraTecla_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (juegoService == nullptr) return;

		if (e->KeyCode == Keys::Up) {
			juegoService->moverCirculo(-1);
		}
		else if (e->KeyCode == Keys::Down) {
			juegoService->moverCirculo(1);
		}
		else if (e->KeyCode == Keys::D) {
			juegoService->lanzarFigura();
		}
	}

	};
}
