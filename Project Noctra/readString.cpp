#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "tenuki.h"

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>



#include <iostream>
#include <stdio.h>
#include <vector>

extern Texture a, b, c, d, e, f, g, h, iL, j, k, l, m;
extern Texture n, o, p, q, r, s, t, u, v, w, x, y, z;
extern Texture singleQuote, comma;


bool wordCheck = false;
bool wordChop = false;

std::vector<float> words = {};

void readString(const std::string& str, GLint uniformModel) {
    int letterPos = 210;
    float letterPosY = 140.0f;

    size_t i = 0;
    while (i < str.length()) {
        // Build the next word
        std::string word;
        while (i < str.length() && str[i] != ' ') {
            word += str[i];
            ++i;
        }

        // Measure total word width
        int wordWidth = word.length() * 15;

        // Wrap if word doesn't fit
        if (letterPos + wordWidth > 720) {
            letterPos = 210;
            letterPosY -= 20.0f;
        }

        // Draw the word character by character
        for (char ch : word) { 
            switch (ch) {
            case 'a': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, a, uniformModel); words.push_back(letterPosY); break;
            case 'b': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, b, uniformModel); words.push_back(letterPosY); break;
            case 'c': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, c, uniformModel); words.push_back(letterPosY); break;
            case 'd': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, d, uniformModel); words.push_back(letterPosY); break;
            case 'e': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, e, uniformModel); words.push_back(letterPosY); break;
            case 'f': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, f, uniformModel); words.push_back(letterPosY); break;
            case 'g': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, g, uniformModel); words.push_back(letterPosY); break;
            case 'h': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, h, uniformModel); words.push_back(letterPosY); break;
            case 'i': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, iL, uniformModel); words.push_back(letterPosY); break;
            case 'j': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, j, uniformModel); words.push_back(letterPosY); break;
            case 'k': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, k, uniformModel); words.push_back(letterPosY); break;
            case 'l': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, l, uniformModel); words.push_back(letterPosY); break;
            case 'm': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, m, uniformModel); words.push_back(letterPosY); break;
            case 'n': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, n, uniformModel); words.push_back(letterPosY); break;
            case 'o': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, o, uniformModel); words.push_back(letterPosY); break;
            case 'p': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, p, uniformModel); words.push_back(letterPosY); break;
            case 'q': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, q, uniformModel); words.push_back(letterPosY); break;
            case 'r': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, r, uniformModel); words.push_back(letterPosY); break;
            case 's': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, s, uniformModel); words.push_back(letterPosY); break;
            case 't': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, t, uniformModel); words.push_back(letterPosY); break;
            case 'u': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, u, uniformModel); words.push_back(letterPosY); break;
            case 'v': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, v, uniformModel); words.push_back(letterPosY); break;
            case 'w': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, w, uniformModel); words.push_back(letterPosY); break;
            case 'x': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, x, uniformModel); words.push_back(letterPosY); break;
            case 'y': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, y, uniformModel); words.push_back(letterPosY); break;
            case 'z': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, z, uniformModel); words.push_back(letterPosY); break;
            case '\'': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, singleQuote, uniformModel); words.push_back(letterPosY); break;
            case ',': spawnObj(0, letterPos, letterPosY, 1.0f, 12.5f, 17.5f, 1.0f, comma, uniformModel); words.push_back(letterPosY); break;

            case ' ': letterPos += 15; wordCheck = true; break;
            default: break;

            }
            words.push_back(letterPosY);
            letterPos += 15; // move forward
        }

        // Handle space after the word (if there was one)
        if (i < str.length() && str[i] == ' ') {
            letterPos += 15; // spacing after word
            ++i; // move past the space
        }
    }
}



