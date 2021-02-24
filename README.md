# FRE
*Required:*                                                                                                                                                                                                                                                                  
OpenGL,
GLAD,
SDL,
GLM Library,
Assimp,
Stbimage      

*Instructions:*   

1) Follow the instructions for each and save all necessary files into an "Include" and "Libs" folder.   
2) In the project properties, under Configuration Properties/VC++ Directories make sure that "Include Directories" is linked to Include folder, and "Library Directories" is linked to Libs folder.
3) Under C/C++/General make sure that "Additional Include Directories" is linked to "include/assimp".
4) Under Linker/General make sure that "Additional Library Directories" is linked to your Libs folder.
5) Under Linker/Input make sure that "Additional Dependencies" has the following:

assimp-vc142-mtd.lib

glew32.lib

SDL2.lib

SDL2main.lib

opengl32.lib

kernel32.lib

user32.lib

gdi32.lib

winspool.lib

comdlg32.lib

advapi32.lib

shell32.lib

ole32.lib

oleaut32.lib

uuid.lib

odbc32.lib

odbccp32.lib

----------------------------------------------------
Following this procedure the project should run.
