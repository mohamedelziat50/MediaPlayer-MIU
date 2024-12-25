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

	private: bool isPlaying = false;  // Boolean to track the state (play/pause)

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			// This makes the WMP's built-in functionality hidden
			this->player->uiMode = L"none";  // This hides all UI elements like play/pause buttons

			// Initially, the Play button is visible and enabled, while the Pause button is hidden
			play_button->Visible = true;
			pause_button->Visible = false;
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
	private: System::Windows::Forms::Panel^ function_panel;

	private: System::Windows::Forms::Button^ play_button;

	private: System::Windows::Forms::Button^ pause_button;
	private: System::Windows::Forms::Button^ next_button;



	private: System::Windows::Forms::Button^ skipBackward_button;
	private: System::Windows::Forms::Button^ previous_button;
	private: System::Windows::Forms::Button^ skipForward_button;
	private: System::Windows::Forms::Label^ video_name;
















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
			this->function_panel = (gcnew System::Windows::Forms::Panel());
			this->video_name = (gcnew System::Windows::Forms::Label());
			this->skipForward_button = (gcnew System::Windows::Forms::Button());
			this->previous_button = (gcnew System::Windows::Forms::Button());
			this->skipBackward_button = (gcnew System::Windows::Forms::Button());
			this->next_button = (gcnew System::Windows::Forms::Button());
			this->pause_button = (gcnew System::Windows::Forms::Button());
			this->play_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->BeginInit();
			this->function_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// player
			// 
			this->player->Dock = System::Windows::Forms::DockStyle::Fill;
			this->player->Enabled = true;
			this->player->Location = System::Drawing::Point(0, 0);
			this->player->Name = L"player";
			this->player->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"player.OcxState")));
			this->player->Size = System::Drawing::Size(971, 544);
			this->player->TabIndex = 0;
			this->player->Enter += gcnew System::EventHandler(this, &MyForm::player_Enter);
			// 
			// function_panel
			// 
			this->function_panel->BackColor = System::Drawing::Color::DimGray;
			this->function_panel->Controls->Add(this->video_name);
			this->function_panel->Controls->Add(this->skipForward_button);
			this->function_panel->Controls->Add(this->previous_button);
			this->function_panel->Controls->Add(this->skipBackward_button);
			this->function_panel->Controls->Add(this->next_button);
			this->function_panel->Controls->Add(this->pause_button);
			this->function_panel->Controls->Add(this->play_button);
			this->function_panel->Location = System::Drawing::Point(0, 456);
			this->function_panel->Name = L"function_panel";
			this->function_panel->Size = System::Drawing::Size(971, 88);
			this->function_panel->TabIndex = 2;
			this->function_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::function_panel_Paint);
			// 
			// video_name
			// 
			this->video_name->AutoSize = true;
			this->video_name->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->video_name->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->video_name->Location = System::Drawing::Point(12, 32);
			this->video_name->Name = L"video_name";
			this->video_name->Size = System::Drawing::Size(124, 28);
			this->video_name->TabIndex = 9;
			this->video_name->Text = L"video_name";
			this->video_name->Click += gcnew System::EventHandler(this, &MyForm::video_name_Click);
			// 
			// skipForward_button
			// 
			this->skipForward_button->FlatAppearance->BorderSize = 0;
			this->skipForward_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->skipForward_button->ForeColor = System::Drawing::Color::White;
			this->skipForward_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"skipForward_button.Image")));
			this->skipForward_button->Location = System::Drawing::Point(751, 32);
			this->skipForward_button->Name = L"skipForward_button";
			this->skipForward_button->Size = System::Drawing::Size(38, 44);
			this->skipForward_button->TabIndex = 8;
			this->skipForward_button->UseVisualStyleBackColor = true;
			this->skipForward_button->Click += gcnew System::EventHandler(this, &MyForm::skipForward_button_Click);
			// 
			// previous_button
			// 
			this->previous_button->FlatAppearance->BorderSize = 0;
			this->previous_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->previous_button->ForeColor = System::Drawing::Color::White;
			this->previous_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"previous_button.Image")));
			this->previous_button->Location = System::Drawing::Point(394, 27);
			this->previous_button->Name = L"previous_button";
			this->previous_button->Size = System::Drawing::Size(36, 38);
			this->previous_button->TabIndex = 7;
			this->previous_button->UseVisualStyleBackColor = true;
			this->previous_button->Click += gcnew System::EventHandler(this, &MyForm::previous_button_Click);
			// 
			// skipBackward_button
			// 
			this->skipBackward_button->FlatAppearance->BorderSize = 0;
			this->skipBackward_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->skipBackward_button->ForeColor = System::Drawing::Color::White;
			this->skipBackward_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"skipBackward_button.Image")));
			this->skipBackward_button->Location = System::Drawing::Point(700, 32);
			this->skipBackward_button->Name = L"skipBackward_button";
			this->skipBackward_button->Size = System::Drawing::Size(38, 44);
			this->skipBackward_button->TabIndex = 4;
			this->skipBackward_button->UseVisualStyleBackColor = true;
			this->skipBackward_button->Click += gcnew System::EventHandler(this, &MyForm::skipBackward_button_Click);
			// 
			// next_button
			// 
			this->next_button->FlatAppearance->BorderSize = 0;
			this->next_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->next_button->ForeColor = System::Drawing::Color::White;
			this->next_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"next_button.Image")));
			this->next_button->Location = System::Drawing::Point(534, 27);
			this->next_button->Name = L"next_button";
			this->next_button->Size = System::Drawing::Size(36, 38);
			this->next_button->TabIndex = 2;
			this->next_button->UseVisualStyleBackColor = true;
			this->next_button->Click += gcnew System::EventHandler(this, &MyForm::next_button_Click);
			// 
			// pause_button
			// 
			this->pause_button->FlatAppearance->BorderSize = 0;
			this->pause_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->pause_button->ForeColor = System::Drawing::Color::White;
			this->pause_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pause_button.Image")));
			this->pause_button->Location = System::Drawing::Point(456, 23);
			this->pause_button->Name = L"pause_button";
			this->pause_button->Size = System::Drawing::Size(47, 47);
			this->pause_button->TabIndex = 1;
			this->pause_button->UseVisualStyleBackColor = true;
			this->pause_button->Click += gcnew System::EventHandler(this, &MyForm::pause_button_Click);
			// 
			// play_button
			// 
			this->play_button->FlatAppearance->BorderSize = 0;
			this->play_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->play_button->ForeColor = System::Drawing::Color::White;
			this->play_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"play_button.Image")));
			this->play_button->Location = System::Drawing::Point(456, 23);
			this->play_button->Name = L"play_button";
			this->play_button->Size = System::Drawing::Size(47, 47);
			this->play_button->TabIndex = 0;
			this->play_button->UseVisualStyleBackColor = true;
			this->play_button->Click += gcnew System::EventHandler(this, &MyForm::play_button_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(971, 544);
			this->Controls->Add(this->function_panel);
			this->Controls->Add(this->player);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->EndInit();
			this->function_panel->ResumeLayout(false);
			this->function_panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void player_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void skipBackward_button_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void next_button_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void play_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Toggle visibility: Show Pause button, hide Play button
		play_button->Visible = false;
		pause_button->Visible = true;

		// Set the isPlaying state to true
		isPlaying = true;
	}
	private: System::Void pause_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Toggle visibility: Show Play button, hide Pause button
		pause_button->Visible = false;
		play_button->Visible = true;

		// Set the isPlaying state to false
		isPlaying = false;
	}
	private: System::Void function_panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void previous_button_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void skipForward_button_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void video_name_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
