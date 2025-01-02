# Getting Started

1.**Clone the Repository**
git clone https://github.com/mohamedelziat50/MediaPlayer-MIU.git cd MediaPlayer-MIU

2. **Build the Solution**
Open Videoplayer-MIU.sln in Visual Studio. Go to Build > Build Solution.

3. **Add Missing Dependencies**
Such as WMP & AXWMP through ToolBox or References

4. **Run The Project!**

# Setting Up WinForms in Visual Studio

## Initial Setup
Follow the guide in this video to install and configure WinForms:  
https://www.youtube.com/watch?v=HcxlYkU8aY0&list=PL2i17lRog5pBe7t9zJdFdugQ6bxgjntJD&index=6  

---

## Steps for Every New Project
1. **Configure the Project Settings:**
   - Go to `Project -> Properties -> Linker -> System` and set **SubSystem** to `"Windows"`.
   - Under `Linker -> Advanced`, set **Entry Point** to `"main"`.

2. **Namespace Adjustments:**
   - Replace `PROJECTNAME::MyForm` with your actual project namespace where applicable.

---

## Adding a New Form
1. Go to `Project -> Add New Item -> UI -> Windows Form`.
2. Fill out the Form's .cpp file
3. If after filling out .cpp file you see only code and not the form, re-open the project 

---

## Common Issues and Fixes
- Ensure the namespace matches your project name in code.
- References -> There has to be AxInterop.WMPLib.1.0

# .gitignore
Included files: C++ source code files (.cpp, .h) Visual Studio project files (.sln, .vcxproj, .vcxproj.filters), and assured that References are not excluded.

Excluded files: IDE-specific files: .vs/, .idea/ Build output directories: Debug/, Release/ OS-specific files: .DS_Store, Thumbs.db User-specific settings: .user
