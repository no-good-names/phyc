//
// Created by cp176 on 9/7/2024.
//

#include "renderer.h"

#include <math.h>
#include <GLFW/glfw3.h>

void draw(const VertexBuf *vb, const IndexBuf *ib, const ShaderBuf *sb) {
	glUseProgram(sb->id);
	glBindVertexArray(vb->id);
	glDrawArrays(GL_TRIANGLES, 0, getCount(ib));
	glUseProgram(0);
}
