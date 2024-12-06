#include "MainFrame.h"
#include <wx/mediactrl.h>
#include<wx/wx.h>
#include <wx/tglbtn.h>


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {
    wxPanel* panel = new wxPanel(this);

    wxMediaCtrl* mediaCtrl = new wxMediaCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(125, 100), wxSize(500, 300));


    wxSlider* soundSlider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(575, 500), wxSize(200, -1), wxSL_VALUE_LABEL);
    soundSlider->Hide();
    soundSlider->SetBackgroundColour(wxColour(30, 30, 30));  // Dark background
    soundSlider->SetForegroundColour(wxColour(0, 200, 200)); // Bright foreground


    wxToggleButton* toggleButton = new wxToggleButton(panel, wxID_ANY, "Play", wxPoint(50, 500), wxSize(100, 50));

    toggleButton->SetBackgroundColour(wxColour(30, 30, 30));  // Dark background
    toggleButton->SetForegroundColour(wxColour(0, 200, 200)); // Bright foreground


    wxToggleButton* sound = new wxToggleButton(panel, wxID_ANY, "sound", wxPoint(475, 500), wxSize(100, 50));
    sound->SetBackgroundColour(wxColour(30, 30, 30));  // Dark background
    sound->SetForegroundColour(wxColour(0, 200, 200)); // Bright foreground

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(mediaCtrl, 1, wxEXPAND | wxALL, 5);
    sizer->Add(toggleButton, 0, wxALIGN_LEFT | wxALL, 5);
    sizer->Add(sound, 0, wxALIGN_LEFT | wxALL, 5);
    sizer->Add(soundSlider, 0, wxTEXT_ALIGNMENT_LEFT | wxALL, 5);

    panel->SetSizerAndFit(sizer);


    if (!mediaCtrl->Load(wxT("E:\\Clips\\Desktop\\Desktop\\Desktop 2024.12.03 - 20.30.21.01.mp4"))) {
        wxMessageBox("Failed to load video!", "Error", wxICON_ERROR);
        return;
    }

    sound->Bind(wxEVT_TOGGLEBUTTON, [sound, soundSlider](wxCommandEvent&) {
        if (sound->GetValue()) { // If toggle button is pressed
            if (!soundSlider->Hide()) {
                //  wxMessageBox("Failed to play video!", "Error", wxICON_ERROR);
                sound->SetValue(false); // Reset toggle button if play fails
                soundSlider->Show();
            }
            else {
                sound->SetValue(false);
                soundSlider->Hide();

            }


        }


        });




    soundSlider->Bind(wxEVT_SLIDER, [mediaCtrl](wxCommandEvent& event) {
        double volume = static_cast<double>(event.GetInt()) / 100.0;
        mediaCtrl->SetVolume(volume);
        });



    toggleButton->Bind(wxEVT_TOGGLEBUTTON, [mediaCtrl, toggleButton](wxCommandEvent&) {
        if (toggleButton->GetValue()) { // If toggle button is pressed
            if (!mediaCtrl->Play()) {
                wxMessageBox("Failed to play video!", "Error", wxICON_ERROR);
                toggleButton->SetValue(false); // Reset toggle button if play fails
            }
            else {
                toggleButton->SetLabel("Pause");
            }
        }
        else { // If toggle button is released
            if (mediaCtrl->Play()) {
                mediaCtrl->Pause();
                toggleButton->SetLabel("Play");
            }
        }
        });



}