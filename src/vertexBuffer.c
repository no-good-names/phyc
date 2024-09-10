//
// Created by cp176 on 9/7/2024.
//

#include "vertexBuffer.h"

#include "renderer.h"

void VertexBuffer(VertexBuf *vb, const void *data, unsigned int size) {
	glGenVertexArrays(1, &vb->id);
	glBindVertexArray(vb->id);
}

void deleteVertexBuffer(const VertexBuf *vb) {
	glDeleteBuffers(1, &vb->id);
}

void bindVertexArray(const VertexBuf *vb) {
	glBindBuffer(GL_ARRAY_BUFFER, vb->id);
}

void unbindVertexArray() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
