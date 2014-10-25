/*


#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>


int main(int argc, char **argv)
{

SDL_Window* fenetre = NULL;
SDL_GLContext contexteOpenGL = 0;
SDL_Event evenements;
bool terminer = false;

if (SDL_Init(SDL_INIT_VIDEO) < 0) {
std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
SDL_Quit();
return -1;
}


SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

if (fenetre == 0) {
std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
SDL_Quit();
return -1;
}


contexteOpenGL = SDL_GL_CreateContext(fenetre);

if (contexteOpenGL == 0) {
std::cout << SDL_GetError() << std::endl;
SDL_DestroyWindow(fenetre);
SDL_Quit();
return -1;
}

GLenum initialisationGLEW(glewInit());

if (initialisationGLEW != GLEW_OK) {
std::cout << "Erreur d'initialisation de GLEW : " << glewGetErrorString(initialisationGLEW) << std::endl;
SDL_GL_DeleteContext(contexteOpenGL);
SDL_DestroyWindow(fenetre);
SDL_Quit();
return -1;
}


float vertices[] = { -0.5, -0.5, 0.0, 0.5, 0.5, -0.5 };

while (!terminer)
{

SDL_WaitEvent(&evenements);

if (evenements.window.event == SDL_WINDOWEVENT_CLOSE)
terminer = true;

glClear(GL_COLOR_BUFFER_BIT);
glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
glEnableVertexAttribArray(0);
glDrawArrays(GL_TRIANGLES, 0, 3);
glDisableVertexAttribArray(0);
SDL_GL_SwapWindow(fenetre);
}

SDL_GL_DeleteContext(contexteOpenGL);
SDL_DestroyWindow(fenetre);
SDL_Quit();

return 0;
}

*/