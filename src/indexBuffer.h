//
// Created by cp176 on 9/7/2024.
//

#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

typedef struct {
	unsigned int id;
	unsigned int count;
} IndexBuf;

void IndexBuffer(IndexBuf *ib, const void *data, unsigned int count);
void deleteIndexBuffer(const IndexBuf *ib);
void bindIndexBuffer(const IndexBuf *ib);
void unbindIndexBuffer();

unsigned int getCount(const IndexBuf *ib);

#endif //INDEXBUFFER_H
