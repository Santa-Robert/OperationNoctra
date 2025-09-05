#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>
#include <fstream>
#include <windows.h>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "tenuki.h"

bool rightSurfaceCollision = false;
bool bottomSurfaceCollision = false;
bool topSurfaceCollision = false;
bool leftSurfaceCollision = false;


bool dontMoveUp, dontMoveDown, dontMoveLeft, dontMoveRight = false;

bool canHit = false;
bool shouldHit = false;

using namespace std;

const float toRadians = 3.14159265f / 180.0f;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;

int windowWidth = 1000;
int windowHeight = 800;

Texture testTexture;
Texture textBoxTexture;
Texture a, b, c, d, e, f, g, h, iL, j, k, l, m;
Texture n, o, p, q, r, s, t, u, v, w, x, y, z;
Texture singleQuote, comma;
Texture testMap;
Texture hitBoxTexture;
Texture mcStationary;
Texture mcWalkingLeft1;
Texture mcWalkingLeft2;
Texture mcWalkingRight1;
Texture mcWalkingRight2;
Texture mcWalkingUp1;
Texture mcWalkingUp2;
Texture mcWalkingDown1;
Texture mcWalkingDown2;
Texture mcAttackRight1, mcAttackRight2, mcAttackRight3, mcAttackRight4, mcAttackRight5, mcAttackRight6, mcAttackRight7;

GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;

// Vertex Shader
static const char* vShader = "Shaders/shader.vert.txt";

// Fragment Shader
static const char* fShader = "Shaders/shader.frag.txt";

void CreateObjects()
{
    unsigned int indices[] = {
        0, 1, 2, // first triangle
        2, 3, 0  // second triangle
    };

    unsigned int indicesTri[] = {
        0, 1, 2, // first triangle
    };

    GLfloat vertices[] = {
        // x     y     z     u     v
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // top right
 -      0.5f,  0.5f, 0.0f, 0.0f, 1.0f  // top left
    };

    GLfloat vertices2[] = {
        // x     y     z     u     v
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // top right
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f  // top left
    };

    GLfloat verticesTri[] = {
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
     0.0f,  0.5f, 0.0f ,1.0f, 1.0f
    };

    Mesh* obj1 = new Mesh();
    obj1->CreateMesh(vertices, indices, 20, 6);
    meshList.push_back(obj1);

    Mesh* obj2 = new Mesh();
    obj2->CreateMesh(vertices, indices, 20, 6);
    meshList.push_back(obj2);
    
    Mesh* obj3 = new Mesh();
    obj3->CreateMesh(vertices2, indices, 20, 6);
    meshList.push_back(obj3);

    Mesh* obj4 = new Mesh();
    obj4->CreateMesh(verticesTri, indicesTri, 9, 3);
    meshList.push_back(obj4);
}

void CreateShaders()
{
    Shader* shader1 = new Shader();
    shader1->CreateFromFiles(vShader, fShader);
    shaderList.push_back(*shader1);
}

void spawnObj(
    int meshNum,
    int transX, float transY, float transZ,
    float scaleX, float scaleY, float scaleZ,
    Texture& texture,
    GLuint uniformModel
) {
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(transX, transY, transZ));
    model = glm::scale(model, glm::vec3(scaleX, scaleY, scaleZ));
    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
    texture.UseTexture();
    meshList[meshNum]->RenderMesh();
}

void initTextures() {
    a = Texture("Textures/a.png");
    b = Texture("Textures/b.png");
    c = Texture("Textures/c.png");
    d = Texture("Textures/d.png");
    e = Texture("Textures/e.png");
    f = Texture("Textures/f.png");
    g = Texture("Textures/g.png");
    h = Texture("Textures/h.png");
    iL = Texture("Textures/i.png");
    j = Texture("Textures/j.png");
    k = Texture("Textures/k.png");
    l = Texture("Textures/l.png");
    m = Texture("Textures/m.png");
    n = Texture("Textures/n.png");
    o = Texture("Textures/o.png");
    p = Texture("Textures/p.png");
    q = Texture("Textures/q.png");
    r = Texture("Textures/r.png");
    s = Texture("Textures/s.png");
    t = Texture("Textures/t.png");
    u = Texture("Textures/u.png");
    v = Texture("Textures/v.png");
    w = Texture("Textures/w.png");
    x = Texture("Textures/x.png");
    y = Texture("Textures/y.png");
    z = Texture("Textures/z.png");
	singleQuote = Texture("Textures/'.png");
	comma = Texture("Textures/comma.png");
	testMap = Texture("Textures/mapTest.png");
	hitBoxTexture = Texture("Textures/hitBoxTexture.png");
	mcStationary = Texture("Textures/mc_stationary.png");
	mcWalkingLeft1 = Texture("Textures/mc_walk_left_1.png");
	mcWalkingLeft2 = Texture("Textures/mc_walk_left_2.png");
	mcWalkingRight1 = Texture("Textures/mc_walk_right_1.png");
	mcWalkingRight2 = Texture("Textures/mc_walk_right_2.png");
	mcWalkingDown1 = Texture("Textures/mc_step_one.png");
	mcWalkingDown2 = Texture("Textures/mc_step_two.png");
	mcWalkingUp1 = Texture("Textures/mc_walk_down_1.png");
	mcWalkingUp2 = Texture("Textures/mc_walk_down_2.png");
	mcAttackRight1 = Texture("Textures/battleAnim/mc_attack_1.png");
	mcAttackRight2 = Texture("Textures/battleAnim/mc_attack_2.png");
	mcAttackRight3 = Texture("Textures/battleAnim/mc_attack_3.png");
	mcAttackRight4 = Texture("Textures/battleAnim/mc_attack_4.png");
	mcAttackRight5 = Texture("Textures/battleAnim/mc_attack_5.png");
	mcAttackRight6 = Texture("Textures/battleAnim/mc_attack_6.png");
	mcAttackRight7 = Texture("Textures/battleAnim/mc_attack_7.png");
    a.LoadTexture();
    b.LoadTexture();
    c.LoadTexture();
    d.LoadTexture();
    e.LoadTexture();
    f.LoadTexture();
    g.LoadTexture();
    h.LoadTexture();
    iL.LoadTexture();
    j.LoadTexture();
    k.LoadTexture();
    l.LoadTexture();
    m.LoadTexture();
    n.LoadTexture();
    o.LoadTexture();
    p.LoadTexture();
    q.LoadTexture();
    r.LoadTexture();
    s.LoadTexture();
    t.LoadTexture();
    u.LoadTexture();
    v.LoadTexture();
    w.LoadTexture();
    x.LoadTexture();
    y.LoadTexture();
    z.LoadTexture();
	singleQuote.LoadTexture();
	comma.LoadTexture();
	testMap.LoadTexture();
	hitBoxTexture.LoadTexture();
	mcStationary.LoadTexture();
	mcWalkingLeft1.LoadTexture();
	mcWalkingLeft2.LoadTexture();
	mcWalkingRight1.LoadTexture();
	mcWalkingRight2.LoadTexture();
	mcWalkingDown1.LoadTexture();
	mcWalkingDown2.LoadTexture();
	mcWalkingUp1.LoadTexture();
	mcWalkingUp2.LoadTexture();
	mcAttackRight1.LoadTexture();
	mcAttackRight2.LoadTexture();
	mcAttackRight3.LoadTexture();
	mcAttackRight4.LoadTexture();
	mcAttackRight5.LoadTexture();
	mcAttackRight6.LoadTexture();
	mcAttackRight7.LoadTexture();
}

void collisionDec(float& XMovement, float& YMovement) {
    

    if (topSurfaceCollision) {
		dontMoveUp = true;
    }
    if (bottomSurfaceCollision) {
		dontMoveDown = true;
    }
    if (rightSurfaceCollision) {
		dontMoveRight = true;
    }
    if (leftSurfaceCollision) {
		dontMoveLeft = true;
    }
}

void canHitDec(float& XMovement, float& YMovement) {


    if (canHit) {
		shouldHit = true;
   }

}

void AttackAnim(GLuint uniformModel, float timeOff) {
	 
    if (timeOff < 0.05f) {
        spawnObj(0, 564.5f, 396.0f, 0.66f, 10.7f * 23, 12.0f * 20, 1.0f, mcAttackRight1, uniformModel);
    }
    else if (timeOff < 0.10f) {
        spawnObj(0, 564.5f, 396.0f, 0.66f, 10.7f * 23, 12.0f * 20, 1.0f, mcAttackRight2, uniformModel);
    }
    else if (timeOff < 0.15f) {
        spawnObj(0, 564.5f, 396.0f, 0.66f, 10.7f * 23, 12.0f * 20, 1.0f, mcAttackRight3, uniformModel);
    }
    else if (timeOff < 0.20f) {
        spawnObj(0, 564.5f, 396.0f, 0.66f, 10.7f * 23, 12.0f * 20, 1.0f, mcAttackRight4, uniformModel);
    }
    else if (timeOff < 0.25f) {
        spawnObj(0, 564.5f, 396.0f, 0.66f, 10.7f * 23, 12.0f * 20, 1.0f, mcAttackRight5, uniformModel);
    }
    else if (timeOff < 0.30f) {
        spawnObj(0, 564.5f, 396.0f, 0.66f, 10.7f * 23, 12.0f * 20, 1.0f, mcAttackRight6, uniformModel);
    }
    else if (timeOff < 0.35f) {
        spawnObj(0, 564.5f, 396.0f, 0.66f, 10.7f * 23, 12.0f * 20, 1.0f, mcAttackRight7, uniformModel);
    }
	cout << "TimeOff: " << timeOff << endl;
	
}

int main()
{
    mainWindow = Window(1000, 800);
    mainWindow.Initialise();
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    CreateObjects();
    CreateShaders();

    stbi_set_flip_vertically_on_load(true);

    testTexture = Texture("Textures/letterTest.png");
    testTexture.LoadTexture();
    textBoxTexture = Texture("Textures/textbox.png");
    textBoxTexture.LoadTexture();
    initTextures();
    
    const float COLLISION_THICKNESS = 5.0f;

	float XMovement = 665.0f;
	float YMovement = 500.0f;

	bool cooldown = false;
	
    bool* keys = mainWindow.getsKeys();
	
	float timeOfHit = 0.0f;
    float hasHit = 0.0f;

    float changeStep = 0.0f;
	float stepTime = 0.0f;

	bool activateWalkingLeft = false;
    bool activateWalkingRight = false;
    bool activateWalkingUp = false;
    bool activateWalkingDown = false;

	float timeOff = 0.0f;
	float timeOffAction = 0.0f;

	bool shouldPlayAnim = false;

    while (!mainWindow.getShouldClose())
    {
        GLfloat now = glfwGetTime();
        deltaTime = now - lastTime;
        lastTime = now;

		hasHit = glfwGetTime() - timeOfHit;
       
        changeStep = glfwGetTime() - stepTime;

		timeOff = glfwGetTime() - timeOffAction;

        glfwPollEvents();

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderList[0].UseShader();

        glm::mat4 projection = glm::ortho(0.0f, (float)windowWidth, 0.0f, (float)windowHeight, -1.0f, 1.0f);
        glm::mat4 view = glm::mat4(1.0f);

        // Translate quad to center of screen!
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(470.0f, 100.0f, 0.0f));
        model = glm::scale(model, glm::vec3(650.0f, 180.0f, 1.0f)); 

        GLuint uniformProjection = shaderList[0].GetProjectionLocation();
        GLuint uniformView = shaderList[0].GetViewLocation();
        GLuint uniformModel = shaderList[0].GetModelLocation();

        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
       
        

        //spawnObj(1, 470.0f, 100.0f, 0.9f, 650.0f, 180.0f, 1.0f, textBoxTexture, uniformModel);
       




       // readString("a pizza finom", uniformModel);
        

       


		spawnObj(2, XMovement, YMovement, 0.2f, 1500.0f, 1500.0f, 1.0f, testMap, uniformModel);

		//spawnObj(0, 500.0f, 400.0f, 0.4f, 5.35f * 23, 6.0f * 20, 1.0f, mcStationary, uniformModel);
        
		

       

		//cout << "Time: " << glfwGetTime() << endl;

		
        


        collision(COLLISION_THICKNESS, rightSurfaceCollision, bottomSurfaceCollision, topSurfaceCollision, leftSurfaceCollision,
            XMovement, YMovement, true, hitBoxTexture, uniformModel, 33, 33, 165, -50, 451, 219, 320, 583);

        collisionDec(XMovement, YMovement);

        collision(COLLISION_THICKNESS, rightSurfaceCollision, bottomSurfaceCollision, topSurfaceCollision, leftSurfaceCollision,
            XMovement, YMovement, true, hitBoxTexture, uniformModel, 33, 33, 600, 0, 15, -215, 270, 530);

        collisionDec(XMovement, YMovement);

        collision(COLLISION_THICKNESS, rightSurfaceCollision, bottomSurfaceCollision, topSurfaceCollision, leftSurfaceCollision,
            XMovement, YMovement, true, hitBoxTexture, uniformModel, 33, 33, -125, 600, 743, 508, -334, -67);

        collisionDec(XMovement, YMovement);

        battleHitBox(canHit, hitBoxTexture, XMovement, YMovement, uniformModel, 66, 66, 76, -45, 625, 226, 232, 657, true);
		canHitDec(XMovement, YMovement);

        battleHitBox(canHit, hitBoxTexture, XMovement, YMovement, uniformModel, 66, 66, 651, -345, 47, -349, 529, 959, true);
        canHitDec(XMovement, YMovement);

        

            if (mainWindow.getsKeys()) {
                
                if (keys[GLFW_KEY_P]) {
                    if (keys[GLFW_KEY_W] && !dontMoveUp) {
                        YMovement -= 10.0f * deltaTime;
                    }
                    if (keys[GLFW_KEY_S] && !dontMoveDown) {
                        YMovement += 10.0f * deltaTime;
                    }
                    if (keys[GLFW_KEY_A] && !dontMoveLeft) {
                        XMovement += 10.0f * deltaTime;
                    }
                    if (keys[GLFW_KEY_D] && !rightSurfaceCollision) {
                        XMovement -= 10.0f * deltaTime;
                    }
                }
                else {
                    if (keys[GLFW_KEY_W] && !dontMoveUp) {
                        YMovement -= 300.0f * deltaTime;
                        activateWalkingUp = true;
                    }
                    if (keys[GLFW_KEY_S] && !dontMoveDown) {
                        YMovement += 300.0f * deltaTime;
                        activateWalkingDown = true;
                    }
                    if (keys[GLFW_KEY_A] && !dontMoveLeft) {
                        XMovement += 300.0f * deltaTime;
						activateWalkingLeft = true;
                    }
                    if (keys[GLFW_KEY_D] && !dontMoveRight) {
                        XMovement -= 300.0f * deltaTime;
                        activateWalkingRight = true;
                    }
                }
           
                if (keys[GLFW_KEY_J] && shouldHit && !cooldown) {
                    
                        cout << "HIT!" << endl;
                        shouldHit = false;
                        cooldown = true;
                        
                        timeOfHit = glfwGetTime();

						timeOffAction = glfwGetTime();

						shouldPlayAnim = true;
						
                    
                }
            }
        
            if (shouldPlayAnim) {
                AttackAnim(uniformModel, timeOff);
                
            }

            if (activateWalkingLeft) {
                if (changeStep >= 0.4) {
                    stepTime += 0.4f;
                    changeStep = 0.0f;
                }
                
                 if (changeStep < 0.2 ) {
                    spawnObj(0, 500.0f, 400.0f, 0.65f, 5.35f * 23, 6.0f * 20, 1.0f, mcWalkingLeft1, uniformModel);
                }
                else if( changeStep < 0.4 ){
                    spawnObj(0, 500.0f, 400.0f, 0.65f, 5.35f * 23, 6.0f * 20, 1.0f, mcWalkingLeft2, uniformModel);
                }
                
            }
            else if (activateWalkingRight) {
                if (changeStep >= 0.4) {
                    stepTime += 0.4f;
                    changeStep = 0.0f;
                }
                if (changeStep < 0.2) {
                    spawnObj(0, 500.0f, 400.0f, 0.65f, 5.35f * 23, 6.0f * 20, 1.0f, mcWalkingRight1, uniformModel);
                }
                else if (changeStep < 0.4) {
                    spawnObj(0, 500.0f, 400.0f, 0.65f, 5.35f * 23, 6.0f * 20, 1.0f, mcWalkingRight2, uniformModel);
                }
            }
            else if (activateWalkingDown) {
                if (changeStep >= 0.4) {
                    stepTime += 0.4f;
                    changeStep = 0.0f;
                }
                if (changeStep < 0.2) {
                    spawnObj(0, 500.0f, 400.0f, 0.65f, 5.35f * 23, 6.0f * 20, 1.0f, mcWalkingDown1, uniformModel);
                }
                else if (changeStep < 0.4) {
                    spawnObj(0, 500.0f, 400.0f, 0.65f, 5.35f * 23, 6.0f * 20, 1.0f, mcWalkingDown2, uniformModel);
                }
            }
            else if (activateWalkingUp) {
                if (changeStep >= 0.4) {
                    stepTime += 0.4f;
                    changeStep = 0.0f;
                }
                if (changeStep < 0.2) {
                    spawnObj(0, 500.0f, 400.0f, 0.65f, 5.35f * 23, 6.0f * 20, 1.0f, mcWalkingUp1, uniformModel);
                }
                else if (changeStep < 0.4) {
                    spawnObj(0, 500.0f, 400.0f, 0.65f, 5.35f * 23, 6.0f * 20, 1.0f, mcWalkingUp2, uniformModel);
                }
            }
            else {
                spawnObj(0, 500.0f, 400.0f, 0.65f, 5.35f * 23, 6.0f * 20, 1.0f, mcStationary, uniformModel);
                
            }

            

            if (cooldown) {
                if (hasHit >= 0.5f) {
                    cooldown = false;
                    hasHit = 0.0f;
                }
            }

           // cout << "X: " << XMovement << " Y: " << YMovement << endl;
                
			//cout << "Can Hit: " << hasHit << endl;

        dontMoveUp = false;
        dontMoveDown = false;
        dontMoveLeft = false;
        dontMoveRight = false;

		activateWalkingLeft = false;
        activateWalkingRight = false;
		activateWalkingDown = false;
        activateWalkingUp = false;
        
		
		//cout << changeStep << endl;

        glUseProgram(0);

        mainWindow.swapBuffers();
    }

    return 0;
}
