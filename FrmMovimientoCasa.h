#pragma once
#include "MovimientoCasaService.h"

namespace Semana10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Formulario para el movimiento de la casa
	/// Contiene la l�gica de presentaci�n y eventos de UI
	/// </summary>
	public ref class FrmMovimientoCasa : public System::Windows::Forms::Form
	{
	private:
		MovimientoCasaService* service;
		//Graphics^ graphics;
	private: System::Windows::Forms::Label^ label1;
		   bool movimientoActivo;

	public:
		FrmMovimientoCasa(void)
		{
			InitializeComponent();
			service = new MovimientoCasaService();
			//graphics = panelDibujo->CreateGraphics();
			movimientoActivo = false;


		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~FrmMovimientoCasa()
		{
			if (components)
			{
				delete components;
			}
			if (service != nullptr) {
				delete service;
			}
		}

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ btnDibujar;
	private: System::Windows::Forms::Button^ btnMover;
	private: System::Windows::Forms::Label^ lblInstrucciones;
	private: System::Windows::Forms::Panel^ panelDibujo;
	private: System::ComponentModel::IContainer^ components;

	private:
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnDibujar = (gcnew System::Windows::Forms::Button());
			this->btnMover = (gcnew System::Windows::Forms::Button());
			this->lblInstrucciones = (gcnew System::Windows::Forms::Label());
			this->panelDibujo = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMovimientoCasa::timer1_Tick);
			// 
			// btnDibujar
			// 
			this->btnDibujar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->btnDibujar->Location = System::Drawing::Point(16, 15);
			this->btnDibujar->Margin = System::Windows::Forms::Padding(4);
			this->btnDibujar->Name = L"btnDibujar";
			this->btnDibujar->Size = System::Drawing::Size(150, 49);
			this->btnDibujar->TabIndex = 0;
			this->btnDibujar->Text = L"Dibujar Casa";
			this->btnDibujar->UseVisualStyleBackColor = true;
			this->btnDibujar->Click += gcnew System::EventHandler(this, &FrmMovimientoCasa::btnDibujar_Click);
			// 
			// btnMover
			// 
			this->btnMover->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->btnMover->Location = System::Drawing::Point(180, 15);
			this->btnMover->Margin = System::Windows::Forms::Padding(4);
			this->btnMover->Name = L"btnMover";
			this->btnMover->Size = System::Drawing::Size(150, 49);
			this->btnMover->TabIndex = 1;
			this->btnMover->Text = L"Mover Casas";
			this->btnMover->UseVisualStyleBackColor = true;
			this->btnMover->Click += gcnew System::EventHandler(this, &FrmMovimientoCasa::btnMover_Click);
			// 
			// lblInstrucciones
			// 
			this->lblInstrucciones->AutoSize = true;
			this->lblInstrucciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInstrucciones->Location = System::Drawing::Point(350, 20);
			this->lblInstrucciones->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblInstrucciones->Name = L"lblInstrucciones";
			this->lblInstrucciones->Size = System::Drawing::Size(523, 25);
			this->lblInstrucciones->TabIndex = 2;
			this->lblInstrucciones->Text = L"Haz clic en Dibujar Casa para agregar casas al panel";
			// 
			// panelDibujo
			// 
			this->panelDibujo->BackColor = System::Drawing::Color::White;
			this->panelDibujo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelDibujo->Location = System::Drawing::Point(16, 80);
			this->panelDibujo->Name = L"panelDibujo";
			this->panelDibujo->Size = System::Drawing::Size(1035, 640);
			this->panelDibujo->TabIndex = 3;
			this->panelDibujo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMovimientoCasa::panelDibujo_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(349, 53);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(463, 24);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Desarrollado por Henry Antonio Mendoza Puerta";
			// 
			// FrmMovimientoCasa
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1067, 738);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panelDibujo);
			this->Controls->Add(this->lblInstrucciones);
			this->Controls->Add(this->btnMover);
			this->Controls->Add(this->btnDibujar);
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"FrmMovimientoCasa";
			this->Text = L"Movimiento de Casa - Arquitectura en Capas";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:	

		
		System::Void panelDibujo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

			//service->dibujarFiguras(graphics);
		}

	
		System::Void btnDibujar_Click(System::Object^ sender, System::EventArgs^ e) {

			Random^ rand = gcnew Random();
			int x = rand->Next(50, panelDibujo->Width - 170);
			int y = rand->Next(50, panelDibujo->Height - 150);


			int r = rand->Next(100, 256);
			int g = rand->Next(100, 256);
			int b = rand->Next(100, 256);


			service->agregarCasa(x, y, 120, 100, r, g, b);

			Graphics^ canvas = panelDibujo->CreateGraphics();
			BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
			BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, panelDibujo->ClientRectangle);

			buffer->Graphics->Clear(Color::White);
			service->dibujarFiguras(buffer->Graphics);
			buffer->Render(canvas);

			delete buffer;
			delete canvas;
		}

		
		System::Void btnMover_Click(System::Object^ sender, System::EventArgs^ e) {
			if (service->getCantidadFiguras() == 0) {
				MessageBox::Show("Primero dibuja algunas casas", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			movimientoActivo = !movimientoActivo;

			if (movimientoActivo) {
				timer1->Start();
				btnMover->Text = "Detener";
				btnMover->BackColor = Color::Salmon;
			}
			else {
				timer1->Stop();
				btnMover->Text = "Mover Casas";
				btnMover->BackColor = Color::LightGreen;
			}
		}



		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			service->moverFigurasAutomatico(panelDibujo->Width, panelDibujo->Height);

			Graphics^ canvas = panelDibujo->CreateGraphics();
			BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
			BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, panelDibujo->ClientRectangle);

			buffer->Graphics->Clear(Color::White);
			service->dibujarFiguras(buffer->Graphics);
			buffer->Render(canvas);

			delete buffer;
			delete canvas;
		}

		
	};
}
