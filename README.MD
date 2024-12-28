# MediaPlayer-MIU

## Overview
MediaPlayer-MIU is a video player application developed in C++ as part of our **Data Structures & Algorithms Course** by a team of 5 members. The project utilizes **Doubly Circular Linked List**, **WinForms**, and **Windows Media Player (WMP)** for managing the playlist functionality.

---

## Features
- 🎥 A user-friendly interface for managing and playing video files.
- 🔄 Dynamic playlist powered by a **Doubly Circular Linked List**.
- 🎛️ Custom playback controls, including play, pause, shuffle, and volume control.
- 💻 Sleek, modern design; However, limited to WinForms' functionalties.
- ⌨️ Keyboard shortcuts for quick media control:
   Right Arrow (→): Skip forward by 5 seconds.
   Left Arrow (←): Skip backward by 5 seconds.
   K: Pause or play the video.
   M: Mute or restore sound.
   Up Arrow (↑): Increase volume by 5 (maximum 100).
   Down Arrow (↓): Decrease volume by 5 (minimum 0).
   Delete: Delete the current video from the playlist.
   F: Toggle fullscreen mode.
   S: Take a screenshot of the current video.


---

## Screenshots

### Library Screen
![library-preview](https://github.com/user-attachments/assets/23d794a6-d028-4cab-a064-6e5a2bf50154)

### Playback Screen
![videplayer-preview1](https://github.com/user-attachments/assets/ed2c9dfb-7d5e-4e99-8bf1-fd0a4ae0ee99)

---

## Project Setup

### Prerequisites
- **Visual Studio** with C++ development tools.
- Ensure `AxInterop.WMPLib.dll` is referenced in your project.
- WinForms library configured in your Visual Studio environment.

# Getting Started

1. **Clone the Repository**
   ```bash
   cd "Preferred Directory"
   git clone https://github.com/mohamedelziat50/MediaPlayer-MIU.git
   ```

2. **Open the Solution**
   Open `MediaPlayer-MIU.sln` in Visual Studio.

3. **Build the Solution**
   Navigate to `Build > Build Solution` to compile the project.

4. **Add Missing Dependencies**
   Add **Windows Media Player (WMP)** through the Toolbox or References if not pre-configured.

5. **Run the Project**
   Use `Start` in Visual Studio to launch the application.

---

### Setting Up WinForms in Visual Studio
If you're new to WinForms, follow this [guide](https://www.youtube.com/watch?v=HcxlYkU8aY0&list=PL2i17lRog5pBe7t9zJdFdugQ6bxgjntJD&index=6) to set up and configure WinForms in Visual Studio.

## Steps for Every New Project
1. **Configure the Project Settings:**
   - Go to `Project -> Properties -> Linker -> System` and set **SubSystem** to `"Windows"`.
   - Under `Linker -> Advanced`, set **Entry Point** to `"main"`.

2. **Namespace Adjustments:**
   - Replace `PROJECTNAME::MyForm` with your actual project namespace where applicable.

## Adding a New Form
1. Go to `Project -> Add New Item -> UI -> Windows Form`.
2. Fill out the Form's .cpp file
3. If after filling out the .cpp file you see only code and not the form, re-open the project 

---

## Common Issues and Fixes
- Ensure the namespace matches your project name in the code.
- References -> There has to be AxInterop.WMPLib.1.0

# .gitignore
Included files: C++ source code files (.cpp, .h) Visual Studio project files (.sln, .vcxproj, .vcxproj.filters), and assured that References are not excluded.

Excluded files: IDE-specific files: .vs/, .idea/ Build output directories: Debug/, Release/ OS-specific files: .DS_Store, Thumbs.db User-specific settings: .user
