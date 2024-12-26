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
			this->SuspendLayout();
			// 
			// player
			// 
			this->player->Dock = System::Windows::Forms::DockStyle::Fill;
			this->player->Enabled = true;
			this->player->Location = System::Drawing::Point(0, 0);
			this->player->Name = L"player";
			this->player->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"player.OcxState")));
			this->player->Size = System::Drawing::Size(1443, 822);
			this->player->TabIndex = 0;
			this->player->Enter += gcnew System::EventHandler(this, &MyForm::player_Enter);
			// 
			// function_panel
			// 
			this->function_panel->AutoSize = true;
			this->function_panel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->function_panel->BackColor = System::Drawing::Color::DimGray;
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
			this->function_panel->Location = System::Drawing::Point(0, 671);
			this->function_panel->Name = L"function_panel";
			this->function_panel->Size = System::Drawing::Size(1443, 151);
			this->function_panel->TabIndex = 2;
			this->function_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::function_panel_Paint);
			// 
			// endtimer
			// 
			this->endtimer->AutoSize = true;
			this->endtimer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->endtimer->Location = System::Drawing::Point(1400, 14);
			this->endtimer->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->endtimer->Name = L"endtimer";
			this->endtimer->Size = System::Drawing::Size(43, 15);
			this->endtimer->TabIndex = 14;
			this->endtimer->Text = L"00:00";
			// 
			// starttimer
			// 
			this->starttimer->AutoSize = true;
			this->starttimer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->starttimer->Location = System::Drawing::Point(17, 14);
			this->starttimer->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->starttimer->Name = L"starttimer";
			this->starttimer->Size = System::Drawing::Size(43, 15);
			this->starttimer->TabIndex = 13;
			this->starttimer->Text = L"00:00";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(64, 19);
			this->progressBar1->Margin = System::Windows::Forms::Padding(2);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(1334, 6);
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
			this->upload_button->Location = System::Drawing::Point(1367, 76);
			this->upload_button->Name = L"upload_button";
			this->upload_button->Size = System::Drawing::Size(46, 46);
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
			this->video_name->Location = System::Drawing::Point(12, 32);
			this->video_name->Name = L"video_name";
			this->video_name->Size = System::Drawing::Size(124, 28);
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
			this->skipForward_button->Location = System::Drawing::Point(1222, 80);
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
			this->previous_button->Location = System::Drawing::Point(632, 86);
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
			this->skipBackward_button->Location = System::Drawing::Point(1171, 80);
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
			this->next_button->Location = System::Drawing::Point(776, 84);
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
			this->pause_button->Location = System::Drawing::Point(692, 76);
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
			this->play_button->Location = System::Drawing::Point(692, 75);
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
			this->track_list->Location = System::Drawing::Point(1207, 30);
			this->track_list->Name = L"track_list";
			this->track_list->Size = System::Drawing::Size(224, 160);
			this->track_list->TabIndex = 3;
			this->track_list->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::track_list_SelectedIndexChanged);
			// 
			// statusLabel
			// 
			this->statusLabel->AutoSize = true;
			this->statusLabel->Location = System::Drawing::Point(45, 30);
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Size = System::Drawing::Size(35, 13);
			this->statusLabel->TabIndex = 4;
			this->statusLabel->Text = L"label1";
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1443, 822);
			this->Controls->Add(this->statusLabel);
			this->Controls->Add(this->track_list);
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
	private: System::Void next_button_Click(System::Object^ sender, System::EventArgs^ e) {
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
		
		if (player->playState == WMPLib::WMPPlayState::wmppsPlaying)
		{
			progressBar1->Maximum = (int)player->Ctlcontrols->currentItem->duration;
			progressBar1->Value = (int)player->Ctlcontrols->currentPosition;
		}

		starttimer->Text = player->Ctlcontrols->currentPositionString;
		endtimer->Text = player->Ctlcontrols->currentItem->durationString->ToString();
		
	}

	private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e)
	{
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
};
}
