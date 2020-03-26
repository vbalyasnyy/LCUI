/*
 * fpsmeter.h -- The widget fps meter operation set.
 *
 * Copyright (c) 2020, Vasilyy Balyasnyy <v.balyasnyy@gmail.com> All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of LCUI nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LCUI_FPSMETER_H
#define LCUI_FPSMETER_H

LCUI_BEGIN_HEADER

#include <LCUI/LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/widget/textview.h>

typedef struct LCUI_FpsMeterRec_ {
	LCUI_BOOL is_enabled;

	LCUI_Widget widget;

	int64_t last_time;
	size_t frame_count;

	size_t fps;
	int render_thread_count;
	size_t render_count;
	size_t widget_update_count;
} LCUI_FpsMeterRec, *LCUI_FpsMeter;

void LCUI_FpsMeter_FrameCount(void);

void LCUI_FpsMeter_RenderThreadCount(int count);

void LCUI_FpsMeter_RenderCount(size_t count);

void LCUI_FpsMeter_WidgetUpdateCount(size_t count);

void LCUI_EnableFpsMeter(LCUI_BOOL enabled);

LCUI_END_HEADER

#endif

