//
// Created by cp176 on 9/7/2024.
//

#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

typedef struct {
	unsigned int id;
} VertexBuf;

void VertexBuffer(VertexBuf *vb, const void *data, unsigned int size);
void deleteVertexBuffer(const VertexBuf *vb);
void bindVertexArray(const VertexBuf *vb);
void unbindVertexArray();

#endif //VERTEXBUFFER_H
