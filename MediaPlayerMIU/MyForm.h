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
	private: bool isLooped = false;
	private: bool mainSceneVisible = true;
	private: cli::array<String^>^ paths;
	private: System::Windows::Forms::ListBox^ track_list;
	private: System::Windows::Forms::Label^ statusLabel;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Label^ starttimer;

	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ endtimer;

	private: System::Windows::Forms::Button^ shuffle_button;



	private: System::Windows::Forms::TrackBar^ soundBar;
	private: System::Windows::Forms::Label^ soundLabel;
	private: System::Windows::Forms::Button^ soundButton;
	private: System::Windows::Forms::Button^ muteButton;
	private: System::Windows::Forms::Button^ progressBarButton;
	private: System::Windows::Forms::Button^ switch_button;
	private: System::Windows::Forms::Button^ front_button;
	private: int previousVolume = 50; //to store volume value
	private: System::Windows::Forms::Button^ deleteButton;
	private: System::Windows::Forms::Button^ speedButton;
	private: System::Windows::Forms::Button^ speed2;
	private: System::Windows::Forms::Button^ speed175;
	private: System::Windows::Forms::Button^ speed125;




	private: System::Windows::Forms::Button^ speed15;
	private: System::Windows::Forms::Button^ speed25;


	private: System::Windows::Forms::Button^ speed5;

	private: System::Windows::Forms::Button^ speed75;

	private: System::Windows::Forms::Button^ speed1;
	private: System::Windows::Forms::Button^ repeatButton;
	private: System::Windows::Forms::GroupBox^ speedOptions;
	private: System::Windows::Forms::Button^ no_repeat_button;
	private: AxWMPLib::AxWindowsMediaPlayer^ player;

















	private: cli::array<String^>^ files;

	public:
		MyForm(void)
		{
			InitializeComponent();

			// This makes the WMP's built-in functionality hidden
			this->player->uiMode = L"none";  // This hides all UI elements like play/pause buttons

			// Initially, the Play button is visible and enabled, while the Pause button is hidden
			play_button->Visible = true;
			pause_button->Visible = false;

			// Initially, the repeat button is visible and enabled, while the no-repeat button is hidden
			repeatButton->Visible = true;
			no_repeat_button->Visible = false;

			// Set the speed options to be invisible at first
			speedOptions->Visible = false;
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
			this->function_panel = (gcnew System::Windows::Forms::Panel());
			this->no_repeat_button = (gcnew System::Windows::Forms::Button());
			this->repeatButton = (gcnew System::Windows::Forms::Button());
			this->speedButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->progressBarButton = (gcnew System::Windows::Forms::Button());
			this->muteButton = (gcnew System::Windows::Forms::Button());
			this->soundButton = (gcnew System::Windows::Forms::Button());
			this->soundLabel = (gcnew System::Windows::Forms::Label());
			this->soundBar = (gcnew System::Windows::Forms::TrackBar());
			this->shuffle_button = (gcnew System::Windows::Forms::Button());
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
			this->speed25 = (gcnew System::Windows::Forms::Button());
			this->speed5 = (gcnew System::Windows::Forms::Button());
			this->speed75 = (gcnew System::Windows::Forms::Button());
			this->speed1 = (gcnew System::Windows::Forms::Button());
			this->speed125 = (gcnew System::Windows::Forms::Button());
			this->speed15 = (gcnew System::Windows::Forms::Button());
			this->speed175 = (gcnew System::Windows::Forms::Button());
			this->speed2 = (gcnew System::Windows::Forms::Button());
			this->track_list = (gcnew System::Windows::Forms::ListBox());
			this->statusLabel = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->switch_button = (gcnew System::Windows::Forms::Button());
			this->front_button = (gcnew System::Windows::Forms::Button());
			this->speedOptions = (gcnew System::Windows::Forms::GroupBox());
			this->player = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->function_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soundBar))->BeginInit();
			this->speedOptions->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->BeginInit();
			this->SuspendLayout();
			// 
			// function_panel
			// 
			this->function_panel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->function_panel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->function_panel->BackColor = System::Drawing::Color::DimGray;
			this->function_panel->Controls->Add(this->no_repeat_button);
			this->function_panel->Controls->Add(this->repeatButton);
			this->function_panel->Controls->Add(this->speedButton);
			this->function_panel->Controls->Add(this->deleteButton);
			this->function_panel->Controls->Add(this->progressBarButton);
			this->function_panel->Controls->Add(this->muteButton);
			this->function_panel->Controls->Add(this->soundButton);
			this->function_panel->Controls->Add(this->soundLabel);
			this->function_panel->Controls->Add(this->soundBar);
			this->function_panel->Controls->Add(this->shuffle_button);
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
			this->function_panel->Location = System::Drawing::Point(-2, 594);
			this->function_panel->Name = L"function_panel";
			this->function_panel->Size = System::Drawing::Size(1039, 169);
			this->function_panel->TabIndex = 2;
			this->function_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::function_panel_Paint);
			// 
			// no_repeat_button
			// 
			this->no_repeat_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->no_repeat_button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->no_repeat_button->BackColor = System::Drawing::Color::DimGray;
			this->no_repeat_button->FlatAppearance->BorderSize = 0;
			this->no_repeat_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->no_repeat_button->ForeColor = System::Drawing::SystemColors::Window;
			this->no_repeat_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"no_repeat_button.Image")));
			this->no_repeat_button->Location = System::Drawing::Point(646, 102);
			this->no_repeat_button->Margin = System::Windows::Forms::Padding(2);
			this->no_repeat_button->Name = L"no_repeat_button";
			this->no_repeat_button->Size = System::Drawing::Size(42, 23);
			this->no_repeat_button->TabIndex = 32;
			this->no_repeat_button->UseVisualStyleBackColor = false;
			this->no_repeat_button->Click += gcnew System::EventHandler(this, &MyForm::no_repeat_button_Click);
			// 
			// repeatButton
			// 
			this->repeatButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->repeatButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->repeatButton->BackColor = System::Drawing::Color::DimGray;
			this->repeatButton->FlatAppearance->BorderSize = 0;
			this->repeatButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->repeatButton->ForeColor = System::Drawing::SystemColors::Window;
			this->repeatButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"repeatButton.Image")));
			this->repeatButton->Location = System::Drawing::Point(646, 98);
			this->repeatButton->Margin = System::Windows::Forms::Padding(2);
			this->repeatButton->Name = L"repeatButton";
			this->repeatButton->Size = System::Drawing::Size(42, 29);
			this->repeatButton->TabIndex = 31;
			this->repeatButton->UseVisualStyleBackColor = false;
			this->repeatButton->Click += gcnew System::EventHandler(this, &MyForm::repeatButton_Click);
			// 
			// speedButton
			// 
			this->speedButton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->speedButton->AutoSize = true;
			this->speedButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->speedButton->FlatAppearance->BorderSize = 0;
			this->speedButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->speedButton->ForeColor = System::Drawing::Color::White;
			this->speedButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"speedButton.Image")));
			this->speedButton->Location = System::Drawing::Point(241, 83);
			this->speedButton->Name = L"speedButton";
			this->speedButton->Size = System::Drawing::Size(54, 54);
			this->speedButton->TabIndex = 22;
			this->speedButton->UseVisualStyleBackColor = true;
			this->speedButton->Click += gcnew System::EventHandler(this, &MyForm::speedButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->deleteButton->AutoSize = true;
			this->deleteButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->deleteButton->FlatAppearance->BorderSize = 0;
			this->deleteButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteButton->ForeColor = System::Drawing::Color::White;
			this->deleteButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deleteButton.Image")));
			this->deleteButton->Location = System::Drawing::Point(45, 102);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(56, 56);
			this->deleteButton->TabIndex = 21;
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &MyForm::deleteButton_Click);
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
			this->progressBarButton->Location = System::Drawing::Point(81, 21);
			this->progressBarButton->Margin = System::Windows::Forms::Padding(0);
			this->progressBarButton->Name = L"progressBarButton";
			this->progressBarButton->Size = System::Drawing::Size(20, 18);
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
			this->muteButton->Location = System::Drawing::Point(794, 40);
			this->muteButton->Name = L"muteButton";
			this->muteButton->Size = System::Drawing::Size(47, 45);
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
			this->soundButton->Location = System::Drawing::Point(872, 94);
			this->soundButton->Name = L"soundButton";
			this->soundButton->Size = System::Drawing::Size(42, 35);
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
			this->soundLabel->Location = System::Drawing::Point(949, 58);
			this->soundLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->soundLabel->Name = L"soundLabel";
			this->soundLabel->Size = System::Drawing::Size(23, 15);
			this->soundLabel->TabIndex = 17;
			this->soundLabel->Text = L"50";
			this->soundLabel->Visible = false;
			this->soundLabel->Click += gcnew System::EventHandler(this, &MyForm::soundLabel_Click);
			// 
			// soundBar
			// 
			this->soundBar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->soundBar->Location = System::Drawing::Point(836, 48);
			this->soundBar->Margin = System::Windows::Forms::Padding(2);
			this->soundBar->Maximum = 100;
			this->soundBar->Name = L"soundBar";
			this->soundBar->Size = System::Drawing::Size(109, 45);
			this->soundBar->TabIndex = 16;
			this->soundBar->Value = 50;
			this->soundBar->Visible = false;
			this->soundBar->Scroll += gcnew System::EventHandler(this, &MyForm::soundBar_Scroll);
			// 
			// shuffle_button
			// 
			this->shuffle_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->shuffle_button->AutoSize = true;
			this->shuffle_button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->shuffle_button->FlatAppearance->BorderSize = 0;
			this->shuffle_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->shuffle_button->ForeColor = System::Drawing::Color::White;
			this->shuffle_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"shuffle_button.Image")));
			this->shuffle_button->Location = System::Drawing::Point(342, 93);
			this->shuffle_button->Margin = System::Windows::Forms::Padding(2);
			this->shuffle_button->Name = L"shuffle_button";
			this->shuffle_button->Size = System::Drawing::Size(36, 36);
			this->shuffle_button->TabIndex = 16;
			this->shuffle_button->UseVisualStyleBackColor = true;
			this->shuffle_button->Click += gcnew System::EventHandler(this, &MyForm::shuffle_button_Click);
			// 
			// endtimer
			// 
			this->endtimer->AutoSize = true;
			this->endtimer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->endtimer->Location = System::Drawing::Point(958, 19);
			this->endtimer->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->endtimer->Name = L"endtimer";
			this->endtimer->Size = System::Drawing::Size(55, 23);
			this->endtimer->TabIndex = 14;
			this->endtimer->Text = L"00:00";
			// 
			// starttimer
			// 
			this->starttimer->AutoSize = true;
			this->starttimer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->starttimer->Location = System::Drawing::Point(22, 19);
			this->starttimer->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->starttimer->Name = L"starttimer";
			this->starttimer->Size = System::Drawing::Size(55, 23);
			this->starttimer->TabIndex = 13;
			this->starttimer->Text = L"00:00";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(81, 25);
			this->progressBar1->Margin = System::Windows::Forms::Padding(2);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(867, 10);
			this->progressBar1->TabIndex = 12;
			this->progressBar1->Click += gcnew System::EventHandler(this, &MyForm::progressBar1_Click);
			// 
			// upload_button
			// 
			this->upload_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->upload_button->AutoSize = true;
			this->upload_button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->upload_button->FlatAppearance->BorderSize = 0;
			this->upload_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->upload_button->ForeColor = System::Drawing::Color::White;
			this->upload_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"upload_button.Image")));
			this->upload_button->Location = System::Drawing::Point(962, 87);
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
			this->video_name->Location = System::Drawing::Point(21, 54);
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
			this->skipForward_button->Location = System::Drawing::Point(783, 89);
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
			this->previous_button->Location = System::Drawing::Point(429, 94);
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
			this->skipBackward_button->Location = System::Drawing::Point(731, 89);
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
			this->next_button->Location = System::Drawing::Point(573, 95);
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
			this->pause_button->Location = System::Drawing::Point(490, 85);
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
			this->play_button->Location = System::Drawing::Point(490, 83);
			this->play_button->Name = L"play_button";
			this->play_button->Size = System::Drawing::Size(54, 54);
			this->play_button->TabIndex = 0;
			this->play_button->UseVisualStyleBackColor = true;
			this->play_button->Click += gcnew System::EventHandler(this, &MyForm::play_button_Click);
			// 
			// speed25
			// 
			this->speed25->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->speed25->AutoSize = true;
			this->speed25->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->speed25->FlatAppearance->BorderSize = 0;
			this->speed25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->speed25->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->speed25->ForeColor = System::Drawing::Color::White;
			this->speed25->Location = System::Drawing::Point(3, 208);
			this->speed25->Name = L"speed25";
			this->speed25->Size = System::Drawing::Size(48, 27);
			this->speed25->TabIndex = 30;
			this->speed25->Text = L"0.25x";
			this->speed25->UseVisualStyleBackColor = true;
			this->speed25->Click += gcnew System::EventHandler(this, &MyForm::speed25_Click);
			// 
			// speed5
			// 
			this->speed5->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->speed5->AutoSize = true;
			this->speed5->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->speed5->FlatAppearance->BorderSize = 0;
			this->speed5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->speed5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->speed5->ForeColor = System::Drawing::Color::White;
			this->speed5->Location = System::Drawing::Point(3, 179);
			this->speed5->Name = L"speed5";
			this->speed5->Size = System::Drawing::Size(41, 27);
			this->speed5->TabIndex = 29;
			this->speed5->Text = L"0.5x";
			this->speed5->UseVisualStyleBackColor = true;
			this->speed5->Click += gcnew System::EventHandler(this, &MyForm::speed5_Click);
			// 
			// speed75
			// 
			this->speed75->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->speed75->AutoSize = true;
			this->speed75->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->speed75->FlatAppearance->BorderSize = 0;
			this->speed75->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->speed75->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->speed75->ForeColor = System::Drawing::Color::White;
			this->speed75->Location = System::Drawing::Point(3, 150);
			this->speed75->Name = L"speed75";
			this->speed75->Size = System::Drawing::Size(48, 27);
			this->speed75->TabIndex = 28;
			this->speed75->Text = L"0.75x";
			this->speed75->UseVisualStyleBackColor = true;
			this->speed75->Click += gcnew System::EventHandler(this, &MyForm::speed75_Click);
			// 
			// speed1
			// 
			this->speed1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->speed1->AutoSize = true;
			this->speed1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->speed1->FlatAppearance->BorderSize = 0;
			this->speed1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->speed1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->speed1->ForeColor = System::Drawing::Color::White;
			this->speed1->Location = System::Drawing::Point(3, 121);
			this->speed1->Name = L"speed1";
			this->speed1->Size = System::Drawing::Size(41, 27);
			this->speed1->TabIndex = 27;
			this->speed1->Text = L"1.0x";
			this->speed1->UseVisualStyleBackColor = true;
			this->speed1->Click += gcnew System::EventHandler(this, &MyForm::speed1_Click);
			// 
			// speed125
			// 
			this->speed125->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->speed125->AutoSize = true;
			this->speed125->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->speed125->FlatAppearance->BorderSize = 0;
			this->speed125->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->speed125->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->speed125->ForeColor = System::Drawing::Color::White;
			this->speed125->Location = System::Drawing::Point(3, 93);
			this->speed125->Name = L"speed125";
			this->speed125->Size = System::Drawing::Size(48, 27);
			this->speed125->TabIndex = 26;
			this->speed125->Text = L"1.25x";
			this->speed125->UseVisualStyleBackColor = true;
			this->speed125->Click += gcnew System::EventHandler(this, &MyForm::speed125_Click);
			// 
			// speed15
			// 
			this->speed15->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->speed15->AutoSize = true;
			this->speed15->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->speed15->FlatAppearance->BorderSize = 0;
			this->speed15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->speed15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->speed15->ForeColor = System::Drawing::Color::White;
			this->speed15->Location = System::Drawing::Point(3, 64);
			this->speed15->Name = L"speed15";
			this->speed15->Size = System::Drawing::Size(41, 27);
			this->speed15->TabIndex = 25;
			this->speed15->Text = L"1.5x";
			this->speed15->UseVisualStyleBackColor = true;
			this->speed15->Click += gcnew System::EventHandler(this, &MyForm::speed15_Click);
			// 
			// speed175
			// 
			this->speed175->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->speed175->AutoSize = true;
			this->speed175->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->speed175->FlatAppearance->BorderSize = 0;
			this->speed175->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->speed175->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->speed175->ForeColor = System::Drawing::Color::White;
			this->speed175->Location = System::Drawing::Point(3, 35);
			this->speed175->Name = L"speed175";
			this->speed175->Size = System::Drawing::Size(48, 27);
			this->speed175->TabIndex = 24;
			this->speed175->Text = L"1.75x";
			this->speed175->UseVisualStyleBackColor = true;
			this->speed175->Click += gcnew System::EventHandler(this, &MyForm::speed175_Click);
			// 
			// speed2
			// 
			this->speed2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->speed2->AutoSize = true;
			this->speed2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->speed2->FlatAppearance->BorderSize = 0;
			this->speed2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->speed2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->speed2->ForeColor = System::Drawing::Color::White;
			this->speed2->Location = System::Drawing::Point(13, 4);
			this->speed2->Name = L"speed2";
			this->speed2->Size = System::Drawing::Size(31, 27);
			this->speed2->TabIndex = 23;
			this->speed2->Text = L"2x";
			this->speed2->UseVisualStyleBackColor = true;
			this->speed2->Click += gcnew System::EventHandler(this, &MyForm::speed2_Click);
			// 
			// track_list
			// 
			this->track_list->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->track_list->FormattingEnabled = true;
			this->track_list->Location = System::Drawing::Point(823, 28);
			this->track_list->Name = L"track_list";
			this->track_list->Size = System::Drawing::Size(171, 134);
			this->track_list->TabIndex = 3;
			this->track_list->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::track_list_SelectedIndexChanged);
			// 
			// statusLabel
			// 
			this->statusLabel->AutoSize = true;
			this->statusLabel->Location = System::Drawing::Point(76, 28);
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Size = System::Drawing::Size(35, 13);
			this->statusLabel->TabIndex = 4;
			this->statusLabel->Text = L"status";
			this->statusLabel->Click += gcnew System::EventHandler(this, &MyForm::statusLabel_Click);
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// switch_button
			// 
			this->switch_button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->switch_button->AutoSize = true;
			this->switch_button->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->switch_button->FlatAppearance->BorderSize = 0;
			this->switch_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->switch_button->ForeColor = System::Drawing::Color::White;
			this->switch_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"switch_button.Image")));
			this->switch_button->Location = System::Drawing::Point(11, 11);
			this->switch_button->Margin = System::Windows::Forms::Padding(2);
			this->switch_button->Name = L"switch_button";
			this->switch_button->Size = System::Drawing::Size(46, 46);
			this->switch_button->TabIndex = 5;
			this->switch_button->UseVisualStyleBackColor = false;
			this->switch_button->Click += gcnew System::EventHandler(this, &MyForm::switch_button_Click);
			// 
			// front_button
			// 
			this->front_button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->front_button->AutoSize = true;
			this->front_button->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->front_button->FlatAppearance->BorderSize = 0;
			this->front_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->front_button->ForeColor = System::Drawing::Color::White;
			this->front_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"front_button.Image")));
			this->front_button->Location = System::Drawing::Point(11, 61);
			this->front_button->Margin = System::Windows::Forms::Padding(2);
			this->front_button->Name = L"front_button";
			this->front_button->Size = System::Drawing::Size(46, 46);
			this->front_button->TabIndex = 6;
			this->front_button->UseVisualStyleBackColor = false;
			this->front_button->Click += gcnew System::EventHandler(this, &MyForm::front_button_Click);
			// 
			// speedOptions
			// 
			this->speedOptions->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->speedOptions->Controls->Add(this->speed125);
			this->speedOptions->Controls->Add(this->speed2);
			this->speedOptions->Controls->Add(this->speed25);
			this->speedOptions->Controls->Add(this->speed175);
			this->speedOptions->Controls->Add(this->speed5);
			this->speedOptions->Controls->Add(this->speed15);
			this->speedOptions->Controls->Add(this->speed75);
			this->speedOptions->Controls->Add(this->speed1);
			this->speedOptions->Location = System::Drawing::Point(239, 430);
			this->speedOptions->Name = L"speedOptions";
			this->speedOptions->Size = System::Drawing::Size(54, 241);
			this->speedOptions->TabIndex = 32;
			this->speedOptions->TabStop = false;
			// 
			// player
			// 
			this->player->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->player->Enabled = true;
			this->player->Location = System::Drawing::Point(-2, 0);
			this->player->Name = L"player";
			this->player->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"player.OcxState")));
			this->player->Size = System::Drawing::Size(1039, 763);
			this->player->TabIndex = 0;
			this->player->Enter += gcnew System::EventHandler(this, &MyForm::player_Enter);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1036, 760);
			this->Controls->Add(this->speedOptions);
			this->Controls->Add(this->front_button);
			this->Controls->Add(this->switch_button);
			this->Controls->Add(this->statusLabel);
			this->Controls->Add(this->track_list);
			this->Controls->Add(this->function_panel);
			this->Controls->Add(this->player);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Media Player";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->function_panel->ResumeLayout(false);
			this->function_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soundBar))->EndInit();
			this->speedOptions->ResumeLayout(false);
			this->speedOptions->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->EndInit();
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

		timer->Interval = 1;

		this->KeyPreview = true; // Enabling "KeyPreview" in order to capture key presses
		this->KeyDown += gcnew KeyEventHandler(this, &MyForm::OnKeyDown); //KeyDown is a built-in event that triggers when a key on the keyboard is pressed
		this->Icon = gcnew System::Drawing::Icon("app_icon.ico");
	}
	private: System::Void player_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void skipBackward_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		double currentPosition = player->Ctlcontrols->currentPosition;     // Get the current position of the player

		player->Ctlcontrols->currentPosition = currentPosition - 15;     // Set the new position
	}
		   
	private: System::Void next_button_Click(System::Object^ sender, System::EventArgs^ e) {
	// Ensure the VideoList is not empty
	if (!videoList->isEmpty())
	{
		// Get the next video path
		
		if (isLooped) {
			player->Ctlcontrols->currentPosition = 0;
		}
		
		else if (videoList->nextVideo() != nullptr)
		{
			// Update the ListBox's selected index to reflect the new current node
			int newIndex = videoList->getCurrentNodeIndex();
			track_list->SelectedIndex = newIndex;

			// Optionally, start playing the new video
			// mediaPlayer->URL = nextVideoPath; // Replace with your media player logic
		}
	}
}


	// Added function to be called anywhere in code, instead of related only to play/pause buttons.
	private: void playAction()
	{
		// Toggle visibility: Show Pause button, hide Play button
		play_button->Visible = false;
		pause_button->Visible = true;

		// Set the isPlaying state to true
		player->Ctlcontrols->play();
		isPlaying = true;
	}

	// Added function to be called anywhere in code, instead of related only to play/pause buttons.
	private: void pauseAction()
	{
		// Toggle visibility: Show Play button, hide Pause button
		pause_button->Visible = false;
		play_button->Visible = true;

		// Set the isPlaying state to false
		player->Ctlcontrols->pause();
		isPlaying = false;
	}

	private: System::Void play_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		playAction();
	}
	private: System::Void pause_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		pauseAction();
	}

	private: System::Void function_panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}


	private: System::Void previous_button_Click(System::Object^ sender, System::EventArgs^ e) {
		// Ensure the VideoList is not empty
		if (!videoList->isEmpty())
		{
			
			//check if the video is looped or not
			if (isLooped) {
				//reset the current position of the video to 0 so that it start from the start
				player->Ctlcontrols->currentPosition = 0;
			}
			
			// Switch to the prev video in the list
			else if (videoList->prevVideo() != nullptr)
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

private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (player->playState == WMPLib::WMPPlayState::wmppsPlaying) {
		// Update the progress bar maximum and value
		progressBar1->Maximum = (int)player->Ctlcontrols->currentItem->duration;
		progressBar1->Value = (int)player->Ctlcontrols->currentPosition;

		// Smoothly move the progressBarButton
		if (player->Ctlcontrols->currentItem->duration > 0) {
			double percentage = player->Ctlcontrols->currentPosition / player->Ctlcontrols->currentItem->duration;
			int buttonX = (int)(percentage * progressBar1->Width) - (progressBarButton->Width / 2);

			// Ensure button stays within bounds
			buttonX = Math::Max(0, Math::Min(buttonX, progressBar1->Width - progressBarButton->Width));
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
	   
	   */
	private: System::Void sound_button_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void shuffle_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (videoList->isEmpty())
		{
			statusLabel->Text = L"Video List is empty...";
			return;
		}

		// This function set's the current node to be at a random index.
		int randomIndex = videoList->shuffle();

		// Only if this list size is greater than 1
		if (randomIndex != -1)
		{
			// First pause the current video
			pauseAction();

			player->URL = videoList->getCurrentNodePath();
			video_name->Text = videoList->getCurrentNodeName();

			track_list->SelectedIndex = randomIndex;

			playAction();
		}
		else
			statusLabel->Text = L"Video List is only a single video...";
		
	}

		

	private: System::Void soundButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
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
			previousVolume = player->settings->volume; //save current volume
			player->settings->volume = 0; //set volume to 0
			soundBar->Value = 0; //set ui to 0
			soundLabel->Text = soundBar->Value.ToString();
		}
		else {
			player->settings->volume = previousVolume;
			soundBar->Value = previousVolume;
			soundLabel->Text = soundBar->Value.ToString();
		}

	}

	private: System::Void OnKeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		if (e->KeyCode == Keys::Right)
		{
			// Skip 5 seconds forward
			if (player->Ctlcontrols->currentPosition + 5 <= player->currentMedia->duration)
			{
				player->Ctlcontrols->currentPosition += 5;
			}
			else
			{
				//CALL NEXT HERE INSTEAD OF ENDING
				//player->Ctlcontrols->currentPosition = player->currentMedia->duration; 
				next_button_Click(sender, e);
			}
		}
		else if (e->KeyCode == Keys::Left)
		{
			// Skip 5 seconds backward
			if (player->Ctlcontrols->currentPosition - 5 >= 0)
			{
				player->Ctlcontrols->currentPosition -= 5;
			}
			else
			{
				player->Ctlcontrols->currentPosition = 0; // Go to start
			}
		}
		else if (e->KeyCode == Keys::K)
		{
			// Pause or play the video
			if (player->playState == WMPLib::WMPPlayState::wmppsPlaying)
			{
				player->Ctlcontrols->pause();
				pause_button->Hide();
				play_button->Show();
			}
			else
			{
				player->Ctlcontrols->play();
				pause_button->Show();
				play_button->Hide();
			}
		}
		else if (e->KeyCode == Keys::M)
		{
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
		else if (e->KeyCode == Keys::M)
		{
			muteButton_Click(sender, e);
		}
		if (e->KeyCode == Keys::Up) {
			// Increase volume by 5, but cap at 100
			int newVolume = player->settings->volume + 5;
			player->settings->volume = Math::Min(newVolume, 100);
			soundBar->Value = player->settings->volume;
			soundLabel->Text = player->settings->volume.ToString();
		}
		else if (e->KeyCode == Keys::Down) {
			// Decrease volume by 5, but don't go below 0
			int newVolume = player->settings->volume - 5;
			player->settings->volume = Math::Max(newVolume, 0);
			soundBar->Value = player->settings->volume;
			soundLabel->Text = player->settings->volume.ToString();
		}
		else if (e->KeyCode == Keys::Delete) {
			deleteButton_Click(sender, e);
		}
	
	}

		private: void HideAllControls_VideoScene()
		{
			// Hide the video player
			if (this->player != nullptr)
				this->player->Visible = false;

			// Hide the status label
			if (this->statusLabel != nullptr)
				this->statusLabel->Visible = false;

			// Hide the track list
			if (this->track_list != nullptr)
				this->track_list->Visible = false;

			// Hide the function
			if (this->function_panel != nullptr)
				this->function_panel->Visible = false;
		}

		private: void ShowAllControls_VideoScene()
		{
			// Hide the video player
			if (this->player != nullptr)
				this->player->Visible = true;

			// Hide the status label
			if (this->statusLabel != nullptr)
				this->statusLabel->Visible = true;

			// Hide the track list
			if (this->track_list != nullptr)
				this->track_list->Visible = true;

			// Hide the function
			if (this->function_panel != nullptr)
				this->function_panel->Visible = true;
		}

	private: System::Void switch_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (mainSceneVisible)
		{
			HideAllControls_VideoScene();
			mainSceneVisible = false;
			
			if(isPlaying)
				player->Ctlcontrols->stop();
		}
	}
	private: System::Void front_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (!mainSceneVisible)
		{
			ShowAllControls_VideoScene();
			mainSceneVisible = true;
		}
	}

	private: System::Void statusLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
		videoList->removeVideo(track_list);
		if (videoList->isEmpty()) {
			pauseAction();
			statusLabel->Text = "Empty";
		}
		next_button_Click(sender, e);
	
	
	
	}


	private: System::Void speedButton_Click(System::Object^ sender, System::EventArgs^ e) {
		speedOptions->Visible = !speedOptions->Visible;
	}



	private: System::Void speed2_Click(System::Object^ sender, System::EventArgs^ e) {
		player->settings->rate = 2;
	}
	private: System::Void speed15_Click(System::Object^ sender, System::EventArgs^ e) {
		player->settings->rate = 1.5;
	}
	private: System::Void speed175_Click(System::Object^ sender, System::EventArgs^ e) {
		player->settings->rate = 1.75;
	}
	private: System::Void speed125_Click(System::Object^ sender, System::EventArgs^ e) {
		player->settings->rate = 1.25;
	}

	private: System::Void speed1_Click(System::Object^ sender, System::EventArgs^ e) {
		player->settings->rate = 1;
	}
	private: System::Void speed75_Click(System::Object^ sender, System::EventArgs^ e) {
		player->settings->rate = 0.75;
	}
	private: System::Void speed5_Click(System::Object^ sender, System::EventArgs^ e) {
		player->settings->rate = 0.5;
	}
	private: System::Void speed25_Click(System::Object^ sender, System::EventArgs^ e) {
		player->settings->rate = 0.25;
	}
	private: System::Void repeatButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Toggle visibility
		repeatButton->Visible = false;
		no_repeat_button->Visible = true;

		isLooped = true;
	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void no_repeat_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Toggle visibility
		repeatButton->Visible = true;
		no_repeat_button->Visible = false;

		isLooped = false;
	}
private: System::Void groupBox1_Enter_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
