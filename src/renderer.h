//
// Created by cp176 on 9/7/2024.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "shaderBuffer.h"

#define ASSERT(_e, ...) if (!(_e)) { fprintf(stderr, __VA_ARGS__); exit(1); }

void draw(const VertexBuf *vb, const IndexBuf *ib, const ShaderBuf *sb);

#endif //RENDERER_H
