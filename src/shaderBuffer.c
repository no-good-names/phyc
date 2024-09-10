//
// Created by cp176 on 9/7/2024.
//

#include "shaderBuffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "renderer.h"

char* readShaderFile(const char* filename) {
	FILE* file = fopen(filename, "r");
	if (!file) {
		fprintf(stderr, "Error: Could not open shader file %s\n", filename);
		return NULL;
	}

	// Allocate an initial buffer size (we will grow it dynamically)
	size_t bufferSize = 1024;
	char* shaderCode = (char*)malloc(bufferSize);
	if (!shaderCode) {
		fprintf(stderr, "Error: Could not allocate memory\n");
		fclose(file);
		return NULL;
	}

	// Temporary buffer to store each line
	char lineBuffer[256];
	shaderCode[0] = '\0';  // Initialize shaderCode as an empty string

	// Read file line by line
	while (fgets(lineBuffer, sizeof(lineBuffer), file)) {
		// Ensure we have enough space in shaderCode
		if (strlen(shaderCode) + strlen(lineBuffer) + 1 > bufferSize) {
			bufferSize *= 2;  // Double the buffer size
			shaderCode = (char*)realloc(shaderCode, bufferSize);
			if (!shaderCode) {
				fprintf(stderr, "Error: Could not reallocate memory\n");
				fclose(file);
				return NULL;
			}
		}

		// Append the line and ensure it ends with a newline
		strcat(shaderCode, lineBuffer);
	}

	fclose(file);
	return shaderCode;
}


void compile_error(const unsigned int source) {
	int status;
	glGetShaderiv(source, GL_COMPILE_STATUS, &status);
	if(!status)
	{
		char log[512];
		glGetShaderInfoLog(source, 512, NULL, log);
		fprintf(stderr, "ERROR::SHADER::VERTEX/FRAGMENT::COMPILATION_FAILED\n");
	}
}

void link_err(const unsigned int source) {
	int success;
	glGetProgramiv(source, GL_LINK_STATUS, &success);
	if(!success) {
		char infoLog[512];
		glGetProgramInfoLog(source, 512, NULL, infoLog);
		fprintf(stderr, "err %s", infoLog);
	}
}

unsigned int create_program(const char *shaderSource, const char *fragmentShaderSource) {
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &shaderSource, NULL);
	glCompileShader(vertexShader);

	compile_error(vertexShader);

	const unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	compile_error(fragmentShader);

	const unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	link_err(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}

void ShaderBuffer(ShaderBuf *sb, const char *vertexSource, const char *fragmentSource) {
	sb->id = create_program(vertexSource, fragmentSource);
	free((void*)vertexSource);
	free((void*)fragmentSource);
}

void deleteShaderBuffer(ShaderBuf *sb) {
	glDeleteProgram(sb->id);
}

void bindShaderBuffer(const ShaderBuf *sb) {
	glUseProgram(sb->id);
}

void unbindShaderBuffer() {
	glUseProgram(0);
}
