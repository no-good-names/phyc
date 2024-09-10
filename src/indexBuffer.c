//
// Created by cp176 on 9/7/2024.
//

#include "indexBuffer.h"

#include "renderer.h"

void IndexBuffer(IndexBuf *ib, const void *data, unsigned int count) {
	ib->count = count;

	glGenBuffers(1, &ib->id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

void deleteIndexBuffer(const IndexBuf *ib) {
	glDeleteBuffers(1, &ib->id);
}

void bindIndexBuffer(const IndexBuf *ib) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->id);
}

void unbindIndexBuffer() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int getCount(const IndexBuf *ib) {
	return ib->count;
}

