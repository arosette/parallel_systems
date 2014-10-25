#ifndef DEF_SCENEOPENGL
#define DEF_SCENEOPENGL


#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "Shader.h"

// Classe

class SceneOpenGL
{
public:

	SceneOpenGL(std::string titreFenetre, int largeurFenetre, int hauteurFenetre);
	~SceneOpenGL();

	bool initialiserFenetre();
	bool initGL();
	void bouclePrincipale();


private:

	std::string m_titreFenetre;
	int m_largeurFenetre;
	int m_hauteurFenetre;

	SDL_Window* m_fenetre;
	SDL_GLContext m_contexteOpenGL;
	SDL_Event m_evenements;
};

#endif

