#pragma once

namespace MediaPlayerMIU {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ libraryPane;
	protected:

	private: System::Windows::Forms::PictureBox^ mainBackground;

	private: System::Windows::Forms::PictureBox^ sideBackground;








	private: System::Windows::Forms::PictureBox^ library_title_picture;


	private: System::Windows::Forms::Button^ Title_Button;
	private: System::Windows::Forms::Button^ Duration_Button;
	private: System::Windows::Forms::ListBox^ track_list;
	private: System::Windows::Forms::ListBox^ duration_list;









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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->libraryPane = (gcnew System::Windows::Forms::Panel());
			this->duration_list = (gcnew System::Windows::Forms::ListBox());
			this->track_list = (gcnew System::Windows::Forms::ListBox());
			this->Duration_Button = (gcnew System::Windows::Forms::Button());
			this->Title_Button = (gcnew System::Windows::Forms::Button());
			this->library_title_picture = (gcnew System::Windows::Forms::PictureBox());
			this->mainBackground = (gcnew System::Windows::Forms::PictureBox());
			this->sideBackground = (gcnew System::Windows::Forms::PictureBox());
			this->libraryPane->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->library_title_picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainBackground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sideBackground))->BeginInit();
			this->SuspendLayout();
			// 
			// libraryPane
			// 
			this->libraryPane->Controls->Add(this->duration_list);
			this->libraryPane->Controls->Add(this->track_list);
			this->libraryPane->Controls->Add(this->Duration_Button);
			this->libraryPane->Controls->Add(this->Title_Button);
			this->libraryPane->Controls->Add(this->library_title_picture);
			this->libraryPane->Controls->Add(this->mainBackground);
			this->libraryPane->Controls->Add(this->sideBackground);
			this->libraryPane->Location = System::Drawing::Point(1, 1);
			this->libraryPane->Name = L"libraryPane";
			this->libraryPane->Size = System::Drawing::Size(1038, 715);
			this->libraryPane->TabIndex = 0;
			// 
			// duration_list
			// 
			this->duration_list->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->duration_list->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->duration_list->FormattingEnabled = true;
			this->duration_list->Location = System::Drawing::Point(590, 247);
			this->duration_list->Name = L"duration_list";
			this->duration_list->Size = System::Drawing::Size(311, 316);
			this->duration_list->TabIndex = 11;
			// 
			// track_list
			// 
			this->track_list->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->track_list->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->track_list->FormattingEnabled = true;
			this->track_list->Location = System::Drawing::Point(270, 247);
			this->track_list->Name = L"track_list";
			this->track_list->Size = System::Drawing::Size(324, 316);
			this->track_list->TabIndex = 10;
			// 
			// Duration_Button
			// 
			this->Duration_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Duration_Button->Font = (gcnew System::Drawing::Font(L"Harrington", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Duration_Button->ForeColor = System::Drawing::Color::Transparent;
			this->Duration_Button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Duration_Button.Image")));
			this->Duration_Button->Location = System::Drawing::Point(668, 170);
			this->Duration_Button->Name = L"Duration_Button";
			this->Duration_Button->Size = System::Drawing::Size(148, 47);
			this->Duration_Button->TabIndex = 9;
			this->Duration_Button->Text = L"Duration";
			this->Duration_Button->UseVisualStyleBackColor = true;
			// 
			// Title_Button
			// 
			this->Title_Button->Font = (gcnew System::Drawing::Font(L"Harrington", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title_Button->ForeColor = System::Drawing::Color::Transparent;
			this->Title_Button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Title_Button.Image")));
			this->Title_Button->Location = System::Drawing::Point(365, 170);
			this->Title_Button->Name = L"Title_Button";
			this->Title_Button->Size = System::Drawing::Size(148, 47);
			this->Title_Button->TabIndex = 8;
			this->Title_Button->Text = L"Title";
			this->Title_Button->UseVisualStyleBackColor = true;
			// 
			// library_title_picture
			// 
			this->library_title_picture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"library_title_picture.Image")));
			this->library_title_picture->Location = System::Drawing::Point(220, 21);
			this->library_title_picture->Name = L"library_title_picture";
			this->library_title_picture->Size = System::Drawing::Size(118, 62);
			this->library_title_picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->library_title_picture->TabIndex = 4;
			this->library_title_picture->TabStop = false;
			// 
			// mainBackground
			// 
			this->mainBackground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mainBackground.Image")));
			this->mainBackground->Location = System::Drawing::Point(188, 3);
			this->mainBackground->Name = L"mainBackground";
			this->mainBackground->Size = System::Drawing::Size(850, 715);
			this->mainBackground->TabIndex = 2;
			this->mainBackground->TabStop = false;
			// 
			// sideBackground
			// 
			this->sideBackground->Dock = System::Windows::Forms::DockStyle::Left;
			this->sideBackground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sideBackground.Image")));
			this->sideBackground->Location = System::Drawing::Point(0, 0);
			this->sideBackground->Name = L"sideBackground";
			this->sideBackground->Size = System::Drawing::Size(172, 715);
			this->sideBackground->TabIndex = 1;
			this->sideBackground->TabStop = false;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1036, 715);
			this->Controls->Add(this->libraryPane);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->libraryPane->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->library_title_picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainBackground))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sideBackground))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
