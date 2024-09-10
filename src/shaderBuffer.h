//
// Created by cp176 on 9/7/2024.
//

#ifndef SHADERBUFFER_H
#define SHADERBUFFER_H

typedef struct {
	unsigned int id;
} ShaderBuf;

char* readShaderFile(const char* filename);
unsigned int create_program(const char *shaderSource, const char *fragmentShaderSource);
void compile_error(unsigned int source);
void link_err(unsigned int source);
void ShaderBuffer(ShaderBuf *sb, const char *vertexSource, const char *fragmentSource);
void deleteShaderBuffer(ShaderBuf *sb);
void bindShaderBuffer(const ShaderBuf *sb);
void unbindShaderBuffer();

#endif //SHADERBUFFER_H
