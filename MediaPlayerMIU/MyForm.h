#pragma once

namespace MediaPlayerMIU {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: AxWMPLib::AxWindowsMediaPlayer^ player;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	protected:

	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->player = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// player
			// 
			this->player->Dock = System::Windows::Forms::DockStyle::Fill;
			this->player->Enabled = true;
			this->player->Location = System::Drawing::Point(0, 0);
			this->player->Margin = System::Windows::Forms::Padding(4);
			this->player->Name = L"player";
			this->player->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"player.OcxState")));
			this->player->Size = System::Drawing::Size(1295, 670);
			this->player->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Blue;
			this->groupBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox1->Location = System::Drawing::Point(277, 351);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(583, 223);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(299, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 98);
			this->button1->TabIndex = 2;
			this->button1->Text = L"next";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1295, 670);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->player);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
