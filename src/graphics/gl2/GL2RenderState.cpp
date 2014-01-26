#include "graphics/gl2/GL2RenderState.h"

namespace Graphics { namespace GL2 {

RenderState::RenderState(const RenderStateDesc &d)
	: Graphics::RenderState(d)
{
}

void RenderState::Apply()
{
	switch (m_desc.blendMode) {
	case BLEND_SOLID:
		glDisable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ZERO);
		break;
	case BLEND_ADDITIVE:
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE);
		break;
	case BLEND_ALPHA:
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		break;
	case BLEND_ALPHA_ONE:
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		break;
	case BLEND_ALPHA_PREMULT:
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
		break;
	case BLEND_SET_ALPHA:
		glEnable(GL_BLEND);
		glBlendFuncSeparate(GL_ZERO, GL_ONE, GL_SRC_COLOR, GL_ZERO);
		break;
	case BLEND_DEST_ALPHA:
		glEnable(GL_BLEND);
		glBlendFunc(GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA);
	default:
		break;
	}

	//TODO cull mode (move from material)

	if (m_desc.depthTest)
		glEnable(GL_DEPTH_TEST);
	else
		glDisable(GL_DEPTH_TEST);

	if (m_desc.depthWrite)
		glDepthMask(GL_TRUE);
	else
		glDepthMask(GL_FALSE);

	glPolygonMode(GL_FRONT_AND_BACK, m_desc.wireFrame ? GL_LINE : GL_FILL);
}

} }
