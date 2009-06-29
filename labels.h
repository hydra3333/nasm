/* ----------------------------------------------------------------------- *
 *   
 *   Copyright 1996-2009 The NASM Authors - All Rights Reserved
 *   See the file AUTHORS included with the NASM distribution for
 *   the specific copyright holders.
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Lesser General Public License as
 *   published by the Free Software Foundation, Inc.,
 *   51 Franklin St, Fifth Floor, Boston MA 02110-1301, USA; version 2.1,
 *   or, at your option, any later version, incorporated herein by
 *   reference.
 *
 *   Patches submitted to this file are required to be dual licensed
 *   under the LGPL 2.1+ and the 2-clause BSD license:
 *
 *   Copyright 1996-2009 the NASM Authors - All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following
 *   conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *     
 *     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *     CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *     INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *     MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *     CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *     SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *     NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *     OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *     EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ----------------------------------------------------------------------- */

/* 
 * labels.h  header file for labels.c
 */

#ifndef LABELS_H
#define LABELS_H

extern char lprefix[PREFIX_MAX];
extern char lpostfix[PREFIX_MAX];

bool lookup_label(char *label, int32_t *segment, int64_t *offset);
bool is_extern(char *label);
void define_label(char *label, int32_t segment, int64_t offset, char *special,
		  bool is_norm, bool isextrn, struct ofmt *ofmt,
                  efunc error);
void redefine_label(char *label, int32_t segment, int64_t offset, char *special,
                    bool is_norm, bool isextrn, struct ofmt *ofmt,
                    efunc error);
void define_common(char *label, int32_t segment, int32_t size, char *special,
                   struct ofmt *ofmt, efunc error);
void declare_as_global(char *label, char *special, efunc error);
int init_labels(void);
void cleanup_labels(void);
char *local_scope(char *label);

#endif /* LABELS_H */
