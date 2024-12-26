#pragma once
#include "VideoList.h"

namespace MediaPlayerMIU 
{

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

	private:VideoList^ videoList;
	private: bool isPlaying = false;  // Boolean to track the state (play/pause)
	private: cli::array<String^>^ paths;
	private: System::Windows::Forms::ListBox^ track_list;
	private: System::Windows::Forms::Label^ statusLabel;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Label^ starttimer;

	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ endtimer;



	private: System::Windows::Forms::TrackBar^ soundBar;
	private: System::Windows::Forms::Label^ soundLabel;
	private: System::Windows::Forms::Button^ soundButton;
	private: System::Windows::Forms::Button^ muteButton;
	private: System::Windows::Forms::Button^ progressBarButton;








	private: cli::array<String^>^ files;

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
	private: System::Windows::Forms::Button^ upload_button;
	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->player = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->function_panel = (gcnew System::Windows::Forms::Panel());
			this->progressBarButton = (gcnew System::Windows::Forms::Button());
			this->muteButton = (gcnew System::Windows::Forms::Button());
			this->soundButton = (gcnew System::Windows::Forms::Button());
			this->soundLabel = (gcnew System::Windows::Forms::Label());
			this->soundBar = (gcnew System::Windows::Forms::TrackBar());
			this->endtimer = (gcnew System::Windows::Forms::Label());
			this->starttimer = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->upload_button = (gcnew System::Windows::Forms::Button());
			this->video_name = (gcnew System::Windows::Forms::Label());
			this->skipForward_button = (gcnew System::Windows::Forms::Button());
			this->previous_button = (gcnew System::Windows::Forms::Button());
			this->skipBackward_button = (gcnew System::Windows::Forms::Button());
			this->next_button = (gcnew System::Windows::Forms::Button());
			this->pause_button = (gcnew System::Windows::Forms::Button());
			this->play_button = (gcnew System::Windows::Forms::Button());
			this->track_list = (gcnew System::Windows::Forms::ListBox());
			this->statusLabel = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->BeginInit();
			this->function_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soundBar))->BeginInit();
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
			this->player->Size = System::Drawing::Size(1924, 1012);
			this->player->TabIndex = 0;
			this->player->Enter += gcnew System::EventHandler(this, &MyForm::player_Enter);
			// 
			// function_panel
			// 
			this->function_panel->AutoSize = true;
			this->function_panel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->function_panel->BackColor = System::Drawing::Color::DimGray;
			this->function_panel->Controls->Add(this->progressBarButton);
			this->function_panel->Controls->Add(this->muteButton);
			this->function_panel->Controls->Add(this->soundButton);
			this->function_panel->Controls->Add(this->soundLabel);
			this->function_panel->Controls->Add(this->soundBar);
			this->function_panel->Controls->Add(this->endtimer);
			this->function_panel->Controls->Add(this->starttimer);
			this->function_panel->Controls->Add(this->progressBar1);
			this->function_panel->Controls->Add(this->upload_button);
			this->function_panel->Controls->Add(this->video_name);
			this->function_panel->Controls->Add(this->skipForward_button);
			this->function_panel->Controls->Add(this->previous_button);
			this->function_panel->Controls->Add(this->skipBackward_button);
			this->function_panel->Controls->Add(this->next_button);
			this->function_panel->Controls->Add(this->pause_button);
			this->function_panel->Controls->Add(this->play_button);
			this->function_panel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->function_panel->Location = System::Drawing::Point(0, 814);
			this->function_panel->Margin = System::Windows::Forms::Padding(4);
			this->function_panel->Name = L"function_panel";
			this->function_panel->Size = System::Drawing::Size(1924, 198);
			this->function_panel->TabIndex = 2;
			this->function_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::function_panel_Paint);
			// 
			// progressBarButton
			// 
			this->progressBarButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->progressBarButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->progressBarButton->BackColor = System::Drawing::Color::Transparent;
			this->progressBarButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->progressBarButton->FlatAppearance->BorderSize = 0;
			this->progressBarButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->progressBarButton->ForeColor = System::Drawing::Color::White;
			this->progressBarButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"progressBarButton.Image")));
			this->progressBarButton->Location = System::Drawing::Point(85, 16);
			this->progressBarButton->Margin = System::Windows::Forms::Padding(0);
			this->progressBarButton->Name = L"progressBarButton";
			this->progressBarButton->Size = System::Drawing::Size(27, 22);
			this->progressBarButton->TabIndex = 20;
			this->progressBarButton->UseVisualStyleBackColor = false;
			// 
			// muteButton
			// 
			this->muteButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->muteButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->muteButton->BackColor = System::Drawing::Color::DimGray;
			this->muteButton->FlatAppearance->BorderSize = 0;
			this->muteButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->muteButton->ForeColor = System::Drawing::Color::White;
			this->muteButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"muteButton.Image")));
			this->muteButton->Location = System::Drawing::Point(35, 82);
			this->muteButton->Margin = System::Windows::Forms::Padding(4);
			this->muteButton->Name = L"muteButton";
			this->muteButton->Size = System::Drawing::Size(69, 30);
			this->muteButton->TabIndex = 19;
			this->muteButton->UseVisualStyleBackColor = false;
			this->muteButton->Visible = false;
			this->muteButton->Click += gcnew System::EventHandler(this, &MyForm::muteButton_Click);
			// 
			// soundButton
			// 
			this->soundButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->soundButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->soundButton->BackColor = System::Drawing::Color::Transparent;
			this->soundButton->FlatAppearance->BorderSize = 0;
			this->soundButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->soundButton->ForeColor = System::Drawing::Color::White;
			this->soundButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"soundButton.Image")));
			this->soundButton->Location = System::Drawing::Point(131, 132);
			this->soundButton->Margin = System::Windows::Forms::Padding(4);
			this->soundButton->Name = L"soundButton";
			this->soundButton->Size = System::Drawing::Size(40, 40);
			this->soundButton->TabIndex = 18;
			this->soundButton->UseVisualStyleBackColor = false;
			this->soundButton->Click += gcnew System::EventHandler(this, &MyForm::soundButton_Click);
			// 
			// soundLabel
			// 
			this->soundLabel->AutoSize = true;
			this->soundLabel->BackColor = System::Drawing::Color::Transparent;
			this->soundLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->soundLabel->Location = System::Drawing::Point(240, 88);
			this->soundLabel->Name = L"soundLabel";
			this->soundLabel->Size = System::Drawing::Size(26, 18);
			this->soundLabel->TabIndex = 17;
			this->soundLabel->Text = L"50";
			this->soundLabel->Visible = false;
			this->soundLabel->Click += gcnew System::EventHandler(this, &MyForm::soundLabel_Click);
			// 
			// soundBar
			// 
			this->soundBar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->soundBar->Location = System::Drawing::Point(98, 83);
			this->soundBar->Maximum = 100;
			this->soundBar->Name = L"soundBar";
			this->soundBar->Size = System::Drawing::Size(145, 56);
			this->soundBar->TabIndex = 16;
			this->soundBar->Value = 50;
			this->soundBar->Visible = false;
			this->soundBar->Scroll += gcnew System::EventHandler(this, &MyForm::soundBar_Scroll);
			// 
			// endtimer
			// 
			this->endtimer->AutoSize = true;
			this->endtimer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->endtimer->Location = System::Drawing::Point(1867, 17);
			this->endtimer->Name = L"endtimer";
			this->endtimer->Size = System::Drawing::Size(49, 18);
			this->endtimer->TabIndex = 14;
			this->endtimer->Text = L"00:00";
			// 
			// starttimer
			// 
			this->starttimer->AutoSize = true;
			this->starttimer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->starttimer->Location = System::Drawing::Point(23, 17);
			this->starttimer->Name = L"starttimer";
			this->starttimer->Size = System::Drawing::Size(49, 18);
			this->starttimer->TabIndex = 13;
			this->starttimer->Text = L"00:00";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(85, 23);
			this->progressBar1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(1779, 7);
			this->progressBar1->TabIndex = 12;
			this->progressBar1->Click += gcnew System::EventHandler(this, &MyForm::progressBar1_Click);
			// 
			// upload_button
			// 
			this->upload_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->upload_button->AutoSize = true;
			this->upload_button->FlatAppearance->BorderSize = 0;
			this->upload_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->upload_button->ForeColor = System::Drawing::Color::White;
			this->upload_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"upload_button.Image")));
			this->upload_button->Location = System::Drawing::Point(1823, 106);
			this->upload_button->Margin = System::Windows::Forms::Padding(4);
			this->upload_button->Name = L"upload_button";
			this->upload_button->Size = System::Drawing::Size(61, 57);
			this->upload_button->TabIndex = 11;
			this->upload_button->UseVisualStyleBackColor = true;
			this->upload_button->Click += gcnew System::EventHandler(this, &MyForm::upload_button_Click);
			// 
			// video_name
			// 
			this->video_name->AutoSize = true;
			this->video_name->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->video_name->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->video_name->Location = System::Drawing::Point(16, 39);
			this->video_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->video_name->Name = L"video_name";
			this->video_name->Size = System::Drawing::Size(155, 35);
			this->video_name->TabIndex = 9;
			this->video_name->Text = L"video_name";
			this->video_name->Click += gcnew System::EventHandler(this, &MyForm::video_name_Click);
			// 
			// skipForward_button
			// 
			this->skipForward_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->skipForward_button->AutoSize = true;
			this->skipForward_button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->skipForward_button->FlatAppearance->BorderSize = 0;
			this->skipForward_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->skipForward_button->ForeColor = System::Drawing::Color::White;
			this->skipForward_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"skipForward_button.Image")));
			this->skipForward_button->Location = System::Drawing::Point(1644, 121);
			this->skipForward_button->Margin = System::Windows::Forms::Padding(4);
			this->skipForward_button->Name = L"skipForward_button";
			this->skipForward_button->Size = System::Drawing::Size(46, 46);
			this->skipForward_button->TabIndex = 8;
			this->skipForward_button->UseVisualStyleBackColor = true;
			this->skipForward_button->Click += gcnew System::EventHandler(this, &MyForm::skipForward_button_Click);
			// 
			// previous_button
			// 
			this->previous_button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->previous_button->AutoSize = true;
			this->previous_button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->previous_button->FlatAppearance->BorderSize = 0;
			this->previous_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->previous_button->ForeColor = System::Drawing::Color::White;
			this->previous_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"previous_button.Image")));
			this->previous_button->Location = System::Drawing::Point(843, 125);
			this->previous_button->Margin = System::Windows::Forms::Padding(4);
			this->previous_button->Name = L"previous_button";
			this->previous_button->Size = System::Drawing::Size(31, 31);
			this->previous_button->TabIndex = 7;
			this->previous_button->UseVisualStyleBackColor = true;
			this->previous_button->Click += gcnew System::EventHandler(this, &MyForm::previous_button_Click);
			// 
			// skipBackward_button
			// 
			this->skipBackward_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->skipBackward_button->AutoSize = true;
			this->skipBackward_button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->skipBackward_button->FlatAppearance->BorderSize = 0;
			this->skipBackward_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->skipBackward_button->ForeColor = System::Drawing::Color::White;
			this->skipBackward_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"skipBackward_button.Image")));
			this->skipBackward_button->Location = System::Drawing::Point(1576, 121);
			this->skipBackward_button->Margin = System::Windows::Forms::Padding(4);
			this->skipBackward_button->Name = L"skipBackward_button";
			this->skipBackward_button->Size = System::Drawing::Size(46, 46);
			this->skipBackward_button->TabIndex = 4;
			this->skipBackward_button->UseVisualStyleBackColor = true;
			this->skipBackward_button->Click += gcnew System::EventHandler(this, &MyForm::skipBackward_button_Click);
			// 
			// next_button
			// 
			this->next_button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->next_button->AutoSize = true;
			this->next_button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->next_button->FlatAppearance->BorderSize = 0;
			this->next_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->next_button->ForeColor = System::Drawing::Color::White;
			this->next_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"next_button.Image")));
			this->next_button->Location = System::Drawing::Point(1035, 122);
			this->next_button->Margin = System::Windows::Forms::Padding(4);
			this->next_button->Name = L"next_button";
			this->next_button->Size = System::Drawing::Size(31, 31);
			this->next_button->TabIndex = 2;
			this->next_button->UseVisualStyleBackColor = true;
			this->next_button->Click += gcnew System::EventHandler(this, &MyForm::next_button_Click);
			// 
			// pause_button
			// 
			this->pause_button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->pause_button->AutoSize = true;
			this->pause_button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->pause_button->FlatAppearance->BorderSize = 0;
			this->pause_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->pause_button->ForeColor = System::Drawing::Color::White;
			this->pause_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pause_button.Image")));
			this->pause_button->Location = System::Drawing::Point(923, 118);
			this->pause_button->Margin = System::Windows::Forms::Padding(4);
			this->pause_button->Name = L"pause_button";
			this->pause_button->Size = System::Drawing::Size(54, 54);
			this->pause_button->TabIndex = 1;
			this->pause_button->UseVisualStyleBackColor = true;
			this->pause_button->Click += gcnew System::EventHandler(this, &MyForm::pause_button_Click);
			// 
			// play_button
			// 
			this->play_button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->play_button->AutoSize = true;
			this->play_button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->play_button->FlatAppearance->BorderSize = 0;
			this->play_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->play_button->ForeColor = System::Drawing::Color::White;
			this->play_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"play_button.Image")));
			this->play_button->Location = System::Drawing::Point(923, 116);
			this->play_button->Margin = System::Windows::Forms::Padding(4);
			this->play_button->Name = L"play_button";
			this->play_button->Size = System::Drawing::Size(54, 54);
			this->play_button->TabIndex = 0;
			this->play_button->UseVisualStyleBackColor = true;
			this->play_button->Click += gcnew System::EventHandler(this, &MyForm::play_button_Click);
			// 
			// track_list
			// 
			this->track_list->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->track_list->FormattingEnabled = true;
			this->track_list->ItemHeight = 16;
			this->track_list->Location = System::Drawing::Point(1609, 37);
			this->track_list->Margin = System::Windows::Forms::Padding(4);
			this->track_list->Name = L"track_list";
			this->track_list->Size = System::Drawing::Size(297, 196);
			this->track_list->TabIndex = 3;
			this->track_list->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::track_list_SelectedIndexChanged);
			// 
			// statusLabel
			// 
			this->statusLabel->AutoSize = true;
			this->statusLabel->Location = System::Drawing::Point(60, 37);
			this->statusLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Size = System::Drawing::Size(44, 16);
			this->statusLabel->TabIndex = 4;
			this->statusLabel->Text = L"label1";
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1012);
			this->Controls->Add(this->statusLabel);
			this->Controls->Add(this->track_list);
			this->Controls->Add(this->function_panel);
			this->Controls->Add(this->player);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->EndInit();
			this->function_panel->ResumeLayout(false);
			this->function_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soundBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		//Intialize
		videoList = gcnew VideoList(); 

		// Assert it doesn't equal null
		assert(videoList != nullptr);

	}
	private: System::Void player_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void skipBackward_button_Click(System::Object^ sender, System::EventArgs^ e) {
		double currentPosition = player->Ctlcontrols->currentPosition;     // Get the current position of the player

		player->Ctlcontrols->currentPosition = currentPosition - 15;     // Set the new position
	}
	private: System::Void next_button_Click(System::Object^ sender, System::EventArgs^ e){
		
		// Ensure the VideoList is not empty
		if (!videoList->isEmpty())
		{
			// Switch to the next video in the list
			String^ nextVideoPath = videoList->nextVideo();

			if (nextVideoPath != nullptr)
			{
				// Update the ListBox's selected index to reflect the new current node
				int newIndex = videoList->getCurrentNodeIndex();
				track_list->SelectedIndex = newIndex;

				// Optionally, start playing the new video
				// mediaPlayer->URL = nextVideoPath; // Replace with your media player logic
			}
		}
		
	}
	private: System::Void play_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Toggle visibility: Show Pause button, hide Play button
		play_button->Visible = false;
		pause_button->Visible = true;

		// Set the isPlaying state to true
		player->Ctlcontrols->play();
		isPlaying = true;

		

	}
	private: System::Void pause_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Toggle visibility: Show Play button, hide Pause button
		pause_button->Visible = false;
		play_button->Visible = true;

		// Set the isPlaying state to false
		player->Ctlcontrols->pause();
		isPlaying = false;
		
	}
	private: System::Void function_panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}


	private: System::Void previous_button_Click(System::Object^ sender, System::EventArgs^ e) {
		// Ensure the VideoList is not empty
		if (!videoList->isEmpty())
		{
			// Switch to the next video in the list
			String^ prevVideoPath = videoList->prevVideo();

			if (prevVideoPath != nullptr)
			{
				// Update the ListBox's selected index to reflect the new current node
				int newIndex = videoList->getCurrentNodeIndex();
				track_list->SelectedIndex = newIndex;

				// Optionally, start playing the new video
				// mediaPlayer->URL = nextVideoPath; // Replace with your media player logic
			}
		}
	}


	private: System::Void skipForward_button_Click(System::Object^ sender, System::EventArgs^ e) {
		double currentPosition = player->Ctlcontrols->currentPosition;     // Get the current position of the player

		player->Ctlcontrols->currentPosition = currentPosition + 15;     // Set the new position
	}
	private: System::Void video_name_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	// Added function that opens file explorer to select videos.
	private: System::Void upload_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Multiselect = true;

		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			// What' the difference between both?
			files = ofd->SafeFileNames; // Video Name
			paths = ofd->FileNames; // PATH to Video

			for (int x = 0; x < files->Length; x++)
			{
				// Then add the video into list for implementation
				videoList->addVideo(paths[x], files[x]); // Add URL to VideoList;
			}

			// Use the VideoList method to populate the track list
			videoList->populateTrackList(track_list);
		}
	}

	private: System::Void track_list_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		// To make code more readable
		int selectedIndex = track_list->SelectedIndex;

		// Simplified it + now only the videoList's size should be checked.
		if (selectedIndex >= 0 && selectedIndex < videoList->getSize())
		{
			// Set the current node in VideoList to match the selected track
			videoList->setCurrentNode(selectedIndex);

			// Update the player's URL to the currently selected video's path
			player->URL = videoList->getCurrentNodePath();

			// Start the video
			player->Ctlcontrols->play();

			// Set the video name label to be the video's name through the "files" array that holds video names
			video_name->Text = videoList->getCurrentNodeName();

			// Switch Icon for pause and play
			play_button->Visible = false;
			pause_button->Visible = true;

			// Set the isPlaying flag to be true
			isPlaying = true;

			// Switch status label for design
			statusLabel->Text = "Playing...";

			// Most importantly, start timer for a working progress bar.
			timer->Start();
		}
	}

	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		// Ensure the player is in a playing state
		if (player->playState == WMPLib::WMPPlayState::wmppsPlaying)
		{
			// Update the progress bar's maximum and current value
			progressBar1->Maximum = (int)player->Ctlcontrols->currentItem->duration;
			progressBar1->Value = (int)player->Ctlcontrols->currentPosition;

			// Update the position of the progressBarButton to follow the progress bar
			if (player->Ctlcontrols->currentItem->duration > 0)
			{
				// Calculate the button's position based on the current playback percentage
				double percentage = player->Ctlcontrols->currentPosition / player->Ctlcontrols->currentItem->duration;
				int buttonX = (int)(percentage * progressBar1->Width) - (progressBarButton->Width / 2);

				// Ensure the button stays within the bounds of the progress bar
				if (buttonX < 0) buttonX = 0;
				if (buttonX > progressBar1->Width - progressBarButton->Width)
					buttonX = progressBar1->Width - progressBarButton->Width;

				progressBarButton->Left = progressBar1->Left + buttonX;
			}
		}

		// Update the start and end timers
		starttimer->Text = player->Ctlcontrols->currentPositionString;
		endtimer->Text = player->Ctlcontrols->currentItem->durationString->ToString();
	}


	private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Get the mouse position relative to the progress bar
		System::Drawing::Point mousePosition = progressBar1->PointToClient(Cursor->Position);

		// Calculate the percentage of the clicked position relative to the progress bar's width
		double percentage = (double)mousePosition.X / progressBar1->Width;

		// Ensure the percentage is within valid bounds
		if (percentage < 0) percentage = 0;
		if (percentage > 1) percentage = 1;

		// Map the percentage to the video's total duration
		double videoDuration = player->currentMedia->duration; // Assuming 'duration' is in seconds
		double newPosition = percentage * videoDuration;

		// Set the video's new playback position
		player->Ctlcontrols->currentPosition = newPosition;

		// Update the progress bar value
		progressBar1->Value = (int)(percentage * progressBar1->Maximum);
	}


	   /*EVEN HANDLING OF SHUFFLE
	   videoList->shuffle();
               String^ shuffledVideo = videoList->getCurrentVideo();
		player->Ctlcontrols->play();
		isPlaying = true;

		if (paths != nullptr && track_list->SelectedIndex >= 0)
		{
			video_name->Text = files[track_list->SelectedIndex];
		}
		else
		{
			video_name->Text = "No video selected";
		}
	   */

private: System::Void soundButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (soundBar->Visible && soundLabel->Visible) {
		muteButton->Hide();
		soundBar->Hide();
		soundLabel->Hide();
	}
	else {
		muteButton->Show();
		soundBar->Show();
		soundLabel->Show();
	}
}
private: System::Void soundBar_Scroll(System::Object^ sender, System::EventArgs^ e) {
	player->settings->volume = soundBar->Value;
	soundLabel->Text = soundBar->Value.ToString();
}
private: System::Void soundLabel_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void muteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (soundBar->Value > 0) {
		player->settings->volume = 0;
		soundBar->Value = 0;
		soundLabel->Text = soundBar->Value.ToString();
	}
	else {
		player->settings->volume = 50;
		soundBar->Value = 50;
		soundLabel->Text = soundBar->Value.ToString();
	}
	
}

};
}
