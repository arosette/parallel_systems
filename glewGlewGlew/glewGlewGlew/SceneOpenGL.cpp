#include "SceneOpenGL.h"


SceneOpenGL::SceneOpenGL(std::string titreFenetre, int largeurFenetre, int hauteurFenetre) : m_titreFenetre(titreFenetre), m_largeurFenetre(largeurFenetre),
m_hauteurFenetre(hauteurFenetre), m_fenetre(0), m_contexteOpenGL(0)
{

}


SceneOpenGL::~SceneOpenGL()
{
	SDL_GL_DeleteContext(m_contexteOpenGL);
	SDL_DestroyWindow(m_fenetre);
	SDL_Quit();
}


// M�thodes

bool SceneOpenGL::initialiserFenetre()
{
	// Initialisation de la SDL

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
		SDL_Quit();

		return false;
	}


	// Version d'OpenGL

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);


	// Double Buffer

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


	// Cr�ation de la fen�tre

	m_fenetre = SDL_CreateWindow(m_titreFenetre.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_largeurFenetre, m_hauteurFenetre, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (m_fenetre == 0)
	{
		std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
		SDL_Quit();

		return false;
	}


	// Cr�ation du contexte OpenGL

	m_contexteOpenGL = SDL_GL_CreateContext(m_fenetre);

	if (m_contexteOpenGL == 0)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_DestroyWindow(m_fenetre);
		SDL_Quit();

		return false;
	}

	return true;
}


bool SceneOpenGL::initGL()
{

	// On initialise GLEW

	GLenum initialisationGLEW(glewInit());


	// Si l'initialisation a �chou� :

	if (initialisationGLEW != GLEW_OK)
	{
		// On affiche l'erreur gr�ce � la fonction : glewGetErrorString(GLenum code)

		std::cout << "Erreur d'initialisation de GLEW : " << glewGetErrorString(initialisationGLEW) << std::endl;


		// On quitte la SDL

		SDL_GL_DeleteContext(m_contexteOpenGL);
		SDL_DestroyWindow(m_fenetre);
		SDL_Quit();

		return false;
	}



	// Tout s'est bien pass�, on retourne true

	return true;
}


void SceneOpenGL::bouclePrincipale()
{
	// Variables

	bool terminer(false);
	float vertices[] = { -0.5, -0.5, 0.0, 0.5, 0.5, -0.5 };
	float couleurs[] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };


	// Shader

	Shader shaderCouleur("Shaders/couleur2D.vert", "Shaders/couleur2D.frag");
	shaderCouleur.charger();


	// Boucle principale

	while (!terminer)
	{
		// Gestion des �v�nements

		SDL_WaitEvent(&m_evenements);

		if (m_evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = true;


		// Nettoyage de l'�cran

		glClear(GL_COLOR_BUFFER_BIT);


		// Activation du shader

		glUseProgram(shaderCouleur.getProgramID());


		// Envoi des vertices

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);


		// Envoi des couleurs

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, couleurs);
		glEnableVertexAttribArray(1);


		// Affichage du triangle

		glDrawArrays(GL_TRIANGLES, 0, 3);


		// D�sactivation des tableaux Vertex Attrib

		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(0);


		// D�sactivation du shader

		glUseProgram(0);


		// Actualisation de la fen�tre

		SDL_GL_SwapWindow(m_fenetre);
	}
}